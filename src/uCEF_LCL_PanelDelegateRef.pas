//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_PanelDelegateRef;

{$MACRO ON}
{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFPanelDelegate,
  uCEF_LCL_EventCallback;

type

  TPanelDelegateRef = class(TCefPanelDelegateOwn)
  public
    {$I CEF_LCL_View_Include_Ptr.inc}
  public
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure PtrSetNil;
    {$I CEF_LCL_View_Include_Defs.inc}
  end;

implementation

constructor TPanelDelegateRef.Create;
begin
  inherited Create;
  PtrSetNil();
end;

destructor TPanelDelegateRef.Destroy;
begin
  inherited Destroy;
  PtrSetNil();
end;

procedure TPanelDelegateRef.PtrSetNil;
begin
  {$I CEF_LCL_View_Include_PtrSetNil.inc}
end;

// ICefViewDelegate
{$define ImplViewClassName := TPanelDelegateRef}
{$I CEF_LCL_View_Include_Defs_Impl.inc}

end.
