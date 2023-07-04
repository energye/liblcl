//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MenuButtonComponent_Create(const AOwner: TComponent; out Result: TCEFMenuButtonComponent); extdecl;
begin
  handleExceptionBegin
  Result := TCEFMenuButtonComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure MenuButtonComponent_CreateMenuButton(const AObj: TCEFMenuButtonComponent; const aText : PChar); extdecl;
begin
    handleExceptionBegin
    AObj.CreateMenuButton(PCharToUStr(aText));
    handleExceptionEnd
end;

procedure MenuButtonComponent_ShowMenu(const AObj: TCEFMenuButtonComponent; const menu_model: ICefMenuModel; const screen_point: TCefPoint; anchor_position: TCefMenuAnchorPosition); extdecl;
begin
    handleExceptionBegin
    AObj.ShowMenu(menu_model, screen_point, anchor_position);
    handleExceptionEnd
end;

procedure MenuButtonComponent_TriggerMenu(const AObj: TCEFMenuButtonComponent); extdecl;
begin
    handleExceptionBegin
    AObj.TriggerMenu;
    handleExceptionEnd
end;

procedure MenuButtonComponent_SetOnMenuButtonPressed(const AObj: TCEFMenuButtonComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := MenuButtonComponent_OnMenuButtonPressed}
    {$DEFINE EventName := OnMenuButtonPressed}
    EventMethodCode
end;

exports
  MenuButtonComponent_Create,
  MenuButtonComponent_CreateMenuButton,
  MenuButtonComponent_ShowMenu,
  MenuButtonComponent_TriggerMenu,
  MenuButtonComponent_SetOnMenuButtonPressed
;
