//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_BrowserViewDelegateRef;

{$MACRO ON}
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
    {$I CEF_LCL_View_Include_Ptr.inc}

    OnBrowserCreatedPtr: Pointer;
    OnBrowserDestroyedPtr: Pointer;
    OnGetDelegateForPopupBrowserViewPtr: Pointer;
    OnPopupBrowserViewCreatedPtr: Pointer;
    OnGetChromeToolbarTypePtr: Pointer;
  public
    procedure PtrSetNil;
    constructor Create; override;
    destructor Destroy; override;
  protected
    // ICefViewDelegate
    {$I CEF_LCL_View_Include_Defs.inc}

    // ICefBrowserViewDelegate
    procedure OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult : ICefBrowserViewDelegate); override;
    procedure OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult : boolean); override;

  end;

implementation


constructor TBrowserViewDelegateRef.Create;
begin
  inherited Create;
  PtrSetNil();
end;

destructor TBrowserViewDelegateRef.Destroy;
begin
  inherited Destroy;
  PtrSetNil();
end;

procedure TBrowserViewDelegateRef.PtrSetNil;
begin
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
  OnBrowserCreatedPtr := nil;
  OnBrowserDestroyedPtr := nil;
  OnGetDelegateForPopupBrowserViewPtr := nil;
  OnPopupBrowserViewCreatedPtr := nil;
  OnGetChromeToolbarTypePtr := nil;
end;

// ICefViewDelegate

{$define ImplViewClassName := TBrowserViewDelegateRef}
{$I CEF_LCL_View_Include_Defs_Impl.inc}

procedure TBrowserViewDelegateRef.OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  if (OnBrowserCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBrowserCreatedPtr, [browser_view, browser]);
  end;
end;

procedure TBrowserViewDelegateRef.OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  if (OnBrowserDestroyedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBrowserDestroyedPtr, [browser_view, browser]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate);
var
  browserSettings: PMCefBrowserSettings;
begin
  if (OnGetDelegateForPopupBrowserViewPtr <> nil) then
  begin
    browserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
    TCEFEventCallback.SendEvent(OnGetDelegateForPopupBrowserViewPtr, [browser_view, @browserSettings, client, is_devtools, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean);
begin
  if (OnPopupBrowserViewCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnPopupBrowserViewCreatedPtr, [browser_view, popup_browser_view, is_devtools, @aResult]);
  end;
end;

end.
