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
    OnGetPreferredSizePtr: Pointer;
    OnGetMinimumSizePtr: Pointer;
    OnGetMaximumSizePtr: Pointer;
    OnGetHeightForWidthPtr: Pointer;
    OnParentViewChangedPtr: Pointer;
    OnChildViewChangedPtr: Pointer;
    OnWindowChangedPtr: Pointer;
    OnLayoutChangedPtr: Pointer;
    OnFocusPtr: Pointer;
    OnBlurPtr: Pointer;
    OnThemeChangedPtr: Pointer;

    OnBrowserCreatedPtr: Pointer;
    OnBrowserDestroyedPtr: Pointer;
    OnGetDelegateForPopupBrowserViewPtr: Pointer;
    OnPopupBrowserViewCreatedPtr: Pointer;
    OnGetChromeToolbarTypePtr: Pointer;
    OnUseFramelessWindowForPictureInPicturePtr: Pointer;
    OnGestureCommandPtr: Pointer;
    OnGetBrowserRuntimeStylePtr: Pointer;
  public
    constructor Create; override;
    destructor Destroy; override;
  protected
    // ICefViewDelegate
    procedure OnGetPreferredSize(const view: ICefView; var aResult : TCefSize); override;
    procedure OnGetMinimumSize(const view: ICefView; var aResult : TCefSize); override;
    procedure OnGetMaximumSize(const view: ICefView; var aResult : TCefSize); override;
    procedure OnGetHeightForWidth(const view: ICefView; width: Integer; var aResult: Integer); override;
    procedure OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView); override;
    procedure OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView); override;
    procedure OnWindowChanged(const view: ICefView; added: boolean); override;
    procedure OnLayoutChanged(const view: ICefView; new_bounds: TCefRect); override;
    procedure OnFocus(const view: ICefView); override;
    procedure OnBlur(const view: ICefView); override;
    procedure OnThemeChanged(const view: ICefView); override;

    // ICefBrowserViewDelegate
    procedure OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult : ICefBrowserViewDelegate); override;
    procedure OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult : boolean); override;
    procedure OnGetChromeToolbarType(const browser_view: ICefBrowserView; var aResult: TCefChromeToolbarType); override;
    procedure OnUseFramelessWindowForPictureInPicture(const browser_view: ICefBrowserView; var aResult: boolean); override;
    procedure OnGestureCommand(const browser_view: ICefBrowserView; gesture_command: TCefGestureCommand; var aResult : boolean); override;
    procedure OnGetBrowserRuntimeStyle(var aResult : TCefRuntimeStyle); override;

  end;

implementation


constructor TBrowserViewDelegateRef.Create;
begin
  inherited Create;

  OnGetPreferredSizePtr := nil;
  OnGetMinimumSizePtr := nil;
  OnGetMaximumSizePtr := nil;
  OnGetHeightForWidthPtr := nil;
  OnParentViewChangedPtr := nil;
  OnChildViewChangedPtr := nil;
  OnWindowChangedPtr := nil;
  OnLayoutChangedPtr := nil;
  OnFocusPtr := nil;
  OnBlurPtr := nil;
  OnThemeChangedPtr := nil;
  OnBrowserCreatedPtr := nil;
  OnBrowserDestroyedPtr := nil;
  OnGetDelegateForPopupBrowserViewPtr := nil;
  OnPopupBrowserViewCreatedPtr := nil;
  OnGetChromeToolbarTypePtr := nil;
  OnUseFramelessWindowForPictureInPicturePtr := nil;
  OnGestureCommandPtr := nil;
end;

destructor TBrowserViewDelegateRef.Destroy;
begin
  inherited Destroy;

  OnGetPreferredSizePtr := nil;
  OnGetMinimumSizePtr := nil;
  OnGetMaximumSizePtr := nil;
  OnGetHeightForWidthPtr := nil;
  OnParentViewChangedPtr := nil;
  OnChildViewChangedPtr := nil;
  OnWindowChangedPtr := nil;
  OnLayoutChangedPtr := nil;
  OnFocusPtr := nil;
  OnBlurPtr := nil;
  OnThemeChangedPtr := nil;
  OnBrowserCreatedPtr := nil;
  OnBrowserDestroyedPtr := nil;
  OnGetDelegateForPopupBrowserViewPtr := nil;
  OnPopupBrowserViewCreatedPtr := nil;
  OnGetChromeToolbarTypePtr := nil;
  OnUseFramelessWindowForPictureInPicturePtr := nil;
  OnGestureCommandPtr := nil;
end;

// ICefViewDelegate
procedure TBrowserViewDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (OnGetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (OnParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TBrowserViewDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (OnChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TBrowserViewDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (OnWindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowChangedPtr, [view, added]);
  end;
end;

procedure TBrowserViewDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (OnLayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnLayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TBrowserViewDelegateRef.OnFocus(const view: ICefView);
begin
  if (OnFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnFocusPtr, [view]);
  end;
end;

procedure TBrowserViewDelegateRef.OnBlur(const view: ICefView);
begin
  if (OnBlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBlurPtr, [view]);
  end;
end;

procedure TBrowserViewDelegateRef.OnThemeChanged(const view: ICefView);
begin
  if (OnThemeChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnThemeChangedPtr, [view]);
  end;
end;

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
  browserSettings: RCefBrowserSettings;
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

procedure TBrowserViewDelegateRef.OnGetChromeToolbarType(const browser_view: ICefBrowserView; var aResult : TCefChromeToolbarType);
begin
  if (OnGetChromeToolbarTypePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetChromeToolbarTypePtr, [browser_view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnUseFramelessWindowForPictureInPicture(const browser_view: ICefBrowserView; var aResult: boolean);
begin
  if (OnUseFramelessWindowForPictureInPicturePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnUseFramelessWindowForPictureInPicturePtr, [browser_view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGestureCommand(const browser_view: ICefBrowserView; gesture_command: TCefGestureCommand; var aResult : boolean);
begin
  if (OnGestureCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGestureCommandPtr, [browser_view, gesture_command, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetBrowserRuntimeStyle(var aResult : TCefRuntimeStyle);
begin
  if (OnGetBrowserRuntimeStylePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetBrowserRuntimeStylePtr, [@aResult]);
  end;
end;

end.
