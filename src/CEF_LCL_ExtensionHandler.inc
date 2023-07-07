//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefExtensionHandlerRef_CreateForChromium(const Chromium: TChromium; var Result: ICefExtensionHandler); extdecl;
begin
  handleExceptionBegin
  Result := TCustomExtensionHandler.Create(Chromium);
  handleExceptionEnd
end;

procedure CefExtensionHandlerRef_Create(var Result: ICefExtensionHandler); extdecl;
begin
  handleExceptionBegin
  Result := TExtensionHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnExtensionLoadFailed(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).ExtensionLoadFailedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnExtensionLoaded(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).ExtensionLoadedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnExtensionUnloaded(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).ExtensionUnloadedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnBeforeBackgroundBrowser(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).BeforeBackgroundBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnBeforeBrowser(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).BeforeBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_GetActiveBrowser(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).GetActiveBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_CanAccessBrowser(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).CanAccessBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_GetExtensionResource(const TObj: ICefExtensionHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TExtensionHandlerRef).GetExtensionResourcePtr := AEventData;
  handleExceptionEnd
end;

exports
  CefExtensionHandlerRef_CreateForChromium,
  CefExtensionHandlerRef_Create,
  CefExtensionHandler_OnExtensionLoadFailed,
  CefExtensionHandler_OnExtensionLoaded,
  CefExtensionHandler_OnExtensionUnloaded,
  CefExtensionHandler_OnBeforeBackgroundBrowser,
  CefExtensionHandler_OnBeforeBrowser,
  CefExtensionHandler_GetActiveBrowser,
  CefExtensionHandler_CanAccessBrowser,
  CefExtensionHandler_GetExtensionResource;