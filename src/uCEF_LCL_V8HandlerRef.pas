//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8HandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_Entity, uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler,
  uEventCallback;

type

  TV8HandlerRef = class(TCefv8HandlerOwn)
  public
    ExecutePtr: Pointer;
    constructor Create;
    destructor Destroy;
  protected
    function Execute(const Name: ustring; const object_: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    procedure SendEvent(DataPtr: Pointer; AArgs: array of const);
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
    SendEvent(ExecutePtr, [PName, object_, @arguments[0], argumentsLen, @retval, @PException, @Result]);
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

procedure TV8HandlerRef.SendEvent(DataPtr: Pointer; AArgs: array of const);
var
  LParams: array[0..CALL_MAX_PARAM - 1] of Pointer;
  LArgLen: integer;
  LV: TVarRec;
  I: integer;
begin
  if Assigned(GEventCallbackPtr) then
  begin
    LArgLen := Length(AArgs);
    if LArgLen <= Length(LParams) then
    begin
      for I := 0 to LArgLen - 1 do
      begin
        LV := AArgs[I];
        case LV.VType of
          vtInteger: LParams[I] := Pointer(LV.VInteger);
          vtBoolean: LParams[I] := Pointer(byte(LV.VBoolean));
          vtChar: LParams[I] := Pointer(Ord(LV.VChar));
          vtExtended: LParams[I] := LV.VExtended;
          vtString: LParams[I] :=
{$IFDEF MSWINDOWS}
              LV.VString
{$ELSE}LV.VAnsiString{$ENDIF}
            ;
          vtPointer: LParams[I] := LV.VPointer;
          vtPChar: LParams[I] := LV.VPChar;
          vtObject: LParams[I] := LV.VObject;
          vtClass: LParams[I] := LV.VClass;
          vtWideChar: LParams[I] := Pointer(Ord(LV.VWideChar));
          vtPWideChar: LParams[I] := LV.VPWideChar;
          vtAnsiString: LParams[I] := LV.VAnsiString;
          //          vtCurrency      = 12;
          //          vtVariant       = 13;
          vtInterface: LParams[I] := LV.VInterface;
          vtWideString: LParams[I] := LV.VWideString;
          vtInt64: LParams[I] := LV.VInt64;
          vtUnicodeString: LParams[I] := LV.VUnicodeString;
        end;
      end;
      GEventCallbackPtr(DataPtr, @LParams[0], LArgLen);
    end;
  end;
end;


end.
