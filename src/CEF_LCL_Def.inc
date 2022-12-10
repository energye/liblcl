//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CEFVersion: PChar; extdecl;
begin
  Result := PChar('1.107.1.12');
end;

function LibBuildVersion: PChar; extdecl;
begin
  Result := PChar('2.2.4');
end;

exports
  CEFVersion,
  LibBuildVersion
;
