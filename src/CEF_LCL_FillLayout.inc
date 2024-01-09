//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  FillLayoutRef_UnWrap(const data: Pointer; out Result: ICefFillLayout); extdecl;
begin
  handleExceptionBegin
  Result := TCefFillLayoutRef.UnWrap(data);
  handleExceptionEnd
end;

exports
  FillLayoutRef_UnWrap;
