//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure Interface_CustomWidgetSetInitialization(); extdecl;
begin
  {$IFDEF Linux}
  //CustomWidgetSetInitialization();
  {$ENDIF}
end;

procedure Interface_CustomWidgetSetFinalization(); extdecl;
begin
  {$IFDEF Linux}
  //CustomWidgetSetFinalization();
  {$ENDIF}
end;

exports
  Interface_CustomWidgetSetInitialization,
  Interface_CustomWidgetSetFinalization;