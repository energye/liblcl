//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefAccessibilityHandlerRef_Create(var Result: ICefAccessibilityHandler); extdecl;
begin
  handleExceptionBegin
  Result := TAccessibilityHandlerRef.Create();
  handleExceptionEnd
end;

procedure CefAccessibilityHandler_OnAccessibilityTreeChange(const TObj: ICefAccessibilityHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TAccessibilityHandlerRef).AccessibilityTreeChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefAccessibilityHandler_OnAccessibilityLocationChange(const TObj: ICefAccessibilityHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TAccessibilityHandlerRef).AccessibilityLocationChangePtr := AEventData;
  handleExceptionEnd
end;

exports
  CefAccessibilityHandlerRef_Create,
  CefAccessibilityHandler_OnAccessibilityTreeChange,
  CefAccessibilityHandler_OnAccessibilityLocationChange;