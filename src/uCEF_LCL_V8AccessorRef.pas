//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8AccessorRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_Entity, uCEFv8Accessor, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TV8AccessorRef = class(TCefV8AccessorOwn)
  public
    GetPtr: Pointer;
    SetPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function Get(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function Set_(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

function TV8AccessorRef.Get(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  PName: PChar;
  PException: PChar;
begin
  Result := False;
  if (GetPtr <> nil) then
  begin
    PName := PChar(string(Name));
    TCEFEventCallback.SendEvent(GetPtr, [PName, object_, @retval, @PException, @Result]);
    if PException <> nil then
      Exception := PCharToUStr(PException);
    PName := nil;
    PException := nil;
  end;
end;


function TV8AccessorRef.Set_(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
var
  PName: PChar;
  PException: PChar;
begin
  Result := False;
  if (SetPtr <> nil) then
  begin
    PName := PChar(string(Name));
    TCEFEventCallback.SendEvent(SetPtr, [PName, object_, Value, @PException, @Result]);
    if PException <> nil then
      Exception := PCharToUStr(PException);
    PName := nil;
    PException := nil;
  end;
end;

constructor TV8AccessorRef.Create;
begin
  inherited Create;
end;

destructor TV8AccessorRef.Destroy;
begin
  inherited Destroy;
end;

end.
