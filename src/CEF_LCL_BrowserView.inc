//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBrowserViewRef_Create(const client: ICefClient; const url: PChar; const PBorwserSettings: PRCefBrowserSettings; const extra_info: ICefDictionaryValue; const request_context: ICefRequestContext; const delegate: ICefBrowserViewDelegate; out Result: ICefBrowserView); extdecl;
var
  settings: TCefBrowserSettings;
begin
  handleExceptionBegin

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
  settings.chrome_status_bubble := TCefState(PBorwserSettings^.chrome_status_bubble) ;

  Result := TCefBrowserViewRef.CreateBrowserView(client, PCharToUStr(url), settings, extra_info, request_context, delegate);
  handleExceptionEnd
end;

procedure CefBrowserViewRef_GetForBrowser(const browser: ICefBrowser; out Result: ICefBrowserView); extdecl;
begin
  handleExceptionBegin
  Result := TCefBrowserViewRef.GetForBrowser(browser);
  handleExceptionEnd
end;

procedure CefBrowserView_Browser(const TObj: ICefBrowserView; var Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBrowser();
  handleExceptionEnd
end;

procedure CefBrowserView_ChromeToolbar(const TObj: ICefBrowserView; var Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetChromeToolbar();
  handleExceptionEnd
end;

procedure CefBrowserView_SetPreferAccelerators(const TObj: ICefBrowserView; prefer_accelerators: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SetPreferAccelerators(prefer_accelerators);
  handleExceptionEnd
end;

exports
  CefBrowserViewRef_Create,
  CefBrowserViewRef_GetForBrowser,
  CefBrowserView_Browser,
  CefBrowserView_ChromeToolbar,
  CefBrowserView_SetPreferAccelerators;
