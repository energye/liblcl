//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFChromium_Free(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Free();
  handleExceptionEnd
end;

function CEFChromium_GetHashCode(const AObj: TChromium):Integer ; extdecl;
begin
  {$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result := AObj.GetHashCode();
  handleExceptionEnd
end;

function CEFChromium_ClassName(const AObj: TChromium):PChar ; extdecl;
begin
  {$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result := ToPChar(AObj.ClassName());
  handleExceptionEnd
end;

function CEFChromium_Equals(const AObj: TChromium; Obj: TObject): LongBool; extdecl;
begin
  {$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result := AObj.Equals(Obj);
  handleExceptionEnd
end;

function CEFChromium_ClassType(const AObj: TChromium): TClass; extdecl;
begin
  {$ifdef UsehandleException}Result := TClass(nil);{$endif}
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

function CEFChromium_InstanceSize(const AObj: TChromium): Integer; extdecl;
begin
  {$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result := AObj.InstanceSize;
  handleExceptionEnd
end;

function CEFChromium_InheritsFrom(const AObj: TChromium; AClass: TClass): LongBool; extdecl;
begin
  {$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

function CEFChromium_ToString(const AObj: TChromium): PChar; extdecl;
begin
  {$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

function CEFChromium_Create(const AOwner: TComponent): TChromium; extdecl;
begin
  handleExceptionBegin
  Result := TChromium.Create(AOwner);
  handleExceptionEnd
end;

procedure CEFChromium_Browser(const AObj: TChromium; var Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := AObj.Browser;
  handleExceptionEnd
end;

function CEFChromium_BrowserId(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BrowserId;
  handleExceptionEnd
end;

procedure CEFChromium_SetDefaultURL(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultUrl:= PCharToUStr(AURL);
  handleExceptionEnd
end;

procedure CEFChromium_LoadURL(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadURL(PCharToUStr(AURL));
  handleExceptionEnd
end;

procedure CEFChromium_LoadString(const AObj: TChromium; AHTML: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.LoadString(PCharToUStr(AHTML));
  handleExceptionEnd
end;

procedure CEFChromium_StartDownload(const AObj: TChromium; AURL: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.StartDownload(PCharToUStr(AURL));
  handleExceptionEnd
end;


procedure CEFChromium_Reload(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Reload;
  handleExceptionEnd
end;

procedure CEFChromium_ReloadIgnoreCache(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ReloadIgnoreCache;
  handleExceptionEnd
end;

procedure CEFChromium_StopLoad(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.StopLoad;
  handleExceptionEnd
end;

function CEFChromium_CreateBrowser(const AObj: TChromium; window: TCEFWindowParent; const windowName: PChar; context: ICefRequestContext; const extraInfo: ICefDictionaryValue): LongBool; extdecl;
var
  aCookiesPath: string;
  aPersistSessionCookies: boolean;
begin
  handleExceptionBegin
  if extraInfo <> nil then
  begin
    aCookiesPath := extraInfo.GetString('cookiesPath');
    aPersistSessionCookies := extraInfo.GetBool('persistSessionCookies');
  end;
  if window = nil then
  begin
    Result := AObj.CreateBrowser(nil, PCharToUStr(windowName), context, aCookiesPath, aPersistSessionCookies);
  end
  else
  begin
    Result := AObj.CreateBrowser(window.Handle, window.BoundsRect, PCharToUStr(windowName), context, aCookiesPath, aPersistSessionCookies);
  end;
  handleExceptionEnd
end;

function CEFChromium_CreateBrowserByWindow(const AObj: TChromium; window: TCEFWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  if window = nil then
    Result := AObj.CreateBrowser(nil, '')
  else
    Result := AObj.CreateBrowser(window.Handle, window.BoundsRect);
  handleExceptionEnd
end;

function CEFChromium_Initialized(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Initialized;
  handleExceptionEnd
end;

function CEFChromium_IsSameBrowser(const AObj: TChromium; const that: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSameBrowser(that);
  handleExceptionEnd
end;

procedure CEFChromium_PrintToPDF(const AObj: TChromium; FilePath: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.PrintToPDF(PCharToUStr(FilePath),  AObj.Browser.MainFrame.GetName, AObj.Browser.MainFrame.Url);
  handleExceptionEnd
end;

procedure CEFChromium_Print(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.Print;
  handleExceptionEnd
end;

procedure CEFChromium_BrowserZoom(const AObj: TChromium; Zoom: integer); extdecl;
begin
  handleExceptionBegin
  if Zoom = 0 then
   AObj.ResetZoomStep
  else if Zoom = 1 then
   AObj.IncZoomStep
  else if Zoom = 2 then
   AObj.DecZoomStep;
  handleExceptionEnd
end;

procedure CEFChromium_GoBackForward(const AObj: TChromium; BackForward: integer); extdecl;
begin
  handleExceptionBegin
  if BackForward = 0 then
    AObj.GoBack
  else if BackForward = 1 then
    AObj.GoForward;
  handleExceptionEnd
end;

procedure CEFChromium_NotifyMoveOrResizeStarted(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyMoveOrResizeStarted;
  handleExceptionEnd
end;

procedure CEFChromium_Invalidate(const AObj: TChromium; type_: Integer); extdecl;
begin
  handleExceptionBegin
  // TCefPaintElementType
  AObj.Invalidate(TCefPaintElementType(type_));
  handleExceptionEnd
end;

procedure CEFChromium_CloseBrowser(const AObj: TChromium; forceClose: LongBool); extdecl;
begin
  handleExceptionBegin
  try
  AObj.CloseBrowser(forceClose);
  except
  on E: Exception do
   CallException(E);
  end;
  handleExceptionEnd
end;

procedure CEFChromium_ExecuteJavaScript(const AObj: TChromium; aCode, aScriptURL : PChar; startLine: integer = 0); extdecl;
var
  code, scriptURL : ustring;
begin
  handleExceptionBegin
  code := PCharToUStr(aCode);
  scriptURL := PCharToUStr(aScriptURL);
  if scriptURL = '' then
  begin
    scriptURL := 'about:blank';
  end;
  AObj.ExecuteJavaScript(code, scriptURL, startLine);
  handleExceptionEnd
end;

procedure CEFChromium_ShowDevTools(const AObj: TChromium); extdecl;
var
  point: TPoint;
begin
  handleExceptionBegin
  point.x := 100;
  point.y := 100;
  AObj.ShowDevTools(point, nil);
  handleExceptionEnd
end;

procedure CEFChromium_ShowDevToolsByWindowParent(const AObj: TChromium; windowParent: TCEFWindowParent); extdecl;
var
  point: TPoint;
begin
  handleExceptionBegin
  point.x := 0;
  point.y := 0;
  AObj.ShowDevTools(point, windowParent);
  handleExceptionEnd
end;

procedure CEFChromium_CloseDevTools(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.CloseDevTools(nil);
  handleExceptionEnd
end;

procedure CEFChromium_CloseDevToolsByWindowParent(const AObj: TChromium; windowParent: TCEFWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.CloseDevTools(windowParent);
  handleExceptionEnd
end;


procedure CEFChromium_DeleteCookies(const AObj: TChromium; PUrl: PChar; PCookieName: PChar; DeleteImmediately: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DeleteCookies();
  handleExceptionEnd
end;

//cookie end

procedure CEFChromium_SetProxy(const AObj: TChromium; const proxy: PRChromiumProxy); extdecl;
begin
  handleExceptionBegin
  AObj.ProxyType := Integer(proxy.ProxyType);
  AObj.ProxyScheme := TCefProxyScheme(Integer(proxy.ProxyScheme));
  AObj.ProxyServer := PCharToUStr(proxy.ProxyServer);
  AObj.ProxyPort := Integer(proxy.ProxyPort);
  AObj.ProxyUsername := PCharToUStr(proxy.ProxyUsername);
  AObj.ProxyPassword := PCharToUStr(proxy.ProxyPassword);
  AObj.ProxyScriptURL := PCharToUStr(proxy.ProxyScriptURL);
  AObj.ProxyByPassList := PCharToUStr(proxy.ProxyByPassList);
  handleExceptionEnd
end;

procedure CEFChromium_UpdatePreferences(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.UpdatePreferences;
  handleExceptionEnd
end;

function CEFChromium_CreateClientHandler(const AObj: TChromium; var client: ICefClient; alsOSR: LongBool): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.CreateClientHandler(client, alsOSR);
  handleExceptionEnd
end;

procedure CEFChromium_SetFocus(const AObj: TChromium; Value: LongBool);extdecl;
begin
  handleExceptionBegin
  AObj.SetFocus(Value);
  handleExceptionEnd
end;

procedure CEFChromium_SendKeyEvent(const TObj: TChromium; const event: PCefKeyEvent); extdecl;
begin
  handleExceptionBegin
  TObj.SendKeyEvent(event);
  handleExceptionEnd
end;

procedure CEFChromium_SendMouseClickEvent(const TObj: TChromium; const event: PCefMouseEvent; type_: integer; mouseUp: LongBool; clickCount: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseClickEvent(event, TCefMouseButtonType(type_), mouseUp, clickCount);
  handleExceptionEnd
end;

procedure CEFChromium_SendMouseMoveEvent(const TObj: TChromium; const event: PCefMouseEvent; mouseLeave: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseMoveEvent(event, mouseLeave);
  handleExceptionEnd
end;

procedure CEFChromium_SendMouseWheelEvent(const TObj: TChromium; const event: PCefMouseEvent; deltaX, deltaY: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseWheelEvent(event, deltaX, deltaY);
  handleExceptionEnd
end;

procedure CEFChromium_SendCaptureLostEvent(const AObj: TChromium);extdecl;
begin
  handleExceptionBegin
  AObj.SendCaptureLostEvent;
  handleExceptionEnd
end;

function CEFChromium_FrameIsFocused(const AObj: TChromium): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.FrameIsFocused;
  handleExceptionEnd
end;

function CEFChromium_BrowserHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.BrowserHandle;
  handleExceptionEnd
end;

function CEFChromium_WidgetHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.WidgetHandle;
  handleExceptionEnd
end;

function CEFChromium_RenderHandle(const AObj: TChromium): THandle ; extdecl;
begin
  handleExceptionBegin
  Result:= AObj.RenderHandle;
  handleExceptionEnd
end;

//CustomHeader
procedure CEFChromium_SetCustomHeader(const AObj: TChromium; PCustomHeader: PRCustomHeader); extdecl;
begin
  handleExceptionBegin
  AObj.CustomHeaderName  := PCharToUStr(PCustomHeader.CustomHeaderName);
  AObj.CustomHeaderValue := PCharToUStr(PCustomHeader.CustomHeaderValue);
  handleExceptionEnd
end;

function CEFChromium_GetCustomHeader(const AObj: TChromium): PRCustomHeader; extdecl;
var
  CustomHeader: PRCustomHeader;
begin
  handleExceptionBegin
  CustomHeader := new(PRCustomHeader);
  CustomHeader.CustomHeaderName := PChar(string(AObj.CustomHeaderName));
  CustomHeader.CustomHeaderValue := PChar(string(AObj.CustomHeaderValue));
  Result := CustomHeader;
  handleExceptionEnd
end;

//WebRTCIPHandlingPolicy
procedure CEFChromium_SetWebRTCIPHandlingPolicy(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = hpDisableNonProxiedUDP
  AObj.WebRTCIPHandlingPolicy := TCefWebRTCHandlingPolicy(value); //defalt hpDefault
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCIPHandlingPolicy(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.WebRTCIPHandlingPolicy);
  handleExceptionEnd
end;

//WebRTCMultipleRoutes
procedure CEFChromium_SetWebRTCMultipleRoutes(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = STATE_DISABLED
  AObj.WebRTCMultipleRoutes := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCMultipleRoutes(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.WebRTCMultipleRoutes);
  handleExceptionEnd
end;

//WebRTCNonproxiedUDP
procedure CEFChromium_SetWebRTCNonproxiedUDP(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏 = STATE_DISABLED
  AObj.WebRTCNonproxiedUDP := TCefState(value); //defalt STATE_DEFAULT
  handleExceptionEnd
end;

function CEFChromium_GetWebRTCNonproxiedUDP(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.WebRTCNonproxiedUDP);
  handleExceptionEnd
end;

//BatterySaverModeState
procedure CEFChromium_SetBatterySaverModeState(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFChromium_GetBatterySaverModeState(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := -1;
  handleExceptionEnd
end;

//HighEfficiencyMode
procedure CEFChromium_SetHighEfficiencyMode(const AObj: TChromium; value: Integer); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFChromium_GetHighEfficiencyMode(const AObj: TChromium): Integer; extdecl;
begin
  handleExceptionBegin
  Result := -1;
  handleExceptionEnd
end;

procedure CEFChromium_SetDragOperations(const AObj: TChromium; value: Cardinal); extdecl;
begin
  handleExceptionBegin
  AObj.DragOperations := value; //default DRAG_OPERATION_NONE
  handleExceptionEnd
end;

function CEFChromium_GetDragOperations(const AObj: TChromium): Cardinal; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DragOperations;
  handleExceptionEnd
end;

function CEFChromium_GetFrameCount(const AObj: TChromium): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.FrameCount;
  handleExceptionEnd
end;

procedure CEFChromium_SetSpellCheckerDicts(const AObj: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SpellCheckerDicts := PCharToUStr(value); //default ''
  handleExceptionEnd
end;

function CEFChromium_GetSpellCheckerDicts(const AObj: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.SpellCheckerDicts));
  handleExceptionEnd
end;

procedure CEFChromium_SetSpellChecking(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SpellChecking := value; //default True
  handleExceptionEnd
end;

function CEFChromium_GetSpellChecking(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SpellChecking;
  handleExceptionEnd
end;

procedure CEFChromium_SetAlwaysOpenPDFExternally(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysOpenPDFExternally(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  handleExceptionEnd
end;

procedure CEFChromium_SetAlwaysAuthorizePlugins(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AlwaysAuthorizePlugins := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAlwaysAuthorizePlugins(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AlwaysAuthorizePlugins;
  handleExceptionEnd
end;

procedure CEFChromium_SetAllowOutdatedPlugins(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AllowOutdatedPlugins := value; //default False
  handleExceptionEnd
end;

function CEFChromium_GetAllowOutdatedPlugins(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AllowOutdatedPlugins;
  handleExceptionEnd
end;

procedure CEFChromium_SetSendReferrer(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SendReferrer := value; //default = True
  handleExceptionEnd
end;

function CEFChromium_GetSendReferrer(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SendReferrer;
  handleExceptionEnd
end;

procedure CEFChromium_SetDoNotTrack(const AObj: TChromium; value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DoNotTrack := value; //default = True
  handleExceptionEnd
end;

function CEFChromium_GetDoNotTrack(const AObj: TChromium): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DoNotTrack;
  handleExceptionEnd
end;

procedure CEFChromium_SetZoomStep(const AObj: TChromium; value: byte); extdecl;
begin
  handleExceptionBegin
  AObj.ZoomStep := value; //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

function CEFChromium_GetZoomStep(const AObj: TChromium): byte; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ZoomStep;
  handleExceptionEnd
end;

procedure CEFChromium_SetZoomPct(const AObj: TChromium; value: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ZoomPct := Double(PDouble(value)^); //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

procedure CEFChromium_GetZoomPct(const AObj: TChromium; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ZoomPct;
  handleExceptionEnd
end;

procedure CEFChromium_SetZoomLevel(const AObj: TChromium; value: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ZoomLevel := Double(PDouble(value)^); //default = ZOOM_STEP_DEF
  handleExceptionEnd
end;

procedure CEFChromium_GetZoomLevel(const AObj: TChromium; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ZoomLevel;
  handleExceptionEnd
end;

procedure CEFChromium_SetDefaultEncoding(const AObj: TChromium; value: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.DefaultEncoding := PCharToUStr(value); //default = ''
  handleExceptionEnd
end;

function CEFChromium_GetDefaultEncoding(const AObj: TChromium): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.DefaultEncoding));
  handleExceptionEnd
end;

procedure CEFChromium_SendProcessMessage(const AObj: TChromium; targetProcess: Integer; const message_: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  handleExceptionEnd
end;

procedure CEFChromium_SendProcessMessageForJSONBytes(const AObj: TChromium; const PName: PChar; targetProcess: Integer; const data: Pointer; dataSize: NativeUInt); extdecl;
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

procedure CEFChromium_CefClient(const AObj: TChromium; var Result: ICefClient); extdecl;
begin
  handleExceptionBegin
  Result := AObj.CefClient;
  handleExceptionEnd
end;

procedure CEFChromium_SendProcessMessageForV8Value(const AObj: TChromium; const PName: PChar; targetProcess: Integer; const arguments: ICefv8Value); extdecl;
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

procedure  CEFChromium_SimulateMouseWheel(const AObj: TChromium; aDeltaX, aDeltaY : integer); extdecl;
begin
  handleExceptionBegin
  AObj.SimulateMouseWheel(aDeltaX, aDeltaY);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveHTMLByFrameName(const AObj: TChromium; const aFrameName : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveHTML(PCharToUStr(aFrameName));
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveHTMLByFrame(const AObj: TChromium; const aFrame : ICefFrame); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveHTML(aFrame);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveHTMLByFrameIdentifier(const AObj: TChromium; var aFrameIdentifier : int64); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveHTML(aFrameIdentifier);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveTextByFrameName(const AObj: TChromium; const aFrameName : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveText(PCharToUStr(aFrameName));
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveTextByFrame(const AObj: TChromium; const aFrame : ICefFrame); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveText(aFrame);
  handleExceptionEnd
end;

procedure  CEFChromium_RetrieveTextByFrameIdentifier(const AObj: TChromium; var aFrameIdentifier : int64); extdecl;
begin
  handleExceptionBegin
  AObj.RetrieveText(aFrameIdentifier);
  handleExceptionEnd
end;

procedure  CEFChromium_ResolveHost(const AObj: TChromium; const aURL : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.ResolveHost(PCharToUStr(aURL));
  handleExceptionEnd
end;

//procedure  CEFChromium_ClearCache(const AObj: TChromium); extdecl;
//begin
//  handleExceptionBegin
//  //AObj.ClearCache();
//  //ExecuteDevToolsMethod(0, 'Network.clearBrowserCache', nil);
//  handleExceptionEnd
//end;

procedure  CEFChromium_ClipboardCopy(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardCopy();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardPaste(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardPaste();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardCut(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardCut();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardUndo(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardUndo();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardRedo(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardRedo();
  handleExceptionEnd
end;

procedure  CEFChromium_ClipboardDel(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ClipboardDel();
  handleExceptionEnd
end;

procedure  CEFChromium_SelectAll(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.SelectAll();
  handleExceptionEnd
end;

procedure  CEFChromium_IncZoomStep(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.IncZoomStep();
  handleExceptionEnd
end;

procedure  CEFChromium_DecZoomStep(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.DecZoomStep();
  handleExceptionEnd
end;

procedure  CEFChromium_ResetZoomStep(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.ResetZoomStep();
  handleExceptionEnd
end;

procedure  CEFChromium_WasResized(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.WasResized();
  handleExceptionEnd
end;

procedure  CEFChromium_WasHidden(const AObj: TChromium; hidden: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.WasHidden(hidden);
  handleExceptionEnd
end;

procedure  CEFChromium_NotifyScreenInfoChanged(const AObj: TChromium); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyScreenInfoChanged();
  handleExceptionEnd
end;

procedure CEFChromium_InitializeDragAndDrop(const AObj: TChromium; const aDropTargetCtrl : TWinControl);
begin
  handleExceptionBegin
  AObj.InitializeDragAndDrop(aDropTargetCtrl);
  handleExceptionEnd
end;

exports
  CEFChromium_Create,
  CEFChromium_Browser,
  CEFChromium_BrowserId,
  CEFChromium_SetDefaultURL,
  CEFChromium_LoadURL,
  CEFChromium_LoadString,
  CEFChromium_StartDownload,
  CEFChromium_Reload,
  CEFChromium_ReloadIgnoreCache,
  CEFChromium_StopLoad,
  CEFChromium_CreateBrowser,
  CEFChromium_CreateBrowserByWindow,
  CEFChromium_Initialized,
  CEFChromium_IsSameBrowser,
  CEFChromium_PrintToPDF,
  CEFChromium_Print,
  CEFChromium_BrowserZoom,
  CEFChromium_GoBackForward,
  CEFChromium_NotifyMoveOrResizeStarted,
  CEFChromium_Invalidate,
  CEFChromium_CloseBrowser,
  CEFChromium_ExecuteJavaScript,
  CEFChromium_ShowDevTools,
  CEFChromium_ShowDevToolsByWindowParent,
  CEFChromium_CloseDevTools,
  CEFChromium_CloseDevToolsByWindowParent,
  CEFChromium_Free,
  CEFChromium_GetHashCode,
  CEFChromium_ClassName,
  CEFChromium_Equals,
  CEFChromium_ClassType,
  CEFChromium_InstanceSize,
  CEFChromium_InheritsFrom,
  CEFChromium_ToString,
  CEFChromium_DeleteCookies,
  CEFChromium_SetProxy,
  CEFChromium_UpdatePreferences,
  CEFChromium_CreateClientHandler,
  CEFChromium_SetFocus,
  CEFChromium_SendKeyEvent,
  CEFChromium_SendMouseClickEvent,
  CEFChromium_SendMouseMoveEvent,
  CEFChromium_SendMouseWheelEvent,
  CEFChromium_SendCaptureLostEvent,
  CEFChromium_FrameIsFocused,
  CEFChromium_BrowserHandle,
  CEFChromium_WidgetHandle,
  CEFChromium_RenderHandle,
  CEFChromium_SetCustomHeader,//
  CEFChromium_GetCustomHeader,
  CEFChromium_SetWebRTCIPHandlingPolicy,
  CEFChromium_GetWebRTCIPHandlingPolicy,
  CEFChromium_SetWebRTCMultipleRoutes,
  CEFChromium_GetWebRTCMultipleRoutes,
  CEFChromium_SetWebRTCNonproxiedUDP,
  CEFChromium_GetWebRTCNonproxiedUDP,
  CEFChromium_SetBatterySaverModeState,
  CEFChromium_GetBatterySaverModeState,
  CEFChromium_SetHighEfficiencyMode,
  CEFChromium_GetHighEfficiencyMode,
  CEFChromium_SetDragOperations,
  CEFChromium_GetDragOperations,
  CEFChromium_GetFrameCount,
  CEFChromium_SetSpellCheckerDicts,
  CEFChromium_GetSpellCheckerDicts,
  CEFChromium_SetSpellChecking,
  CEFChromium_GetSpellChecking,
  CEFChromium_SetAlwaysOpenPDFExternally,
  CEFChromium_GetAlwaysOpenPDFExternally,
  CEFChromium_SetAlwaysAuthorizePlugins,
  CEFChromium_GetAlwaysAuthorizePlugins,
  CEFChromium_SetAllowOutdatedPlugins,
  CEFChromium_GetAllowOutdatedPlugins,
  CEFChromium_SetSendReferrer,
  CEFChromium_GetSendReferrer,
  CEFChromium_SetDoNotTrack,
  CEFChromium_GetDoNotTrack,
  CEFChromium_SetZoomStep,
  CEFChromium_GetZoomStep,
  CEFChromium_SetZoomPct,
  CEFChromium_GetZoomPct,
  CEFChromium_SetZoomLevel,
  CEFChromium_GetZoomLevel,
  CEFChromium_SetDefaultEncoding,
  CEFChromium_GetDefaultEncoding,
  CEFChromium_SendProcessMessage,
  CEFChromium_SendProcessMessageForJSONBytes,
  CEFChromium_CefClient,
  CEFChromium_SendProcessMessageForV8Value,
  CEFChromium_SimulateMouseWheel,
  CEFChromium_RetrieveHTMLByFrameName,
  CEFChromium_RetrieveHTMLByFrame,
  CEFChromium_RetrieveHTMLByFrameIdentifier,
  CEFChromium_RetrieveTextByFrameName,
  CEFChromium_RetrieveTextByFrame,
  CEFChromium_RetrieveTextByFrameIdentifier,
  CEFChromium_ResolveHost,
  CEFChromium_ClipboardCopy,
  CEFChromium_ClipboardPaste,
  CEFChromium_ClipboardCut,
  CEFChromium_ClipboardUndo,
  CEFChromium_ClipboardRedo,
  CEFChromium_ClipboardDel,
  CEFChromium_SelectAll,
  CEFChromium_IncZoomStep,
  CEFChromium_DecZoomStep,
  CEFChromium_ResetZoomStep,
  CEFChromium_WasResized,
  CEFChromium_WasHidden,
  CEFChromium_NotifyScreenInfoChanged,
  CEFChromium_InitializeDragAndDrop;
