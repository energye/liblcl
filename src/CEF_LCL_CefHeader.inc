//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//header map
function cefHeaderMap_GetSize(TObj: TCefCustomStringMultimap): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := ICefStringMultimap(TObj).GetSize;
  handleExceptionEnd
end;

function cefHeaderMap_FindCount(TObj: TCefCustomStringMultimap; Key: PChar): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := ICefStringMultimap(TObj).FindCount(PCharToUStr(Key));
  handleExceptionEnd
end;

function cefHeaderMap_GetEnumerate(TObj: TCefCustomStringMultimap; Key: PChar; ValueIndex: NativeUInt): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(ICefStringMultimap(TObj).GetEnumerate(PCharToUStr(Key), ValueIndex)));
  handleExceptionEnd
end;

function cefHeaderMap_GetKey(TObj: TCefCustomStringMultimap; Index: NativeUInt): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(ICefStringMultimap(TObj).GetKey(Index)));
  handleExceptionEnd
end;

function cefHeaderMap_GetValue(TObj: TCefCustomStringMultimap; Index: NativeUInt): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(ICefStringMultimap(TObj).GetValue(Index)));
  handleExceptionEnd
end;

function cefHeaderMap_Append(TObj: TCefCustomStringMultimap; Key, Value: PChar) : boolean; extdecl;
begin
  handleExceptionBegin
  Result := ICefStringMultimap(TObj).Append(PCharToUStr(Key), PCharToUStr(Value));
  handleExceptionEnd
end;

procedure cefHeaderMap_Clear(TObj: TCefCustomStringMultimap); extdecl;
begin
  handleExceptionBegin
  ICefStringMultimap(TObj).Clear;
  handleExceptionEnd
end;

exports
//header map
  cefHeaderMap_GetSize,
  cefHeaderMap_FindCount,
  cefHeaderMap_GetEnumerate,
  cefHeaderMap_GetKey,
  cefHeaderMap_GetValue,
  cefHeaderMap_Append,
  cefHeaderMap_Clear
;
