//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure PanelDelegateRef_Create(out Result: ICefPanelDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TPanelDelegateRef.Create;
  handleExceptionEnd
end;

procedure PanelDelegateRef_CreateForCustom(const events: ICefPanelDelegateEvents; out Result: ICefPanelDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TCustomPanelDelegate.Create(events);
  handleExceptionEnd
end;

// ICefViewDelegate
procedure  PanelDelegate_SetOnGetPreferredSize(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).GetPreferredSizePtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnGetMinimumSize(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).GetMinimumSizePtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnGetMaximumSize(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).GetMaximumSizePtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnGetHeightForWidth(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).GetHeightForWidthPtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnParentViewChanged(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).ParentViewChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnChildViewChanged(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).ChildViewChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnFocus(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).FocusPtr := AEventData;
  handleExceptionEnd
end;

procedure PanelDelegate_SetOnBlur(const AObj: ICefPanelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPanelDelegateRef).BlurPtr := AEventData;
  handleExceptionEnd
end;

exports
  PanelDelegateRef_Create,
  PanelDelegateRef_CreateForCustom,
  PanelDelegate_SetOnGetPreferredSize,
  PanelDelegate_SetOnGetMinimumSize,
  PanelDelegate_SetOnGetMaximumSize,
  PanelDelegate_SetOnGetHeightForWidth,
  PanelDelegate_SetOnParentViewChanged,
  PanelDelegate_SetOnChildViewChanged,
  PanelDelegate_SetOnFocus,
  PanelDelegate_SetOnBlur;
