//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CustomUserData_Create(AUserDataType, AUserData: Pointer; out Result: ICefCustomUserData); extdecl;
begin
  handleExceptionBegin
  Result := TCefCustomUserData.Create(AUserDataType, AUserData);
  handleExceptionEnd
end;

function CustomUserData_UserDataType(const TObj: ICefCustomUserData): Pointer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.UserDataType;
  handleExceptionEnd
end;

function CustomUserData_UserData(const TObj: ICefCustomUserData): Pointer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.UserData;
  handleExceptionEnd
end;


exports
  CustomUserData_Create,
  CustomUserData_UserDataType,
  CustomUserData_UserData;
