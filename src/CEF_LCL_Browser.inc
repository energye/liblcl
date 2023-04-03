//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//CEFBrowser_GetIdentifier
function CEFBrowser_GetIdentifier(const TObj: ICefBrowser): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Identifier;
  handleExceptionEnd
end;

procedure CEFBrowser_GetFocusedFrame(const TObj: ICefBrowser; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin;
  Result := TObj.GetFocusedFrame;
  handleExceptionEnd
end;

procedure CEFBrowser_GetMainFrame(const TObj: ICefBrowser; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin;
  Result := TObj.GetMainFrame;
  handleExceptionEnd
end;

procedure CEFBrowser_GetFrameById(const TObj: ICefBrowser; frameId: PInt64; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetFrameByident(FrameId^);
  if Result = nil then
  begin
     exit;
  end;
  if not Result.IsValid then
     Result := nil;
  handleExceptionEnd
end;

procedure CEFBrowser_GetFrameByName(const TObj: ICefBrowser; PName: PChar; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetFrame(PCharToUStr(PName));
  if Result = nil then
  begin
     exit;
  end;
  if not Result.IsValid then
     Result := nil;
  handleExceptionEnd
end;

function CEFBrowser_GetHostWindowHandle(const TObj: ICefBrowser): TCefWindowHandle ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.GetWindowHandle();
  handleExceptionEnd
end;

procedure CEFBrowser_CloseBrowser(const TObj: ICefBrowser; forceClose: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.CloseBrowser(forceClose);
  handleExceptionEnd
end;

function CEFBrowser_TryCloseBrowser(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.TryCloseBrowser();
  handleExceptionEnd
end;

procedure CEFBrowser_SetFocus(const TObj: ICefBrowser; focus: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SetFocus(focus);
  handleExceptionEnd
end;

procedure CEFBrowser_GetZoomLevel(const TObj: ICefBrowser; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.GetZoomLevel();
  handleExceptionEnd
end;

procedure CEFBrowser_SetZoomLevel(const TObj: ICefBrowser; const zoomLevel: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SetZoomLevel(Double(PDouble(zoomLevel)^));
  handleExceptionEnd
end;

// TODO 待写回调函数
procedure CEFBrowser_RunFileDialog(const TObj: ICefBrowser; mode: integer; const PTitle, PDefaultFilePath: PChar; const acceptFilters: TStrings); extdecl;
var
  callback: ICefRunFileDialogCallback;
begin
  handleExceptionBegin
  callback := TCefRunFileDialogCallbackOwn.Create;
  TObj.GetHost.RunFileDialog(mode, PCharToUStr(PTitle), PCharToUStr(PDefaultFilePath), acceptFilters, callback);
  handleExceptionEnd
end;

procedure CEFBrowser_StartDownload(const TObj: ICefBrowser; const PUrl: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.StartDownload(PCharToUStr(PUrl));
  handleExceptionEnd
end;

// TODO 待写回调函数
procedure CEFBrowser_DownloadImage(const TObj: ICefBrowser; const PImageUrl: PChar; isFavicon: LongBool; maxImageSize: integer; bypassCache: LongBool); extdecl;
var
  callback: ICefDownloadImageCallback;
begin
  handleExceptionBegin
  callback := TCefDownloadImageCallbackOwn.Create;
  TObj.GetHost.DownloadImage(PCharToUStr(PImageUrl), isFavicon, maxImageSize, bypassCache, callback);
  handleExceptionEnd
end;

procedure CEFBrowser_Print(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.Print();
  handleExceptionEnd
end;

procedure CEFBrowser_PrintToPdf(const TObj: ICefBrowser; const PPath: PChar; const PSettings: PRCefPdfPrintSettings; const callback: TPdfPrintCallbackRef); extdecl;
var
  settings: PCefPdfPrintSettings;
  margin_type: Integer;
begin
  handleExceptionBegin
  // settings.margin_type = TCefPdfPrintMarginType = (
  //  PDF_PRINT_MARGIN_DEFAULT,
  //  PDF_PRINT_MARGIN_NONE,
  //  PDF_PRINT_MARGIN_CUSTOM
  //)
  //FillChar(settings, SizeOf(TCefPdfPrintSettings), 0);
  settings := nil;
  if PSettings <> nil then
  begin
    settings := new(PCefPdfPrintSettings);
    margin_type := Integer(PSettings.margin_type);
    if margin_type = 0 then
       settings.margin_type := TCefPdfPrintMarginType.PDF_PRINT_MARGIN_DEFAULT
    else if margin_type = 1 then
       settings.margin_type := TCefPdfPrintMarginType.PDF_PRINT_MARGIN_NONE
    else if margin_type = 2 then
       settings.margin_type := TCefPdfPrintMarginType.PDF_PRINT_MARGIN_CUSTOM;
    if PSettings.landscape <> nil then
       settings.landscape := Integer(PSettings.landscape);
    if PSettings.print_background <> nil then
       settings.print_background := Integer(PSettings.print_background);
    if PSettings.scale <> nil then
       settings.scale := Double(PSettings.scale^);
    if PSettings.paper_width <> nil then
       settings.paper_width := Double(PSettings.paper_width^);
    if PSettings.paper_height <> nil then
       settings.paper_height := Double(PSettings.paper_height^);
    if PSettings.prefer_css_page_size <> nil then
       settings.prefer_css_page_size := Integer(PSettings.prefer_css_page_size);
    if PSettings.margin_top <> nil then
       settings.margin_top := Double(PSettings.margin_top^);
    if PSettings.margin_right <> nil then
       settings.margin_right := Double(PSettings.margin_right^);
    if PSettings.margin_bottom <> nil then
       settings.margin_bottom := Double(PSettings.margin_bottom^);
    if PSettings.margin_left <> nil then
       settings.margin_left := Double(PSettings.margin_left^);
    if PSettings.page_ranges <> nil then
       settings.page_ranges := CefString(PCharToUStr(PSettings.page_ranges));
    if PSettings.display_header_footer <> nil then
       settings.display_header_footer := Integer(PSettings.display_header_footer);
    if PSettings.header_template <> nil then
       settings.header_template := CefString(PCharToUStr(PSettings.header_template));
    if PSettings.footer_template <> nil then
       settings.footer_template := CefString(PCharToUStr(PSettings.footer_template));
  end;

  TObj.GetHost.PrintToPdf(PCharToUStr(PPath), settings, callback)
  handleExceptionEnd
end;

function CEFBrowser_ExecuteDevToolsMethod(const TObj: ICefBrowser; messageId: integer; const PMethod: PChar; const dictionaryValue: ICefDictionaryValue): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.ExecuteDevToolsMethod(messageId, PCharToUStr(PMethod), dictionaryValue);
  handleExceptionEnd
end;

procedure CEFBrowser_SendKeyEvent(const TObj: ICefBrowser; const event: PCefKeyEvent); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SendKeyEvent(event);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseClickEvent(const TObj: ICefBrowser; const event: PCefMouseEvent; type_: integer; mouseUp: LongBool; clickCount: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SendMouseClickEvent(event, TCefMouseButtonType(type_), mouseUp, clickCount);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseMoveEvent(const TObj: ICefBrowser; const event: PCefMouseEvent; mouseLeave: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SendMouseMoveEvent(event, mouseLeave);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseWheelEvent(const TObj: ICefBrowser; const event: PCefMouseEvent; deltaX, deltaY: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SendMouseWheelEvent(event, deltaX, deltaY);
  handleExceptionEnd
end;

procedure CEFBrowser_SendTouchEvent(const TObj: ICefBrowser; const event: PCefTouchEvent); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SendTouchEvent(event);
  handleExceptionEnd
end;

procedure CEFBrowser_SendCaptureLostEvent(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SendCaptureLostEvent;
  handleExceptionEnd
end;

procedure CEFBrowser_NotifyMoveOrResizeStarted(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

procedure CEFBrowser_NotifyScreenInfoChanged(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.NotifyScreenInfoChanged;
  handleExceptionEnd
end;

procedure CEFBrowser_SetAccessibilityState(const TObj: ICefBrowser; accessibilityState: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SetAccessibilityState(TCefState(accessibilityState));
  handleExceptionEnd
end;

procedure CEFBrowser_SetAutoResizeEnabled(const TObj: ICefBrowser; enabled: LongBool; const min_size, max_size: PCefSize); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SetAutoResizeEnabled(enabled, min_size, max_size);
  handleExceptionEnd
end;

function CEFBrowser_IsBackgroundHost(const TObj: ICefBrowser) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.IsBackgroundHost;
  handleExceptionEnd
end;

procedure CEFBrowser_SetAudioMuted(const TObj: ICefBrowser; mute: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.SetAudioMuted(mute);
  handleExceptionEnd
end;

function CEFBrowser_IsAudioMuted(const TObj: ICefBrowser) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.IsAudioMuted;
  handleExceptionEnd
end;

procedure CEFBrowser_ShowDevTools(const TObj: ICefBrowser; const Chromium: TChromium; const windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PDevToolsWinName: PChar); extdecl;
var
  windowInfo: TCefWindowInfo;
  client: ICefClient;
  browserSettings: TCefBrowserSettings;
  devToolsWinName: ustring;
begin
  handleExceptionBegin
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
  WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect, devToolsWinName);
  client := TCustomClientHandler.Create(Chromium, True);
  FillChar(browserSettings, SizeOf(TCefBrowserSettings), 0);
  TObj.GetHost.ShowDevTools(@windowInfo, client, @browserSettings, nil);
  handleExceptionEnd
end;

procedure CEFBrowser_CloseDevTools(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.CloseDevTools;
  handleExceptionEnd
end;

function CEFBrowser_HasDevTools(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHost.HasDevTools;
  handleExceptionEnd
end;

function  CEFBrowser_CanGoBack(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.CanGoBack;
  handleExceptionEnd
end;

procedure CEFBrowser_GoBack(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GoBack;
  handleExceptionEnd
end;

function CEFBrowser_CanGoForward(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.CanGoForward;
  handleExceptionEnd
end;

procedure CEFBrowser_GoForward(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.GoForward;
  handleExceptionEnd
end;

function CEFBrowser_IsLoading(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsLoading;
  handleExceptionEnd
end;

procedure CEFBrowser_Reload(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.Reload;
  handleExceptionEnd
end;

procedure CEFBrowser_ReloadIgnoreCache(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.ReloadIgnoreCache;
  handleExceptionEnd
end;

procedure CEFBrowser_StopLoad(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  TObj.StopLoad;
  handleExceptionEnd
end;

function CEFBrowser_FrameCount(const TObj: ICefBrowser):NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.FrameCount;
  handleExceptionEnd
end;

procedure CEFBrowser_GetFrameNames(const TObj: ICefBrowser; var Result: Pointer; var resultSize: Integer); extdecl;
var
  frameNames : TStrings;
  idx: Integer;
  name, value: string;
  resultArr: FrameNamesArray;
begin
  handleExceptionBegin
  try
    frameNames := TStringList.Create;
    TObj.GetFrameNames(frameNames);
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

procedure CEFBrowser_Find(const TObj: ICefBrowser; PSearchText: PChar; forward_, matchCase, findNext: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.Find(PCharToUStr(PSearchText), forward_, matchCase, findNext);
  handleExceptionEnd
end;

procedure CEFBrowser_StopFinding(const TObj: ICefBrowser; clearSelection: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.GetHost.StopFinding(clearSelection);
  handleExceptionEnd
end;

procedure CEFBrowserRef_UnWrap(const data: ICefBrowser; var Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TCefBrowserRef.UnWrap(data.Wrap);
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
  CEFBrowser_PrintToPdf,
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
  CEFBrowser_StopFinding,
  CEFBrowserRef_UnWrap
;

