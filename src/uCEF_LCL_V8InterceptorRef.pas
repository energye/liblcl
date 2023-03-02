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
  uCEF_LCL_EventCallback;

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
  end;

implementation


function TV8InterceptorRef.GetByName(const Name: ustring; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
begin
  Result := False;
  if (GetByNamePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetByNamePtr, []);
  end;
end;

function TV8InterceptorRef.GetByIndex(index: integer; const object_: ICefv8Value; var retval: ICefv8Value; var Exception: ustring): boolean;
begin
  Result := False;
  if (GetByIndexPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetByIndexPtr, []);
  end;
end;

function TV8InterceptorRef.SetByName(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
begin
  Result := False;
  if (SetByNamePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(SetByNamePtr, []);
  end;
end;

function TV8InterceptorRef.SetByIndex(index: integer; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
begin
  Result := False;
  if (SetByIndexPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(SetByIndexPtr, []);
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

end.
