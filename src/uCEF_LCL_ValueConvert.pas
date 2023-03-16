//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ValueConvert;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  SysUtils, uCEFTypes, uCEFInterfaces, uCEFConstants, fpjson, jsonparser,
  uCEFProcessMessage, uCEFListValue, uCEFDictionaryValue, uCEFv8Value;

type

  TValueConvert = class
  public
    class constructor Create;
    class destructor Destroy;
    // JSONArray TBytes 转换 进程消息
    class function BytesToProcessMessage(Name: unicodestring; const Data: Pointer; dataSize: nativeuint): ICefProcessMessage;
    // JSONArray TBytes 转换 ICefListValue
    class function BytesToListValue(const Data: Pointer; dataSize: nativeuint): ICefListValue;
    // TJSONArray 转换 ICefListValue
    class function JSONArrayToListValue(JSONArray: TJSONArray): ICefListValue;
    // TJSONObject TBytes 转换 ICefDictionaryValue
    class function BytesToDictionaryValue(const Data: Pointer; dataSize: nativeuint): ICefDictionaryValue;
    // TJSONObject 转换 ICefDictionaryValue
    class function JSONObjectToDictionaryValue(JSONObject: TJSONObject): ICefDictionaryValue;

    // JSONArray TBytes 转换 TCefv8ValueArray
    class function BytesToV8ValueArray(const Data: Pointer; dataSize: nativeuint): TCefv8ValueArray;
    // TJSONArray TBytes 转换 ICefv8Value
    class function BytesToV8Array(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
    // TJSONArray 转换 ICefv8Value
    class function JSONArrayToV8Array(JSONArray: TJSONArray): ICefv8Value;
    // TJSONObject TBytes 转换 ICefv8Value
    class function BytesToV8Object(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
    // TJSONObject 转换 ICefv8Value
    class function JSONObjectToV8Object(JSONObject: TJSONObject): ICefv8Value;
  end;

implementation

// JSONArray TBytes 转换 进程消息
class function TValueConvert.BytesToProcessMessage(Name: unicodestring; const Data: Pointer; dataSize: nativeuint): ICefProcessMessage;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
  JSONArray: TJSONArray;
  message: ICefProcessMessage;
  I: integer;
begin
  try
    try
      SetLength(FData, dataSize);
      Move(Data^, FData[0], dataSize);
      JSONString := string(StringOf(FData));
      JSON := GetJSON(JSONString);
      JSONArray := TJSONArray(JSON);
      message := TCefProcessMessageRef.New(Name);
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

// JSONArray TBytes 转换 ICefListValue
class function TValueConvert.BytesToListValue(const Data: Pointer; dataSize: nativeuint): ICefListValue;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
begin
  try
    SetLength(FData, dataSize);
    Move(Data^, FData[0], dataSize);
    JSONString := string(StringOf(FData));
    JSON := GetJSON(JSONString);
    Result := JSONArrayToListValue(TJSONArray(JSON));
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

// TJSONArray 转换 ICefListValue
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

// TJSONObject TBytes 转换 ICefDictionaryValue
class function TValueConvert.BytesToDictionaryValue(const Data: Pointer; dataSize: nativeuint): ICefDictionaryValue;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
begin
  try
    SetLength(FData, dataSize);
    Move(Data^, FData[0], dataSize);
    JSONString := string(StringOf(FData));
    JSON := GetJSON(JSONString);
    Result := JSONObjectToDictionaryValue(TJSONObject(JSON));
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

// TJSONObject 转换 ICefDictionaryValue
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

// JSONArray TBytes 转换 TCefv8ValueArray
class function TValueConvert.BytesToV8ValueArray(const Data: Pointer; dataSize: nativeuint): TCefv8ValueArray;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
  JSONArray: TJSONArray;
  ValueArray: TCefv8ValueArray;
  I: integer;
begin
  try
    try
      SetLength(FData, dataSize);
      Move(Data^, FData[0], dataSize);
      JSONString := string(StringOf(FData));
      JSON := GetJSON(JSONString);
      JSONArray := TJSONArray(JSON);
      SetLength(ValueArray, JSONArray.Count);
      I := 0;
      while (I < JSONArray.Count) do
      begin
        case JSONArray.Types[I] of
          TJSONtype.jtString:
          begin
            ValueArray[I] := TCefv8ValueRef.NewString(UTF8Decode(JSONArray.Strings[I]));
          end;
          TJSONtype.jtNumber:
          begin
            ValueArray[I] := TCefv8ValueRef.NewDouble(JSONArray.Floats[I]);
          end;
          TJSONtype.jtBoolean:
          begin
            ValueArray[I] := TCefv8ValueRef.NewBool(JSONArray.Booleans[I]);
          end;
          TJSONtype.jtNull:
          begin
            ValueArray[I] := TCefv8ValueRef.NewNull;
          end;
          TJSONtype.jtUnknown:
          begin
            ValueArray[I] := TCefv8ValueRef.NewNull;
          end;
          TJSONtype.jtArray:
          begin
            ValueArray[I] := JSONArrayToV8Array(JSONArray.Arrays[I]);
          end;
          TJSONtype.jtObject:
          begin
            ValueArray[I] := JSONObjectToV8Object(JSONArray.Objects[I]);
          end;
        end;
        Inc(I);
      end;
      Result := ValueArray;
    except
      on E: Exception do
    end;
  finally
    JSONString := '';
    SetLength(FData, 0);
    // SetLength(ValueArray, 0);//
    JSON.Free;
  end;
end;

// TJSONArray TBytes 转换 ICefv8Value
class function TValueConvert.BytesToV8Array(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
begin
  try
    SetLength(FData, dataSize);
    Move(Data^, FData[0], dataSize);
    JSONString := string(StringOf(FData));
    JSON := GetJSON(JSONString);
    Result := JSONArrayToV8Array(TJSONArray(JSON));
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

// TJSONArray 转换 ICefv8Value
class function TValueConvert.JSONArrayToV8Array(JSONArray: TJSONArray): ICefv8Value;
var
  V8Array: ICefv8Value;
  I: integer;
begin
  try
    V8Array := TCefv8ValueRef.NewArray(JSONArray.Count);
    I := 0;
    while (I < JSONArray.Count) do
    begin
      case JSONArray.Types[I] of
        TJSONtype.jtString:
        begin
          V8Array.SetValueByIndex(I, TCefv8ValueRef.NewString(UTF8Decode(JSONArray.Strings[I])));
        end;
        TJSONtype.jtNumber:
        begin
          V8Array.SetValueByIndex(I, TCefv8ValueRef.NewDouble(JSONArray.Floats[I]));
        end;
        TJSONtype.jtBoolean:
        begin
          V8Array.SetValueByIndex(I, TCefv8ValueRef.NewBool(JSONArray.Booleans[I]));
        end;
        TJSONtype.jtNull:
        begin
          V8Array.SetValueByIndex(I, TCefv8ValueRef.NewNull);
        end;
        TJSONtype.jtUnknown:
        begin
          V8Array.SetValueByIndex(I, TCefv8ValueRef.NewNull);
        end;
        TJSONtype.jtArray:
        begin
          V8Array.SetValueByIndex(I, JSONArrayToV8Array(JSONArray.Arrays[I]));
        end;
        TJSONtype.jtObject:
        begin
          V8Array.SetValueByIndex(I, JSONObjectToV8Object(JSONArray.Objects[I]));
        end;
      end;
      Inc(I);
    end;
    Result := V8Array;
  except
    on E: Exception do
  end;
end;

// TJSONObject TBytes 转换 ICefv8Value
class function TValueConvert.BytesToV8Object(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
var
  FData: TBytes;
  JSONString: string;
  JSON: TJSONData;
begin
  try
    SetLength(FData, dataSize);
    Move(Data^, FData[0], dataSize);
    JSONString := string(StringOf(FData));
    JSON := GetJSON(JSONString);
    Result := JSONObjectToV8Object(TJSONObject(JSON));
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

// TJSONObject 转换 ICefv8Value
class function TValueConvert.JSONObjectToV8Object(JSONObject: TJSONObject): ICefv8Value;
var
  V8Object: ICefv8Value;
  I: integer;
  Name: TJSONStringType;
begin
  try
    V8Object := TCefv8ValueRef.NewObject(nil, nil);
    I := 0;
    while (I < JSONObject.Count) do
    begin
      Name := JSONObject.Names[I];
      case JSONObject.Types[Name] of
        TJSONtype.jtString:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewString(UTF8Decode(JSONObject.Strings[Name])), V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtNumber:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewDouble(JSONObject.Floats[Name]), V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtBoolean:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewBool(JSONObject.Booleans[Name]), V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtNull:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewNull, V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtUnknown:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewNull, V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtArray:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), JSONArrayToV8Array(JSONObject.Arrays[Name]), V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtObject:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), JSONObjectToV8Object(JSONObject.Objects[Name]), V8_PROPERTY_ATTRIBUTE_NONE);
        end;
      end;
      Inc(I);
    end;
    Result := V8Object;
  except
    on E: Exception do
  end;
end;

class constructor TValueConvert.Create;
begin
end;

class destructor TValueConvert.Destroy;
begin
end;

end.
