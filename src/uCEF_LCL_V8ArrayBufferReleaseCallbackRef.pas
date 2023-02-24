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
  uEventCallback;

type

  TV8ArrayBufferReleaseCallbackRef = class(TCefFastv8ArrayBufferReleaseCallback)
  public
    ReleaseBufferPtr: Pointer;
    constructor Create();
    destructor Destroy;
  protected
    procedure ReleaseBuffer(buffer: Pointer); override;
    procedure SendEvent(DataPtr: Pointer; AArgs: array of const);
  end;

implementation

procedure TV8ArrayBufferReleaseCallbackRef.ReleaseBuffer(buffer: Pointer);
var
  isReleaseBuffer: boolean;
begin
  if (ReleaseBufferPtr <> nil) then
  begin
    isReleaseBuffer := False;
    SendEvent(ReleaseBufferPtr, [@isReleaseBuffer, buffer]);
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

procedure TV8ArrayBufferReleaseCallbackRef.SendEvent(DataPtr: Pointer; AArgs: array of const);
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
