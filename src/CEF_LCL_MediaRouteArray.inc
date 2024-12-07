//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaRouteArray_Get(const AObj: TCefMediaRouteArray; index: Integer; out Result: ICefMediaRoute); extdecl;
begin
  handleExceptionBegin
  Result := AObj[index];
  handleExceptionEnd
end;

exports
  MediaRouteArray_Get;
