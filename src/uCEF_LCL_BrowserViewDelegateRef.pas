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
    // ptr
    BrowserCreatedPtr: Pointer;
    BrowserDestroyedPtr: Pointer;
    GetDelegateForPopupBrowserViewPtr: Pointer;
    PopupBrowserViewCreatedPtr: Pointer;
    GetChromeToolbarTypePtr: Pointer;
    UseFramelessWindowForPictureInPicturePtr: Pointer;
    GestureCommandPtr: Pointer;
    // override
    constructor Create; override;
    destructor Destroy; override;
    procedure OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate); override;
    procedure OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean); override;
    procedure OnGetChromeToolbarType(const browser_view: ICefBrowserView; var aResult : TCefChromeToolbarType); override;
    procedure OnUseFramelessWindowForPictureInPicture(const browser_view: ICefBrowserView; var aResult: boolean); override;
    procedure OnGestureCommand(const browser_view: ICefBrowserView; gesture_command: TCefGestureCommand; var aResult : boolean); override;
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
  browserSettings: PRCefBrowserSettings;
begin
  try
    if (GetDelegateForPopupBrowserViewPtr <> nil) then
    begin
      browserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
      TCEFEventCallback.SendEvent(GetDelegateForPopupBrowserViewPtr, [browser_view, browserSettings, client, is_devtools, @aResult]);
    end;
  finally
    browserSettings := nil;
  end;
end;

procedure TBrowserViewDelegateRef.OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean);
begin
  if (PopupBrowserViewCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PopupBrowserViewCreatedPtr, [browser_view, popup_browser_view, is_devtools, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetChromeToolbarType(const browser_view: ICefBrowserView; var aResult : TCefChromeToolbarType);
begin
  if (GetChromeToolbarTypePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetChromeToolbarTypePtr, [browser_view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnUseFramelessWindowForPictureInPicture(const browser_view: ICefBrowserView; var aResult: boolean);
begin
  if (UseFramelessWindowForPictureInPicturePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(UseFramelessWindowForPictureInPicturePtr, [browser_view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGestureCommand(const browser_view: ICefBrowserView; gesture_command: TCefGestureCommand; var aResult : boolean);
begin
  if (GestureCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GestureCommandPtr, [browser_view, gesture_command, @aResult]);
  end;
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
  GetChromeToolbarTypePtr := nil;
  UseFramelessWindowForPictureInPicturePtr := nil;
  GestureCommandPtr := nil;
end;

destructor TBrowserViewDelegateRef.Destroy;
begin
  inherited Destroy;
  BrowserCreatedPtr := nil;
  BrowserDestroyedPtr := nil;
  GetDelegateForPopupBrowserViewPtr := nil;
  PopupBrowserViewCreatedPtr := nil;
  GetChromeToolbarTypePtr := nil;
  UseFramelessWindowForPictureInPicturePtr := nil;
  GestureCommandPtr := nil;
end;

end.
