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
    // ICefViewDelegate
    GetPreferredSizePtr: Pointer;
    GetMinimumSizePtr: Pointer;
    GetMaximumSizePtr: Pointer;
    GetHeightForWidthPtr: Pointer;
    ParentViewChangedPtr: Pointer;
    ChildViewChangedPtr: Pointer;
    WindowChangedPtr: Pointer;
    LayoutChangedPtr: Pointer;
    FocusPtr: Pointer;
    BlurPtr: Pointer;

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
  protected
    // ICefViewDelegate
    procedure OnGetPreferredSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetMinimumSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetMaximumSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer); override;
    procedure OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView); override;
    procedure OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView); override;
    procedure OnWindowChanged(const view: ICefView; added: boolean); override;
    procedure OnLayoutChanged(const view: ICefView; new_bounds: TCefRect); override;
    procedure OnFocus(const view: ICefView); override;
    procedure OnBlur(const view: ICefView); override;

    procedure OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate); override;
    procedure OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean); override;
    procedure OnGetChromeToolbarType(const browser_view: ICefBrowserView; var aResult : TCefChromeToolbarType); override;
    procedure OnUseFramelessWindowForPictureInPicture(const browser_view: ICefBrowserView; var aResult: boolean); override;
    procedure OnGestureCommand(const browser_view: ICefBrowserView; gesture_command: TCefGestureCommand; var aResult : boolean); override;

  end;

implementation

// ICefViewDelegate
procedure TBrowserViewDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (GetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TBrowserViewDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (ParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TBrowserViewDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (ChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TBrowserViewDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (WindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowChangedPtr, [view, added]);
  end;
end;

procedure TBrowserViewDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (LayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TBrowserViewDelegateRef.OnFocus(const view: ICefView);
begin
  if (FocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FocusPtr, [view]);
  end;
end;

procedure TBrowserViewDelegateRef.OnBlur(const view: ICefView);
begin
  if (BlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BlurPtr, [view]);
  end;
end;

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


constructor TBrowserViewDelegateRef.Create;
begin
  inherited Create;
  GetPreferredSizePtr := nil;
  GetMinimumSizePtr := nil;
  GetMaximumSizePtr := nil;
  GetHeightForWidthPtr := nil;
  ParentViewChangedPtr := nil;
  ChildViewChangedPtr := nil;
  WindowChangedPtr := nil;
  LayoutChangedPtr := nil;
  FocusPtr := nil;
  BlurPtr := nil;

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
  GetPreferredSizePtr := nil;
  GetMinimumSizePtr := nil;
  GetMaximumSizePtr := nil;
  GetHeightForWidthPtr := nil;
  ParentViewChangedPtr := nil;
  ChildViewChangedPtr := nil;
  WindowChangedPtr := nil;
  LayoutChangedPtr := nil;
  FocusPtr := nil;
  BlurPtr := nil;

  BrowserCreatedPtr := nil;
  BrowserDestroyedPtr := nil;
  GetDelegateForPopupBrowserViewPtr := nil;
  PopupBrowserViewCreatedPtr := nil;
  GetChromeToolbarTypePtr := nil;
  UseFramelessWindowForPictureInPicturePtr := nil;
  GestureCommandPtr := nil;
end;

end.
