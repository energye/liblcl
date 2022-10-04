//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8ValueRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  Generics.Collections, fgl, SysUtils, Controls,
  uCEFInterfaces, uCEFv8Value, uCEFConstants, uCEFTypes,
  uCEF_LCL_Entity;

type

  //RPValueBindInfo 存放字段或函数的指针信息数据值
  PRPValueBindInfo = ^RPValueBindInfo;

  RPValueBindInfo = record
    Name: PChar;
    EventId: nativeuint;
    BindType: PInteger;
    FnInNum: PInteger;
    FnInParamType: PChar;
    FnOutNum: PInteger;
    FnOutParamType: PChar;
  end;

  //RFieldBindInfo 存放字段或函数的实际信息数据
  PRFieldBindInfo = ^RFieldBindInfo;

  RFieldBindInfo = record
    FullName: string;
    Name: string;
    EventId: nativeuint;
    BindType: integer;
    FnInNum: integer;
    FnInParamType: TStringArray;
    FnOutNum: integer;
    FnOutParamType: TStringArray;
    ArgumentsArr: PArgumentsArray;
  end;

  //Object Bind
  TempObjectFieldInfoArray = array of PRPValueBindInfo;
  ObjectFieldInfoArray = array of PRFieldBindInfo;

  //go中生分析完对象结构后，把对象字段和函数信息传递过来，用一个TList维护
  PRTempCefObject = ^RTempCefObject;

  RTempCefObject = record
    Id: nativeuint;
    ParentId: nativeuint;
    Name: PChar;
    FullObjName: PChar;
    FieldLen: PInteger;
    Fields: TempObjectFieldInfoArray;
    FuncLen: PInteger;
    Funcs: TempObjectFieldInfoArray;
  end;

  PRCefObject = ^RCefObject;

  RCefObject = record
    Id: nativeuint;
    ParentId: nativeuint;
    Name: ustring;
    FullObjName: TStringArray; //字符串分割后的 obj1.obj2.obj3 = ['obj1', 'obj2', 'obj3']
    FieldLen: integer;
    Fields: ObjectFieldInfoArray;
    FuncLen: integer;
    Funcs: ObjectFieldInfoArray;
  end;

  {
   map 对象函数映射对象
      key = name
      value = objRecord
            id, parentId, name, eventId, vtype(0:对象 1:字段 2:函数)
            ICefv8Value, fields=map[fieldName]info, funcs=map[funcName]info,
            subRecord=map[objName]=objRecord
  }
  FieldBindInfoMap = specialize TFPGMap<ustring, PRFieldBindInfo>;
  PCEFObjectBinds = ^CEFObjectBindMap;
  PRCEFObjectBind = ^RCEFObjectBind;

  RCEFObjectBind = record
    Id: nativeuint;//当前ID
    ParentId: nativeuint;//父ID
    Name: ustring;//对象名
    Parent: PRCEFObjectBind;
    CefV8ValueField: ICefv8Value;//V8对象
    Fields: FieldBindInfoMap;//字段信息
    Funcs: FieldBindInfoMap;//函数信息
    Children: PCEFObjectBinds;//CEFObjectBindMap
  end;
  //key=objName, value=RCEFObjectBind
  CEFObjectBindMap = specialize TFPGMap<ustring, PRCEFObjectBind>;

  //Common window bind
  TCommonValueBindInfoList = specialize TList<PRFieldBindInfo>;
  // Common Window Bind class
  TCommonValueBindInfoClass = class
  private
  class var
    TCommonValueBindInfos: TCommonValueBindInfoList;
  public
    class constructor Create;
    class destructor Destroy;
    class procedure Add(TempCommonValueBindInfo: PRPValueBindInfo);
    class function GetCommonValueBindInfos(): TCommonValueBindInfoList;
    class function Size(): int64;
    class procedure Clear();
  end;

  TCefObjectList = specialize TList<PRCefObject>;

  //Object Window Bind class
  TObjectValueBindInfoClass = class
  private
  class var
    TCefObjects: TCefObjectList;
  public
    class constructor Create;
    class destructor Destroy;
    class procedure AddCefObject(CefObject: PRCefObject);
    class function GetCefObjects(): TCefObjectList;
    class function Size(): int64;
    class procedure Clear();
  end;

{实现}
implementation

class constructor TObjectValueBindInfoClass.Create;
begin
  TCefObjects := TCefObjectList.Create;
end;

class function TObjectValueBindInfoClass.Size(): int64;
begin
  Result := TCefObjects.Count;
end;

class procedure TObjectValueBindInfoClass.Clear();
begin
  ConsoleLn('TObjectValueBindInfoClass.Clear Count: ' + IntToStr(Size));
  TCefObjects.Clear;
  ConsoleLn('TObjectValueBindInfoClass.Clear Count: ' + IntToStr(Size));
end;

class destructor TObjectValueBindInfoClass.Destroy;
begin
  TCefObjects.Clear;
  TCefObjects.Free;
  ConsoleLn('TObjectValueBindInfoClass.Destroy');
end;

class procedure TObjectValueBindInfoClass.AddCefObject(CefObject: PRCefObject);
begin
  TCefObjects.Add(CefObject);
end;

class function TObjectValueBindInfoClass.GetCefObjects(): TCefObjectList;
begin
  Result := TCefObjects;
end;

class procedure TCommonValueBindInfoClass.Add(TempCommonValueBindInfo: PRPValueBindInfo);
var
  CommonValueBindInfo: PRFieldBindInfo;
begin
  CommonValueBindInfo := new(PRFieldBindInfo);
  CommonValueBindInfo^.Name := StrPas(TempCommonValueBindInfo^.Name);
  CommonValueBindInfo^.FullName := StrPas(TempCommonValueBindInfo^.Name);
  CommonValueBindInfo^.EventId := TempCommonValueBindInfo^.EventId;
  CommonValueBindInfo^.BindType := integer(TempCommonValueBindInfo^.BindType);
  CommonValueBindInfo^.FnInNum := integer(TempCommonValueBindInfo^.FnInNum);
  if CommonValueBindInfo^.FnInNum > 0 then
    CommonValueBindInfo^.FnInParamType := string(PCharToUStr(TempCommonValueBindInfo^.FnInParamType)).Split(',');
  CommonValueBindInfo^.FnOutNum := integer(TempCommonValueBindInfo^.FnOutNum);
  if CommonValueBindInfo^.FnOutNum > 0 then
    CommonValueBindInfo^.FnOutParamType := string(PCharToUStr(TempCommonValueBindInfo^.FnOutParamType)).Split(',');
  TCommonValueBindInfos.Add(CommonValueBindInfo);
end;

class function TCommonValueBindInfoClass.GetCommonValueBindInfos(): TCommonValueBindInfoList;
begin
  Result := TCommonValueBindInfos;
end;

// Common Window Bind class
class function TCommonValueBindInfoClass.Size(): int64;
begin
  Result := TCommonValueBindInfos.Count;
end;

class constructor TCommonValueBindInfoClass.Create;
begin
  TCommonValueBindInfos := TCommonValueBindInfoList.Create;
end;

class procedure TCommonValueBindInfoClass.Clear();
begin
  ConsoleLn('TCommonValueBindInfoClass.Clear Count: ' + IntToStr(Size));
  TCommonValueBindInfos.Clear;
  ConsoleLn('TCommonValueBindInfoClass.Clear Count: ' + IntToStr(Size));
end;

class destructor TCommonValueBindInfoClass.Destroy;
begin
  TCommonValueBindInfos.Clear;
  TCommonValueBindInfos.Free;
  ConsoleLn('TCommonValueBindInfoClass.Destroy');
end;


end.
