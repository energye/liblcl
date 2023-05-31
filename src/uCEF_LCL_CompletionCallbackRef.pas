//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_CompletionCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFCompletionCallback,
  uCEF_LCL_EventCallback;

type

  TCompletionCallbackRef = class(TCefCompletionCallbackOwn)
  public
    CompletionCallbackPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnComplete(); override;

  end;

implementation

procedure TCompletionCallbackRef.OnComplete();
begin
  if (CompletionCallbackPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CompletionCallbackPtr, []);
  end
  else
    inherited OnComplete();
end;

constructor TCompletionCallbackRef.Create;
begin
  inherited Create;
end;

destructor TCompletionCallbackRef.Destroy;
begin
  inherited Destroy;
end;

end.
