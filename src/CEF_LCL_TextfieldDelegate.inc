//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure TextfieldDelegate_Create(out Result: TTextfieldDelegateRef) ; extdecl;
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

procedure  TextfieldDelegate_SetOnKeyEvent(const AObj: TTextfieldDelegateRef; AEventData: Pointer); extdecl;
begin
    AObj.KeyEventPtr := AEventData;
end;

procedure  TextfieldDelegate_SetOnAfterUserAction(const AObj: TTextfieldDelegateRef; AEventData: Pointer); extdecl;
begin
    AObj.AfterUserActionPtr := AEventData;
end;

exports
  TextfieldDelegate_Create,
  TextfieldDelegate_CreateForCustom,
  TextfieldDelegate_SetOnKeyEvent,
  TextfieldDelegate_SetOnAfterUserAction
;

