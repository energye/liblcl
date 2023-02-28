//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function cefMenuModel_AddSeparator(model :ICefMenuModel): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.AddSeparator;
    handleExceptionEnd
end;

function cefMenuModel_Clear(model :ICefMenuModel): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.Clear;
    handleExceptionEnd
end;

function cefMenuModel_IsSubMenu(model :ICefMenuModel): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.IsSubMenu;
    handleExceptionEnd
end;

function cefMenuModel_GetCount(model :ICefMenuModel): Integer ; extdecl;
begin
    handleExceptionBegin
    Result := model.GetCount;
    handleExceptionEnd
end;

function cefMenuModel_AddItem(model :ICefMenuModel; commandId: integer; PText: PChar): LongBool ; extdecl;
begin
    handleExceptionBegin
    Result := model.AddItem(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_AddCheckItem(model :ICefMenuModel; commandId: Integer; PText: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.AddCheckItem(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_AddRadioItem(model :ICefMenuModel; commandId: Integer; PText: PChar; groupId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.AddRadioItem(commandId, PCharToUStr(PText), groupId);
    handleExceptionEnd
end;

procedure cefMenuModel_AddSubMenu(model :ICefMenuModel; commandId: Integer; PText: PChar; out ret: ICefMenuModel); extdecl;
begin
    handleExceptionBegin
    ret := model.AddSubMenu(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_Remove(model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.Remove(commandId);
    handleExceptionEnd
end;

function cefMenuModel_RemoveAt(model :ICefMenuModel; index: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.RemoveAt(index);
    handleExceptionEnd
end;

function cefMenuModel_SetChecked(model :ICefMenuModel; commandId: Integer; checked: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.setChecked(commandId, checked);
    handleExceptionEnd
end;

function cefMenuModel_IsChecked(model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.IsChecked(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetColor(model :ICefMenuModel; commandId: Integer; colorType: integer; color: Cardinal): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetColor(commandId, TCefMenuColorType(colorType), TCefColor(color));
    handleExceptionEnd
end;

function cefMenuModel_SetFontList(model :ICefMenuModel; commandId: Integer; PFontList: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetFontList(commandId, PCharToUStr(PFontList));
    handleExceptionEnd
end;

function cefMenuModel_HasAccelerator(model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.HasAccelerator(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetAccelerator(model :ICefMenuModel; commandId, keyCode: Integer; shiftPressed, ctrlPressed, altPressed: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetAccelerator(commandId, keyCode, shiftPressed, ctrlPressed, altPressed);
    handleExceptionEnd
end;

function cefMenuModel_RemoveAccelerator(model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.RemoveAccelerator(commandId);
    handleExceptionEnd
end;

function cefMenuModel_IsVisible(model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.IsVisible(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetVisible(model :ICefMenuModel; commandId: Integer; visible: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetVisible(commandId, visible);
    handleExceptionEnd
end;

function cefMenuModel_IsEnabled(model :ICefMenuModel; commandId: Integer): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.IsEnabled(commandId);
    handleExceptionEnd
end;

function cefMenuModel_SetEnabled(model :ICefMenuModel; commandId: Integer; enabled: LongBool): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetEnabled(commandId, enabled);
    handleExceptionEnd
end;

function cefMenuModel_SetLabel(model :ICefMenuModel; commandId: Integer; PText: PChar): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := model.SetLabel(commandId, PCharToUStr(PText));
    handleExceptionEnd
end;

function cefMenuModel_GetIndexOf(model :ICefMenuModel; commandId: Integer): Integer ; extdecl;
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

