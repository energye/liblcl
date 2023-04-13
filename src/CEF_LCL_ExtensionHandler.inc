//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefExtensionHandlerRef_CreateForChromium(const Chromium: TChromium; var Result: TCustomExtensionHandler); extdecl;
begin
  handleExceptionBegin
  Result := TCustomExtensionHandler.Create(Chromium);
  handleExceptionEnd
end;

procedure CefExtensionHandlerRef_Create(var Result: TExtensionHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TExtensionHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnExtensionLoadFailed(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.ExtensionLoadFailedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnExtensionLoaded(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.ExtensionLoadedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnExtensionUnloaded(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.ExtensionUnloadedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnBeforeBackgroundBrowser(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.BeforeBackgroundBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_OnBeforeBrowser(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.BeforeBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_GetActiveBrowser(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.GetActiveBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_CanAccessBrowser(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.CanAccessBrowserPtr := AEventData;
  handleExceptionEnd
end;

procedure CefExtensionHandler_GetExtensionResource(const TObj: TExtensionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.GetExtensionResourcePtr := AEventData;
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
    CefExtensionHandler_GetExtensionResource
;
