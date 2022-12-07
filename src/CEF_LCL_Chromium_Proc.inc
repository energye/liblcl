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
  //初始化默认配置
  ChromiumInitDefault(Result, Config);
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
function CEFChromium_IsSameBrowser(AObj: TChromium; browserId: integer): Boolean; extdecl;
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
  AObj.PrintToPDF(PCharToUStr(FilePath), AObj.DocumentURL, AObj.DocumentURL);
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
  Chromium.VisitAllCookies(aID);
end;

procedure CEFChromium_VisitURLCookies(Chromium: TChromium; URL: PChar; includeHttpOnly: boolean; aID: integer); extdecl;
begin
  Chromium.VisitURLCookies(PCharToUStr(URL), includeHttpOnly, aID);
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
  try
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
  finally
    CefCookie := nil;
  end;
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
var
  ProxyType, ProxyScheme: integer;
  ProxyServer: string;
  ProxyPort: integer;
  ProxyUsername, ProxyPassword, ProxyScriptURL, ProxyByPassList: string;
  MaxConnectionsPerProxy: integer;
  CustomHeaderName, CustomHeaderValue: string;
begin
  handleExceptionBegin
  ProxyType := Integer(proxy.ProxyType);
  ProxyScheme := Integer(proxy.ProxyScheme);
  ProxyServer := PCharToUStr(proxy.ProxyServer);
  ProxyPort := Integer(proxy.ProxyPort);
  ProxyUsername := PCharToUStr(proxy.ProxyUsername);
  ProxyPassword := PCharToUStr(proxy.ProxyPassword);
  ProxyScriptURL := PCharToUStr(proxy.ProxyScriptURL);
  ProxyByPassList := PCharToUStr(proxy.ProxyByPassList);
  MaxConnectionsPerProxy := Integer(proxy.MaxConnectionsPerProxy);
  CustomHeaderName := PCharToUStr(proxy.CustomHeaderName);
  CustomHeaderValue := PCharToUStr(proxy.CustomHeaderValue);
  Chromium.ProxyType              := ProxyType;
  Chromium.ProxyScheme            := TCefProxyScheme(ProxyScheme);
  Chromium.ProxyServer            := ProxyServer;
  Chromium.ProxyPort              := ProxyPort;
  Chromium.ProxyUsername          := ProxyUsername;
  Chromium.ProxyPassword          := ProxyPassword;
  Chromium.ProxyScriptURL         := ProxyScriptURL;
  Chromium.ProxyByPassList        := ProxyByPassList;
  Chromium.CustomHeaderName       := CustomHeaderName;
  Chromium.CustomHeaderValue      := CustomHeaderValue;
  Chromium.MaxConnectionsPerProxy := MaxConnectionsPerProxy;
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

function CEFChromium_CreateClientHandler(Chromium: TChromium; client: ICefClient; alsOSR: boolean): boolean ; extdecl;
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

function CEFChromium_FrameIsFocused(Chromium: TChromium): boolean ; extdecl;
begin
  handleExceptionBegin
  Result:= Chromium.FrameIsFocused;
  handleExceptionEnd
end;

procedure CEF_AddGoForm(BrowserId: Integer; GoForm: TGoForm); extdecl;
begin
  handleExceptionBegin
  TBrowserWindowClass.Add(BrowserId, GoForm);
  handleExceptionEnd
end;

procedure CEF_RemoveGoForm(BrowserId: Integer); extdecl;
begin
  handleExceptionBegin
  TBrowserWindowClass.Remove(BrowserId);
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
  { ====  proc end ==== }
  { ====  go from begin ==== }
  CEF_AddGoForm,
  CEF_RemoveGoForm
  { ====  go from end ==== }

//结尾
;

