//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function cefMenuModel_AddSeparator(const model :ICefMenuModel): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.AddSeparator;
    handleExceptionEnd
end;

function cefMenuModel_Clear(const model :ICefMenuModel): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.Clear;
    handleExceptionEnd
end;

function cefMenuModel_IsSubMenu(const model :ICefMenuModel): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.IsSubMenu;
    handleExceptionEnd
end;

function cefMenuModel_GetCount(const model :ICefMenuModel): Integer ; extdecl;
begin
    handleExceptionBegin
    Result := model.GetCount;
    handleExceptionEnd
end;

function cefMenuModel_AddItem(const model :ICefMenuModel; commandId: integer; PText: PChar): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.AddItem(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_AddCheckItem(const model :ICefMenuModel; commandId: Integer; PText: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.AddCheckItem(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_AddRadioItem(const model :ICefMenuModel; commandId: Integer; PText: PChar; groupId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.AddRadioItem(commandId, PCharToUStr(PText), groupId);
    handleExceptionEnd
end;

procedure cefMenuModel_AddSubMenu(const model :ICefMenuModel; commandId: Integer; PText: PChar; out ret: ICefMenuModel); extdecl;
begin
    handleExceptionBegin
    ret := model.AddSubMenu(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_Remove(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.Remove(commandId);
    handleExceptionEnd
end;

function cefMenuModel_RemoveAt(const model :ICefMenuModel; index: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.RemoveAt(index);
    handleExceptionEnd
end;

function cefMenuModel_SetChecked(const model :ICefMenuModel; commandId: Integer; checked: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.setChecked(commandId, checked);
    handleExceptionEnd
end;

function cefMenuModel_IsChecked(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.IsChecked(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetColor(const model :ICefMenuModel; commandId: Integer; colorType: integer; color: Cardinal): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetColor(commandId, TCefMenuColorType(colorType), TCefColor(color));
    handleExceptionEnd
end;

function cefMenuModel_SetFontList(const model :ICefMenuModel; commandId: Integer; PFontList: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetFontList(commandId, PCharToUStr(PFontList));
    handleExceptionEnd
end;

function cefMenuModel_HasAccelerator(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.HasAccelerator(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetAccelerator(const model :ICefMenuModel; commandId, keyCode: Integer; shiftPressed, ctrlPressed, altPressed: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetAccelerator(commandId, keyCode, shiftPressed, ctrlPressed, altPressed);
    handleExceptionEnd
end;

function cefMenuModel_RemoveAccelerator(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.RemoveAccelerator(commandId);
    handleExceptionEnd
end;

function cefMenuModel_IsVisible(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.IsVisible(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetVisible(const model :ICefMenuModel; commandId: Integer; visible: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetVisible(commandId, visible);
    handleExceptionEnd
end;

function cefMenuModel_IsEnabled(const model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.IsEnabled(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetEnabled(const model :ICefMenuModel; commandId: Integer; enabled: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetEnabled(commandId, enabled);
    handleExceptionEnd
end;

function cefMenuModel_SetLabel(const model :ICefMenuModel; commandId: Integer; PText: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetLabel(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_GetIndexOf(const model :ICefMenuModel; commandId: Integer): Integer ; extdecl;
begin
    handleExceptionBegin
    Result := model.GetIndexOf(commandId);
    handleExceptionEnd
end;

exports
  cefMenuModel_AddSeparator,
  cefMenuModel_Clear,
  cefMenuModel_IsSubMenu,
  cefMenuModel_GetCount,
  cefMenuModel_AddItem,
  cefMenuModel_AddCheckItem,
  cefMenuModel_AddRadioItem,
  cefMenuModel_AddSubMenu,
  cefMenuModel_Remove,
  cefMenuModel_RemoveAt,
  cefMenuModel_SetChecked,
  cefMenuModel_IsChecked,
  cefMenuModel_SetColor,
  cefMenuModel_SetFontList,
  cefMenuModel_HasAccelerator,
  cefMenuModel_SetAccelerator,
  cefMenuModel_RemoveAccelerator,
  cefMenuModel_IsVisible,
  cefMenuModel_SetVisible,
  cefMenuModel_IsEnabled,
  cefMenuModel_SetEnabled,
  cefMenuModel_SetLabel,
  cefMenuModel_GetIndexOf
//结尾
;

