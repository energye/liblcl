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

procedure  RequestContextRef_New(var RequestContextSettings: PMCefRequestContextSettings; const handler: ICefRequestContextHandler; out Result: ICefRequestContext); extdecl;
var
  TempRequestContextSettings: TCefRequestContextSettings;
begin
  handleExceptionBegin
  TempRequestContextSettings := RequestContextSettingsToPas(RequestContextSettings);
  Result := TCefRequestContextRef.New(@TempRequestContextSettings, handler);
  handleExceptionEnd
end;

procedure  RequestContextRef_NewTwo(const aCache, aAcceptLanguageList, aCookieableSchemesList : PChar; aCookieableSchemesExcludeDefaults, aPersistSessionCookies: LongBool;
  const handler: ICefRequestContextHandler; out Result: ICefRequestContext); extdecl;
begin
  handleExceptionBegin
  Result := TCefRequestContextRef.New(PCharToUStr(aCache), PCharToUStr(aAcceptLanguageList), PCharToUStr(aCookieableSchemesList), aCookieableSchemesExcludeDefaults, aPersistSessionCookies, handler);
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
  Result := TObj.GetCookieManager(callback);
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

procedure RequestContext_ClearHttpAuthCredentials(const TObj: ICefRequestContext; const callback: ICefCompletionCallback);  extdecl;
begin
  handleExceptionBegin
  TObj.ClearHttpAuthCredentials(callback);
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

procedure  RequestContext_GetMediaRouter(const TObj: ICefRequestContext; const callback: ICefCompletionCallback; var Result: ICefMediaRouter);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetMediaRouter(callback);
  handleExceptionEnd
end;

procedure  RequestContext_WebsiteSetting(IsSet: LongBool; const TObj: ICefRequestContext; const requesting_url, top_level_url: PChar; content_type: TCefContentSettingTypes; newValue: ICefValue; out Result: ICefValue); extdecl;
begin
   handleExceptionBegin
   if IsSet then
   begin
     TObj.SetWebsiteSetting(PCharToUStr(requesting_url), PCharToUStr(top_level_url), content_type, newValue);
   end
   else
   begin
     Result := TObj.GetWebsiteSetting(PCharToUStr(requesting_url), PCharToUStr(top_level_url), content_type);
   end;
   handleExceptionEnd
end;

function  RequestContext_ContentSetting(IsSet: LongBool; const TObj: ICefRequestContext; const requesting_url, top_level_url: PChar; content_type: TCefContentSettingTypes; value: TCefContentSettingValues): TCefContentSettingValues; extdecl;
begin
   handleExceptionBegin
   if IsSet then
   begin
     TObj.SetContentSetting(PCharToUStr(requesting_url), PCharToUStr(top_level_url), content_type, value);
   end
   else
   begin
     Result := TObj.GetContentSetting(PCharToUStr(requesting_url), PCharToUStr(top_level_url), content_type);
   end;
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
  RequestContext_ClearHttpAuthCredentials,
  RequestContext_CloseAllConnections,
  RequestContext_ResolveHost,
  RequestContext_GetMediaRouter,
  RequestContext_WebsiteSetting,
  RequestContext_ContentSetting;
