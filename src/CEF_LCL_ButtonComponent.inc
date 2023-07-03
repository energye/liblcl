//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ButtonComponent_Create(const AOwner: TComponent; out Result: TCEFButtonComponent); extdecl;
begin
  handleExceptionBegin
  Result := TCEFButtonComponent.Create(AOwner);
  handleExceptionEnd
end;

exports
  ButtonComponent_Create
;
