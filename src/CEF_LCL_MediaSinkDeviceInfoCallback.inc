//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaRouteCreateCallbackRef_Create(out Result: ICefMediaRouteCreateCallback); extdecl;
begin
  handleExceptionBegin
  Result := TMediaRouteCreateCallbackRef.Create();
  handleExceptionEnd
end;

procedure MediaRouteCreateCallbackRef_CustomCreate(const events: IChromiumEvents; out Result: ICefMediaRouteCreateCallback); extdecl;
begin
  handleExceptionBegin
  Result := TCefCustomMediaRouteCreateCallback.Create(events);
  handleExceptionEnd
end;

procedure MediaRouteCreateCallback_OnMediaRouteCreateFinished(const AObj: ICefMediaRouteCreateCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMediaRouteCreateCallbackRef).OnMediaRouteCreateFinishedPtr := AEventData;
  handleExceptionEnd
end;

exports
  MediaRouteCreateCallbackRef_Create,
  MediaRouteCreateCallbackRef_CustomCreate,
  MediaRouteCreateCallback_OnMediaRouteCreateFinished;
