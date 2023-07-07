//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure PostDataElementRef_Create(var Result: ICefPostDataElement); extdecl;
begin
  handleExceptionBegin
  Result := TCefPostDataElementRef.New;
  handleExceptionEnd
end;

procedure PostDataElementRef_UnWrap(const data: ICefPostDataElement; var Result: ICefPostDataElement); extdecl;
begin
  handleExceptionBegin
  Result := TCefPostDataElementRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function  PostDataElement_IsReadOnly(const TObj: ICefPostDataElement): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly();
  handleExceptionEnd
end;

procedure PostDataElement_SetToEmpty(const TObj: ICefPostDataElement); extdecl;
begin
  handleExceptionBegin
  TObj.SetToEmpty();
  handleExceptionEnd
end;

procedure PostDataElement_SetToFile(const TObj: ICefPostDataElement; const PFileName: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetToFile(PCharToUStr(PFileName));
  handleExceptionEnd
end;

procedure PostDataElement_SetToBytes(const TObj: ICefPostDataElement; size: NativeUInt; const bytes: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.SetToBytes(size, bytes);
  handleExceptionEnd
end;

function  PostDataElement_GetType(const TObj: ICefPostDataElement): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TObj.GetType);
  handleExceptionEnd
end;

function  PostDataElement_GetFile(const TObj: ICefPostDataElement): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetFile()));
  handleExceptionEnd
end;

function  PostDataElement_GetBytesCount(const TObj: ICefPostDataElement): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBytesCount();
  handleExceptionEnd
end;

function  PostDataElement_GetBytes(const TObj: ICefPostDataElement; size: NativeUInt; var bytes: Pointer): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBytes(size, bytes);
  handleExceptionEnd
end;

exports
  PostDataElementRef_Create,
  PostDataElementRef_UnWrap,
  PostDataElement_IsReadOnly,
  PostDataElement_SetToEmpty,
  PostDataElement_SetToFile,
  PostDataElement_SetToBytes,
  PostDataElement_GetType,
  PostDataElement_GetFile,
  PostDataElement_GetBytesCount,
  PostDataElement_GetBytes;