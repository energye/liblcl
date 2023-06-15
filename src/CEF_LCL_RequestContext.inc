//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

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

procedure  RequestContext_GetCookieManager(const TObj: ICefRequestContext; const callback: TCompletionCallbackRef; var Result: ICefCookieManager);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetCookieManager(callback);
  handleExceptionEnd
end;

// GetCookieManager
//procedure  RequestContext_GetCookieManagerProc(const TObj: ICefRequestContext; const callback: TCefCompletionCallbackProc; var Result: ICefCookieManager);  extdecl;
//begin
//  handleExceptionBegin
//  handleExceptionEnd
//end;

function  RequestContext_RegisterSchemeHandlerFactory(const TObj: ICefRequestContext; const schemeName, domainName: PChar; const factory: TSchemeHandlerFactoryRef): LongBool;  extdecl;
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

procedure RequestContext_ClearCertificateExceptions(const TObj: ICefRequestContext; const callback: TCompletionCallbackRef);  extdecl;
begin
  handleExceptionBegin
  TObj.ClearCertificateExceptions(callback);
  handleExceptionEnd
end;

procedure RequestContext_ClearHttpAuthCredentials(const TObj: ICefRequestContext; const callback: TCompletionCallbackRef);  extdecl;
begin
  handleExceptionBegin
  TObj.ClearHttpAuthCredentials(callback);
  handleExceptionEnd
end;

procedure RequestContext_CloseAllConnections(const TObj: ICefRequestContext; const callback: TCompletionCallbackRef);  extdecl;
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

procedure RequestContext_LoadExtension(const TObj: ICefRequestContext; const root_directory: PChar; const manifest: ICefDictionaryValue; const handler: TExtensionHandlerRef);  extdecl;
begin
  handleExceptionBegin
  TObj.LoadExtension(PCharToUStr(root_directory), manifest, handler);
  handleExceptionEnd
end;

function  RequestContext_DidLoadExtension(const TObj: ICefRequestContext; const extension_id: PChar): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.DidLoadExtension(PCharToUStr(extension_id));
  handleExceptionEnd
end;

function  RequestContext_HasExtension(const TObj: ICefRequestContext; const extension_id: PChar): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasExtension(PCharToUStr(extension_id));
  handleExceptionEnd
end;

function  RequestContext_GetExtensions(const TObj: ICefRequestContext; const extension_ids: TStringList): LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetExtensions(extension_ids);
  handleExceptionEnd
end;

procedure  RequestContext_GetExtension(const TObj: ICefRequestContext; const extension_id: PChar; var Result: ICefExtension);  extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetExtension(PCharToUStr(extension_id));
  handleExceptionEnd
end;

procedure  RequestContext_GetMediaRouter(const TObj: ICefRequestContext; const callback: ICefCompletionCallback; var Result: ICefMediaRouter);  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;


exports
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
    //RequestContext_GetCookieManagerProc,
    RequestContext_RegisterSchemeHandlerFactory,
    RequestContext_ClearSchemeHandlerFactories,
    RequestContext_ClearCertificateExceptions,
    RequestContext_ClearHttpAuthCredentials,
    RequestContext_CloseAllConnections,
    RequestContext_ResolveHost,
    RequestContext_LoadExtension,
    RequestContext_DidLoadExtension,
    RequestContext_HasExtension,
    RequestContext_GetExtensions,
    RequestContext_GetExtension,
    RequestContext_GetMediaRouter
;