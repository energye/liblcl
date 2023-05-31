//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefResponseRef_New(var Result: ICefResponse); extdecl;
begin
  handleExceptionBegin
  Result := TCefResponseRef.New;
  handleExceptionEnd
end;

procedure CefResponseRef_UnWrap(const data: ICefResponse; var Result: ICefResponse); extdecl;
begin
  handleExceptionBegin
  Result := TCefResponseRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function CefResponse_IsReadOnly(const TObj: ICefResponse): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly;
  handleExceptionEnd
end;

function CefResponse_GetError(const TObj: ICefResponse): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefErrorCode
  Result := Integer(TObj.Error);
  handleExceptionEnd
end;

procedure CefResponse_SetError(const TObj: ICefResponse; error: integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetError(error);
  handleExceptionEnd
end;

function CefResponse_GetStatus(const TObj: ICefResponse): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Status;
  handleExceptionEnd
end;

procedure CefResponse_SetStatus(const TObj: ICefResponse; status: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetStatus(status);
  handleExceptionEnd
end;

function CefResponse_GetStatusText(const TObj: ICefResponse): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.StatusText));
  handleExceptionEnd
end;

procedure CefResponse_SetStatusText(const TObj: ICefResponse; statusText: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetStatusText(PCharToUStr(statusText));
  handleExceptionEnd
end;

function CefResponse_GetMimeType(const TObj: ICefResponse): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.MimeType));
  handleExceptionEnd
end;

procedure CefResponse_SetMimeType(const TObj: ICefResponse; mimetype: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetMimeType(PCharToUStr(mimetype));
  handleExceptionEnd
end;

function CefResponse_GetCharset(const TObj: ICefResponse): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Charset));
  handleExceptionEnd
end;

procedure CefResponse_SetCharset(const TObj: ICefResponse; charset: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetCharset(PCharToUStr(charset));
  handleExceptionEnd
end;

function CefResponse_GetHeaderByName(const TObj: ICefResponse; name: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetHeaderByName(PCharToUStr(name))));
  handleExceptionEnd
end;

procedure CefResponse_SetHeaderByName(const TObj: ICefResponse; name, value: PChar; overwrite: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderByName(PCharToUStr(name), PCharToUStr(value), overwrite);
  handleExceptionEnd
end;

function CefResponse_GetURL(const TObj: ICefResponse): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.URL));
  handleExceptionEnd
end;

procedure CefResponse_SetURL(const TObj: ICefResponse; url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetURL(PCharToUStr(url));
  handleExceptionEnd
end;

procedure CefResponse_GetHeaderMap(const TObj: ICefResponse; var Result: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  Result := TCefStringMultimapOwn.Create();
  TObj.GetHeaderMap(Result);
  handleExceptionEnd
end;

procedure CefResponse_SetHeaderMap(const TObj: ICefResponse; const HeaderMap: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderMap(HeaderMap);
  handleExceptionEnd
end;

exports
  CefResponseRef_New,
  CefResponseRef_UnWrap,
  CefResponse_IsReadOnly,
  CefResponse_GetError,
  CefResponse_SetError,
  CefResponse_GetStatus,
  CefResponse_SetStatus,
  CefResponse_GetStatusText,
  CefResponse_SetStatusText,
  CefResponse_GetMimeType,
  CefResponse_SetMimeType,
  CefResponse_GetCharset,
  CefResponse_SetCharset,
  CefResponse_GetHeaderByName,
  CefResponse_SetHeaderByName,
  CefResponse_GetURL,
  CefResponse_SetURL,
  CefResponse_GetHeaderMap,
  CefResponse_SetHeaderMap
;
