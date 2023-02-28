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

//创建 TChromium
function CEFChromium_Create(const AOwner: TComponent; Config: TCEFChromiumConfig): TChromium; extdecl;
begin
  handleExceptionBegin
  Result := TChromium.Create(AOwner);
  GChromiumConfig := Config;
  handleExceptionEnd
end;

//获取 Browser
procedure CEFChromium_Browser(const AObj: TChromium; out Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := AObj.Browser;
  handleExceptionEnd
end;

//根据 id 获取 Browser
procedure CEFChromium_BrowserById(const AObj: TChromium; id: integer; out Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserById[id];
  handleExceptionEnd
end;

//根据 index 获取 browserId
function CEFChromium_BrowserIdByIndex(const AObj: TChromium; index: integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserIdByIndex[index];
  handleExceptionEnd
end;

//获取 Browser 数量
function CEFChromium_BrowserCount(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserCount;
  handleExceptionEnd
end;

//获取 BrowserId
function CEFChromium_BrowserId(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserId;
  handleExceptionEnd
end;

//设置 默认URL
procedure CEFChromium_SetDefaultURL(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultUrl:= PCharToUStr(AURL);
  handleExceptionEnd
end;

//设置 MultiBrowserMode 模式
procedure CEFChromium_SetMultiBrowserMode(const AObj: TChromium; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.MultiBrowserMode := AValue;
  handleExceptionEnd
end;

//加载URL
procedure CEFChromium_LoadURL(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadURL(PCharToUStr(AURL));
  handleExceptionEnd
end;

//加载HTML
procedure CEFChromium_LoadString(const AObj: TChromium; AHTML: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadString(PCharToUStr(AHTML));
  handleExceptionEnd
end;

//开始下载
procedure CEFChromium_StartDownload(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.StartDownload(PCharToUStr(AURL));
  handleExceptionEnd
end;

//下载图片
procedure CEFChromium_DownloadImage(const AObj: TChromium; const imageUrl: PChar; isFavicon: LongBool; maxImageSize: integer; bypassCache: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DownloadImage(PCharToUStr(imageUrl), isFavicon, maxImageSize, bypassCache);
  handleExceptionEnd
end;

//重新加载
procedure CEFChromium_Reload(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Reload;
  handleExceptionEnd
end;

//停止加载
procedure CEFChromium_StopLoad(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.StopLoad;
  handleExceptionEnd
end;

//重置缩放级别
procedure CEFChromium_ResetZoomLevel(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ResetZoomLevel;
  handleExceptionEnd
end;

//关闭所有浏览器
procedure CEFChromium_CloseAllBrowsers(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.CloseAllBrowsers;
  handleExceptionEnd
end;

//创建浏览器
function CEFChromium_CreateBrowserByWindow(const AObj: TChromium; window: TCEFWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

//创建浏览器
function CEFChromium_CreateBrowserByLinkedWindow(const AObj: TChromium; window: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

//创建浏览器
function CEFChromium_CreateBrowserByBrowserViewComponent(const AObj: TChromium; PHomePage: PChar; BrowserViewComponent: TCEFBrowserViewComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(PCharToUStr(PHomePage), BrowserViewComponent);
  handleExceptionEnd
end;

//浏览器初始化
function CEFChromium_Initialized(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Initialized;
  handleExceptionEnd
end;

//判断是否为当前浏览器
function CEFChromium_IsSameBrowser(const AObj: TChromium; const that: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSameBrowser(that);
  handleExceptionEnd
end;

//导出PDF
procedure CEFChromium_PrintToPDF(const AObj: TChromium; FilePath: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.PrintToPDF(PCharToUStr(FilePath));
  handleExceptionEnd
end;

//打印
procedure CEFChromium_Print(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Print;
  handleExceptionEnd
end;

//zoom 页面，0恢复 1放大 2缩小
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

//回退 & 前进
procedure CEFChromium_GoBackForward(const AObj: TChromium; BackForward: integer); extdecl;
begin
  handleExceptionBegin
  if BackForward = 0 then
     AObj.GoBack
  else if BackForward = 1 then
     AObj.GoForward;
  handleExceptionEnd
end;

//移动窗口后选项 调用的 NotifyMoveOrResizeStarted
procedure CEFChromium_NotifyMoveOrResizeStarted(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

//关闭 CloseBrowser
procedure CEFChromium_CloseBrowser(const AObj: TChromium; forceClose: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.CloseBrowser(forceClose);
  handleExceptionEnd
end;

//执行 JavaScript
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

//开发者工具-单独只能弹出主浏览器的
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

//开发者工具-单独只能弹出主浏览器的
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
  aSetImmediately := LongBool(PLongBool(CefCookie.aSetImmediately));
  aID := Integer(CefCookie.aID);
  AObj.SetCookie(url, name, value, domain, path, secure, httponly, hasExpires, creation, lastAccess, expires, sameSite, priority, aSetImmediately, aID);
  CefCookie := nil;
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

//设置proxy
procedure CEFChromium_SetProxy(const AObj: TChromium; proxy: PRChromiumProxy); extdecl;
begin
  handleExceptionBegin
  AObj.ProxyType              := Integer(proxy.ProxyType);
  AObj.ProxyScheme            := TCefProxyScheme(Integer(proxy.ProxyScheme));
  AObj.ProxyServer            := PCharToUStr(proxy.ProxyServer);
  AObj.ProxyPort              := Integer(proxy.ProxyPort);
  AObj.ProxyUsername          := PCharToUStr(proxy.ProxyUsername);
  AObj.ProxyPassword          := PCharToUStr(proxy.ProxyPassword);
  AObj.ProxyScriptURL         := PCharToUStr(proxy.ProxyScriptURL);
  AObj.ProxyByPassList        := PCharToUStr(proxy.ProxyByPassList);
  AObj.MaxConnectionsPerProxy := Integer(proxy.MaxConnectionsPerProxy);
  handleExceptionEnd
end;

procedure CEFChromium_UpdatePreferences(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.UpdatePreferences;
  handleExceptionEnd
end;

//执行开发者工具方法
procedure CEFChromium_ExecuteDevToolsMethod(const AObj: TChromium; messageId: integer; PMethodName: PChar; const dictionaryValue: ICefDictionaryValue); extdecl;
begin
  handleExceptionBegin
  AObj.ExecuteDevToolsMethod(messageId, PCharToUStr(PMethodName), dictionaryValue);
  handleExceptionEnd
end;

function CEFChromium_CreateClientHandler(const AObj: TChromium; client: ICefClient; alsOSR: LongBool): LongBool ; extdecl;
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
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_WidgetHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= AObj.WidgetHandle;
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_RenderHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= AObj.RenderHandle;
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
  AObj.BatterySaverModeState := TCefBatterySaverModeState(value); //defalt bsmsDefault
  handleExceptionEnd
end;

function CEFChromium_GetBatterySaverModeState(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.BatterySaverModeState);
  handleExceptionEnd
end;

//HighEfficiencyMode
procedure CEFChromium_SetHighEfficiencyMode(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.HighEfficiencyMode := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetHighEfficiencyMode(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.HighEfficiencyMode);
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
  AObj.AlwaysOpenPDFExternally := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysOpenPDFExternally(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AlwaysOpenPDFExternally;
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

procedure CEFChromium_GetZoomPct(const AObj: TChromium; out Result: Double); extdecl;
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

procedure CEFChromium_GetZoomLevel(const AObj: TChromium; out Result: Double); extdecl;
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
  CEFChromium_ResetZoomLevel,
  CEFChromium_StopLoad,
  CEFChromium_CloseAllBrowsers,
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
  CEFChromium_DeleteCookies,
  CEFChromium_SetProxy,
  CEFChromium_UpdatePreferences,
  CEFChromium_ExecuteDevToolsMethod,
  CEFChromium_CreateClientHandler,
  CEFChromium_SetFocus,
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
  CEFChromium_SendProcessMessage
;

