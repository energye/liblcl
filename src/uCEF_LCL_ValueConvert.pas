//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ValueConvert;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  SysUtils, Classes, uCEFTypes, uCEFInterfaces, uCEFConstants, fpjson, jsonparser,
  uCEFProcessMessage, uCEFListValue, uCEFDictionaryValue, uCEFv8Value;

type

  TValueConvert = class
  public
    class constructor Create;
    class destructor Destroy;
    // JSONArray TBytes 转换 进程消息 ICefProcessMessage
    class function BytesToProcessMessage(Name: ustring; const Data: Pointer; dataSize: nativeuint): ICefProcessMessage;
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
    // JSONArray TBytes 转换 ICefv8Value
    class function BytesToV8Array(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
    // JSONArray 转换 ICefv8Value
    class function JSONArrayToV8Array(JSONArray: TJSONArray): ICefv8Value;
    // JSONObject TBytes 转换 ICefv8Value
    class function BytesToV8Object(const Data: Pointer; dataSize: nativeuint): ICefv8Value;
    // JSONObject 转换 ICefv8Value
    class function JSONObjectToV8Object(JSONObject: TJSONObject): ICefv8Value;

    // ICefv8Value 转换 ProcessMessage
    class function V8ValueToProcessMessage(Name: ustring; const Value: ICefv8Value): ICefProcessMessage;
    // ICefv8Value 转换 ICefListValue
    class function V8ValueToListValue(const Value: ICefv8Value): ICefListValue;
    // ICefv8Value 转换 ICefDictionaryValue
    class function V8ValueToDictionaryValue(const Value: ICefv8Value): ICefDictionaryValue;
  end;

implementation

// JSONArray TBytes 转换 进程消息
class function TValueConvert.BytesToProcessMessage(Name: ustring; const Data: Pointer; dataSize: nativeuint): ICefProcessMessage;
var
  FData: TBytes;
  JSONString: string;
  Item, JSON: TJSONData;
  JSONArray: TJSONArray;
  JSONNumber: TJSONNumber;
  message: ICefProcessMessage;
  I: integer;
begin
  try
    SetLength(FData, dataSize);
    Move(Data^, FData[0], dataSize);
    //JSONString := '["返回值", 111111, 2222.22, true]';
    JSONString := string(StringOf(FData));
    JSON := GetJSON(JSONString);
    JSONArray := TJSONArray(JSON);
    message := TCefProcessMessageRef.New(Name);
    try
      I := 0;
      while (I < JSONArray.Count) do
      begin
        Item := JSONArray.Items[I];
        case Item.JSONType of
          TJSONtype.jtString:
          begin
            message.ArgumentList.SetString(I, UTF8Decode(JSONArray.Strings[I]));
          end;
          TJSONtype.jtNumber:
          begin
            JSONNumber := (Item as TJSONNumber);
            case JSONNumber.NumberType of
              TJSONNumberType.ntInteger:
              begin
                message.ArgumentList.SetInt(I, JSONArray.Integers[I]);
              end;
              TJSONNumberType.ntInt64:
              begin
                message.ArgumentList.SetInt(I, integer(JSONArray.Int64s[I]));
              end;
              TJSONNumberType.ntQWord:
              begin
                message.ArgumentList.SetInt(I, integer(JSONArray.QWords[I]));
              end;
              TJSONNumberType.ntFloat:
              begin
                message.ArgumentList.SetDouble(I, JSONArray.Floats[I]);
              end;
            end;
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
    JSONArray.Free;
    //JSON.Free;
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
    Result := JSONArrayToListValue(JSON as TJSONArray);
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
  Item: TJSONData;
  JSONNumber: TJSONNumber;
  I: integer;
begin
  try
    ListValue := TCefListValueRef.New;
    I := 0;
    while (I < JSONArray.Count) do
    begin
      Item := JSONArray.Items[I];
      case Item.JSONType of
        TJSONtype.jtString:
        begin
          ListValue.SetString(I, UTF8Decode(JSONArray.Strings[I]));
        end;
        TJSONtype.jtNumber:
        begin
          JSONNumber := (Item as TJSONNumber);
          case JSONNumber.NumberType of
            TJSONNumberType.ntInteger:
            begin
              ListValue.SetInt(I, JSONArray.Integers[I]);
            end;
            TJSONNumberType.ntInt64:
            begin
              ListValue.SetInt(I, integer(JSONArray.Int64s[I]));
            end;
            TJSONNumberType.ntQWord:
            begin
              ListValue.SetInt(I, integer(JSONArray.QWords[I]));
            end;
            TJSONNumberType.ntFloat:
            begin
              ListValue.SetDouble(I, JSONArray.Floats[I]);
            end;
          end;
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
    Result := JSONObjectToDictionaryValue(JSON as TJSONObject);
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
  Item: TJSONData;
  JSONNumber: TJSONNumber;
begin
  try
    DictionaryValue := TCefDictionaryValueRef.New;
    I := 0;
    while (I < JSONObject.Count) do
    begin
      Name := JSONObject.Names[I];
      Item := JSONObject.Elements[Name];
      case Item.JSONType of
        TJSONtype.jtString:
        begin
          DictionaryValue.SetString(UTF8Decode(Name), UTF8Decode(JSONObject.Strings[Name]));
        end;
        TJSONtype.jtNumber:
        begin
          JSONNumber := (Item as TJSONNumber);
          case JSONNumber.NumberType of
            TJSONNumberType.ntInteger:
            begin
              DictionaryValue.SetInt(UTF8Decode(Name), JSONObject.Integers[Name]);
            end;
            TJSONNumberType.ntInt64:
            begin
              DictionaryValue.SetInt(UTF8Decode(Name), integer(JSONObject.Int64s[Name]));
            end;
            TJSONNumberType.ntQWord:
            begin
              DictionaryValue.SetInt(UTF8Decode(Name), integer(JSONObject.QWords[Name]));
            end;
            TJSONNumberType.ntFloat:
            begin
              DictionaryValue.SetDouble(UTF8Decode(Name), JSONObject.Floats[Name]);
            end;
          end;
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
  Item, JSON: TJSONData;
  JSONArray: TJSONArray;
  JSONNumber: TJSONNumber;
  ValueArray: TCefv8ValueArray;
  I: integer;
begin
  try
    try
      SetLength(FData, dataSize);
      Move(Data^, FData[0], dataSize);
      JSONString := string(StringOf(FData));
      JSON := GetJSON(JSONString);
      JSONArray := JSON as TJSONArray;
      if JSONArray.Count = 0 then
      begin
        Result := nil;
        exit;
      end;
      SetLength(ValueArray, JSONArray.Count);
      I := 0;
      while (I < JSONArray.Count) do
      begin
        Item := JSONArray.Items[I];
        case Item.JSONType of
          TJSONtype.jtString:
          begin
            ValueArray[I] := TCefv8ValueRef.NewString(UTF8Decode(JSONArray.Strings[I]));
          end;
          TJSONtype.jtNumber:
          begin
            JSONNumber := (Item as TJSONNumber);
            case JSONNumber.NumberType of
              TJSONNumberType.ntInteger:
              begin
                ValueArray[I] := TCefv8ValueRef.NewInt(JSONArray.Integers[I]);
              end;
              TJSONNumberType.ntInt64:
              begin
                ValueArray[I] := TCefv8ValueRef.NewInt(integer(JSONArray.Int64s[I]));
              end;
              TJSONNumberType.ntQWord:
              begin
                ValueArray[I] := TCefv8ValueRef.NewInt(integer(JSONArray.QWords[I]));
              end;
              TJSONNumberType.ntFloat:
              begin
                ValueArray[I] := TCefv8ValueRef.NewDouble(JSONArray.Floats[I]);
              end;
            end;
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
            //ValueArray[I] := TCefv8ValueRef.NewNull;
          end;
          TJSONtype.jtObject:
          begin
            ValueArray[I] := JSONObjectToV8Object(JSONArray.Objects[I]);
            //ValueArray[I] := TCefv8ValueRef.NewNull;
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
    SetLength(ValueArray, 0);
    JSON.Free;
  end;
end;

// JSONArray TBytes 转换 ICefv8Value
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
    Result := JSONArrayToV8Array(JSON as TJSONArray);
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

// JSONArray 转换 ICefv8Value
class function TValueConvert.JSONArrayToV8Array(JSONArray: TJSONArray): ICefv8Value;
var
  V8Array: ICefv8Value;
  I: integer;
  Item: TJSONData;
  JSONNumber: TJSONNumber;
begin
  try
    V8Array := TCefv8ValueRef.NewArray(JSONArray.Count);
    I := 0;
    while (I < JSONArray.Count) do
    begin
      Item := JSONArray.Items[I];
      case Item.JSONType of
        TJSONtype.jtString:
        begin
          V8Array.SetValueByIndex(I, TCefv8ValueRef.NewString(UTF8Decode(JSONArray.Strings[I])));
        end;
        TJSONtype.jtNumber:
        begin
          JSONNumber := (Item as TJSONNumber);
          case JSONNumber.NumberType of
            TJSONNumberType.ntInteger:
            begin
              V8Array.SetValueByIndex(I, TCefv8ValueRef.NewInt(JSONArray.Integers[I]));
            end;
            TJSONNumberType.ntInt64:
            begin
              V8Array.SetValueByIndex(I, TCefv8ValueRef.NewInt(integer(JSONArray.Int64s[I])));
            end;
            TJSONNumberType.ntQWord:
            begin
              V8Array.SetValueByIndex(I, TCefv8ValueRef.NewInt(integer(JSONArray.QWords[I])));
            end;
            TJSONNumberType.ntFloat:
            begin
              V8Array.SetValueByIndex(I, TCefv8ValueRef.NewDouble(JSONArray.Floats[I]));
            end;
          end;
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

// JSONObject TBytes 转换 ICefv8Value
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
    Result := JSONObjectToV8Object(JSON as TJSONObject);
  finally
    JSONString := '';
    SetLength(FData, 0);
    JSON.Free;
  end;
end;

// JSONObject 转换 ICefv8Value
class function TValueConvert.JSONObjectToV8Object(JSONObject: TJSONObject): ICefv8Value;
var
  V8Object: ICefv8Value;
  I: integer;
  Name: TJSONStringType;
  Item: TJSONData;
  JSONNumber: TJSONNumber;
begin
  try
    V8Object := TCefv8ValueRef.NewObject(nil, nil);
    I := 0;
    while (I < JSONObject.Count) do
    begin
      Name := JSONObject.Names[I];
      Item := JSONObject.Elements[Name];
      case Item.JSONType of
        TJSONtype.jtString:
        begin
          V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewString(UTF8Decode(JSONObject.Strings[Name])), V8_PROPERTY_ATTRIBUTE_NONE);
        end;
        TJSONtype.jtNumber:
        begin
          JSONNumber := (Item as TJSONNumber);
          case JSONNumber.NumberType of
            TJSONNumberType.ntInteger:
            begin
              V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewInt(JSONObject.Integers[Name]), V8_PROPERTY_ATTRIBUTE_NONE);
            end;
            TJSONNumberType.ntInt64:
            begin
              V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewInt(integer(JSONObject.Int64s[Name])), V8_PROPERTY_ATTRIBUTE_NONE);
            end;
            TJSONNumberType.ntQWord:
            begin
              V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewInt(integer(JSONObject.QWords[Name])), V8_PROPERTY_ATTRIBUTE_NONE);
            end;
            TJSONNumberType.ntFloat:
            begin
              V8Object.SetValueByKey(UTF8Decode(Name), TCefv8ValueRef.NewDouble(JSONObject.Floats[Name]), V8_PROPERTY_ATTRIBUTE_NONE);
            end;
          end;
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


// ICefv8Value 转换 ProcessMessage
class function TValueConvert.V8ValueToProcessMessage(Name: ustring; const Value: ICefv8Value): ICefProcessMessage;
var
  message: ICefProcessMessage;
  I, keysSize: integer;
  dataValue: ICefv8Value;
  keys: TStrings;
  key: string;
begin
  try
    message := TCefProcessMessageRef.New(Name);
    if Value = nil then
    begin
      Result := message;
      exit;
    end;
    if Value.IsArray then
    begin
      I := 0;
      while (I < Value.GetArrayLength) do
      begin
        dataValue := Value.GetValueByIndex(I);
        if dataValue.IsString then
          message.ArgumentList.SetString(I, dataValue.GetStringValue)
        else if dataValue.IsInt then
          message.ArgumentList.SetInt(I, dataValue.GetIntValue)
        else if dataValue.IsUInt then
          message.ArgumentList.SetInt(I, integer(dataValue.GetUIntValue))
        else if dataValue.IsDouble then
          message.ArgumentList.SetDouble(I, dataValue.GetDoubleValue)
        else if dataValue.IsBool then
          message.ArgumentList.SetBool(I, dataValue.GetBoolValue)
        else if dataValue.IsArray then
          message.ArgumentList.SetList(I, V8ValueToListValue(dataValue))
        else if dataValue.IsObject then
          message.ArgumentList.SetDictionary(I, V8ValueToDictionaryValue(dataValue))
        else
          message.ArgumentList.SetNull(I);
        Inc(I);
        TCefv8ValueRef(dataValue).Free;
      end;
    end
    else if Value.IsObject then
    begin
      keys := TStringList.Create;
      keysSize := Value.GetKeys(keys);
      I := 0;
      while (I < keysSize) do
      begin
        key := keys.Strings[I];
        dataValue := Value.GetValueByKey(key);
        if dataValue.IsString then
          message.ArgumentList.SetString(I, dataValue.GetStringValue)
        else if dataValue.IsInt then
          message.ArgumentList.SetInt(I, dataValue.GetIntValue)
        else if dataValue.IsUInt then
          message.ArgumentList.SetInt(I, integer(dataValue.GetUIntValue))
        else if dataValue.IsDouble then
          message.ArgumentList.SetDouble(I, dataValue.GetDoubleValue)
        else if dataValue.IsBool then
          message.ArgumentList.SetBool(I, dataValue.GetBoolValue)
        else if dataValue.IsArray then
          message.ArgumentList.SetList(I, V8ValueToListValue(dataValue))
        else if dataValue.IsObject then
          message.ArgumentList.SetDictionary(I, V8ValueToDictionaryValue(dataValue))
        else
          message.ArgumentList.SetNull(I);
        Inc(I);
        TCefv8ValueRef(dataValue).Free;
      end;
      keys.Free;
    end
    else
    begin
      if Value.IsString then
        message.ArgumentList.SetString(0, Value.GetStringValue)
      else if Value.IsInt then
        message.ArgumentList.SetInt(0, Value.GetIntValue)
      else if Value.IsUInt then
        message.ArgumentList.SetInt(0, integer(Value.GetUIntValue))
      else if Value.IsDouble then
        message.ArgumentList.SetDouble(0, Value.GetDoubleValue)
      else if Value.IsBool then
        message.ArgumentList.SetBool(0, Value.GetBoolValue)
      else
        message.ArgumentList.SetNull(0);
    end;
    Result := message;
  except
    on E: Exception do
  end;
  TCefv8ValueRef(Value).Free;
end;


// ICefv8Value 转换 ICefListValue
class function TValueConvert.V8ValueToListValue(const Value: ICefv8Value): ICefListValue;
var
  ListValue: ICefListValue;
  I: integer;
  dataValue: ICefv8Value;
begin
  try
    ListValue := TCefListValueRef.New;
    I := 0;
    while (I < Value.GetArrayLength) do
    begin
      dataValue := Value.GetValueByIndex(I);
      if dataValue.IsString then
        ListValue.SetString(I, dataValue.GetStringValue)
      else if dataValue.IsInt then
        ListValue.SetInt(I, dataValue.GetIntValue)
      else if dataValue.IsUInt then
        ListValue.SetInt(I, integer(dataValue.GetUIntValue))
      else if dataValue.IsDouble then
        ListValue.SetDouble(I, dataValue.GetDoubleValue)
      else if dataValue.IsBool then
        ListValue.SetBool(I, dataValue.GetBoolValue)
      else if dataValue.IsArray then
        ListValue.SetList(I, V8ValueToListValue(dataValue))
      else if dataValue.IsObject then
        ListValue.SetDictionary(I, V8ValueToDictionaryValue(dataValue))
      else
        ListValue.SetNull(I);
      Inc(I);
      TCefv8ValueRef(dataValue).Free;
    end;
  except
    on E: Exception do
  end;
end;

// ICefv8Value 转换 ICefDictionaryValue
class function TValueConvert.V8ValueToDictionaryValue(const Value: ICefv8Value): ICefDictionaryValue;
var
  DictionaryValue: ICefDictionaryValue;
  I, keysSize: integer;
  dataValue: ICefv8Value;
  keys: TStrings;
  key: string;
begin
  try
    DictionaryValue := TCefDictionaryValueRef.New;
    keys := TStringList.Create;
    keysSize := Value.GetKeys(keys);
    try
      I := 0;
      while (I < keysSize) do
      begin
        key := keys.Strings[I];
        dataValue := Value.GetValueByKey(key);
        if dataValue.IsString then
          DictionaryValue.SetString(key, dataValue.GetStringValue)
        else if dataValue.IsInt then
          DictionaryValue.SetInt(key, dataValue.GetIntValue)
        else if dataValue.IsUInt then
          DictionaryValue.SetInt(key, integer(dataValue.GetUIntValue))
        else if dataValue.IsDouble then
          DictionaryValue.SetDouble(key, dataValue.GetDoubleValue)
        else if dataValue.IsBool then
          DictionaryValue.SetBool(key, dataValue.GetBoolValue)
        else if dataValue.IsArray then
          DictionaryValue.SetList(key, V8ValueToListValue(dataValue))
        else if dataValue.IsObject then
          DictionaryValue.SetDictionary(key, V8ValueToDictionaryValue(dataValue))
        else
          DictionaryValue.SetNull(key);
        Inc(I);
        TCefv8ValueRef(dataValue).Free;
      end;
      Result := DictionaryValue;
    except
      on E: Exception do
    end;
  finally
    keys.Free;
  end;
end;

class constructor TValueConvert.Create;
begin
end;

class destructor TValueConvert.Destroy;
begin
end;

end.
