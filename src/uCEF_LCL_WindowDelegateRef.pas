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
  uCEF_LCL_EventCallback;

type

  TWindowDelegateRef = class(TCefWindowDelegateOwn)
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

    // ICefWindowDelegate
    WindowCreatedPtr: Pointer;
    WindowClosingPtr: Pointer;
    WindowDestroyedPtr: Pointer;
    WindowActivationChangedPtr: Pointer;
    WindowBoundsChangedPtr: Pointer;
    GetParentWindowPtr: Pointer;
    GetInitialBoundsPtr: Pointer;
    GetInitialShowStatePtr: Pointer;
    IsFramelessPtr: Pointer;
    CanResizePtr: Pointer;
    CanMaximizePtr: Pointer;
    CanMinimizePtr: Pointer;
    CanClosePtr: Pointer;
    AcceleratorPtr: Pointer;
    KeyEventPtr: Pointer;

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

    // ICefWindowDelegate
    procedure OnWindowCreated(const window_: ICefWindow); override;
    procedure OnWindowClosing(const window_: ICefWindow); override;
    procedure OnWindowDestroyed(const window_: ICefWindow); override;
    procedure OnWindowActivationChanged(const window_: ICefWindow; active: boolean); override;
    procedure OnWindowBoundsChanged(const window_: ICefWindow; const new_bounds: TCefRect); override;
    procedure OnGetParentWindow(const window_: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult: ICefWindow); override;
    procedure OnGetInitialBounds(const window_: ICefWindow; var aResult: TCefRect); override;
    procedure OnGetInitialShowState(const window_: ICefWindow; var aResult: TCefShowState); override;
    procedure OnIsFrameless(const window_: ICefWindow; var aResult: boolean); override;
    procedure OnCanResize(const window_: ICefWindow; var aResult: boolean); override;
    procedure OnCanMaximize(const window_: ICefWindow; var aResult: boolean); override;
    procedure OnCanMinimize(const window_: ICefWindow; var aResult: boolean); override;
    procedure OnCanClose(const window_: ICefWindow; var aResult: boolean); override;
    procedure OnAccelerator(const window_: ICefWindow; command_id: integer; var aResult: boolean); override;
    procedure OnKeyEvent(const window_: ICefWindow; const event: TCefKeyEvent; var aResult: boolean); override;

  end;

implementation


// ICefViewDelegate
procedure TWindowDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (GetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (ParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TWindowDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (ChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TWindowDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (WindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowChangedPtr, [view, added]);
  end;
end;

procedure TWindowDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (LayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TWindowDelegateRef.OnFocus(const view: ICefView);
begin
  if (FocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FocusPtr, [view]);
  end;
end;

procedure TWindowDelegateRef.OnBlur(const view: ICefView);
begin
  if (BlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BlurPtr, [view]);
  end;
end;


// ICefWindowDelegate
procedure TWindowDelegateRef.OnWindowCreated(const window_: ICefWindow);
begin
  if (WindowCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowCreatedPtr, [window_]);
  end;
end;

procedure TWindowDelegateRef.OnWindowClosing(const window_: ICefWindow);
begin
  if (WindowClosingPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowClosingPtr, [window_]);
  end;
end;

procedure TWindowDelegateRef.OnWindowDestroyed(const window_: ICefWindow);
begin
  if (WindowDestroyedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowDestroyedPtr, [window_]);
  end;
end;

procedure TWindowDelegateRef.OnWindowActivationChanged(const window_: ICefWindow; active: boolean);
begin
  if (WindowActivationChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowActivationChangedPtr, [window_, active]);
  end;
end;

procedure TWindowDelegateRef.OnWindowBoundsChanged(const window_: ICefWindow; const new_bounds: TCefRect);
begin
  if (WindowBoundsChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowBoundsChangedPtr, [window_, @new_bounds]);
  end;
end;

procedure TWindowDelegateRef.OnGetParentWindow(const window_: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult: ICefWindow);
begin
  if (GetParentWindowPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetParentWindowPtr, [window_, @is_menu, @can_activate_menu, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetInitialBounds(const window_: ICefWindow; var aResult: TCefRect);
begin
  if (GetInitialBoundsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetInitialBoundsPtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnGetInitialShowState(const window_: ICefWindow; var aResult: TCefShowState);
begin
  if (GetInitialShowStatePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetInitialShowStatePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnIsFrameless(const window_: ICefWindow; var aResult: boolean);
begin
  if (IsFramelessPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(IsFramelessPtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanResize(const window_: ICefWindow; var aResult: boolean);
begin
  if (CanResizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanResizePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanMaximize(const window_: ICefWindow; var aResult: boolean);
begin
  if (CanMaximizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanMaximizePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanMinimize(const window_: ICefWindow; var aResult: boolean);
begin
  if (CanMinimizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanMinimizePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnCanClose(const window_: ICefWindow; var aResult: boolean);
begin
  if (CanClosePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanClosePtr, [window_, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnAccelerator(const window_: ICefWindow; command_id: integer; var aResult: boolean);
begin
  if (AcceleratorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AcceleratorPtr, [window_, command_id, @aResult]);
  end;
end;

procedure TWindowDelegateRef.OnKeyEvent(const window_: ICefWindow; const event: TCefKeyEvent; var aResult: boolean);
begin
  if (KeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(KeyEventPtr, [window_, @event, @aResult]);
  end;
end;


constructor TWindowDelegateRef.Create;
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

  WindowCreatedPtr := nil;
  WindowClosingPtr := nil;
  WindowDestroyedPtr := nil;
  WindowActivationChangedPtr := nil;
  WindowBoundsChangedPtr := nil;
  GetParentWindowPtr := nil;
  GetInitialBoundsPtr := nil;
  GetInitialShowStatePtr := nil;
  IsFramelessPtr := nil;
  CanResizePtr := nil;
  CanMaximizePtr := nil;
  CanMinimizePtr := nil;
  CanClosePtr := nil;
  AcceleratorPtr := nil;
  KeyEventPtr := nil;
end;

destructor TWindowDelegateRef.Destroy;
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

  WindowCreatedPtr := nil;
  WindowClosingPtr := nil;
  WindowDestroyedPtr := nil;
  WindowActivationChangedPtr := nil;
  WindowBoundsChangedPtr := nil;
  GetParentWindowPtr := nil;
  GetInitialBoundsPtr := nil;
  GetInitialShowStatePtr := nil;
  IsFramelessPtr := nil;
  CanResizePtr := nil;
  CanMaximizePtr := nil;
  CanMinimizePtr := nil;
  CanClosePtr := nil;
  AcceleratorPtr := nil;
  KeyEventPtr := nil;
end;

end.
