//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MenuButtonDelegateRef_Create(out Result: ICefMenuButtonDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TMenuButtonDelegateRef.Create;
  handleExceptionEnd
end;

procedure MenuButtonDelegateRef_CreateForCustom(const events: ICefMenuButtonDelegateEvents; out Result: ICefMenuButtonDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TCustomMenuButtonDelegate.Create(events);
  handleExceptionEnd
end;

procedure MenuButtonDelegate_SetOnMenuButtonPressed(const AObj: ICefMenuButtonDelegate; const AEvent: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuButtonDelegateRef).OnMenuButtonPressedPtr := AEvent;
  handleExceptionEnd
end;

exports
  MenuButtonDelegateRef_Create,
  MenuButtonDelegateRef_CreateForCustom,
  MenuButtonDelegate_SetOnMenuButtonPressed;
