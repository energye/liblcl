//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefMediaAccessCallback_Cont(const AObj: ICefMediaAccessCallback; allowed_permissions: TCefMediaAccessPermissionTypes); extdecl;
begin
  handleExceptionBegin
  AObj.cont(allowed_permissions);
  handleExceptionEnd
end;

procedure CefMediaAccessCallback_Cancel(const AObj: ICefMediaAccessCallback); extdecl;
begin
  handleExceptionBegin
  AObj.cancel;
  handleExceptionEnd
end;

exports
    CefMediaAccessCallback_Cont,
    CefMediaAccessCallback_Cancel
;
