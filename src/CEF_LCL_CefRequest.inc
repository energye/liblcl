//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//request
function cefRequest_IsReadOnly(TObj: ICefRequest): boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly;
  handleExceptionEnd
end;

procedure cefRequest_SetUrl(TObj: ICefRequest; Url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetUrl(PCharToUStr(Url));
  handleExceptionEnd
end;

procedure cefRequest_SetMethod(TObj: ICefRequest; Method: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetMethod(PCharToUStr(Method));
  handleExceptionEnd
end;

procedure cefRequest_SetReferrer(TObj: ICefRequest; referrerUrl: PChar; policy: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetReferrer(PCharToUStr(referrerUrl), TCefReferrerPolicy(policy));
  handleExceptionEnd
end;

procedure cefRequest_SetFlags(TObj: ICefRequest; flags: Cardinal); extdecl;
begin
  handleExceptionBegin
  TObj.SetFlags(flags);
  handleExceptionEnd
end;

procedure cefRequest_SetFirstPartyForCookies(TObj: ICefRequest; url: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetFirstPartyForCookies(PCharToUStr(url));
  handleExceptionEnd
end;

function cefRequest_GetHeaderByName(TObj: ICefRequest; name: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  TObj.GetHeaderByName(PCharToUStr(name));
  handleExceptionEnd
end;

procedure cefRequest_SetHeaderByName(TObj: ICefRequest; name, value: PChar ; overwrite: boolean); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderByName(PCharToUStr(name), PCharToUStr(value), overwrite);
  handleExceptionEnd
end;

function cefRequest_GetHeaderMap(TObj: ICefRequest): TCefCustomStringMultimap; extdecl;
var
  headerMap: TCefCustomStringMultimap;
begin
  handleExceptionBegin
  headerMap := TCefStringMultimapOwn.Create;
  TObj.GetHeaderMap(headerMap);
  Result := headerMap;
  handleExceptionEnd
end;

procedure cefRequest_SetHeaderMap(TObj: ICefRequest; HeaderMap: TCefCustomStringMultimap); extdecl;
begin
  handleExceptionBegin
  TObj.SetHeaderMap(ICefStringMultimap(HeaderMap));
  handleExceptionEnd
end;


exports
  cefRequest_IsReadOnly,
  cefRequest_SetUrl,
  cefRequest_SetMethod,
  cefRequest_SetReferrer,
  cefRequest_SetFlags,
  cefRequest_SetFirstPartyForCookies,
  cefRequest_GetHeaderByName,
  cefRequest_SetHeaderByName,
  cefRequest_GetHeaderMap,
  cefRequest_SetHeaderMap
;
