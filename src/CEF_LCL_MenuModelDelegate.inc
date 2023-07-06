//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MenuModelDelegateRef_Create(var Result: ICefMenuModelDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TMenuModelDelegateRef.Create;
  handleExceptionEnd
end;

procedure MenuModelDelegate_ExecuteCommand(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).ExecuteCommandPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_MouseOutsideMenu(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).MouseOutsideMenuPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_UnhandledOpenSubmenu(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).UnhandledOpenSubmenuPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_UnhandledCloseSubmenu(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).UnhandledCloseSubmenuPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_MenuWillShow(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).MenuWillShowPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_MenuClosed(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).MenuClosedPtr := AEventData;
  handleExceptionEnd
end;

procedure MenuModelDelegate_FormatLabel(const AObj: ICefMenuModelDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMenuModelDelegateRef).FormatLabelPtr := AEventData;
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
