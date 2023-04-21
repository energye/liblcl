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
  CookieAccessFilter_CanSaveCookie
;
