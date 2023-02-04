//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFChromium_Free(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Free();
  handleExceptionEnd
end;

function CEFChromium_GetHashCode(AObj: TChromium):Integer ; extdecl;
begin
  {$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result := AObj.GetHashCode();
  handleExceptionEnd
end;

function CEFChromium_ClassName(AObj: TChromium):PChar ; extdecl;
begin
  {$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result := ToPChar(AObj.ClassName());
  handleExceptionEnd
end;

function CEFChromium_Equals(AObj: TChromium; Obj: TObject): LongBool; extdecl;
begin
  {$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result := AObj.Equals(Obj);
  handleExceptionEnd
end;

function CEFChromium_ClassType(AObj: TChromium): TClass; extdecl;
begin
  {$ifdef UsehandleException}Result := TClass(nil);{$endif}
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

function CEFChromium_InstanceSize(AObj: TChromium): Integer; extdecl;
begin
  {$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result := AObj.InstanceSize;
  handleExceptionEnd
end;

function CEFChromium_InheritsFrom(AObj: TChromium; AClass: TClass): LongBool; extdecl;
begin
  {$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

function CEFChromium_ToString(AObj: TChromium): PChar; extdecl;
begin
  {$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

//创建 TChromium
function CEFChromium_Create(AOwner: TComponent; Config: TCEFChromiumConfig): TChromium; extdecl;
begin
  handleExceptionBegin
  Result := TChromium.Create(AOwner);
  GChromiumConfig := Config;
  handleExceptionEnd
end;

//设置 默认URL
procedure CEFChromium_SetDefaultURL(AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultUrl:= PCharToUStr(AURL);
  handleExceptionEnd
end;

//设置 MultiBrowserMode 模式
procedure CEFChromium_SetMultiBrowserMode(AObj: TChromium; AValue: Boolean); extdecl;
begin
  handleExceptionBegin
  AObj.MultiBrowserMode := AValue;
  handleExceptionEnd
end;

//加载URL
procedure CEFChromium_LoadURL(AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadURL(PCharToUStr(AURL));
  handleExceptionEnd
end;

//加载HTML
procedure CEFChromium_LoadString(AObj: TChromium; AHTML: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadString(PCharToUStr(AHTML));
  handleExceptionEnd
end;

//开始下载
procedure CEFChromium_StartDownload(AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.StartDownload(PCharToUStr(AURL));
  handleExceptionEnd
end;

//下载图片
procedure CEFChromium_DownloadImage(AObj: TChromium; const imageUrl: PChar; isFavicon: Boolean; maxImageSize: integer; bypassCache: Boolean); extdecl;
begin
  handleExceptionBegin
  AObj.DownloadImage(PCharToUStr(imageUrl), isFavicon, maxImageSize, bypassCache);
  handleExceptionEnd
end;

//重新加载
procedure CEFChromium_Reload(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Reload;
  handleExceptionEnd
end;

//停止加载
procedure CEFChromium_StopLoad(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.StopLoad;
  handleExceptionEnd
end;

//重置缩放级别
procedure CEFChromium_ResetZoomLevel(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ResetZoomLevel;
  handleExceptionEnd
end;

//关闭所有浏览器
procedure CEFChromium_CloseAllBrowsers(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.CloseAllBrowsers;
  handleExceptionEnd
end;

//创建浏览器
function CEFChromium_CreateBrowserByWindow(AObj: TChromium; window: TCEFWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

//创建浏览器
function CEFChromium_CreateBrowserByLinkedWindow(AObj: TChromium; window: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

//创建浏览器
function CEFChromium_CreateBrowserByBrowserViewComponent(AObj: TChromium; PHomePage: PChar; BrowserViewComponent: TCEFBrowserViewComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CreateBrowser(PCharToUStr(PHomePage), BrowserViewComponent);
  handleExceptionEnd
end;

//浏览器初始化
function CEFChromium_Initialized(AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Initialized;
  handleExceptionEnd
end;

//获取浏览器ID 数字 1 2 3 4 ...
function CEFChromium_GetBrowserId(AObj: TChromium): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserId;
  handleExceptionEnd
end;

//判断是否为当前浏览器
function CEFChromium_IsSameBrowser(AObj: TChromium; browserId: integer): LongBool; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  Result := AObj.IsSameBrowser(browser);
  handleExceptionEnd
end;

//导出PDF
procedure CEFChromium_PrintToPDF(AObj: TChromium; FilePath: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.PrintToPDF(PCharToUStr(FilePath));
  handleExceptionEnd
end;

//打印
procedure CEFChromium_Print(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Print;
  handleExceptionEnd
end;

//设置下载目录
procedure CEFChromium_SetDownloadPath(callback: ICefBeforeDownloadCallback; downloadPath: PChar; showDialog: LongBool); extdecl;
begin
  handleExceptionBegin
  callback.Cont(PCharToUStr(downloadPath), showDialog);
  handleExceptionEnd
end;

//下载暂停
procedure CEFChromium_DownloadPause(Callback: ICefDownloadItemCallback); extdecl;
begin
  handleExceptionBegin
  if Callback <> nil then
     Callback.Pause;
  handleExceptionEnd
end;

//下载取消
procedure CEFChromium_BrowserDownloadCancel(borwserId: integer; DownId: integer); extdecl;
var
  itemCallback: ICefDownloadItemCallback;
begin
  handleExceptionBegin
  itemCallback := TMainChromiumBrowserClass.GetBrowserDownloadItemCallback(borwserId, DownId);
  if itemCallback <> nil then
  begin
     itemCallback.Cancel;
  end;
  handleExceptionEnd
end;

//下载暂停
procedure CEFChromium_BrowserDownloadPause(borwserId: integer; DownId: integer); extdecl;
var
  itemCallback: ICefDownloadItemCallback;
begin
  handleExceptionBegin
  itemCallback := TMainChromiumBrowserClass.GetBrowserDownloadItemCallback(borwserId, DownId);
  if itemCallback <> nil then
  begin
     itemCallback.Pause;
  end;
  handleExceptionEnd
end;

//下载恢复
procedure CEFChromium_DownloadResume(borwserId: integer; DownId: integer); extdecl;
var
  itemCallback: ICefDownloadItemCallback;
begin
  handleExceptionBegin
  itemCallback := TMainChromiumBrowserClass.GetBrowserDownloadItemCallback(borwserId, DownId);
  if itemCallback <> nil then
  begin
     itemCallback.Resume;
  end;
  handleExceptionEnd
end;

//zoom 页面，0恢复 1放大 2缩小
procedure CEFChromium_BrowserZoom(AObj: TChromium; Zoom: integer); extdecl;
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
procedure CEFChromium_GoBackForward(AObj: TChromium; BackForward: integer); extdecl;
begin
  handleExceptionBegin
  if BackForward = 0 then
     AObj.GoBack
  else if BackForward = 1 then
     AObj.GoForward;
  handleExceptionEnd
end;

//移动窗口后选项 调用的 NotifyMoveOrResizeStarted
procedure CEFChromium_NotifyMoveOrResizeStarted(AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

//关闭 CloseBrowser
procedure CEFChromium_CloseBrowser(AObj: TChromium; forceClose: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.CloseBrowser(forceClose);
  handleExceptionEnd
end;

//执行 JavaScript
procedure CEFChromium_ExecuteJavaScript(AObj: TChromium; aCode, aScriptURL : PChar; startLine: integer = 0); extdecl;
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
procedure CEFChromium_ShowDevTools(Chromium: TChromium); extdecl;
var
  point: TPoint;
begin
  handleExceptionBegin
  point.x := 100;
  point.y := 100;
  Chromium.ShowDevTools(point, nil);
  handleExceptionEnd
end;

//开发者工具-单独只能弹出主浏览器的
procedure CEFChromium_ShowDevToolsByWindowParent(Chromium: TChromium; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}); extdecl;
var
  point: TPoint;
begin
  handleExceptionBegin
  point.x := 0;
  point.y := 0;
  Chromium.ShowDevTools(point, windowParent);
  handleExceptionEnd
end;

procedure CEFChromium_CloseDevTools(Chromium: TChromium); extdecl;
begin
  handleExceptionBegin
  Chromium.CloseDevTools(nil);
  handleExceptionEnd
end;

procedure CEFChromium_CloseDevToolsByWindowParent(Chromium: TChromium; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}); extdecl;
begin
  handleExceptionBegin
  Chromium.CloseDevTools(windowParent);
  handleExceptionEnd
end;

//cookie begin
procedure CEFChromium_VisitAllCookies(Chromium: TChromium; aID: integer); extdecl;
begin
  handleExceptionBegin
  Chromium.VisitAllCookies(aID);
  handleExceptionEnd
end;

procedure CEFChromium_VisitURLCookies(Chromium: TChromium; URL: PChar; includeHttpOnly: boolean; aID: integer); extdecl;
begin
  handleExceptionBegin
  Chromium.VisitURLCookies(PCharToUStr(URL), includeHttpOnly, aID);
  handleExceptionEnd
end;

procedure CEFChromium_SetCookie(Chromium: TChromium; CefCookie: PRCefCookie); extdecl;
var
  url, name, value, domain, path: ustring;
  secure, httponly, hasExpires: boolean;
  creation, lastAccess, expires: double;
  sameSite: TCefCookieSameSite;
  priority: TCefCookiePriority;
  aSetImmediately: boolean;
  aID: integer;
begin
  handleExceptionBegin
  url := PCharToUStr(CefCookie.url);
  name := PCharToUStr(CefCookie.name);
  value := PCharToUStr(CefCookie.value);
  domain := PCharToUStr(CefCookie.domain);
  path := PCharToUStr(CefCookie.path);
  secure := Boolean(PBoolean(CefCookie.secure));
  httponly := Boolean(PBoolean(CefCookie.httponly));
  hasExpires := Boolean(PBoolean(CefCookie.hasExpires));
  creation := Double(PDouble(CefCookie.creation)^);
  lastAccess := Double(PDouble(CefCookie.lastAccess)^);
  expires := Double(PDouble(CefCookie.expires)^);
  sameSite := TCefCookieSameSite(Integer(CefCookie.sameSite));
  priority := TCefCookiePriority(Integer(CefCookie.priority));
  aSetImmediately := Boolean(PBoolean(CefCookie.aSetImmediately));
  aID := Integer(CefCookie.aID);
  Chromium.SetCookie(url, name, value, domain, path, secure, httponly, hasExpires, creation, lastAccess, expires, sameSite, priority, aSetImmediately, aID);
  CefCookie := nil;
  handleExceptionEnd
end;

procedure CEFChromium_DeleteCookies(Chromium: TChromium; PUrl: PChar; PCookieName: PChar; DeleteImmediately: boolean); extdecl;
var
  url: ustring;
  cookieName: ustring;
begin
  handleExceptionBegin
  url := PCharToUStr(PUrl);
  cookieName := PCharToUStr(PCookieName);
  Chromium.DeleteCookies(url, cookieName, DeleteImmediately);
  handleExceptionEnd
end;

//cookie end

//设置proxy
procedure CEFChromium_SetProxy(Chromium: TChromium; proxy: PRChromiumProxy); extdecl;
begin
  handleExceptionBegin
  Chromium.ProxyType              := Integer(proxy.ProxyType);
  Chromium.ProxyScheme            := TCefProxyScheme(Integer(proxy.ProxyScheme));
  Chromium.ProxyServer            := PCharToUStr(proxy.ProxyServer);
  Chromium.ProxyPort              := Integer(proxy.ProxyPort);
  Chromium.ProxyUsername          := PCharToUStr(proxy.ProxyUsername);
  Chromium.ProxyPassword          := PCharToUStr(proxy.ProxyPassword);
  Chromium.ProxyScriptURL         := PCharToUStr(proxy.ProxyScriptURL);
  Chromium.ProxyByPassList        := PCharToUStr(proxy.ProxyByPassList);
  Chromium.MaxConnectionsPerProxy := Integer(proxy.MaxConnectionsPerProxy);
  handleExceptionEnd
end;

procedure CEFChromium_UpdatePreferences(Chromium: TChromium); extdecl;
begin
  handleExceptionBegin
  Chromium.UpdatePreferences;
  handleExceptionEnd
end;

//执行开发者工具方法
{$ifdef DARWIN}
procedure CEFChromium_ExecuteDevToolsMethod(Chromium: TChromium; messageId: integer; PMethodName: PChar; len: integer; const arguments: array of Byte; argumentsLength: integer); extdecl;
var
  args: array of Byte;
{$else}
procedure CEFChromium_ExecuteDevToolsMethod(Chromium: TChromium; messageId: integer; PMethodName: PChar; len: integer; const arguments: array of Byte); stdcall;
{$endif}
begin
  handleExceptionBegin
  {$ifdef DARWIN}
  if argumentsLength >0 then
  begin
    try
      SetLength(args, argumentsLength);
      Move(arguments[0], args[0], argumentsLength+1);
      ChromiumExecDevToolsMethod(Chromium, messageId, PMethodName, len, args);
    finally
      SetLength(args, 0);
    end;
  end;
  {$else}
  ChromiumExecDevToolsMethod(Chromium, messageId, PMethodName, len, arguments);
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_CreateClientHandler(Chromium: TChromium; client: ICefClient; alsOSR: boolean): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= Chromium.CreateClientHandler(client, alsOSR);
  handleExceptionEnd
end;

procedure CEFChromium_SetFocus(Chromium: TChromium; Value: Boolean);extdecl;
begin
  handleExceptionBegin
  Chromium.SetFocus(Value);
  handleExceptionEnd
end;

procedure CEFChromium_SendCaptureLostEvent(Chromium: TChromium);extdecl;
begin
  handleExceptionBegin
  Chromium.SendCaptureLostEvent;
  handleExceptionEnd
end;

function CEFChromium_FrameIsFocused(Chromium: TChromium): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= Chromium.FrameIsFocused;
  handleExceptionEnd
end;

function CEFChromium_TryCloseBrowser(Chromium: TChromium): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= Chromium.TryCloseBrowser;
  handleExceptionEnd
end;

function CEFChromium_BrowserHandle(Chromium: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= Chromium.BrowserHandle;
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_WidgetHandle(Chromium: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= Chromium.WidgetHandle;
  {$endif}
  handleExceptionEnd
end;

function CEFChromium_RenderHandle(Chromium: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  {$ifdef mswindows}
  Result:= Chromium.RenderHandle;
  {$endif}
  handleExceptionEnd
end;

//CustomHeader
procedure CEFChromium_SetCustomHeader(Chromium: TChromium; PCustomHeader: PRCustomHeader); extdecl;
begin
  handleExceptionBegin
  Chromium.CustomHeaderName  := PCharToUStr(PCustomHeader.CustomHeaderName);
  Chromium.CustomHeaderValue := PCharToUStr(PCustomHeader.CustomHeaderValue);
  handleExceptionEnd
end;

function CEFChromium_GetCustomHeader(Chromium: TChromium): PRCustomHeader; extdecl;
var
  CustomHeader: PRCustomHeader;
begin
  handleExceptionBegin
  CustomHeader := new(PRCustomHeader);
  CustomHeader.CustomHeaderName := PChar(string(Chromium.CustomHeaderName));
  CustomHeader.CustomHeaderValue := PChar(string(Chromium.CustomHeaderValue));
  Result := CustomHeader;
  handleExceptionEnd
end;

//JavascriptEnabled
procedure CEFChromium_SetJavascriptEnabled(Chromium: TChromium; EnabledJavascript: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.JavascriptEnabled := EnabledJavascript;//default true
  handleExceptionEnd
end;

function CEFChromium_GetJavascriptEnabled(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.JavascriptEnabled;
  handleExceptionEnd
end;

//WebRTCIPHandlingPolicy
procedure CEFChromium_SetWebRTCIPHandlingPolicy(Chromium: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = hpDisableNonProxiedUDP
  Chromium.WebRTCIPHandlingPolicy := TCefWebRTCHandlingPolicy(value); //defalt hpDefault
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCIPHandlingPolicy(Chromium: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(Chromium.WebRTCIPHandlingPolicy);
  handleExceptionEnd
end;

//WebRTCMultipleRoutes
procedure CEFChromium_SetWebRTCMultipleRoutes(Chromium: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = STATE_DISABLED
  Chromium.WebRTCMultipleRoutes := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCMultipleRoutes(Chromium: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(Chromium.WebRTCMultipleRoutes);
  handleExceptionEnd
end;

//WebRTCNonproxiedUDP
procedure CEFChromium_SetWebRTCNonproxiedUDP(Chromium: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = STATE_DISABLED
  Chromium.WebRTCNonproxiedUDP := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCNonproxiedUDP(Chromium: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(Chromium.WebRTCNonproxiedUDP);
  handleExceptionEnd
end;

//BatterySaverModeState
procedure CEFChromium_SetBatterySaverModeState(Chromium: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  Chromium.BatterySaverModeState := TCefBatterySaverModeState(value); //defalt bsmsDefault
  handleExceptionEnd
end;

function CEFChromium_GetBatterySaverModeState(Chromium: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(Chromium.BatterySaverModeState);
  handleExceptionEnd
end;

//HighEfficiencyMode
procedure CEFChromium_SetHighEfficiencyMode(Chromium: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  Chromium.HighEfficiencyMode := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetHighEfficiencyMode(Chromium: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(Chromium.HighEfficiencyMode);
  handleExceptionEnd
end;

//LoadImagesAutomatically
procedure CEFChromium_SetLoadImagesAutomatically(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.LoadImagesAutomatically := value; //defalt true
  handleExceptionEnd
end;

function CEFChromium_GetLoadImagesAutomatically(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.LoadImagesAutomatically;
  handleExceptionEnd
end;

//QuicAllowed
procedure CEFChromium_SetQuicAllowed(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.QuicAllowed := value; //defalt true
  handleExceptionEnd
end;

function CEFChromium_GetQuicAllowed(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.QuicAllowed;
  handleExceptionEnd
end;

//Offline
procedure CEFChromium_SetOffline(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.Offline := value; //defalt False
  handleExceptionEnd
end;

function CEFChromium_GetOffline(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.Offline;
  handleExceptionEnd
end;

//DefaultWindowInfoExStyle
procedure CEFChromium_SetDefaultWindowInfoExStyle(Chromium: TChromium; value: DWORD); extdecl;
begin
  handleExceptionBegin
  Chromium.DefaultWindowInfoExStyle := value; //defalt 0
  handleExceptionEnd
end;

function CEFChromium_GetDefaultWindowInfoExStyle(Chromium: TChromium): DWORD; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.DefaultWindowInfoExStyle;
  handleExceptionEnd
end;

//Block3rdPartyCookies
procedure CEFChromium_SetBlock3rdPartyCookies(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.Block3rdPartyCookies := value; //defalt False
  handleExceptionEnd
end;

function CEFChromium_GetBlock3rdPartyCookies(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.Block3rdPartyCookies;
  handleExceptionEnd
end;

//AcceptCookies
procedure CEFChromium_SetAcceptCookies(Chromium: TChromium; value: integer); extdecl;
begin
  handleExceptionBegin
  Chromium.AcceptCookies := TCefCookiePref(value); //defalt cpAllow
  handleExceptionEnd
end;

function CEFChromium_GetAcceptCookies(Chromium: TChromium): integer; extdecl;
begin
  handleExceptionBegin
  Result := integer(Chromium.AcceptCookies);
  handleExceptionEnd
end;

//AcceptLanguageList
procedure CEFChromium_SetAcceptLanguageList(Chromium: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  Chromium.AcceptLanguageList := PCharToUStr(value); //defalt ''
  handleExceptionEnd
end;

function CEFChromium_GetAcceptLanguageList(Chromium: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(Chromium.AcceptLanguageList));
  handleExceptionEnd
end;

//PrintingEnabled
procedure CEFChromium_SetPrintingEnabled(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.PrintingEnabled := value; //defalt True
  handleExceptionEnd
end;

function CEFChromium_GetPrintingEnabled(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.PrintingEnabled;
  handleExceptionEnd
end;

//YouTubeRestrict
procedure CEFChromium_SetYouTubeRestrict(Chromium: TChromium; value: integer); extdecl;
begin
  handleExceptionBegin
  Chromium.YouTubeRestrict := value; //defalt YOUTUBE_RESTRICT_OFF
  handleExceptionEnd
end;

function CEFChromium_GetYouTubeRestrict(Chromium: TChromium): integer; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.YouTubeRestrict;
  handleExceptionEnd
end;

//SafeSearch
procedure CEFChromium_SetSafeSearch(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.SafeSearch := value; //defalt False
  handleExceptionEnd
end;

function CEFChromium_GetSafeSearch(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.SafeSearch;
  handleExceptionEnd
end;

//AudioMuted
procedure CEFChromium_SetAudioMuted(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.AudioMuted := value; //defalt ?
  handleExceptionEnd
end;

function CEFChromium_GetAudioMuted(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.AudioMuted;
  handleExceptionEnd
end;

//DragOperations
procedure CEFChromium_SetDragOperations(Chromium: TChromium; value: Cardinal); extdecl;
begin
  handleExceptionBegin
  Chromium.DragOperations := value; //default DRAG_OPERATION_NONE
  handleExceptionEnd
end;

function CEFChromium_GetDragOperations(Chromium: TChromium): Cardinal; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.DragOperations;
  handleExceptionEnd
end;

//FrameCount
function CEFChromium_GetFrameCount(Chromium: TChromium): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.FrameCount;
  handleExceptionEnd
end;

//SpellCheckerDicts
procedure CEFChromium_SetSpellCheckerDicts(Chromium: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  Chromium.SpellCheckerDicts := PCharToUStr(value); //default ''
  handleExceptionEnd
end;

function CEFChromium_GetSpellCheckerDicts(Chromium: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(Chromium.SpellCheckerDicts));
  handleExceptionEnd
end;

//SpellChecking
procedure CEFChromium_SetSpellChecking(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.SpellChecking := value; //default True
  handleExceptionEnd
end;

function CEFChromium_GetSpellChecking(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.SpellChecking;
  handleExceptionEnd
end;

//AlwaysOpenPDFExternally
procedure CEFChromium_SetAlwaysOpenPDFExternally(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.AlwaysOpenPDFExternally := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysOpenPDFExternally(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.AlwaysOpenPDFExternally;
  handleExceptionEnd
end;

//AlwaysAuthorizePlugins
procedure CEFChromium_SetAlwaysAuthorizePlugins(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.AlwaysAuthorizePlugins := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysAuthorizePlugins(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.AlwaysAuthorizePlugins;
  handleExceptionEnd
end;

//AllowOutdatedPlugins
procedure CEFChromium_SetAllowOutdatedPlugins(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.AllowOutdatedPlugins := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAllowOutdatedPlugins(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.AllowOutdatedPlugins;
  handleExceptionEnd
end;

//SendReferrer
procedure CEFChromium_SetSendReferrer(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.SendReferrer := value; //default = True
  handleExceptionEnd
end;

function CEFChromium_GetSendReferrer(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.SendReferrer;
  handleExceptionEnd
end;

//DoNotTrack
procedure CEFChromium_SetDoNotTrack(Chromium: TChromium; value: boolean); extdecl;
begin
  handleExceptionBegin
  Chromium.DoNotTrack := value; //default = True
  handleExceptionEnd
end;

function CEFChromium_GetDoNotTrack(Chromium: TChromium): boolean; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.DoNotTrack;
  handleExceptionEnd
end;

//ZoomStep
procedure CEFChromium_SetZoomStep(Chromium: TChromium; value: byte); extdecl;
begin
  handleExceptionBegin
  Chromium.ZoomStep := value; //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

function CEFChromium_GetZoomStep(Chromium: TChromium): byte; extdecl;
begin
  handleExceptionBegin
  Result := Chromium.ZoomStep;
  handleExceptionEnd
end;

//ZoomPct
procedure CEFChromium_SetZoomPct(Chromium: TChromium; value: PDouble); extdecl;
begin
  handleExceptionBegin
  Chromium.ZoomPct := Double(value); //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

function CEFChromium_GetZoomPct(Chromium: TChromium): PDouble; extdecl;
begin
  handleExceptionBegin
  Result := PDouble(Chromium.ZoomPct);
  handleExceptionEnd
end;

//ZoomLevel
procedure CEFChromium_SetZoomLevel(Chromium: TChromium; value: PDouble); extdecl;
begin
  handleExceptionBegin
  Chromium.ZoomLevel := Double(value); //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

function CEFChromium_GetZoomLevel(Chromium: TChromium): PDouble; extdecl;
begin
  handleExceptionBegin
  Result := PDouble(Chromium.ZoomLevel);
  handleExceptionEnd
end;

//DefaultEncoding
procedure CEFChromium_SetDefaultEncoding(Chromium: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  Chromium.DefaultEncoding := PCharToUStr(value); //default = ''
  handleExceptionEnd
end;

function CEFChromium_GetDefaultEncoding(Chromium: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(Chromium.DefaultEncoding));
  handleExceptionEnd
end;

exports
{ ==== proc begin ====  }
  CEFChromium_Create,
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
  CEFChromium_GetBrowserId,
  CEFChromium_IsSameBrowser,
  CEFChromium_PrintToPDF,
  CEFChromium_Print,
  CEFChromium_SetDownloadPath,
  CEFChromium_BrowserDownloadCancel,
  CEFChromium_DownloadPause,
  CEFChromium_BrowserDownloadPause,
  CEFChromium_DownloadResume,
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
  CEFChromium_GetDefaultEncoding
  { ====  proc end ==== }

//结尾
;

