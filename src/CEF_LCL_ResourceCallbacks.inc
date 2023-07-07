//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure ResourceSkipCallback_Cont(const callback: ICefResourceSkipCallback; var bytes_skipped: int64); extdecl;
begin
  handleExceptionBegin
  callback.Cont(bytes_skipped);
  handleExceptionEnd
end;

procedure ResourceReadCallback_Cont(const callback: ICefResourceReadCallback; var bytes_read: int64); extdecl;
begin
  handleExceptionBegin
  callback.Cont(bytes_read);
  handleExceptionEnd
end;


exports
  ResourceSkipCallback_Cont,
  ResourceReadCallback_Cont;