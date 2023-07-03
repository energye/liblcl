//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ButtonDelegateRef_Create(out Result: TButtonDelegateRef);  extdecl;
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

procedure ButtonDelegate_SetOnButtonPressed(const AObj: TButtonDelegateRef; const AEvent: Pointer);  extdecl;
begin
  handleExceptionBegin
  AObj.ButtonPressedPtr := AEvent;
  handleExceptionEnd
end;

procedure ButtonDelegate_SetOnButtonStateChanged(const AObj: TButtonDelegateRef; const AEvent: Pointer);  extdecl;
begin
  handleExceptionBegin
  AObj.ButtonStateChangedPtr := AEvent;
  handleExceptionEnd
end;

exports
  ButtonDelegateRef_Create,
  ButtonDelegateRef_CreateForCustom,
  ButtonDelegate_SetOnButtonPressed,
  ButtonDelegate_SetOnButtonStateChanged
;
