//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== chromium ==}
procedure TLCLEvent.ChromiumEvent_OnAcceleratedPaint(Sender: TObject; const browser: ICefBrowser; type_: TCefPaintElementType; dirtyRectsCount: NativeUInt; const dirtyRects: PCefRectArray; shared_handle: Pointer);
var
  TempPaintInfo: TCefAcceleratedPaintInfo;
begin
  TempPaintInfo.shared_texture_handle := shared_handle;
  TempPaintInfo.format := nil;
  SendEvent([Sender, browser, type_, @dirtyRectsCount, dirtyRects, @TempPaintInfo]);
end;

procedure TLCLEvent.ChromiumEvent_OnAllConnectionsClosed(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.ChromiumEvent_OnAudioStreamError(Sender: TObject; const browser: ICefBrowser; const message_: ustring);
begin
  SendEvent([Sender, browser, PChar(string(message_))]);
end;

procedure TLCLEvent.ChromiumEvent_OnAudioStreamPacket(Sender: TObject; const browser: ICefBrowser; const Data: PPSingle; frames: integer; pts: int64);
begin
  SendEvent([Sender, browser, Data, frames, pts]);
end;

procedure TLCLEvent.ChromiumEvent_OnAudioStreamStarted(Sender: TObject; const browser: ICefBrowser; const params: TCefAudioParameters; channels: integer);
begin
  SendEvent([Sender, browser, @params, channels]);
end;

procedure TLCLEvent.ChromiumEvent_OnAudioStreamStopped(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnAutoResize(Sender: TObject; const browser: ICefBrowser; const new_size: PCefSize; out Result: boolean);
begin
  SendEvent([Sender, browser, new_size, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeUnloadDialog(Sender: TObject; const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback; out Result: boolean);
begin
  SendEvent([Sender, browser, PChar(string(messageText)), isReload, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnCanSaveCookie(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const response: ICefResponse; const cookie: PCefCookie; var aResult: boolean);
var
  TempCookie: PMCefCookie;
begin
  TempCookie := InitCookie();
  TempCookie := CefCookieToGoCookie(cookie^);
  SendEvent([Sender, browser, frame, request, response, @TempCookie, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnCanSendCookie(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const cookie: PCefCookie; var aResult: boolean);
var
  TempCookie: PMCefCookie;
begin
  TempCookie := InitCookie();
  TempCookie := CefCookieToGoCookie(cookie^);
  SendEvent([Sender, browser, frame, request, @TempCookie, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnCertificateError(Sender: TObject; const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefRequestCallback; out Result: Boolean);
begin
  SendEvent([Sender, browser, certError, PChar(string(requestUrl)), sslInfo, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnCertificateExceptionsCleared(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.ChromiumEvent_OnConsoleMessage(Sender: TObject; const browser: ICefBrowser; level: TCefLogSeverity; const message, Source: ustring; line: integer; out Result: boolean);
begin
  SendEvent([Sender, browser, level, PChar(string(message)), PChar(string(Source)), line, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnCursorChange(Sender: TObject; const browser: ICefBrowser; cursor_: TCefCursorHandle; cursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo; var aResult: boolean);
begin
  SendEvent([Sender, browser, cursor_, CursorType, customCursorInfo, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsAgentAttached(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsAgentDetached(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsEvent(Sender: TObject; const browser: ICefBrowser; const method: ustring; const params: ICefValue);
begin
  SendEvent([Sender, browser, PChar(string(method)), params]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsMessage(Sender: TObject; const browser: ICefBrowser; const message_: ICefValue; var aHandled: boolean);
begin
  SendEvent([Sender, browser, message_, @aHandled]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsMethodRawResult(Sender: TObject; const browser: ICefBrowser; message_id: integer; success: boolean; const Result: Pointer; result_size: nativeuint);
begin
  SendEvent([Sender, browser, message_id, success, Result, @result_size]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsMethodResult(Sender: TObject; const browser: ICefBrowser; message_id: integer; success: boolean; const Result: ICefValue);
begin
  SendEvent([Sender, browser, message_id, success, Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsRawEvent(Sender: TObject; const browser: ICefBrowser; const method: ustring; const params: Pointer; params_size: nativeuint);
begin
  SendEvent([Sender, browser, PChar(string(method)), params, @params_size]);
end;

procedure TLCLEvent.ChromiumEvent_OnDevToolsRawMessage(Sender: TObject; const browser: ICefBrowser; const message_: Pointer; message_size: nativeuint; var aHandled: boolean);
begin
  SendEvent([Sender, browser, message_, @message_size, @aHandled]);
end;

procedure TLCLEvent.ChromiumEvent_OnDialogClosed(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnDocumentAvailableInMainFrame(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnDownloadImageFinished(Sender: TObject; const imageUrl: ustring; httpStatusCode: integer; const image: ICefImage);
begin
  SendEvent([Sender, PChar(string(imageUrl)), httpStatusCode, image]);
end;

procedure TLCLEvent.ChromiumEvent_OnExecuteTaskOnCefThread(Sender: TObject; aTaskID: cardinal);
begin
  SendEvent([Sender, aTaskID]);
end;

procedure TLCLEvent.ChromiumEvent_OnFavIconUrlChange(Sender: TObject; const browser: ICefBrowser; const iconUrls: TStrings);
begin
  SendEvent([Sender, browser, iconUrls]);
end;

procedure TLCLEvent.ChromiumEvent_OnFileDialog(Sender: TObject; const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; selectedAcceptFilter: Integer; const callback: ICefFileDialogCallback; out Result: Boolean);
begin
  SendEvent([Sender, browser, mode, ToPchar(title), ToPchar(defaultFilePath), acceptFilters, Pointer(nil), Pointer(nil), callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetAccessibilityHandler(Sender: TObject; var aAccessibilityHandler: ICefAccessibilityHandler);
begin
  SendEvent([Sender, @aAccessibilityHandler]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetAudioParameters(Sender: TObject; const browser: ICefBrowser; var params: TCefAudioParameters; var aResult: boolean);
begin
  SendEvent([Sender, browser, @params, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetResourceHandler(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aResourceHandler: ICefResourceHandler);
begin
  SendEvent([Sender, browser, frame, request, @aResourceHandler]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetResourceRequestHandler_ReqCtxHdlr(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aExternalResourceRequestHandler: ICefResourceRequestHandler);
begin
  SendEvent([Sender, browser, frame, request, is_navigation, is_download, PChar(string(request_initiator)), @disable_default_handling, @aExternalResourceRequestHandler]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetResourceRequestHandler_ReqHdlr(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aExternalResourceRequestHandler: ICefResourceRequestHandler);
begin
  SendEvent([Sender, browser, frame, request, is_navigation, is_download, PChar(string(request_initiator)), @disable_default_handling, @aExternalResourceRequestHandler]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetResourceResponseFilter(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: ICefResponseFilter);
begin
  SendEvent([Sender, browser, frame, request, response, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetRootScreenRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect; out Result: boolean);
begin
  SendEvent([Sender, browser, @rect, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetScreenInfo(Sender: TObject; const browser: ICefBrowser; var screenInfo: TCefScreenInfo; out Result: boolean);
begin
  SendEvent([Sender, browser, @screenInfo, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetScreenPoint(Sender: TObject; const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer; out Result: boolean);
begin
  SendEvent([Sender, browser, viewX, viewY, @screenX, @screenY, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetViewRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect);
begin
  SendEvent([Sender, browser, @rect]);
end;

procedure TLCLEvent.ChromiumEvent_OnGotFocus(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnHttpAuthCredentialsCleared(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.ChromiumEvent_OnIMECompositionRangeChanged(Sender: TObject; const browser: ICefBrowser; const selected_range: PCefRange; character_boundsCount: nativeuint;
  const character_bounds: PCefRect);
begin
  SendEvent([Sender, browser, selected_range, @character_boundsCount, character_bounds]);
end;

procedure TLCLEvent.ChromiumEvent_OnJsDialog(Sender: TObject; const browser: ICefBrowser; const originUrl: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: boolean; out Result: boolean);
begin
  SendEvent([Sender, browser, PChar(string(originUrl)), integer(dialogType), PChar(string(messageText)), PChar(string(defaultPromptText)), callback, @suppressMessage, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnMediaRouteCreateFinished(Sender: TObject; Result: TCefMediaRouterCreateResult; const error: ustring; const route: ICefMediaRoute);
begin
  SendEvent([Sender, integer(Result), PChar(string(error)), route]);
end;

procedure TLCLEvent.ChromiumEvent_OnMediaSinkDeviceInfo(Sender: TObject; const ip_address: ustring; port: integer; const model_name: ustring);
begin
  SendEvent([Sender, PChar(string(ip_address)), port, PChar(string(model_name))]);
end;

procedure TLCLEvent.ChromiumEvent_OnNavigationVisitorResultAvailable(Sender: TObject; const entry: ICefNavigationEntry; current: boolean; index, total: integer; var aResult: boolean);
begin
  SendEvent([Sender, entry, current, index, total, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnPaint(Sender: TObject; const browser: ICefBrowser; type_: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer);
begin
  SendEvent([Sender, browser, type_, @dirtyRectsCount, dirtyRects, buffer, Width, Height]);
end;

procedure TLCLEvent.ChromiumEvent_OnPopupShow(Sender: TObject; const browser: ICefBrowser; Show: boolean);
begin
  SendEvent([Sender, browser, Show]);
end;

procedure TLCLEvent.ChromiumEvent_OnPopupSize(Sender: TObject; const browser: ICefBrowser; const rect: PCefRect);
begin
  SendEvent([Sender, browser, rect]);
end;

procedure TLCLEvent.ChromiumEvent_OnPrefsAvailable(Sender: TObject; aResultOK: boolean);
begin
  SendEvent([Sender, aResultOK]);
end;

procedure TLCLEvent.ChromiumEvent_OnPreKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean; out Result: boolean);
begin
  SendEvent([Sender, browser, event, osEvent, @isKeyboardShortcut, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnProtocolExecution(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var allowOsExecution: boolean);
begin
  SendEvent([Sender, browser, frame, request, @allowOsExecution]);
end;

procedure TLCLEvent.ChromiumEvent_OnRequestContextInitialized(Sender: TObject; const request_context: ICefRequestContext);
begin
  SendEvent([Sender, request_context]);
end;

procedure TLCLEvent.ChromiumEvent_OnResetDialogState(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnResolvedHostAvailable(Sender: TObject; Result: TCefErrorCode; const resolvedIps: TStrings);
begin
  SendEvent([Sender, Integer(Result), resolvedIps]);
end;

procedure TLCLEvent.ChromiumEvent_OnRouteMessageReceived(Sender: TObject; const route: ICefMediaRoute; const message_: ustring);
begin
  SendEvent([Sender, route, PChar(string(message_))]);
end;

procedure TLCLEvent.ChromiumEvent_OnRoutes(Sender: TObject; const routes: TCefMediaRouteArray);
begin
  SendEvent([Sender, @routes, Length(routes)]);
end;

procedure TLCLEvent.ChromiumEvent_OnRouteStateChanged(Sender: TObject; const route: ICefMediaRoute; state: TCefMediaRouteConnectionState);
begin
  SendEvent([Sender, route, Integer(state)]);
end;

procedure TLCLEvent.ChromiumEvent_OnRunContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback; var aResult: boolean);
begin
  SendEvent([Sender, browser, frame, params, model, callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnSelectClientCertificate(Sender: TObject; const browser: ICefBrowser; isProxy: boolean; const host: ustring; port: integer; certificatesCount: nativeuint; const certificates: TCefX509CertificateArray; const callback: ICefSelectClientCertificateCallback; var aResult: boolean);
begin
  SendEvent([Sender, browser, isProxy, PChar(string(host)), port, @certificatesCount, @certificates, callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnSetFocus(Sender: TObject; const browser: ICefBrowser; Source: TCefFocusSource; out Result: boolean);
begin
  SendEvent([Sender, browser, integer(Source), @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnSinks(Sender: TObject; const sinks: TCefMediaSinkArray);
begin
  SendEvent([Sender, @sinks, Length(sinks)]);
end;

procedure TLCLEvent.ChromiumEvent_OnStartDragging(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer; out Result: boolean);
begin
  SendEvent([Sender, browser, dragData, allowedOps, x, y, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnStatusMessage(Sender: TObject; const browser: ICefBrowser; const Value: ustring);
begin
  SendEvent([Sender, browser, PChar(string(Value))]);
end;

procedure TLCLEvent.ChromiumEvent_OnTakeFocus(Sender: TObject; const browser: ICefBrowser; Next: boolean);
begin
  SendEvent([Sender, browser, Next]);
end;

procedure TLCLEvent.ChromiumEvent_OnTextResultAvailable(Sender: TObject; const aText: ustring);
begin
  SendEvent([Sender, PChar(string(aText))]);
end;

procedure TLCLEvent.ChromiumEvent_OnTextSelectionChanged(Sender: TObject; const browser: ICefBrowser; const selected_text: ustring; const selected_range: PCefRange);
begin
  SendEvent([Sender, browser, PChar(string(selected_text)), selected_range]);
end;

procedure TLCLEvent.ChromiumEvent_OnTooltip(Sender: TObject; const browser: ICefBrowser; var Text: ustring; out Result: boolean);
var
  PText: PChar;
begin
  PText := PChar(string(Text));
  SendEvent([Sender, browser, @PText, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnUpdateDragCursor(Sender: TObject; const browser: ICefBrowser; operation: TCefDragOperation);
begin
  SendEvent([Sender, browser, operation]);
end;

procedure TLCLEvent.ChromiumEvent_OnVirtualKeyboardRequested(Sender: TObject; const browser: ICefBrowser; input_mode: TCefTextInpuMode);
begin
  SendEvent([Sender, browser, input_mode]);
end;

procedure TLCLEvent.ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; user_gesture, isRedirect: Boolean; out Result: Boolean);
begin
  SendEvent([Sender, browser, frame, request, user_gesture, isRedirect, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnAddressChange(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);
begin
  SendEvent([Sender, browser, frame, PChar(string(url))]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
begin
  SendEvent([Sender, browser, @aAction]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
begin
  SendEvent([Sender, browser, frame, params, model]);
end;

procedure TLCLEvent.ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: Integer; eventFlags: TCefEventFlags; out Result: Boolean);
begin
  SendEvent([Sender, browser, frame, params, commandId, eventFlags, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
begin
  SendEvent([Sender, browser, frame]);
end;

procedure TLCLEvent.ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);
begin
  SendEvent([Sender, aResultOK]);
end;

procedure TLCLEvent.ChromiumEvent_OnKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out Result: boolean);
begin
  SendEvent([Sender, browser, event, osEvent, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
begin
  SendEvent([Sender, browser, frame, transitionType]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
begin
  SendEvent([Sender, browser, isLoading, canGoBack, canGoForward]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadingProgressChange(Sender: TObject; const browser: ICefBrowser; const progress: Double);
begin
  SendEvent([Sender, browser, @progress]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);
begin
  SendEvent([Sender, browser, frame, errorCode, PChar(string(errorText)), PChar(string(failedUrl))]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
begin
  SendEvent([Sender, browser, frame, httpStatusCode]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
var
  aResult: Boolean;
begin
  SendEvent([Sender, browser, downloadItem, PChar(string(suggestedName)), callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);
begin
  SendEvent([Sender, browser, downloadItem, callback]);
end;

procedure TLCLEvent.ChromiumEvent_OnZoomPctAvailable(Sender: TObject; const aZoomPct: Double);
begin
  SendEvent([Sender, @aZoomPct]);
end;

procedure TLCLEvent.ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);
begin
  SendEvent([Sender, browser, fullscreen]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl,
  targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings;
  var extra_info: ICefDictionaryValue; var noJavascriptAccess: Boolean;  var Result: Boolean);
var
  beforePopupInfo  : RBeforePopupInfo;
  rpopupFeatures   : PMCefPopupFeatures;
  rwindowInfo      : PMCefWindowInfo;
  rbrowserSettings : PMCefBrowserSettings;
  TempTargetDisposition: Integer;
begin
    //popup info
    beforePopupInfo.TargetUrl := PChar(string(targetUrl));
    beforePopupInfo.TargetFrameName := PChar(string(targetFrameName));
    TempTargetDisposition := Integer(targetDisposition);
    beforePopupInfo.TargetDisposition := PInteger(@TempTargetDisposition);
    beforePopupInfo.UserGesture := @userGesture;
    // popupFeatures
    rpopupFeatures := CefPopupFeaturesToGoCefPopupFeatures(popupFeatures);
    // windowInfo
    rwindowInfo := CefWindowInfoToGoCefWindowInfo(windowInfo);
    // settings
    rbrowserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
    //event
    SendEvent([Sender, browser, frame, @beforePopupInfo, @rpopupFeatures, @rwindowInfo, @client, @rbrowserSettings, @extra_info, @noJavascriptAccess, @Result]);
    windowInfo := GoCefWindowInfoToCefWindowInfo(rwindowInfo);
end;

procedure TLCLEvent.ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring;
  targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);
begin
  SendEvent([Sender, browser, frame, PChar(string(targetUrl)), Integer(targetDisposition), userGesture, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);
begin
  SendEvent([Sender, browser, PChar(string(title))]);
end;

procedure TLCLEvent.ChromiumEvent_OnRenderCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
var
  MessageResult: LRESULT;
begin
  MessageResult := aMessage.Result;
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;

procedure TLCLEvent.ChromiumEvent_OnWidgetCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
var
  MessageResult: LRESULT;
begin
  MessageResult := aMessage.Result;
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;

procedure TLCLEvent.ChromiumEvent_OnBrowserCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
var
  MessageResult: LRESULT;
begin
  MessageResult := aMessage.Result;
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;

procedure TLCLEvent.ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
begin
  SendEvent([Sender, browser, status, 0, PChar('')]);
end;

procedure TLCLEvent.ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);
begin
  SendEvent([Sender, browser, @x, @y]);
end;

procedure TLCLEvent.ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);
begin
  Result := False;
  SendEvent([Sender, browser, frame, sourceProcess, message, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);
begin
  SendEvent([Sender, browser, identifier, count, selectionRect, activeMatchOrdinal, finalUpdate]);
end;

procedure TLCLEvent.ChromiumEvent_OnCookieSet(Sender: TObject; aSuccess: boolean; aID: integer);
begin
  SendEvent([Sender, aSuccess, aID]);
end;

procedure TLCLEvent.ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
begin
  SendEvent([Sender, numDeleted]);
end;

procedure TLCLEvent.ChromiumEvent_OnCookiesFlushed(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.ChromiumEvent_OnCookiesVisited(Sender: TObject;
  const name_, value, domain, path    : ustring;
  secure, httponly, hasExpires        : Boolean;
  const creation, lastAccess, expires : TDateTime;
  count, total, aID                   : Integer;
  same_site : TCefCookieSameSite; priority : TCefCookiePriority; var aDeleteCookie, aResult : Boolean);
var
  TempGoCookie: PMCefCookie;
begin
  TempGoCookie := InitCookie();
  TempGoCookie.name := ToPChar(name_);
  TempGoCookie.value := ToPChar(value);
  TempGoCookie.domain := ToPChar(domain);
  TempGoCookie.path := ToPChar(path);
  TempGoCookie.secure := PBoolean(@secure);
  TempGoCookie.httponly := PBoolean(@httponly);
  TempGoCookie.has_expires := PBoolean(@hasExpires);
  TempGoCookie.creation := PDouble(@creation);
  TempGoCookie.last_access := PDouble(@lastAccess);
  TempGoCookie.expires := PDouble(@expires);
  TempGoCookie.same_site := PInteger(@same_site);
  TempGoCookie.priority := PInteger(@priority);
  TempGoCookie.Count := PInteger(@count);
  TempGoCookie.total := PInteger(@total);
  TempGoCookie.id := PInteger(@aID);
  SendEvent([Sender, @TempGoCookie, @aDeleteCookie, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnCookieVisitorDestroyed(Sender: TObject; aID: integer);
begin
  SendEvent([Sender, aID]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefRequestCallback; out Result: TCefReturnValue);
begin
  SendEvent([Sender, browser, frame, request, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: boolean);
begin
  SendEvent([Sender, browser, frame, request, response, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var newUrl: ustring);
var
  pNewUrl : PChar;
begin
  SendEvent([Sender, browser, frame, request, response, @pNewUrl]);
  newUrl := PCharToUStr(pNewUrl);
  pNewUrl := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);
begin
  SendEvent([Sender, browser, frame, request, response, @integer(status), @receivedContentLength]);
end;

procedure TLCLEvent.ChromiumEvent_OnDragEnter(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations; out Result: Boolean);
begin
  SendEvent([Sender, browser, dragData, mask, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; regionsCount: NativeUInt; const regions: PCefDraggableRegionArray);
begin
  SendEvent([Sender, browser, frame, @regionsCount, regions]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetAuthCredentials(Sender: TObject; const browser: ICefBrowser; const originUrl: ustring; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback; out Result: Boolean);
begin
  SendEvent([Sender, browser, PChar(string(originUrl)), isProxy, PChar(string(host)), port, PChar(string(realm)), PChar(string(scheme)), callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnPrintStart(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnPrintSettings(Sender: TObject; const browser: ICefBrowser; const settings: ICefPrintSettings; getDefaults: boolean);
begin
  SendEvent([Sender, browser, settings, LongBool(getDefaults)]);
end;

procedure TLCLEvent.ChromiumEvent_OnPrintDialog(Sender: TObject; const browser: ICefBrowser; hasSelection: boolean; const callback: ICefPrintDialogCallback; var aResult : boolean);
begin
  SendEvent([Sender, browser, LongBool(hasSelection), callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnPrintJob(Sender: TObject; const browser: ICefBrowser; const documentName, PDFFilePath: ustring; const callback: ICefPrintJobCallback; var aResult : boolean);
begin
  SendEvent([Sender,  browser, PChar(string(documentName)), PChar(string(PDFFilePath)), callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnPrintReset(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetPDFPaperSize(Sender: TObject; const browser: ICefBrowser; deviceUnitsPerInch: Integer; var aResult : TCefSize);
begin
  SendEvent([Sender, browser, deviceUnitsPerInch, @aResult]);
end;


{== window parent ==}
procedure TLCLEvent.CEFWindowEvent_OnEnter(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.CEFWindowEvent_OnExit(Sender: TObject);
begin
  SendEvent([Sender]);
end;

{== CEFWindowComponent ==}
procedure TLCLEvent.WindowComponent_OnWindowCreated(const Sender: TObject; const window: ICefWindow);
begin
  SendEvent([window]);
end;

procedure TLCLEvent.WindowComponent_OnWindowDestroyed(const Sender: TObject; const window: ICefWindow);
begin
  SendEvent([window]);
end;

procedure TLCLEvent.WindowComponent_OnGetParentWindow(const Sender: TObject; const window: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult : ICefWindow);
begin
  SendEvent([window, @is_menu, @can_activate_menu, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnGetInitialBounds(const Sender: TObject; const window: ICefWindow; var aResult : TCefRect);
begin
  SendEvent([window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnIsFrameless(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanResize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanMaximize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanMinimize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanClose(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnAccelerator(const Sender: TObject; const window: ICefWindow; command_id: Integer; var aResult : boolean);
begin
  SendEvent([window, command_id, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnKeyEvent(const Sender: TObject; const window: ICefWindow; const event: TCefKeyEvent; var aResult : boolean);
begin
  SendEvent([window, @event, @aResult]);
end;

{==CEFBrowserViewComponent==}
procedure TLCLEvent.BrowserViewComponent_OnBrowserCreated(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  SendEvent([browser_view, browser]);
end;

procedure TLCLEvent.BrowserViewComponent_OnBrowserDestroyed(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  SendEvent([browser_view, browser]);
end;

procedure TLCLEvent.BrowserViewComponent_OnGetDelegateForPopupBrowserView(const Sender: TObject; const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult : ICefBrowserViewDelegate);
var
  browserSettings: PMCefBrowserSettings;
begin
  browserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
  SendEvent([browser_view, @browserSettings, client, is_devtools, @aResult]);
end;

procedure TLCLEvent.BrowserViewComponent_OnPopupBrowserViewCreated(const Sender: TObject; const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult : boolean);
begin
  SendEvent([browser_view, popup_browser_view, is_devtools, @aResult]);
end;

{==TBufferPanel==}
{$IFDEF MSWINDOWS}
procedure TLCLEvent.BufferPanel_OnIMECancelComposition(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.BufferPanel_OnIMECommitText(Sender: TObject; const aText : ustring; const replacement_range : PCefRange; relative_cursor_pos : integer);
begin
  SendEvent([Sender, PChar(string(aText)), replacement_range, relative_cursor_pos]);
end;

procedure TLCLEvent.BufferPanel_OnIMESetComposition(Sender: TObject; const aText : ustring; const underlines : TCefCompositionUnderlineDynArray;
  const replacement_range, selection_range : TCefRange);
begin
  SendEvent([Sender, ToPChar(aText), @underlines, Integer(Length(underlines)), @replacement_range, @selection_range]);
end;

procedure TLCLEvent.BufferPanel_OnCustomTouch(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
var
  MessageResult: LRESULT;
begin
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;

procedure TLCLEvent.BufferPanel_OnPointerDown(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
var
  MessageResult: LRESULT;
begin
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;

procedure TLCLEvent.BufferPanel_OnPointerUp(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
var
  MessageResult: LRESULT;
begin
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;

procedure TLCLEvent.BufferPanel_OnPointerUpdate(Sender: TObject; var aMessage: TMessage; var aHandled : boolean);
var
  MessageResult: LRESULT;
begin
  SendEvent([Sender, @aMessage, @MessageResult, @aHandled]);
  if MessageResult > 0 then
  begin
  aMessage.Result := MessageResult;
  end;
end;
{$ENDIF}

procedure TLCLEvent.BufferPanel_OnPaintParentBkg(Sender: TObject);
begin
  SendEvent([Sender]);
end;

{==TCEFViewComponent==}
procedure TLCLEvent.ViewComponent_OnGetPreferredSize(const Sender: TObject; const view: ICefView; var aResult : TCefSize);
begin
  SendEvent([view, @aResult]);
end;

procedure TLCLEvent.ViewComponent_OnGetMinimumSize(const Sender: TObject; const view: ICefView; var aResult : TCefSize);
begin
  SendEvent([view, @aResult]);
end;

procedure TLCLEvent.ViewComponent_OnGetMaximumSize(const Sender: TObject; const view: ICefView; var aResult : TCefSize);
begin
  SendEvent([view, @aResult]);
end;

procedure TLCLEvent.ViewComponent_OnGetHeightForWidth(const Sender: TObject; const view: ICefView; width: Integer; var aResult: Integer);
begin
  SendEvent([view, width, @aResult]);
end;

procedure TLCLEvent.ViewComponent_OnParentViewChanged(const Sender: TObject; const view: ICefView; added: boolean; const parent: ICefView);
begin
  SendEvent([view, added, parent]);
end;

procedure TLCLEvent.ViewComponent_OnChildViewChanged(const Sender: TObject; const view: ICefView; added: boolean; const child: ICefView);
begin
  SendEvent([view, added, child]);
end;

procedure TLCLEvent.ViewComponent_OnFocus(const Sender: TObject; const view: ICefView);
begin
  SendEvent([view]);
end;

procedure TLCLEvent.ViewComponent_OnBlur(const Sender: TObject; const view: ICefView);
begin
  SendEvent([view]);
end;

procedure TLCLEvent.ViewComponent_OnThemeChanged(const Sender: TObject; const view: ICefView);
begin
  SendEvent([view]);
end;

{==TCEFButtonComponent==}
procedure TLCLEvent.ButtonComponent_OnButtonPressed(const Sender: TObject; const button: ICefButton);
begin
  SendEvent([button]);
end;

procedure TLCLEvent.ButtonComponent_OnButtonStateChanged(const Sender: TObject; const button: ICefButton);
begin
  SendEvent([button]);
end;

{==TCEFMenuButtonComponent==}
procedure TLCLEvent.MenuButtonComponent_OnMenuButtonPressed(const Sender: TObject; const menu_button: ICefMenuButton; const screen_point: TCefPoint; const button_pressed_lock: ICefMenuButtonPressedLock);
begin
  SendEvent([menu_button, @screen_point, button_pressed_lock]);
end;

{==TCEFTextfieldComponent==}
procedure TLCLEvent.TextfieldComponent_OnTextfieldKeyEvent(const Sender: TObject; const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult : boolean);
begin
  SendEvent([textfield, @event, @aResult]);
end;

procedure TLCLEvent.TextfieldComponent_OnAfterUserAction(const Sender: TObject; const textfield: ICefTextfield);
begin
  SendEvent([textfield]);
end;

// TTask
procedure TLCLEvent.Task_OnExecute();
begin
  SendEvent([]);
end;
