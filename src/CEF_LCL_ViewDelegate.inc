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

{
TTextfieldDelegateRef
TPanelDelegateRef
TWindowDelegateRef
TBrowserViewDelegateRef
TButtonDelegateRef
TMenuButtonDelegateRef
}

procedure  ViewDelegate_SetOnGetPreferredSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).GetPreferredSizePtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).GetPreferredSizePtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).GetPreferredSizePtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).GetPreferredSizePtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).GetPreferredSizePtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).GetPreferredSizePtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).GetPreferredSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetMinimumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).GetMinimumSizePtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).GetMinimumSizePtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).GetMinimumSizePtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).GetMinimumSizePtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).GetMinimumSizePtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).GetMinimumSizePtr := AEvent;
  end
  else
   (AObj as TViewDelegateRef).GetMinimumSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetMaximumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).GetMaximumSizePtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).GetMaximumSizePtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).GetMaximumSizePtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).GetMaximumSizePtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).GetMaximumSizePtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).GetMaximumSizePtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).GetMaximumSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetHeightForWidth(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).GetHeightForWidthPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).GetHeightForWidthPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).GetHeightForWidthPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).GetHeightForWidthPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).GetHeightForWidthPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).GetHeightForWidthPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).GetHeightForWidthPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnParentViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).ParentViewChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).ParentViewChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).ParentViewChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).ParentViewChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).ParentViewChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).ParentViewChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).ParentViewChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnChildViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).ChildViewChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).ChildViewChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).ChildViewChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).ChildViewChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).ChildViewChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).ChildViewChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).ChildViewChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnFocus(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).FocusPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).FocusPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).FocusPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).FocusPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).FocusPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).FocusPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).FocusPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnBlur(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).BlurPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).BlurPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).BlurPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).BlurPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).BlurPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).BlurPtr := AEvent;
  end
  else
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
  ViewDelegate_SetOnFocus,
  ViewDelegate_SetOnBlur;
