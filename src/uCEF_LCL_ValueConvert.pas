//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ValueConvert;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  SysUtils, uCEFTypes, uCEFInterfaces, fpjson, jsonparser,
  uCEFProcessMessage, uCEFListValue, uCEFDictionaryValue, uCEFv8Value;

type

  TValueConvert = class
  public
    class constructor Create;
    class destructor Destroy;
    class function BytesToProcessMessage(const Data: Pointer; dataSize: nativeuint): ICefProcessMessage;
    class function JSONArrayToListValue(JSONArray: TJSONArray): ICefListValue;
    class function JSONObjectToDictionaryValue(JSONObject: TJSONObject): ICefDictionaryValue;
    class function BytesToV8ValueArray(const Data: Pointer; dataSize: nativeuint): TCefv8ValueArray;
    class function BytesToV8Array(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
    class  function BytesToV8Object(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
  end;

implementation

class function TValueConvert.BytesToProcessMessage(const Data: Pointer; dataSize: nativeuint): ICefProcessMessage;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
  JSONObject: TJSONObject;
  JSONArray: TJSONArray;
  message: ICefProcessMessage;
  Name: unicodestring;
  I: integer;
begin
  try
    try
      SetLength(FData, dataSize);
      Move(Data^, FData[0], dataSize);
      JSONString := string(StringOf(FData));
      JSON := GetJSON(JSONString);
      JSONObject := TJSONObject(JSON);
      Name := JSONObject.Get('name');
      message := TCefProcessMessageRef.New(Name);
      JSONArray := TJSONArray.Create;
      JSONArray := JSONObject.Get('argumentList', JSONArray);
      I := 0;
      while (I < JSONArray.Count) do
      begin
        case JSONArray.Types[I] of
          TJSONtype.jtString:
          begin
            message.ArgumentList.SetString(I, UTF8Decode(JSONArray.Strings[I]));
          end;
          TJSONtype.jtNumber:
          begin
            message.ArgumentList.SetDouble(I, JSONArray.Floats[I]);
          end;
          TJSONtype.jtBoolean:
          begin
            message.ArgumentList.SetBool(I, JSONArray.Booleans[I]);
          end;
          TJSONtype.jtNull:
          begin
            message.ArgumentList.SetNull(I);
          end;
          TJSONtype.jtUnknown:
          begin
            message.ArgumentList.SetNull(I);
          end;
          TJSONtype.jtArray:
          begin
            message.ArgumentList.SetList(I, JSONArrayToListValue(JSONArray.Arrays[I]));
          end;
          TJSONtype.jtObject:
          begin
            message.ArgumentList.SetDictionary(I, JSONObjectToDictionaryValue(JSONArray.Objects[I]));
          end;
        end;
        Inc(I);
      end;
      Result := message;
    except
      on E: Exception do
    end;
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

class function TValueConvert.JSONArrayToListValue(JSONArray: TJSONArray): ICefListValue;
var
  ListValue: ICefListValue;
  I: integer;
begin
  try
    ListValue := TCefListValueRef.New;
    I := 0;
    while (I < JSONArray.Count) do
    begin
      case JSONArray.Types[I] of
        TJSONtype.jtString:
        begin
          ListValue.SetString(I, UTF8Decode(JSONArray.Strings[I]));
        end;
        TJSONtype.jtNumber:
        begin
          ListValue.SetDouble(I, JSONArray.Floats[I]);
        end;
        TJSONtype.jtBoolean:
        begin
          ListValue.SetBool(I, JSONArray.Booleans[I]);
        end;
        TJSONtype.jtNull:
        begin
          ListValue.SetNull(I);
        end;
        TJSONtype.jtUnknown:
        begin
          ListValue.SetNull(I);
        end;
        TJSONtype.jtArray:
        begin
          ListValue.SetList(I, JSONArrayToListValue(JSONArray.Arrays[I]));
        end;
        TJSONtype.jtObject:
        begin
          ListValue.SetDictionary(I, JSONObjectToDictionaryValue(JSONArray.Objects[I]));
        end;
      end;
      Inc(I);
    end;
    Result := ListValue;
  except
    on E: Exception do
  end;
end;

class function TValueConvert.JSONObjectToDictionaryValue(JSONObject: TJSONObject): ICefDictionaryValue;
var
  DictionaryValue: ICefDictionaryValue;
  I: integer;
  Name: TJSONStringType;
begin
  try
    DictionaryValue := TCefDictionaryValueRef.New;
    I := 0;
    while (I < JSONObject.Count) do
    begin
      Name := JSONObject.Names[I];
      case JSONObject.Types[Name] of
        TJSONtype.jtString:
        begin
          DictionaryValue.SetString(UTF8Decode(Name), JSONObject.Strings[Name]);
        end;
        TJSONtype.jtNumber:
        begin
          DictionaryValue.SetDouble(UTF8Decode(Name), JSONObject.Floats[Name]);
        end;
        TJSONtype.jtBoolean:
        begin
          DictionaryValue.SetBool(UTF8Decode(Name), JSONObject.Booleans[Name]);
        end;
        TJSONtype.jtNull:
        begin
          DictionaryValue.SetNull(UTF8Decode(Name));
        end;
        TJSONtype.jtUnknown:
        begin
          DictionaryValue.SetNull(UTF8Decode(Name));
        end;
        TJSONtype.jtArray:
        begin
          DictionaryValue.SetList(UTF8Decode(Name), JSONArrayToListValue(JSONObject.Arrays[Name]));
        end;
        TJSONtype.jtObject:
        begin
          DictionaryValue.SetDictionary(UTF8Decode(Name), JSONObjectToDictionaryValue(JSONObject.Objects[Name]));
        end;
      end;
      Inc(I);
    end;
    Result := DictionaryValue;
  except
    on E: Exception do
  end;
end;

class function TValueConvert.BytesToV8ValueArray(const Data: Pointer; dataSize: nativeuint): TCefv8ValueArray;
begin

end;

class function TValueConvert.BytesToV8Array(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
begin

end;

class function TValueConvert.BytesToV8Object(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
begin

end;

class constructor TValueConvert.Create;
begin
end;

class destructor TValueConvert.Destroy;
begin
end;

end.
