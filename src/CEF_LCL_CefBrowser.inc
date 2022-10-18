//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//CEFBrowser_GetIdentifier
function CEFBrowser_GetIdentifier(browser: ICefBrowser): integer; extdecl;
begin
  handleExceptionBegin
  if browser <> nil then
    Result := browser.Identifier
  else
    Result := 0;
  handleExceptionEnd
end;

function CEFBrowser_GetFocusedFrame(browserId: Integer): PRCEFFrame; extdecl;
var
  browser: ICefBrowser;
  cefFrame: PRCEFFrame;
  frame: ICefFrame;
  name, url: PChar;
begin
  handleExceptionBegin;
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := nil;
    exit;
  end;
  frame := browser.GetFocusedFrame;
  cefFrame := new(PRCEFFrame);
  name := PChar(UTF8Encode(frame.Name));
  url := PChar(UTF8Encode(frame.Url));
  cefFrame^.Name := name;
  cefFrame^.Url := url;
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  Result := cefFrame;
  name := nil;
  url := nil;
  cefFrame := nil;
  handleExceptionEnd
end;

function CEFBrowser_GetMainFrame(browserId: Integer): PRCEFFrame; extdecl;
var
  browser: ICefBrowser;
  cefFrame: PRCEFFrame;
  frame: ICefFrame;
  name, url: PChar;
begin
  handleExceptionBegin;
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := nil;
    exit;
  end;
  frame := browser.GetMainFrame;
  cefFrame := new(PRCEFFrame);
  name := PChar(UTF8Encode(frame.Name));
  url := PChar(UTF8Encode(frame.Url));
  cefFrame^.Name := name;
  cefFrame^.Url := url;
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  Result := cefFrame;
  name := nil;
  url := nil;
  cefFrame := nil;
  handleExceptionEnd
end;

function CEFBrowser_GetFrameById(browserId: Integer; FrameId: PInt64): PRCEFFrame; extdecl;
var
  browser: ICefBrowser;
  cefFrame: PRCEFFrame;
  frame: ICefFrame;
  name, url: PChar;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := nil;
    exit;
  end;
  frame := browser.GetFrameByident(FrameId^);
  if frame = nil then
  begin
    Result := nil;
    exit;
  end;
  name := PChar(UTF8Encode(frame.Name));
  url := PChar(UTF8Encode(frame.Url));
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := name;
  cefFrame^.Url := url;
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  Result := cefFrame;
  name := nil;
  url := nil;
  cefFrame := nil;
  handleExceptionEnd
end;

function CEFBrowser_GetFrameByName(browserId: Integer; PName: PChar): PRCEFFrame; extdecl;
var
  browser: ICefBrowser;
  cefFrame: PRCEFFrame;
  frame: ICefFrame;
  name, url: PChar;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := nil;
    exit;
  end;
  frame := browser.GetFrame(PCharToUStr(PName));
  name := PChar(UTF8Encode(frame.Name));
  url := PChar(UTF8Encode(frame.Url));
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := name;
  cefFrame^.Url := url;
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  Result := cefFrame;
  name := nil;
  url := nil;
  cefFrame := nil;
  handleExceptionEnd
end;

//CEFBrowser_GetHostWindowHandle
function CEFBrowser_GetHostWindowHandle(browserId: Integer): TCefWindowHandle ; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := 0;
    exit;
  end;
  Result := browser.GetHost.GetWindowHandle();
  handleExceptionEnd
end;

//CEFBrowser_CloseBrowser
procedure CEFBrowser_CloseBrowser(browserId: Integer; forceClose: Boolean); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.CloseBrowser(forceClose);
  handleExceptionEnd
end;

//CEFBrowser_TryCloseBrowser
function CEFBrowser_TryCloseBrowser(browserId: Integer): Boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := False;
    exit;
  end;
  Result := Browser.GetHost.TryCloseBrowser();
  handleExceptionEnd
end;

//CEFBrowser_SetFocus
procedure CEFBrowser_SetFocus(browserId: Integer; focus: Boolean); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SetFocus(focus);
  handleExceptionEnd
end;

//CEFBrowser_GetZoomLevel
procedure CEFBrowser_GetZoomLevel(browserId: Integer; out RetDouble: Double); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  RetDouble := browser.GetHost.GetZoomLevel();
  handleExceptionEnd
end;

//CEFBrowser_SetZoomLevel
procedure CEFBrowser_SetZoomLevel(browserId: Integer; const zoomLevel: PDouble); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SetZoomLevel(zoomLevel^);
  handleExceptionEnd
end;

//CEFBrowser_RunFileDialog TODO 待写回调函数
procedure CEFBrowser_RunFileDialog(browserId: Integer; mode: integer; const title, defaultFilePath: PChar; const acceptFilters: TStrings); extdecl;
var
  browser: ICefBrowser;
  callback: ICefRunFileDialogCallback;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  callback := TCefRunFileDialogCallbackOwn.Create;
  browser.GetHost.RunFileDialog(mode, PCharToUStr(title), PCharToUStr(defaultFilePath), acceptFilters, callback);
  handleExceptionEnd
end;

//CEFBrowser_StartDownload
procedure CEFBrowser_StartDownload(browserId: Integer; const PUrl: PChar); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.StartDownload(PCharToUStr(PUrl));
  handleExceptionEnd
end;

//CEFBrowser_DownloadImage
procedure CEFBrowser_DownloadImage(browserId: Integer; const PImageUrl: PChar; isFavicon: Boolean; maxImageSize: integer; bypassCache: Boolean); extdecl;
var
  browser: ICefBrowser;
  callback: ICefDownloadImageCallback;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  callback := TCefDownloadImageCallbackOwn.Create;
  browser.GetHost.DownloadImage(PCharToUStr(PImageUrl), isFavicon, maxImageSize, bypassCache, callback);
  handleExceptionEnd
end;

procedure CEFBrowser_Print(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.Print();
  handleExceptionEnd
end;

//procedure CEFBrowser_PrintToPdf(browserId: Integer; const PPath: PChar; settings: PCefPdfPrintSettings); extdecl;
//var
//  chromiumbrowser: PChromiumBrowser;
//  browser: ICefBrowser;
//  callback: ICefPdfPrintCallback;
//begin
//  handleExceptionBegin
//  chromiumBrowser := TMainChromiumBrowserClass.GetBrowser(browserId);
//  if chromiumBrowser <> nil then
//  begin
//    browser := chromiumBrowser^.Browser;
//    callback := TCefPdfPrintCallbackOwn.Create;
//    browser.GetHost.PrintToPdf(PCharToUStr(PPath), settings, callback);
//  end;
//  handleExceptionEnd
//end;

{$ifdef DARWIN}
function CEFBrowser_ExecuteDevToolsMethod(browserId: Integer; messageId: integer; const method: PChar; const len: integer; const arguments: array of Byte; argumentsLength: integer): Integer; extdecl;
var
  macArgs: array of Byte;
{$else}
function CEFBrowser_ExecuteDevToolsMethod(browserId: Integer; messageId: integer; const method: PChar; const len: integer; const arguments: array of Byte): Integer;stdcall;
var
{$endif}
  browser: ICefBrowser;
  dictValue: TDictValueList;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  try
    if len > 0 then
    begin
      dictValue := TDictValueList.Create;
      {$ifdef DARWIN}
      SetLength(macArgs, argumentsLength);
      Move(arguments[0], macArgs[0], argumentsLength+1);
      dictValue.UnPackage(macArgs);
      {$else}
      dictValue.UnPackage(arguments);
      {$endif}
      Result := browser.GetHost.ExecuteDevToolsMethod(messageId, PCharToUStr(method), dictValue.GetDictValue());
    end
    else
    begin
      Result := browser.GetHost.ExecuteDevToolsMethod(messageId, PCharToUStr(method), nil);
    end;
  finally
    {$ifdef DARWIN}
    SetLength(macArgs, 0);
    {$endif}
    dictValue.Destroy;
    dictValue := nil;
  end;
  handleExceptionEnd
end;


procedure CEFBrowser_SendKeyEvent(browserId: Integer; const event: PCefKeyEvent); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SendKeyEvent(event);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseClickEvent(browserId: Integer; const event: PCefMouseEvent; type_: integer; mouseUp: Boolean; clickCount: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SendMouseClickEvent(event, TCefMouseButtonType(type_), mouseUp, clickCount);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseMoveEvent(browserId: Integer; const event: PCefMouseEvent; mouseLeave: Boolean); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SendMouseMoveEvent(event, mouseLeave);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseWheelEvent(browserId: Integer; const event: PCefMouseEvent; deltaX, deltaY: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SendMouseWheelEvent(event, deltaX, deltaY);
  handleExceptionEnd
end;

procedure CEFBrowser_SendTouchEvent(browserId: Integer; const event: PCefTouchEvent); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SendTouchEvent(event);
  handleExceptionEnd
end;

procedure CEFBrowser_SendCaptureLostEvent(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SendCaptureLostEvent;
  handleExceptionEnd
end;

procedure CEFBrowser_NotifyMoveOrResizeStarted(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

procedure CEFBrowser_NotifyScreenInfoChanged(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.NotifyScreenInfoChanged;
  handleExceptionEnd
end;

procedure CEFBrowser_SetAccessibilityState(browserId: Integer; accessibilityState: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SetAccessibilityState(TCefState(accessibilityState));
  handleExceptionEnd
end;

procedure CEFBrowser_SetAutoResizeEnabled(browserId: Integer; enabled: boolean; const min_size, max_size: PCefSize); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SetAutoResizeEnabled(enabled, min_size, max_size);
  handleExceptionEnd
end;

function CEFBrowser_IsBackgroundHost(browserId: Integer) : boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := False;
    exit;
  end;
  Result := browser.GetHost.IsBackgroundHost;
  handleExceptionEnd
end;

procedure CEFBrowser_SetAudioMuted(browserId: Integer; mute: boolean); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.SetAudioMuted(mute);
  handleExceptionEnd
end;

function  CEFBrowser_IsAudioMuted(browserId: Integer) : boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := False;
    exit;
  end;
  Result := browser.GetHost.IsAudioMuted;
  handleExceptionEnd
end;

procedure CEFBrowser_ShowDevTools(Chromium: TChromium; browserId: Integer; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PDevToolsWinName: PChar); extdecl;
var
  browser: ICefBrowser;
  windowInfo: TCefWindowInfo;
  client: ICefClient;
  browserSettings: TCefBrowserSettings;
  devToolsWinName: ustring;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  try
    if PDevToolsWinName <> nil then
    begin
      devToolsWinName := PCharToUStr(PDevToolsWinName);
      if devToolsWinName = '' then
         devToolsWinName := DEVTOOLS_WINDOWNAME;
    end
    else
    begin
      devToolsWinName := DEVTOOLS_WINDOWNAME;
    end;
    FillChar(windowInfo, SizeOf(TCefWindowInfo), 0);
    //WindowInfoAsPopUp(windowInfo, browser.Host.WindowHandle, devToolsWinName);
    //WindowInfoAsWindowless(windowInfo, windowParent.Handle, devToolsWinName);
    WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect, devToolsWinName);
    client := TCustomClientHandler.Create(Chromium, True);
    FillChar(browserSettings, SizeOf(TCefBrowserSettings), 0);
    browser.GetHost.ShowDevTools(@windowInfo, client, @browserSettings, nil);
  finally
    //Free(windowInfo);
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_CloseDevTools(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.CloseDevTools;
  handleExceptionEnd
end;

function CEFBrowser_HasDevTools(browserId: Integer): Boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := False;
    exit;
  end;
  Result := browser.GetHost.HasDevTools;
  handleExceptionEnd
end;

function  CEFBrowser_CanGoBack(browserId: Integer): Boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := False;
    exit;
  end;
  Result := browser.CanGoBack;
  handleExceptionEnd
end;

procedure CEFBrowser_GoBack(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GoBack;
  handleExceptionEnd
end;

function  CEFBrowser_CanGoForward(browserId: Integer): Boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    Result := False;
    exit;
  end;
  Result := browser.CanGoForward;
  handleExceptionEnd
end;

procedure CEFBrowser_GoForward(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GoForward;
  handleExceptionEnd
end;

function  CEFBrowser_IsLoading(browserId: Integer): Boolean; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  Result := browser.IsLoading;
  handleExceptionEnd
end;

procedure CEFBrowser_Reload(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.Reload;
  handleExceptionEnd
end;

procedure CEFBrowser_ReloadIgnoreCache(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.ReloadIgnoreCache;
  handleExceptionEnd
end;

procedure CEFBrowser_StopLoad(browserId: Integer); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.StopLoad;
  handleExceptionEnd
end;

function CEFBrowser_FrameCount(browserId: Integer):NativeUInt; extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  Result := browser.FrameCount;
  handleExceptionEnd
end;

procedure CEFBrowser_GetFrameNames(browserId: Integer; out Result: Pointer; out resultSize: Integer); extdecl;
var
  browser: ICefBrowser;
  frameNames : TStrings;
  idx: Integer;
  name, value: string;
  resultArr: FrameNamesArray;
begin
  handleExceptionBegin
  try
    browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
    if browser = nil then
    begin
      exit;
    end;
    frameNames := TStringList.Create;
    browser.GetFrameNames(frameNames);
    resultSize := frameNames.Count;
    SetLength(resultArr, resultSize);
    for idx := 0 to resultSize - 1 do
    begin
      frameNames.GetNameValue(idx, name, value);
      resultArr[idx] := new(PRFrameNames);
      resultArr[idx]^.Name := PChar(name);
      resultArr[idx]^.Value := PChar(value);
    end;
    Result := @resultArr[0];
  finally
    frameNames.Clear;
    frameNames.Free;
    SetLength(resultArr, 0);
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_Find(browserId: Integer; searchText: PChar; forward_, matchCase, findNext: Boolean); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.Find(PCharToUStr(searchText), forward_, matchCase, findNext);
  handleExceptionEnd
end;

procedure CEFBrowser_StopFinding(browserId: Integer; clearSelection: Boolean); extdecl;
var
  browser: ICefBrowser;
begin
  handleExceptionBegin
  browser := TMainChromiumBrowserClass.GetBrowserById(browserId);
  if browser = nil then
  begin
    exit;
  end;
  browser.GetHost.StopFinding(clearSelection);
  handleExceptionEnd
end;

exports
  CEFBrowser_ShowDevTools,
  CEFBrowser_CloseDevTools,
  CEFBrowser_HasDevTools,
  CEFBrowser_GetIdentifier,
  CEFBrowser_GetFocusedFrame,
  CEFBrowser_GetMainFrame,
  CEFBrowser_GetFrameById,
  CEFBrowser_GetFrameByName,
  CEFBrowser_GetHostWindowHandle,
  CEFBrowser_CloseBrowser,
  CEFBrowser_TryCloseBrowser,
  CEFBrowser_SetFocus,
  CEFBrowser_GetZoomLevel,
  CEFBrowser_SetZoomLevel,
  CEFBrowser_RunFileDialog,
  CEFBrowser_StartDownload,
  CEFBrowser_DownloadImage,
  CEFBrowser_Print,
  CEFBrowser_ExecuteDevToolsMethod,
  CEFBrowser_SendKeyEvent,
  CEFBrowser_SetAudioMuted,
  CEFBrowser_IsAudioMuted,
  CEFBrowser_SetAutoResizeEnabled,
  CEFBrowser_SetAccessibilityState,
  CEFBrowser_NotifyMoveOrResizeStarted,
  CEFBrowser_NotifyScreenInfoChanged,
  CEFBrowser_SendCaptureLostEvent,
  CEFBrowser_SendTouchEvent,
  CEFBrowser_SendMouseWheelEvent,
  CEFBrowser_SendMouseMoveEvent,
  CEFBrowser_SendMouseClickEvent,
  CEFBrowser_CanGoBack,
  CEFBrowser_GoBack,
  CEFBrowser_CanGoForward,
  CEFBrowser_GoForward,
  CEFBrowser_IsLoading,
  CEFBrowser_Reload,
  CEFBrowser_ReloadIgnoreCache,
  CEFBrowser_StopLoad,
  CEFBrowser_FrameCount,
  CEFBrowser_GetFrameNames,
  CEFBrowser_Find,
  CEFBrowser_StopFinding
;

