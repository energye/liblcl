//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ViewDelegateRef;

{$MACRO ON}
{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFViewDelegate,
  uCEF_LCL_EventCallback;

type

  TViewDelegateRef = class(TCefViewDelegateOwn)
  public
    {$I CEF_LCL_View_Include_Ptr.inc}
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure PtrSetNil;
  protected
    {$I CEF_LCL_View_Include_Defs.inc}
  end;

implementation


constructor TViewDelegateRef.Create;
begin
  inherited Create;
  PtrSetNil();
end;

destructor TViewDelegateRef.Destroy;
begin
  inherited Destroy;
  PtrSetNil();
end;

procedure TViewDelegateRef.PtrSetNil;
begin
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
end;

{$define ImplViewClassName := TViewDelegateRef}
{$I CEF_LCL_View_Include_Defs_Impl.inc}

end.
