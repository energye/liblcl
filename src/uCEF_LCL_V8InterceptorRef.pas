//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8InterceptorRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFv8Interceptor,
  uCEF_LCL_EventCallback, uCEF_LCL_Entity;

type

  TV8InterceptorRef = class(TCefV8InterceptorOwn)
  public
    GetByNamePtr: Pointer;
    GetByIndexPtr: Pointer;
    SetByNamePtr: Pointer;
    SetByIndexPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function GetByName(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function GetByIndex(index: integer; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean; override;
    function SetByName(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
    function SetByIndex(index: integer; const object_, Value: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

constructor TV8InterceptorRef.Create;
begin
  inherited Create;
end;

destructor TV8InterceptorRef.Destroy;
begin
  inherited Destroy;
end;

function TV8InterceptorRef.GetByName(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  RetException: PChar;
begin
  Result := False;
  if (GetByNamePtr <> nil) then
  begin
    RetException := PChar(Exception);
    TCEFEventCallback.SendEvent(GetByNamePtr, [PChar(Name), object_, @retval, @RetException, @Result]);
    Exception := PCharToUStr(RetException);
  end;
end;

function TV8InterceptorRef.GetByIndex(index: integer; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  RetException: PChar;
begin
  Result := False;
  if (GetByIndexPtr <> nil) then
  begin
    RetException := PChar(Exception);
    TCEFEventCallback.SendEvent(GetByIndexPtr, [index, object_, @retval, @RetException, @Result]);
    Exception := PCharToUStr(RetException);
  end;
end;

function TV8InterceptorRef.SetByName(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
var
  RetException: PChar;
begin
  Result := False;
  if (SetByNamePtr <> nil) then
  begin
    RetException := PChar(Exception);
    TCEFEventCallback.SendEvent(SetByNamePtr, [PChar(Name), object_, Value, @RetException, @Result]);
    Exception := PCharToUStr(RetException);
  end;
end;

function TV8InterceptorRef.SetByIndex(index: integer; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
var
  RetException: PChar;
begin
  Result := False;
  if (SetByIndexPtr <> nil) then
  begin
    RetException := PChar(Exception);
    TCEFEventCallback.SendEvent(SetByIndexPtr, [index, object_, Value, @RetException, @Result]);
    Exception := PCharToUStr(RetException);
  end;
end;

end.
