
procedure ImplViewClassName.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure ImplViewClassName.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure ImplViewClassName.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure ImplViewClassName.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (OnGetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure ImplViewClassName.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (OnParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure ImplViewClassName.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (OnChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure ImplViewClassName.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (OnWindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowChangedPtr, [view, added]);
  end;
end;

procedure ImplViewClassName.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (OnLayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnLayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure ImplViewClassName.OnFocus(const view: ICefView);
begin
  if (OnFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnFocusPtr, [view]);
  end;
end;

procedure ImplViewClassName.OnBlur(const view: ICefView);
begin
  if (OnBlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBlurPtr, [view]);
  end;
end;
