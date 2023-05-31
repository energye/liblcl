//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== ResourceSkipCallback ==}
procedure ResourceSkipCallback_Cont(const callback: ICefResourceSkipCallback; var bytes_skipped: int64); extdecl;
begin
  handleExceptionBegin
  callback.Cont(bytes_skipped);
  handleExceptionEnd
end;

{== ResourceReadCallback ==}
procedure ResourceReadCallback_Cont(const callback: ICefResourceReadCallback; var bytes_read: int64); extdecl;
begin
  handleExceptionBegin
  callback.Cont(bytes_read);
  handleExceptionEnd
end;


exports
  {== ResourceSkipCallback ==}
  ResourceSkipCallback_Cont,
  {== ResourceReadCallback ==}
  ResourceReadCallback_Cont
;
