//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_WindowDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFWindowDelegate,
  uCEF_LCL_Entity, uCEF_LCL_EventCallback;

type

  TWindowDelegateRef = class(TCefWindowDelegateOwn)
  public
    // ICefViewDelegate
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

    // ICefWindowDelegate
    OnWindowCreatedPtr: Pointer;
    OnWindowClosingPtr: Pointer;
    OnWindowDestroyedPtr: Pointer;
    OnWindowActivationChangedPtr: Pointer;
    OnWindowBoundsChangedPtr: Pointer;
    OnWindowFullscreenTransitionPtr: Pointer;
    OnGetParentWindowPtr: Pointer;
    OnIsWindowModalDialogPtr: Pointer;
    OnGetInitialBoundsPtr: Pointer;
    OnGetInitialShowStatePtr: Pointer;
    OnIsFramelessPtr: Pointer;
    OnWithStandardWindowButtonsPtr: Pointer;
    OnGetTitlebarHeightPtr: Pointer;
    OnAcceptsFirstMousePtr: Pointer;
    OnCanResizePtr: Pointer;
    OnCanMaximizePtr: Pointer;
    OnCanMinimizePtr: Pointer;
    OnCanClosePtr: Pointer;
    OnAcceleratorPtr: Pointer;
    OnKeyEventPtr: Pointer;
    OnThemeColorsChangedPtr: Pointer;
    OnGetWindowRuntimeStylePtr: Pointer;
    OnGetLinuxWindowPropertiesPtr: Pointer;

    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure PtrSetNil();

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

    // ICefWindowDelegate
    procedure OnWindowCreated(const window_: ICefWindow); override;
    procedure OnWindowClosing(const window_: ICefWindow); override;
    procedure OnWindowDestroyed(const window_: ICefWindow); override;
    procedure OnWindowActivationChanged(const window_: ICefWindow; active: boolean); override;
    procedure OnWindowBoundsChanged(const window_: ICefWindow; const new_bounds: TCefRect); override;
    procedure OnWindowFullscreenTransition(const window_: ICefWindow; is_completed: boolean); override;
    procedure OnGetParentWindow(const window_: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult : ICefWindow); override;
    procedure OnIsWindowModalDialog(const window_: ICefWindow; var aResult: boolean); override;
    procedure OnGetInitialBounds(const window_: ICefWindow; var aResult : TCefRect); override;
    procedure OnGetInitialShowState(const window_: ICefWindow; var aResult : TCefShowState); override;
    procedure OnIsFrameless(const window_: ICefWindow; var aResult : boolean); override;
    procedure OnWithStandardWindowButtons(const window_: ICefWindow; var aResult : boolean); override;
    procedure OnGetTitlebarHeight(const window_: ICefWindow; var titlebar_height: Single; var aResult : boolean); override;
    procedure OnAcceptsFirstMouse(const window_: ICefWindow; var aResult: TCefState); override;
    procedure OnCanResize(const window_: ICefWindow; var aResult : boolean); override;
    procedure OnCanMaximize(const window_: ICefWindow; var aResult : boolean); override;
    procedure OnCanMinimize(const window_: ICefWindow; var aResult : boolean); override;
    procedure OnCanClose(const window_: ICefWindow; var aResult : boolean); override;
    procedure OnAccelerator(const window_: ICefWindow; command_id: Integer; var aResult : boolean); override;
    procedure OnKeyEvent(const window_: ICefWindow; const event: TCefKeyEvent; var aResult : boolean); override;
    procedure OnThemeColorsChanged(const window_: ICefWindow; chrome_theme: Integer); override;
    procedure OnGetWindowRuntimeStyle(var aResult: TCefRuntimeStyle); override;
    procedure OnGetLinuxWindowProperties(const window_: ICefWindow; var properties: TLinuxWindowProperties; var aResult: boolean); override;

  end;

implementation


constructor TWindowDelegateRef.Create;
begin
  inherited Create;
  PtrSetNil();
end;

destructor TWindowDelegateRef.Destroy;
begin
  inherited Destroy;
  PtrSetNil();
end;

// ICefViewDelegate
procedure TWindowDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (OnGetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (OnParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TWindowDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (OnChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TWindowDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (OnWindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowChangedPtr, [view, added]);
  end;
end;

procedure TWindowDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (OnLayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnLayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TWindowDelegateRef.OnFocus(const view: ICefView);
begin
  if (OnFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnFocusPtr, [view]);
  end;
end;

procedure TWindowDelegateRef.OnBlur(const view: ICefView);
begin
  if (OnBlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBlurPtr, [view]);
  end;
end;

procedure TWindowDelegateRef.OnThemeChanged(const view: ICefView);
begin
  if (OnThemeChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnThemeChangedPtr, [view]);
  end;
end;


// ICefWindowDelegate
procedure TWindowDelegateRef.OnWindowCreated(const window_: ICefWindow);
begin
  if (OnWindowCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowCreatedPtr, [window_]);
  end;
end;

procedure TWindowDelegateRef.OnWindowClosing(const window_: ICefWindow);
begin
  if (OnWindowClosingPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowClosingPtr, [window_]);
  end;
end;

procedure TWindowDelegateRef.OnWindowDestroyed(const window_: ICefWindow);
begin
  if (OnWindowDestroyedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowDestroyedPtr, [window_]);
  end;
end;

procedure TWindowDelegateRef.OnWindowActivationChanged(const window_: ICefWindow; active: boolean);
begin
  if (OnWindowActivationChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowActivationChangedPtr, [window_, active]);
  end;
end;

procedure TWindowDelegateRef.OnWindowBoundsChanged(const window_: ICefWindow; const new_bounds: TCefRect);
begin
  if (OnWindowBoundsChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowBoundsChangedPtr, [window_, @new_bounds]);
  end;
end;

procedure TWindowDelegateRef.OnWindowFullscreenTransition(const window_: ICefWindow; is_completed: boolean);
begin
  if (OnWindowFullscreenTransitionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowFullscreenTransitionPtr, [window_, is_completed]);
  end;
end;

procedure TWindowDelegateRef.OnGetParentWindow(const window_: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult: ICefWindow);
begin
  if (OnGetParentWindowPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetParentWindowPtr, [window_, @is_menu, @can_activate_menu, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnIsWindowModalDialog(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnIsWindowModalDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnIsWindowModalDialogPtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetInitialBounds(const window_: ICefWindow; var aResult: TCefRect);
begin
  if (OnGetInitialBoundsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetInitialBoundsPtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetInitialShowState(const window_: ICefWindow; var aResult: TCefShowState);
begin
  if (OnGetInitialShowStatePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetInitialShowStatePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnIsFrameless(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnIsFramelessPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnIsFramelessPtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnWithStandardWindowButtons(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnWithStandardWindowButtonsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWithStandardWindowButtonsPtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetTitlebarHeight(const window_: ICefWindow; var titlebar_height: single; var aResult: boolean);
begin
  if (OnGetTitlebarHeightPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetTitlebarHeightPtr, [window_, @titlebar_height, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnAcceptsFirstMouse(const window_: ICefWindow; var aResult: TCefState);
begin
  if (OnAcceptsFirstMousePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnAcceptsFirstMousePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanResize(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnCanResizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnCanResizePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanMaximize(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnCanMaximizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnCanMaximizePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanMinimize(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnCanMinimizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnCanMinimizePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanClose(const window_: ICefWindow; var aResult: boolean);
begin
  if (OnCanClosePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnCanClosePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnAccelerator(const window_: ICefWindow; command_id: integer; var aResult: boolean);
begin
  if (OnAcceleratorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnAcceleratorPtr, [window_, command_id, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnKeyEvent(const window_: ICefWindow; const event: TCefKeyEvent; var aResult: boolean);
begin
  if (OnKeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnKeyEventPtr, [window_, @event, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnThemeColorsChanged(const window_: ICefWindow; chrome_theme: Integer);
begin
  if (OnThemeColorsChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnThemeColorsChangedPtr, [window_, chrome_theme]);
  end;
end;

procedure TWindowDelegateRef.OnGetWindowRuntimeStyle(var aResult: TCefRuntimeStyle);
begin
  if (OnGetWindowRuntimeStylePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetWindowRuntimeStylePtr, [@aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetLinuxWindowProperties(const window_: ICefWindow; var properties: TLinuxWindowProperties; var aResult: boolean);
var
  TempLinuxWindowProperties: PLinuxWindowProperties;
begin
  if (OnGetLinuxWindowPropertiesPtr <> nil) then
  begin
    TempLinuxWindowProperties := CefLinuxWindowPropertiesToGoLinuxWindowProperties(properties);
    TCEFEventCallback.SendEvent(OnGetLinuxWindowPropertiesPtr, [window_, @properties, @aResult]);
    properties := GoLinuxWindowPropertiesToCefLinuxWindowProperties(TempLinuxWindowProperties);
  end;
end;


procedure TWindowDelegateRef.PtrSetNil();
begin
   // ICefViewDelegate
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

   // ICefWindowDelegate
   OnWindowCreatedPtr :=nil;
   OnWindowClosingPtr :=nil;
   OnWindowDestroyedPtr :=nil;
   OnWindowActivationChangedPtr :=nil;
   OnWindowBoundsChangedPtr :=nil;
   OnWindowFullscreenTransitionPtr :=nil;
   OnGetParentWindowPtr :=nil;
   OnIsWindowModalDialogPtr :=nil;
   OnGetInitialBoundsPtr :=nil;
   OnGetInitialShowStatePtr :=nil;
   OnIsFramelessPtr :=nil;
   OnWithStandardWindowButtonsPtr :=nil;
   OnGetTitlebarHeightPtr :=nil;
   OnAcceptsFirstMousePtr :=nil;
   OnCanResizePtr :=nil;
   OnCanMaximizePtr :=nil;
   OnCanMinimizePtr :=nil;
   OnCanClosePtr :=nil;
   OnAcceleratorPtr :=nil;
   OnKeyEventPtr :=nil;
   OnThemeColorsChangedPtr :=nil;
   OnGetWindowRuntimeStylePtr :=nil;
   OnGetLinuxWindowPropertiesPtr :=nil;
end;

end.
