//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8ObjectAccessor;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils, fgl,
  uCEFv8Value, uCEFv8Accessor, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_Entity, uCEF_LCL_Event;

type

  {
  对象查找数据结构
  Map key = name  value=[]pointer array of PRCEFObjectBind
  查找时 使用名字 找到自己的对象，
         名字相同有多个，循环数组遍历
             条件1 IsSame(parent.ICefv8Value)=true 表示找到自己的父节点，
             条件2 否则查找 parent=nil 有返回，否则不存在返回错误
         只有一个，IsSame(parent.ICefv8Value)= true 表示找到自己的父节点，
  }
  PRLookupObject = ^RLookupObject;

  RLookupObject = record
    Parent: PRCEFObjectBind;//父对象信息
    VType: integer;//类别 0对象 1普通字段 2函数 3对象字段
    FieldInfo: PRFieldBindInfo;//当前 1字段 2函数 VType
    CefObject: PRCEFObjectBind;//当前 对象 VType=0 或 3
  end;

  LookupCEFObjectArray = array of PRLookupObject;
  //PLookupCEFObjectArray = ^LookupCEFObjectArray;
  TLookupObjectArrayMap = specialize TFPGMap<ustring, LookupCEFObjectArray>;


  //V8 Get Set 处理器
  TV8ObjectAccessor = class(TCefV8AccessorOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
    initState: integer; //状态0:初始化 1:初始化完成
    CefV8Objects: CEFObjectBindMap;//存储对象的关系集合
    LookupObjectsMap: TLookupObjectArrayMap;//存储对象的查找集合1维map
    RootObjectAccessor: ICEFv8Value;
    constructor Create;
    destructor Destroy;
    //PRCEFObjectBind
    procedure Put(ObjName: ustring; Value: PRCEFObjectBind);
    function GetObject(ObjName: ustring): PRCEFObjectBind;
    function PutChildrenObject(FullObjName: TStringArray; ObjName: ustring; Value: PRCEFObjectBind): PRCEFObjectBind;
    function GetObjectByFullName(FullName: TStringArray): PRCEFObjectBind;
    //TLookupObjectArrayMap
    procedure PutLookupObjectsMap(Name: ustring; VType: integer; CefObject: PRCEFObjectBind; ParentCefObject: PRCEFObjectBind; FieldInfo: PRFieldBindInfo);
    function GetLookupObjectsMap(Name: ustring): LookupCEFObjectArray;
    function FindLookupObject(Name: ustring; const object_: ICefv8Value): PRLookupObject;
  protected
    function Get(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function Set_(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
  end;

var
  //上一次取到的 CefObject
  PreCefV8Object: PRCEFObjectBind;

implementation

{
 变量属性值获取
 javascript 获取值时会触发该函数
}
function TV8ObjectAccessor.Get(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  //Result
  PRetException: Pointer;
  ExceptionMessage: ustring = '';
  PRetStringValue: Pointer;
  PRetIntValue: PInteger;
  RetDoubleValue: double;
  PRetBooleanValue: PBoolean;
  PRetVType: Pinteger;
  //逻辑变量
  newRetVal: ICefv8Value;
  //查找对象Map
  PLookupObjectItem: PRLookupObject;
  FieldInfo: PRFieldBindInfo;
begin
  try
    //获取值时，在go中获取，同时更新 map 值
    //获得实际的 Name 对象
    PLookupObjectItem := FindLookupObject(Name, object_);
    if not (PLookupObjectItem = nil) then
    begin
      //Parent = nil 一定是根对象
      if PLookupObjectItem^.Parent = nil then
      begin
        retval := PLookupObjectItem^.CefObject^.CefV8ValueField;
        Result := True;
        exit;
      end
      else
      begin
        //子节点，根据子节点信息返回对应的值
        case PLookupObjectItem^.VType of
          1://普通字段会触发事件函数在Go中获取值
          begin
            //判断类型
            FieldInfo := PLookupObjectItem^.FieldInfo;
            //变量类型 0:string 1:int 2:double 3:bool 4:null 5:undefined 6:object
            TCEFWindowBindClass.SendEvent(FieldInfo^.FullName, [BE_GET, @PRetVType, @PRetStringValue, @PRetIntValue, @RetDoubleValue, @PRetBooleanValue, @PRetException]);
            ExceptionMessage := PCharToUstr(PChar(PRetException));
            if not (ExceptionMessage = '') then
            begin//有错误时返回错误，直接退出
              Exception := ExceptionMessage;
              Result := True;
              exit;
            end
            else
            begin
              case FieldInfo^.BindType of
                0://ustring
                begin
                  newRetVal := TCefv8ValueRef.NewString(PCharToUStr(PChar(PRetStringValue)));
                end;
                1://integer
                begin
                  newRetVal := TCefv8ValueRef.NewInt(integer(PRetIntValue));
                end;
                2://double
                begin
                  newRetVal := TCefv8ValueRef.NewDouble(RetDoubleValue);
                end;
                3://boolean
                begin
                  newRetVal := TCefv8ValueRef.NewBool(boolean(PRetBooleanValue));
                end
                else
                begin//类型不正确
                  newRetVal := nil;
                end;
              end;
            end;
          end;
          3://对象字段
          begin
            newRetVal := PLookupObjectItem^.CefObject^.CefV8ValueField;
          end;
        end;
        //= nil 类型不正确，返回错误
        if newRetVal = nil then
        begin
          Exception := ('Type is invalid');
          //retval := TCefv8ValueRef.NewString(Exception);
          Result := True;
          exit;
        end;
        retval := newRetVal;
        Result := True;
        exit;
      end;
    end;
  except
    on E: Exception do
    begin
      Exception := StrToUstr(E.ToString);
      retval := TCefv8ValueRef.NewString(Exception);
    end;
  end;
  Result := True;
end;


function TV8ObjectAccessor.Set_(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
var
  //查找对象Map
  PLookupObjectItem: PRLookupObject;
  FieldInfo: PRFieldBindInfo;
  //Ret
  PRetException: Pointer;
  ExceptionMessage: ustring = '';
begin
  //设置值时，同时更新到go中
  //initState = 1 只让初始化完之后才触发
  if initState = 1 then
  begin
    try
      try
        //赋值操作, 不支持 对象 数组 函数 buffer
        if Value.IsArray or Value.IsObject or Value.IsFunction or Value.IsArrayBuffer then
        begin
          Exception := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_CANNOT_CHANGE);
          Result := False;
          exit;
        end
        else
        begin
          //这里只支持 string int double bool
          PLookupObjectItem := FindLookupObject(Name, object_);
          if not (PLookupObjectItem = nil) then
          begin
            //判断当前返回的是否为对象类型，对象类型不支持赋值操作
            if (PLookupObjectItem^.VType = 0) or (PLookupObjectItem^.VType = 3) then
            begin
              Exception := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_CANNOT_CHANGE);
              Result := False;
              exit;
            end;
            //判断类型实际类型
            FieldInfo := PLookupObjectItem^.FieldInfo;
            if (FieldInfo^.BindType = 0) and Value.IsString then
            begin
              TCEFWindowBindClass.SendEvent(FieldInfo^.FullName, [BE_SET, 0, string(Value.GetStringValue), @PRetException]);
            end
            else if (FieldInfo^.BindType = 1) and Value.IsInt then
            begin
              TCEFWindowBindClass.SendEvent(FieldInfo^.FullName, [BE_SET, 1, Value.GetIntValue, @PRetException]);
            end
            else if (FieldInfo^.BindType = 2) and Value.IsDouble then
            begin
              TCEFWindowBindClass.SendEvent(FieldInfo^.FullName, [BE_SET, 2, Value.GetDoubleValue, @PRetException]);
            end
            else if (FieldInfo^.BindType = 3) and Value.IsBool then
            begin
              TCEFWindowBindClass.SendEvent(FieldInfo^.FullName, [BE_SET, 3, Value.GetBoolValue, @PRetException]);
            end
            else
            begin
              //新值类型和原数据类型不匹配，返回错误
              Exception := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_INVALID);
              Result := False;
              exit;
            end;
            ExceptionMessage := PCharToUstr(PChar(PRetException));
            if not (ExceptionMessage = '') then
            begin
              Exception := ExceptionMessage;
              Result := False;
              exit;
            end;
          end
          else
          begin
            Exception := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_CANNOT_CHANGE);
            Result := False;
            exit;
          end;
        end;
      except
        on E: Exception do
        begin
          Exception := StrToUstr(E.ToString);
        end;
      end;
    finally
      PLookupObjectItem := nil;
      FieldInfo := nil;
      PRetException := nil;
    end;
  end;
  Result := True;
end;

//添加到根节点
procedure TV8ObjectAccessor.Put(ObjName: ustring; Value: PRCEFObjectBind);
begin
  CefV8Objects.AddOrSetData(ObjName, Value);
end;

//获取一个对象
function TV8ObjectAccessor.GetObject(ObjName: ustring): PRCEFObjectBind;
var
  v8Object: PRCEFObjectBind;
begin
  if CefV8Objects.TryGetData(ObjName, v8Object) then
    Result := v8Object
  else
    Result := nil;
end;

{
维护一棵对象关系树
将对象添加到指定的FullObjName节点中
}
function TV8ObjectAccessor.PutChildrenObject(FullObjName: TStringArray; ObjName: ustring; Value: PRCEFObjectBind): PRCEFObjectBind;
var
  i: integer;
  parentV8Object: PRCEFObjectBind;
  NextCefObjects: CEFObjectBindMap;
  isFindBool: boolean;
begin
  //临时遍历map变量
  NextCefObjects := CefV8Objects;
  for i := 0 to length(FullObjName) - 2 do
  begin
    if NextCefObjects.TryGetData(FullObjName[i], parentV8Object) then
    begin
      if Value^.ParentId = parentV8Object^.Id then
      begin
        //找到了跳出循环
        isFindBool := True;
        break;
      end;
      //没找到继续找, 先把指针类型的map转换成实际的map，否则会地址无效
      NextCefObjects := CEFObjectBindMap(parentV8Object^.Children);
    end;
  end;
  if isFindBool then
  begin
    //先把指针类型的map转换成实际的map，否则会地址无效
    Value^.Parent := parentV8Object;
    CEFObjectBindMap(parentV8Object^.Children).AddOrSetData(ObjName, Value);
    Result := parentV8Object;
    exit;
  end;
  Result := nil;
end;

//根据全路径查找某个对象
function TV8ObjectAccessor.GetObjectByFullName(FullName: TStringArray): PRCEFObjectBind;
var
  i: integer;
  V8Object: PRCEFObjectBind;
  PreV8Object: PRCEFObjectBind;
  NextCefObjects: CEFObjectBindMap;
  len: integer;
  field: PRFieldBindInfo;
  fieldName: string;
  isFind: boolean;
begin

  NextCefObjects := CefV8Objects;
  len := length(FullName);
  fieldName := FullName[len - 1];
  for i := 0 to len - 1 do
  begin
    //循环查找下一个子对象
    isFind := NextCefObjects.TryGetData(FullName[i], V8Object);
    if isFind then
    begin
      PreV8Object := V8Object;
      NextCefObjects := CEFObjectBindMap(V8Object^.Children);
    end
    else
    begin
      V8Object := PreV8Object;
    end;
    //最后一次循环判断
    if (len - 1 = i) and (not (isFind)) then
    begin
      if V8Object^.Name = fieldName then
      begin
        Result := V8Object;
        exit;
      end
      else
      begin
        if V8Object^.Fields.TryGetData(fieldName, field) then
        begin
          Result := V8Object;
          exit;
        end
        else if V8Object^.Funcs.TryGetData(fieldName, field) then
        begin
          Result := V8Object;
          exit;
        end;
      end;
    end;
  end;
  if isFind then
  begin
    Result := V8Object;
  end
  else
    Result := nil;
end;

//name, type 类别 0对象 1普通字段 2函数 3对象字段, CefObject 当前对象或父对象, FieldInfo 字段信息
procedure TV8ObjectAccessor.PutLookupObjectsMap(Name: ustring; VType: integer; CefObject: PRCEFObjectBind; ParentCefObject: PRCEFObjectBind; FieldInfo: PRFieldBindInfo);
var
  IsGet: boolean;
  PObjects: LookupCEFObjectArray;
  LookupObject: PRLookupObject;
begin
  //获取该名字的查找对象，如果有就在后面追加
  IsGet := LookupObjectsMap.TryGetData(Name, PObjects);
  if IsGet then
  begin
    SetLength(PObjects, Length(PObjects) + 1);
  end
  else
  begin
    SetLength(PObjects, 1);
  end;
  LookupObject := new(PRLookupObject);
  if VType = 0 then
  begin
    LookupObject^.CefObject := CefObject;
    LookupObject^.Parent := nil;
  end
  else if VType = 3 then
  begin
    LookupObject^.Parent := ParentCefObject;
    LookupObject^.CefObject := CefObject;
  end
  else// VType = 1字段 或 2函数
  begin
    LookupObject^.Parent := ParentCefObject;
    LookupObject^.FieldInfo := FieldInfo;
  end;
  LookupObject^.VType := VType;
  PObjects[High(PObjects)] := LookupObject;
  LookupObjectsMap.AddOrSetData(Name, PObjects);
end;

//获取查找对象数组
function TV8ObjectAccessor.GetLookupObjectsMap(Name: ustring): LookupCEFObjectArray;
var
  PObjects: LookupCEFObjectArray;
begin
  if LookupObjectsMap.TryGetData(Name, PObjects) then
  begin
    Result := PObjects;
    exit;
  end;
  Result := nil;
end;

//获取真正的当前对象
function TV8ObjectAccessor.FindLookupObject(Name: ustring; const object_: ICefv8Value): PRLookupObject;
var
  //查找对象Map
  lookupIdx: integer;
  LookupObjects: LookupCEFObjectArray;
  PLookupObjectItem: PRLookupObject;
begin
  //获取当前name的对象，name可能重复，所以返回的是个数组。
  LookupObjects := GetLookupObjectsMap(Name);
  if not (LookupObjects = nil) then
  begin
    //判断是否只有1个元素
    //遍历每个object，判断 ICefv8Value IsSame
    for lookupIdx := 0 to Length(LookupObjects) - 1 do
    begin
      PLookupObjectItem := LookupObjects[lookupIdx];
      //=nil 是根对象，就和 root accessor做xxlq比较
      if (PLookupObjectItem^.Parent = nil) and (object_.IsSame(RootObjectAccessor)) then
      begin//Parent = nil时是根对象
        Result := PLookupObjectItem;
        exit;
      end
      else
      begin//Parent <> nil 需要判断每个item的父节点是否和当前对象是同一个，是同一个判断类型并返回
        //2. 父节点不是空，判断父节点的 ICefv8Value IsSame = true
        if object_.IsSame(PLookupObjectItem^.Parent^.CefV8ValueField) then
        begin
          Result := PLookupObjectItem;
          exit;
        end;
      end;
    end;
  end;
  Result := nil;
end;

constructor TV8ObjectAccessor.Create;
begin
  inherited Create;
  CefV8Objects := CEFObjectBindMap.Create;
  LookupObjectsMap := TLookupObjectArrayMap.Create;
end;

destructor TV8ObjectAccessor.Destroy;
begin
  inherited Destroy;
  CefV8Objects.Clear;
  CefV8Objects.Free;
  LookupObjectsMap.Clear;
  LookupObjectsMap.Free;
end;

end.
