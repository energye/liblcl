//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------


procedure StringMultimapRef_Create(out Result: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  Result := TCefStringMultimapOwn.Create();
  handleExceptionEnd
end;

function StringMultimap_GetSize(const TObj: ICefStringMultimap): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TObj.GetSize);
  handleExceptionEnd
end;

function StringMultimap_FindCount(const TObj: ICefStringMultimap; Key: PChar): Integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TObj.FindCount(PCharToUStr(Key)));
  handleExceptionEnd
end;

function StringMultimap_GetEnumerate(const TObj: ICefStringMultimap; Key: PChar; ValueIndex: Integer): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetEnumerate(PCharToUStr(Key), NativeUInt(ValueIndex))));
  handleExceptionEnd
end;

function StringMultimap_GetKey(const TObj: ICefStringMultimap; Index: Integer): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetKey(NativeUInt(Index))));
  handleExceptionEnd
end;

function StringMultimap_GetValue(const TObj: ICefStringMultimap; Index: Integer): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetValue(NativeUInt(Index))));
  handleExceptionEnd
end;

function StringMultimap_Append(const TObj: ICefStringMultimap; Key, Value: PChar): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Append(PCharToUStr(Key), PCharToUStr(Value));
  handleExceptionEnd
end;

procedure StringMultimap_Clear(const TObj: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  TObj.Clear;
  handleExceptionEnd
end;

exports
  StringMultimapRef_Create,
  StringMultimap_GetSize,
  StringMultimap_FindCount,
  StringMultimap_GetEnumerate,
  StringMultimap_GetKey,
  StringMultimap_GetValue,
  StringMultimap_Append,
  StringMultimap_Clear
;
