//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure BrowserViewDelegateRef_Create(out Result: ICefBrowserViewDelegate) ; extdecl;
begin
  handleExceptionBegin
  Result := TBrowserViewDelegateRef.Create();
  handleExceptionEnd
end;

procedure BrowserViewDelegateRef_CreateForCustom(const events: ICefBrowserViewDelegateEvents; out Result: ICefBrowserViewDelegate) ; extdecl;
begin
  handleExceptionBegin
  Result := TCustomBrowserViewDelegate.Create(events);
  handleExceptionEnd
end;

procedure BrowserViewDelegate_SetOnBrowserCreated(const AObj: ICefBrowserViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TBrowserViewDelegateRef).OnBrowserCreatedPtr := AEvent;
  handleExceptionEnd
end;

procedure BrowserViewDelegate_SetOnBrowserDestroyed(const AObj: ICefBrowserViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TBrowserViewDelegateRef).OnBrowserDestroyedPtr := AEvent;
  handleExceptionEnd
end;

procedure BrowserViewDelegate_SetOnGetDelegateForPopupBrowserView(const AObj: ICefBrowserViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TBrowserViewDelegateRef).OnGetDelegateForPopupBrowserViewPtr := AEvent;
  handleExceptionEnd
end;

procedure BrowserViewDelegate_SetOnPopupBrowserViewCreated(const AObj: ICefBrowserViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TBrowserViewDelegateRef).OnPopupBrowserViewCreatedPtr := AEvent;
  handleExceptionEnd
end;

procedure BrowserViewDelegate_SetOnGetChromeToolbarType(const AObj: ICefBrowserViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TBrowserViewDelegateRef).OnGetChromeToolbarTypePtr := AEvent;
  handleExceptionEnd
end;

exports
  BrowserViewDelegateRef_Create,
  BrowserViewDelegateRef_CreateForCustom,
  BrowserViewDelegate_SetOnBrowserCreated,
  BrowserViewDelegate_SetOnBrowserDestroyed,
  BrowserViewDelegate_SetOnGetDelegateForPopupBrowserView,
  BrowserViewDelegate_SetOnPopupBrowserViewCreated,
  BrowserViewDelegate_SetOnGetChromeToolbarType;
