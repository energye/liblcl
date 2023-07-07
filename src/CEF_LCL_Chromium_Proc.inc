//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFChromium_Free(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Free();
  handleExceptionEnd
end;

function CEFChromium_GetHashCode(const AObj: TChromium):Integer ; extdecl;
begin
  {$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result := AObj.GetHashCode();
  handleExceptionEnd
end;

function CEFChromium_ClassName(const AObj: TChromium):PChar ; extdecl;
begin
  {$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result := ToPChar(AObj.ClassName());
  handleExceptionEnd
end;

function CEFChromium_Equals(const AObj: TChromium; Obj: TObject): LongBool; extdecl;
begin
  {$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result := AObj.Equals(Obj);
  handleExceptionEnd
end;

function CEFChromium_ClassType(const AObj: TChromium): TClass; extdecl;
begin
  {$ifdef UsehandleException}Result := TClass(nil);{$endif}
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

function CEFChromium_InstanceSize(const AObj: TChromium): Integer; extdecl;
begin
  {$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result := AObj.InstanceSize;
  handleExceptionEnd
end;

function CEFChromium_InheritsFrom(const AObj: TChromium; AClass: TClass): LongBool; extdecl;
begin
  {$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

function CEFChromium_ToString(const AObj: TChromium): PChar; extdecl;
begin
  {$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

function CEFChromium_Create(const AOwner: TComponent): TChromium; extdecl;
begin
  handleExceptionBegin
  Result := TChromium.Create(AOwner);
  handleExceptionEnd
end;

procedure CEFChromium_Browser(const AObj: TChromium; var Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := AObj.Browser;
  handleExceptionEnd
end;

procedure CEFChromium_BrowserById(const AObj: TChromium; id: integer; var Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserById[id];
  if Result = nil then
  begin
     exit;
  end;
  handleExceptionEnd
end;

function CEFChromium_BrowserIdByIndex(const AObj: TChromium; index: integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserIdByIndex[index];
  handleExceptionEnd
end;

function CEFChromium_BrowserCount(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserCount;
  handleExceptionEnd
end;

function CEFChromium_BrowserId(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserId;
  handleExceptionEnd
end;

procedure CEFChromium_SetDefaultURL(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultUrl:= PCharToUStr(AURL);
  handleExceptionEnd
end;

procedure CEFChromium_SetMultiBrowserMode(const AObj: TChromium; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.MultiBrowserMode := AValue;
  handleExceptionEnd
end;

procedure CEFChromium_LoadURL(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadURL(PCharToUStr(AURL));
  handleExceptionEnd
end;

procedure CEFChromium_LoadString(const AObj: TChromium; AHTML: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadString(PCharToUStr(AHTML));
  handleExceptionEnd
end;

procedure CEFChromium_StartDownload(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.StartDownload(PCharToUStr(AURL));
  handleExceptionEnd
end;

procedure CEFChromium_DownloadImage(const AObj: TChromium; const imageUrl: PChar; isFavicon: LongBool; maxImageSize: integer; bypassCache: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DownloadImage(PCharToUStr(imageUrl), isFavicon, maxImageSize, bypassCache);
  handleExceptionEnd
end;

procedure CEFChromium_Reload(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Reload;
  handleExceptionEnd
end;

procedure CEFChromium_ReloadIgnoreCache(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ReloadIgnoreCache;
  handleExceptionEnd
end;

procedure CEFChromium_StopLoad(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.StopLoad;
  handleExceptionEnd
end;

procedure CEFChromium_ResetZoomLevel(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ResetZoomLevel;
  handleExceptionEnd
end;

procedure CEFChromium_CloseAllBrowsers(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.CloseAllBrowsers;
  handleExceptionEnd
end;

function CEFChromium_CreateBrowser(const AObj: TChromium; window:{$IFDEF WINDOWS} TCEFWindowParent{$ELSE} TCEFLinkedWindowParent {$ENDIF}; const windowName: PChar; context: ICefRequestContext; const extraInfo: ICefDictionaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  if window = nil then
  begin
    Result := AObj.CreateBrowser(nil, PCharToUStr(windowName), context, extraInfo);
  end
  else
  begin
    Result := AObj.CreateBrowser(window.Handle, window.BoundsRect, PCharToUStr(windowName), context, extraInfo);
  end;
  handleExceptionEnd
end;

function CEFChromium_CreateBrowserByWindow(const AObj: TChromium; window: TCEFWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  if window = nil then
    Result := AObj.CreateBrowser(nil, '')
  else
    Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

function CEFChromium_CreateBrowserByLinkedWindow(const AObj: TChromium; window: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  if window = nil then
    Result := AObj.CreateBrowser(nil, '')
  else
    Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

function CEFChromium_CreateBrowserByBrowserViewComponent(const AObj: TChromium; PHomePage: PChar; BrowserViewComponent: TCEFBrowserViewComponent; const aContext : ICefRequestContext; const aExtraInfo : ICefDictionaryValue): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(PCharToUStr(PHomePage), BrowserViewComponent, aContext, aExtraInfo);
  handleExceptionEnd
end;

function CEFChromium_Initialized(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Initialized;
  handleExceptionEnd
end;

function CEFChromium_IsSameBrowser(const AObj: TChromium; const that: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSameBrowser(that);
  handleExceptionEnd
end;

procedure CEFChromium_PrintToPDF(const AObj: TChromium; FilePath: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.PrintToPDF(PCharToUStr(FilePath), '', AObj.Browser.MainFrame.GetUrl);
  handleExceptionEnd
end;

procedure CEFChromium_Print(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Print;
  handleExceptionEnd
end;

procedure CEFChromium_BrowserZoom(const AObj: TChromium; Zoom: integer); extdecl;
begin
  handleExceptionBegin
  if Zoom = 0 then
   AObj.ResetZoomLevel
  else if Zoom = 1 then
   AObj.IncZoomStep
  else if Zoom = 2 then
   AObj.DecZoomStep;
  handleExceptionEnd
end;

procedure CEFChromium_GoBackForward(const AObj: TChromium; BackForward: integer); extdecl;
begin
  handleExceptionBegin
  if BackForward = 0 then
  AObj.GoBack
  else if BackForward = 1 then
  AObj.GoForward;
  handleExceptionEnd
end;

procedure CEFChromium_NotifyMoveOrResizeStarted(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

procedure CEFChromium_Invalidate(const AObj: TChromium; type_: Integer); extdecl;
begin
  handleExceptionBegin
  // TCefPaintElementType
  AObj.Invalidate(TCefPaintElementType(type_));
  handleExceptionEnd
end;

procedure CEFChromium_CloseBrowser(const AObj: TChromium; forceClose: LongBool); extdecl;
begin
  handleExceptionBegin
   try
     AObj.CloseBrowser(forceClose);
   except
     on E: Exception do
       CallException(E);
   end;
  handleExceptionEnd
end;

procedure CEFChromium_ExecuteJavaScript(const AObj: TChromium; aCode, aScriptURL : PChar; startLine: integer = 0); extdecl;
var
  code, scriptURL : ustring;
begin
  handleExceptionBegin
  code := PCharToUStr(aCode);
  scriptURL := PCharToUStr(aScriptURL);
  if scriptURL = '' then
  begin
    scriptURL := 'about:blank';
  end;
  AObj.ExecuteJavaScript(code, scriptURL, startLine);
  handleExceptionEnd
end;

procedure CEFChromium_ShowDevTools(const AObj: TChromium); extdecl;
var
  point: TPoint;
begin
  handleExceptionBegin
  point.x := 100;
  point.y := 100;
  AObj.ShowDevTools(point, nil);
  handleExceptionEnd
end;

procedure CEFChromium_ShowDevToolsByWindowParent(const AObj: TChromium; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}); extdecl;
var
  point: TPoint;
begin
  handleExceptionBegin
  point.x := 0;
  point.y := 0;
  AObj.ShowDevTools(point, windowParent);
  handleExceptionEnd
end;

procedure CEFChromium_CloseDevTools(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.CloseDevTools(nil);
  handleExceptionEnd
end;

procedure CEFChromium_CloseDevToolsByWindowParent(const AObj: TChromium; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}); extdecl;
begin
  handleExceptionBegin
  AObj.CloseDevTools(windowParent);
  handleExceptionEnd
end;

//cookie begin
procedure CEFChromium_VisitAllCookies(const AObj: TChromium; aID: integer); extdecl;
begin
  handleExceptionBegin
  AObj.VisitAllCookies(aID);
  handleExceptionEnd
end;

procedure CEFChromium_VisitURLCookies(const AObj: TChromium; URL: PChar; includeHttpOnly: LongBool; aID: integer); extdecl;
begin
  handleExceptionBegin
  AObj.VisitURLCookies(PCharToUStr(URL), includeHttpOnly, aID);
  handleExceptionEnd
end;

procedure CEFChromium_SetCookie(const AObj: TChromium; CefCookie: PRCefCookie); extdecl;
var
  url, name, value, domain, path: ustring;
  secure, httponly, hasExpires: LongBool;
  creation, lastAccess, expires: double;
  sameSite: TCefCookieSameSite;
  priority: TCefCookiePriority;
  aSetImmediately: LongBool;
  aID: integer;
begin
  handleExceptionBegin
  url := PCharToUStr(CefCookie.url);
  name := PCharToUStr(CefCookie.name);
  value := PCharToUStr(CefCookie.value);
  domain := PCharToUStr(CefCookie.domain);
  path := PCharToUStr(CefCookie.path);
  secure := LongBool(PLongBool(CefCookie.secure));
  httponly := LongBool(PLongBool(CefCookie.httponly));
  hasExpires := LongBool(PLongBool(CefCookie.hasExpires));
  creation := Double(PDouble(CefCookie.creation)^);
  lastAccess := Double(PDouble(CefCookie.lastAccess)^);
  expires := Double(PDouble(CefCookie.expires)^);
  sameSite := TCefCookieSameSite(Integer(CefCookie.sameSite));
  priority := TCefCookiePriority(Integer(CefCookie.priority));
  aSetImmediately := LongBool(PLongBool(CefCookie.setImmediately));
  aID := Integer(CefCookie.aID);
  AObj.SetCookie(url, name, value, domain, path, secure, httponly, hasExpires, creation, lastAccess, expires, sameSite, priority, aSetImmediately, aID);
  CefCookie := nil;
  handleExceptionEnd
end;

function CEFChromium_FlushCookieStore(const AObj: TChromium; flushImmediately: LongBool):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.FlushCookieStore(flushImmediately);
  handleExceptionEnd
end;

procedure CEFChromium_DeleteCookies(const AObj: TChromium; PUrl: PChar; PCookieName: PChar; DeleteImmediately: LongBool); extdecl;
var
  url: ustring;
  cookieName: ustring;
begin
  handleExceptionBegin
  url := PCharToUStr(PUrl);
  cookieName := PCharToUStr(PCookieName);
  AObj.DeleteCookies(url, cookieName, DeleteImmediately);
  handleExceptionEnd
end;

//cookie end

procedure CEFChromium_SetProxy(const AObj: TChromium; const proxy: PRChromiumProxy); extdecl;
begin
  handleExceptionBegin
  AObj.ProxyType := Integer(proxy.ProxyType);
  AObj.ProxyScheme := TCefProxyScheme(Integer(proxy.ProxyScheme));
  AObj.ProxyServer := PCharToUStr(proxy.ProxyServer);
  AObj.ProxyPort := Integer(proxy.ProxyPort);
  AObj.ProxyUsername := PCharToUStr(proxy.ProxyUsername);
  AObj.ProxyPassword := PCharToUStr(proxy.ProxyPassword);
  AObj.ProxyScriptURL := PCharToUStr(proxy.ProxyScriptURL);
  AObj.ProxyByPassList := PCharToUStr(proxy.ProxyByPassList);
  AObj.MaxConnectionsPerProxy := Integer(proxy.MaxConnectionsPerProxy);
  handleExceptionEnd
end;

procedure CEFChromium_UpdatePreferences(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.UpdatePreferences;
  handleExceptionEnd
end;

procedure CEFChromium_ExecuteDevToolsMethod(const AObj: TChromium; messageId: integer; PMethodName: PChar; const dictionaryValue: ICefDictionaryValue); extdecl;
begin
  handleExceptionBegin
  AObj.ExecuteDevToolsMethod(messageId, PCharToUStr(PMethodName), dictionaryValue);
  handleExceptionEnd
end;

function CEFChromium_CreateClientHandler(const AObj: TChromium; var client: ICefClient; alsOSR: LongBool): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.CreateClientHandler(client, alsOSR);
  handleExceptionEnd
end;

procedure CEFChromium_SetFocus(const AObj: TChromium; Value: LongBool);extdecl;
begin
  handleExceptionBegin
  AObj.SetFocus(Value);
  handleExceptionEnd
end;

procedure CEFChromium_SendExternalBeginFrame(const TObj: TChromium); extdecl;
begin
  handleExceptionBegin
  TObj.SendExternalBeginFrame();
  handleExceptionEnd
end;

procedure CEFChromium_SendKeyEvent(const TObj: TChromium; const event: PCefKeyEvent); extdecl;
begin
  handleExceptionBegin
  TObj.SendKeyEvent(event);
  handleExceptionEnd
end;

procedure CEFChromium_SendMouseClickEvent(const TObj: TChromium; const event: PCefMouseEvent; type_: integer; mouseUp: LongBool; clickCount: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseClickEvent(event, TCefMouseButtonType(type_), mouseUp, clickCount);
  handleExceptionEnd
end;

procedure CEFChromium_SendMouseMoveEvent(const TObj: TChromium; const event: PCefMouseEvent; mouseLeave: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseMoveEvent(event, mouseLeave);
  handleExceptionEnd
end;

procedure CEFChromium_SendMouseWheelEvent(const TObj: TChromium; const event: PCefMouseEvent; deltaX, deltaY: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseWheelEvent(event, deltaX, deltaY);
  handleExceptionEnd
end;

procedure CEFChromium_SendTouchEvent(const TObj: TChromium; const event: PCefTouchEvent); extdecl;
begin
  handleExceptionBegin
  TObj.SendTouchEvent(event);
  handleExceptionEnd
end;

procedure CEFChromium_SendCaptureLostEvent(const AObj: TChromium);extdecl;
begin
  handleExceptionBegin
  AObj.SendCaptureLostEvent;
  handleExceptionEnd
end;

function CEFChromium_FrameIsFocused(const AObj: TChromium): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.FrameIsFocused;
  handleExceptionEnd
end;

function CEFChromium_TryCloseBrowser(const AObj: TChromium): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.TryCloseBrowser;
  handleExceptionEnd
end;

function CEFChromium_BrowserHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= AObj.BrowserHandle;
  {$else}
  Result := 0;
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_WidgetHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= AObj.WidgetHandle;
  {$else}
  Result := 0;
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_RenderHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= AObj.RenderHandle;
  {$else}
  Result := 0;
  {$endif}
  handleExceptionEnd
end;

//CustomHeader
procedure CEFChromium_SetCustomHeader(const AObj: TChromium; PCustomHeader: PRCustomHeader); extdecl;
begin
  handleExceptionBegin
  AObj.CustomHeaderName  := PCharToUStr(PCustomHeader.CustomHeaderName);
  AObj.CustomHeaderValue := PCharToUStr(PCustomHeader.CustomHeaderValue);
  handleExceptionEnd
end;

function CEFChromium_GetCustomHeader(const AObj: TChromium): PRCustomHeader; extdecl;
var
  CustomHeader: PRCustomHeader;
begin
  handleExceptionBegin
  CustomHeader := new(PRCustomHeader);
  CustomHeader.CustomHeaderName := PChar(string(AObj.CustomHeaderName));
  CustomHeader.CustomHeaderValue := PChar(string(AObj.CustomHeaderValue));
  Result := CustomHeader;
  handleExceptionEnd
end;

//JavascriptEnabled
procedure CEFChromium_SetJavascriptEnabled(const AObj: TChromium; EnabledJavascript: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.JavascriptEnabled := EnabledJavascript;//default true
  handleExceptionEnd
end;

function CEFChromium_GetJavascriptEnabled(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.JavascriptEnabled;
  handleExceptionEnd
end;

//WebRTCIPHandlingPolicy
procedure CEFChromium_SetWebRTCIPHandlingPolicy(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = hpDisableNonProxiedUDP
  AObj.WebRTCIPHandlingPolicy := TCefWebRTCHandlingPolicy(value); //defalt hpDefault
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCIPHandlingPolicy(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.WebRTCIPHandlingPolicy);
  handleExceptionEnd
end;

//WebRTCMultipleRoutes
procedure CEFChromium_SetWebRTCMultipleRoutes(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = STATE_DISABLED
  AObj.WebRTCMultipleRoutes := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCMultipleRoutes(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.WebRTCMultipleRoutes);
  handleExceptionEnd
end;

//WebRTCNonproxiedUDP
procedure CEFChromium_SetWebRTCNonproxiedUDP(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = STATE_DISABLED
  AObj.WebRTCNonproxiedUDP := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCNonproxiedUDP(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.WebRTCNonproxiedUDP);
  handleExceptionEnd
end;

//BatterySaverModeState
procedure CEFChromium_SetBatterySaverModeState(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFChromium_GetBatterySaverModeState(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

//HighEfficiencyMode
procedure CEFChromium_SetHighEfficiencyMode(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFChromium_GetHighEfficiencyMode(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

//LoadImagesAutomatically
procedure CEFChromium_SetLoadImagesAutomatically(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.LoadImagesAutomatically := value; //defalt true
  handleExceptionEnd
end;

function CEFChromium_GetLoadImagesAutomatically(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.LoadImagesAutomatically;
  handleExceptionEnd
end;

//QuicAllowed
procedure CEFChromium_SetQuicAllowed(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.QuicAllowed := value; //defalt true
  handleExceptionEnd
end;

function CEFChromium_GetQuicAllowed(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.QuicAllowed;
  handleExceptionEnd
end;

//Offline
procedure CEFChromium_SetOffline(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Offline := value; //defalt False
  handleExceptionEnd
end;

function CEFChromium_GetOffline(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Offline;
  handleExceptionEnd
end;

//DefaultWindowInfoExStyle
procedure CEFChromium_SetDefaultWindowInfoExStyle(const AObj: TChromium; value: DWORD); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultWindowInfoExStyle := value; //defalt 0
  handleExceptionEnd
end;

function CEFChromium_GetDefaultWindowInfoExStyle(const AObj: TChromium): DWORD; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DefaultWindowInfoExStyle;
  handleExceptionEnd
end;

//Block3rdPartyCookies
procedure CEFChromium_SetBlock3rdPartyCookies(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Block3rdPartyCookies := value; //defalt False
  handleExceptionEnd
end;

function CEFChromium_GetBlock3rdPartyCookies(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Block3rdPartyCookies;
  handleExceptionEnd
end;

//AcceptCookies
procedure CEFChromium_SetAcceptCookies(const AObj: TChromium; value: integer); extdecl;
begin
  handleExceptionBegin
  AObj.AcceptCookies := TCefCookiePref(value); //defalt cpAllow
  handleExceptionEnd
end;

function CEFChromium_GetAcceptCookies(const AObj: TChromium): integer; extdecl;
begin
  handleExceptionBegin
  Result := integer(AObj.AcceptCookies);
  handleExceptionEnd
end;

//AcceptLanguageList
procedure CEFChromium_SetAcceptLanguageList(const AObj: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.AcceptLanguageList := PCharToUStr(value); //defalt ''
  handleExceptionEnd
end;

function CEFChromium_GetAcceptLanguageList(const AObj: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.AcceptLanguageList));
  handleExceptionEnd
end;

//PrintingEnabled
procedure CEFChromium_SetPrintingEnabled(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.PrintingEnabled := value; //defalt True
  handleExceptionEnd
end;

function CEFChromium_GetPrintingEnabled(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.PrintingEnabled;
  handleExceptionEnd
end;

//YouTubeRestrict
procedure CEFChromium_SetYouTubeRestrict(const AObj: TChromium; value: integer); extdecl;
begin
  handleExceptionBegin
  AObj.YouTubeRestrict := value; //defalt YOUTUBE_RESTRICT_OFF
  handleExceptionEnd
end;

function CEFChromium_GetYouTubeRestrict(const AObj: TChromium): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.YouTubeRestrict;
  handleExceptionEnd
end;

procedure CEFChromium_SetSafeSearch(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SafeSearch := value; //defalt False
  handleExceptionEnd
end;

function CEFChromium_GetSafeSearch(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SafeSearch;
  handleExceptionEnd
end;

procedure CEFChromium_SetAudioMuted(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AudioMuted := value; //defalt ?
  handleExceptionEnd
end;

function CEFChromium_GetAudioMuted(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AudioMuted;
  handleExceptionEnd
end;

procedure CEFChromium_SetDragOperations(const AObj: TChromium; value: Cardinal); extdecl;
begin
  handleExceptionBegin
  AObj.DragOperations := value; //default DRAG_OPERATION_NONE
  handleExceptionEnd
end;

function CEFChromium_GetDragOperations(const AObj: TChromium): Cardinal; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DragOperations;
  handleExceptionEnd
end;

function CEFChromium_GetFrameCount(const AObj: TChromium): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.FrameCount;
  handleExceptionEnd
end;

procedure CEFChromium_SetSpellCheckerDicts(const AObj: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SpellCheckerDicts := PCharToUStr(value); //default ''
  handleExceptionEnd
end;

function CEFChromium_GetSpellCheckerDicts(const AObj: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.SpellCheckerDicts));
  handleExceptionEnd
end;

procedure CEFChromium_SetSpellChecking(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SpellChecking := value; //default True
  handleExceptionEnd
end;

function CEFChromium_GetSpellChecking(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SpellChecking;
  handleExceptionEnd
end;

procedure CEFChromium_SetAlwaysOpenPDFExternally(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysOpenPDFExternally(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure CEFChromium_SetAlwaysAuthorizePlugins(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AlwaysAuthorizePlugins := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysAuthorizePlugins(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AlwaysAuthorizePlugins;
  handleExceptionEnd
end;

procedure CEFChromium_SetAllowOutdatedPlugins(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AllowOutdatedPlugins := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAllowOutdatedPlugins(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AllowOutdatedPlugins;
  handleExceptionEnd
end;

procedure CEFChromium_SetSendReferrer(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SendReferrer := value; //default = True
  handleExceptionEnd
end;

function CEFChromium_GetSendReferrer(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SendReferrer;
  handleExceptionEnd
end;

procedure CEFChromium_SetDoNotTrack(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DoNotTrack := value; //default = True
  handleExceptionEnd
end;

function CEFChromium_GetDoNotTrack(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DoNotTrack;
  handleExceptionEnd
end;

procedure CEFChromium_SetZoomStep(const AObj: TChromium; value: byte); extdecl;
begin
  handleExceptionBegin
  AObj.ZoomStep := value; //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

function CEFChromium_GetZoomStep(const AObj: TChromium): byte; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ZoomStep;
  handleExceptionEnd
end;

procedure CEFChromium_SetZoomPct(const AObj: TChromium; value: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ZoomPct := Double(PDouble(value)^); //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

procedure CEFChromium_GetZoomPct(const AObj: TChromium; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ZoomPct;
  handleExceptionEnd
end;

procedure CEFChromium_SetZoomLevel(const AObj: TChromium; value: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ZoomLevel := Double(PDouble(value)^); //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

procedure CEFChromium_GetZoomLevel(const AObj: TChromium; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ZoomLevel;
  handleExceptionEnd
end;

procedure CEFChromium_SetDefaultEncoding(const AObj: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultEncoding := PCharToUStr(value); //default = ''
  handleExceptionEnd
end;

function CEFChromium_GetDefaultEncoding(const AObj: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.DefaultEncoding));
  handleExceptionEnd
end;

procedure CEFChromium_SendProcessMessage(const AObj: TChromium; targetProcess: Integer; const message_: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  handleExceptionEnd
end;

procedure CEFChromium_SendProcessMessageForJSONBytes(const AObj: TChromium; const PName: PChar; targetProcess: Integer; const data: Pointer; dataSize: NativeUInt); extdecl;
var
  message_ : ICefProcessMessage;
begin
  handleExceptionBegin
  message_ := TCefProcessMessageRef.New(PCharToUStr(PName));
  message_.ArgumentList.SetBinary(0, TCefBinaryValueRef.New(data, dataSize));
  AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  message_.ArgumentList.Clear;
  handleExceptionEnd
end;

procedure CEFChromium_CefClient(const AObj: TChromium; var Result: ICefClient); extdecl;
begin
  handleExceptionBegin
  Result := AObj.CefClient;
  handleExceptionEnd
end;

procedure CEFChromium_SendProcessMessageForV8Value(const AObj: ICefFrame; const PName: PChar; targetProcess: Integer; const arguments: ICefv8Value); extdecl;
var
  message_ : ICefProcessMessage;
begin
  handleExceptionBegin
  message_ := TValueConvert.V8ValueToProcessMessage(PCharToUStr(PName), arguments);
  if message_ <> nil then
  begin
    AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
    message_.ArgumentList.Clear;
  end;
  handleExceptionEnd
end;

procedure  CEFChromium_SimulateMouseWheel(const AObj: TChromium; aDeltaX, aDeltaY : integer); extdecl;
begin
  handleExceptionBegin
  AObj.SimulateMouseWheel(aDeltaX, aDeltaY);
  handleExceptionEnd
end;

function  CEFChromium_CloseAllConnections(const AObj: TChromium; aCloseImmediately : LongBool) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CloseAllConnections(aCloseImmediately);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveHTMLByFrameName(const AObj: TChromium; const aFrameName : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveHTML(PCharToUStr(aFrameName));
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveHTMLByFrame(const AObj: TChromium; const aFrame : ICefFrame); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveHTML(aFrame);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveHTMLByFrameIdentifier(const AObj: TChromium; var aFrameIdentifier : int64); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveHTML(aFrameIdentifier);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveTextByFrameName(const AObj: TChromium; const aFrameName : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveText(PCharToUStr(aFrameName));
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveTextByFrame(const AObj: TChromium; const aFrame : ICefFrame); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveText(aFrame);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveTextByFrameIdentifier(const AObj: TChromium; var aFrameIdentifier : int64); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveText(aFrameIdentifier);
  handleExceptionEnd
end;

procedure  CEFChromium_ResolveHost(const AObj: TChromium; const aURL : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.ResolveHost(PCharToUStr(aURL));
  handleExceptionEnd
end;

procedure  CEFChromium_SetUserAgentOverride(const AObj: TChromium; const aUserAgent : PChar; const aAcceptLanguage : PChar; const aPlatform : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetUserAgentOverride(PCharToUStr(aUserAgent), PCharToUStr(aAcceptLanguage), PCharToUStr(aPlatform));
  handleExceptionEnd
end;

procedure  CEFChromium_ClearDataForOrigin(const AObj: TChromium; const aOrigin : PChar; aStorageTypes : Integer); extdecl;
var
  st: TCefClearDataStorageTypes;
begin
  handleExceptionBegin
  st := cdstAll;
  // TCefClearDataStorageTypes = default cdstAll
  if aStorageTypes = 0 then
    st := cdstAppCache
  else if aStorageTypes = 1 then
    st := cdstCookies
  else if aStorageTypes = 2 then
    st := cdstFileSystems
  else if aStorageTypes = 3 then
    st := cdstIndexeddb
  else if aStorageTypes = 4 then
    st := cdstLocalStorage
  else if aStorageTypes = 5 then
    st := cdstShaderCache
  else if aStorageTypes = 6 then
    st := cdstWebsql
  else if aStorageTypes = 7 then
    st := cdstServiceWorkers
  else if aStorageTypes = 8 then
    st := cdstCacheStorage
  else if aStorageTypes = 9 then
    st := cdstAll;
  AObj.ClearDataForOrigin(PCharToUStr(aOrigin), st);
  handleExceptionEnd
end;

procedure  CEFChromium_ClearCache(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClearCache();
  handleExceptionEnd
end;

procedure  CEFChromium_ToggleAudioMuted(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardCopy(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardCopy();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardPaste(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardPaste();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardCut(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardCut();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardUndo(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardUndo();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardRedo(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardRedo();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardDel(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardDel();
  handleExceptionEnd
end;

procedure  CEFChromium_SelectAll(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.SelectAll();
  handleExceptionEnd
end;

procedure  CEFChromium_IncZoomStep(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.IncZoomStep();
  handleExceptionEnd
end;

procedure  CEFChromium_DecZoomStep(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.DecZoomStep();
  handleExceptionEnd
end;

procedure  CEFChromium_IncZoomPct(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.IncZoomPct();
  handleExceptionEnd
end;

procedure  CEFChromium_DecZoomPct(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.DecZoomPct();
  handleExceptionEnd
end;

procedure  CEFChromium_ResetZoomStep(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ResetZoomStep();
  handleExceptionEnd
end;

procedure  CEFChromium_ResetZoomPct(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ResetZoomPct();
  handleExceptionEnd
end;

procedure  CEFChromium_ReadZoom(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ReadZoom();
  handleExceptionEnd
end;

procedure  CEFChromium_WasResized(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.WasResized();
  handleExceptionEnd
end;

procedure  CEFChromium_WasHidden(const AObj: TChromium; hidden: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.WasHidden(hidden);
  handleExceptionEnd
end;

procedure  CEFChromium_NotifyScreenInfoChanged(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyScreenInfoChanged();
  handleExceptionEnd
end;

procedure  CEFChromium_IMESetComposition(const AObj: TChromium; const text: PChar; const replacement_range, selection_range : TCefRange; const PUnderlines : PTCefCompositionUnderlineDynArray; size: Integer); extdecl;
var
  i: integer;
  underlines : TCefCompositionUnderlineDynArray;
begin
  handleExceptionBegin
  try
    SetLength(underlines, size);
    for i := 0 to  size - 1 do
    begin
      underlines[i] := PUnderlines^[i];
    end;
    AObj.IMESetComposition(PChar(text), underlines, @replacement_range, @selection_range);
  finally
    SetLength(underlines, 0);
  end;
  handleExceptionEnd
end;

procedure   CEFChromium_IMECommitText(const AObj: TChromium; const text: PChar; const replacement_range : TCefRange; relative_cursor_pos : integer); extdecl;
begin
  handleExceptionBegin
  AObj.IMECommitText(PChar(text), @replacement_range, relative_cursor_pos);
  handleExceptionEnd
end;

procedure   CEFChromium_IMEFinishComposingText(const AObj: TChromium; keep_selection : boolean); extdecl;
begin
  handleExceptionBegin
  AObj.IMEFinishComposingText(keep_selection);
  handleExceptionEnd
end;

procedure   CEFChromium_IMECancelComposition(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.IMECancelComposition();
  handleExceptionEnd
end;

function   CEFChromium_HasDevTools(const AObj: TChromium):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasDevTools;
  handleExceptionEnd
end;

procedure CEFChromium_InitializeDragAndDrop(const AObj: TChromium; const aDropTargetCtrl : TWinControl);
begin
  handleExceptionBegin
  {$IFDEF MSWINDOWS}
  AObj.InitializeDragAndDrop(aDropTargetCtrl);
  {$ENDIF MSWINDOWS}
  handleExceptionEnd
end;

exports
  CEFChromium_Create,
  CEFChromium_Browser,
  CEFChromium_BrowserById,
  CEFChromium_BrowserIdByIndex,
  CEFChromium_BrowserCount,
  CEFChromium_BrowserId,
  CEFChromium_SetDefaultURL,
  CEFChromium_SetMultiBrowserMode,
  CEFChromium_LoadURL,
  CEFChromium_LoadString,
  CEFChromium_StartDownload,
  CEFChromium_DownloadImage,
  CEFChromium_Reload,
  CEFChromium_ReloadIgnoreCache,
  CEFChromium_ResetZoomLevel,
  CEFChromium_StopLoad,
  CEFChromium_CloseAllBrowsers,
  CEFChromium_CreateBrowser,
  CEFChromium_CreateBrowserByWindow,
  CEFChromium_CreateBrowserByLinkedWindow,
  CEFChromium_CreateBrowserByBrowserViewComponent,
  CEFChromium_Initialized,
  CEFChromium_IsSameBrowser,
  CEFChromium_PrintToPDF,
  CEFChromium_Print,
  CEFChromium_BrowserZoom,
  CEFChromium_GoBackForward,
  CEFChromium_NotifyMoveOrResizeStarted,
  CEFChromium_Invalidate,
  CEFChromium_CloseBrowser,
  CEFChromium_ExecuteJavaScript,
  CEFChromium_ShowDevTools,
  CEFChromium_ShowDevToolsByWindowParent,
  CEFChromium_CloseDevTools,
  CEFChromium_CloseDevToolsByWindowParent,
  CEFChromium_Free,
  CEFChromium_GetHashCode,
  CEFChromium_ClassName,
  CEFChromium_Equals,
  CEFChromium_ClassType,
  CEFChromium_InstanceSize,
  CEFChromium_InheritsFrom,
  CEFChromium_ToString,
  CEFChromium_VisitAllCookies,
  CEFChromium_VisitURLCookies,
  CEFChromium_SetCookie,
  CEFChromium_FlushCookieStore,
  CEFChromium_DeleteCookies,
  CEFChromium_SetProxy,
  CEFChromium_UpdatePreferences,
  CEFChromium_ExecuteDevToolsMethod,
  CEFChromium_CreateClientHandler,
  CEFChromium_SetFocus,
  CEFChromium_SendExternalBeginFrame,
  CEFChromium_SendKeyEvent,
  CEFChromium_SendMouseClickEvent,
  CEFChromium_SendMouseMoveEvent,
  CEFChromium_SendMouseWheelEvent,
  CEFChromium_SendTouchEvent,
  CEFChromium_SendCaptureLostEvent,
  CEFChromium_FrameIsFocused,
  CEFChromium_TryCloseBrowser,
  CEFChromium_BrowserHandle,
  CEFChromium_WidgetHandle,
  CEFChromium_RenderHandle,
  CEFChromium_SetCustomHeader,//
  CEFChromium_GetCustomHeader,
  CEFChromium_SetJavascriptEnabled,
  CEFChromium_GetJavascriptEnabled,
  CEFChromium_SetWebRTCIPHandlingPolicy,
  CEFChromium_GetWebRTCIPHandlingPolicy,
  CEFChromium_SetWebRTCMultipleRoutes,
  CEFChromium_GetWebRTCMultipleRoutes,
  CEFChromium_SetWebRTCNonproxiedUDP,
  CEFChromium_GetWebRTCNonproxiedUDP,
  CEFChromium_SetBatterySaverModeState,
  CEFChromium_GetBatterySaverModeState,
  CEFChromium_SetHighEfficiencyMode,
  CEFChromium_GetHighEfficiencyMode,
  CEFChromium_SetLoadImagesAutomatically,
  CEFChromium_GetLoadImagesAutomatically,
  CEFChromium_SetQuicAllowed,
  CEFChromium_GetQuicAllowed,
  CEFChromium_SetOffline,
  CEFChromium_GetOffline,
  CEFChromium_SetDefaultWindowInfoExStyle,
  CEFChromium_GetDefaultWindowInfoExStyle,
  CEFChromium_SetBlock3rdPartyCookies,
  CEFChromium_GetBlock3rdPartyCookies,
  CEFChromium_SetAcceptCookies,
  CEFChromium_GetAcceptCookies,
  CEFChromium_SetAcceptLanguageList,
  CEFChromium_GetAcceptLanguageList,
  CEFChromium_SetPrintingEnabled,
  CEFChromium_GetPrintingEnabled,
  CEFChromium_SetYouTubeRestrict,
  CEFChromium_GetYouTubeRestrict,
  CEFChromium_SetSafeSearch,
  CEFChromium_GetSafeSearch,
  CEFChromium_SetAudioMuted,
  CEFChromium_GetAudioMuted,
  CEFChromium_SetDragOperations,
  CEFChromium_GetDragOperations,
  CEFChromium_GetFrameCount,
  CEFChromium_SetSpellCheckerDicts,
  CEFChromium_GetSpellCheckerDicts,
  CEFChromium_SetSpellChecking,
  CEFChromium_GetSpellChecking,
  CEFChromium_SetAlwaysOpenPDFExternally,
  CEFChromium_GetAlwaysOpenPDFExternally,
  CEFChromium_SetAlwaysAuthorizePlugins,
  CEFChromium_GetAlwaysAuthorizePlugins,
  CEFChromium_SetAllowOutdatedPlugins,
  CEFChromium_GetAllowOutdatedPlugins,
  CEFChromium_SetSendReferrer,
  CEFChromium_GetSendReferrer,
  CEFChromium_SetDoNotTrack,
  CEFChromium_GetDoNotTrack,
  CEFChromium_SetZoomStep,
  CEFChromium_GetZoomStep,
  CEFChromium_SetZoomPct,
  CEFChromium_GetZoomPct,
  CEFChromium_SetZoomLevel,
  CEFChromium_GetZoomLevel,
  CEFChromium_SetDefaultEncoding,
  CEFChromium_GetDefaultEncoding,
  CEFChromium_SendProcessMessage,
  CEFChromium_SendProcessMessageForJSONBytes,
  CEFChromium_CefClient,
  CEFChromium_SendProcessMessageForV8Value,
  CEFChromium_SimulateMouseWheel,
  CEFChromium_CloseAllConnections,
  CEFChromium_RetrieveHTMLByFrameName,
  CEFChromium_RetrieveHTMLByFrame,
  CEFChromium_RetrieveHTMLByFrameIdentifier,
  CEFChromium_RetrieveTextByFrameName,
  CEFChromium_RetrieveTextByFrame,
  CEFChromium_RetrieveTextByFrameIdentifier,
  CEFChromium_ResolveHost,
  CEFChromium_SetUserAgentOverride,
  CEFChromium_ClearDataForOrigin,
  CEFChromium_ClearCache,
  CEFChromium_ToggleAudioMuted,
  CEFChromium_ClipboardCopy,
  CEFChromium_ClipboardPaste,
  CEFChromium_ClipboardCut,
  CEFChromium_ClipboardUndo,
  CEFChromium_ClipboardRedo,
  CEFChromium_ClipboardDel,
  CEFChromium_SelectAll,
  CEFChromium_IncZoomStep,
  CEFChromium_DecZoomStep,
  CEFChromium_IncZoomPct,
  CEFChromium_DecZoomPct,
  CEFChromium_ResetZoomStep,
  CEFChromium_ResetZoomPct,
  CEFChromium_ReadZoom,
  CEFChromium_WasResized,
  CEFChromium_WasHidden,
  CEFChromium_NotifyScreenInfoChanged,
  CEFChromium_IMESetComposition,
  CEFChromium_IMECommitText,
  CEFChromium_IMEFinishComposingText,
  CEFChromium_IMECancelComposition,
  CEFChromium_HasDevTools,
  CEFChromium_InitializeDragAndDrop;
