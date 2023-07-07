//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure FileDialogCallback_Cont(const TObj: ICefFileDialogCallback; const filePaths: TStrings); extdecl;
begin
  handleExceptionBegin
  // TCefEventFlags
  TObj.Cont(filePaths.Count, filePaths);
  handleExceptionEnd
end;

procedure FileDialogCallback_Cancel(const TObj: ICefFileDialogCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cancel;
  handleExceptionEnd
end;

exports
  FileDialogCallback_Cont,
  FileDialogCallback_Cancel;