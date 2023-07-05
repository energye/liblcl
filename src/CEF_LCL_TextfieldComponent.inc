//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure TextfieldComponent_Create(AOwner: TComponent; out Result: TCEFTextfieldComponent) ; extdecl;
begin
    handleExceptionBegin
    Result := TCEFTextfieldComponent.Create(AOwner);
    handleExceptionEnd
end;

procedure  TextfieldComponent_CreateTextField(const AObj: TCEFTextfieldComponent); extdecl;
begin
    handleExceptionBegin
    AObj.CreateTextField;
    handleExceptionEnd
end;

procedure  TextfieldComponent_AppendText(const AObj: TCEFTextfieldComponent; const text_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.AppendText(PCharToUStr(text_));
    handleExceptionEnd
end;

procedure  TextfieldComponent_InsertOrReplaceText(const AObj: TCEFTextfieldComponent; const text_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.InsertOrReplaceText(PCharToUStr(text_));
    handleExceptionEnd
end;

procedure  TextfieldComponent_SelectAll(const AObj: TCEFTextfieldComponent; reversed: LongBool); extdecl;
begin
    handleExceptionBegin
    AObj.SelectAll(reversed);
    handleExceptionEnd
end;

procedure  TextfieldComponent_ClearSelection(const AObj: TCEFTextfieldComponent); extdecl;
begin
    handleExceptionBegin
    AObj.ClearSelection;
    handleExceptionEnd
end;

procedure  TextfieldComponent_SelectRange(const AObj: TCEFTextfieldComponent; const range: TCefRange); extdecl;
begin
    handleExceptionBegin
    AObj.SelectRange(range);
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetFontList(const AObj: TCEFTextfieldComponent; const font_list: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.InsertOrReplaceText(PCharToUStr(font_list));
    handleExceptionEnd
end;

procedure  TextfieldComponent_ApplyTextColor(const AObj: TCEFTextfieldComponent; color: TCefColor; const range: TCefRange); extdecl;
begin
    handleExceptionBegin
    AObj.ApplyTextColor(color, range);
    handleExceptionEnd
end;

procedure  TextfieldComponent_ApplyTextStyle(const AObj: TCEFTextfieldComponent; style: TCefTextStyle; add: LongBool; const range: TCefRange); extdecl;
begin
    handleExceptionBegin
    AObj.ApplyTextStyle(style, add, range);
    handleExceptionEnd
end;

function   TextfieldComponent_IsCommandEnabled(const AObj: TCEFTextfieldComponent; command_id: TCefTextFieldCommands): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := AObj.IsCommandEnabled(command_id);
    handleExceptionEnd
end;

procedure  TextfieldComponent_ExecuteCommand(const AObj: TCEFTextfieldComponent; command_id: TCefTextFieldCommands); extdecl;
begin
    handleExceptionBegin
    AObj.ExecuteCommand(command_id);
    handleExceptionEnd
end;

procedure  TextfieldComponent_ClearEditHistory(const AObj: TCEFTextfieldComponent); extdecl;
begin
    handleExceptionBegin
    AObj.ClearEditHistory;
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetAccessibleName(const AObj: TCEFTextfieldComponent; const name_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.SetAccessibleName(PChar(string(name_)));
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetPlaceholderTextColor(const AObj: TCEFTextfieldComponent; color: TCefColor); extdecl;
begin
    handleExceptionBegin
    AObj.SetPlaceholderTextColor(color);
    handleExceptionEnd
end;

function   TextfieldComponent_IsPasswordInput(const AObj: TCEFTextfieldComponent) : LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := AObj.PasswordInput;
    handleExceptionEnd
end;

procedure   TextfieldComponent_SetPasswordInput(const AObj: TCEFTextfieldComponent; value: LongBool) ; extdecl;
begin
    handleExceptionBegin
    AObj.PasswordInput := value;
    handleExceptionEnd
end;

function   TextfieldComponent_IsReadOnly(const AObj: TCEFTextfieldComponent) : LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := AObj.ReadOnly;
    handleExceptionEnd
end;

procedure   TextfieldComponent_SetReadOnly(const AObj: TCEFTextfieldComponent; value: LongBool) ; extdecl;
begin
    handleExceptionBegin
    AObj.ReadOnly := value;
    handleExceptionEnd
end;

function   TextfieldComponent_GetText(const AObj: TCEFTextfieldComponent) : PChar ; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(AObj.Text));
    handleExceptionEnd
end;

procedure   TextfieldComponent_SetText(const AObj: TCEFTextfieldComponent; text: PChar) ; extdecl;
begin
    handleExceptionBegin
    AObj.Text := PCharToUStr(text);
    handleExceptionEnd
end;

function   TextfieldComponent_GetSelectedText(const AObj: TCEFTextfieldComponent) : PChar ; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(AObj.SelectedText));
    handleExceptionEnd
end;

procedure  TextfieldComponent_GetTextColor(const AObj: TCEFTextfieldComponent; out Result: TCefColor) ; extdecl;
begin
    handleExceptionBegin
    Result := AObj.TextColor;
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetTextColor(const AObj: TCEFTextfieldComponent; color: TCefColor) ; extdecl;
begin
    handleExceptionBegin
    AObj.TextColor := color;
    handleExceptionEnd
end;

procedure  TextfieldComponent_GetSelectionTextColor(const AObj: TCEFTextfieldComponent; out Result: TCefColor) ; extdecl;
begin
    handleExceptionBegin
    Result := AObj.SelectionTextColor;
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetSelectionTextColor(const AObj: TCEFTextfieldComponent; color: TCefColor) ; extdecl;
begin
    handleExceptionBegin
    AObj.SelectionTextColor := color;
    handleExceptionEnd
end;

procedure  TextfieldComponent_GetSelectionBackgroundColor(const AObj: TCEFTextfieldComponent; out Result: TCefColor) ; extdecl;
begin
    handleExceptionBegin
    Result := AObj.SelectionBackgroundColor;
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetSelectionBackgroundColor(const AObj: TCEFTextfieldComponent; color: TCefColor) ; extdecl;
begin
    handleExceptionBegin
    AObj.SelectionBackgroundColor := color;
    handleExceptionEnd
end;

function   TextfieldComponent_GetPlaceholderText(const AObj: TCEFTextfieldComponent) : PChar ; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(AObj.PlaceholderText));
    handleExceptionEnd
end;

procedure   TextfieldComponent_SetPlaceholderText(const AObj: TCEFTextfieldComponent; text: PChar) ; extdecl;
begin
    handleExceptionBegin
    AObj.PlaceholderText := PCharToUStr(text);
    handleExceptionEnd
end;

function   TextfieldComponent_HasSelection(const AObj: TCEFTextfieldComponent) : LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := AObj.HasSelection;
    handleExceptionEnd
end;

procedure  TextfieldComponent_SetOnTextfieldKeyEvent(const AObj: TCEFTextfieldComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := TextfieldComponent_OnTextfieldKeyEvent}
  {$DEFINE EventName := OnTextfieldKeyEvent}
  EventMethodCode
end;

procedure  TextfieldComponent_SetOnAfterUserAction(const AObj: TCEFTextfieldComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := TextfieldComponent_OnAfterUserAction}
  {$DEFINE EventName := OnAfterUserAction}
  EventMethodCode
end;

exports
  TextfieldComponent_Create,
  TextfieldComponent_CreateTextField,
  TextfieldComponent_AppendText,
  TextfieldComponent_InsertOrReplaceText,
  TextfieldComponent_SelectAll,
  TextfieldComponent_ClearSelection,
  TextfieldComponent_SelectRange,
  TextfieldComponent_SetFontList,
  TextfieldComponent_ApplyTextColor,
  TextfieldComponent_ApplyTextStyle,
  TextfieldComponent_IsCommandEnabled,
  TextfieldComponent_ExecuteCommand,
  TextfieldComponent_ClearEditHistory,
  TextfieldComponent_SetAccessibleName,
  TextfieldComponent_SetPlaceholderTextColor,
  TextfieldComponent_IsPasswordInput,
  TextfieldComponent_SetPasswordInput,
  TextfieldComponent_IsReadOnly,
  TextfieldComponent_SetReadOnly,
  TextfieldComponent_GetText,
  TextfieldComponent_SetText,
  TextfieldComponent_GetSelectedText,
  TextfieldComponent_GetTextColor,
  TextfieldComponent_SetTextColor,
  TextfieldComponent_GetSelectionTextColor,
  TextfieldComponent_SetSelectionTextColor,
  TextfieldComponent_GetSelectionBackgroundColor,
  TextfieldComponent_SetSelectionBackgroundColor,
  TextfieldComponent_GetPlaceholderText,
  TextfieldComponent_SetPlaceholderText,
  TextfieldComponent_HasSelection,
  TextfieldComponent_SetOnTextfieldKeyEvent,
  TextfieldComponent_SetOnAfterUserAction
;


