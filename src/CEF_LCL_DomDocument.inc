//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CefDomDocument_GetDocType(const TObj: ICefDomDocument): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefDomDocumentType
  Result := Integer(TObj.DocType);
  handleExceptionEnd
end;

procedure CefDomDocument_GetDocument(const TObj: ICefDomDocument; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Document;
  handleExceptionEnd
end;

procedure CefDomDocument_GetBody(const TObj: ICefDomDocument; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Body;
  handleExceptionEnd
end;

procedure CefDomDocument_GetHead(const TObj: ICefDomDocument; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Head;
  handleExceptionEnd
end;

function CefDomDocument_GetTitle(const TObj: ICefDomDocument): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Title));
  handleExceptionEnd
end;

procedure CefDomDocument_GetElementById(const TObj: ICefDomDocument; const id: PChar; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetElementById(PCharToUStr(id));
  handleExceptionEnd
end;

procedure CefDomDocument_GetFocusedNode(const TObj: ICefDomDocument; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.FocusedNode;
  handleExceptionEnd
end;

function CefDomDocument_HasSelection(const TObj: ICefDomDocument): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasSelection;
  handleExceptionEnd
end;

function CefDomDocument_GetSelectionStartOffset(const TObj: ICefDomDocument): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SelectionStartOffset;
  handleExceptionEnd
end;

function CefDomDocument_GetSelectionEndOffset(const TObj: ICefDomDocument): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SelectionEndOffset;
  handleExceptionEnd
end;

function CefDomDocument_GetSelectionAsMarkup(const TObj: ICefDomDocument): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.SelectionAsMarkup));
  handleExceptionEnd
end;

function CefDomDocument_GetSelectionAsText(const TObj: ICefDomDocument): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.SelectionAsText));
  handleExceptionEnd
end;

function CefDomDocument_GetBaseUrl(const TObj: ICefDomDocument): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.BaseUrl));
  handleExceptionEnd
end;

function CefDomDocument_GetCompleteUrl(const TObj: ICefDomDocument): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetCompleteUrl()));
  handleExceptionEnd
end;

exports
   CefDomDocument_GetDocType,
   CefDomDocument_GetDocument,
   CefDomDocument_GetBody,
   CefDomDocument_GetHead,
   CefDomDocument_GetTitle,
   CefDomDocument_GetElementById,
   CefDomDocument_GetFocusedNode,
   CefDomDocument_HasSelection,
   CefDomDocument_GetSelectionStartOffset,
   CefDomDocument_GetSelectionEndOffset,
   CefDomDocument_GetSelectionAsMarkup,
   CefDomDocument_GetSelectionAsText,
   CefDomDocument_GetBaseUrl,
   CefDomDocument_GetCompleteUrl
;
