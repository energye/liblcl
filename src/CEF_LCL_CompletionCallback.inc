//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefCompletionCallbackRef_Create(var Result: TCompletionCallbackRef); extdecl;
begin
  handleExceptionBegin
  Result := TCompletionCallbackRef.Create;
  handleExceptionEnd
end;

procedure CefCompletionCallback_OnComplete(const AObj: TCompletionCallbackRef; AEventData: Pointer); extdecl;
begin
    AObj.CompletionCallbackPtr := AEventData;
end;

exports
    CefCompletionCallbackRef_Create,
    CefCompletionCallback_OnComplete
;
