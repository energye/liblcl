//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefDictionaryValueRef_New(out Result: ICefDictionaryValue); extdecl;
begin
    handleExceptionBegin
    Result := TCefDictionaryValueRef.New();
    handleExceptionEnd
end;

function CefDictionaryValue_IsValid(const TObj: ICefDictionaryValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsValid();
    handleExceptionEnd
end;

function CefDictionaryValue_IsOwned(const TObj: ICefDictionaryValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.isOwned();
    handleExceptionEnd
end;

function CefDictionaryValue_IsReadOnly(const TObj: ICefDictionaryValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsReadOnly();
    handleExceptionEnd
end;

procedure CefDictionaryValue_Copy(const TObj: ICefDictionaryValue; excludeEmptyChildren: LongBool; out Result: ICefDictionaryValue); extdecl;
begin
    handleExceptionBegin
    Result := TObj.Copy(excludeEmptyChildren);
    handleExceptionEnd
end;

function CefDictionaryValue_GetSize(const TObj: ICefDictionaryValue): NativeUInt; extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetSize();
    handleExceptionEnd
end;

function CefDictionaryValue_Clear(const TObj: ICefDictionaryValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.Clear();
    handleExceptionEnd
end;

function CefDictionaryValue_HasKey(const TObj: ICefDictionaryValue; const key: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.HasKey(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_GetKeys(const TObj: ICefDictionaryValue; const keys: TStrings): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetKeys(keys);
    handleExceptionEnd
end;

function CefDictionaryValue_Remove(const TObj: ICefDictionaryValue; const key: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.Remove(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_GetType(const TObj: ICefDictionaryValue; const key: PChar): Integer; extdecl;
begin
    handleExceptionBegin
    Result := Integer(TObj.GetType(PCharToUStr(key)));
    handleExceptionEnd
end;

procedure CefDictionaryValue_GetValue(const TObj: ICefDictionaryValue; const key: PChar; out Result: ICefValue); extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetValue(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_GetBool(const TObj: ICefDictionaryValue; const key: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetBool(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_GetInt(const TObj: ICefDictionaryValue; const key: PChar): Integer; extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetInt(PCharToUStr(key));
    handleExceptionEnd
end;

procedure CefDictionaryValue_GetDouble(const TObj: ICefDictionaryValue; const key: PChar; out Result: Double); extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetDouble(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_GetString(const TObj: ICefDictionaryValue; const key: PChar): PChar; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(TObj.GetString(PCharToUStr(key))));
    handleExceptionEnd
end;

procedure CefDictionaryValue_GetBinary(const TObj: ICefDictionaryValue; const key: PChar; out Result: ICefBinaryValue); extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetBinary(PCharToUStr(key));
    handleExceptionEnd
end;

procedure CefDictionaryValue_GetDictionary(const TObj: ICefDictionaryValue; const key: PChar; out Result: ICefDictionaryValue); extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetDictionary(PCharToUStr(key));
    handleExceptionEnd
end;

procedure CefDictionaryValue_GetList(const TObj: ICefDictionaryValue; const key: PChar; out Result: ICefListValue); extdecl;
begin
    handleExceptionBegin
    Result := TObj.GetList(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_SetValue(const TObj: ICefDictionaryValue; const key: PChar; const value: ICefValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetValue(PCharToUStr(key), value);
    handleExceptionEnd
end;

function CefDictionaryValue_SetNull(const TObj: ICefDictionaryValue; const key: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetNull(PCharToUStr(key));
    handleExceptionEnd
end;

function CefDictionaryValue_SetBool(const TObj: ICefDictionaryValue; const key: PChar; value: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetBool(PCharToUStr(key), value);
    handleExceptionEnd
end;

function CefDictionaryValue_SetInt(const TObj: ICefDictionaryValue; const key: PChar; value: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetInt(PCharToUStr(key), value);
    handleExceptionEnd
end;

function CefDictionaryValue_SetDouble(const TObj: ICefDictionaryValue; const key: PChar; value: Pointer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetDouble(PCharToUStr(key), Double(PDouble(value)^));
    handleExceptionEnd
end;

function CefDictionaryValue_SetString(const TObj: ICefDictionaryValue; const key, value: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetString(PCharToUStr(key), PCharToUStr(value));
    handleExceptionEnd
end;

function CefDictionaryValue_SetBinary(const TObj: ICefDictionaryValue; const key: PChar; const value: ICefBinaryValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetBinary(PCharToUStr(key), value);
    handleExceptionEnd
end;

function CefDictionaryValue_SetDictionary(const TObj: ICefDictionaryValue; const key: PChar; const value: ICefDictionaryValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetDictionary(PCharToUStr(key), value);
    handleExceptionEnd
end;

function CefDictionaryValue_SetList(const TObj: ICefDictionaryValue; const key: PChar; const value: ICefListValue): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.SetList(PCharToUStr(key), value);
    handleExceptionEnd
end;

exports
    CefDictionaryValueRef_New,
    CefDictionaryValue_IsValid,
    CefDictionaryValue_IsOwned,
    CefDictionaryValue_IsReadOnly,
    CefDictionaryValue_Copy,
    CefDictionaryValue_GetSize,
    CefDictionaryValue_Clear,
    CefDictionaryValue_HasKey,
    CefDictionaryValue_GetKeys,
    CefDictionaryValue_Remove,
    CefDictionaryValue_GetType,
    CefDictionaryValue_GetValue,
    CefDictionaryValue_GetBool,
    CefDictionaryValue_GetInt,
    CefDictionaryValue_GetDouble,
    CefDictionaryValue_GetString,
    CefDictionaryValue_GetBinary,
    CefDictionaryValue_GetDictionary,
    CefDictionaryValue_GetList,
    CefDictionaryValue_SetValue,
    CefDictionaryValue_SetNull,
    CefDictionaryValue_SetBool,
    CefDictionaryValue_SetInt,
    CefDictionaryValue_SetDouble,
    CefDictionaryValue_SetString,
    CefDictionaryValue_SetBinary,
    CefDictionaryValue_SetDictionary,
    CefDictionaryValue_SetList
;
