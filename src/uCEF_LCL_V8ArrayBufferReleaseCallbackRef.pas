//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8ArrayBufferReleaseCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_EventCallback;

type

  TV8ArrayBufferReleaseCallbackRef = class
  public
    ReleaseBufferPtr: Pointer;
    constructor Create();
    destructor Destroy;
  end;

implementation


constructor TV8ArrayBufferReleaseCallbackRef.Create();
begin
end;

destructor TV8ArrayBufferReleaseCallbackRef.Destroy;
begin
end;

end.
