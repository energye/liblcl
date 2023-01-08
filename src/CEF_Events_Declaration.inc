//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{==chromium begin==}
//chromium 浏览器创建之后
procedure ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
//chromium 浏览器创建之前
procedure ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; user_gesture, isRedirect: Boolean; out Result: Boolean);

//chromium 地址改变
procedure ChromiumEvent_OnAddressChange(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);

//chromium 关闭
procedure ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);

//chromium 右键菜单
procedure ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
procedure ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: Integer; eventFlags: Cardinal; out Result: Boolean);
procedure ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);

//chromium 导出PDF完成-事件
procedure ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);

//chromium 键盘-事件
procedure ChromiumEvent_KeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out Result: boolean);

//chromium 加载
procedure ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
procedure ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
procedure ChromiumEvent_OnLoadingProgressChange(Sender: TObject; const browser: ICefBrowser; const progress: double);
procedure ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
procedure ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);

//chromium 下载之前
procedure ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
procedure ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);

//chromium 放大缩小回调
procedure ChromiumEvent_OnZoomPctAvailable(Sender: TObject; const aZoomPct: double);

//chromium 全屏模式-事件
procedure ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);

//chromium 弹窗之前-事件 此事件只用在了配置禁用
procedure ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var extra_info: ICefDictionaryValue; var noJavascriptAccess: Boolean;  var Result: Boolean);
//chromium 打开tab-事件 此事件只用在了配置禁用
procedure ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);

//chromium TitleChange
procedure ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);

//chromium msg
procedure ChromiumEvent_OnRenderCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnWidgetCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnBrowserCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);

//chromium Render
procedure ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
procedure ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);

//chromium ScrollOffsetChanged
procedure ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);

//chromium ProcessMessageReceived
procedure ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);

//chromium find text
procedure ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);

//chromium Resource
procedure ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefCallback; out Result: TCefReturnValue);
procedure ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: boolean);
procedure ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var newUrl: ustring);
procedure ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);

{==chromium cookie==}
procedure ChromiumEvent_OnCookieSet(Sender: TObject; aSuccess: boolean; aID: integer);
procedure ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
procedure ChromiumEvent_OnCookiesFlushed(Sender: TObject);
procedure ChromiumEvent_OnCookiesVisited(Sender: TObject; const name_, value, domain, path: ustring; secure, httponly, hasExpires: Boolean; const creation, lastAccess, expires: TDateTime; count, total, aID: Integer; same_site: TCefCookieSameSite; priority: Integer; var aDeleteCookie, aResult: Boolean);
procedure ChromiumEvent_OnCookieVisitorDestroyed(Sender: TObject; aID: integer);

{==chromium frame==}
procedure ChromiumEvent_OnFrameAttached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
procedure ChromiumEvent_OnFrameCreated(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnFrameDetached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnMainFrameChanged(Sender: TObject; const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);

{==chromium Drag==}
procedure ChromiumEvent_OnDragEnter(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations; out Result: Boolean);
procedure ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; regionsCount: NativeUInt; const regions: PCefDraggableRegionArray);

{== window parent ==}
procedure CEFWindowEvent_OnEnter(Sender: TObject);
procedure CEFWindowEvent_OnExit(Sender: TObject);

{==CEFWindowComponent==}
procedure WindowComponent_OnWindowCreated(const Sender: TObject; const window: ICefWindow);
procedure WindowComponent_OnWindowDestroyed(const Sender: TObject; const window: ICefWindow);
procedure WindowComponent_OnWindowActivationChanged(const Sender: TObject; const window: ICefWindow; active: boolean);
procedure WindowComponent_OnGetParentWindow(const Sender: TObject; const window: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult : ICefWindow);
procedure WindowComponent_OnGetInitialBounds(const Sender: TObject; const window: ICefWindow; var aResult : TCefRect);
procedure WindowComponent_OnGetInitialShowState(const Sender: TObject; const window: ICefWindow; var aResult : TCefShowState);
procedure WindowComponent_OnIsFrameless(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
procedure WindowComponent_OnCanResize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
procedure WindowComponent_OnCanMaximize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
procedure WindowComponent_OnCanMinimize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
procedure WindowComponent_OnCanClose(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
procedure WindowComponent_OnAccelerator(const Sender: TObject; const window: ICefWindow; command_id: Integer; var aResult : boolean);
procedure WindowComponent_OnKeyEvent(const Sender: TObject; const window: ICefWindow; const event: TCefKeyEvent; var aResult : boolean);

{==CEFBrowserViewComponent==}
procedure BrowserViewComponent_OnBrowserCreated(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
procedure BrowserViewComponent_OnBrowserDestroyed(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
procedure BrowserViewComponent_OnGetDelegateForPopupBrowserView(const Sender: TObject; const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult : ICefBrowserViewDelegate);
procedure BrowserViewComponent_OnPopupBrowserViewCreated(const Sender: TObject; const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult : boolean);
procedure BrowserViewComponent_OnGetChromeToolbarType(const Sender: TObject; var aChromeToolbarType: TCefChromeToolbarType);
