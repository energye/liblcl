//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  CefDragData_Clone(const AObj: ICefDragData; var Result: ICefDragData); extdecl;
begin
  handleExceptionBegin
  Result := AObj.Clone;
  handleExceptionEnd
end;

function  CefDragData_IsReadOnly(const AObj: ICefDragData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsReadOnly;
  handleExceptionEnd
end;

function  CefDragData_IsLink(const AObj: ICefDragData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsLink;
  handleExceptionEnd
end;

function  CefDragData_IsFragment(const AObj: ICefDragData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsFragment;
  handleExceptionEnd
end;

function  CefDragData_IsFile(const AObj: ICefDragData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsFile;
  handleExceptionEnd
end;

function  CefDragData_GetLinkUrl(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetLinkUrl));
  handleExceptionEnd
end;

function  CefDragData_GetLinkTitle(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetLinkTitle));
  handleExceptionEnd
end;

function  CefDragData_GetLinkMetadata(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetLinkMetadata));
  handleExceptionEnd
end;

function  CefDragData_GetFragmentText(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetFragmentText));
  handleExceptionEnd
end;

function  CefDragData_GetFragmentHtml(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetFragmentHtml));
  handleExceptionEnd
end;

function  CefDragData_GetFragmentBaseUrl(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetFragmentBaseUrl));
  handleExceptionEnd
end;

function  CefDragData_GetFileName(const AObj: ICefDragData): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetFileName));
  handleExceptionEnd
end;

function  CefDragData_GetFileContents(const AObj: ICefDragData; const writer: ICefStreamWriter): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetFileContents(writer);
  handleExceptionEnd
end;

function  CefDragData_GetFileNames(const AObj: ICefDragData; var names: TStrings): Integer; extdecl;
var
  RetNames: TStrings;
begin
  handleExceptionBegin
  RetNames := TStringList.Create;
  Result := AObj.GetFileNames(RetNames);
  names := RetNames;
  handleExceptionEnd
end;

procedure CefDragData_SetLinkUrl(const AObj: ICefDragData; const url: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetLinkUrl(PCharToUStr(url));
  handleExceptionEnd
end;

procedure CefDragData_SetLinkTitle(const AObj: ICefDragData; const title: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetLinkTitle(PCharToUStr(title));
  handleExceptionEnd
end;

procedure CefDragData_SetLinkMetadata(const AObj: ICefDragData; const data: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetLinkMetadata(PCharToUStr(data));
  handleExceptionEnd
end;

procedure CefDragData_SetFragmentText(const AObj: ICefDragData; const text: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetFragmentText(PCharToUStr(text));
  handleExceptionEnd
end;

procedure CefDragData_SetFragmentHtml(const AObj: ICefDragData; const html: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetFragmentHtml(PCharToUStr(html));
  handleExceptionEnd
end;

procedure CefDragData_SetFragmentBaseUrl(const AObj: ICefDragData; const baseUrl: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetFragmentBaseUrl(PCharToUStr(baseUrl));
  handleExceptionEnd
end;

procedure CefDragData_ResetFileContents(const AObj: ICefDragData); extdecl;
begin
  handleExceptionBegin
  AObj.ResetFileContents;
  handleExceptionEnd
end;

procedure CefDragData_AddFile(const AObj: ICefDragData; const path, displayName: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.AddFile(PCharToUStr(path), PCharToUStr(displayName));
  handleExceptionEnd
end;

procedure CefDragData_ClearFilenames(const AObj: ICefDragData); extdecl;
begin
  handleExceptionBegin
  AObj.ClearFilenames;
  handleExceptionEnd
end;

procedure  CefDragData_GetImage(const AObj: ICefDragData; var Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetImage;
  handleExceptionEnd
end;

procedure  CefDragData_GetImageHotspot(const AObj: ICefDragData; var Result: TCefPoint); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetImageHotspot;
  handleExceptionEnd
end;

function  CefDragData_HasImage(const AObj: ICefDragData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasImage;
  handleExceptionEnd
end;

exports
  CefDragData_Clone,
  CefDragData_IsReadOnly,
  CefDragData_IsLink,
  CefDragData_IsFragment,
  CefDragData_IsFile,
  CefDragData_GetLinkUrl,
  CefDragData_GetLinkTitle,
  CefDragData_GetLinkMetadata,
  CefDragData_GetFragmentText,
  CefDragData_GetFragmentHtml,
  CefDragData_GetFragmentBaseUrl,
  CefDragData_GetFileName,
  CefDragData_GetFileContents,
  CefDragData_GetFileNames,
  CefDragData_SetLinkUrl,
  CefDragData_SetLinkTitle,
  CefDragData_SetLinkMetadata,
  CefDragData_SetFragmentText,
  CefDragData_SetFragmentHtml,
  CefDragData_SetFragmentBaseUrl,
  CefDragData_ResetFileContents,
  CefDragData_AddFile,
  CefDragData_ClearFilenames,
  CefDragData_GetImage,
  CefDragData_GetImageHotspot,
  CefDragData_HasImage;
