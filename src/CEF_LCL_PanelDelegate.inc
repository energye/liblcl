//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure PanelDelegateRef_Create(out Result: ICefPanelDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TPanelDelegateRef.Create;
  handleExceptionEnd
end;

procedure PanelDelegateRef_CreateForCustom(const events: ICefPanelDelegateEvents; out Result: ICefPanelDelegate); extdecl;
begin
  handleExceptionBegin
  Result := TCustomPanelDelegate.Create(events);
  handleExceptionEnd
end;

exports
  PanelDelegateRef_Create,
  PanelDelegateRef_CreateForCustom;