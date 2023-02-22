//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8CommonAccessor;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFv8Value, uCEFv8Accessor, uCEFInterfaces, uCEFTypes, uCEFv8Context,
  uCEF_LCL_Entity, uCEF_LCL_Event,
  uCEF_LCL_V8Accessor;

type
  //V8 Get Set 处理器
  TV8CommonAccessor = class(TCefV8AccessorOwn)
  public
    V8Object: ICEFv8Value;
    Browser: ICefBrowser;
    Frame: ICefFrame;
    initState: integer; //状态0:初始化 1:初始化完成
  protected
    function Get(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function Set_(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

{
 变量属性值获取
 javascript 获取值时会触发该函数
}
function TV8CommonAccessor.Get(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  ExceptionMessage: ustring = '';
  RetValue: RRetBindValue;
  newRetVal: ICefv8Value;
begin
  try
    //变量类型 0:string 1:int 2:double 3:bool 4:null 5:undefined 6:obje
    //Go进程获取值， 通过GO IPC

    RetValue := TV8Accessor.GetFieldValue(Name);
    case integer(RetValue.PVType) of
      0://ustring
      begin
        newRetVal := TCefv8ValueRef.NewString(PCharToUStr(PChar(RetValue.PStringValue)));
      end;
      1://integer
      begin
        newRetVal := TCefv8ValueRef.NewInt(integer(RetValue.PIntValue));
      end;
      2://double
      begin
        newRetVal := TCefv8ValueRef.NewDouble(RetValue.DoubleValue);
      end;
      3://boolean
      begin
        newRetVal := TCefv8ValueRef.NewBool(boolean(RetValue.PBooleanValue));
      end;
      4://null
      begin
        newRetVal := TCefv8ValueRef.NewNull;
      end;
      5://undefined
      begin
        newRetVal := TCefv8ValueRef.NewUndefined;
      end;
      else
      begin
        ExceptionMessage := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_NOT_SUPPORTED);
      end;
    end;
    if (ExceptionMessage = '') then
    begin
      ExceptionMessage := PCharToUstr(PChar(RetValue.PException));
    end;
    if not (ExceptionMessage = '') then
    begin
      Exception := ExceptionMessage;
    end
    else
    begin
      retval := newRetVal;
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

{
 变量属性值设置
 javascript 设置值时会触发该函数
 会将新值同步更新到go对应的配置变量属性
}
function TV8CommonAccessor.Set_(const Name: ustring; const object_: ICefv8Value; const Value: ICefv8Value; var Exception: ustring): boolean;
begin
  //fieldName BE_SET newValue  type
  //变量类型 0:string 1:int 2:double 3:bool 4:null 5:undefined 6:object 7:array 8:function
  //initState = 1 只让初始化完之后才触发
  if initState = 1 then
  begin
    Result := TV8Accessor.SetFieldValue(Name, object_, Value, Exception);
  end
  else
  begin
    Result := False;
  end;
end;

end.
