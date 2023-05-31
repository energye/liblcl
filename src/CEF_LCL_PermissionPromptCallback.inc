//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPermissionPromptCallback_Cont(const AObj: ICefPermissionPromptCallback; result: TCefPermissionRequestResult); extdecl;
begin
  handleExceptionBegin
  AObj.cont(result);
  handleExceptionEnd
end;

exports
    CefPermissionPromptCallback_Cont
;
