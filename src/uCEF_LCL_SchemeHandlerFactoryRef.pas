//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_SchemeHandlerFactoryRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFSchemeHandlerFactory, uCEFResourceHandler, uCEFBaseRefCounted,
  uCEF_LCL_EventCallback;

type

  TSchemeHandlerFactoryRef = class(TCefSchemeHandlerFactoryOwn)
  public
    NewPtr: Pointer;
    constructor Create(const AClass: TCefResourceHandlerClass); override;
    destructor Destroy; override;
  protected
    function New(const browser: ICefBrowser; const frame: ICefFrame; const schemeName: ustring; const request: ICefRequest): ICefResourceHandler; override;

  end;

implementation

function TSchemeHandlerFactoryRef.New(const browser: ICefBrowser; const frame: ICefFrame; const schemeName: ustring; const request: ICefRequest): ICefResourceHandler;
var
  RetResourceHandler: ICefResourceHandler;
begin
  if (NewPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(NewPtr, [browser, frame, PChar(string(schemeName)), request, @RetResourceHandler]);
    Result := RetResourceHandler;
  end
  else
    Result := nil;
end;

constructor TSchemeHandlerFactoryRef.Create(const AClass: TCefResourceHandlerClass);
begin
  inherited Create(AClass);
end;

destructor TSchemeHandlerFactoryRef.Destroy;
begin
  inherited Destroy;
  NewPtr := nil;
end;

end.
