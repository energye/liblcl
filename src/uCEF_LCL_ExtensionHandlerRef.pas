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
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnExtensionLoadFailed(Result: TCefErrorcode); override;
    procedure OnExtensionLoaded(const extension: ICefExtension); override;
    procedure OnExtensionUnloaded(const extension: ICefExtension); override;
    function OnBeforeBackgroundBrowser(const extension: ICefExtension; const url: ustring; var client: ICefClient; var settings: TCefBrowserSettings): boolean; override;
    function OnBeforeBrowser(const extension: ICefExtension; const browser, active_browser: ICefBrowser; index: integer; const url: ustring; active: boolean; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings): boolean; override;
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
  end
  else
    inherited OnExtensionLoadFailed(Result);
end;

procedure TExtensionHandlerRef.OnExtensionLoaded(const extension: ICefExtension);
begin
  if (ExtensionLoadedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ExtensionLoadedPtr, [extension]);
  end
  else
    inherited OnExtensionLoaded(extension);
end;

procedure TExtensionHandlerRef.OnExtensionUnloaded(const extension: ICefExtension);
begin
  if (ExtensionUnloadedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ExtensionUnloadedPtr, [extension]);
  end
  else
    inherited OnExtensionUnloaded(extension);
end;

function TExtensionHandlerRef.OnBeforeBackgroundBrowser(const extension: ICefExtension; const url: ustring; var client: ICefClient; var settings: TCefBrowserSettings): boolean;
begin
  Result := False;
  if (BeforeBackgroundBrowserPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeBackgroundBrowserPtr, [extension, PChar(string(url)), @client, @settings, @Result]);
  end
  else
    Result := inherited OnBeforeBackgroundBrowser(extension, url, client, settings);
end;

function TExtensionHandlerRef.OnBeforeBrowser(const extension: ICefExtension; const browser, active_browser: ICefBrowser; index: integer; const url: ustring; active: boolean; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings): boolean;
begin
  Result := False;
  if (BeforeBrowserPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeBrowserPtr, [extension, browser, active_browser, index, PChar(string(url)), active, @windowInfo, @client, @settings, @Result]);
  end
  else
    Result := inherited OnBeforeBrowser(extension, browser, active_browser, index, url, active, windowInfo, client, settings);
end;

procedure TExtensionHandlerRef.GetActiveBrowser(const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; var aRsltBrowser: ICefBrowser);
begin
  if (GetActiveBrowserPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetActiveBrowserPtr, [extension, browser, include_incognito, @aRsltBrowser]);
  end
  else
    inherited GetActiveBrowser(extension, browser, include_incognito, aRsltBrowser);
end;

function TExtensionHandlerRef.CanAccessBrowser(const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; const target_browser: ICefBrowser): boolean;
begin
  Result := False;
  if (CanAccessBrowserPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanAccessBrowserPtr, [extension, browser, include_incognito, target_browser, @Result]);
  end
  else
    Result := inherited CanAccessBrowser(extension, browser, include_incognito, target_browser);
end;

function TExtensionHandlerRef.GetExtensionResource(const extension: ICefExtension; const browser: ICefBrowser; const file_: ustring; const callback: ICefGetExtensionResourceCallback): boolean;
begin
  Result := False;
  if (GetExtensionResourcePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetExtensionResourcePtr, [extension, browser, PChar(string(file_)), callback, @Result]);
  end
  else
    Result := inherited GetExtensionResource(extension, browser, file_, callback);
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
