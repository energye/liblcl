//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure StringMultimapRef_Create(var Result: ICefStringMultimap); extdecl;
begin
  handleExceptionBegin
  Result := TCefStringMultimapOwn.Create();
  handleExceptionEnd
end;

function StringMultimap_GetSize(const TObj: ICefStringMultimap): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetSize;
  handleExceptionEnd
end;

function StringMultimap_FindCount(const TObj: ICefStringMultimap; Key: PChar): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.FindCount(PCharToUStr(Key));
  handleExceptionEnd
end;

function StringMultimap_GetEnumerate(const TObj: ICefStringMultimap; Key: PChar; ValueIndex: NativeUInt): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetEnumerate(PCharToUStr(Key), ValueIndex)));
  handleExceptionEnd
end;

function StringMultimap_GetKey(const TObj: ICefStringMultimap; Index: NativeUInt): PChar; extdecl;
var
  key: string;
begin
  handleExceptionBegin
  key := string(TObj.GetKey(Index));
  key := copy(key, 0, Length(key));
  Result := PChar(key);
  handleExceptionEnd
end;

function StringMultimap_GetValue(const TObj: ICefStringMultimap; Index: NativeUInt): PChar; extdecl;
var
  value: string;
begin
  handleExceptionBegin
  value := string(TObj.GetValue(Index));
  value := copy(value, 0, Length(value));
  Result := PChar(value);
  handleExceptionEnd
end;

function StringMultimap_Append(const TObj: ICefStringMultimap; Key, Value: PChar): LongBool; extdecl;
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
