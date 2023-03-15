//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8ObjectHandler;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler,
  uCEF_LCL_Entity, uCEF_LCL_Event;

type


  TV8ObjectHandler = class(TCefv8HandlerOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
    ObjectAccessor: TV8ObjectAccessor;
    V8FuncHandler: TV8FuncHandler;
    constructor Create;
    destructor Destroy;
  protected
    function Execute(const Name: ustring; const object_: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

constructor TV8ObjectHandler.Create;
begin
  inherited Create;
  V8FuncHandler := TV8FuncHandler.Create;
end;

destructor TV8ObjectHandler.Destroy;
begin
  inherited Destroy;
  ObjectAccessor := nil;
  V8FuncHandler.Destroy;
  V8FuncHandler.Free;
  V8FuncHandler := nil;
end;


//函数执行处理
function TV8ObjectHandler.Execute(const Name: ustring; const object_: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  //查找对象Map
  PLookupObjectItem: PRLookupObject;
  FieldBindInfo: PRFieldBindInfo;
  //args
  argumentsLen: integer;
begin
  PLookupObjectItem := ObjectAccessor.FindLookupObject(Name, object_);
  if not (PLookupObjectItem = nil) then
  begin
    argumentsLen := Length(arguments);
    FieldBindInfo := PLookupObjectItem^.FieldInfo;
    //判断入参个数
    if not (FieldBindInfo^.FnInNum = argumentsLen) then
    begin
      Exception := 'The input parameter is incorrect. The input parameter should be:' + IntToStr(FieldBindInfo^.FnInNum) + ', which is actually ' + IntToStr(argumentsLen);
      retval := TCefv8ValueRef.NewString(Exception);
      Result := True;
      exit;
    end;
    //函数类型8，参数个数最多只能有9个
    if (FieldBindInfo^.BindType = 8) and (argumentsLen < 10) then
    begin
        {
          1.分析参数类型、参数个数
          2.返回参数类型，返回结果
          3.返回错误信息
        }
      retval := V8FuncHandler.Execute(FieldBindInfo, arguments, Exception);
      if not (Exception = '') then
      begin
        Exception := Name + Exception;
      end;
    end
    else
    begin
      Exception := Name + ErrorCodeToMessage(CVE_ERROR_FUNC_INVALID_P_L_9);
    end;
  end;
  Result := True;
end;

end.
