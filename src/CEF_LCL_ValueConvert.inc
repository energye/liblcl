//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

// JSONArray TBytes 转换 进程消息 ICefProcessMessage
procedure ValueConvert_BytesToProcessMessage(const PName: PChar; const Data: Pointer; dataSize: nativeuint; out Result: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  Result := TValueConvert.BytesToProcessMessage(PCharToUStr(PName), Data, dataSize);
  handleExceptionEnd
end;

// JSONArray TBytes 转换 ICefListValue
procedure ValueConvert_BytesToListValue(const Data: Pointer; dataSize: nativeuint; out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  Result := TValueConvert.BytesToListValue(Data, dataSize);
  handleExceptionEnd
end;

// TJSONObject TBytes 转换 ICefDictionaryValue
procedure ValueConvert_BytesToDictionaryValue(const Data: Pointer; dataSize: nativeuint; out Result: ICefDictionaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TValueConvert.BytesToDictionaryValue(Data, dataSize);
  handleExceptionEnd
end;

// JSONArray TBytes 转换 TCefv8ValueArray
procedure ValueConvert_BytesToV8ValueArray(const Data: Pointer; dataSize: nativeuint; out Result: TCefv8ValueArray; out ResultLength: Integer); extdecl;
var
  ValueArray: TCefv8ValueArray;
begin
  handleExceptionBegin
  ValueArray := TValueConvert.BytesToV8ValueArray(Data, dataSize);
  if ValueArray = nil then
  begin
    Result := nil;
    ResultLength := 0;
  end
  else
  begin
    Result := ValueArray;
    ResultLength := Length(ValueArray);
  end;
handleExceptionEnd
end;

// JSONArray TBytes 转换 ICefv8Value
procedure ValueConvert_BytesToV8Array(const Data: Pointer; dataSize: nativeuint; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TValueConvert.BytesToV8Array(Data, dataSize);
  handleExceptionEnd
end;

// JSONObject TBytes 转换 ICefv8Value
procedure ValueConvert_BytesToV8Object(const Data: Pointer; dataSize: nativeuint; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TValueConvert.BytesToV8Object(Data, dataSize);
  handleExceptionEnd
end;

exports
    ValueConvert_BytesToProcessMessage,
    ValueConvert_BytesToListValue,
    ValueConvert_BytesToDictionaryValue,
    ValueConvert_BytesToV8ValueArray,
    ValueConvert_BytesToV8Array,
    ValueConvert_BytesToV8Object
;
