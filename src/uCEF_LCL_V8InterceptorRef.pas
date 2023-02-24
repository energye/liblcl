//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8InterceptorRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Interceptor,
  uEventCallback;

type

  TV8InterceptorRef = class(TCefV8InterceptorOwn)
  public
    GetByNamePtr: Pointer;
    GetByIndexPtr: Pointer;
    SetByNamePtr: Pointer;
    SetByIndexPtr: Pointer;
    constructor Create;
    destructor Destroy;
  protected
    function GetByName(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function GetByIndex(index: integer; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function SetByName(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
    function SetByIndex(index: integer; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
    procedure SendEvent(DataPtr: Pointer; AArgs: array of const);
  end;

implementation


function TV8InterceptorRef.GetByName(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
begin
  if (GetByNamePtr <> nil) then
  begin
    SendEvent(GetByNamePtr, []);
  end;
end;

function TV8InterceptorRef.GetByIndex(index: integer; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
begin
  if (GetByIndexPtr <> nil) then
  begin
    SendEvent(GetByIndexPtr, []);
  end;
end;

function TV8InterceptorRef.SetByName(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
begin
  if (SetByNamePtr <> nil) then
  begin
    SendEvent(SetByNamePtr, []);
  end;
end;

function TV8InterceptorRef.SetByIndex(index: integer; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
begin
  if (SetByIndexPtr <> nil) then
  begin
    SendEvent(SetByIndexPtr, []);
  end;
end;

constructor TV8InterceptorRef.Create;
begin
  inherited Create;
end;

destructor TV8InterceptorRef.Destroy;
begin
  inherited Destroy;
end;

procedure TV8InterceptorRef.SendEvent(DataPtr: Pointer; AArgs: array of const);
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
