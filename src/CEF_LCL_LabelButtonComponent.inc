//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  LabelButtonComponent_Create(AOwner: TComponent; out Result: TCEFLabelButtonComponent); extdecl;
begin
  handleExceptionBegin
  Result := TCEFLabelButtonComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure  LabelButtonComponent_CreateLabelButton(const AObj: TCEFLabelButtonComponent; const aText : PChar); extdecl;
begin
  handleExceptionBegin
  AObj.CreateLabelButton(PCharToUStr(aText));
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetTextColor(const AObj: TCEFLabelButtonComponent; for_state: TCefButtonState; color: TCefColor); extdecl;
begin
  handleExceptionBegin
  AObj.SetTextColor(for_state, color);
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetEnabledTextColors(const AObj: TCEFLabelButtonComponent; color: TCefColor); extdecl;
begin
  handleExceptionBegin
  AObj.SetEnabledTextColors(color);
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetFontList(const AObj: TCEFLabelButtonComponent; const font_list: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetFontList(PCharToUStr(font_list));
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetHorizontalAlignment(const AObj: TCEFLabelButtonComponent; alignment: TCefHorizontalAlignment); extdecl;
begin
  handleExceptionBegin
  AObj.SetHorizontalAlignment(alignment);
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetMinimumSize(const AObj: TCEFLabelButtonComponent; const size_: TCefSize); extdecl;
begin
  handleExceptionBegin
  AObj.SetMinimumSize(size_);
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetMaximumSize(const AObj: TCEFLabelButtonComponent; const size_: TCefSize); extdecl;
begin
  handleExceptionBegin
  AObj.SetMaximumSize(size_);
  handleExceptionEnd
end;

function   LabelButtonComponent_GetText(const AObj: TCEFLabelButtonComponent): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.Text));
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetText(const AObj: TCEFLabelButtonComponent; text: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Text := PCharToUStr(text);
  handleExceptionEnd
end;

procedure  LabelButtonComponent_GetImage(const AObj: TCEFLabelButtonComponent; button_state : TCefButtonState; out Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := AObj.Image[button_state];
  handleExceptionEnd
end;

procedure  LabelButtonComponent_SetImage(const AObj: TCEFLabelButtonComponent; button_state : TCefButtonState; const image: ICefImage); extdecl;
begin
  handleExceptionBegin
  AObj.Image[button_state] := image;
  handleExceptionEnd
end;

procedure  LabelButtonComponent_AsMenuButton(const AObj: TCEFLabelButtonComponent; out Result: ICefMenuButton); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsMenuButton;
  handleExceptionEnd
end;


exports
  LabelButtonComponent_Create,
  LabelButtonComponent_CreateLabelButton,
  LabelButtonComponent_SetTextColor,
  LabelButtonComponent_SetEnabledTextColors,
  LabelButtonComponent_SetFontList,
  LabelButtonComponent_SetHorizontalAlignment,
  LabelButtonComponent_SetMinimumSize,
  LabelButtonComponent_SetMaximumSize,
  LabelButtonComponent_GetText,
  LabelButtonComponent_SetText,
  LabelButtonComponent_GetImage,
  LabelButtonComponent_SetImage,
  LabelButtonComponent_AsMenuButton
;
