//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_Process_Message;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  //uCEF_LCL_ConsoleWrite,
  uCEF_LCL_Entity,
  Classes, SysUtils;

type
  Arguments = ^TArgumentList;

  TDataItem = class
  protected
    VType: shortint;
    DataLen: integer;
    Data: TBytes;
  public
    constructor Create;
    destructor Destroy;
  public
    procedure SetString(v: string);
    procedure SetInt(v: integer);
    procedure SetDouble(v: double);
    procedure SetBoolean(v: boolean);
    function GetArgumens(): Arguments;
    function GetString(): string;
    function GetInt(): integer;
    function GetDouble(): double;
    function GetBoolean(): boolean;
    function IsArguments(): boolean;
    function IsString(): boolean;
    function IsInt(): boolean;
    function IsDouble(): boolean;
    function IsBoolean(): boolean;
  end;

  TDataItems = array of TDataItem;

  TArgumentList = class
  private
    iData: TDataItems;
    len: integer;
    //dataBytes: TBytes;
  public
    constructor Create;
    destructor Destroy;
    function Package(): TBytes;
    function DataItems(): TDataItems;
    procedure UnPackage(ItemLen: integer; const Arguments: array of byte; ArgumentsLength: integer);
    procedure SetString(idx: integer; v: string);
    procedure SetInt(idx: integer; v: integer);
    procedure SetDouble(idx: integer; v: double);
    procedure SetBoolean(idx: integer; v: boolean);
    function GetArgumens(idx: integer): TArgumentList;
    function GetString(idx: integer): string;
    function GetInt(idx: integer): integer;
    function GetDouble(idx: integer): double;
    function GetBoolean(idx: integer): boolean;
  end;

function baseDataLength(gvt: GO_VALUE_TYPE): integer;

implementation

function baseDataLength(gvt: GO_VALUE_TYPE): integer;
begin
  case gvt of
    GO_VALUE_INT, GO_VALUE_UINT:
      Result := intSize;
    GO_VALUE_INT8, GO_VALUE_UINT8, GO_VALUE_BOOL:
      Result := 1;
    GO_VALUE_INT16, GO_VALUE_UINT16:
      Result := 2;
    GO_VALUE_INT32, GO_VALUE_UINT32, GO_VALUE_FLOAT32:
      Result := 4;
    GO_VALUE_INT64, GO_VALUE_UINT64, GO_VALUE_FLOAT64:
      Result := 8;
    else
      Result := -1;
  end;
end;

{--------------------------TArgumentList-------------------------------------------------}

function TArgumentList.Package(): TBytes;
begin
end;

procedure TArgumentList.UnPackage(ItemLen: integer; const Arguments: array of byte; ArgumentsLength: integer);
var
  //for
  i, dataByteLen: integer;
  idx: integer;
  low, high: integer;
  //data
  tempArr: TBytes;
begin
  idx := 0;
  i := 0;
  low := 0;
  high := 1;
  try
    if ArgumentsLength > 0 then
    begin
      dataByteLen := ArgumentsLength;
    end
    else
    begin
      dataByteLen := Length(Arguments);
    end;
    //SetLength(dataBytes, dataByteLen);
    SetLength(iData, ItemLen);
    len := ItemLen;
    //[4 0 0 0 4 0 1 4 106 0 0 0 0 15 230 157 168 231 186 162 229 178 169 230 181 139 232 175 149]
    while (i < dataByteLen) do
    begin
      iData[idx] := TDataItem.Create;
      //vType
      low := i;
      high := low + 1;
      tempArr := CopyByteArray(Arguments, low, high);
      iData[idx].VType := shortint(tempArr[0]);
      SetLength(tempArr, 0);
      //dataLen
      if iData[idx].VType = 0 then
      begin
        low := high;
        high := high + 4;
        tempArr := CopyByteArray(Arguments, low, high);
        iData[idx].DataLen := ByteToInteger(tempArr);
        SetLength(tempArr, 0);
      end
      else
      begin
        iData[idx].DataLen := baseDataLength(GO_VALUE_TYPE(iData[idx].VType));
      end;
      //data
      low := high;
      high := high + iData[idx].DataLen;
      tempArr := CopyByteArray(Arguments, low, high);
      SetLength(iData[idx].Data, iData[idx].DataLen);
      Move(tempArr[0], iData[idx].Data[0], iData[idx].DataLen);
      SetLength(tempArr, 0);
      Inc(idx);
      i := high;
    end;
  finally
    SetLength(tempArr, 0);
  end;
end;

function TArgumentList.GetArgumens(idx: integer): TArgumentList;
var
  argument: TArgumentList;
  item: TDataItem;
begin
  if Length(iData) > idx then
  begin
    item := iData[idx];
    if item.IsArguments() then
    begin
      Result := TArgumentList(item.GetArgumens());
      exit;
    end;
  end;
  Result := nil;
end;

procedure TArgumentList.SetString(idx: integer; v: string);
begin

end;

procedure TArgumentList.SetInt(idx: integer; v: integer);
begin

end;

procedure TArgumentList.SetDouble(idx: integer; v: double);
begin

end;

procedure TArgumentList.SetBoolean(idx: integer; v: boolean);
begin

end;

function TArgumentList.GetString(idx: integer): string;
var
  item: TDataItem;
begin
  if Length(iData) > idx then
  begin
    item := iData[idx];
    if item.IsString() then
    begin
      Result := item.GetString();
      exit;
    end;
  end;
  Result := '';
end;

function TArgumentList.GetInt(idx: integer): integer;
var
  item: TDataItem;
begin
  if Length(iData) > idx then
  begin
    item := iData[idx];
    if item.IsInt() then
    begin
      Result := item.GetInt();
      exit;
    end;
  end;
  Result := 0;
end;

function TArgumentList.GetDouble(idx: integer): double;
var
  item: TDataItem;
begin
  if Length(iData) > idx then
  begin
    item := iData[idx];
    if item.IsDouble() then
    begin
      Result := item.GetDouble();
      exit;
    end;
  end;
  Result := 0.0;
end;

function TArgumentList.GetBoolean(idx: integer): boolean;
var
  item: TDataItem;
begin
  if Length(iData) > idx then
  begin
    item := iData[idx];
    if item.IsBoolean() then
    begin
      Result := item.GetBoolean();
      exit;
    end;
  end;
  Result := False;
end;

function TArgumentList.DataItems(): TDataItems;
begin
  Result := iData;
end;

constructor TArgumentList.Create();
begin
end;

destructor TArgumentList.Destroy;
var
  idx: integer;
begin
  for idx := 0 to Length(iData) - 1 do
  begin
    iData[idx].Destroy;
    iData[idx] := nil;
  end;
  SetLength(iData, 0);
  len := 0;
end;

{--------------------------TDataItem-------------------------------------------------}

function TDataItem.GetArgumens(): Arguments;
var
  v: TArgumentList;
begin
  v := TArgumentList.Create;
  v.UnPackage(DataLen, Data, -1);
  Result := Arguments(v);
end;

function TDataItem.GetString(): string;
var
  v: string;
begin
  SetLength(v, DataLen - 1);
  Move(Data[0], v[1], DataLen - 1);
  Result := v;
end;

procedure TDataItem.SetString(v: string);
var
  buf: array of byte;
begin
  VType := 0;
  DataLen := Length(v);
  SetLength(buf, DataLen);
  Move(v[1], buf[0], DataLen);
  Data := buf;
end;

function TDataItem.GetInt(): integer;
begin
  Result := ByteToInteger(Data);
end;

procedure TDataItem.SetInt(v: integer);
var
  buf: array[0..3] of byte;
begin
  VType := 4;
  DataLen := 4;
  Move(v, buf[0], DataLen);
  Data := buf;
end;

function TDataItem.GetDouble(): double;
var
  v: double;
begin
  Move(Data[0], v, DataLen);
  Result := v;
end;

procedure TDataItem.SetDouble(v: double);
var
  buf: array[0..7] of byte;
begin
  VType := 13;
  DataLen := 8;
  Move(v, buf[0], DataLen);
  Data := buf;
end;

function TDataItem.GetBoolean(): boolean;
begin
  Result := Data[0] = 1;
end;

procedure TDataItem.SetBoolean(v: boolean);
var
  buf: array[0..0] of byte;
begin
  VType := 14;
  DataLen := 1;
  if v then
  begin
    buf[0] := 1;
  end
  else
  begin
    buf[0] := 0;
  end;
  Data := buf;
end;

function TDataItem.IsArguments(): boolean;
begin
  Result := VType = 22;
end;

function TDataItem.IsString(): boolean;
begin
  Result := VType = 0;
end;

function TDataItem.IsInt(): boolean;
begin
  Result := VType = 4;
end;

function TDataItem.IsDouble(): boolean;
begin
  Result := VType = 13;
end;

function TDataItem.IsBoolean(): boolean;
begin
  Result := VType = 14;
end;

constructor TDataItem.Create;
begin
  VType := 0;
  DataLen := 0;
end;

destructor TDataItem.Destroy;
begin
  SetLength(Data, 0);
  VType := 0;
  DataLen := 0;
end;

end.
