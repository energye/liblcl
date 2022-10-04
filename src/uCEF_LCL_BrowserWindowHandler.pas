//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_BrowserWindowHandler;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFConstants, uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler,
  uCEF_LCL_Entity;

type

  TBrowserWindowHandler = class(TCefv8HandlerOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
    BrowserWindowObject: ICefv8Value;
  public
    constructor Create;
    destructor Destroy;
    procedure Init();
  protected
    function Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

var
  BrowserWindow: string = 'browserWindow';
  FNBrowserId: string = 'browserId';
  FNFrameId: string = 'frameId';

implementation

//函数执行处理
function TBrowserWindowHandler.Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  argumentsLen: integer;
begin
  argumentsLen := length(arguments);
  if (Name = FNBrowserId) and (argumentsLen = 0) then
  begin
    retval := TCefv8ValueRef.NewInt(Browser.Identifier);
  end
  else if (Name = FNFrameId) and (argumentsLen = 0) then
  begin
    retval := TCefv8ValueRef.NewString(IntToStr(Frame.Identifier));
  end
  else
  begin
    Exception := '';
    Result := False;
    exit;
  end;
  Result := True;
end;

procedure TBrowserWindowHandler.Init();
begin
  BrowserWindowObject.SetValueByKey(FNBrowserId, TCefv8ValueRef.NewFunction(FNBrowserId, self), V8_PROPERTY_ATTRIBUTE_READONLY);
  BrowserWindowObject.SetValueByKey(FNFrameId, TCefv8ValueRef.NewFunction(FNFrameId, self), V8_PROPERTY_ATTRIBUTE_READONLY);
end;

constructor TBrowserWindowHandler.Create;
begin
  inherited Create;
end;

destructor TBrowserWindowHandler.Destroy;
begin
  inherited Destroy;
  Browser := nil;
  Frame := nil;
  BrowserWindowObject := nil;
end;

end.
