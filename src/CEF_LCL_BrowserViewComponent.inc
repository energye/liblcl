//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFBrowserViewComponent_Create(const AOwner: TComponent; var Result: TCEFBrowserViewComponent) ; extdecl;
begin
  handleExceptionBegin
  Result := TCEFBrowserViewComponent.Create(AOwner);
  handleExceptionEnd
end;

function CEFBrowserViewComponent_CreateBrowserView(const TObj: TCEFBrowserViewComponent; client: ICefClient; PUrl: PChar; PRequestContextSettings: PRCefRequestContextSettings; PBorwserSettings: PRCefBrowserSettings;
  const extra_info: ICefDictionaryValue): LongBool; extdecl;
var
  request_context: ICefRequestContext;
  requestContextSettings: PCefRequestContextSettings;
  settings: TCefBrowserSettings;
begin
  handleExceptionBegin
  //ICefRequestContext
  requestContextSettings := new(PCefRequestContextSettings);
  requestContextSettings^.size := NativeUInt(PRequestContextSettings^.size);
  requestContextSettings^.cache_path := CefString(PCharToUStr(PRequestContextSettings^.cachePath));
  requestContextSettings^.persist_session_cookies := Integer(PRequestContextSettings^.persistSessionCookies);
  requestContextSettings^.persist_user_preferences := Integer(PRequestContextSettings^.persistUserPreferences);
  requestContextSettings^.accept_language_list := CefString(PCharToUStr(PRequestContextSettings^.acceptLanguageList));
  requestContextSettings^.cookieable_schemes_list := CefString(PCharToUStr(PRequestContextSettings^.cookieableSchemesList));
  requestContextSettings^.cookieable_schemes_exclude_defaults := Integer(PRequestContextSettings^.cookieableSchemesExcludeDefaults);
  request_context := TCefRequestContextRef.New(requestContextSettings);

  //TCefBrowserSettings
  settings.size := NativeUInt(PBorwserSettings^.size);
  settings.windowless_frame_rate := Integer(PBorwserSettings^.windowless_frame_rate);
  settings.standard_font_family := CefString(PCharToUStr(PBorwserSettings^.standard_font_family));
  settings.fixed_font_family := CefString(PCharToUStr(PBorwserSettings^.fixed_font_family));
  settings.serif_font_family := CefString(PCharToUStr(PBorwserSettings^.serif_font_family));
  settings.sans_serif_font_family := CefString(PCharToUStr(PBorwserSettings^.sans_serif_font_family));
  settings.cursive_font_family := CefString(PCharToUStr(PBorwserSettings^.cursive_font_family));
  settings.fantasy_font_family := CefString(PCharToUStr(PBorwserSettings^.fantasy_font_family));
  settings.default_font_size := Integer(PBorwserSettings^.default_font_size);
  settings.default_fixed_font_size := Integer(PBorwserSettings^.default_fixed_font_size);
  settings.minimum_font_size := Integer(PBorwserSettings^.minimum_font_size);
  settings.minimum_logical_font_size := Integer(PBorwserSettings^.minimum_logical_font_size);
  settings.default_encoding := CefString(PCharToUStr(PBorwserSettings^.default_encoding));
  settings.remote_fonts := TCefState(PBorwserSettings^.remote_fonts);
  settings.javascript := TCefState(PBorwserSettings^.javascript);
  settings.javascript_close_windows := TCefState(PBorwserSettings^.javascript_close_windows);
  settings.javascript_access_clipboard := TCefState(PBorwserSettings^.javascript_access_clipboard) ;
  settings.javascript_dom_paste := TCefState(PBorwserSettings^.javascript_dom_paste) ;
  settings.image_loading := TCefState(PBorwserSettings^.image_loading) ;
  settings.image_shrink_standalone_to_fit := TCefState(PBorwserSettings^.image_shrink_standalone_to_fit) ;
  settings.text_area_resize := TCefState(PBorwserSettings^.text_area_resize) ;
  settings.tab_to_links := TCefState(PBorwserSettings^.tab_to_links) ;
  settings.local_storage := TCefState(PBorwserSettings^.local_storage) ;
  settings.databases := TCefState(PBorwserSettings^.databases) ;
  settings.webgl := TCefState(PBorwserSettings^.webgl) ;
  settings.background_color := TCefColor(PBorwserSettings^.background_color) ;
  settings.accept_language_list := CefString(PCharToUStr(PBorwserSettings^.accept_language_list)) ;

  Result := TObj.CreateBrowserView(client, PCharToUStr(PUrl), settings, extra_info, request_context);
  handleExceptionEnd
end;

function CEFBrowserViewComponent_GetForBrowser(const TObj: TCEFBrowserViewComponent; const browser: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetForBrowser(browser);
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_SetPreferAccelerators(const TObj: TCEFBrowserViewComponent; prefer_accelerators: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SetPreferAccelerators(prefer_accelerators);
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_RequestFocus(const TObj: TCEFBrowserViewComponent); extdecl;
begin
  handleExceptionBegin
  TObj.RequestFocus;
  handleExceptionEnd
end;

//property
procedure CEFBrowserViewComponent_Browser(const TObj: TCEFBrowserViewComponent; out Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Browser;
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_BrowserView(const TObj: TCEFBrowserViewComponent; out Result: ICefBrowserView) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.BrowserView;
  handleExceptionEnd
end;

//event
procedure CEFBrowserViewComponent_SetOnBrowserCreated(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnBrowserCreated}
  {$DEFINE EventName := OnBrowserCreated}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnBrowserDestroyed(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnBrowserDestroyed}
  {$DEFINE EventName := OnBrowserDestroyed}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetDelegateForPopupBrowserView(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetDelegateForPopupBrowserView}
  {$DEFINE EventName := OnGetDelegateForPopupBrowserView}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnPopupBrowserViewCreated(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnPopupBrowserViewCreated}
  {$DEFINE EventName := OnPopupBrowserViewCreated}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetChromeToolbarType(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetChromeToolbarType}
  {$DEFINE EventName := OnGetChromeToolbarType}
  EventMethodCode
end;


exports
  CEFBrowserViewComponent_Create,
  CEFBrowserViewComponent_CreateBrowserView,
  CEFBrowserViewComponent_GetForBrowser,
  CEFBrowserViewComponent_SetPreferAccelerators,
  CEFBrowserViewComponent_RequestFocus,
  CEFBrowserViewComponent_Browser,
  CEFBrowserViewComponent_BrowserView,
  CEFBrowserViewComponent_SetOnBrowserCreated,
  CEFBrowserViewComponent_SetOnBrowserDestroyed,
  CEFBrowserViewComponent_SetOnGetDelegateForPopupBrowserView,
  CEFBrowserViewComponent_SetOnPopupBrowserViewCreated,
  CEFBrowserViewComponent_SetOnGetChromeToolbarType;
