//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure RunFileDialogCallbackRef_Create(var Result: ICefRunFileDialogCallback); extdecl;
begin
  handleExceptionBegin
  Result := TRunFileDialogCallbackRef.Create;
  handleExceptionEnd
end;

procedure RunFileDialogCallback_OnFileDialogDismissed(const AObj: ICefRunFileDialogCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRunFileDialogCallbackRef).FileDialogDismissedPtr := AEventData;
  handleExceptionEnd
end;

exports
  RunFileDialogCallbackRef_Create,
  RunFileDialogCallback_OnFileDialogDismissed
;
