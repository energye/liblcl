//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefGetExtensionResourceCallback_Cont(const AObj: ICefGetExtensionResourceCallback; const stream: ICefStreamReader); extdecl;
begin
  handleExceptionBegin
  AObj.cont(stream);
  handleExceptionEnd
end;

procedure CefGetExtensionResourceCallback_Cancel(const AObj: ICefGetExtensionResourceCallback); extdecl;
begin
  handleExceptionBegin
  AObj.cancel;
  handleExceptionEnd
end;

exports
    CefGetExtensionResourceCallback_Cont,
    CefGetExtensionResourceCallback_Cancel
;
