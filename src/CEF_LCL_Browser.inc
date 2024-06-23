//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

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
  if Result = nil then
  begin
    exit;
  end;
  if not Result.IsValid then
    Result := nil;
  handleExceptionEnd
end;

procedure CEFBrowser_GetMainFrame(const TObj: ICefBrowser; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin;
  Result := TObj.GetMainFrame;
  if Result = nil then
  begin
    exit;
  end;
  if not Result.IsValid then
    Result := nil;
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
  Result := 0;
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.GetWindowHandle();
  handleExceptionEnd
end;

procedure CEFBrowser_CloseBrowser(const TObj: ICefBrowser; forceClose: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.CloseBrowser(forceClose);
  handleExceptionEnd
end;

function CEFBrowser_TryCloseBrowser(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  handleExceptionEnd
end;

procedure CEFBrowser_SetFocus(const TObj: ICefBrowser; focus: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SetFocus(focus);
  handleExceptionEnd
end;

procedure CEFBrowser_GetZoomLevel(const TObj: ICefBrowser; var Result: Double); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.GetZoomLevel();
  handleExceptionEnd
end;

procedure CEFBrowser_SetZoomLevel(const TObj: ICefBrowser; const zoomLevel: Pointer); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SetZoomLevel(Double(PDouble(zoomLevel)^));
  handleExceptionEnd
end;

procedure CEFBrowser_RunFileDialog(const TObj: ICefBrowser; mode: integer; const PTitle, PDefaultFilePath: PChar; const acceptFilters: TStrings; const callback: ICefRunFileDialogCallback); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
  begin
    TObj.GetHost.RunFileDialog(mode, PCharToUStr(PTitle), PCharToUStr(PDefaultFilePath), acceptFilters, acceptFilters.Count, callback);
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_StartDownload(const TObj: ICefBrowser; const PUrl: PChar); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.StartDownload(PCharToUStr(PUrl));
  handleExceptionEnd
end;

procedure CEFBrowser_DownloadImage(); extdecl;
begin
end;

procedure CEFBrowser_Print(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.Print();
  handleExceptionEnd
end;

procedure CEFBrowser_PrintToPdf(const TObj: ICefBrowser; const PPath: PChar; const PSettings: PRCefPdfPrintSettings; const callback: ICefPdfPrintCallback); extdecl;
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
  if TObj.GetHost <> nil then
  begin
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
      if PSettings.margin_top <> nil then
       settings.margin_top := Trunc(Double(PSettings.margin_top^));
      if PSettings.margin_right <> nil then
       settings.margin_right := Trunc(Double(PSettings.margin_right^));
      if PSettings.margin_bottom <> nil then
       settings.margin_bottom := Trunc(Double(PSettings.margin_bottom^));
      if PSettings.margin_left <> nil then
       settings.margin_left := Trunc(Double(PSettings.margin_left^));
      if PSettings.header_template <> nil then
       settings.header_footer_title := CefString(PCharToUStr(PSettings.header_template));
      if PSettings.footer_template <> nil then
       settings.header_footer_url := CefString(PCharToUStr(PSettings.footer_template));
    end;
    TObj.GetHost.PrintToPdf(PCharToUStr(PPath), settings, callback)
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_SendKeyEvent(const TObj: ICefBrowser; const event: PCefKeyEvent); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SendKeyEvent(event);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseClickEvent(const TObj: ICefBrowser; const event: PCefMouseEvent; type_: integer; mouseUp: LongBool; clickCount: Integer); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SendMouseClickEvent(event, TCefMouseButtonType(type_), mouseUp, clickCount);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseMoveEvent(const TObj: ICefBrowser; const event: PCefMouseEvent; mouseLeave: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SendMouseMoveEvent(event, mouseLeave);
  handleExceptionEnd
end;

procedure CEFBrowser_SendMouseWheelEvent(const TObj: ICefBrowser; const event: PCefMouseEvent; deltaX, deltaY: Integer); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SendMouseWheelEvent(event, deltaX, deltaY);
  handleExceptionEnd
end;

procedure CEFBrowser_SendTouchEvent(); extdecl;
begin
end;

procedure CEFBrowser_SendCaptureLostEvent(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SendCaptureLostEvent;
  handleExceptionEnd
end;

procedure CEFBrowser_NotifyMoveOrResizeStarted(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

procedure CEFBrowser_NotifyScreenInfoChanged(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.NotifyScreenInfoChanged;
  handleExceptionEnd
end;

procedure CEFBrowser_ShowDevTools(const TObj: ICefBrowser; const Chromium: TChromium; const windowParent: TCEFWindowParent; PDevToolsWinName: PChar); extdecl;
var
  windowInfo: TCefWindowInfo;
  client: ICefClient;
  browserSettings: TCefBrowserSettings;
  devToolsWinName: ustring;
  APoint: TPoint;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
  begin
    Chromium.ShowDevTools(APoint, windowParent);
    // TODO 用 Chromium.ShowDevTools
    //if PDevToolsWinName <> nil then
    //begin
    //  devToolsWinName := PCharToUStr(PDevToolsWinName);
    //  if devToolsWinName = '' then
    //   devToolsWinName := DEVTOOLS_WINDOWNAME;
    //end
    //else
    //begin
    //  devToolsWinName := DEVTOOLS_WINDOWNAME;
    //end;
    //
    //try
    //  try
    //    FillChar(windowInfo, SizeOf(TCefWindowInfo), 0);
    //    WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect, devToolsWinName);
    //    client := TCustomClientHandler.Create(Chromium, False, False, False, False,
    //      False, False, False, False, False, False, False, False, False, False);
    //    FillChar(browserSettings, SizeOf(TCefBrowserSettings), 0);
    //    TObj.GetHost.ShowDevTools(@windowInfo, client, @browserSettings, nil);
    //  finally
    //    client := nil
    //  end;
    //except
    //on E: Exception do
    //  CallException(E);
    //end;
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_SendProcessMessage(const AObj: ICefBrowser; targetProcess: Integer; const message_: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  handleExceptionEnd
end;

procedure CEFBrowser_SendProcessMessageForJSONBytes(const AObj: ICefBrowser; const PName: PChar; targetProcess: Integer; const data: Pointer; dataSize: NativeUInt); extdecl;
var
  message_ : ICefProcessMessage;
begin
  handleExceptionBegin
  message_ := TCefProcessMessageRef.New(PCharToUStr(PName));
  message_.ArgumentList.SetBinary(0, TCefBinaryValueRef.New(data, dataSize));
  AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  message_.ArgumentList.Clear;
  handleExceptionEnd
end;

procedure CEFBrowser_SendProcessMessageForV8Value(const AObj: ICefBrowser; const PName: PChar; targetProcess: Integer; const arguments: ICefv8Value); extdecl;
var
  message_ : ICefProcessMessage;
begin
  handleExceptionBegin
  message_ := TValueConvert.V8ValueToProcessMessage(PCharToUStr(PName), arguments);
  if message_ <> nil then
  begin
    AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
    message_.ArgumentList.Clear;
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_CloseDevTools(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.CloseDevTools;
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

procedure CEFBrowser_GetFrameIdentifiers(const TObj: ICefBrowser; var Result: TStrings; var rFrameCount : NativeUInt; var rFrameIds: TCefFrameIdentifierArray); extdecl;
var
  frameIds : TStrings;
  idx: Integer;
  resultFrameCount : NativeUInt;
  resultFrameIds: TCefFrameIdentifierArray;
begin
  handleExceptionBegin
  TObj.GetFrameIdentifiers(resultFrameCount, resultFrameIds);
  rFrameCount := resultFrameCount;
  if resultFrameCount > 0 then
  begin
    rFrameIds := resultFrameIds;
    frameIds := TStringList.Create;
    for idx := 0 to resultFrameCount - 1 do
    begin
      frameIds.Add(IntToStr(resultFrameIds[idx]));
    end;
    Result := frameIds;
  end
  else
    Result := nil;
  handleExceptionEnd
end;

procedure CEFBrowser_Find(const TObj: ICefBrowser; PSearchText: PChar; forward_, matchCase, findNext: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.Find(TObj.Identifier, PCharToUStr(PSearchText), forward_, matchCase, findNext);
  handleExceptionEnd
end;

procedure CEFBrowser_StopFinding(const TObj: ICefBrowser; clearSelection: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.StopFinding(clearSelection);
  handleExceptionEnd
end;

procedure CEFBrowser_GetRequestContext(const TObj: ICefBrowser; var Result: ICefRequestContext); extdecl;
begin
  handleExceptionBegin
  Result := nil;
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.GetRequestContext();
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
  CEFBrowser_SendKeyEvent,
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
  CEFBrowser_GetFrameIdentifiers,
  CEFBrowser_Find,
  CEFBrowser_StopFinding,
  CEFBrowser_GetRequestContext,
  CEFBrowserRef_UnWrap,
  CEFBrowser_SendProcessMessage,
  CEFBrowser_SendProcessMessageForJSONBytes,
  CEFBrowser_SendProcessMessageForV8Value;
