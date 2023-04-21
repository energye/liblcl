//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function SchemeRegistrarRef_AddCustomScheme(const AObj: TCefSchemeRegistrarRef; const schemeName: PChar; options: TCefSchemeOptions):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AddCustomScheme(PCharToUStr(schemeName), options);
  handleExceptionEnd
end;

exports
  SchemeRegistrarRef_AddCustomScheme
;
