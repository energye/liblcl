//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8EventOnHandler;

{
 JS监听事件on函数处理
}
{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  fgl, SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler, uCEFv8Context, uCEFProcessMessage,
  uCEF_LCL_Entity, uCEF_LCL_Event,
  uCEF_LCL_IPC;

type

  TV8EventOnHandler = class(TCefv8HandlerOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
  public
    constructor Create;
    destructor Destroy;
  protected
    function Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

var
  IPCEventOnName: string = 'on';

implementation

//函数执行处理
function TV8EventOnHandler.Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  Callback: PRGlobalCallback;
  argumentsLen: integer;
begin
  argumentsLen := length(arguments);
  if (argumentsLen = 2) and (arguments[0].IsString) and (arguments[1].IsFunction) then
  begin
    Callback := new(PRGlobalCallback);
    Callback^.GlobalCallbackFunc := arguments[1];
    Callback^.GlobalCallbackContext := TCefv8ContextRef.Current;
    TCEFIPCClass.PutOnCallback(arguments[0].GetStringValue, Callback);
    Result := True;
  end
  else
  begin
    retval := TCefv8ValueRef.NewBool(False);
    Result := False;
  end;
end;


constructor TV8EventOnHandler.Create;
begin
  inherited Create;
end;

destructor TV8EventOnHandler.Destroy;
begin
  inherited Destroy;
end;

end.
