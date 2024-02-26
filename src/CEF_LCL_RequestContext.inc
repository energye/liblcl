//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------


procedure  RequestContextRef_Global(out Result: ICefRequestContext); extdecl;
begin
  handleExceptionBegin
  Result := TCefRequestContextRef.Global();
  handleExceptionEnd
end;

procedure  RequestContextRef_New(const PRequestContextSettings: PRCefRequestContextSettings; const handler: ICefRequestContextHandler; out Result: ICefRequestContext); extdecl;
var
  requestContextSettings: PCefRequestContextSettings;
begin
  handleExceptionBegin
  //ICefRequestContext
  requestContextSettings := new(PCefRequestContextSettings);
  requestContextSettings^.size := SizeOf(TCefRequestContextSettings);
  requestContextSettings^.cache_path := CefString(PCharToUStr(PRequestContextSettings^.cachePath));
  requestContextSettings^.persist_session_cookies := Integer(PRequestContextSettings^.persistSessionCookies);
  requestContextSettings^.persist_user_preferences := Integer(PRequestContextSettings^.persistUserPreferences);
  requestContextSettings^.accept_language_list := CefString(PCharToUStr(PRequestContextSettings^.acceptLanguageList));

  Result := TCefRequestContextRef.New(requestContextSettings, handler);
  handleExceptionEnd
end;

procedure  RequestContextRef_NewTwo(const aCache, aAcceptLanguageList, aCookieableSchemesList : PChar; aCookieableSchemesExcludeDefaults, aPersistSessionCookies, aPersistUserPreferences : LongBool; const handler: ICefRequestContextHandler; out Result: ICefRequestContext); extdecl;
begin
  handleExceptionBegin
  Result := TCefRequestContextRef.New(PCharToUStr(aCache), PCharToUStr(aAcceptLanguageList), aPersistSessionCookies, aPersistUserPreferences, False, handler);
  handleExceptionEnd
end;

procedure  RequestContextRef_Shared(const other: ICefRequestContext; const handler: ICefRequestContextHandler; out Result: ICefRequestContext); extdecl;
begin
  handleExceptionBegin
  Result := TCefRequestContextRef.Shared(other, handler);
  handleExceptionEnd
end;

function  RequestContext_HasPreference(const TObj: ICefRequestContext; const name: PChar): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasPreference(PCharToUStr(name));
  handleExceptionEnd
end;

procedure  RequestContext_GetPreference(const TObj: ICefRequestContext; const name: PChar; var Result: ICefValue);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetPreference(PCharToUStr(name));
  handleExceptionEnd
end;

procedure  RequestContext_GetAllPreferences(const TObj: ICefRequestContext; includeDefaults: LongBool; var Result: ICefDictionaryValue);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetAllPreferences(includeDefaults);
  handleExceptionEnd
end;

function  RequestContext_CanSetPreference(const TObj: ICefRequestContext; const name: PChar): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.CanSetPreference(PCharToUStr(name));
  handleExceptionEnd
end;

function  RequestContext_SetPreference(const TObj: ICefRequestContext; const name: PChar; const value: ICefValue; var outError: PChar): LongBool;  extdecl;
var
  error: ustring;
begin
  handleExceptionBegin
  error := '';
  Result := TObj.SetPreference(PCharToUStr(name), value, error);
  outError := PChar(string(error));
  handleExceptionEnd
end;

function  RequestContext_IsSame(const TObj: ICefRequestContext; const other: ICefRequestContext): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSame(other);
  handleExceptionEnd
end;

function  RequestContext_IsSharingWith(const TObj: ICefRequestContext; const other: ICefRequestContext): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSharingWith(other);
  handleExceptionEnd
end;

function  RequestContext_IsGlobal(const TObj: ICefRequestContext): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsGlobal;
  handleExceptionEnd
end;

procedure  RequestContext_GetHandler(const TObj: ICefRequestContext; var Result: ICefRequestContextHandler);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHandler;
  handleExceptionEnd
end;

function  RequestContext_GetCachePath(const TObj: ICefRequestContext): PChar;  extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetCachePath));
  handleExceptionEnd
end;

procedure  RequestContext_GetCookieManager(const TObj: ICefRequestContext; const callback: ICefCompletionCallback; var Result: ICefCookieManager);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDefaultCookieManager(callback);
  handleExceptionEnd
end;

function  RequestContext_RegisterSchemeHandlerFactory(const TObj: ICefRequestContext; const schemeName, domainName: PChar; const factory: ICefSchemeHandlerFactory): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.RegisterSchemeHandlerFactory(PCharToUStr(schemeName), PCharToUStr(domainName), factory);
  handleExceptionEnd
end;

function  RequestContext_ClearSchemeHandlerFactories(const TObj: ICefRequestContext): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.ClearSchemeHandlerFactories;
  handleExceptionEnd
end;

procedure RequestContext_ClearCertificateExceptions(const TObj: ICefRequestContext; const callback: ICefCompletionCallback);  extdecl;
begin
  handleExceptionBegin
  TObj.ClearCertificateExceptions(callback);
  handleExceptionEnd
end;

procedure RequestContext_CloseAllConnections(const TObj: ICefRequestContext; const callback: ICefCompletionCallback);  extdecl;
begin
  handleExceptionBegin
  TObj.CloseAllConnections(callback);
  handleExceptionEnd
end;

procedure RequestContext_ResolveHost(const TObj: ICefRequestContext; const origin: PChar; const callback: ICefResolveCallback);  extdecl;
begin
  handleExceptionBegin
  TObj.ResolveHost(PCharToUStr(origin), callback);
  handleExceptionEnd
end;

exports
  RequestContextRef_Global,
  RequestContextRef_New,
  RequestContextRef_NewTwo,
  RequestContextRef_Shared,
  RequestContext_HasPreference,
  RequestContext_GetPreference,
  RequestContext_GetAllPreferences,
  RequestContext_CanSetPreference,
  RequestContext_SetPreference,
  RequestContext_IsSame,
  RequestContext_IsSharingWith,
  RequestContext_IsGlobal,
  RequestContext_GetHandler,
  RequestContext_GetCachePath,
  RequestContext_GetCookieManager,
  RequestContext_RegisterSchemeHandlerFactory,
  RequestContext_ClearSchemeHandlerFactories,
  RequestContext_ClearCertificateExceptions,
  RequestContext_CloseAllConnections,
  RequestContext_ResolveHost;
