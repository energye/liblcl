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

procedure CEFBrowser_GetFrameById(const TObj: ICefBrowser; frameId: PChar; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetFrameByIdentifier(PCharToUStr(frameId));
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
  Result := TObj.GetFrameByName(PCharToUStr(PName));
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
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.TryCloseBrowser();
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
    TObj.GetHost.RunFileDialog(mode, PCharToUStr(PTitle), PCharToUStr(PDefaultFilePath), acceptFilters, callback);
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

procedure CEFBrowser_DownloadImage(const TObj: ICefBrowser; const PImageUrl: PChar; isFavicon: LongBool; maxImageSize: integer; bypassCache: LongBool; const callback: ICefDownloadImageCallback); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
  begin
    TObj.GetHost.DownloadImage(PCharToUStr(PImageUrl), isFavicon, maxImageSize, bypassCache, callback);
  end;
  handleExceptionEnd
end;

procedure CEFBrowser_Print(const TObj: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  if TObj.Host <> nil then
    TObj.Host.Print();
  handleExceptionEnd
end;

procedure CEFBrowser_PrintToPdf(const TObj: ICefBrowser; const PPath: PChar; var pdfPrintSettings: PMCefPdfPrintSettings; const callback: ICefPdfPrintCallback); extdecl;
var
  TempSettings: TCefPdfPrintSettings;
begin
  handleExceptionBegin
  if TObj.Host <> nil then
  begin
    TempSettings := PdfPrintSettingsToPas(pdfPrintSettings);
    TObj.Host.PrintToPdf(PCharToUStr(PPath), @TempSettings, callback);
  end;
  handleExceptionEnd
end;

function CEFBrowser_SendDevToolsMessage(const TObj: ICefBrowser; const message_: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.SendDevToolsMessage(PCharToUStr(message_));
  handleExceptionEnd
end;

function CEFBrowser_ExecuteDevToolsMethod(const TObj: ICefBrowser; messageId: integer; const PMethod: PChar; const dictionaryValue: ICefDictionaryValue): Integer; extdecl;
begin
  handleExceptionBegin
  Result := 0;
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.ExecuteDevToolsMethod(messageId, PCharToUStr(PMethod), dictionaryValue);
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

procedure CEFBrowser_SendTouchEvent(const TObj: ICefBrowser; const event: PCefTouchEvent); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SendTouchEvent(event);
  handleExceptionEnd
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

procedure CEFBrowser_SetAccessibilityState(const TObj: ICefBrowser; accessibilityState: Integer); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SetAccessibilityState(TCefState(accessibilityState));
  handleExceptionEnd
end;

procedure CEFBrowser_SetAutoResizeEnabled(const TObj: ICefBrowser; enabled: LongBool; const min_size, max_size: PCefSize); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SetAutoResizeEnabled(enabled, min_size, max_size);
  handleExceptionEnd
end;

procedure CEFBrowser_SetAudioMuted(const TObj: ICefBrowser; mute: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.SetAudioMuted(mute);
  handleExceptionEnd
end;

function CEFBrowser_IsAudioMuted(const TObj: ICefBrowser) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  if TObj.GetHost <> nil then
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
  if TObj.GetHost <> nil then
  begin
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

  //try
  //  try
  //  WindowInfoAsPopUp(windowInfo, TObj.Host.WindowHandle, devToolsWinName);
  //  client := TCustomClientHandler.Create(Chromium, True);
  //  FillChar(browserSettings, SizeOf(TCefBrowserSettings), 0);
  //  TObj.Host.ShowDevTools(@windowInfo, client, @browserSettings, nil);
  //  finally
  //  client:=nil;
  //  end;
  //except
  //  on E: Exception do
  //  CallException(E);
  //end;

  try
    try
      FillChar(windowInfo, SizeOf(TCefWindowInfo), 0);
      WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect);
      client := TCustomClientHandler.Create(Chromium, True);
      FillChar(browserSettings, SizeOf(TCefBrowserSettings), 0);
      TObj.GetHost.ShowDevTools(@windowInfo, client, @browserSettings, nil);
    finally
      client := nil
    end;
  except
  on E: Exception do
    CallException(E);
  end;

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

function CEFBrowser_HasView(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  if TObj.GetHost <> nil then
    Result := TObj.GetHost.HasView;
  handleExceptionEnd
end;

function CEFBrowser_HasDevTools(const TObj: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  if TObj.GetHost <> nil then
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

function CEFBrowser_GetFrameIdentifiers(const TObj: ICefBrowser; var ResultIds: TStrings): Boolean; extdecl;
var
  frameIds : TStrings;
begin
  handleExceptionBegin
  frameIds := TStringList.Create;
  Result := TObj.GetFrameIdentifiers(frameIds);
  ResultIds := frameIds;
  handleExceptionEnd
end;

procedure CEFBrowser_Find(const TObj: ICefBrowser; PSearchText: PChar; forward_, matchCase, findNext: LongBool); extdecl;
begin
  handleExceptionBegin
  if TObj.GetHost <> nil then
    TObj.GetHost.Find(PCharToUStr(PSearchText), forward_, matchCase, findNext);
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
  CEFBrowser_HasView,
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
  CEFBrowser_SendDevToolsMessage,
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
  CEFBrowser_GetFrameIdentifiers,
  CEFBrowser_Find,
  CEFBrowser_StopFinding,
  CEFBrowser_GetRequestContext,
  CEFBrowserRef_UnWrap;
