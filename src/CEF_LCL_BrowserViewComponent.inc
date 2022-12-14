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
function CEFBrowserViewComponent_CreateBrowserView(TObj: TCEFBrowserViewComponent; client: ICefClient; url: PChar; PRequestContextSettings: PRCefRequestContextSettings; PBorwserSettings: PRCefBrowserSettings; argsLen: integer; const dataBytesPtr: array of Byte; dataBytesLen: integer): LongBool; extdecl;
var
  tempDataBytes: array of Byte;
{$else}
function CEFBrowserViewComponent_CreateBrowserView(TObj: TCEFBrowserViewComponent; client: ICefClient; url: PChar; PRequestContextSettings: PRCefRequestContextSettings; PBorwserSettings: PRCefBrowserSettings; argsLen: integer; const dataBytesPtr: array of Byte): LongBool; stdcall;
var
{$endif}
  request_context: ICefRequestContext;
  requestContextSettings: PCefRequestContextSettings;
  settings: TCefBrowserSettings;
  extra_info: ICefDictionaryValue;
  dictValue: TDictValueList;
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
  settings.chrome_status_bubble := TCefState(PBorwserSettings^.chrome_status_bubble) ;

  //extra_info
  if argsLen > 0 then
  begin
    dictValue := TDictValueList.Create;
    {$ifdef DARWIN}
    try
      SetLength(tempDataBytes, dataBytesLen);
      Move(dataBytesPtr[0], tempDataBytes[0], dataBytesLen+1);
      dictValue.UnPackage(tempDataBytes);
      extra_info := dictValue.GetDictValue();
      Result := TObj.CreateBrowserView(client, PCharToUStr(url), settings, extra_info, request_context);
    finally
      SetLength(tempDataBytes, 0);
    end;
    {$else}
    dictValue.UnPackage(dataBytesPtr);
    extra_info := dictValue.GetDictValue();
    Result := TObj.CreateBrowserView(client, PCharToUStr(url), settings, extra_info, request_context);
    {$endif}
  end;
  handleExceptionEnd
end;

function CEFBrowserViewComponent_GetForBrowser(TObj: TCEFBrowserViewComponent; const browserId: Integer): LongBool; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser <> nil then
  begin
    Result := TObj.GetForBrowser(browser);
  end;
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
function CEFBrowserViewComponent_Browser(TObj: TCEFBrowserViewComponent):Integer ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Browser.Identifier;
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

