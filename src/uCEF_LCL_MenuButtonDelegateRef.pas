//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MenuButtonDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFMenuButtonDelegate,
  uCEF_LCL_EventCallback;

type

  TMenuButtonDelegateRef = class(TCefMenuButtonDelegateOwn)
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

    MenuButtonPressedPtr: Pointer;
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

    procedure OnMenuButtonPressed(const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock); override;

  end;

implementation


// ICefViewDelegate
procedure TMenuButtonDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (GetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (ParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TMenuButtonDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (ChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TMenuButtonDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (WindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowChangedPtr, [view, added]);
  end;
end;

procedure TMenuButtonDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (LayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TMenuButtonDelegateRef.OnFocus(const view: ICefView);
begin
  if (FocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FocusPtr, [view]);
  end;
end;

procedure TMenuButtonDelegateRef.OnBlur(const view: ICefView);
begin
  if (BlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BlurPtr, [view]);
  end;
end;

procedure TMenuButtonDelegateRef.OnMenuButtonPressed(const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock);
begin
  if (MenuButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MenuButtonPressedPtr, [menu_button, @screen_point, button_pressed_lock]);
  end;
end;


constructor TMenuButtonDelegateRef.Create;
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

  MenuButtonPressedPtr := nil;
end;

destructor TMenuButtonDelegateRef.Destroy;
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

  MenuButtonPressedPtr := nil;
end;

end.
