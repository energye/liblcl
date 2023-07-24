//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefValueRef_New(out Result: ICefValue); extdecl;
begin
  handleExceptionBegin
  Result := TCefValueRef.New();
  handleExceptionEnd
end;

procedure CefValueRef_UnWrap(const data: ICefValue; out Result: ICefValue); extdecl;
begin
  handleExceptionBegin
  Result := TCefValueRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function CefValue_IsValid(const TObj: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid();
  handleExceptionEnd
end;

function CefValue_IsOwned(const TObj: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsOwned();
  handleExceptionEnd
end;

function CefValue_IsReadOnly(const TObj: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly();
  handleExceptionEnd
end;

procedure CefValue_Copy(const TObj: ICefValue; out Result: ICefValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Copy();
  handleExceptionEnd
end;

function CefValue_GetType(const TObj: ICefValue): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TObj.GetType());
  handleExceptionEnd
end;

function CefValue_GetBool(const TObj: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBool();
  handleExceptionEnd
end;

function CefValue_GetInt(const TObj: ICefValue): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetInt();
  handleExceptionEnd
end;

procedure CefValue_GetDouble(const TObj: ICefValue; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDouble();
  handleExceptionEnd
end;

procedure CefValue_GetString(const TObj: ICefValue; const TValue: TString); extdecl;
begin
  handleExceptionBegin
  TValue.SetValue(string(TObj.GetString()));
  handleExceptionEnd
end;

procedure CefValue_GetBinary(const TObj: ICefValue; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBinary();
  handleExceptionEnd
end;

procedure CefValue_GetDictionary(const TObj: ICefValue; var Result: ICefDictionaryValue) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDictionary();
  handleExceptionEnd
end;

procedure CefValue_GetList(const TObj: ICefValue; var Result: ICefListValue) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetList();
  handleExceptionEnd
end;

function CefValue_SetNull(const TObj: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetNull();
  handleExceptionEnd
end;

function CefValue_SetBool(const TObj: ICefValue; value: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetBool(value);
  handleExceptionEnd
end;

function CefValue_SetInt(const TObj: ICefValue; value: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetInt(value);
  handleExceptionEnd
end;

function CefValue_SetDouble(const TObj: ICefValue; value: Pointer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetDouble(Double(PDouble(value)^));
  handleExceptionEnd
end;

function CefValue_SetString(const TObj: ICefValue; const value: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetString(PCharToUStr(value));
  handleExceptionEnd
end;

function CefValue_SetBinary(const TObj: ICefValue; const value: ICefBinaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetBinary(value);
  handleExceptionEnd
end;

function CefValue_SetDictionary(const TObj: ICefValue; const value: ICefDictionaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetDictionary(value);
  handleExceptionEnd
end;

function CefValue_SetList(const TObj: ICefValue; const value: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetList(value);
  handleExceptionEnd
end;

exports
  CefValueRef_New,
  CefValueRef_UnWrap,
  CefValue_IsValid,
  CefValue_IsOwned,
  CefValue_IsReadOnly,
  CefValue_Copy,
  CefValue_GetType,
  CefValue_GetBool,
  CefValue_GetInt,
  CefValue_GetDouble,
  CefValue_GetString,
  CefValue_GetBinary,
  CefValue_GetDictionary,
  CefValue_GetList,
  CefValue_SetNull,
  CefValue_SetBool,
  CefValue_SetInt,
  CefValue_SetDouble,
  CefValue_SetString,
  CefValue_SetBinary,
  CefValue_SetDictionary,
  CefValue_SetList;