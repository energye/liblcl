//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure RequestContextHandlerRef_Create(var Result: ICefRequestContextHandler); extdecl;
begin
  handleExceptionBegin
  Result := TRequestContextHandlerRef.Create;
  handleExceptionEnd
end;

procedure RequestContextHandler_OnGetCookieManager(const AObj: ICefRequestContextHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestContextHandlerRef).GetCookieManagerPtr := AEventData;
  handleExceptionEnd
end;

procedure RequestContextHandler_OnBeforePluginLoad(const AObj: ICefRequestContextHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestContextHandlerRef).OnBeforePluginLoadPtr := AEventData;
  handleExceptionEnd
end;

exports
  RequestContextHandlerRef_Create,
  RequestContextHandler_OnGetCookieManager,
  RequestContextHandler_OnBeforePluginLoad;
