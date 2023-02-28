//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//ICefProcessMessageRef
procedure CefProcessMessageRef_New(const name: PChar; out Result: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  Result := TCefProcessMessageRef.New(PCharToUStr(name));
  handleExceptionEnd
end;

procedure CefProcessMessage_ArgumentList(const TObj: ICefProcessMessage; out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.ArgumentList;
  handleExceptionEnd
end;

function CefProcessMessage_IsValid(const TObj: ICefProcessMessage): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid;
  handleExceptionEnd
end;

procedure CefProcessMessage_Copy(const TObj: ICefProcessMessage; out Result: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Copy;
  handleExceptionEnd
end;

function CefProcessMessage_Name(const TObj: ICefProcessMessage): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Name));
  handleExceptionEnd
end;

//ICefListValue
procedure CefListValue_New(out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  Result := TCefListValueRef.New;
  handleExceptionEnd
end;

function CefListValue_IsValid(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid;
  handleExceptionEnd
end;

function CefListValue_IsOwned(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsOwned;
  handleExceptionEnd
end;

function CefListValue_IsReadOnly(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly;
  handleExceptionEnd
end;

procedure CefListValue_Copy(const TObj: ICefListValue; out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Copy;
  handleExceptionEnd
end;

function CefListValue_SetSize(const TObj: ICefListValue; size: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetSize(size);
  handleExceptionEnd
end;

function CefListValue_GetSize(const TObj: ICefListValue): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetSize;
  handleExceptionEnd
end;

function CefListValue_Clear(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Clear;
  handleExceptionEnd
end;

function CefListValue_Remove(const TObj: ICefListValue; index: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Remove(index);
  handleExceptionEnd
end;

function CefListValue_GetType(const TObj: ICefListValue; index: NativeUInt): TCefValueType; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetType(index);
  handleExceptionEnd
end;

procedure CefListValue_GetValue(const TObj: ICefListValue; index: NativeUInt; out Result: ICefValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetValue(index);
  handleExceptionEnd
end;

function CefListValue_GetBool(const TObj: ICefListValue; index: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBool(index);
  handleExceptionEnd
end;

function CefListValue_GetInt(const TObj: ICefListValue; index: NativeUInt): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetInt(index);
  handleExceptionEnd
end;

procedure CefListValue_GetDouble(const TObj: ICefListValue; index: NativeUInt; out Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDouble(index);
  handleExceptionEnd
end;

function CefListValue_GetString(const TObj: ICefListValue; index: NativeUInt): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetString(index)));
  handleExceptionEnd
end;

procedure CefListValue_GetBinary(const TObj: ICefListValue; index: NativeUInt; out Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBinary(index);
  handleExceptionEnd
end;

procedure CefListValue_GetDictionary(const TObj: ICefListValue; index: NativeUInt; out Result: ICefDictionaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDictionary(index);
  handleExceptionEnd
end;

procedure CefListValue_GetList(const TObj: ICefListValue; index: NativeUInt; out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetList(index);
  handleExceptionEnd
end;

function CefListValue_SetValue(const TObj: ICefListValue; index: NativeUInt; const value: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetValue(index, value);
  handleExceptionEnd
end;

function CefListValue_SetNull(const TObj: ICefListValue; index: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetNull(index);
  handleExceptionEnd
end;

function CefListValue_SetBool(const TObj: ICefListValue; index: NativeUInt; value: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetBool(index, value);
  handleExceptionEnd
end;

function CefListValue_SetInt(const TObj: ICefListValue; index: NativeUInt; value: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetInt(index, value);
  handleExceptionEnd
end;

function CefListValue_SetDouble(const TObj: ICefListValue; index: NativeUInt; value: Pointer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetDouble(index, Double(PDouble(value)^));
  handleExceptionEnd
end;

function CefListValue_SetString(const TObj: ICefListValue; index: NativeUInt; const value: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetString(index, PCharToUStr(value));
  handleExceptionEnd
end;

function CefListValue_SetBinary(const TObj: ICefListValue; index: NativeUInt; const value: ICefBinaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetBinary(index, value);
  handleExceptionEnd
end;

function CefListValue_SetDictionary(const TObj: ICefListValue; index: NativeUInt; const value: ICefDictionaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetDictionary(index, value);
  handleExceptionEnd
end;

function CefListValue_SetList(const TObj: ICefListValue; index: NativeUInt; const value: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetList(index, value);
  handleExceptionEnd
end;


exports
//ICefProcessMessage
  CefProcessMessageRef_New,
  CefProcessMessage_ArgumentList,
  CefProcessMessage_IsValid,
  CefProcessMessage_Copy,
  CefProcessMessage_Name,
//ICefListValue
  CefListValue_New,
  CefListValue_IsValid,
  CefListValue_IsOwned,
  CefListValue_IsReadOnly,
  CefListValue_Copy,
  CefListValue_SetSize,
  CefListValue_GetSize,
  CefListValue_Clear,
  CefListValue_Remove,
  CefListValue_GetType,
  CefListValue_GetValue,
  CefListValue_GetBool,
  CefListValue_GetInt,
  CefListValue_GetDouble,
  CefListValue_GetString,
  CefListValue_GetBinary,
  CefListValue_GetDictionary,
  CefListValue_GetList,
  CefListValue_SetValue,
  CefListValue_SetNull,
  CefListValue_SetBool,
  CefListValue_SetInt,
  CefListValue_SetDouble,
  CefListValue_SetString,
  CefListValue_SetBinary,
  CefListValue_SetDictionary,
  CefListValue_SetList
;
