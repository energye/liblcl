//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ButtonComponent_Create(const AOwner: TComponent; out Result: TCEFButtonComponent); extdecl;
begin
  handleExceptionBegin
  Result := TCEFButtonComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure ButtonComponent_SetInkDropEnabled(const AObj: TCEFButtonComponent; enabled_: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetInkDropEnabled(enabled_);
  handleExceptionEnd
end;

procedure ButtonComponent_SetTooltipText(const AObj: TCEFButtonComponent; const tooltip_text: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetTooltipText(PCharToUStr(tooltip_text));
  handleExceptionEnd
end;

procedure ButtonComponent_SetAccessibleName(const AObj: TCEFButtonComponent; const name_: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetAccessibleName(PCharToUStr(name_));
  handleExceptionEnd
end;

procedure ButtonComponent_AsLabelButton(const AObj: TCEFButtonComponent; out Result: ICefLabelButton); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsLabelButton;
  handleExceptionEnd
end;

function  ButtonComponent_GetState(const AObj: TCEFButtonComponent): TCefButtonState; extdecl;
begin
  handleExceptionBegin
  Result := AObj.State;
  handleExceptionEnd
end;

procedure ButtonComponent_SetState(const AObj: TCEFButtonComponent; state: TCefButtonState); extdecl;
begin
  handleExceptionBegin
  AObj.State := state;
  handleExceptionEnd
end;

procedure ButtonComponent_SetOnButtonPressed(const AObj: TCEFButtonComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ButtonComponent_OnButtonPressed}
  {$DEFINE EventName := OnButtonPressed}
  EventMethodCode
end;

procedure ButtonComponent_SetOnButtonStateChanged(const AObj: TCEFButtonComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ButtonComponent_OnButtonStateChanged}
  {$DEFINE EventName := OnButtonStateChanged}
  EventMethodCode
end;

exports
  ButtonComponent_Create,
  ButtonComponent_SetInkDropEnabled,
  ButtonComponent_SetTooltipText,
  ButtonComponent_SetAccessibleName,
  ButtonComponent_AsLabelButton,
  ButtonComponent_GetState,
  ButtonComponent_SetState,
  ButtonComponent_SetOnButtonPressed,
  ButtonComponent_SetOnButtonStateChanged
;
