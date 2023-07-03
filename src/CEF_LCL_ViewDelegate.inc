//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ViewDelegateRef_Create(out Result: TViewDelegateRef); extdecl;
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

procedure  ViewDelegate_SetOnGetPreferredSize(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.GetPreferredSizePtr := AEvent;
end;

procedure  ViewDelegate_SetOnGetMinimumSize(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.GetMinimumSizePtr := AEvent;
end;

procedure  ViewDelegate_SetOnGetMaximumSize(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.GetMaximumSizePtr := AEvent;
end;

procedure  ViewDelegate_SetOnGetHeightForWidth(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.GetHeightForWidthPtr := AEvent;
end;

procedure  ViewDelegate_SetOnParentViewChanged(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.ParentViewChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnChildViewChanged(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.ChildViewChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnWindowChanged(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.WindowChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnLayoutChanged(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.LayoutChangedPtr := AEvent;
end;

procedure  ViewDelegate_SetOnFocus(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.FocusPtr := AEvent;
end;

procedure  ViewDelegate_SetOnBlur(const AObj: TViewDelegateRef; const AEvent: Pointer); extdecl;
begin
  AObj.BlurPtr := AEvent;
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
  ViewDelegate_SetOnBlur
;
