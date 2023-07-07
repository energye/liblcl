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
  (AObj as TViewDelegateRef).GetPreferredSizePtr := AEvent;
end;

procedure  ViewDelegate_SetOnGetMinimumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).GetMinimumSizePtr := AEvent;
end;

procedure  ViewDelegate_SetOnGetMaximumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).GetMaximumSizePtr := AEvent;
end;

procedure  ViewDelegate_SetOnGetHeightForWidth(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).GetHeightForWidthPtr := AEvent;
end;

procedure  ViewDelegate_SetOnParentViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).ParentViewChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnChildViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).ChildViewChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnWindowChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).WindowChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnLayoutChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).LayoutChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnFocus(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).FocusPtr := AEvent;
end;

procedure  ViewDelegate_SetOnBlur(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  (AObj as TViewDelegateRef).BlurPtr := AEvent;
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