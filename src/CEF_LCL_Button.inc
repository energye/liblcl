//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  Button_AsLabelButton(const AObj: ICefButton; out Result: ICefLabelButton);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsLabelButton;
  handleExceptionEnd
end;

procedure Button_SetState(const AObj: ICefButton; state_: TCefButtonState);  extdecl;
begin
  handleExceptionBegin
  AObj.SetState(state_);
  handleExceptionEnd
end;

function  Button_GetState(const AObj: ICefButton) : TCefButtonState;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetState;
  handleExceptionEnd
end;

procedure Button_SetInkDropEnabled(const AObj: ICefButton; enabled_: LongBool);  extdecl;
begin
  handleExceptionBegin
  AObj.SetInkDropEnabled(enabled_);
  handleExceptionEnd
end;

procedure Button_SetTooltipText(const AObj: ICefButton; const tooltip_text: PChar);  extdecl;
begin
  handleExceptionBegin
  AObj.SetTooltipText(PCharToUStr(tooltip_text));
  handleExceptionEnd
end;

procedure Button_SetAccessibleName(const AObj: ICefButton; const name: PChar);  extdecl;
begin
  handleExceptionBegin
  AObj.SetAccessibleName(PCharToUStr(name));
  handleExceptionEnd
end;

exports
  Button_AsLabelButton,
  Button_SetState,
  Button_GetState,
  Button_SetInkDropEnabled,
  Button_SetTooltipText,
  Button_SetAccessibleName
;
