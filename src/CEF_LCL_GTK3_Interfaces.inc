//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure GTK3_CustomWidgetSetInitialization(); extdecl;
begin
  {$IFDEF Linux}
  //CustomWidgetSetInitialization();
  {$ENDIF}
end;

procedure GTK3_CustomWidgetSetFinalization(); extdecl;
begin
  {$IFDEF Linux}
  //CustomWidgetSetFinalization();
  {$ENDIF}
end;

exports
  GTK3_CustomWidgetSetInitialization,
  GTK3_CustomWidgetSetFinalization
;
