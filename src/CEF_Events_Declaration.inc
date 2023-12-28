//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== chromium ==}
procedure ChromiumEvent_OnBeforeUnloadDialog(Sender: TObject; const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback; out Result: boolean);
procedure ChromiumEvent_OnCertificateError(Sender: TObject; const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefRequestCallback; out Result: Boolean);
procedure ChromiumEvent_OnConsoleMessage(Sender: TObject; const browser: ICefBrowser; const message, source: ustring; line: Integer; out Result: Boolean);
procedure ChromiumEvent_OnCursorChange(Sender: TObject; const browser: ICefBrowser; cursor: TCefCursorHandle; cursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo);
procedure ChromiumEvent_OnDialogClosed(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnExecuteTaskOnCefThread(Sender: TObject; aTaskID: cardinal);
procedure ChromiumEvent_OnFavIconUrlChange(Sender: TObject; const browser: ICefBrowser; const iconUrls: TStrings);
procedure ChromiumEvent_OnFileDialog(Sender: TObject; const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; selectedAcceptFilter: Integer; const callback: ICefFileDialogCallback; out Result: Boolean);
procedure ChromiumEvent_OnGetAccessibilityHandler(Sender: TObject; var aAccessibilityHandler: ICefAccessibilityHandler);
procedure ChromiumEvent_OnGetResourceHandler(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; out Result: ICefResourceHandler);
procedure ChromiumEvent_OnGetResourceResponseFilter(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: ICefResponseFilter);
procedure ChromiumEvent_OnGetRootScreenRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect; out Result: boolean);
procedure ChromiumEvent_OnGetScreenInfo(Sender: TObject; const browser: ICefBrowser; var screenInfo: TCefScreenInfo; out Result: boolean);
procedure ChromiumEvent_OnGetScreenPoint(Sender: TObject; const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer; out Result: boolean);
procedure ChromiumEvent_OnGetViewRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect; out Result: Boolean);
procedure ChromiumEvent_OnGotFocus(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnJsDialog(Sender: TObject; const browser: ICefBrowser; const originUrl, accept_lang: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: Boolean; out Result: Boolean);
procedure ChromiumEvent_OnPaint(Sender: TObject; const browser: ICefBrowser; type_: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer);
procedure ChromiumEvent_OnPopupShow(Sender: TObject; const browser: ICefBrowser; Show: boolean);
procedure ChromiumEvent_OnPopupSize(Sender: TObject; const browser: ICefBrowser; const rect: PCefRect);
procedure ChromiumEvent_OnPrefsAvailable(Sender: TObject; aResultOK: boolean);
procedure ChromiumEvent_OnPrefsUpdated(Sender: TObject);
procedure ChromiumEvent_OnPreKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean; out Result: boolean);
procedure ChromiumEvent_OnProtocolExecution(Sender: TObject; const browser: ICefBrowser; const url: ustring; out allowOsExecution: Boolean);
procedure ChromiumEvent_OnQuickMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; command_id: integer; event_flags: TCefEventFlags; var aResult: boolean);
procedure ChromiumEvent_OnResetDialogState(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnRunContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback; var aResult: boolean);
procedure ChromiumEvent_OnSetFocus(Sender: TObject; const browser: ICefBrowser; Source: TCefFocusSource; out Result: boolean);
procedure ChromiumEvent_OnStartDragging(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer; out Result: boolean);
procedure ChromiumEvent_OnStatusMessage(Sender: TObject; const browser: ICefBrowser; const Value: ustring);
procedure ChromiumEvent_OnTakeFocus(Sender: TObject; const browser: ICefBrowser; Next: boolean);
procedure ChromiumEvent_OnTooltip(Sender: TObject; const browser: ICefBrowser; var Text: ustring; out Result: boolean);
procedure ChromiumEvent_OnUpdateDragCursor(Sender: TObject; const browser: ICefBrowser; operation: TCefDragOperation);

procedure ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; isRedirect: Boolean; out Result: Boolean);
procedure ChromiumEvent_OnAddressChange(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);
procedure ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
procedure ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
procedure ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: Integer; eventFlags: Cardinal; out Result: Boolean);
procedure ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);
procedure ChromiumEvent_OnKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out Result: boolean);
procedure ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
procedure ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
procedure ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
procedure ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
procedure ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);
procedure ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);
procedure ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: Boolean; var Result: Boolean);
procedure ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);
procedure ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);
procedure ChromiumEvent_OnRenderCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: Boolean);
procedure ChromiumEvent_OnWidgetCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnBrowserCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
procedure ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);
procedure ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);
procedure ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);
procedure ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);
procedure ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefRequestCallback; out Result: TCefReturnValue);
procedure ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: boolean);
procedure ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var newUrl: ustring);
procedure ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);
procedure ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
procedure ChromiumEvent_OnDragEnter(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations; out Result: Boolean);
procedure ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; regionsCount: NativeUInt; regions: PCefDraggableRegionArray);
procedure ChromiumEvent_OnGetAuthCredentials(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback; out Result: Boolean);

{== window parent ==}
procedure CEFWindowEvent_OnEnter(Sender: TObject);
procedure CEFWindowEvent_OnExit(Sender: TObject);
