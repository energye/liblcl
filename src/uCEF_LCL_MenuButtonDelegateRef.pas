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
    MenuButtonPressedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnMenuButtonPressed(const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock); override;

    procedure InitializeCEFMethods; override;
  end;

implementation

procedure TMenuButtonDelegateRef.OnMenuButtonPressed(const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock);
begin
  if (MenuButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MenuButtonPressedPtr, [menu_button, @screen_point, button_pressed_lock]);
  end;
end;

procedure TMenuButtonDelegateRef.InitializeCEFMethods;
begin
  inherited InitializeCEFMethods;
end;

constructor TMenuButtonDelegateRef.Create;
begin
  inherited Create;
  MenuButtonPressedPtr := nil;
end;

destructor TMenuButtonDelegateRef.Destroy;
begin
  inherited Destroy;
  MenuButtonPressedPtr := nil;
end;

end.
