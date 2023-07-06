//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8HandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_Entity, uCEFTypes, uCEFInterfaces, uCEFv8Handler,
  uCEF_LCL_EventCallback;

type

  TV8HandlerRef = class(TCefv8HandlerOwn)
  public
    ExecutePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function Execute(const Name: ustring; const object_: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

function TV8HandlerRef.Execute(const Name: ustring; const object_: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  PName: PChar;
  PException: PChar;
  argumentsLen: Integer;
begin
  Result := False;
  if (ExecutePtr <> nil) then
  begin
    PName := PChar(string(Name));
    argumentsLen := Length(arguments);
    TCEFEventCallback.SendEvent(ExecutePtr, [PName, object_, @arguments[0], argumentsLen, @retval, @PException, @Result]);
    if PException <> nil then
      Exception := PCharToUStr(PException);
    PName := nil;
    PException := nil;
  end;
end;

constructor TV8HandlerRef.Create;
begin
  inherited Create;
end;

destructor TV8HandlerRef.Destroy;
begin
  inherited Destroy;
end;


end.
