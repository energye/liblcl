//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFBrowserViewComponent_Create(const AOwner: TComponent; var Result: TCEFBrowserViewComponent) ; extdecl;
begin
  handleExceptionBegin
  Result := TCEFBrowserViewComponent.Create(AOwner);
  handleExceptionEnd
end;

function CEFBrowserViewComponent_CreateBrowserView(const TObj: TCEFBrowserViewComponent; client: ICefClient; url: PChar; var borwserSettings: PMCefBrowserSettings;
  const extra_info: ICefDictionaryValue; request_context: ICefRequestContext): LongBool; extdecl;
var
  TempBrowserSettings: TCefBrowserSettings;
begin
  handleExceptionBegin
  TempBrowserSettings := GoBrowserSettingsToCefBrowserSettings(borwserSettings);
  Result := TObj.CreateBrowserView(client, PCharToUStr(url), TempBrowserSettings, extra_info, request_context);
  handleExceptionEnd
end;

function CEFBrowserViewComponent_GetForBrowser(const TObj: TCEFBrowserViewComponent; const browser: ICefBrowser): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetForBrowser(browser);
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_SetPreferAccelerators(const TObj: TCEFBrowserViewComponent; prefer_accelerators: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SetPreferAccelerators(prefer_accelerators);
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_RequestFocus(const TObj: TCEFBrowserViewComponent); extdecl;
begin
  handleExceptionBegin
  TObj.RequestFocus;
  handleExceptionEnd
end;

//property
procedure CEFBrowserViewComponent_Browser(const TObj: TCEFBrowserViewComponent; out Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Browser;
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_BrowserView(const TObj: TCEFBrowserViewComponent; out Result: ICefBrowserView) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.BrowserView;
  handleExceptionEnd
end;

procedure CEFBrowserViewComponent_ChromeToolbar(const TObj: TCEFBrowserViewComponent; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := TObj.ChromeToolbar;
  handleExceptionEnd
end;

function CEFBrowserViewComponent_RuntimeStyle(const TObj: TCEFBrowserViewComponent): TCefRuntimeStyle; extdecl;
begin
  handleExceptionBegin
  Result := TObj.RuntimeStyle;
  handleExceptionEnd
end;

//event
procedure CEFBrowserViewComponent_SetOnBrowserCreated(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnBrowserCreated}
  {$DEFINE EventName := OnBrowserCreated}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnBrowserDestroyed(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnBrowserDestroyed}
  {$DEFINE EventName := OnBrowserDestroyed}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetDelegateForPopupBrowserView(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetDelegateForPopupBrowserView}
  {$DEFINE EventName := OnGetDelegateForPopupBrowserView}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnPopupBrowserViewCreated(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnPopupBrowserViewCreated}
  {$DEFINE EventName := OnPopupBrowserViewCreated}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetChromeToolbarType(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetChromeToolbarType}
  {$DEFINE EventName := OnGetChromeToolbarType}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnUseFramelessWindowForPictureInPicture(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnUseFramelessWindowForPictureInPicture}
  {$DEFINE EventName := OnUseFramelessWindowForPictureInPicture}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGestureCommand(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGestureCommand}
  {$DEFINE EventName := OnGestureCommand}
  EventMethodCode
end;

procedure CEFBrowserViewComponent_SetOnGetBrowserRuntimeStyle(const AObj: TCEFBrowserViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BrowserViewComponent_OnGetBrowserRuntimeStyle}
  {$DEFINE EventName := OnGetBrowserRuntimeStyle}
  EventMethodCode
end;


exports
  CEFBrowserViewComponent_Create,
  CEFBrowserViewComponent_CreateBrowserView,
  CEFBrowserViewComponent_GetForBrowser,
  CEFBrowserViewComponent_SetPreferAccelerators,
  CEFBrowserViewComponent_RequestFocus,
  CEFBrowserViewComponent_Browser,
  CEFBrowserViewComponent_BrowserView,
  CEFBrowserViewComponent_ChromeToolbar,
  CEFBrowserViewComponent_RuntimeStyle,
  CEFBrowserViewComponent_SetOnBrowserCreated,
  CEFBrowserViewComponent_SetOnBrowserDestroyed,
  CEFBrowserViewComponent_SetOnGetDelegateForPopupBrowserView,
  CEFBrowserViewComponent_SetOnPopupBrowserViewCreated,
  CEFBrowserViewComponent_SetOnGetChromeToolbarType,
  CEFBrowserViewComponent_SetOnUseFramelessWindowForPictureInPicture,
  CEFBrowserViewComponent_SetOnGestureCommand,
  CEFBrowserViewComponent_SetOnGetBrowserRuntimeStyle;
