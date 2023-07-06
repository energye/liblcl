//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8ArrayBufferReleaseCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFv8ArrayBufferReleaseCallback,
  uCEF_LCL_EventCallback;

type

  TV8ArrayBufferReleaseCallbackRef = class(TCefFastv8ArrayBufferReleaseCallback)
  public
    ReleaseBufferPtr: Pointer;
    constructor Create();
    destructor Destroy; override;
  protected
    procedure ReleaseBuffer(buffer: Pointer); override;
  end;

implementation

procedure TV8ArrayBufferReleaseCallbackRef.ReleaseBuffer(buffer: Pointer);
var
  isReleaseBuffer: boolean;
begin
  if (ReleaseBufferPtr <> nil) then
  begin
    isReleaseBuffer := False;
    TCEFEventCallback.SendEvent(ReleaseBufferPtr, [@isReleaseBuffer, buffer]);
    if not isReleaseBuffer then
    begin
      exit;
    end;
  end;
  if (buffer <> nil) then FreeMem(buffer);
end;

constructor TV8ArrayBufferReleaseCallbackRef.Create();
begin
  inherited Create(nil);
end;

destructor TV8ArrayBufferReleaseCallbackRef.Destroy;
begin
  inherited Destroy;
end;

end.
