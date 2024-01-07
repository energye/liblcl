//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ButtonDelegateRef_Create(out Result: ICefButtonDelegate);  extdecl;
begin
  handleExceptionBegin
  Result := TButtonDelegateRef.Create;
  handleExceptionEnd
end;

procedure  ButtonDelegateRef_CreateForCustom(const events: ICefButtonDelegateEvents; out Result: ICefButtonDelegate);  extdecl;
begin
  handleExceptionBegin
  Result := TCustomButtonDelegate.Create(events);
  handleExceptionEnd
end;


// ICefViewDelegate
procedure  ButtonDelegate_SetOnGetPreferredSize(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).GetPreferredSizePtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnGetMinimumSize(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).GetMinimumSizePtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnGetMaximumSize(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).GetMaximumSizePtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnGetHeightForWidth(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).GetHeightForWidthPtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnParentViewChanged(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).ParentViewChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnChildViewChanged(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).ChildViewChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnWindowChanged(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).WindowChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnLayoutChanged(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).LayoutChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnFocus(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).FocusPtr := AEventData;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnBlur(const AObj: ICefButtonDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).BlurPtr := AEventData;
  handleExceptionEnd
end;


procedure ButtonDelegate_SetOnButtonPressed(const AObj: ICefButtonDelegate; const AEvent: Pointer);  extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).ButtonPressedPtr := AEvent;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnButtonStateChanged(const AObj: ICefButtonDelegate; const AEvent: Pointer);  extdecl;
begin
  handleExceptionBegin
  (AObj as TButtonDelegateRef).ButtonStateChangedPtr := AEvent;
  handleExceptionEnd
end;

exports
  ButtonDelegateRef_Create,
  ButtonDelegateRef_CreateForCustom,
  ButtonDelegate_SetOnGetPreferredSize,
  ButtonDelegate_SetOnGetMinimumSize,
  ButtonDelegate_SetOnGetMaximumSize,
  ButtonDelegate_SetOnGetHeightForWidth,
  ButtonDelegate_SetOnParentViewChanged,
  ButtonDelegate_SetOnChildViewChanged,
  ButtonDelegate_SetOnWindowChanged,
  ButtonDelegate_SetOnLayoutChanged,
  ButtonDelegate_SetOnFocus,
  ButtonDelegate_SetOnBlur,
  ButtonDelegate_SetOnButtonPressed,
  ButtonDelegate_SetOnButtonStateChanged;
