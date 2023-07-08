//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefMediaAccessCallback_Cont(const AObj: Pointer; allowed_permissions: Integer); extdecl;
begin
end;

procedure CefMediaAccessCallback_Cancel(const AObj: Pointer); extdecl;
begin
end;

exports
  CefMediaAccessCallback_Cont,
  CefMediaAccessCallback_Cancel;
