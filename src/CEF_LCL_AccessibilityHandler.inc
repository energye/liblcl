//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefAccessibilityHandlerRef_Create(var Result: TAccessibilityHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TAccessibilityHandlerRef.Create();
  handleExceptionEnd
end;

procedure CefAccessibilityHandler_OnAccessibilityTreeChange(const TObj: TAccessibilityHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.AccessibilityTreeChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefAccessibilityHandler_OnAccessibilityLocationChange(const TObj: TAccessibilityHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.AccessibilityLocationChangePtr := AEventData;
  handleExceptionEnd
end;

exports
  CefAccessibilityHandlerRef_Create,
  CefAccessibilityHandler_OnAccessibilityTreeChange,
  CefAccessibilityHandler_OnAccessibilityLocationChange
;
