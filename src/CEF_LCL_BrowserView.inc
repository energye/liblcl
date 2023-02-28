//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBrowserView_Browser(const TObj: ICefBrowserView; out Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBrowser();
  handleExceptionEnd
end;

procedure CefBrowserView_ChromeToolbar(const TObj: ICefBrowserView; out Result: ICefView); extdecl;
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
    CefBrowserView_Browser,
    CefBrowserView_ChromeToolbar,
    CefBrowserView_SetPreferAccelerators
;
