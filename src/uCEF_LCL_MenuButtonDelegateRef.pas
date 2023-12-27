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
  uCEF_LCL_EventCallback;

type

  TMenuButtonDelegateRef = class
  public
    MenuButtonPressedPtr: Pointer;
    constructor Create;
    destructor Destroy;
  end;

implementation

constructor TMenuButtonDelegateRef.Create;
begin
end;

destructor TMenuButtonDelegateRef.Destroy;
begin
end;

end.
