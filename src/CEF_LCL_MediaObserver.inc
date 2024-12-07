//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaObserverRef_Create(out Result: ICefMediaObserver); extdecl;
begin
  handleExceptionBegin
  Result := TMediaObserverRef.Create();
  handleExceptionEnd
end;

procedure MediaObserverRef_CustomCreate(const events: IChromiumEvents; out Result: ICefMediaObserver); extdecl;
begin
  handleExceptionBegin
  Result := TCustomMediaObserver.Create(events);
  handleExceptionEnd
end;

procedure MediaObserver_OnSinks(const AObj: ICefMediaObserver; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMediaObserverRef).OnSinksPtr := AEventData;
  handleExceptionEnd
end;

procedure MediaObserver_OnRoutes(const AObj: ICefMediaObserver; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMediaObserverRef).OnRoutesPtr := AEventData;
  handleExceptionEnd
end;

procedure MediaObserver_OnRouteStateChanged(const AObj: ICefMediaObserver; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMediaObserverRef).OnRouteStateChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure MediaObserver_OnRouteMessageReceived(const AObj: ICefMediaObserver; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMediaObserverRef).OnRouteMessageReceivedPtr := AEventData;
  handleExceptionEnd
end;


exports
  MediaObserverRef_Create,
  MediaObserverRef_CustomCreate,
  MediaObserver_OnSinks,
  MediaObserver_OnRoutes,
  MediaObserver_OnRouteStateChanged,
  MediaObserver_OnRouteMessageReceived;