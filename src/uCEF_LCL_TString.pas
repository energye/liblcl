//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_TString;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

type

  TString = class
  protected
    FValue: string;
    FSize: NativeInt;
  public
    constructor Create;
    destructor Destroy;
    procedure SetValue(Value: string);
    function GetValue(): string;
    function GetSize(): NativeInt;
  end;

implementation

procedure TString.SetValue(Value: string);
begin
  FValue := Value;
  FSize := Length(Value); //UTF8Length(); UTF8LengthFast
end;

function TString.GetValue(): string;
begin
  Result := FValue;
end;

function TString.GetSize(): NativeInt;
begin
  Result := FSize;
end;

constructor TString.Create;
begin
  inherited Create;
end;

destructor TString.Destroy;
begin
  inherited Destroy;
  FValue := '';
  FSize := 0;
end;

end.
