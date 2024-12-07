//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CefDomNode_GetNodeType(const TObj: ICefDomNode): Integer; extdecl;
begin
  handleExceptionBegin
  // TCefDomNodeType
  Result := Integer(TObj.NodeType);
  handleExceptionEnd
end;

function  CefDomNode_IsText(const TObj: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsText;
  handleExceptionEnd
end;

function  CefDomNode_IsElement(const TObj: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsElement;
  handleExceptionEnd
end;

function  CefDomNode_IsEditable(const TObj: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsEditable;
  handleExceptionEnd
end;

function  CefDomNode_IsFormControlElement(const TObj: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsFormControlElement;
  handleExceptionEnd
end;

function  CefDomNode_GetFormControlElementType(const TObj: ICefDomNode): Integer; extdecl;
var
  eleType: string;
begin
  handleExceptionBegin
  eleType := string(TObj.GetFormControlElementType);
  if eleType = 'BUTTON_BUTTON' then
    Result := 1
  else if eleType = 'BUTTON_SUBMIT' then
    Result := 2
  else if eleType = 'BUTTON_RESET' then
    Result := 3
  else if eleType = 'BUTTON_SELECT_LIST' then
    Result := 4
  else if eleType = 'BUTTON_POPOVER' then
    Result := 5
  else if eleType = 'FIELDSET' then
    Result := 6
  else if eleType = 'INPUT_BUTTON' then
    Result := 7
  else if eleType = 'INPUT_CHECKBOX' then
    Result := 8
  else if eleType = 'INPUT_COLOR' then
    Result := 9
  else if eleType = 'INPUT_DATE' then
    Result := 10
  else if eleType = 'INPUT_DATETIME_LOCAL' then
    Result := 11
  else if eleType = 'INPUT_EMAIL' then
    Result := 12
  else if eleType = 'INPUT_FILE' then
    Result := 13
  else if eleType = 'INPUT_HIDDEN' then
    Result := 14
  else if eleType = 'INPUT_IMAGE' then
    Result := 15
  else if eleType = 'INPUT_MONTH' then
    Result := 16
  else if eleType = 'INPUT_NUMBER' then
    Result := 17
  else if eleType = 'INPUT_PASSWORD' then
    Result := 18
  else if eleType = 'INPUT_RADIO' then
    Result := 19
  else if eleType = 'INPUT_RANGE' then
    Result := 21
  else if eleType = 'INPUT_RESET' then
    Result := 22
  else if eleType = 'INPUT_SEARCH' then
    Result := 23
  else if eleType = 'INPUT_SUBMIT' then
    Result := 24
  else if eleType = 'INPUT_TELEPHONE' then
    Result := 25
  else if eleType = 'INPUT_TEXT' then
    Result := 26
  else if eleType = 'INPUT_TIME' then
    Result := 27
  else if eleType = 'INPUT_URL' then
    Result := 28
  else if eleType = 'INPUT_WEEK' then
    Result := 29
  else if eleType = 'OUTPUT' then
    Result := 30
  else if eleType = 'SELECT_ONE' then
    Result := 31
  else if eleType = 'SELECT_MULTIPLE' then
    Result := 32
  else if eleType = 'SELECT_LIST' then
    Result := 33
  else if eleType = 'TEXT_AREA' then
    Result := 34
  else
    Result := 0;
  handleExceptionEnd
end;

function  CefDomNode_IsSame(const TObj: ICefDomNode; const that: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSame(that);
  handleExceptionEnd
end;

function  CefDomNode_GetName(const TObj: ICefDomNode): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetName));
  handleExceptionEnd
end;

function  CefDomNode_GetValue(const TObj: ICefDomNode): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetValue));
  handleExceptionEnd
end;

function  CefDomNode_SetValue(const TObj: ICefDomNode; const value: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetValue(PCharToUStr(value));
  handleExceptionEnd
end;

function  CefDomNode_GetAsMarkup(const TObj: ICefDomNode): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetAsMarkup));
  handleExceptionEnd
end;

procedure  CefDomNode_GetDocument(const TObj: ICefDomNode; var Result: ICefDomDocument); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDocument;
  handleExceptionEnd
end;

procedure  CefDomNode_GetParent(const TObj: ICefDomNode; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetParent;
  handleExceptionEnd
end;

procedure  CefDomNode_GetPreviousSibling(const TObj: ICefDomNode; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetPreviousSibling;
  handleExceptionEnd
end;

procedure  CefDomNode_GetNextSibling(const TObj: ICefDomNode; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetNextSibling;
  handleExceptionEnd
end;

function  CefDomNode_HasChildren(const TObj: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasChildren;
  handleExceptionEnd
end;

procedure  CefDomNode_GetFirstChild(const TObj: ICefDomNode; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetFirstChild;
  handleExceptionEnd
end;

procedure  CefDomNode_GetLastChild(const TObj: ICefDomNode; var Result: ICefDomNode); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetLastChild;
  handleExceptionEnd
end;

function  CefDomNode_GetElementTagName(const TObj: ICefDomNode): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetElementTagName));
  handleExceptionEnd
end;

function  CefDomNode_HasElementAttributes(const TObj: ICefDomNode): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasElementAttributes;
  handleExceptionEnd
end;

function  CefDomNode_HasElementAttribute(const TObj: ICefDomNode; const attrName: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasElementAttribute(PCharToUStr(attrName));
  handleExceptionEnd
end;

function  CefDomNode_GetElementAttribute(const TObj: ICefDomNode; const attrName: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetElementAttribute(PCharToUStr(attrName))));
  handleExceptionEnd
end;

//procedure CefDomNode_GetElementAttributes(const TObj: ICefDomNode; const attrMap: ICefStringMap); extdecl;
//begin
//  handleExceptionBegin
//  handleExceptionEnd
//end;

procedure CefDomNode_GetElementAttributes(const TObj: ICefDomNode; var ResultAttrList: TStrings); extdecl;
begin
  handleExceptionBegin
  ResultAttrList := TStringList.Create;
  TObj.GetElementAttributes(ResultAttrList);
  handleExceptionEnd
end;

function  CefDomNode_SetElementAttribute(const TObj: ICefDomNode; const attrName, value: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetElementAttribute(PCharToUStr(attrName), PCharToUStr(value));
  handleExceptionEnd
end;

function  CefDomNode_GetElementInnerText(const TObj: ICefDomNode): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetElementInnerText()));
  handleExceptionEnd
end;

procedure  CefDomNode_GetElementBounds(const TObj: ICefDomNode; var Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetElementBounds();
  handleExceptionEnd
end;

exports
  CefDomNode_GetNodeType,
  CefDomNode_IsText,
  CefDomNode_IsElement,
  CefDomNode_IsEditable,
  CefDomNode_IsFormControlElement,
  CefDomNode_GetFormControlElementType,
  CefDomNode_IsSame,
  CefDomNode_GetName,
  CefDomNode_GetValue,
  CefDomNode_SetValue,
  CefDomNode_GetAsMarkup,
  CefDomNode_GetDocument,
  CefDomNode_GetParent,
  CefDomNode_GetPreviousSibling,
  CefDomNode_GetNextSibling,
  CefDomNode_HasChildren,
  CefDomNode_GetFirstChild,
  CefDomNode_GetLastChild,
  CefDomNode_GetElementTagName,
  CefDomNode_HasElementAttributes,
  CefDomNode_HasElementAttribute,
  CefDomNode_GetElementAttribute,
  CefDomNode_GetElementAttributes,
  CefDomNode_SetElementAttribute,
  CefDomNode_GetElementInnerText,
  CefDomNode_GetElementBounds;
