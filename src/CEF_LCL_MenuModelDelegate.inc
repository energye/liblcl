//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MenuModelDelegateRef_Create(var Result: TMenuModelDelegateRef); extdecl;
begin
  handleExceptionBegin
  Result := TMenuModelDelegateRef.Create;
  handleExceptionEnd
end;

procedure MenuModelDelegate_ExecuteCommand(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ExecuteCommandPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_MouseOutsideMenu(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.MouseOutsideMenuPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_UnhandledOpenSubmenu(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.UnhandledOpenSubmenuPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_UnhandledCloseSubmenu(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.UnhandledCloseSubmenuPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_MenuWillShow(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.MenuWillShowPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_MenuClosed(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.MenuClosedPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_FormatLabel(const AObj: TMenuModelDelegateRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.FormatLabelPtr := AEventData;
  handleExceptionEnd
end;

exports
  MenuModelDelegateRef_Create,
  MenuModelDelegate_ExecuteCommand,
  MenuModelDelegate_MouseOutsideMenu,
  MenuModelDelegate_UnhandledOpenSubmenu,
  MenuModelDelegate_UnhandledCloseSubmenu,
  MenuModelDelegate_MenuWillShow,
  MenuModelDelegate_MenuClosed,
  MenuModelDelegate_FormatLabel
;
