//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefRequestRef_UnWrap(const data: ICefRequest; out Result: ICefRequest); extdecl;
begin
  handleExceptionBegin
  Result := TCefRequestRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function CefRequest_IsReadOnly(const TObj: ICefRequest): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly;
  handleExceptionEnd
end;

procedure CefRequest_SetUrl(const TObj: ICefRequest; Url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetUrl(PCharToUStr(Url));
  handleExceptionEnd
end;

procedure CefRequest_SetMethod(const TObj: ICefRequest; Method: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetMethod(PCharToUStr(Method));
  handleExceptionEnd
end;

procedure CefRequest_SetReferrer(const TObj: ICefRequest; referrerUrl: PChar; policy: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetReferrer(PCharToUStr(referrerUrl), TCefReferrerPolicy(policy));
  handleExceptionEnd
end;

procedure CefRequest_SetFlags(const TObj: ICefRequest; flags: Cardinal); extdecl;
begin
  handleExceptionBegin
  TObj.SetFlags(flags);
  handleExceptionEnd
end;

procedure CefRequest_SetFirstPartyForCookies(const TObj: ICefRequest; url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetFirstPartyForCookies(PCharToUStr(url));
  handleExceptionEnd
end;

function CefRequest_GetHeaderByName(const TObj: ICefRequest; name: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetHeaderByName(PCharToUStr(name))));
  handleExceptionEnd
end;

procedure CefRequest_SetHeaderByName(const TObj: ICefRequest; name, value: PChar ; overwrite: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderByName(PCharToUStr(name), PCharToUStr(value), overwrite);
  handleExceptionEnd
end;

procedure CefRequest_GetHeaderMap(const TObj: ICefRequest; out Result: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  Result := TCefStringMultimapOwn.Create();
  TObj.GetHeaderMap(Result);
  handleExceptionEnd
end;

procedure CefRequest_SetHeaderMap(const TObj: ICefRequest; const HeaderMap: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderMap(HeaderMap);
  handleExceptionEnd
end;

procedure CefRequest_GetPostData(const TObj: ICefRequest; out Result: ICefPostData); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetPostData();
  handleExceptionEnd
end;

procedure CefRequest_SetPostData(const TObj: ICefRequest; const value: ICefPostData); extdecl;
begin
  handleExceptionBegin
  TObj.SetPostData(value);
  handleExceptionEnd
end;


exports
  CefRequestRef_UnWrap,
  CefRequest_IsReadOnly,
  CefRequest_SetUrl,
  CefRequest_SetMethod,
  CefRequest_SetReferrer,
  CefRequest_SetFlags,
  CefRequest_SetFirstPartyForCookies,
  CefRequest_GetHeaderByName,
  CefRequest_SetHeaderByName,
  CefRequest_GetHeaderMap,
  CefRequest_SetHeaderMap,
  CefRequest_GetPostData,
  CefRequest_SetPostData
;
