//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

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
  ResourceHandlerRef_Create,
  ResourceHandler_Open,
  ResourceHandler_GetResponseHeaders,
  ResourceHandler_Skip,
  ResourceHandler_Read,
  ResourceHandler_ProcessRequest,
  ResourceHandler_ReadResponse,
  ResourceHandler_Cancel;
