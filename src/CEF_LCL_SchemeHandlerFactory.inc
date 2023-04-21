//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure SchemeHandlerFactoryRef_Create(const AClass: TCefResourceHandlerClass; var Result: ICefSchemeHandlerFactory); extdecl;
begin
  handleExceptionBegin
  if AClass <> nil then
  begin
       Result := TSchemeHandlerFactoryRef.Create(AClass);
  end
  else
  begin
       Result := TSchemeHandlerFactoryRef.Create(TResourceHandlerRef);
  end;
  handleExceptionEnd
end;

procedure SchemeHandlerFactory_New(const AObj: TSchemeHandlerFactoryRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.NewPtr := AEventData;
  handleExceptionEnd
end;

exports
  SchemeHandlerFactoryRef_Create,
  SchemeHandlerFactory_New
;
