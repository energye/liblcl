//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaRouterRef_UnWrap(const AObj: ICefMediaRouter; out Result: ICefMediaRouter); extdecl;
begin
  handleExceptionBegin
  Result := TCefMediaRouterRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

procedure MediaRouterRef_Global(out Result: ICefMediaRouter); extdecl;
begin
  handleExceptionBegin
  Result := TCefMediaRouterRef.Global();
  handleExceptionEnd
end;

procedure   MediaRouter_AddObserver(const AObj: ICefMediaRouter; const observer: ICefMediaObserver; out Result: ICefRegistration); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AddObserver(observer);
  handleExceptionEnd
end;

procedure   MediaRouter_GetSource(const AObj: ICefMediaRouter; const urn: PChar; out Result: ICefMediaSource); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSource(PCharToUStr(urn));
  handleExceptionEnd
end;

procedure  MediaRouter_NotifyCurrentSinks(const AObj: ICefMediaRouter); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyCurrentSinks();
  handleExceptionEnd
end;

procedure  MediaRouter_CreateRoute(const AObj: ICefMediaRouter; const source: ICefMediaSource; const sink: ICefMediaSink; const callback: ICefMediaRouteCreateCallback); extdecl;
begin
  handleExceptionBegin
  AObj.CreateRoute(source, sink, callback);
  handleExceptionEnd
end;

procedure  MediaRouter_NotifyCurrentRoutes(const AObj: ICefMediaRouter); extdecl;
begin
  handleExceptionBegin
  AObj.NotifyCurrentRoutes();
  handleExceptionEnd
end;


exports
  MediaRouterRef_UnWrap,
  MediaRouterRef_Global,
  MediaRouter_AddObserver,
  MediaRouter_GetSource,
  MediaRouter_NotifyCurrentSinks,
  MediaRouter_CreateRoute,
  MediaRouter_NotifyCurrentRoutes;
