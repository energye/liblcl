//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBrowserViewRef_Create(const client: ICefClient; const url: PChar; var borwserSettings: PMCefBrowserSettings; const extra_info: ICefDictionaryValue; const request_context: ICefRequestContext; const delegate: ICefBrowserViewDelegate; out Result: ICefBrowserView); extdecl;
var
  TempBrowserSettings: TCefBrowserSettings;
begin
  handleExceptionBegin
  TempBrowserSettings := GoBrowserSettingsToCefBrowserSettings(borwserSettings);
  Result := TCefBrowserViewRef.CreateBrowserView(client, PCharToUStr(url), TempBrowserSettings, extra_info, request_context, delegate);
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

function CefBrowserView_RuntimeStyle(const TObj: ICefBrowserView): TCefRuntimeStyle; extdecl;
begin
  handleExceptionBegin
  Result := TObj.RuntimeStyle;
  handleExceptionEnd
end;

exports
  CefBrowserViewRef_Create,
  CefBrowserViewRef_GetForBrowser,
  CefBrowserView_Browser,
  CefBrowserView_ChromeToolbar,
  CefBrowserView_SetPreferAccelerators,
  CefBrowserView_RuntimeStyle;
