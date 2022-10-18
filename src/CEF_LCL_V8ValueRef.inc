//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//设置 ICEFv8Value 通用类型变量属性的所属默认对象名称
procedure CEFV8ValueRef_SetCommonRootName(PName: PChar); extdecl;
var
  name : ustring;
begin
  name := PCharToUStr(PName);
  if name = '' then
  begin
     name := v8cobj;
  end;
  CommonRootName := name;
end;

//设置 ICEFv8Value 通用类型变量属性的所属默认对象名称
procedure CEFV8ValueRef_SetObjectRootName(PName: PChar); extdecl;
var
  name : ustring;
begin
  name := PCharToUStr(PName);
  if name = '' then
  begin
     name := v8obj;
  end;
  ObjectRootName := name;
end;

//CommonValueBind处理
procedure CEFV8ValueRef_CommonValueBindInfo(TempCommonValueBindInfo: PRPValueBindInfo); extdecl;
begin
  TCommonValueBindInfoClass.Add(TempCommonValueBindInfo);
end;


//ObjectValueBind处理 将传入的数据转换
procedure CEFV8ValueRef_ObjectValueBindInfo(TempCefObject: PRTempCefObject); extdecl;
var
    i: integer;
    CefObject: PRCefObject;
    TempField: PRPValueBindInfo;
    TempFunc: PRPValueBindInfo;
    Field: PRFieldBindInfo;
    Func: PRFieldBindInfo;
    FullObjName: ustring;
begin
    try
      //对象的信息记录
      FullObjName := PCharToUStr(TempCefObject^.FullObjName);
      CefObject := new(PRCefObject);
      CefObject^.Id := TempCefObject^.Id;
      CefObject^.ParentId := TempCefObject^.ParentId;
      CefObject^.Name := PCharToUStr(TempCefObject^.Name);
      CefObject^.FullObjName := string(FullObjName).Split('.') ;
      CefObject^.FieldLen := integer(TempCefObject^.FieldLen);
      CefObject^.FuncLen := integer(TempCefObject^.FuncLen);
      SetLength(CefObject^.Fields, CefObject^.FieldLen);
      SetLength(CefObject^.Funcs, CefObject^.FuncLen);
      //取出所有字段信息数据
      for i := 0 to CefObject^.FieldLen-1 do
      begin
        TempField := TempCefObject^.Fields[i];
        Field := new(PRFieldBindInfo);
        Field^.Name := PCharToUStr(TempField^.Name);
        Field^.FullName := FullObjName + StrToUStr('.') + Field^.Name;
        Field^.BindType := integer(TempField^.BindType);
        Field^.EventId := TempField^.EventId;
        CefObject^.Fields[i] := Field;
      end;
      //取出所有函数信息数据
      for i := 0 to integer(CefObject^.FuncLen) - 1 do
      begin
        TempFunc := TempCefObject^.Funcs[i];
        Func := new(PRFieldBindInfo);
        Func^.Name := PCharToUStr(TempFunc^.Name);
        Func^.FullName := FullObjName + StrToUStr('.') + Func^.Name;
        Func^.BindType := integer(TempFunc^.BindType);
        Func^.EventId := TempFunc^.EventId;
        Func^.FnInNum := integer(TempFunc^.FnInNum);
        Func^.FnInParamType := string(PCharToUStr(TempFunc^.FnInParamType)).Split(',');
        Func^.FnOutNum := integer(TempFunc^.FnOutNum);
        Func^.FnOutParamType := string(PCharToUStr(TempFunc^.FnOutParamType)).Split(',');
        CefObject^.Funcs[i] := Func;
      end;
      //将对象的信息 添加到 TList 待 ContextCreated 处理
      TObjectValueBindInfoClass.AddCefObject(CefObject);
    except
      on E: Exception do
      begin
      end;
    end;
end;

exports
  CEFV8ValueRef_SetCommonRootName,
  CEFV8ValueRef_SetObjectRootName,
//bind
  CEFV8ValueRef_CommonValueBindInfo,
  CEFV8ValueRef_ObjectValueBindInfo

{end}
;

