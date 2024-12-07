//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure NavigationEntryRef_UnWrap(const AObj: ICefNavigationEntry; out Result: ICefNavigationEntry); extdecl;
begin
  handleExceptionBegin
  Result := TCefNavigationEntryRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function NavigationEntry_IsValid(const AObj: ICefNavigationEntry): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsValid();
  handleExceptionEnd
end;

function NavigationEntry_GetUrl(const AObj: ICefNavigationEntry): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetUrl());
  handleExceptionEnd
end;

function NavigationEntry_GetDisplayUrl(const AObj: ICefNavigationEntry): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetDisplayUrl());
  handleExceptionEnd
end;

function NavigationEntry_GetOriginalUrl(const AObj: ICefNavigationEntry): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetOriginalUrl());
  handleExceptionEnd
end;

function NavigationEntry_GetTitle(const AObj: ICefNavigationEntry): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetTitle());
  handleExceptionEnd
end;

function NavigationEntry_GetTransitionType(const AObj: ICefNavigationEntry): TCefTransitionType; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetTransitionType();
  handleExceptionEnd
end;

function NavigationEntry_HasPostData(const AObj: ICefNavigationEntry): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasPostData();
  handleExceptionEnd
end;

procedure NavigationEntry_GetCompletionTime(const AObj: ICefNavigationEntry; var Result: TDateTime); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetCompletionTime();
  handleExceptionEnd
end;

function NavigationEntry_GetHttpStatusCode(const AObj: ICefNavigationEntry): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetHttpStatusCode();
  handleExceptionEnd
end;

procedure NavigationEntry_GetSSLStatus(const AObj: ICefNavigationEntry; var Result: ICefSSLStatus); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSSLStatus();
  handleExceptionEnd
end;

exports
  NavigationEntryRef_UnWrap,
  NavigationEntry_IsValid,
  NavigationEntry_GetUrl,
  NavigationEntry_GetDisplayUrl,
  NavigationEntry_GetOriginalUrl,
  NavigationEntry_GetTitle,
  NavigationEntry_GetTransitionType,
  NavigationEntry_HasPostData,
  NavigationEntry_GetCompletionTime,
  NavigationEntry_GetHttpStatusCode,
  NavigationEntry_GetSSLStatus;
