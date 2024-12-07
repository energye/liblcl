//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MenuButtonDelegateRef;

{$MACRO ON}
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
    {$I CEF_LCL_View_Include_Ptr.inc}

    OnButtonPressedPtr: Pointer;
    OnButtonStateChangedPtr: Pointer;

    OnMenuButtonPressedPtr: Pointer;
  public
    constructor Create; override;
    destructor Destroy; override;
  protected
    // ICefViewDelegate
    {$I CEF_LCL_View_Include_Defs.inc}

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
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
  OnButtonPressedPtr := nil;
  OnButtonStateChangedPtr := nil;
  OnMenuButtonPressedPtr := nil;
end;

destructor TMenuButtonDelegateRef.Destroy;
begin
  inherited Destroy;
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
  OnButtonPressedPtr := nil;
  OnButtonStateChangedPtr := nil;
  OnMenuButtonPressedPtr := nil;
end;

{$define ImplViewClassName := TMenuButtonDelegateRef}
{$I CEF_LCL_View_Include_Defs_Impl.inc}

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
