//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== chromium ==}
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
  beforePopupInfo: PRBeforePopupInfo;
begin
  try
    //popup info
    beforePopupInfo := new(PRBeforePopupInfo);
    beforePopupInfo^.TargetUrl := PChar(string(targetUrl));
    beforePopupInfo^.TargetFrameName := PChar(string(targetFrameName));
    beforePopupInfo^.TargetDisposition := PInteger(Integer(targetDisposition));
    beforePopupInfo^.UserGesture := @userGesture;
    //event
    SendEvent([Sender, browser, frame, beforePopupInfo, @windowInfo, @client, @settings, @extra_info, @noJavascriptAccess, @Result]);
  finally
    //free beforePopupInfo
    beforePopupInfo^.TargetUrl := nil;
    beforePopupInfo^.TargetFrameName := nil;
    beforePopupInfo^.UserGesture := nil;
    beforePopupInfo := nil;
  end;
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

procedure TLCLEvent.ChromiumEvent_OnCookiesVisited(Sender: TObject; const name_, value, domain, path: ustring; secure, httponly, hasExpires: Boolean;
  const creation, lastAccess, expires: TDateTime; count, total, aID: Integer; same_site: TCefCookieSameSite; priority: Integer; var aDeleteCookie, aResult: Boolean);
var
  cookie: PRCefCookie;
begin
  cookie := new(PRCefCookie);
  cookie^.url := PChar('');
  cookie^.Name := PChar(string(name_));
  cookie^.Value := PChar(string(value));
  cookie^.domain := PChar(string(domain));
  cookie^.path := PChar(string(path));
  cookie^.secure := @secure;
  cookie^.httponly := @httponly;
  cookie^.hasExpires := @hasExpires;
  cookie^.creation := @creation;
  cookie^.lastAccess := @lastAccess;
  cookie^.expires := @expires;
  cookie^.Count := PInteger(count);
  cookie^.total := PInteger(total);
  cookie^.aID := PInteger(aID);
  cookie^.sameSite := PInteger(integer(same_site));
  cookie^.priority := PInteger(priority);
  cookie^.aSetImmediately := @aResult;
  cookie^.aDeleteCookie := @aDeleteCookie;
  cookie^.Result := @aResult;
  SendEvent([Sender, cookie]);
  cookie := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnCookieVisitorDestroyed(Sender: TObject; aID: integer);
begin
  SendEvent([Sender, aID]);
end;

procedure TLCLEvent.ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefCallback; out Result: TCefReturnValue);
var
  rCefRequest: PRICefRequest;
  identifier: UInt64;
begin
  rCefRequest := new(PRICefRequest);
  rCefRequest^.Instance := @request;
  rCefRequest^.Url := PChar(string(request.Url));
  rCefRequest^.Method := PChar(string(request.Method));
  rCefRequest^.ReferrerUrl := PChar(string(request.ReferrerUrl));
  rCefRequest^.ReferrerPolicy := pinteger(integer(request.ReferrerPolicy));
  rCefRequest^.Flags := PCardinal(request.Flags);
  rCefRequest^.FirstPartyForCookies := PChar(string(request.FirstPartyForCookies));
  rCefRequest^.ResourceType := pinteger(integer(request.ResourceType));
  rCefRequest^.TransitionType := PCardinal(request.TransitionType);
  identifier := request.Identifier;
  rCefRequest^.Identifier := @identifier;

  SendEvent([Sender, browser, frame, rCefRequest, callback, @Result]);

  rCefRequest := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; out Result: boolean);
var
  rCefRequest: PRICefRequest;
  rCefResponse: PRICefResponse;
  identifier: UInt64;
begin
  //request
  rCefRequest := new(PRICefRequest);
  rCefRequest^.Instance := @request;
  rCefRequest^.Url := PChar(string(request.Url));
  rCefRequest^.Method := PChar(string(request.Method));
  rCefRequest^.ReferrerUrl := PChar(string(request.ReferrerUrl));
  rCefRequest^.ReferrerPolicy := pinteger(integer(request.ReferrerPolicy));
  rCefRequest^.Flags := PCardinal(request.Flags);
  rCefRequest^.FirstPartyForCookies := PChar(string(request.FirstPartyForCookies));
  rCefRequest^.ResourceType := pinteger(integer(request.ResourceType));
  rCefRequest^.TransitionType := PCardinal(request.TransitionType);
  identifier := request.Identifier;
  rCefRequest^.Identifier := @identifier;
  //response
  rCefResponse := new(PRICefResponse);
  rCefResponse^.Instance := @response;
  rCefResponse^.Status := pinteger(integer(response.Status));
  rCefResponse^.StatusText := PChar(string(response.StatusText));
  rCefResponse^.MimeType := PChar(string(response.MimeType));
  rCefResponse^.Charset := PChar(string(response.Charset));
  rCefResponse^.Error := pinteger(integer(response.Error));;
  rCefResponse^.URL := PChar(string(response.Url));

  SendEvent([Sender, browser, frame, rCefRequest, rCefResponse, @Result]);

  rCefRequest := nil;
  rCefResponse := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var newUrl: ustring);
var
  rCefRequest: PRICefRequest;
  rCefResponse: PRICefResponse;
  identifier: UInt64;
  pNewUrl : PChar;
begin
  //request
  rCefRequest := new(PRICefRequest);
  rCefRequest^.Instance := @request;
  rCefRequest^.Url := PChar(string(request.Url));
  rCefRequest^.Method := PChar(string(request.Method));
  rCefRequest^.ReferrerUrl := PChar(string(request.ReferrerUrl));
  rCefRequest^.ReferrerPolicy := pinteger(integer(request.ReferrerPolicy));
  rCefRequest^.Flags := PCardinal(request.Flags);
  rCefRequest^.FirstPartyForCookies := PChar(string(request.FirstPartyForCookies));
  rCefRequest^.ResourceType := pinteger(integer(request.ResourceType));
  rCefRequest^.TransitionType := PCardinal(request.TransitionType);
  identifier := request.Identifier;
  rCefRequest^.Identifier := @identifier;
  //response
  rCefResponse := new(PRICefResponse);
  rCefResponse^.Instance := @response;
  rCefResponse^.Status := pinteger(integer(response.Status));
  rCefResponse^.StatusText := PChar(string(response.StatusText));
  rCefResponse^.MimeType := PChar(string(response.MimeType));
  rCefResponse^.Charset := PChar(string(response.Charset));
  rCefResponse^.Error := pinteger(integer(response.Error));;
  rCefResponse^.URL := PChar(string(response.Url));

  SendEvent([Sender, browser, frame, rCefRequest, rCefResponse, @pNewUrl]);
  newUrl := PCharToUStr(pNewUrl);
  rCefRequest := nil;
  rCefResponse := nil;
end;


procedure TLCLEvent.ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);
var
  rCefRequest: PRICefRequest;
  rCefResponse: PRICefResponse;
  identifier: UInt64;
begin
  //request
  rCefRequest := new(PRICefRequest);
  rCefRequest^.Instance := @request;
  rCefRequest^.Url := PChar(string(request.Url));
  rCefRequest^.Method := PChar(string(request.Method));
  rCefRequest^.ReferrerUrl := PChar(string(request.ReferrerUrl));
  rCefRequest^.ReferrerPolicy := pinteger(integer(request.ReferrerPolicy));
  rCefRequest^.Flags := PCardinal(request.Flags);
  rCefRequest^.FirstPartyForCookies := PChar(string(request.FirstPartyForCookies));
  rCefRequest^.ResourceType := pinteger(integer(request.ResourceType));
  rCefRequest^.TransitionType := PCardinal(request.TransitionType);
  identifier := request.Identifier;
  rCefRequest^.Identifier := @identifier;
  //response
  rCefResponse := new(PRICefResponse);
  rCefResponse^.Instance := @response;
  rCefResponse^.Status := pinteger(integer(response.Status));
  rCefResponse^.StatusText := PChar(string(response.StatusText));
  rCefResponse^.MimeType := PChar(string(response.MimeType));
  rCefResponse^.Charset := PChar(string(response.Charset));
  rCefResponse^.Error := pinteger(integer(response.Error));;
  rCefResponse^.URL := PChar(string(response.Url));
  SendEvent([Sender, browser, frame, rCefRequest, rCefResponse, @integer(status), @receivedContentLength]);
  rCefRequest := nil;
  rCefResponse := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnFrameAttached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
begin
  SendEvent([Sender, browser, frame, reattached]);
end;

procedure TLCLEvent.ChromiumEvent_OnFrameCreated(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
begin
  SendEvent([Sender, browser, frame]);
end;

procedure TLCLEvent.ChromiumEvent_OnFrameDetached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
begin
  SendEvent([Sender, browser, frame]);
end;

procedure TLCLEvent.ChromiumEvent_OnMainFrameChanged(Sender: TObject; const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);
begin
  SendEvent([Sender, browser, old_frame, new_frame]);
end;

procedure TLCLEvent.ChromiumEvent_OnDragEnter(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations; out Result: Boolean);
begin
  SendEvent([Sender, browser, @dragData, mask, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; regionsCount: NativeUInt; const regions: PCefDraggableRegionArray);
begin
  SendEvent([Sender, browser, frame, Integer(regionsCount), regions]);
end;

procedure TLCLEvent.ChromiumEvent_OnGetAuthCredentials(Sender: TObject; const browser: ICefBrowser; const originUrl: ustring; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback; out Result: Boolean);
begin
   SendEvent([Sender, browser, PChar(string(originUrl)), isProxy, PChar(string(host)), port, PChar(string(realm)), PChar(string(scheme)), callback, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionBeforeBackgroundBrowser(Sender: TObject; const extension: ICefExtension; const url: ustring; var client: ICefClient; var settings: TCefBrowserSettings; var aResult: boolean);
begin
  SendEvent([extension, PChar(string(url)), @client, @settings, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionBeforeBrowser(Sender: TObject; const extension: ICefExtension; const browser, active_browser: ICefBrowser; index: integer; const url: ustring; active: boolean; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var aResult: boolean);
begin
  SendEvent([extension, browser, active_browser, index, PChar(string(url)), active, @windowInfo, @client, @settings, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionCanAccessBrowser(Sender: TObject; const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; const target_browser: ICefBrowser; var aResult: boolean);
begin
  SendEvent([extension, browser, include_incognito, target_browser, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionGetActiveBrowser(Sender: TObject; const extension: ICefExtension; const browser: ICefBrowser; include_incognito: boolean; var aRsltBrowser: ICefBrowser);
begin
  SendEvent([extension, browser, include_incognito, @aRsltBrowser]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionGetExtensionResource(Sender: TObject; const extension: ICefExtension; const browser: ICefBrowser; const file_: ustring; const callback: ICefGetExtensionResourceCallback; var aResult: boolean);
begin
  SendEvent([extension, browser, PChar(string(file_)), callback, @aResult]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionLoaded(Sender: TObject; const extension: ICefExtension);
begin
  SendEvent([extension]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionLoadFailed(Sender: TObject; Result: TCefErrorcode);
begin
  SendEvent([Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnExtensionUnloaded(Sender: TObject; const extension: ICefExtension);
begin
  SendEvent([extension]);
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
  SendEvent([Sender, window]);
end;

procedure TLCLEvent.WindowComponent_OnWindowDestroyed(const Sender: TObject; const window: ICefWindow);
begin
  SendEvent([Sender, window]);
end;

procedure TLCLEvent.WindowComponent_OnWindowActivationChanged(const Sender: TObject; const window: ICefWindow; active: boolean);
begin
  SendEvent([Sender, window, active]);
end;

procedure TLCLEvent.WindowComponent_OnGetParentWindow(const Sender: TObject; const window: ICefWindow; var is_menu, can_activate_menu: boolean; var aResult : ICefWindow);
begin
  SendEvent([Sender, window, @is_menu, @can_activate_menu, aResult]);
end;

procedure TLCLEvent.WindowComponent_OnGetInitialBounds(const Sender: TObject; const window: ICefWindow; var aResult : TCefRect);
var
  PRet : PRTCefRect;
begin
  PRet := new(PRTCefRect);
  SendEvent([Sender, window, PRet]);
  aResult.x := Integer(PRet^.x);
  aResult.y := Integer(PRet^.y);
  aResult.width := Integer(PRet^.width);
  aResult.height := Integer(PRet^.height);
  PRet := nil;
end;

procedure TLCLEvent.WindowComponent_OnGetInitialShowState(const Sender: TObject; const window: ICefWindow; var aResult : TCefShowState);
begin
  SendEvent([Sender, window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnIsFrameless(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([Sender, window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanResize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([Sender, window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanMaximize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([Sender, window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanMinimize(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([Sender, window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnCanClose(const Sender: TObject; const window: ICefWindow; var aResult : boolean);
begin
  SendEvent([Sender, window, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnAccelerator(const Sender: TObject; const window: ICefWindow; command_id: Integer; var aResult : boolean);
begin
  SendEvent([Sender, window, command_id, @aResult]);
end;

procedure TLCLEvent.WindowComponent_OnKeyEvent(const Sender: TObject; const window: ICefWindow; const event: TCefKeyEvent; var aResult : boolean);
begin
  SendEvent([Sender, window, @event, @aResult]);
end;

{==CEFBrowserViewComponent==}
procedure TLCLEvent.BrowserViewComponent_OnBrowserCreated(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser_view, browser]);
end;

procedure TLCLEvent.BrowserViewComponent_OnBrowserDestroyed(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser_view, browser]);
end;

procedure TLCLEvent.BrowserViewComponent_OnGetDelegateForPopupBrowserView(const Sender: TObject; const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult : ICefBrowserViewDelegate);
var
  browserSettings: PRCefBrowserSettings;
begin
  browserSettings := new(PRCefBrowserSettings);
  SendEvent([Sender, browser_view, browserSettings, client, is_devtools, @aResult]);
  browserSettings := nil;
end;

procedure TLCLEvent.BrowserViewComponent_OnPopupBrowserViewCreated(const Sender: TObject; const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult : boolean);
begin
  SendEvent([Sender, browser_view, popup_browser_view, is_devtools, @aResult]);
end;

procedure TLCLEvent.BrowserViewComponent_OnGetChromeToolbarType(const Sender: TObject; var aChromeToolbarType: TCefChromeToolbarType);
begin
  SendEvent([Sender, @aChromeToolbarType]);
end;

