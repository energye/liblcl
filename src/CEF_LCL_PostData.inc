//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPostDataRef_Create(out Result: ICefPostData); extdecl;
begin
  handleExceptionBegin
  Result := TCefPostDataRef.New;
  handleExceptionEnd
end;

function CefPostData_IsReadOnly(const TObj: ICefPostData): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly();
  handleExceptionEnd
end;

function CefPostData_HasExcludedElements(const TObj: ICefPostData): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasExcludedElements();
  handleExceptionEnd
end;

function CefPostData_GetElementCount(const TObj: ICefPostData): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetElementCount();
  handleExceptionEnd
end;

procedure CefPostData_GetElements(const TObj: ICefPostData; elementsCount: NativeUInt; out Result: TCefPostDataElementArray); extdecl;
begin
  handleExceptionBegin
  //SetLength(Result, elementsCount);
  TObj.GetElements(elementsCount, Result);
  handleExceptionEnd
end;

function CefPostData_RemoveElement(const TObj: ICefPostData; const element: ICefPostDataElement): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.RemoveElement(element);
  handleExceptionEnd
end;

function CefPostData_AddElement(const TObj: ICefPostData; const element: ICefPostDataElement): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.AddElement(element);
  handleExceptionEnd
end;

procedure CefPostData_RemoveElements(const TObj: ICefPostData); extdecl;
begin
  handleExceptionBegin
  TObj.RemoveElements();
  handleExceptionEnd
end;

exports
  CefPostDataRef_Create,
  CefPostData_IsReadOnly,
  CefPostData_HasExcludedElements,
  CefPostData_GetElementCount,
  CefPostData_GetElements,
  CefPostData_RemoveElement,
  CefPostData_AddElement,
  CefPostData_RemoveElements
;
