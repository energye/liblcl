//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MenuModelDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils,uCEFInterfaces, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TMenuModelDelegateRef = class
  public
    ExecuteCommandPtr: Pointer;
    MouseOutsideMenuPtr: Pointer;
    UnhandledOpenSubmenuPtr: Pointer;
    UnhandledCloseSubmenuPtr: Pointer;
    MenuWillShowPtr: Pointer;
    MenuClosedPtr: Pointer;
    FormatLabelPtr: Pointer;
    constructor Create;
    destructor Destroy;

  end;

implementation


constructor TMenuModelDelegateRef.Create;
begin
end;

destructor TMenuModelDelegateRef.Destroy;
begin
end;

end.
