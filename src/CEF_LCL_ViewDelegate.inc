//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ViewDelegateRef_Create(out Result: ICefViewDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TViewDelegateRef.Create;
  handleExceptionEnd
end;

procedure  ViewDelegateRef_CreateForCustom(const events: ICefViewDelegateEvents; out Result: ICefViewDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TCustomViewDelegate.Create(events);
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetPreferredSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).GetPreferredSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetMinimumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).GetMinimumSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetMaximumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).GetMaximumSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetHeightForWidth(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).GetHeightForWidthPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnParentViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).ParentViewChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnChildViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).ChildViewChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnWindowChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).WindowChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnLayoutChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).LayoutChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnFocus(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).FocusPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnBlur(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TViewDelegateRef).BlurPtr := AEvent;
  handleExceptionEnd
end;


exports
  ViewDelegateRef_Create,
  ViewDelegateRef_CreateForCustom,
  ViewDelegate_SetOnGetPreferredSize,
  ViewDelegate_SetOnGetMinimumSize,
  ViewDelegate_SetOnGetMaximumSize,
  ViewDelegate_SetOnGetHeightForWidth,
  ViewDelegate_SetOnParentViewChanged,
  ViewDelegate_SetOnChildViewChanged,
  ViewDelegate_SetOnWindowChanged,
  ViewDelegate_SetOnLayoutChanged,
  ViewDelegate_SetOnFocus,
  ViewDelegate_SetOnBlur;