//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== chromium ==}
//chromium 浏览器创建之后
procedure TLCLEvent.ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
begin
  //SendMessage(browser.Host.WindowHandle, WM_SETICON, 1, application.Icon.Handle);
  SendEvent([Sender, browser.Identifier]);
end;

//chromium 浏览器创建之前
procedure TLCLEvent.ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  const request: ICefRequest; user_gesture, isRedirect: Boolean; out Result: Boolean);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent([Sender, browser.Identifier, cefFrame, @Result]);
  FreePRCEFFrame(cefFrame);
end;

//chromium 地址改变
procedure TLCLEvent.ChromiumEvent_OnAddressChange(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame, PChar(string(url))]);
  FreePRCEFFrame(cefFrame);
end;

//chromium 关闭之前
procedure TLCLEvent.ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);
begin
  TMainChromiumBrowserClass.RemoveBrowser(browser.Identifier);
  SendEvent([Sender, browser.Identifier]);
end;

//chromium 关闭
procedure TLCLEvent.ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
begin
  SendEvent([Sender, browser.Identifier, @aAction]);
  if not SingleProcess then
  begin
    TObjectValueBindInfoClass.Clear;
    TCommonValueBindInfoClass.Clear;
  end;
end;

//chromium 右键菜单-before-开启
procedure TLCLEvent.ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  const params: ICefContextMenuParams; const model: ICefMenuModel);
var
  PParams : PRContextMenuParams;
  cefFrame: PRCEFFrame;
begin
  PParams := new(PRContextMenuParams);
  PParams^.XCoord := PInteger(params.XCoord);
  PParams^.YCoord := PInteger(params.YCoord);
  PParams^.TypeFlags := PCardinal(params.TypeFlags);
  PParams^.LinkUrl := PChar(string(params.LinkUrl));
  PParams^.UnfilteredLinkUrl := PChar(string(params.UnfilteredLinkUrl));
  PParams^.SourceUrl := PChar(string(params.SourceUrl));
  PParams^.TitleText := PChar(string(params.TitleText));
  PParams^.PageUrl := PChar(string(params.PageUrl));
  PParams^.FrameUrl := PChar(string(params.FrameUrl));
  PParams^.FrameCharset := PChar(string(params.FrameCharset));
  PParams^.MediaType := PInteger(integer(params.MediaType));
  PParams^.MediaStateFlags := PCardinal(params.MediaStateFlags);
  PParams^.SelectionText := PChar(string(params.SelectionText));
  PParams^.EditStateFlags := PCardinal(params.EditStateFlags);
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame, PParams, model]);
  PParams := nil;
  FreePRCEFFrame(cefFrame);
end;

//chromium 右键菜单-command-开启
procedure TLCLEvent.ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  const params: ICefContextMenuParams; commandId: Integer; eventFlags: Cardinal; out Result: Boolean);
var
  PParams : PRContextMenuParams;
  cefFrame: PRCEFFrame;
begin
  PParams := new(PRContextMenuParams);
  PParams^.XCoord := PInteger(params.XCoord);
  PParams^.YCoord := PInteger(params.YCoord);
  PParams^.TypeFlags := PCardinal(params.TypeFlags);
  PParams^.LinkUrl := PChar(string(params.LinkUrl));
  PParams^.UnfilteredLinkUrl := PChar(string(params.UnfilteredLinkUrl));
  PParams^.SourceUrl := PChar(string(params.SourceUrl));
  PParams^.TitleText := PChar(string(params.TitleText));
  PParams^.PageUrl := PChar(string(params.PageUrl));
  PParams^.FrameUrl := PChar(string(params.FrameUrl));
  PParams^.FrameCharset := PChar(string(params.FrameCharset));
  PParams^.MediaType := PInteger(integer(params.MediaType));
  PParams^.MediaStateFlags := PCardinal(params.MediaStateFlags);
  PParams^.SelectionText := PChar(string(params.SelectionText));
  PParams^.EditStateFlags := PCardinal(params.EditStateFlags);
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame, PParams, commandId, eventFlags, @Result]);
  PParams := nil;
end;

//chromium 右键菜单-Dismissed
procedure TLCLEvent.ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame]);
  FreePRCEFFrame(cefFrame);
end;

//chromium 导出PDF完成
procedure TLCLEvent.ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);
begin
  SendEvent([Sender, aResultOK]);
end;

//chromium 键盘
procedure TLCLEvent.ChromiumEvent_KeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle;
  out Result: boolean);
begin
  SendEvent([Sender, browser.Identifier, event, @Result]);
end;

//chromium 加载 start
procedure TLCLEvent.ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  transitionType: TCefTransitionType);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent([Sender, browser.Identifier, cefFrame]);
  FreePRCEFFrame(cefFrame);
end;

//chromium 加载 LoadingStateChange
procedure TLCLEvent.ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser;
  isLoading, canGoBack, canGoForward: boolean);
begin
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent([Sender, browser.Identifier, isLoading, canGoBack, canGoForward]);
end;

//chromium 加载 LoadingProgressChange
procedure TLCLEvent.ChromiumEvent_OnLoadingProgressChange(Sender: TObject; const browser: ICefBrowser; const progress: Double);
begin
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent([Sender, browser.Identifier, @progress]);
end;

//chromium 加载 LoadError
procedure TLCLEvent.ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame, errorCode, PChar(string(errorText)), PChar(string(failedUrl))]);
  FreePRCEFFrame(cefFrame);
end;

//chromium 加载 LoadEnd
procedure TLCLEvent.ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame, httpStatusCode]);
  FreePRCEFFrame(cefFrame);
end;

//chromium 下载之前
procedure TLCLEvent.ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem;
  const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
var
  downItem: PRDownloadItem;
  startTime, dndTime: double;
  isValid: boolean;
begin
  startTime := downloadItem.StartTime;
  dndTime := downloadItem.EndTime;
  downItem := new(PRDownloadItem);
  isValid := downloadItem.IsValid;
  downItem^.Id := PInteger(downloadItem.Id);
  downItem^.CurrentSpeed := PInt64(downloadItem.CurrentSpeed);
  downItem^.PercentComplete := PInteger(downloadItem.PercentComplete);
  downItem^.TotalBytes := PInt64(downloadItem.TotalBytes);
  downItem^.ReceivedBytes := PInt64(downloadItem.ReceivedBytes);
  downItem^.StartTime := @startTime;
  downItem^.EndTime := @dndTime;
  downItem^.FullPath := PChar(string(downloadItem.FullPath));
  downItem^.Url := PChar(string(downloadItem.Url));
  downItem^.OriginalUrl := PChar(string(downloadItem.OriginalUrl));
  downItem^.SuggestedFileName := PChar(string(downloadItem.SuggestedFileName));
  downItem^.ContentDisposition := PChar(string(downloadItem.ContentDisposition));
  downItem^.MimeType := PChar(string(downloadItem.MimeType));
  downItem^.IsValid := @isValid;
  downItem^.State := PInteger(-1);
  SendEvent([Sender, browser.Identifier, downItem, PChar(string(suggestedName)), callback]);
  downItem := nil;
end;

//chromium 下载更新
procedure TLCLEvent.ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem;
  const callback: ICefDownloadItemCallback);
var
  downItem: PRDownloadItem;
  startTime, dndTime: double;
  isValid: boolean;
begin
  startTime := downloadItem.StartTime;
  dndTime := downloadItem.EndTime;
  downItem := new(PRDownloadItem);
  isValid := downloadItem.IsValid;
  downItem^.Id := PInteger(downloadItem.Id);
  downItem^.CurrentSpeed := PInt64(downloadItem.CurrentSpeed);
  downItem^.PercentComplete := PInteger(downloadItem.PercentComplete);
  downItem^.TotalBytes := PInt64(downloadItem.TotalBytes);
  downItem^.ReceivedBytes := PInt64(downloadItem.ReceivedBytes);
  downItem^.StartTime := @startTime;
  downItem^.EndTime := @dndTime;
  downItem^.FullPath := PChar(string(downloadItem.FullPath));
  downItem^.Url := PChar(string(downloadItem.Url));
  downItem^.OriginalUrl := PChar(string(downloadItem.OriginalUrl));
  downItem^.SuggestedFileName := PChar(string(downloadItem.SuggestedFileName));
  downItem^.ContentDisposition := PChar(string(downloadItem.ContentDisposition));
  downItem^.MimeType := PChar(string(downloadItem.MimeType));
  downItem^.IsValid := @isValid;
  if downloadItem.IsComplete then //完成
  begin
     downItem^.State := PInteger(2);
     TMainChromiumBrowserClass.RemoveBrowserItemDownload(browser.Identifier, downloadItem.Id);
  end
  else if downloadItem.IsCanceled then//取消
  begin
     downItem^.State := PInteger(1);
     TMainChromiumBrowserClass.RemoveBrowserItemDownload(browser.Identifier, downloadItem.Id);
  end
  else if downloadItem.IsInProgress then//下载中
  begin
     downItem^.State := PInteger(0);
    //进度和接收都是0是第一次
    if (downloadItem.PercentComplete = 0) and (downloadItem.ReceivedBytes = 0) then
    begin
      TMainChromiumBrowserClass.PutBrowserDownloadItemCallback(browser.Identifier, downloadItem.Id, callback);
    end;
  end;
  SendEvent([Sender, browser.Identifier, downItem, callback]);
  downItem := nil;
end;

//chromium 放大缩小回调
procedure TLCLEvent.ChromiumEvent_OnZoomPctAvailable(Sender: TObject; const aZoomPct: Double);
begin
  SendEvent([Sender, @aZoomPct]);
end;

//chromium 全屏模式
procedure TLCLEvent.ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);
begin
  SendEvent([Sender, browser.Identifier, fullscreen]);
end;

//chromium 弹窗之前
procedure TLCLEvent.ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl,
  targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings;
  var extra_info: ICefDictionaryValue; var noJavascriptAccess: Boolean;  var Result: Boolean);
var
  cefFrame: PRCEFFrame;
  beforePopupInfo: PRBeforePopupInfo;
begin
  try
    //frame
    cefFrame := new(PRCEFFrame);
    cefFrame^.Name := PChar(string(frame.Name));
    cefFrame^.Url := PChar(string(frame.Url));
    cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));

    //popup info
    beforePopupInfo := new(PRBeforePopupInfo);
    beforePopupInfo^.TargetUrl := PChar(string(targetUrl));
    beforePopupInfo^.TargetFrameName := PChar(string(targetFrameName));
    beforePopupInfo^.TargetDisposition := PInteger(Integer(targetDisposition));
    beforePopupInfo^.UserGesture := @userGesture;

    //event
    SendEvent([Sender, browser.Identifier, cefFrame, beforePopupInfo, @windowInfo, client, @noJavascriptAccess, @Result]);
  finally
    //free beforePopupInfo
    beforePopupInfo^.TargetUrl := nil;
    beforePopupInfo^.TargetFrameName := nil;
    beforePopupInfo^.UserGesture := nil;
    beforePopupInfo := nil;
    //free frame
    FreePRCEFFrame(cefFrame);
  end;
end;

//chromium 打开tab
procedure TLCLEvent.ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring;
  targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);
begin
  if not boolean(GChromiumConfig.EnableOpenUrlTab) then //禁止弹新Tab
  begin
    // 阻止所有弹出窗口和新选项卡
     Result := (targetDisposition in [WOD_NEW_FOREGROUND_TAB, WOD_NEW_BACKGROUND_TAB, WOD_NEW_POPUP, WOD_NEW_WINDOW]);
     exit;
  end;
end;

//chromium 标题改变
procedure TLCLEvent.ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);
begin
  SendEvent([Sender, browser.Identifier, PChar(string(title))]);
end;

//chromium msg
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
  //WriteLn('RenderCompMsg aHandled ', aHandled ,' Result ' ,aMessage.Result);
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
  //WriteLn('WidgetCompMsg aHandled ',aHandled ,' Result ' ,aMessage.Result);
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

//chromium Render
procedure TLCLEvent.ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
begin
  SendEvent([Sender, browser.Identifier, status]);
end;

procedure TLCLEvent.ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser.Identifier]);
end;

//chromium 滚动条事件
procedure TLCLEvent.ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);
begin
  SendEvent([Sender, browser.Identifier, @x, @y]);
end;

//chromium 进程消息
procedure TLCLEvent.ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  sourceProcess: TCefProcessId; const message: ICefProcessMessage; out Result: Boolean);
var
  ret: boolean;
  processMessage: PRCEFProcessMessage;
  cefFrame: PRCEFFrame;
  binaryValue: ICefBinaryValue;
  binarySize: integer;
  binaryBuf: array of Byte;
begin
  ret := TCEFIPCClass.BrowserProcessReceivedMessage(browser, frame, sourceProcess, message);
  if not ret then
  begin
    processMessage := new(PRCEFProcessMessage);
    cefFrame := new(PRCEFFrame);
    cefFrame^.Name := PChar(string(frame.Name));
    cefFrame^.Url := PChar(string(frame.Url));
    cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
    binarySize := message.ArgumentList.GetInt(0);
    binaryValue := message.ArgumentList.GetBinary(2);
    SetLength(binaryBuf, binarySize);
    binaryValue.GetData(@binaryBuf[0], nativeuint(binarySize), 0);
    processMessage^.Name := PChar(string(message.Name));
    processMessage^.Data := @binaryBuf[0];
    processMessage^.DataLen := PInteger(binarySize);
    SendEvent([Sender, browser.Identifier, cefFrame, sourceProcess, processMessage, @Result]);
    SetLength(binaryBuf, 0);
    processMessage^.Data := nil;
    processMessage := nil;
    FreePRCEFFrame(cefFrame);
  end;
  Result := True;
end;

//chromium 查找结果回调
procedure TLCLEvent.ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);
begin
    SendEvent([Sender, browser.Identifier, identifier, count, selectionRect, activeMatchOrdinal, finalUpdate]);
end;

//chromium cookie
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

//chromium Resource 资源加载之前
procedure TLCLEvent.ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const callback: ICefCallback; out Result: TCefReturnValue);
var
  cefFrame: PRCEFFrame;
  rCefRequest: PRICefRequest;
  identifier: UInt64;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
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

  SendEvent([Sender, browser.Identifier, cefFrame, rCefRequest, callback, @Result]);

  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const response: ICefResponse; out Result: boolean);
var
  cefFrame: PRCEFFrame;
  rCefRequest: PRICefRequest;
  rCefResponse: PRICefResponse;
  identifier: UInt64;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
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

  SendEvent([Sender, browser.Identifier, cefFrame, rCefRequest, rCefResponse, @Result]);

  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
  rCefResponse := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
  const response: ICefResponse; var newUrl: ustring);
var
  cefFrame: PRCEFFrame;
  rCefRequest: PRICefRequest;
  rCefResponse: PRICefResponse;
  identifier: UInt64;
  pNewUrl : PChar;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
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

  SendEvent([Sender, browser.Identifier, cefFrame, rCefRequest, rCefResponse, @pNewUrl]);
  newUrl := PCharToUStr(pNewUrl);
  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
  rCefResponse := nil;
end;


procedure TLCLEvent.ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
  status: TCefUrlRequestStatus; receivedContentLength: Int64);
var
  cefFrame: PRCEFFrame;
  rCefRequest: PRICefRequest;
  rCefResponse: PRICefResponse;
  identifier: UInt64;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
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
  SendEvent([Sender, browser.Identifier, cefFrame, rCefRequest, rCefResponse, @integer(status), @receivedContentLength]);
  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
  rCefResponse := nil;
end;

{==chromium frame==}
procedure TLCLEvent.ChromiumEvent_OnFrameAttached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  if (frame <> nil) then
  begin
    cefFrame^.Name := PChar(string(frame.Name));
    cefFrame^.Url := PChar(string(frame.Url));
    cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  end
  else
  begin
    cefFrame^.Name := PChar('');
    cefFrame^.Url := PChar('');
    cefFrame^.Identifier := PChar('-1');
  end;
  SendEvent([Sender, browser.Identifier, cefFrame, reattached]);
  FreePRCEFFrame(cefFrame);
end;

procedure TLCLEvent.ChromiumEvent_OnFrameCreated(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
var
  cefFrame: PRCEFFrame;
  frameId, frameName, frameUrl: PChar;
begin
  frameId := PChar(UTF8Encode(IntToStr(frame.Identifier)));
  frameName := PChar(UTF8Encode(frame.Name));
  frameUrl := PChar(UTF8Encode(frame.Url));
  cefFrame := new(PRCEFFrame);
  cefFrame^.Identifier := frameId;
  cefFrame^.Name := frameName;
  cefFrame^.Url := frameUrl;
  if Assigned(cefFrame) then
  begin
    SendEvent([Sender, browser.Identifier, cefFrame]);
  end;
  frameId := nil;
  frameName := nil;
  frameUrl := nil;
  FreePRCEFFrame(cefFrame);
  cefFrame := nil;
end;

procedure TLCLEvent.ChromiumEvent_OnFrameDetached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  if (frame <> nil) then
  begin
    cefFrame^.Name := PChar(string(frame.Name));
    cefFrame^.Url := PChar(string(frame.Url));
    cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  end
  else
  begin
    cefFrame^.Name := PChar('');
    cefFrame^.Url := PChar('');
    cefFrame^.Identifier := PChar('-1');
  end;
  SendEvent([Sender, browser.Identifier, cefFrame]);
  FreePRCEFFrame(cefFrame);
end;

procedure TLCLEvent.ChromiumEvent_OnMainFrameChanged(Sender: TObject; const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);
var
  oldCefFrame: PRCEFFrame;
  newCefFrame: PRCEFFrame;
begin
  oldCefFrame := new(PRCEFFrame);
  newCefFrame := new(PRCEFFrame);
  if (old_frame <> nil) then
  begin
    oldCefFrame^.Name := PChar(string(old_frame.Name));
    oldCefFrame^.Url := PChar(string(old_frame.Url));
    oldCefFrame^.Identifier := PChar(IntToStr(old_frame.Identifier));
  end
  else
  begin
    oldCefFrame^.Name := PChar('');
    oldCefFrame^.Url := PChar('');
    oldCefFrame^.Identifier := PChar('-1');
  end;
  if (new_frame <> nil) then
  begin
    newCefFrame^.Name := PChar(string(new_frame.Name));
    newCefFrame^.Url := PChar(string(new_frame.Url));
    newCefFrame^.Identifier := PChar(IntToStr(new_frame.Identifier));
  end
  else
  begin
    newCefFrame^.Name := PChar('');
    newCefFrame^.Url := PChar('');
    newCefFrame^.Identifier := PChar('-1');
  end;
  SendEvent([Sender, browser.Identifier, oldCefFrame, newCefFrame]);
  FreePRCEFFrame(oldCefFrame);
  FreePRCEFFrame(newCefFrame);
end;

{==chromium Drag==}
procedure TLCLEvent.ChromiumEvent_OnDragEnter(Sender: TObject; const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations; out Result: Boolean);
begin
  SendEvent([Sender, browser.Identifier, @dragData, mask, @Result]);
end;

procedure TLCLEvent.ChromiumEvent_OnDraggableRegionsChanged(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; regionsCount: NativeUInt; const regions: PCefDraggableRegionArray);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent([Sender, browser.Identifier, cefFrame, Integer(regionsCount), regions]);
  FreePRCEFFrame(cefFrame);
end;

{==window parent==}
procedure TLCLEvent.CEFWindowEvent_OnEnter(Sender: TObject);
begin
  SendEvent([Sender]);
end;

procedure TLCLEvent.CEFWindowEvent_OnExit(Sender: TObject);
begin
  SendEvent([Sender]);
end;


{==CEFWindowComponent==}
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
  SendEvent([Sender, browser_view, browser.Identifier]);
end;

procedure TLCLEvent.BrowserViewComponent_OnBrowserDestroyed(const Sender: TObject; const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
  SendEvent([Sender, browser_view, browser.Identifier]);
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

