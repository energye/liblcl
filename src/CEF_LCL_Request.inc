//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefRequestRef_UnWrap(const data: ICefRequest; var Result: ICefRequest); extdecl;
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

function CefRequest_GetUrl(const TObj: ICefRequest): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Url));
  handleExceptionEnd
end;

procedure CefRequest_SetUrl(const TObj: ICefRequest; Url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetUrl(PCharToUStr(Url));
  handleExceptionEnd
end;

function CefRequest_GetMethod(const TObj: ICefRequest): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Method));
  handleExceptionEnd
end;

procedure CefRequest_SetMethod(const TObj: ICefRequest; Method: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetMethod(PCharToUStr(Method));
  handleExceptionEnd
end;

function CefRequest_GetReferrerUrl(const TObj: ICefRequest): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.ReferrerUrl));
  handleExceptionEnd
end;

procedure CefRequest_SetReferrer(const TObj: ICefRequest; referrerUrl: PChar; policy: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetReferrer(PCharToUStr(referrerUrl), TCefReferrerPolicy(policy));
  handleExceptionEnd
end;

function CefRequest_GetReferrerPolicy(const TObj: ICefRequest): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefReferrerPolicy
  Result := Integer(TObj.ReferrerPolicy);
  handleExceptionEnd
end;

function CefRequest_GetFlags(const TObj: ICefRequest): TCefUrlRequestFlags; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Flags;
  handleExceptionEnd
end;

procedure CefRequest_SetFlags(const TObj: ICefRequest; flags: TCefUrlRequestFlags); extdecl;
begin
  handleExceptionBegin
  TObj.SetFlags(flags);
  handleExceptionEnd
end;

function CefRequest_GetFirstPartyForCookies(const TObj: ICefRequest): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.FirstPartyForCookies));
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

procedure CefRequest_GetHeaderMap(const TObj: ICefRequest; var Result: ICefStringMultimap); extdecl;
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

procedure CefRequest_GetPostData(const TObj: ICefRequest; var Result: ICefPostData); extdecl;
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

function CefRequest_GetResourceType(const TObj: ICefRequest): Integer; extdecl;
begin
  handleExceptionBegin
  //TCefResourceType
  Result := Integer(TObj.ResourceType);
  handleExceptionEnd
end;

function CefRequest_GetTransitionType(const TObj: ICefRequest): Integer; extdecl;
begin
  handleExceptionBegin
  //TCefTransitionType
  Result := Integer(TObj.TransitionType);
  handleExceptionEnd
end;

procedure CefRequest_GetIdentifier(const TObj: ICefRequest; var Result: UInt64); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Identifier;
  handleExceptionEnd
end;


exports
  CefRequestRef_UnWrap,
  CefRequest_IsReadOnly,
  CefRequest_GetUrl,
  CefRequest_SetUrl,
  CefRequest_GetMethod,
  CefRequest_SetMethod,
  CefRequest_GetReferrerUrl,
  CefRequest_SetReferrer,
  CefRequest_GetReferrerPolicy,
  CefRequest_GetFlags,
  CefRequest_SetFlags,
  CefRequest_GetFirstPartyForCookies,
  CefRequest_SetFirstPartyForCookies,
  CefRequest_GetHeaderByName,
  CefRequest_SetHeaderByName,
  CefRequest_GetHeaderMap,
  CefRequest_SetHeaderMap,
  CefRequest_GetPostData,
  CefRequest_SetPostData,
  CefRequest_GetResourceType,
  CefRequest_GetTransitionType,
  CefRequest_GetIdentifier
;
