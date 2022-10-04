//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8WindowMoveDragHandler;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler, uCEFProcessMessage,
  uCEF_LCL_Entity;

type

  TV8WindowMoveDragHandler = class(TCefv8HandlerOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
    BrowserId: integer;
    FrameId: int64;
  public
    constructor Create;
    destructor Destroy;
    procedure Init();
  protected
    function Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

//函数执行处理
function TV8WindowMoveDragHandler.Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  argumentsLen: integer;
  processMessage: ICefProcessMessage;
begin
  argumentsLen := length(arguments);
  if (Name = MoveDragDown) and (argumentsLen = 2) then
  begin
    processMessage := TCefProcessMessageRef.New(Name);
    processMessage.ArgumentList.SetInt(0, BrowserId);// browserId
    processMessage.ArgumentList.SetInt(1, arguments[0].GetIntValue);// x
    processMessage.ArgumentList.SetInt(2, arguments[1].GetIntValue);// y
  end
  else if (Name = MoveDragMove) and (argumentsLen = 2) then
  begin
    processMessage := TCefProcessMessageRef.New(Name);
    processMessage.ArgumentList.SetInt(0, BrowserId);// browserId
    processMessage.ArgumentList.SetInt(1, arguments[0].GetIntValue);// x
    processMessage.ArgumentList.SetInt(2, arguments[1].GetIntValue);// y
  end
  else if Name = MoveDragUp then
  begin
    processMessage := TCefProcessMessageRef.New(Name);
    processMessage.ArgumentList.SetInt(0, BrowserId);// browserId
  end
  else
  begin
    retval := TCefv8ValueRef.NewString('The window drag parameter is incorrect');
    Exception := 'The window drag parameter is incorrect';
    exit;
  end;
  //给browser进程发送消息
  Frame.SendProcessMessage(PID_BROWSER, processMessage);
end;

procedure TV8WindowMoveDragHandler.Init();
begin
  BrowserId := Browser.Identifier;
  FrameId := Frame.Identifier;
end;

constructor TV8WindowMoveDragHandler.Create;
begin
  inherited Create;
end;

destructor TV8WindowMoveDragHandler.Destroy;
begin
  inherited Destroy;
end;

end.
