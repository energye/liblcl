//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function cefResponse_IsReadOnly(TObj: ICefResponse): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly;
  handleExceptionEnd
end;

procedure cefResponse_SetError(TObj: ICefResponse; error: integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetError(error);
  handleExceptionEnd
end;

procedure cefResponse_SetStatus(TObj: ICefResponse; status: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetStatus(status);
  handleExceptionEnd
end;

procedure cefResponse_SetStatusText(TObj: ICefResponse; statusText: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetStatusText(PCharToUStr(statusText));
  handleExceptionEnd
end;
procedure cefResponse_SetMimeType(TObj: ICefResponse; mimetype: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetMimeType(PCharToUStr(mimetype));
  handleExceptionEnd
end;

procedure cefResponse_SetCharset(TObj: ICefResponse; charset: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetCharset(PCharToUStr(charset));
  handleExceptionEnd
end;

function cefResponse_GetHeaderByName(TObj: ICefResponse; name: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  TObj.GetHeaderByName(PCharToUStr(name));
  handleExceptionEnd
end;

procedure cefResponse_SetHeaderByName(TObj: ICefResponse; name, value: PChar; overwrite: boolean); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderByName(PCharToUStr(name), PCharToUStr(value), overwrite);
  handleExceptionEnd
end;

procedure cefResponse_SetURL(TObj: ICefResponse; url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetURL(PCharToUStr(url));
  handleExceptionEnd
end;

function cefResponse_GetHeaderMap(TObj: ICefResponse): TCefCustomStringMultimap; extdecl;
var
  headerMap: TCefCustomStringMultimap;
begin
  handleExceptionBegin
  headerMap := TCefStringMultimapOwn.Create;
  TObj.GetHeaderMap(headerMap);
  Result := headerMap;
  handleExceptionEnd
end;

exports
  cefResponse_IsReadOnly,
  cefResponse_SetError,
  cefResponse_SetStatus,
  cefResponse_SetStatusText,
  cefResponse_SetMimeType,
  cefResponse_SetCharset,
  cefResponse_GetHeaderByName,
  cefResponse_SetHeaderByName,
  cefResponse_SetURL,
  cefResponse_GetHeaderMap
;
