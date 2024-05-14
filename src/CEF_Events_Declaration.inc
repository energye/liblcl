//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== chromium ==}
procedure ChromiumEvent_OnAcceleratedPaint(Sender: TObject; const browser: ICefBrowser; type_: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; shared_handle: Pointer);
procedure ChromiumEvent_OnAllConnectionsClosed(Sender: TObject);
procedure ChromiumEvent_OnAudioStreamError(Sender: TObject; const browser: ICefBrowser; const message_: ustring);
procedure ChromiumEvent_OnAudioStreamPacket(Sender: TObject; const browser: ICefBrowser; const Data: PPSingle; frames: integer; pts: int64);
procedure ChromiumEvent_OnAudioStreamStarted(Sender: TObject; const browser: ICefBrowser; const params: TCefAudioParameters; channels: integer);
procedure ChromiumEvent_OnAudioStreamStopped(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnAutoResize(Sender: TObject; const browser: ICefBrowser; const new_size: PCefSize; out Result: boolean);
procedure ChromiumEvent_OnBeforeUnloadDialog(Sender: TObject; const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback; out Result: boolean);
procedure ChromiumEvent_OnCanDownload(Sender: TObject; const browser: ICefBrowser; const url, request_method: ustring; var aResult: boolean);
procedure ChromiumEvent_OnCanSaveCookie(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; const cookie: PCefCookie; var aResult: boolean);
procedure ChromiumEvent_OnCanSendCookie(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const cookie: PCefCookie; var aResult: boolean);
procedure ChromiumEvent_OnCertificateError(Sender: TObject; const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefCallback; out Result: boolean);
procedure ChromiumEvent_OnCertificateExceptionsCleared(Sender: TObject);
procedure ChromiumEvent_OnChromeCommand(Sender: TObject; const browser: ICefBrowser; command_id: integer; disposition: TCefWindowOpenDisposition; var aResult: boolean);
procedure ChromiumEvent_OnConsoleMessage(Sender: TObject; const browser: ICefBrowser; level: TCefLogSeverity; const message, Source: ustring; line: integer; out Result: boolean);
procedure ChromiumEvent_OnCursorChange(Sender: TObject; const browser: ICefBrowser; cursor_: TCefCursorHandle; cursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo; var aResult: boolean);
procedure ChromiumEvent_OnDevToolsAgentAttached(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnDevToolsAgentDetached(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnDevToolsEvent(Sender: TObject; const browser: ICefBrowser; const method: ustring; const params: ICefValue);
procedure ChromiumEvent_OnDevToolsMessage(Sender: TObject; const browser: ICefBrowser; const message_: ICefValue; var aHandled: boolean);
procedure ChromiumEvent_OnDevToolsMethodRawResult(Sender: TObject; const browser: ICefBrowser; message_id: integer; success: boolean; const Result: Pointer; result_size: nativeuint);
procedure ChromiumEvent_OnDevToolsMethodResult(Sender: TObject; const browser: ICefBrowser; message_id: integer; success: boolean; const Result: ICefValue);
procedure ChromiumEvent_OnDevToolsRawEvent(Sender: TObject; const browser: ICefBrowser; const method: ustring; const params: Pointer; params_size: nativeuint);
procedure ChromiumEvent_OnDevToolsRawMessage(Sender: TObject; const browser: ICefBrowser; const message_: Pointer; message_size: nativeuint; var aHandled: boolean);
procedure ChromiumEvent_OnDialogClosed(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnDismissPermissionPrompt(Sender: TObject; const browser: ICefBrowser; prompt_id: uint64; Result: TCefPermissionRequestResult);
procedure ChromiumEvent_OnDocumentAvailableInMainFrame(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnDownloadImageFinished(Sender: TObject; const imageUrl: ustring; httpStatusCode: integer; const image: ICefImage);
procedure ChromiumEvent_OnExecuteTaskOnCefThread(Sender: TObject; aTaskID: cardinal);
procedure ChromiumEvent_OnFavIconUrlChange(Sender: TObject; const browser: ICefBrowser; const iconUrls: TStrings);
procedure ChromiumEvent_OnFileDialog(Sender: TObject; const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; const callback: ICefFileDialogCallback; var Result: boolean);
procedure ChromiumEvent_OnGetAccessibilityHandler(Sender: TObject; var aAccessibilityHandler: ICefAccessibilityHandler);
procedure ChromiumEvent_OnGetAudioParameters(Sender: TObject; const browser: ICefBrowser; var params: TCefAudioParameters; var aResult: boolean);
procedure ChromiumEvent_OnGetResourceHandler(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aResourceHandler: ICefResourceHandler);
procedure ChromiumEvent_OnGetResourceRequestHandler_ReqCtxHdlr(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aExternalResourceRequestHandler: ICefResourceRequestHandler);
procedure ChromiumEvent_OnGetResourceRequestHandler_ReqHdlr(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aExternalResourceRequestHandler: ICefResourceRequestHandler);
procedure ChromiumEvent_OnGetResourceResponseFilter(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: ICefResponseFilter);
procedure ChromiumEvent_OnGetRootScreenRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect; out Result: boolean);
procedure ChromiumEvent_OnGetScreenInfo(Sender: TObject; const browser: ICefBrowser; var screenInfo: TCefScreenInfo; out Result: boolean);
procedure ChromiumEvent_OnGetScreenPoint(Sender: TObject; const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer; out Result: boolean);
procedure ChromiumEvent_OnGetTouchHandleSize(Sender: TObject; const browser: ICefBrowser; orientation: TCefHorizontalAlignment; var size: TCefSize);
procedure ChromiumEvent_OnGetViewRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect);
procedure ChromiumEvent_OnGotFocus(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnHttpAuthCredentialsCleared(Sender: TObject);
procedure ChromiumEvent_OnIMECompositionRangeChanged(Sender: TObject; const browser: ICefBrowser; const selected_range: PCefRange; character_boundsCount: nativeuint; const character_bounds: PCefRect);
procedure ChromiumEvent_OnJsDialog(Sender: TObject; const browser: ICefBrowser; const originUrl: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: boolean; out Result: boolean);
procedure ChromiumEvent_OnMediaAccessChange(Sender: TObject; const browser: ICefBrowser; has_video_access, has_audio_access: boolean);
procedure ChromiumEvent_OnMediaRouteCreateFinished(Sender: TObject; Result: TCefMediaRouterCreateResult; const error: ustring; const route: ICefMediaRoute);
procedure ChromiumEvent_OnMediaSinkDeviceInfo(Sender: TObject; const ip_address: ustring; port: integer; const model_name: ustring);
procedure ChromiumEvent_OnNavigationVisitorResultAvailable(Sender: TObject; const entry: ICefNavigationEntry; current: boolean; index, total: integer; var aResult: boolean);
procedure ChromiumEvent_OnPaint(Sender: TObject; const browser: ICefBrowser; type_: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer);
procedure ChromiumEvent_OnPopupShow(Sender: TObject; const browser: ICefBrowser; Show: boolean);
procedure ChromiumEvent_OnPopupSize(Sender: TObject; const browser: ICefBrowser; const rect: PCefRect);
procedure ChromiumEvent_OnPrefsAvailable(Sender: TObject; aResultOK: boolean);
procedure ChromiumEvent_OnPrefsUpdated(Sender: TObject);
procedure ChromiumEvent_OnPreKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean; out Result: boolean);
procedure ChromiumEvent_OnProtocolExecution(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var allowOsExecution: boolean);
procedure ChromiumEvent_OnQuickMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; command_id: integer; event_flags: TCefEventFlags; var aResult: boolean);
procedure ChromiumEvent_OnQuickMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnRequestContextInitialized(Sender: TObject; const request_context: ICefRequestContext);
procedure ChromiumEvent_OnRequestMediaAccessPermission(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const requesting_origin: ustring; requested_permissions: cardinal; const callback: ICefMediaAccessCallback; var aResult: boolean);
procedure ChromiumEvent_OnResetDialogState(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnResolvedHostAvailable(Sender: TObject; Result: TCefErrorCode; const resolvedIps: TStrings);
procedure ChromiumEvent_OnRouteMessageReceived(Sender: TObject; const route: ICefMediaRoute; const message_: ustring);
procedure ChromiumEvent_OnRoutes(Sender: TObject; const routes: TCefMediaRouteArray);
procedure ChromiumEvent_OnRouteStateChanged(Sender: TObject; const route: ICefMediaRoute; state: TCefMediaRouteConnectionState);
procedure ChromiumEvent_OnRunContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback; var aResult: boolean);
procedure ChromiumEvent_OnRunQuickMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; location: TCefPoint; size: TCefSize; edit_state_flags: TCefQuickMenuEditStateFlags; const callback: ICefRunQuickMenuCallback; var aResult: boolean);
procedure ChromiumEvent_OnSelectClientCertificate(Sender: TObject; const browser: ICefBrowser; isProxy: boolean; const host: ustring; port: integer; certificatesCount: nativeuint; const certificates: TCefX509CertificateArray; const callback: ICefSelectClientCertificateCallback; var aResult: boolean);
procedure ChromiumEvent_OnSetFocus(Sender: TObject; const browser: ICefBrowser; Source: TCefFocusSource; out Result: boolean);
procedure ChromiumEvent_OnShowPermissionPrompt(Sender: TObject; const browser: ICefBrowser; prompt_id: uint64; const requesting_origin: ustring; requested_permissions: cardinal; const callback: ICefPermissionPromptCallback; var aResult: boolean);
procedure ChromiumEvent_OnSinks(Sender: TObject; const sinks: TCefMediaSinkArray);
procedure ChromiumEvent_OnStartDragging(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer; out Result: boolean);
procedure ChromiumEvent_OnStatusMessage(Sender: TObject; const browser: ICefBrowser; const Value: ustring);
procedure ChromiumEvent_OnTakeFocus(Sender: TObject; const browser: ICefBrowser; Next: boolean);
procedure ChromiumEvent_OnTextResultAvailable(Sender: TObject; const aText: ustring);
procedure ChromiumEvent_OnTextSelectionChanged(Sender: TObject; const browser: ICefBrowser; const selected_text: ustring; const selected_range: PCefRange);
procedure ChromiumEvent_OnTooltip(Sender: TObject; const browser: ICefBrowser; var Text: ustring; out Result: boolean);
procedure ChromiumEvent_OnTouchHandleStateChanged(Sender: TObject; const browser: ICefBrowser; const state: TCefTouchHandleState);
procedure ChromiumEvent_OnUpdateDragCursor(Sender: TObject; const browser: ICefBrowser; operation: TCefDragOperation);
procedure ChromiumEvent_OnVirtualKeyboardRequested(Sender: TObject; const browser: ICefBrowser; input_mode: TCefTextInpuMode);

procedure ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; user_gesture, isRedirect: Boolean; out Result: Boolean);
procedure ChromiumEvent_OnAddressChange(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);
procedure ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
procedure ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
procedure ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: Integer; eventFlags: Cardinal; out Result: Boolean);
procedure ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);
procedure ChromiumEvent_OnKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out Result: boolean);
procedure ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
procedure ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
procedure ChromiumEvent_OnLoadingProgressChange(Sender: TObject; const browser: ICefBrowser; const progress: double);
procedure ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
procedure ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
procedure ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
procedure ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);
procedure ChromiumEvent_OnZoomPctAvailable(Sender: TObject; const aZoomPct: double);
procedure ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);
procedure ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var extra_info: ICefDictionaryValue; var noJavascriptAccess: Boolean;  var Result: Boolean);
procedure ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);
procedure ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);
procedure ChromiumEvent_OnRenderCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnWidgetCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnBrowserCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
procedure ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
procedure ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);
procedure ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);
procedure ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);
procedure ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);
procedure ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefCallback; out Result: TCefReturnValue);
procedure ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: boolean);
procedure ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var newUrl: ustring);
procedure ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);
procedure ChromiumEvent_OnCookieSet(Sender: TObject; aSuccess: boolean; aID: integer);
procedure ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
procedure ChromiumEvent_OnCookiesFlushed(Sender: TObject);
procedure ChromiumEvent_OnCookiesVisited(Sender: TObject; const name_, value, domain, path: ustring; secure, httponly, hasExpires: Boolean; const creation, lastAccess, expires: TDateTime; count, total, aID: Integer; same_site: TCefCookieSameSite; priority: Integer; var aDeleteCookie, aResult: Boolean);
procedure ChromiumEvent_OnCookieVisitorDestroyed(Sender: TObject; aID: integer);
procedure ChromiumEvent_OnFrameAttached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
procedure ChromiumEvent_OnFrameCreated(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnFrameDetached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
procedure ChromiumEvent_OnMainFrameChanged(Sender: TObject; const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);
procedure ChromiumEvent_OnDragEnter(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations; out Result: Boolean);
procedure ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; regionsCount: NativeUInt; const regions: PCefDraggableRegionArray);
procedure ChromiumEvent_OnGetAuthCredentials(Sender: TObject; const browser: ICefBrowser; const originUrl: ustring; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback; out Result: Boolean);
procedure ChromiumEvent_OnExtensionBeforeBackgroundBrowser(Sender: TObject; const extension: ICefExtension; const url: ustring; var client: ICefClient; var settings: TCefBrowserSettings; var aResult: boolean);
procedure ChromiumEvent_OnExtensionBeforeBrowser(Sender: TObject; const extension: ICefExtension; const browser, active_browser: ICefBrowser; index: integer; const url: ustring; active: boolean; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var aResult: boolean);
procedure ChromiumEvent_OnExtensionCanAccessBrowser(Sender: TObject; const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; const target_browser: ICefBrowser; var aResult: boolean);
procedure ChromiumEvent_OnExtensionGetActiveBrowser(Sender: TObject; const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; var aRsltBrowser: ICefBrowser);
procedure ChromiumEvent_OnExtensionGetExtensionResource(Sender: TObject; const extension: ICefExtension; const browser: ICefBrowser; const file_: ustring; const callback: ICefGetExtensionResourceCallback; var aResult: boolean);
procedure ChromiumEvent_OnExtensionLoaded(Sender: TObject; const extension: ICefExtension);
procedure ChromiumEvent_OnExtensionLoadFailed(Sender: TObject; Result: TCefErrorcode);
procedure ChromiumEvent_OnExtensionUnloaded(Sender: TObject; const extension: ICefExtension);
procedure ChromiumEvent_OnPrintStart(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnPrintSettings(Sender: TObject; const browser: ICefBrowser; const settings: ICefPrintSettings; getDefaults: boolean);
procedure ChromiumEvent_OnPrintDialog(Sender: TObject; const browser: ICefBrowser; hasSelection: boolean; const callback: ICefPrintDialogCallback; var aResult : boolean);
procedure ChromiumEvent_OnPrintJob(Sender: TObject; const browser: ICefBrowser; const documentName, PDFFilePath: ustring; const callback: ICefPrintJobCallback; var aResult : boolean);
procedure ChromiumEvent_OnPrintReset(Sender: TObject; const browser: ICefBrowser);
procedure ChromiumEvent_OnGetPDFPaperSize(Sender: TObject; const browser: ICefBrowser; deviceUnitsPerInch: Integer; var aResult : TCefSize);

{== window parent ==}
procedure CEFWindowEvent_OnEnter(Sender: TObject);
procedure CEFWindowEvent_OnExit(Sender: TObject);

{== CEFWindowComponent ==}
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

{==TBufferPanel==}
{$IFDEF MSWINDOWS}
procedure BufferPanel_OnIMECancelComposition(Sender: TObject);
procedure BufferPanel_OnIMECommitText(Sender: TObject; const aText : ustring; const replacement_range : PCefRange; relative_cursor_pos : integer);
procedure BufferPanel_OnIMESetComposition(Sender: TObject; const aText : ustring; const underlines : TCefCompositionUnderlineDynArray; const replacement_range, selection_range : TCefRange);
procedure BufferPanel_OnCustomTouch(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
procedure BufferPanel_OnPointerDown(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
procedure BufferPanel_OnPointerUp(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
procedure BufferPanel_OnPointerUpdate(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
{$ENDIF}
procedure BufferPanel_OnPaintParentBkg(Sender: TObject);

{==TCEFViewComponent==}
procedure ViewComponent_OnGetPreferredSize(const Sender: TObject; const view: ICefView; var aResult : TCefSize);
procedure ViewComponent_OnGetMinimumSize(const Sender: TObject; const view: ICefView; var aResult : TCefSize);
procedure ViewComponent_OnGetMaximumSize(const Sender: TObject; const view: ICefView; var aResult : TCefSize);
procedure ViewComponent_OnGetHeightForWidth(const Sender: TObject; const view: ICefView; width: Integer; var aResult: Integer);
procedure ViewComponent_OnParentViewChanged(const Sender: TObject; const view: ICefView; added: boolean; const parent: ICefView);
procedure ViewComponent_OnChildViewChanged(const Sender: TObject; const view: ICefView; added: boolean; const child: ICefView);
procedure ViewComponent_OnWindowChanged(const Sender: TObject; const view: ICefView; added: boolean);
procedure ViewComponent_OnLayoutChanged(const Sender: TObject; const view: ICefView; new_bounds: TCefRect);
procedure ViewComponent_OnFocus(const Sender: TObject; const view: ICefView);
procedure ViewComponent_OnBlur(const Sender: TObject; const view: ICefView);

{==TCEFButtonComponent==}
procedure ButtonComponent_OnButtonPressed(const Sender: TObject; const button: ICefButton);
procedure ButtonComponent_OnButtonStateChanged(const Sender: TObject; const button: ICefButton);

{==TCEFMenuButtonComponent==}
procedure MenuButtonComponent_OnMenuButtonPressed(const Sender: TObject; const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock);

{==TCEFTextfieldComponent==}
procedure TextfieldComponent_OnTextfieldKeyEvent(const Sender: TObject; const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult : boolean);
procedure TextfieldComponent_OnAfterUserAction(const Sender: TObject; const textfield: ICefTextfield);

// TTask
procedure Task_OnExecute();
