//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure TextfieldRef_CreateTextField(const delegate: ICefTextfieldDelegate; out Result: ICefTextfield) ; extdecl;
begin
    handleExceptionBegin
    Result := TCefTextfieldRef.CreateTextField(delegate);
    handleExceptionEnd
end;

procedure Textfield_SetPasswordInput(const AObj: ICefTextfield; password_input: LongBool); extdecl;
begin
    handleExceptionBegin
    AObj.SetPasswordInput(password_input);
    handleExceptionEnd
end;

function  Textfield_IsPasswordInput(const AObj: ICefTextfield) : LongBool; extdecl;
begin
    handleExceptionBegin
    Result := AObj.IsPasswordInput;
    handleExceptionEnd
end;

procedure Textfield_SetReadOnly(const AObj: ICefTextfield; read_only: LongBool); extdecl;
begin
    handleExceptionBegin
    AObj.SetReadOnly(read_only);
    handleExceptionEnd
end;

function  Textfield_IsReadOnly(const AObj: ICefTextfield) : LongBool; extdecl;
begin
    handleExceptionBegin
    Result := AObj.IsReadOnly;
    handleExceptionEnd
end;

function  Textfield_GetText(const AObj: ICefTextfield) : PChar; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(AObj.GetText));
    handleExceptionEnd
end;

procedure Textfield_SetText(const AObj: ICefTextfield; const text_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.SetText(PCharToUStr(text_));
    handleExceptionEnd
end;

procedure Textfield_AppendText(const AObj: ICefTextfield; const text_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.AppendText(PCharToUStr(text_));
    handleExceptionEnd
end;

procedure Textfield_InsertOrReplaceText(const AObj: ICefTextfield; const text_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.InsertOrReplaceText(PCharToUStr(text_));
    handleExceptionEnd
end;

function  Textfield_HasSelection(const AObj: ICefTextfield) : LongBool; extdecl;
begin
    handleExceptionBegin
    Result := AObj.HasSelection();
    handleExceptionEnd
end;

function  Textfield_GetSelectedText(const AObj: ICefTextfield) : PChar; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(AObj.GetSelectedText));
    handleExceptionEnd
end;

procedure Textfield_SelectAll(const AObj: ICefTextfield; reversed: LongBool); extdecl;
begin
    handleExceptionBegin
    AObj.SelectAll(reversed);
    handleExceptionEnd
end;

procedure Textfield_ClearSelection(const AObj: ICefTextfield); extdecl;
begin
    handleExceptionBegin
    AObj.ClearSelection;
    handleExceptionEnd
end;

procedure  Textfield_GetSelectedRange(const AObj: ICefTextfield; out Result: TCefRange); extdecl;
begin
    handleExceptionBegin
    Result := AObj.GetSelectedRange;
    handleExceptionEnd
end;

procedure Textfield_SelectRange(const AObj: ICefTextfield; const range: TCefRange); extdecl;
begin
    handleExceptionBegin
    AObj.SelectRange(range);
    handleExceptionEnd
end;

function  Textfield_GetCursorPosition(const AObj: ICefTextfield) : NativeUInt; extdecl;
begin
    handleExceptionBegin
    Result := AObj.GetCursorPosition;
    handleExceptionEnd
end;

procedure Textfield_SetTextColor(const AObj: ICefTextfield; color: TCefColor); extdecl;
begin
    handleExceptionBegin
    AObj.SetTextColor(color);
    handleExceptionEnd
end;

procedure  Textfield_GetTextColor(const AObj: ICefTextfield; out Result: TCefColor); extdecl;
begin
    handleExceptionBegin
    Result := AObj.GetTextColor;
    handleExceptionEnd
end;

procedure Textfield_SetSelectionTextColor(const AObj: ICefTextfield; color: TCefColor); extdecl;
begin
    handleExceptionBegin
    AObj.SetSelectionTextColor(color);
    handleExceptionEnd
end;

procedure  Textfield_GetSelectionTextColor(const AObj: ICefTextfield; out Result: TCefColor); extdecl;
begin
    handleExceptionBegin
    Result := AObj.GetSelectionTextColor;
    handleExceptionEnd
end;

procedure Textfield_SetSelectionBackgroundColor(const AObj: ICefTextfield; color: TCefColor); extdecl;
begin
    handleExceptionBegin
    AObj.SetSelectionBackgroundColor(color);
    handleExceptionEnd
end;

procedure  Textfield_GetSelectionBackgroundColor(const AObj: ICefTextfield; out Result: TCefColor); extdecl;
begin
    handleExceptionBegin
    Result := AObj.GetSelectionBackgroundColor();
    handleExceptionEnd
end;

procedure Textfield_SetFontList(const AObj: ICefTextfield; const font_list: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.SetFontList(PCharToUStr(font_list));
    handleExceptionEnd
end;

procedure Textfield_ApplyTextColor(const AObj: ICefTextfield; color: TCefColor; const range: TCefRange); extdecl;
begin
    handleExceptionBegin
    AObj.ApplyTextColor(color, range);
    handleExceptionEnd
end;

procedure Textfield_ApplyTextStyle(const AObj: ICefTextfield; style: TCefTextStyle; add: LongBool; const range: TCefRange); extdecl;
begin
    handleExceptionBegin
    AObj.ApplyTextStyle(style, add, range);
    handleExceptionEnd
end;

function  Textfield_IsCommandEnabled(const AObj: ICefTextfield; command_id: TCefTextFieldCommands): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := AObj.IsCommandEnabled(command_id);
    handleExceptionEnd
end;

procedure Textfield_ExecuteCommand(const AObj: ICefTextfield; command_id: TCefTextFieldCommands); extdecl;
begin
    handleExceptionBegin
    AObj.ExecuteCommand(command_id);
    handleExceptionEnd
end;

procedure Textfield_ClearEditHistory(const AObj: ICefTextfield); extdecl;
begin
    handleExceptionBegin
    AObj.ClearEditHistory;
    handleExceptionEnd
end;

procedure Textfield_SetPlaceholderText(const AObj: ICefTextfield; const text_: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.SetPlaceholderText(PCharToUStr(text_));
    handleExceptionEnd
end;

function  Textfield_GetPlaceholderText(const AObj: ICefTextfield) : PChar; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(AObj.GetPlaceholderText));
    handleExceptionEnd
end;

procedure Textfield_SetPlaceholderTextColor(const AObj: ICefTextfield; color: TCefColor); extdecl;
begin
    handleExceptionBegin
    AObj.SetPlaceholderTextColor(color);
    handleExceptionEnd
end;

procedure Textfield_SetAccessibleName(const AObj: ICefTextfield; const name: PChar); extdecl;
begin
    handleExceptionBegin
    AObj.SetAccessibleName(PCharToUStr(name));
    handleExceptionEnd
end;


exports
  TextfieldRef_CreateTextField,
  Textfield_SetPasswordInput,
  Textfield_IsPasswordInput,
  Textfield_SetReadOnly,
  Textfield_IsReadOnly,
  Textfield_GetText,
  Textfield_SetText,
  Textfield_AppendText,
  Textfield_InsertOrReplaceText,
  Textfield_HasSelection,
  Textfield_GetSelectedText,
  Textfield_SelectAll,
  Textfield_ClearSelection,
  Textfield_GetSelectedRange,
  Textfield_SelectRange,
  Textfield_GetCursorPosition,
  Textfield_SetTextColor,
  Textfield_GetTextColor,
  Textfield_SetSelectionTextColor,
  Textfield_GetSelectionTextColor,
  Textfield_SetSelectionBackgroundColor,
  Textfield_GetSelectionBackgroundColor,
  Textfield_SetFontList,
  Textfield_ApplyTextColor,
  Textfield_ApplyTextStyle,
  Textfield_IsCommandEnabled,
  Textfield_ExecuteCommand,
  Textfield_ClearEditHistory,
  Textfield_SetPlaceholderText,
  Textfield_GetPlaceholderText,
  Textfield_SetPlaceholderTextColor,
  Textfield_SetAccessibleName
;

