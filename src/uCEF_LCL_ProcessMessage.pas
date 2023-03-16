//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ProcessMessage;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_Entity, uCEFTypes, uCEFInterfaces, uCEFv8Handler,
  uCEF_LCL_EventCallback;

type

  TProcessMessage = class
  public
    constructor Create;
    destructor Destroy;
  protected
  end;

implementation

constructor TProcessMessage.Create;
begin
  inherited Create;
end;

destructor TProcessMessage.Destroy;
begin
  inherited Destroy;
end;


end.
