//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBinaryValueRef_New(const data: Pointer; dataSize: NativeUInt; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TCefBinaryValueRef.New(data, dataSize);
  handleExceptionEnd
end;

procedure CefBinaryValueRef_Create(var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TCefBinaryValueOwn.Create;
  handleExceptionEnd
end;

procedure CefBinaryValueRef_UnWrap(const data: ICefBinaryValue; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TCefBinaryValueRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function CefBinaryValue_IsValid(const TObj: ICefBinaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid();
  handleExceptionEnd
end;

function CefBinaryValue_IsOwned(const TObj: ICefBinaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsOwned();
  handleExceptionEnd
end;

procedure CefBinaryValue_Copy(const TObj: ICefBinaryValue; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Copy();
  handleExceptionEnd
end;

function CefBinaryValue_GetSize(const TObj: ICefBinaryValue): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetSize();
  handleExceptionEnd
end;

function CefBinaryValue_GetData(const TObj: ICefBinaryValue; buffer: Pointer; bufferSize, dataOffset: NativeUInt): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetData(buffer, bufferSize, dataOffset);
  handleExceptionEnd
end;

exports
    CefBinaryValueRef_New,
    CefBinaryValueRef_Create,
    CefBinaryValueRef_UnWrap,
    CefBinaryValue_IsValid,
    CefBinaryValue_IsOwned,
    CefBinaryValue_Copy,
    CefBinaryValue_GetSize,
    CefBinaryValue_GetData
;
