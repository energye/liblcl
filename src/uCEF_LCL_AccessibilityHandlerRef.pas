//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_AccessibilityHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFInterfaces, uCEFAccessibilityHandler,
  uCEF_LCL_EventCallback;

type

  TAccessibilityHandlerRef = class(TCEFAccessibilityHandlerOwn)
  public
    AccessibilityTreeChangePtr: Pointer;
    AccessibilityLocationChangePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnAccessibilityTreeChange(const Value: ICefValue); override;
    procedure OnAccessibilityLocationChange(const Value: ICefValue); override;

  end;

implementation

procedure TAccessibilityHandlerRef.OnAccessibilityTreeChange(const Value: ICefValue);
begin
  if (AccessibilityTreeChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AccessibilityTreeChangePtr, [Value]);
  end;
end;

procedure TAccessibilityHandlerRef.OnAccessibilityLocationChange(const Value: ICefValue);
begin
  if (AccessibilityLocationChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AccessibilityLocationChangePtr, [Value]);
  end;
end;

constructor TAccessibilityHandlerRef.Create;
begin
  inherited Create;
end;

destructor TAccessibilityHandlerRef.Destroy;
begin
  AccessibilityTreeChangePtr := nil;
  AccessibilityLocationChangePtr := nil;
  inherited Destroy;
end;

end.
