//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== chromium ==}
procedure TLCLEvent.ChromiumEvent_OnBeforeUnloadDialog(Sender: TObject; const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback; out Result: boolean);
begin
  SendEvent([Sender, browser, PChar(string(messageText)), isReload, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnCertificateError(Sender: TObject; const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefRequestCallback; out Result: Boolean);
begin
  SendEvent([Sender, browser, certError, PChar(string(requestUrl)), sslInfo, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnConsoleMessage(Sender: TObject; const browser: ICefBrowser; const message, source: ustring; line: Integer; out Result: Boolean);
begin
  SendEvent([Sender, browser, 0, PChar(string(message)), PChar(string(Source)), line, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnCursorChange(Sender: TObject; const browser: ICefBrowser; cursor: TCefCursorHandle; cursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo);
var
  Result: Boolean;
begin
  SendEvent([Sender, browser, cursor, cursorType, customCursorInfo, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnDialogClosed(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
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
  SendEvent([Sender, browser, mode, PChar(string(title)), PChar(string(defaultFilePath)), acceptFilters, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetAccessibilityHandler(Sender: TObject; var aAccessibilityHandler: ICefAccessibilityHandler);
begin
  SendEvent([Sender, @aAccessibilityHandler]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetResourceHandler(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; out Result: ICefResourceHandler);
begin
  SendEvent([Sender, browser, frame, request, @Result]);
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

procedure TLCLEvent.ChromiumEvent_OnGetViewRect(Sender: TObject; const browser: ICefBrowser; var rect: TCefRect; out Result: Boolean);
begin
  SendEvent([Sender, browser, @rect]);
end;

procedure TLCLEvent.ChromiumEvent_OnGotFocus(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnJsDialog(Sender: TObject; const browser: ICefBrowser; const originUrl, accept_lang: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: Boolean; out Result: Boolean);
begin
  SendEvent([Sender, browser, PChar(string(originUrl)), integer(dialogType), PChar(string(messageText)), PChar(string(defaultPromptText)), callback, @suppressMessage, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnPaint(Sender: TObject; const browser: ICefBrowser; type_: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer);
begin
  SendEvent([Sender, browser, type_, uint32(dirtyRectsCount), dirtyRects, buffer, Width, Height]);
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

procedure TLCLEvent.ChromiumEvent_OnPrefsUpdated(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.ChromiumEvent_OnPreKeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean; out Result: boolean);
begin
  SendEvent([Sender, browser, event, osEvent, @isKeyboardShortcut, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnProtocolExecution(Sender: TObject; const browser: ICefBrowser; const url: ustring; out allowOsExecution: Boolean);
begin
  SendEvent([Sender, browser, browser.MainFrame, Pointer(0), @allowOsExecution]);
end;

procedure TLCLEvent.ChromiumEvent_OnQuickMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; command_id: integer; event_flags: TCefEventFlags; var aResult: boolean);
begin
  SendEvent([Sender, browser, frame, command_id, event_flags, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnResetDialogState(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnRunContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback; var aResult: boolean);
begin
  SendEvent([Sender, browser, frame, params, model, callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnSetFocus(Sender: TObject; const browser: ICefBrowser; Source: TCefFocusSource; out Result: boolean);
begin
  SendEvent([Sender, browser, integer(Source), @Result]);
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

procedure TLCLEvent.ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; isRedirect: Boolean; out Result: Boolean);
begin
  SendEvent([Sender, browser, frame, request, false, isRedirect, @Result]);
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

procedure TLCLEvent.ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: Integer; eventFlags: Cardinal; out Result: Boolean);
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

procedure TLCLEvent.ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
begin
  SendEvent([Sender, browser, frame, 0]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
begin
  SendEvent([Sender, browser, isLoading, canGoBack, canGoForward]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
begin
  SendEvent([Sender, browser, frame, errorCode, PChar(string(errorText)), PChar(string(failedUrl))]);
end;

procedure TLCLEvent.ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
begin
  SendEvent([Sender, browser, frame, httpStatusCode]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
begin
  SendEvent([Sender, browser, downloadItem, PChar(string(suggestedName)), callback]);
end;

procedure TLCLEvent.ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);
begin
  SendEvent([Sender, browser, downloadItem, callback]);
end;

procedure TLCLEvent.ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);
begin
  SendEvent([Sender, browser, fullscreen]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition;
  userGesture: Boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: Boolean; var Result: Boolean);
var
  beforePopupInfo: RBeforePopupInfo;
  browserSettings: RCefBrowserSettings;
begin
  //try
    //popup info
    //beforePopupInfo := PRBeforePopupInfo;
    beforePopupInfo.TargetUrl := PChar(string(targetUrl));
    beforePopupInfo.TargetFrameName := PChar(string(targetFrameName));
    beforePopupInfo.TargetDisposition := PInteger(Integer(targetDisposition));
    beforePopupInfo.UserGesture := @userGesture;
    // settings
    browserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
    //event
    //WriteLn('pas= size 1 ', browserSettings.size^, ' windowless_frame_rate: ', browserSettings.windowless_frame_rate^, ' standard_font_family: ', string(browserSettings.standard_font_family));
    SendEvent([Sender, browser, frame, @beforePopupInfo, @windowInfo, client, @browserSettings, Pointer(0), @noJavascriptAccess, @Result]);
    //WriteLn('pas= size 2 ', browserSettings.size^, ' windowless_frame_rate: ', browserSettings.windowless_frame_rate^, ' standard_font_family: ', string(browserSettings.standard_font_family));
    settings := GoBrowserSettingsToCefBrowserSettings(browserSettings);
  //finally
    //free beforePopupInfo
    //beforePopupInfo := nil;
    //browserSettings := nil;
  //end;
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
  SendEvent([Sender, browser, status]);
end;

procedure TLCLEvent.ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser]);
end;

procedure TLCLEvent.ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);
begin
  SendEvent([Sender, browser, @x, @y]);
end;

procedure TLCLEvent.ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);
begin
  Result := False;
  SendEvent([Sender, browser, browser.MainFrame, sourceProcess, message, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);
begin
  SendEvent([Sender, browser, identifier, count, selectionRect, activeMatchOrdinal, finalUpdate]);
end;

procedure TLCLEvent.ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
begin
  SendEvent([Sender, numDeleted]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefRequestCallback; out Result: TCefReturnValue);
begin
  SendEvent([Sender, browser, frame, request, callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: boolean);
begin
  SendEvent([Sender, browser, frame, request, response, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var newUrl: ustring);
var
  pNewUrl : PChar;
begin
  SendEvent([Sender, browser, frame, request, Pointer(0), @pNewUrl]);
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

procedure TLCLEvent.ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; regionsCount: NativeUInt; regions: PCefDraggableRegionArray);
begin
  SendEvent([Sender, browser, browser.MainFrame, Integer(regionsCount), regions]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetAuthCredentials(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback; out Result: Boolean);
begin
  SendEvent([Sender, browser, PChar(string(frame.Url)), isProxy, PChar(string(host)), port, PChar(string(realm)), PChar(string(scheme)), callback, @Result]);
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
