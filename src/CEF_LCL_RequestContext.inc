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

function  RequestContext_GetHandler(const TObj: ICefRequestContext): ICefRequestContextHandler;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_GetCachePath(const TObj: ICefRequestContext): PChar;  extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetCachePath));
  handleExceptionEnd
end;

function  RequestContext_GetCookieManager(const TObj: ICefRequestContext; const callback: ICefCompletionCallback): ICefCookieManager;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_GetCookieManagerProc(const TObj: ICefRequestContext; const callback: TCefCompletionCallbackProc): ICefCookieManager;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_RegisterSchemeHandlerFactory(const TObj: ICefRequestContext; const schemeName, domainName: PChar; const factory: ICefSchemeHandlerFactory): LongBool;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_ClearSchemeHandlerFactories(const TObj: ICefRequestContext): LongBool;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure RequestContext_ClearCertificateExceptions(const TObj: ICefRequestContext; const callback: ICefCompletionCallback);  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure RequestContext_ClearHttpAuthCredentials(const TObj: ICefRequestContext; const callback: ICefCompletionCallback);  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure RequestContext_CloseAllConnections(const TObj: ICefRequestContext; const callback: ICefCompletionCallback);  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure RequestContext_ResolveHost(const TObj: ICefRequestContext; const origin: ustring; const callback: ICefResolveCallback);  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure RequestContext_LoadExtension(const TObj: ICefRequestContext; const root_directory: ustring; const manifest: ICefDictionaryValue; const handler: ICefExtensionHandler);  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_DidLoadExtension(const TObj: ICefRequestContext; const extension_id: PChar): LongBool;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_HasExtension(const TObj: ICefRequestContext; const extension_id: PChar): LongBool;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_GetExtensions(const TObj: ICefRequestContext; const extension_ids: TStringList): LongBool;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_GetExtension(const TObj: ICefRequestContext; const extension_id: PChar): ICefExtension;  extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function  RequestContext_GetMediaRouter(const TObj: ICefRequestContext; const callback: ICefCompletionCallback): ICefMediaRouter;  extdecl;
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
    RequestContext_GetCookieManagerProc,
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
