//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{==chromium begin==}
//浏览器创建之后
procedure ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
//浏览器创建之前事件
procedure ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  const request: ICefRequest; user_gesture, isRedirect: Boolean; out Result: Boolean);

//地址改变-事件
procedure ChromiumEvent_OnAddressChange(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);

//关闭之前-事件
procedure ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);

//关闭-事件
procedure ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);

//右键菜单-before 创建时设置
procedure ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser;
  const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
//右键菜单-Command
procedure ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  const params: ICefContextMenuParams; commandId: Integer; eventFlags: Cardinal; out Result: Boolean);
//右键菜单-Dismissed
procedure ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);

//导出PDF完成-事件
procedure ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);

//键盘-事件
procedure ChromiumEvent_KeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle;
  out Result: boolean);

//加载 start-事件
procedure ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  transitionType: TCefTransitionType);
//加载 LoadingStateChange-事件
procedure ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser;
  isLoading, canGoBack, canGoForward: boolean);
//加载 LoadingProgressChange-事件
procedure ChromiumEvent_OnLoadingProgressChange(Sender: TObject; const browser: ICefBrowser; const progress: double);
//加载 LoadError-事件
procedure ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer;
  const errorText, failedUrl: ustring);
//加载 LoadEnd-事件
procedure ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);

//下载之前-事件  创建时设置
procedure ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem;
  const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
//下载更新-事件  创建时设置
procedure ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem;
  const callback: ICefDownloadItemCallback);

//放大缩小回调
procedure ChromiumEvent_OnZoomPctAvailable(Sender: TObject; const aZoomPct: double);

//全屏模式-事件
procedure ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);

//弹窗之前-事件 此事件只用在了配置禁用
procedure ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl,
  targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings;
  var extra_info: ICefDictionaryValue; var noJavascriptAccess: Boolean;  var Result: Boolean);
//打开tab-事件 此事件只用在了配置禁用
procedure ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring;
  targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);

//标题改变-事件
procedure ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);

//Render-事件
procedure ChromiumEvent_OnRenderCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
procedure ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);

//滚动条事件
procedure ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);

//进程消息接收
procedure ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);

//查找结果回调
procedure ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);

//资源加载之前消息
procedure ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const callback: ICefCallback; out Result: TCefReturnValue);
procedure ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const response: ICefResponse; out Result: boolean);
procedure ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const response: ICefResponse; var newUrl: ustring);
procedure ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);
{==chromium end==}

{==cookie begin==}
procedure ChromiumEvent_OnCookieSet(Sender: TObject; aSuccess: boolean; aID: integer);
procedure ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
procedure ChromiumEvent_OnCookiesFlushed(Sender: TObject);
procedure ChromiumEvent_OnCookiesVisited(Sender: TObject; const name_, value, domain, path: ustring; secure, httponly, hasExpires: Boolean;
  const creation, lastAccess, expires: TDateTime; count, total, aID: Integer; same_site: TCefCookieSameSite; priority: Integer; var aDeleteCookie, aResult: Boolean);
procedure ChromiumEvent_OnCookieVisitorDestroyed(Sender: TObject; aID: integer);
{==cookie end==}

{==frame begin==}
procedure ChromiumEvent_OnFrameAttached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
procedure ChromiumEvent_OnFrameCreated(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnFrameDetached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnMainFrameChanged(Sender: TObject; const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);
{==frame end==}

{==window begin==}
procedure CEFWindowEvent_OnEnter(Sender: TObject);
procedure CEFWindowEvent_OnExit(Sender: TObject);
{==window end==}


