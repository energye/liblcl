//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure RequestContextHandlerRef_Create(var Result: TRequestContextHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TRequestContextHandlerRef.Create;
  handleExceptionEnd
end;

procedure RequestContextHandlerRef_CreateForChromium(const Chromium: TChromium; var Result: ICefRequestContextHandler); extdecl;
begin
  handleExceptionBegin
  Result := TCustomRequestContextHandler.Create(Chromium);
  handleExceptionEnd
end;

procedure RequestContextHandler_OnRequestContextInitialized(const AObj: TRequestContextHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.RequestContextInitializedPtr := AEventData;
  handleExceptionEnd
end;

procedure RequestContextHandler_GetResourceRequestHandler(const AObj: TRequestContextHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.GetResourceRequestHandlerPtr := AEventData;
  handleExceptionEnd
end;

exports
  RequestContextHandlerRef_Create,
  RequestContextHandlerRef_CreateForChromium,
  RequestContextHandler_OnRequestContextInitialized,
  RequestContextHandler_GetResourceRequestHandler
;
