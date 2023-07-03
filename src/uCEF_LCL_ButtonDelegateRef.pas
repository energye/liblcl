//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ButtonDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFButtonDelegate,
  uCEF_LCL_EventCallback;

type

  TButtonDelegateRef = class(TCefButtonDelegateOwn)
  public
    ButtonPressedPtr: Pointer;
    ButtonStateChangedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnButtonPressed(const button: ICefButton); override;
    procedure OnButtonStateChanged(const button: ICefButton); override;

    procedure InitializeCEFMethods; override;
  end;

implementation

procedure TButtonDelegateRef.OnButtonPressed(const button: ICefButton);
begin
  if (ButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ButtonPressedPtr, [button]);
  end;
end;

procedure TButtonDelegateRef.OnButtonStateChanged(const button: ICefButton);
begin
  if (ButtonStateChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ButtonStateChangedPtr, [button]);
  end;
end;

procedure TButtonDelegateRef.InitializeCEFMethods;
begin
  inherited InitializeCEFMethods;
end;

constructor TButtonDelegateRef.Create;
begin
  inherited Create;
  ButtonPressedPtr := nil;
  ButtonStateChangedPtr := nil;
end;

destructor TButtonDelegateRef.Destroy;
begin
  inherited Destroy;
  ButtonPressedPtr := nil;
  ButtonStateChangedPtr := nil;
end;

end.
