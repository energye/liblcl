//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure RunFileDialogCallbackRef_Create(var Result: TRunFileDialogCallbackRef); extdecl;
begin
  handleExceptionBegin
  Result := TRunFileDialogCallbackRef.Create;
  handleExceptionEnd
end;

procedure RunFileDialogCallback_OnFileDialogDismissed(const AObj: TRunFileDialogCallbackRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.FileDialogDismissedPtr := AEventData;
  handleExceptionEnd
end;

exports
  RunFileDialogCallbackRef_Create,
  RunFileDialogCallback_OnFileDialogDismissed
;
