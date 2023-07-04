//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MenuButtonRef_New(const delegate: ICefMenuButtonDelegate; const text: PChar; out Result: ICefMenuButton) ; extdecl;
begin
    handleExceptionBegin
    Result := TCefMenuButtonRef.CreateMenuButton(delegate, PCharToUStr(text));
    handleExceptionEnd
end;

procedure MenuButton_ShowMenu(const AObj: ICefMenuButton; const menu_model: ICefMenuModel; const screen_point: TCefPoint; anchor_position: TCefMenuAnchorPosition); extdecl;
begin
    handleExceptionBegin
    AObj.ShowMenu(menu_model, screen_point, anchor_position);
    handleExceptionEnd
end;

procedure MenuButton_TriggerMenu(const AObj: ICefMenuButton); extdecl;
begin
    handleExceptionBegin
    AObj.TriggerMenu;
    handleExceptionEnd
end;

exports
  MenuButtonRef_New,
  MenuButton_ShowMenu,
  MenuButton_TriggerMenu
;

