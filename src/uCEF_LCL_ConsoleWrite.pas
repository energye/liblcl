//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ConsoleWrite;

{$mode objfpc}{$H+}
{$I cef.inc}
{$APPTYPE CONSOLE}

interface

procedure ConsoleLn(msg: UnicodeString);

implementation

procedure ConsoleLn(msg: UnicodeString);
begin
  //WriteLn('==[CEF-LCL-Log] == [', msg,']');
end;

end.
