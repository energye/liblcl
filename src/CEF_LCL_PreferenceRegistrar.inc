//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function PreferenceRegistrarRef_AddPreference(const TObj: TCefPreferenceRegistrarRef; const name: PChar; const default_value: ICefValue): LongBool; extdecl;
begin
  handleExceptionBegin
  TObj.AddPreference(PCharToUStr(name), default_value);
  handleExceptionEnd
end;

exports
  PreferenceRegistrarRef_AddPreference;
