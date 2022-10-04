//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function cefMenuModel_AddSeparator(model :ICefMenuModel): Boolean ; extdecl;
begin
  Result := model.AddSeparator;
end;

function cefMenuModel_Clear(model :ICefMenuModel): Boolean ; extdecl;
begin
  Result := model.Clear;
end;

function cefMenuModel_IsSubMenu(model :ICefMenuModel): Boolean ; extdecl;
begin
  Result := model.IsSubMenu;
end;

function cefMenuModel_GetCount(model :ICefMenuModel): Integer ; extdecl;
begin
  Result := model.GetCount;
end;

function cefMenuModel_AddItem(model :ICefMenuModel; commandId: integer; PText: PChar): Boolean ; extdecl;
begin
  Result := model.AddItem(commandId, PCharToUStr(PText));
end;

function cefMenuModel_AddCheckItem(model :ICefMenuModel; commandId: Integer; PText: PChar): Boolean; extdecl;
begin
  Result := model.AddCheckItem(commandId, PCharToUStr(PText));
end;

function cefMenuModel_AddRadioItem(model :ICefMenuModel; commandId: Integer; PText: PChar; groupId: Integer): Boolean; extdecl;
begin
  Result := model.AddRadioItem(commandId, PCharToUStr(PText), groupId);
end;

procedure cefMenuModel_AddSubMenu(model :ICefMenuModel; commandId: Integer; PText: PChar; out ret: ICefMenuModel); extdecl;
begin
  ret := model.AddSubMenu(commandId, PCharToUStr(PText));
end;

function cefMenuModel_Remove(model :ICefMenuModel; commandId: Integer): Boolean; extdecl;
begin
  Result := model.Remove(commandId);
end;

function cefMenuModel_RemoveAt(model :ICefMenuModel; index: Integer): Boolean; extdecl;
begin
  Result := model.RemoveAt(index);
end;

function cefMenuModel_SetChecked(model :ICefMenuModel; commandId: Integer; checked: Boolean): Boolean; extdecl;
begin
  Result := model.setChecked(commandId, checked);
end;

function cefMenuModel_IsChecked(model :ICefMenuModel; commandId: Integer): Boolean; extdecl;
begin
  Result := model.IsChecked(commandId);
end;

function cefMenuModel_SetColor(model :ICefMenuModel; commandId: Integer; colorType: integer; color: Cardinal): Boolean; extdecl;
begin
  Result := model.SetColor(commandId, TCefMenuColorType(colorType), TCefColor(color));
end;

function cefMenuModel_SetFontList(model :ICefMenuModel; commandId: Integer; PFontList: PChar): Boolean; extdecl;
begin
  Result := model.SetFontList(commandId, PCharToUStr(PFontList));
end;

function cefMenuModel_HasAccelerator(model :ICefMenuModel; commandId: Integer): Boolean; extdecl;
begin
  Result := model.HasAccelerator(commandId);
end;

function cefMenuModel_SetAccelerator(model :ICefMenuModel; commandId, keyCode: Integer; shiftPressed, ctrlPressed, altPressed: Boolean): Boolean; extdecl;
begin
  Result := model.SetAccelerator(commandId, keyCode, shiftPressed, ctrlPressed, altPressed);
end;

function cefMenuModel_RemoveAccelerator(model :ICefMenuModel; commandId: Integer): Boolean; extdecl;
begin
  Result := model.RemoveAccelerator(commandId);
end;

function cefMenuModel_IsVisible(model :ICefMenuModel; commandId: Integer): Boolean; extdecl;
begin
     Result := model.IsVisible(commandId);
end;

function cefMenuModel_SetVisible(model :ICefMenuModel; commandId: Integer; visible: Boolean): Boolean; extdecl;
begin
     Result := model.SetVisible(commandId, visible);
end;

function cefMenuModel_IsEnabled(model :ICefMenuModel; commandId: Integer): Boolean; extdecl;
begin
     Result := model.IsEnabled(commandId);
end;

function cefMenuModel_SetEnabled(model :ICefMenuModel; commandId: Integer; enabled: Boolean): Boolean; extdecl;
begin
     Result := model.SetEnabled(commandId, enabled);
end;

function cefMenuModel_SetLabel(model :ICefMenuModel; commandId: Integer; PText: PChar): Boolean; extdecl;
begin
     Result := model.SetLabel(commandId, PCharToUStr(PText));
end;

function cefMenuModel_GetIndexOf(model :ICefMenuModel; commandId: Integer): Integer ; extdecl;
begin
  Result := model.GetIndexOf(commandId);
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

