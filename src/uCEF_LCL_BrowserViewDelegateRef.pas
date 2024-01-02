//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_BrowserViewDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_Entity,
  uCEFBrowserViewDelegate,
  uCEF_LCL_EventCallback;

type

  TBrowserViewDelegateRef = class(TCefBrowserViewDelegateOwn)
  public
    BrowserCreatedPtr: Pointer;
    BrowserDestroyedPtr: Pointer;
    GetDelegateForPopupBrowserViewPtr: Pointer;
    PopupBrowserViewCreatedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
    function  GetChromeToolbarType: Integer;
  protected
    procedure OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate); override;
    procedure OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean); override;
    procedure InitializeCEFMethods; override;

  end;

implementation

procedure TBrowserViewDelegateRef.OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  if (BrowserCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BrowserCreatedPtr, [browser_view, browser]);
  end;
end;

procedure TBrowserViewDelegateRef.OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  if (BrowserDestroyedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BrowserDestroyedPtr, [browser_view, browser]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate);
var
  browserSettings: RCefBrowserSettings;
begin
  if (GetDelegateForPopupBrowserViewPtr <> nil) then
  begin
    browserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
    TCEFEventCallback.SendEvent(GetDelegateForPopupBrowserViewPtr, [browser_view, @browserSettings, client, is_devtools, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean);
begin
  if (PopupBrowserViewCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PopupBrowserViewCreatedPtr, [browser_view, popup_browser_view, is_devtools, @aResult]);
  end;
end;

function TBrowserViewDelegateRef.GetChromeToolbarType: Integer;
begin
end;

procedure TBrowserViewDelegateRef.InitializeCEFMethods;
begin
  inherited InitializeCEFMethods;
end;


constructor TBrowserViewDelegateRef.Create;
begin
  inherited Create;
  BrowserCreatedPtr := nil;
  BrowserDestroyedPtr := nil;
  GetDelegateForPopupBrowserViewPtr := nil;
  PopupBrowserViewCreatedPtr := nil;
end;

destructor TBrowserViewDelegateRef.Destroy;
begin
  inherited Destroy;
  BrowserCreatedPtr := nil;
  BrowserDestroyedPtr := nil;
  GetDelegateForPopupBrowserViewPtr := nil;
  PopupBrowserViewCreatedPtr := nil;
end;

end.
