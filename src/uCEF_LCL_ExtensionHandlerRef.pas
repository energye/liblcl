//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ExtensionHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFExtensionHandler,
  uCEF_LCL_EventCallback;

type

  TExtensionHandlerRef = class(TCefExtensionHandlerOwn)
  public
    ExtensionLoadFailedPtr: Pointer;
    ExtensionLoadedPtr: Pointer;
    ExtensionUnloadedPtr: Pointer;
    BeforeBackgroundBrowserPtr: Pointer;
    BeforeBrowserPtr: Pointer;
    GetActiveBrowserPtr: Pointer;
    CanAccessBrowserPtr: Pointer;
    GetExtensionResourcePtr: Pointer;
    constructor Create;
    destructor Destroy;
  protected
    procedure OnExtensionLoadFailed(Result: TCefErrorcode); override;
    procedure OnExtensionLoaded(const extension: ICefExtension); override;
    procedure OnExtensionUnloaded(const extension: ICefExtension); override;
    function OnBeforeBackgroundBrowser(const extension: ICefExtension; const url: ustring; var client: ICefClient; var settings: TCefBrowserSettings): boolean; override;
    function OnBeforeBrowser(const extension: ICefExtension; const browser, active_browser: ICefBrowser; index: integer; const url: ustring;
      active: boolean; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings): boolean; override;
    procedure GetActiveBrowser(const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; var aRsltBrowser: ICefBrowser); override;
    function CanAccessBrowser(const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; const target_browser: ICefBrowser): boolean; override;
    function GetExtensionResource(const extension: ICefExtension; const browser: ICefBrowser; const file_: ustring; const callback: ICefGetExtensionResourceCallback): boolean;
      override;
    procedure RemoveReferences; override;

  end;

implementation


procedure TExtensionHandlerRef.OnExtensionLoadFailed(Result: TCefErrorcode);
begin
  if (ExtensionLoadFailedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ExtensionLoadFailedPtr, [integer(Result)]);
  end;
end;

procedure TExtensionHandlerRef.OnExtensionLoaded(const extension: ICefExtension);
begin
  if (ExtensionLoadedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ExtensionLoadedPtr, [extension]);
  end;
end;

procedure TExtensionHandlerRef.OnExtensionUnloaded(const extension: ICefExtension);
begin
  if (ExtensionUnloadedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ExtensionUnloadedPtr, [extension]);
  end;
end;

function TExtensionHandlerRef.OnBeforeBackgroundBrowser(const extension: ICefExtension; const url: ustring; var client: ICefClient; var settings: TCefBrowserSettings): boolean;
begin
  if (BeforeBackgroundBrowserPtr <> nil) then
  begin
    Result := False;
    TCEFEventCallback.SendEvent(BeforeBackgroundBrowserPtr, [extension, PChar(string(url)), @client, @settings, @Result]);
  end;
end;

function TExtensionHandlerRef.OnBeforeBrowser(const extension: ICefExtension; const browser, active_browser: ICefBrowser; index: integer;
  const url: ustring; active: boolean; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings): boolean;
begin
  if (BeforeBrowserPtr <> nil) then
  begin
    Result := False;
    TCEFEventCallback.SendEvent(BeforeBrowserPtr, [extension, browser, active_browser, index, PChar(string(url)), active, @windowInfo, @client, @settings, @Result]);
  end;
end;

procedure TExtensionHandlerRef.GetActiveBrowser(const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; var aRsltBrowser: ICefBrowser);
begin
  if (GetActiveBrowserPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetActiveBrowserPtr, [extension, browser, include_incognito, @aRsltBrowser]);
  end;
end;

function TExtensionHandlerRef.CanAccessBrowser(const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; const target_browser: ICefBrowser): boolean;
begin
  if (CanAccessBrowserPtr <> nil) then
  begin
    Result := False;
    TCEFEventCallback.SendEvent(CanAccessBrowserPtr, [extension, browser, include_incognito, target_browser, @Result]);
  end;
end;

function TExtensionHandlerRef.GetExtensionResource(const extension: ICefExtension; const browser: ICefBrowser; const file_: ustring; const callback: ICefGetExtensionResourceCallback): boolean;
begin
  if (GetExtensionResourcePtr <> nil) then
  begin
    Result := False;
    TCEFEventCallback.SendEvent(GetExtensionResourcePtr, [extension, browser, PChar(string(file_)), callback, @Result]);
  end;
end;

procedure TExtensionHandlerRef.RemoveReferences;
begin
  ExtensionLoadFailedPtr := nil;
  ExtensionLoadedPtr := nil;
  ExtensionUnloadedPtr := nil;
  BeforeBackgroundBrowserPtr := nil;
  BeforeBrowserPtr := nil;
  GetActiveBrowserPtr := nil;
  CanAccessBrowserPtr := nil;
  GetExtensionResourcePtr := nil;
end;

constructor TExtensionHandlerRef.Create;
begin
  inherited Create;
end;

destructor TExtensionHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

end.
