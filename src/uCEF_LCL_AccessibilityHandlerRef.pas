//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_AccessibilityHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_EventCallback;

type

  TAccessibilityHandlerRef = class
  public
    AccessibilityTreeChangePtr: Pointer;
    AccessibilityLocationChangePtr: Pointer;
    constructor Create;
    destructor Destroy;

  end;

implementation

constructor TAccessibilityHandlerRef.Create;
begin
end;

destructor TAccessibilityHandlerRef.Destroy;
begin
end;

end.
