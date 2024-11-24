//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ButtonDelegateRef;

{$MACRO ON}

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
    {$I CEF_LCL_View_Include_Ptr.inc}

    OnButtonPressedPtr: Pointer;
    OnButtonStateChangedPtr: Pointer;
  public
    constructor Create; override;
    destructor Destroy; override;
  protected
    // ICefViewDelegate
    {$I CEF_LCL_View_Include_Defs.inc}

    // ICefButtonDelegate
    procedure OnButtonPressed(const button: ICefButton); override;
    procedure OnButtonStateChanged(const button: ICefButton); override;

  end;

implementation

constructor TButtonDelegateRef.Create;
begin
  inherited Create;
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
  OnButtonPressedPtr := nil;
  OnButtonStateChangedPtr := nil;
end;

destructor TButtonDelegateRef.Destroy;
begin
  inherited Destroy;
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
  OnButtonPressedPtr := nil;
  OnButtonStateChangedPtr := nil;
end;

// ICefViewDelegate
{$define ImplViewClassName := TButtonDelegateRef}
{$I CEF_LCL_View_Include_Defs_Impl.inc}

procedure TButtonDelegateRef.OnButtonPressed(const button: ICefButton);
begin
  if (OnButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnButtonPressedPtr, [button]);
  end;
end;

procedure TButtonDelegateRef.OnButtonStateChanged(const button: ICefButton);
begin
  if (OnButtonStateChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnButtonStateChangedPtr, [button]);
  end;
end;

end.
