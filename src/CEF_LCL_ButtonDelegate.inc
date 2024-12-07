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

procedure ButtonDelegate_SetOnButtonPressed(const AObj: ICefButtonDelegate; const AEvent: Pointer);  extdecl;
begin
  handleExceptionBegin
  if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnButtonPressedPtr := AEvent;
  end
  else
    (AObj as TButtonDelegateRef).OnButtonPressedPtr := AEvent;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnButtonStateChanged(const AObj: ICefButtonDelegate; const AEvent: Pointer);  extdecl;
begin
  handleExceptionBegin
  if AObj is TMenuButtonDelegateRef then
  begin
    (AObj as TMenuButtonDelegateRef).OnButtonStateChangedPtr := AEvent;
  end
  else
  (AObj as TButtonDelegateRef).OnButtonStateChangedPtr := AEvent;
  handleExceptionEnd
end;

exports
  ButtonDelegateRef_Create,
  ButtonDelegateRef_CreateForCustom,
  ButtonDelegate_SetOnButtonPressed,
  ButtonDelegate_SetOnButtonStateChanged;
