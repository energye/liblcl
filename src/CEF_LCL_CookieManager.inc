//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefCookieManager_VisitAllCookies(const AObj: ICefCookieManager; const visitor: ICefCookieVisitor); extdecl;
begin
  handleExceptionBegin
  AObj.VisitAllCookies(visitor);
  handleExceptionEnd
end;

function  CefCookieManager_VisitUrlCookies(const AObj: ICefCookieManager; const url: PChar; includeHttpOnly: LongBool; const visitor: ICefCookieVisitor): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.VisitUrlCookies(PCharToUStr(url), includeHttpOnly, visitor);
  handleExceptionEnd
end;

function  CefCookieManager_SetCookie(const AObj: ICefCookieManager; CefCookie: PRCefCookie; const callback: ICefSetCookieCallback): LongBool; extdecl;
var
  url, name, value, domain, path: ustring;
  secure, httponly, hasExpires: LongBool;
  creation, lastAccess, expires: double;
  sameSite: TCefCookieSameSite;
  priority: TCefCookiePriority;
begin
  handleExceptionBegin
  url := PCharToUStr(CefCookie.url);
  name := PCharToUStr(CefCookie.name);
  value := PCharToUStr(CefCookie.value);
  domain := PCharToUStr(CefCookie.domain);
  path := PCharToUStr(CefCookie.path);
  secure := PLongBool(CefCookie.secure)^;
  httponly := PLongBool(CefCookie.httponly)^;
  hasExpires := PLongBool(CefCookie.hasExpires)^;
  creation := Double(PDouble(CefCookie.creation)^);
  lastAccess := Double(PDouble(CefCookie.lastAccess)^);
  expires := Double(PDouble(CefCookie.expires)^);
  sameSite := TCefCookieSameSite(CefCookie.sameSite^);
  priority := TCefCookiePriority(CefCookie.priority^);
  Result := AObj.SetCookie(url, name, value, domain, path, secure, httponly, hasExpires, creation, lastAccess, expires, sameSite, priority, callback);
  CefCookie := nil;
  handleExceptionEnd
end;

function  CefCookieManager_DeleteCookies(const AObj: ICefCookieManager; const url, cookieName: PChar; const callback: ICefDeleteCookiesCallback): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DeleteCookies(PCharToUStr(url), PCharToUStr(cookieName), callback);
  handleExceptionEnd
end;

function  CefCookieManager_FlushStore(const AObj: ICefCookieManager; const callback: ICefCompletionCallback): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.FlushStore(callback);
  handleExceptionEnd
end;

exports
  CefCookieManager_VisitAllCookies,
  CefCookieManager_VisitUrlCookies,
  CefCookieManager_SetCookie,
  CefCookieManager_DeleteCookies,
  CefCookieManager_FlushStore;
