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

    OnButtonPressedPtr: Pointer;
    OnButtonStateChangedPtr: Pointer;

    OnMenuButtonPressedPtr: Pointer;
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

    // ICefButtonDelegate
    procedure OnButtonPressed(const button: ICefButton); override;
    procedure OnButtonStateChanged(const button: ICefButton); override;

    // ICefMenuButtonDelegate
    procedure OnMenuButtonPressed(const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock); override;

  end;

implementation


constructor TMenuButtonDelegateRef.Create;
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
  OnButtonPressedPtr := nil;
  OnButtonStateChangedPtr := nil;
  OnMenuButtonPressedPtr := nil;
end;

destructor TMenuButtonDelegateRef.Destroy;
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
  OnButtonPressedPtr := nil;
  OnButtonStateChangedPtr := nil;
  OnMenuButtonPressedPtr := nil;
end;

// ICefViewDelegate
procedure TMenuButtonDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (OnGetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TMenuButtonDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (OnParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TMenuButtonDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (OnChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TMenuButtonDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (OnWindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowChangedPtr, [view, added]);
  end;
end;

procedure TMenuButtonDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (OnLayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnLayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TMenuButtonDelegateRef.OnFocus(const view: ICefView);
begin
  if (OnFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnFocusPtr, [view]);
  end;
end;

procedure TMenuButtonDelegateRef.OnBlur(const view: ICefView);
begin
  if (OnBlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBlurPtr, [view]);
  end;
end;

procedure TMenuButtonDelegateRef.OnThemeChanged(const view: ICefView);
begin
  if (OnThemeChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnThemeChangedPtr, [view]);
  end;
end;
procedure TMenuButtonDelegateRef.OnButtonPressed(const button: ICefButton);
begin
  if (OnButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnButtonPressedPtr, [button]);
  end;
end;
procedure TMenuButtonDelegateRef.OnButtonStateChanged(const button: ICefButton);
begin
  if (OnButtonStateChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnButtonStateChangedPtr, [button]);
  end;
end;

procedure TMenuButtonDelegateRef.OnMenuButtonPressed(const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock);
begin
  if (OnMenuButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnMenuButtonPressedPtr, [menu_button, @screen_point, button_pressed_lock]);
  end;
end;

end.
