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
  CefResponse_GetStatus,
  CefResponse_SetStatus,
  CefResponse_GetStatusText,
  CefResponse_SetStatusText,
  CefResponse_GetMimeType,
  CefResponse_SetMimeType,
  CefResponse_GetHeaderMap,
  CefResponse_SetHeaderMap;
