//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function ContextMenuParams_XCoord(const TObj: ICefContextMenuParams): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetXCoord;
  handleExceptionEnd
end;

function ContextMenuParams_YCoord(const TObj: ICefContextMenuParams): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetYCoord;
  handleExceptionEnd
end;

function ContextMenuParams_TypeFlags(const TObj: ICefContextMenuParams): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefContextMenuTypeFlags
  Result := Integer(TObj.GetTypeFlags);
  handleExceptionEnd
end;

function ContextMenuParams_LinkUrl(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetLinkUrl));
  handleExceptionEnd
end;

function ContextMenuParams_UnfilteredLinkUrl(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetUnfilteredLinkUrl));
  handleExceptionEnd
end;

function ContextMenuParams_SourceUrl(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetSourceUrl));
  handleExceptionEnd
end;

function ContextMenuParams_HasImageContents(const TObj: ICefContextMenuParams): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasImageContents;
  handleExceptionEnd
end;

function ContextMenuParams_PageUrl(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetPageUrl));
  handleExceptionEnd
end;

function ContextMenuParams_FrameUrl(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetFrameUrl));
  handleExceptionEnd
end;

function ContextMenuParams_FrameCharset(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetFrameCharset));
  handleExceptionEnd
end;

function ContextMenuParams_MediaType(const TObj: ICefContextMenuParams): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefContextMenuMediaType
  Result := Integer(TObj.GetMediaType);
  handleExceptionEnd
end;

function ContextMenuParams_MediaStateFlags(const TObj: ICefContextMenuParams): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefContextMenuMediaStateFlags
  Result := Integer(TObj.GetMediaType);
  handleExceptionEnd
end;

function ContextMenuParams_SelectionText(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetSelectionText));
  handleExceptionEnd
end;

function ContextMenuParams_MisspelledWord(const TObj: ICefContextMenuParams): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetMisspelledWord));
  handleExceptionEnd
end;

function ContextMenuParams_DictionarySuggestions(const TObj: ICefContextMenuParams; const suggestions: TStringList): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDictionarySuggestions(suggestions);
  handleExceptionEnd
end;

function ContextMenuParams_IsEditable(const TObj: ICefContextMenuParams): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsEditable;
  handleExceptionEnd
end;

function ContextMenuParams_IsSpellCheckEnabled(const TObj: ICefContextMenuParams): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSpellCheckEnabled;
  handleExceptionEnd
end;

function ContextMenuParams_EditStateFlags(const TObj: ICefContextMenuParams): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefContextMenuEditStateFlags
  Result := Integer(TObj.EditStateFlags);
  handleExceptionEnd
end;

function ContextMenuParams_IsCustomMenu(const TObj: ICefContextMenuParams): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsCustomMenu;
  handleExceptionEnd
end;


exports
  ContextMenuParams_XCoord,
  ContextMenuParams_YCoord,
  ContextMenuParams_TypeFlags,
  ContextMenuParams_LinkUrl,
  ContextMenuParams_UnfilteredLinkUrl,
  ContextMenuParams_SourceUrl,
  ContextMenuParams_HasImageContents,
  ContextMenuParams_PageUrl,
  ContextMenuParams_FrameUrl,
  ContextMenuParams_FrameCharset,
  ContextMenuParams_MediaType,
  ContextMenuParams_MediaStateFlags,
  ContextMenuParams_SelectionText,
  ContextMenuParams_MisspelledWord,
  ContextMenuParams_DictionarySuggestions,
  ContextMenuParams_IsEditable,
  ContextMenuParams_IsSpellCheckEnabled,
  ContextMenuParams_EditStateFlags,
  ContextMenuParams_IsCustomMenu;
