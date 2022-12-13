//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//function
function CEFBrowserViewComponent_Create(AOwner: TComponent):TCEFBrowserViewComponent ; extdecl;
begin
  handleExceptionBegin
  Result := TCEFBrowserViewComponent.Create(AOwner);
  handleExceptionEnd
end;

{$ifdef DARWIN}
function CEFBrowserViewComponent_CreateBrowserView(TObj: TCEFBrowserViewComponent; const client: ICefClient; const url: PChar; const settings: PRCefRequestContextSettings; len: integer; const arguments: array of Byte; argumentsLength: integer): LongBool; extdecl;
var
  args: array of Byte;
{$else}
function CEFBrowserViewComponent_CreateBrowserView(TObj: TCEFBrowserViewComponent; const client: ICefClient; const url: PChar; const settings: PRCefRequestContextSettings; len: integer; const arguments: array of Byte): LongBool; stdcall;
var
{$endif}
  request_context: ICefRequestContext;
  requestContextSettings: PCefRequestContextSettings;
  extra_info: ICefDictionaryValue;
begin
  handleExceptionBegin
  requestContextSettings := new(PCefRequestContextSettings);
  requestContextSettings^.size := NativeUInt(settings^.size);
  requestContextSettings^.cache_path := CefString(PCharToUStr(settings^.cachePath));
  requestContextSettings^.persist_session_cookies := Integer(settings^.persistSessionCookies);
  requestContextSettings^.persist_user_preferences := Integer(settings^.persistUserPreferences);
  requestContextSettings^.accept_language_list := CefString(PCharToUStr(settings^.acceptLanguageList));
  requestContextSettings^.cookieable_schemes_list := CefString(PCharToUStr(settings^.cookieableSchemesList));
  requestContextSettings^.cookieable_schemes_exclude_defaults := Integer(settings^.cookieableSchemesExcludeDefaults);
  request_context := TCefRequestContextRef.New(requestContextSettings);
  //const client: ICefClient; const url: ustring; const settings: TCefBrowserSettings; const extra_info: ICefDictionaryValue; const request_context: ICefRequestContext
  Result := TObj.CreateBrowserView(client, PCharToUStr(url), settings, extra_info, request_context);
  handleExceptionEnd
end;

function CEFBrowserViewComponent_GetForBrowser(TObj: TCEFBrowserViewComponent; const browser: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetForBrowser(browser);
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_SetPreferAccelerators(TObj: TCEFBrowserViewComponent; prefer_accelerators: boolean); extdecl;
begin
  handleExceptionBegin
  TObj.SetPreferAccelerators(prefer_accelerators);
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_RequestFocus(TObj: TCEFBrowserViewComponent); extdecl;
begin
  handleExceptionBegin
  TObj.RequestFocus;
  handleExceptionEnd
end;

//property
function CEFBrowserViewComponent_Browser(TObj: TCEFBrowserViewComponent):ICefBrowser ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Browser;
  handleExceptionEnd
end;

function CEFBrowserViewComponent_BrowserView(TObj: TCEFBrowserViewComponent):ICefBrowserView ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.BrowserView;
  handleExceptionEnd
end;

//event
procedure CEFBrowserViewComponent_SetOnBrowserCreated(AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnBrowserCreated}
  {$DEFINE EventName := OnBrowserCreated}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnBrowserDestroyed(AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnBrowserDestroyed}
  {$DEFINE EventName := OnBrowserDestroyed}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetDelegateForPopupBrowserView(AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetDelegateForPopupBrowserView}
  {$DEFINE EventName := OnGetDelegateForPopupBrowserView}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnPopupBrowserViewCreated(AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnPopupBrowserViewCreated}
  {$DEFINE EventName := OnPopupBrowserViewCreated}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetChromeToolbarType(AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetChromeToolbarType}
  {$DEFINE EventName := OnGetChromeToolbarType}
  EventMethodCode
end;


exports
//function
  CEFBrowserViewComponent_Create,
  CEFBrowserViewComponent_CreateBrowserView,
  CEFBrowserViewComponent_GetForBrowser,
  CEFBrowserViewComponent_SetPreferAccelerators,
  CEFBrowserViewComponent_RequestFocus,
//property
  CEFBrowserViewComponent_Browser,
  CEFBrowserViewComponent_BrowserView,
//event
  CEFBrowserViewComponent_SetOnBrowserCreated,
  CEFBrowserViewComponent_SetOnBrowserDestroyed,
  CEFBrowserViewComponent_SetOnGetDelegateForPopupBrowserView,
  CEFBrowserViewComponent_SetOnPopupBrowserViewCreated,
  CEFBrowserViewComponent_SetOnGetChromeToolbarType
;

