//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure TextfieldDelegate_Create(out Result: ICefTextfieldDelegate) ; extdecl;
begin
  handleExceptionBegin
  Result := TTextfieldDelegateRef.Create();
  handleExceptionEnd
end;

procedure TextfieldDelegate_CreateForCustom(const events: ICefTextfieldDelegateEvents; out Result: ICefTextfieldDelegate) ; extdecl;
begin
  handleExceptionBegin
  Result := TCustomTextfieldDelegate.Create(events);
  handleExceptionEnd
end;

procedure  TextfieldDelegate_SetOnKeyEvent(const AObj: ICefTextfieldDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TTextfieldDelegateRef).OnKeyEventPtr := AEventData;
  handleExceptionEnd
end;

procedure  TextfieldDelegate_SetOnAfterUserAction(const AObj: ICefTextfieldDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TTextfieldDelegateRef).OnAfterUserActionPtr := AEventData;
  handleExceptionEnd
end;

exports
  TextfieldDelegate_Create,
  TextfieldDelegate_CreateForCustom,
  TextfieldDelegate_SetOnKeyEvent,
  TextfieldDelegate_SetOnAfterUserAction;
