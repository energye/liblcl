//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_RequestContextRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFRequestContextHandler,
  uCEF_LCL_EventCallback;

type

  TRequestContextHandlerRef = class(TCefRequestContextHandlerOwn)
  public
    GetCookieManagerPtr: Pointer;
    OnBeforePluginLoadPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function GetCookieManager(): ICefCookieManager; override;
    function OnBeforePluginLoad(const mimeType, pluginUrl: ustring; const topOriginUrl: ustring; const pluginInfo: ICefWebPluginInfo; pluginPolicy: PCefPluginPolicy): boolean; override;

  end;

implementation

function TRequestContextHandlerRef.GetCookieManager(): ICefCookieManager;
var
  ResultCookieManager: ICefCookieManager;
begin
  if (GetCookieManagerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetCookieManagerPtr, [@ResultCookieManager]);
    Result := ResultCookieManager;
  end
  else
    Result := inherited GetCookieManager();
end;

function TRequestContextHandlerRef.OnBeforePluginLoad(const mimeType, pluginUrl: ustring; const topOriginUrl: ustring; const pluginInfo: ICefWebPluginInfo;
  pluginPolicy: PCefPluginPolicy): boolean;
begin
  if (OnBeforePluginLoadPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBeforePluginLoadPtr, [PChar(string(mimeType)), PChar(string(pluginUrl)), PChar(string(topOriginUrl)), @pluginInfo, integer(pluginPolicy^)]);
  end
  else
    inherited OnBeforePluginLoad(mimeType, pluginUrl, topOriginUrl, pluginInfo, pluginPolicy);
end;


constructor TRequestContextHandlerRef.Create;
begin
  inherited Create;
end;

destructor TRequestContextHandlerRef.Destroy;
begin
  GetCookieManagerPtr := nil;
  OnBeforePluginLoadPtr := nil;
  inherited Destroy;
end;

end.
