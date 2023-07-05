//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_TextfieldDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFTextfieldDelegate,
  uCEF_LCL_EventCallback;

type

  TTextfieldDelegateRef = class(TCefTextfieldDelegateOwn)
  public
    KeyEventPtr: Pointer;
    AfterUserActionPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult: boolean); override;
    procedure OnAfterUserAction(const textfield: ICefTextfield); override;

    procedure InitializeCEFMethods; override;
  end;

implementation

procedure TTextfieldDelegateRef.OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult: boolean);
begin
  if (KeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(KeyEventPtr, [textfield, @event, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnAfterUserAction(const textfield: ICefTextfield);
begin
  if (AfterUserActionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AfterUserActionPtr, [textfield]);
  end;
end;

procedure TTextfieldDelegateRef.InitializeCEFMethods;
begin
  inherited InitializeCEFMethods;
end;

constructor TTextfieldDelegateRef.Create;
begin
  inherited Create;
  KeyEventPtr := nil;
  AfterUserActionPtr := nil;
end;

destructor TTextfieldDelegateRef.Destroy;
begin
  inherited Destroy;
  KeyEventPtr := nil;
  AfterUserActionPtr := nil;
end;

end.
