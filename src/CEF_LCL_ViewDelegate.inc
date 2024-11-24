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
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnGetPreferredSizePtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnGetPreferredSizePtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnGetPreferredSizePtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnGetPreferredSizePtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnGetPreferredSizePtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnGetPreferredSizePtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnGetPreferredSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetMinimumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnGetMinimumSizePtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnGetMinimumSizePtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnGetMinimumSizePtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnGetMinimumSizePtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnGetMinimumSizePtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnGetMinimumSizePtr := AEvent;
  end
  else
   (AObj as TViewDelegateRef).OnGetMinimumSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetMaximumSize(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnGetMaximumSizePtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnGetMaximumSizePtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnGetMaximumSizePtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnGetMaximumSizePtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnGetMaximumSizePtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnGetMaximumSizePtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnGetMaximumSizePtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnGetHeightForWidth(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnGetHeightForWidthPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnGetHeightForWidthPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnGetHeightForWidthPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnGetHeightForWidthPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnGetHeightForWidthPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnGetHeightForWidthPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnGetHeightForWidthPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnParentViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnParentViewChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnParentViewChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnParentViewChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnParentViewChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnParentViewChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnParentViewChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnParentViewChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnChildViewChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnChildViewChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnChildViewChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnChildViewChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnChildViewChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnChildViewChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnChildViewChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnChildViewChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnWindowChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnWindowChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnWindowChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnWindowChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnWindowChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnWindowChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnWindowChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnWindowChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnLayoutChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnLayoutChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnLayoutChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnLayoutChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnLayoutChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnLayoutChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnLayoutChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnLayoutChangedPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnFocus(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnFocusPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnFocusPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnFocusPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnFocusPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnFocusPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnFocusPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnFocusPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnBlur(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnBlurPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnBlurPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnBlurPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnBlurPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnBlurPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnBlurPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnBlurPtr := AEvent;
  handleExceptionEnd
end;

procedure  ViewDelegate_SetOnThemeChanged(const AObj: ICefViewDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  if AObj is TTextfieldDelegateRef then
  begin
    (AObj as TTextfieldDelegateRef).OnThemeChangedPtr := AEvent;
  end
  else if AObj is TPanelDelegateRef then
  begin
    (AObj as TPanelDelegateRef).OnThemeChangedPtr := AEvent;
  end
  else if AObj is TWindowDelegateRef then
  begin
    (AObj as TWindowDelegateRef).OnThemeChangedPtr := AEvent;
  end
  else if AObj is TBrowserViewDelegateRef then
  begin
    (AObj as TBrowserViewDelegateRef).OnThemeChangedPtr := AEvent;
  end
  else if AObj is TButtonDelegateRef then
  begin
    (AObj as TButtonDelegateRef).OnThemeChangedPtr := AEvent;
  end
  else if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnThemeChangedPtr := AEvent;
  end
  else
    (AObj as TViewDelegateRef).OnThemeChangedPtr := AEvent;
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
  ViewDelegate_SetOnBlur,
  ViewDelegate_SetOnThemeChanged;
