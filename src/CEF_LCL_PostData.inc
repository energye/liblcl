//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPostDataRef_Create(var Result: ICefPostData); extdecl;
begin
  handleExceptionBegin
  Result := TCefPostDataRef.New;
  handleExceptionEnd
end;

procedure CefPostDataRef_UnWrap(const data: ICefPostData; var Result: ICefPostData); extdecl;
begin
  handleExceptionBegin
  Result := TCefPostDataRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function CefPostData_IsReadOnly(const TObj: ICefPostData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly();
  handleExceptionEnd
end;

function CefPostData_HasExcludedElements(const TObj: ICefPostData): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasExcludedElements();
  handleExceptionEnd
end;

function CefPostData_GetElementCount(const TObj: ICefPostData): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetCount();
  handleExceptionEnd
end;

procedure CefPostData_GetElements(const TObj: ICefPostData; elementsCount: NativeUInt; var Result: TCefPostDataElementArray); extdecl;
begin
  handleExceptionBegin
  TObj.GetElements(elementsCount, Result);
  handleExceptionEnd
end;

function CefPostData_RemoveElement(const TObj: ICefPostData; const element: ICefPostDataElement): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.RemoveElement(element) > 0;
  handleExceptionEnd
end;

function CefPostData_AddElement(const TObj: ICefPostData; const element: ICefPostDataElement): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.AddElement(element) > 0;
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
  CefPostDataRef_UnWrap,
  CefPostData_IsReadOnly,
  CefPostData_HasExcludedElements,
  CefPostData_GetElementCount,
  CefPostData_GetElements,
  CefPostData_RemoveElement,
  CefPostData_AddElement,
  CefPostData_RemoveElements;
