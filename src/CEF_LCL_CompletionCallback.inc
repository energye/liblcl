//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefCompletionCallbackRef_Create(out Result: ICefCompletionCallback); extdecl;
begin
  handleExceptionBegin
  Result := TCompletionCallbackRef.Create;
  handleExceptionEnd
end;

procedure CefCompletionCallback_OnComplete(const AObj: ICefCompletionCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TCompletionCallbackRef).CompletionCallbackPtr := AEventData;
  handleExceptionEnd
end;

exports
  CefCompletionCallbackRef_Create,
  CefCompletionCallback_OnComplete;