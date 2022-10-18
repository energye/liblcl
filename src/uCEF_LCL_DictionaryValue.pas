//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_DictionaryValue;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  Classes, SysUtils,
  uCEF_LCL_Entity,
  uCEFInterfaces, uCEFDictionaryValue;

type

  TDictValueList = class
  private
    dictValue: ICefDictionaryValue;
    dataLen: integer;
  public
    constructor Create;
    destructor Destroy;
    function GetDictValue(): ICefDictionaryValue;
    procedure UnPackage(const DataArray: array of byte);
  end;

implementation

procedure TDictValueList.UnPackage(const DataArray: array of byte);
var
  //for
  vType: shortint; // 0:string 4:integer 13:double 14:boolean 23:dictValueList
  i, dataByteLen: integer;
  idx: integer;
  low, high: integer;
  //data
  tempArr: TBytes;
  tempKeyName: string;
  tempDataLen: integer;
  tempDictValueList: TDictValueList;
  tempStringValue: string;
  tempIntegerValue: integer;
  tempDoubleValue: Double;
  tempBooleanValue: boolean;
begin
  try
    dictValue := TCefDictionaryValueRef.New;
    idx := 0;
    i := 0;
    low := 0;
    high := 1;
    dataByteLen := Length(DataArray);
    while (i < dataByteLen) do
    begin
      //vType
      low := i;
      high := low + 1;
      tempArr := CopyByteArray(DataArray, low, high);
      vType := shortint(tempArr[0]);
      SetLength(tempArr, 0);
      //keyLen
      low := high;
      high := high + 4;
      tempArr := CopyByteArray(DataArray, low, high);
      tempDataLen := ByteToInteger(tempArr);
      SetLength(tempArr, 0);
      //key
      low := high;
      high := high + tempDataLen;
      tempArr := CopyByteArray(DataArray, low, high);
      SetLength(tempKeyName, tempDataLen);
      Move(tempArr[0], tempKeyName[1], tempDataLen);
      SetLength(tempArr, 0);
      //dataLen
      low := high;
      high := high + 4;
      tempArr := CopyByteArray(DataArray, low, high);
      tempDataLen := ByteToInteger(tempArr);
      //data
      low := high;
      high := high + tempDataLen;
      tempArr := CopyByteArray(DataArray, low, high);

      case vType of
        0://string
        begin
          SetLength(tempStringValue, tempDataLen);
          Move(tempArr[0], tempStringValue[1], tempDataLen);
          dictValue.SetString(tempKeyName, StrToUStr(tempStringValue));
          SetLength(tempStringValue, 0);
        end;
        4://integer
        begin
          tempIntegerValue := ByteToInteger(tempArr);
          dictValue.SetInt(tempKeyName, tempIntegerValue);
        end;
        13://double
        begin
          Move(tempArr[0], tempDoubleValue, tempDataLen);
          dictValue.SetDouble(tempKeyName, tempDoubleValue);
        end;
        14://boolean
        begin
          tempBooleanValue := tempArr[0] = 1;
          dictValue.SetBool(tempKeyName, tempBooleanValue);
        end;
        23://dictValueList
        begin
          tempDictValueList := TDictValueList.Create;
          tempDictValueList.UnPackage(tempArr);
          dictValue.SetDictionary(tempKeyName, tempDictValueList.GetDictValue());
        end;
      end;

      //end
      SetLength(tempArr, 0);
      SetLength(tempKeyName, 0);
      Inc(idx);
      i := high;
    end;
  finally
    SetLength(tempArr, 0);
  end;
end;

function TDictValueList.GetDictValue(): ICefDictionaryValue;
begin
  Result := dictValue;
end;

constructor TDictValueList.Create;
begin
  dictValue := TCefDictionaryValueRef.New;
  dataLen := 0;
end;

destructor TDictValueList.Destroy;
begin
  dictValue.Clear;
  dictValue := nil;
  dataLen := 0;
end;

end.
