//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_TextfieldDelegateRef;

{$MACRO ON}
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
    {$I CEF_LCL_View_Include_Ptr.inc}

    OnKeyEventPtr: Pointer;
    OnAfterUserActionPtr: Pointer;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure PtrSetNil;
  protected
    // ICefViewDelegate
    {$I CEF_LCL_View_Include_Defs.inc}

    // ICefTextfieldDelegate
    procedure OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult : boolean); override;
    procedure OnAfterUserAction(const textfield: ICefTextfield); override;

  end;

implementation

constructor TTextfieldDelegateRef.Create;
begin
  inherited Create;
  PtrSetNil();
end;

destructor TTextfieldDelegateRef.Destroy;
begin
  inherited Destroy;
  PtrSetNil();
end;

procedure TTextfieldDelegateRef.PtrSetNil;
begin
  {$I CEF_LCL_View_Include_PtrSetNil.inc}

  OnKeyEventPtr := nil;
  OnAfterUserActionPtr := nil;
end;

// ICefViewDelegate

{$define ImplViewClassName := TTextfieldDelegateRef}
{$I CEF_LCL_View_Include_Defs_Impl.inc}

procedure TTextfieldDelegateRef.OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult: boolean);
begin
  if (OnKeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnKeyEventPtr, [textfield, @event, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnAfterUserAction(const textfield: ICefTextfield);
begin
  if (OnAfterUserActionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnAfterUserActionPtr, [textfield]);
  end;
end;

end.
