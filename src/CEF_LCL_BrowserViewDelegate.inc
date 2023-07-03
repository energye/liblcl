//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure BrowserViewDelegateRef_Create(out Result: TBrowserViewDelegateRef) ; extdecl;
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

procedure BrowserViewDelegate_SetOnBrowserCreated(const AObj: TBrowserViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.BrowserCreatedPtr := AEvent;
end;

procedure BrowserViewDelegate_SetOnBrowserDestroyed(const AObj: TBrowserViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.BrowserDestroyedPtr := AEvent;
end;

procedure BrowserViewDelegate_SetOnGetDelegateForPopupBrowserView(const AObj: TBrowserViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.GetDelegateForPopupBrowserViewPtr := AEvent;
end;

procedure BrowserViewDelegate_SetOnPopupBrowserViewCreated(const AObj: TBrowserViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.PopupBrowserViewCreatedPtr := AEvent;
end;

function BrowserViewDelegate_GetChromeToolbarType(const AObj: TBrowserViewDelegateRef): TCefChromeToolbarType; extdecl;
begin
  Result := AObj.GetChromeToolbarType;
end;


exports
  BrowserViewDelegateRef_Create,
  BrowserViewDelegateRef_CreateForCustom,
  BrowserViewDelegate_SetOnBrowserCreated,
  BrowserViewDelegate_SetOnBrowserDestroyed,
  BrowserViewDelegate_SetOnGetDelegateForPopupBrowserView,
  BrowserViewDelegate_SetOnPopupBrowserViewCreated,
  BrowserViewDelegate_GetChromeToolbarType
;

