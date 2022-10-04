//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ContextCreatedJSInject;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFInterfaces, uCEFTypes;

type
  //js 注入
  TContextCreatedJSInjectClass = class
  public
    constructor Create(const browser_: ICefBrowser; const frame_: ICefFrame; const context_: ICefv8Context);
    destructor Destroy;
  private
    browser: ICefBrowser;
    frame: ICefFrame;
    context: ICefv8Context;
  public
    procedure JavaScriptInject();
  end;

implementation

constructor TContextCreatedJSInjectClass.Create(const browser_: ICefBrowser; const frame_: ICefFrame; const context_: ICefv8Context);
begin
  inherited Create;
  browser := Browser_;
  frame := Frame_;
  context := context_;
end;

destructor TContextCreatedJSInjectClass.Destroy;
begin
  inherited Destroy;
  browser := nil;
  frame := nil;
  context := nil;
end;

procedure TContextCreatedJSInjectClass.JavaScriptInject();
begin

end;

end.
