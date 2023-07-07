//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefMenuModelRef_New(const delegate: ICefMenuModelDelegate; out Result: ICefMenuModel) ; extdecl;
begin
  handleExceptionBegin
  Result := TCefMenuModelRef.New(delegate);
  handleExceptionEnd
end;

function CefMenuModel_AddSeparator(const model :ICefMenuModel): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := model.AddSeparator;
  handleExceptionEnd
end;

function CefMenuModel_Clear(const model :ICefMenuModel): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := model.Clear;
  handleExceptionEnd
end;

function CefMenuModel_IsSubMenu(const model :ICefMenuModel): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := model.IsSubMenu;
  handleExceptionEnd
end;

function CefMenuModel_GetCount(const model :ICefMenuModel): Integer ; extdecl;
begin
  handleExceptionBegin
  Result := model.GetCount;
  handleExceptionEnd
end;

function CefMenuModel_AddItem(const model :ICefMenuModel; commandId: integer; PText: PChar): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := model.AddItem(commandId, PCharToUStr(PText));
  handleExceptionEnd
end;

function CefMenuModel_AddCheckItem(const model :ICefMenuModel; commandId: Integer; PText: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.AddCheckItem(commandId, PCharToUStr(PText));
  handleExceptionEnd
end;

function CefMenuModel_AddRadioItem(const model :ICefMenuModel; commandId: Integer; PText: PChar; groupId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.AddRadioItem(commandId, PCharToUStr(PText), groupId);
  handleExceptionEnd
end;

procedure CefMenuModel_AddSubMenu(const model :ICefMenuModel; commandId: Integer; PText: PChar; var Result: ICefMenuModel); extdecl;
begin
  handleExceptionBegin
  Result := model.AddSubMenu(commandId, PCharToUStr(PText));
  handleExceptionEnd
end;

function CefMenuModel_Remove(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.Remove(commandId);
  handleExceptionEnd
end;

function CefMenuModel_RemoveAt(const model :ICefMenuModel; index: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.RemoveAt(index);
  handleExceptionEnd
end;

function CefMenuModel_SetChecked(const model :ICefMenuModel; commandId: Integer; checked: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.setChecked(commandId, checked);
  handleExceptionEnd
end;

function CefMenuModel_IsChecked(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.IsChecked(commandId);
  handleExceptionEnd
end;

function CefMenuModel_SetColor(const model :ICefMenuModel; commandId: Integer; colorType: integer; color: Cardinal): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetColor(commandId, TCefMenuColorType(colorType), TCefColor(color));
  handleExceptionEnd
end;

function CefMenuModel_SetFontList(const model :ICefMenuModel; commandId: Integer; PFontList: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetFontList(commandId, PCharToUStr(PFontList));
  handleExceptionEnd
end;

function CefMenuModel_HasAccelerator(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.HasAccelerator(commandId);
  handleExceptionEnd
end;

function CefMenuModel_SetAccelerator(const model :ICefMenuModel; commandId, keyCode: Integer; shiftPressed, ctrlPressed, altPressed: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetAccelerator(commandId, keyCode, shiftPressed, ctrlPressed, altPressed);
  handleExceptionEnd
end;

function CefMenuModel_RemoveAccelerator(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.RemoveAccelerator(commandId);
  handleExceptionEnd
end;

function CefMenuModel_IsVisible(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.IsVisible(commandId);
  handleExceptionEnd
end;

function CefMenuModel_SetVisible(const model :ICefMenuModel; commandId: Integer; visible: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetVisible(commandId, visible);
  handleExceptionEnd
end;

function CefMenuModel_IsEnabled(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.IsEnabled(commandId);
  handleExceptionEnd
end;

function CefMenuModel_SetEnabled(const model :ICefMenuModel; commandId: Integer; enabled: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetEnabled(commandId, enabled);
  handleExceptionEnd
end;

function CefMenuModel_SetLabel(const model :ICefMenuModel; commandId: Integer; PText: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetLabel(commandId, PCharToUStr(PText));
  handleExceptionEnd
end;

function CefMenuModel_GetIndexOf(const model :ICefMenuModel; commandId: Integer): Integer ; extdecl;
begin
  handleExceptionBegin
  Result := model.GetIndexOf(commandId);
  handleExceptionEnd
end;

function CefMenuModel_GetType(const model :ICefMenuModel; commandId: Integer): TCefMenuItemType; extdecl;
begin
  handleExceptionBegin
  Result := model.GetType(commandId);
  handleExceptionEnd
end;

function CefMenuModel_GetLabel(const model :ICefMenuModel; commandId: Integer): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(model.GetLabel(commandId)));
  handleExceptionEnd
end;

function CefMenuModel_GetGroupId(const model :ICefMenuModel; commandId: Integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := model.GetGroupId(commandId);
  handleExceptionEnd
end;

function CefMenuModel_SetGroupId(const model :ICefMenuModel; commandId, groupId: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.SetGroupId(commandId, groupId);
  handleExceptionEnd
end;

function CefMenuModel_GetSubMenu(const model :ICefMenuModel; commandId: Integer): ICefMenuModel; extdecl;
begin
  handleExceptionBegin
  Result := model.GetSubMenu(commandId);
  handleExceptionEnd
end;

function CefMenuModel_GetColor(const model :ICefMenuModel; commandId: Integer; colorType: TCefMenuColorType; out color: TCefColor): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := model.GetColor(commandId, colorType, color);
  handleExceptionEnd
end;

exports
  CefMenuModelRef_New,
  CefMenuModel_AddSeparator,
  CefMenuModel_Clear,
  CefMenuModel_IsSubMenu,
  CefMenuModel_GetCount,
  CefMenuModel_AddItem,
  CefMenuModel_AddCheckItem,
  CefMenuModel_AddRadioItem,
  CefMenuModel_AddSubMenu,
  CefMenuModel_Remove,
  CefMenuModel_RemoveAt,
  CefMenuModel_SetChecked,
  CefMenuModel_IsChecked,
  CefMenuModel_SetColor,
  CefMenuModel_SetFontList,
  CefMenuModel_HasAccelerator,
  CefMenuModel_SetAccelerator,
  CefMenuModel_RemoveAccelerator,
  CefMenuModel_IsVisible,
  CefMenuModel_SetVisible,
  CefMenuModel_IsEnabled,
  CefMenuModel_SetEnabled,
  CefMenuModel_SetLabel,
  CefMenuModel_GetIndexOf,
  CefMenuModel_GetType,
  CefMenuModel_GetLabel,
  CefMenuModel_GetGroupId,
  CefMenuModel_SetGroupId,
  CefMenuModel_GetSubMenu,
  CefMenuModel_GetColor;