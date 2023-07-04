//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  LabelButtonRef_CreateLabelButton(const delegate: ICefButtonDelegate; const text: PChar; out Result: ICefLabelButton); extdecl;
begin
  handleExceptionBegin
  Result := TCefLabelButtonRef.CreateLabelButton(delegate, PCharToUStr(text));
  handleExceptionEnd
end;

procedure LabelButton_AsMenuButton(const AObj: ICefLabelButton; out Result: ICefMenuButton); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsMenuButton;
  handleExceptionEnd
end;

procedure LabelButton_SetText(const AObj: ICefLabelButton; const text_: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetText(PCharToUStr(text_));
  handleExceptionEnd
end;

function  LabelButton_GetText(const AObj: ICefLabelButton) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetText));
  handleExceptionEnd
end;

procedure LabelButton_SetImage(const AObj: ICefLabelButton; button_state: TCefButtonState; const image: ICefImage); extdecl;
begin
  handleExceptionBegin
  AObj.SetImage(button_state, image);
  handleExceptionEnd
end;

procedure LabelButton_GetImage(const AObj: ICefLabelButton; button_state: TCefButtonState; out Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetImage(button_state);
  handleExceptionEnd
end;

procedure LabelButton_SetTextColor(const AObj: ICefLabelButton; for_state: TCefButtonState; color: TCefColor); extdecl;
begin
  handleExceptionBegin
  AObj.SetTextColor(for_state, color);
  handleExceptionEnd
end;

procedure LabelButton_SetEnabledTextColors(const AObj: ICefLabelButton; color: TCefColor); extdecl;
begin
  handleExceptionBegin
  AObj.SetEnabledTextColors(color);
  handleExceptionEnd
end;

procedure LabelButton_SetFontList(const AObj: ICefLabelButton; const font_list: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetFontList(PCharToUStr(font_list));
  handleExceptionEnd
end;

procedure LabelButton_SetHorizontalAlignment(const AObj: ICefLabelButton; alignment: TCefHorizontalAlignment); extdecl;
begin
  handleExceptionBegin
  AObj.SetHorizontalAlignment(alignment);
  handleExceptionEnd
end;

procedure LabelButton_SetMinimumSize(const AObj: ICefLabelButton; const size_: TCefSize); extdecl;
begin
  handleExceptionBegin
  AObj.SetMinimumSize(size_);
  handleExceptionEnd
end;

procedure LabelButton_SetMaximumSize(const AObj: ICefLabelButton; const size_: TCefSize); extdecl;
begin
  handleExceptionBegin
  AObj.SetMaximumSize(size_);
  handleExceptionEnd
end;


exports
  LabelButtonRef_CreateLabelButton,
  LabelButton_AsMenuButton,
  LabelButton_SetText,
  LabelButton_GetText,
  LabelButton_SetImage,
  LabelButton_GetImage,
  LabelButton_SetTextColor,
  LabelButton_SetEnabledTextColors,
  LabelButton_SetFontList,
  LabelButton_SetHorizontalAlignment,
  LabelButton_SetMinimumSize,
  LabelButton_SetMaximumSize
;
