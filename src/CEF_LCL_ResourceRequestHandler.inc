//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== ResourceRequestHandler ==}
procedure ResourceRequestHandlerRef_Create(var Result: TResourceRequestHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TResourceRequestHandlerRef.Create;
  handleExceptionEnd
end;

procedure ResourceRequestHandlerRef_CreateForChromium(const chromium: TChromium; var Result: ICefResourceRequestHandler); extdecl;
begin
  handleExceptionBegin
  Result := TCustomResourceRequestHandler.Create(chromium);
  handleExceptionEnd
end;

procedure ResourceRequestHandler_GetCookieAccessFilter(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.GetCookieAccessFilterPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnBeforeResourceLoad(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.BeforeResourceLoadPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_GetResourceHandler(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.GetResourceHandlerPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnResourceRedirect(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ResourceRedirectPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnResourceResponse(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ResourceResponsePtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_GetResourceResponseFilter(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.GetResourceResponseFilterPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnResourceLoadComplete(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ResourceLoadCompletePtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnProtocolExecution(const AObj: TResourceRequestHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ProtocolExecutionPtr := AEventData;
  handleExceptionEnd
end;

{== CookieAccessFilter ==}
procedure CookieAccessFilterRef_Create(var Result: TCookieAccessFilterRef); extdecl;
begin
  handleExceptionBegin
  Result := TCookieAccessFilterRef.Create;
  handleExceptionEnd
end;

procedure CookieAccessFilterRef_CreateForChromium(const chromium: TChromium; var Result: ICefCookieAccessFilter); extdecl;
begin
  handleExceptionBegin
  Result := TCustomCookieAccessFilter.Create(chromium);
  handleExceptionEnd
end;

procedure CookieAccessFilter_CanSendCookie(const AObj: TCookieAccessFilterRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.CanSendCookiePtr := AEventData;
  handleExceptionEnd
end;

procedure CookieAccessFilter_CanSaveCookie(const AObj: TCookieAccessFilterRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.CanSaveCookiePtr := AEventData;
  handleExceptionEnd
end;

{== ResourceHandler ==}
procedure ResourceHandlerRef_Create(const browser: ICefBrowser; const frame: ICefFrame; const schemeName: PChar; const request: ICefRequest; var Result: TResourceHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TResourceHandlerRef.Create(browser, frame, PCharToUStr(schemeName), request);
  handleExceptionEnd
end;

procedure ResourceHandler_Open(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.OpenPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_GetResponseHeaders(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.GetResponseHeadersPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_Skip(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.skipPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_Read(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ReadPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_ProcessRequest(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ProcessRequestPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_ReadResponse(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ReadResponsePtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_Cancel(const AObj: TResourceHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.CancelPtr := AEventData;
  handleExceptionEnd
end;

exports
  {== ResourceRequestHandler ==}
  ResourceRequestHandlerRef_Create,
  ResourceRequestHandlerRef_CreateForChromium,
  ResourceRequestHandler_GetCookieAccessFilter,
  ResourceRequestHandler_OnBeforeResourceLoad,
  ResourceRequestHandler_GetResourceHandler,
  ResourceRequestHandler_OnResourceRedirect,
  ResourceRequestHandler_OnResourceResponse,
  ResourceRequestHandler_GetResourceResponseFilter,
  ResourceRequestHandler_OnResourceLoadComplete,
  ResourceRequestHandler_OnProtocolExecution,
  {== CookieAccessFilter ==}
  CookieAccessFilterRef_Create,
  CookieAccessFilterRef_CreateForChromium,
  CookieAccessFilter_CanSendCookie,
  CookieAccessFilter_CanSaveCookie,
  {== ResourceHandler ==}
  ResourceHandlerRef_Create,
  ResourceHandler_Open,
  ResourceHandler_GetResponseHeaders,
  ResourceHandler_Skip,
  ResourceHandler_Read,
  ResourceHandler_ProcessRequest,
  ResourceHandler_ReadResponse,
  ResourceHandler_Cancel
;
