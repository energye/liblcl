//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function SchemeRegistrarRef_AddCustomScheme(const AObj: ICEFSchemeRegistrar; const schemeName: PChar; IsStandard, IsLocal, IsDisplayIsolated: LongBool):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.AddCustomScheme(PCharToUStr(schemeName), IsStandard, IsLocal, IsDisplayIsolated);
  handleExceptionEnd
end;

exports
  SchemeRegistrarRef_AddCustomScheme;
