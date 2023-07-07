//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== ResourceRequestHandler ==}
procedure ResourceRequestHandlerRef_Create(var Result: ICefResourceRequestHandler); extdecl;
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

procedure ResourceRequestHandler_GetCookieAccessFilter(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).GetCookieAccessFilterPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnBeforeResourceLoad(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).BeforeResourceLoadPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_GetResourceHandler(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).GetResourceHandlerPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnResourceRedirect(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).ResourceRedirectPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnResourceResponse(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).ResourceResponsePtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_GetResourceResponseFilter(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).GetResourceResponseFilterPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnResourceLoadComplete(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).ResourceLoadCompletePtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceRequestHandler_OnProtocolExecution(const AObj: ICefResourceRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceRequestHandlerRef).ProtocolExecutionPtr := AEventData;
  handleExceptionEnd
end;

{== CookieAccessFilter ==}
procedure CookieAccessFilterRef_Create(var Result: ICefCookieAccessFilter); extdecl;
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

procedure CookieAccessFilter_CanSendCookie(const AObj: ICefCookieAccessFilter; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TCookieAccessFilterRef).CanSendCookiePtr := AEventData;
  handleExceptionEnd
end;

procedure CookieAccessFilter_CanSaveCookie(const AObj: ICefCookieAccessFilter; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TCookieAccessFilterRef).CanSaveCookiePtr := AEventData;
  handleExceptionEnd
end;

{== ResourceHandler ==}
procedure ResourceHandlerRef_Create(const browser: ICefBrowser; const frame: ICefFrame; const schemeName: PChar; const request: ICefRequest; var Result: ICefResourceHandler); extdecl;
begin
  handleExceptionBegin
  Result := TResourceHandlerRef.Create(browser, frame, PCharToUStr(schemeName), request);
  handleExceptionEnd
end;

procedure ResourceHandler_Open(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).OpenPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_GetResponseHeaders(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).GetResponseHeadersPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_Skip(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).skipPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_Read(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).ReadPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_ProcessRequest(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).ProcessRequestPtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_ReadResponse(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).ReadResponsePtr := AEventData;
  handleExceptionEnd
end;

procedure ResourceHandler_Cancel(const AObj: ICefResourceHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TResourceHandlerRef).CancelPtr := AEventData;
  handleExceptionEnd
end;

exports
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
  CookieAccessFilterRef_Create,
  CookieAccessFilterRef_CreateForChromium,
  CookieAccessFilter_CanSendCookie,
  CookieAccessFilter_CanSaveCookie,
  ResourceHandlerRef_Create,
  ResourceHandler_Open,
  ResourceHandler_GetResponseHeaders,
  ResourceHandler_Skip,
  ResourceHandler_Read,
  ResourceHandler_ProcessRequest,
  ResourceHandler_ReadResponse,
  ResourceHandler_Cancel;