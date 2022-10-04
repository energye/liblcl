//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------
{
  CEF 事件实现
  说明：在lcl扩展的用户自定义(uEventCallback.pas -> UserDefineEventsImplement.inc)文件引入
  为CEF专有事件实现文件
}

{==chromium begin==}
//浏览器创建之后
class procedure TEventClass.ChromiumEvent_OnAfterCreated(Sender: TObject; const browser: ICefBrowser);
begin
  //SendMessage(browser.Host.WindowHandle, WM_SETICON, 1, application.Icon.Handle);
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnAfterCreated, [Sender, browser.Identifier]);
end;

//浏览器创建之前事件
class procedure TEventClass.ChromiumEvent_OnBeforeBrowse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  const request: ICefRequest; user_gesture, isRedirect: Boolean; out Result: Boolean);
var
  cefFrame: PRCEFFrame;
begin
  ConsoleLn('OnBeforeBrowser Id: '+IntToStr(browser.Identifier));
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnBeforeBrowse, [Sender, browser.Identifier, cefFrame, @Result]);
  FreePRCEFFrame(cefFrame);
end;

//关闭之前-事件
class procedure TEventClass.ChromiumEvent_OnBeforeClose(Sender: TObject; const browser: ICefBrowser);
begin
  //ConsoleLn('OnBeforeClose: '+IntToStr(browser.Identifier));
  TMainChromiumBrowserClass.RemoveBrowser(browser.Identifier);
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnBeforeClose, [Sender, browser.Identifier]);
end;

//关闭-事件
class procedure TEventClass.ChromiumEvent_OnClose(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
begin
  ConsoleLn('OnClose: '+IntToStr(browser.Identifier));
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnClose, [Sender, browser.Identifier, @aAction]);
  if not SingleProcess then
  begin
    TObjectValueBindInfoClass.Clear;
    TCommonValueBindInfoClass.Clear;
  end;
end;

//右键菜单-before-正常
class procedure TEventClass.ChromiumEvent_OnBeforeContextMenu(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
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
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnBeforeContextMenu, [Sender, browser.Identifier, cefFrame, PParams, model]);
  PParams := nil;
  FreePRCEFFrame(cefFrame);
end;

//右键菜单-command-正常
class procedure TEventClass.ChromiumEvent_OnContextMenuCommand(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
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
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnContextMenuCommand, [Sender, browser.Identifier, cefFrame, PParams, commandId, eventFlags, @Result]);
  PParams := nil;
end;

//右键菜单-Dismissed
class procedure TEventClass.ChromiumEvent_OnContextMenuDismissed(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnContextMenuDismissed, [Sender, browser.Identifier, cefFrame]);
  FreePRCEFFrame(cefFrame);
end;

//导出PDF完成-事件
class procedure TEventClass.ChromiumEvent_OnPdfPrintFinished(Sender: TObject; aResultOK: boolean);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnPdfPrintFinished, [Sender, aResultOK]);
end;

//键盘-事件
class procedure TEventClass.ChromiumEvent_KeyEvent(Sender: TObject; const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle;
  out Result: boolean);
begin
  //ConsoleLn('kind: '+IntToStr(integer(event^.kind))+'  modifiers: '+IntToStr(integer(event^.modifiers))+'  windows_key_code: '+IntToStr(event^.windows_key_code)+
  //'  native_key_code: '+IntToStr(event^.native_key_code)+'  is_system_key: '+IntToStr(event^.is_system_key)+
  //'  character: '+string(WideCharToString(PWideChar(@event^.character))) +
  //'  unmodified_character: '+string(WideCharToString(PWideChar(@event^.unmodified_character))) +
  //'  focus_on_editable_field: '+IntToStr(event^.focus_on_editable_field));
  SendEvent(Sender, @TEventClass.ChromiumEvent_KeyEvent, [Sender, browser.Identifier, event, @Result]);
end;

//加载 start-事件
class procedure TEventClass.ChromiumEvent_OnLoadStart(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
  transitionType: TCefTransitionType);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnLoadStart, [Sender, browser.Identifier, cefFrame]);
  FreePRCEFFrame(cefFrame);
end;

//加载 LoadingStateChange-事件
class procedure TEventClass.ChromiumEvent_OnLoadingStateChange(Sender: TObject; const browser: ICefBrowser;
  isLoading, canGoBack, canGoForward: boolean);
begin
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnLoadingStateChange, [Sender, browser.Identifier, isLoading, canGoBack, canGoForward]);
end;

//加载 LoadingProgressChange-事件
class procedure TEventClass.ChromiumEvent_OnLoadingProgressChange(Sender: TObject; const browser: ICefBrowser; const progress: Double);
begin
  TMainChromiumBrowserClass.PutBrowser(browser);
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnLoadingProgressChange, [Sender, browser.Identifier, @progress]);
end;

//加载 LoadError-事件
class procedure TEventClass.ChromiumEvent_OnLoadError(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnLoadError, [Sender, browser.Identifier, cefFrame, errorCode, PChar(string(errorText)), PChar(string(failedUrl))]);
  FreePRCEFFrame(cefFrame);
end;

//加载 LoadEnd-事件
class procedure TEventClass.ChromiumEvent_OnLoadEnd(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(string(frame.Name));
  cefFrame^.Url := PChar(string(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnLoadEnd, [Sender, browser.Identifier, cefFrame, httpStatusCode]);
  FreePRCEFFrame(cefFrame);
end;

//下载之前-事件  创建时设置
class procedure TEventClass.ChromiumEvent_OnBeforeDownload(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem;
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
  //ConsoleLn('OnBeforeDownload- startTime: '+FloatToStr(startTime) + '  dndTime: '+FloatToStr(dndTime));
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnBeforeDownload, [Sender, browser.Identifier, downItem, PChar(string(suggestedName)), callback]);
  downItem := nil;
end;

//下载更新-事件
class procedure TEventClass.ChromiumEvent_OnDownloadUpdated(Sender: TObject; const browser: ICefBrowser; const downloadItem: ICefDownloadItem;
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
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnDownloadUpdated, [Sender, browser.Identifier, downItem, callback]);
  downItem := nil;
end;

//放大缩小回调-事件
class procedure TEventClass.ChromiumEvent_OnZoomPctAvailable(Sender: TObject; const aZoomPct: Double);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnZoomPctAvailable, [Sender, @aZoomPct]);
end;

//全屏模式-事件
class procedure TEventClass.ChromiumEvent_OnFullScreenModeChange(Sender: TObject;  const browser: ICefBrowser; fullscreen: boolean);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnFullScreenModeChange, [Sender, browser.Identifier, fullscreen]);
end;

//弹窗之前-事件
class procedure TEventClass.ChromiumEvent_OnBeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl,
  targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings;
  var extra_info: ICefDictionaryValue; var noJavascriptAccess: Boolean;  var Result: Boolean);
var
  cefFrame: PRCEFFrame;
  beforePopupInfo: PRBeforePopupInfo;
  //windowHandlePtr: PTCefWindowHandle;
begin
  ConsoleLn('ChromiumEvent_OnBeforePopup BrowserId: ' + IntToStr(browser.Identifier) + '  MainThreadId: '+ IntToStr(NativeInt(MainThreadId))+ '  CurrentThreadId: '+ IntToStr(NativeInt(TThread.CurrentThread.ThreadID)));
  try
    //ConsoleLn('ChromiumEvent_OnBeforePopup ExStyle: ' + IntToStr(windowInfo.ex_style));
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
    SendEvent(Sender, @TEventClass.ChromiumEvent_OnBeforePopup, [Sender, browser.Identifier, cefFrame, beforePopupInfo, @windowInfo, client, @noJavascriptAccess, @Result]);
  finally
    //free beforePopupInfo
    beforePopupInfo^.TargetUrl := nil;
    beforePopupInfo^.TargetFrameName := nil;
    beforePopupInfo^.UserGesture := nil;
    beforePopupInfo := nil;
    //free frame
    FreePRCEFFrame(cefFrame);
    //other
    //windowHandlePtr := nil;
    //chromiumPtr := nil;
  end;
end;

//打开tab-事件
class procedure TEventClass.ChromiumEvent_OnOpenUrlFromTab(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring;
  targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; out Result: Boolean);
begin
  if not boolean(GChromiumConfig.EnableOpenUrlTab) then //禁止弹新Tab
  begin
    // 阻止所有弹出窗口和新选项卡
     Result := (targetDisposition in [WOD_NEW_FOREGROUND_TAB, WOD_NEW_BACKGROUND_TAB, WOD_NEW_POPUP, WOD_NEW_WINDOW]);
     exit;
  end;
end;

//标题改变-事件
class procedure TEventClass.ChromiumEvent_OnTitleChange(Sender: TObject; const browser: ICefBrowser; const title: ustring);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnTitleChange, [Sender, browser.Identifier, string(title)]);
end;

//Render-事件
class procedure TEventClass.ChromiumEvent_OnRenderCompMsg(Sender: TObject; var aMessage: TMessage; var aHandled: boolean);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnRenderCompMsg, [Sender, @aMessage, aHandled]);
end;

class procedure TEventClass.ChromiumEvent_OnRenderProcessTerminated(Sender: TObject; const browser: ICefBrowser; status: TCefTerminationStatus);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnRenderProcessTerminated, [Sender, browser.Identifier, status]);
end;

class procedure TEventClass.ChromiumEvent_OnRenderViewReady(Sender: Tobject; const browser: ICefBrowser);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnRenderViewReady, [Sender, browser.Identifier]);
end;

//滚动条事件
class procedure TEventClass.ChromiumEvent_OnScrollOffsetChanged(Sender: TObject; const browser: ICefBrowser; x, y: Double);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnScrollOffsetChanged, [Sender, browser.Identifier, @x, @y]);
end;

//browser 进程消息
class procedure TEventClass.ChromiumEvent_OnProcessMessageReceived(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame;
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
    SendEvent(Sender, @TEventClass.ChromiumEvent_OnProcessMessageReceived, [Sender, browser.Identifier, cefFrame, sourceProcess, processMessage, @Result]);
    SetLength(binaryBuf, 0);
    processMessage^.Data := nil;
    processMessage := nil;
    FreePRCEFFrame(cefFrame);
  end;
  Result := True;
end;

//查找结果回调
class procedure TEventClass.ChromiumEvent_OnFindResult(Sender: TObject; const browser: ICefBrowser; identifier, count: Integer; const selectionRect: PCefRect; activeMatchOrdinal: Integer; finalUpdate: Boolean);
begin
    SendEvent(Sender, @TEventClass.ChromiumEvent_OnFindResult, [Sender, browser.Identifier, identifier, count, selectionRect, activeMatchOrdinal, finalUpdate]);
end;

{==chromium end==}

//cookie begin
class procedure TEventClass.ChromiumEvent_OnCookieSet(Sender: TObject; aSuccess: boolean; aID: integer);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnCookieSet, [Sender, aSuccess, aID]);
end;

class procedure TEventClass.ChromiumEvent_OnCookiesDeleted(Sender: TObject; numDeleted: Integer);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnCookiesDeleted, [Sender, numDeleted]);
end;

class procedure TEventClass.ChromiumEvent_OnCookiesFlushed(Sender: TObject);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnCookiesFlushed, [Sender]);
end;

class procedure TEventClass.ChromiumEvent_OnCookiesVisited(Sender: TObject; const name_, value, domain, path: ustring; secure, httponly, hasExpires: Boolean;
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
  //ConsoleLn('date time: '+FloatToStr(creation)+'   '+FloatToStr(lastAccess)+'   '+FloatToStr(expires) + '  Id: '+IntToStr(aID) + '  Count: '+IntToStr(count) +
  //                  '  total: '+IntToStr(total)+ '   same_site: '+IntToStr(integer(same_site))+ '  priority:'+IntToStr(priority) +
  //                  '  secure: '+BoolToStr(secure) + '  httponly: '+BoolToStr(httponly) + '  hasExpires: '+BoolToStr(hasExpires)) ;
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnCookiesVisited, [Sender, cookie]);
  cookie := nil;
end;

class procedure TEventClass.ChromiumEvent_OnCookieVisitorDestroyed(Sender: TObject; aID: integer);
begin
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnCookieVisitorDestroyed, [Sender, aID]);
end;
//cookie end

//资源加载之前消息
class procedure TEventClass.ChromiumEvent_OnBeforeResourceLoad(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
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
  //ConsoleLn('ResourceType:  '+IntToStr(integer(request.ResourceType)) +
  //   '  TransitionType:  '+IntToStr(integer(request.TransitionType))+'  Identifier: '+ IntToStr(request.Identifier));

  SendEvent(Sender, @TEventClass.ChromiumEvent_OnBeforeResourceLoad, [Sender, browser.Identifier, cefFrame, rCefRequest, callback, @Result]);

  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
end;

class procedure TEventClass.ChromiumEvent_OnResourceResponse(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
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

  SendEvent(Sender, @TEventClass.ChromiumEvent_OnResourceResponse, [Sender, browser.Identifier, cefFrame, rCefRequest, rCefResponse, @Result]);

  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
  rCefResponse := nil;
end;

class procedure TEventClass.ChromiumEvent_OnResourceRedirect(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest;
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

  SendEvent(Sender, @TEventClass.ChromiumEvent_OnResourceRedirect, [Sender, browser.Identifier, cefFrame, rCefRequest, rCefResponse, @pNewUrl]);
  //ConsoleLn('OnResourceRedirect newUrl: '+ string(pNewUrl));
  newUrl := PCharToUStr(pNewUrl);
  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
  rCefResponse := nil;
end;


class procedure TEventClass.ChromiumEvent_OnResourceLoadComplete(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse;
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
  //ConsoleLn('OnResourceLoadComplete: '+ IntToStr(integer(status)) + '  receivedContentLength: '+ IntToStr(receivedContentLength));
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnResourceLoadComplete, [Sender, browser.Identifier, cefFrame, rCefRequest, rCefResponse, @integer(status), @receivedContentLength]);
  FreePRCEFFrame(cefFrame);
  rCefRequest := nil;
  rCefResponse := nil;
end;

{==frame begin==}
class procedure TEventClass.ChromiumEvent_OnFrameAttached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
var
  cefFrame: PRCEFFrame;
begin
  //ConsoleLn('OnFrameAttached');
  cefFrame := new(PRCEFFrame);
  if (frame <> nil) then
  begin
    //ConsoleLn('OnFrameAttached BrowseId: ' + IntToStr(browser.Identifier) + '  Name :' + string(frame.Name)+' Url: '+ string(frame.Url)+' frameId: '+ IntToStr(frame.Identifier) + '  reattached: '+BoolToSTr(reattached));
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
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnFrameAttached, [Sender, browser.Identifier, cefFrame, reattached]);
  FreePRCEFFrame(cefFrame);
end;

class procedure TEventClass.ChromiumEvent_OnFrameCreated(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
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
  //ConsoleLn('ChromiumEvent_OnFrameCreated frameId: ' + string(frameId) + ' frameName: ' + frameName + ' frameUrl: ' + frameUrl);
  if Assigned(cefFrame) then
  begin
    SendEvent(Sender, @TEventClass.ChromiumEvent_OnFrameCreated, [Sender, browser.Identifier, cefFrame]);
  end;
  frameId := nil;
  frameName := nil;
  frameUrl := nil;
  FreePRCEFFrame(cefFrame);
  cefFrame := nil;
end;

class procedure TEventClass.ChromiumEvent_OnFrameDetached(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame);
var
  cefFrame: PRCEFFrame;
begin
  //ConsoleLn('OnFrameDetached');
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
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnFrameDetached, [Sender, browser.Identifier, cefFrame]);
  FreePRCEFFrame(cefFrame);
end;

class procedure TEventClass.ChromiumEvent_OnMainFrameChanged(Sender: TObject; const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);
var
  oldCefFrame: PRCEFFrame;
  newCefFrame: PRCEFFrame;
begin
  //ConsoleLn('OnMainFrameChanged');
  oldCefFrame := new(PRCEFFrame);
  newCefFrame := new(PRCEFFrame);
  if (old_frame <> nil) then
  begin
    //ConsoleLn('OnMainFrameChanged oldFrameId: '+IntToStr(old_frame.Identifier));
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
    //ConsoleLn('OnMainFrameChanged newFrameId: '+IntToStr(new_frame.Identifier));
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
  SendEvent(Sender, @TEventClass.ChromiumEvent_OnMainFrameChanged, [Sender, browser.Identifier, oldCefFrame, newCefFrame]);
  FreePRCEFFrame(oldCefFrame);
  FreePRCEFFrame(newCefFrame);
end;
{==frame end==}

{==window begin==}
class procedure TEventClass.CEFWindowEvent_OnEnter(Sender: TObject);
begin
  ConsoleLn('CEFWindowEvent_OnEnter');
  SendEvent(Sender, @TEventClass.CEFWindowEvent_OnEnter, [Sender]);
end;

class procedure TEventClass.CEFWindowEvent_OnExit(Sender: TObject);
begin
  ConsoleLn('CEFWindowEvent_OnExit');
  SendEvent(Sender, @TEventClass.CEFWindowEvent_OnExit, [Sender]);
end;

