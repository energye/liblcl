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
  uCEF_LCL_EventCallback;

type

  TButtonDelegateRef = class
  public
    ButtonPressedPtr: Pointer;
    ButtonStateChangedPtr: Pointer;
    constructor Create;
    destructor Destroy;
  end;

implementation

constructor TButtonDelegateRef.Create;
begin
end;

destructor TButtonDelegateRef.Destroy;
begin
end;

end.
