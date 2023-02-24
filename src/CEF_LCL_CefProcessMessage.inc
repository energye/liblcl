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

procedure CefProcessMessage_Free(var TObj: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  TObj := nil;
  handleExceptionEnd
end;

//ICefListValue
function CefListValue_IsValid(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_IsOwned(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_IsReadOnly(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_Copy(const TObj: ICefListValue; out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetSize(const TObj: ICefListValue; size: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_GetSize(const TObj: ICefListValue): NativeUInt; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_Clear(const TObj: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_Remove(const TObj: ICefListValue; index: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_GetType(const TObj: ICefListValue; index: NativeUInt): TCefValueType; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_GetValue(const TObj: ICefListValue; index: NativeUInt; out Result: ICefValue); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_GetBool(const TObj: ICefListValue; index: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_GetInt(const TObj: ICefListValue; index: NativeUInt): Integer; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_GetDouble(const TObj: ICefListValue; index: NativeUInt; out Result: Double); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_GetString(const TObj: ICefListValue; index: NativeUInt; out Result: PChar); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_GetBinary(const TObj: ICefListValue; index: NativeUInt; out Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_GetDictionary(const TObj: ICefListValue; index: NativeUInt; out Result: ICefDictionaryValue); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CefListValue_GetList(const TObj: ICefListValue; index: NativeUInt; out Result: ICefListValue); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetValue(const TObj: ICefListValue; index: NativeUInt; const value: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetNull(const TObj: ICefListValue; index: NativeUInt): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetBool(const TObj: ICefListValue; index: NativeUInt; value: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetInt(const TObj: ICefListValue; index: NativeUInt; value: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetDouble(const TObj: ICefListValue; index: NativeUInt; value: Double): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetString(const TObj: ICefListValue; index: NativeUInt; const value: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetBinary(const TObj: ICefListValue; index: NativeUInt; const value: ICefBinaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetDictionary(const TObj: ICefListValue; index: NativeUInt; const value: ICefDictionaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CefListValue_SetList(const TObj: ICefListValue; index: NativeUInt; const value: ICefListValue): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;


exports
//ICefProcessMessage
  CefProcessMessageRef_New,
  CefProcessMessage_ArgumentList,
  CefProcessMessage_Copy,
  CefProcessMessage_Name,
  CefProcessMessage_Free,
//ICefListValue
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
