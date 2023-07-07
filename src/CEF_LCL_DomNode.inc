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

function  CefDomNode_GetFormControlElementType(const TObj: ICefDomNode): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetFormControlElementType));
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