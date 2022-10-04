//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------
unit uCEF_LCL_GTK2_Interfaces;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

{$IFDEF UNIX}{$IFNDEF DisableCWString}uses cwstring;{$ENDIF}{$ENDIF}

procedure CustomWidgetSetInitialization;
procedure CustomWidgetSetFinalization;

implementation

uses
 uCEF_LCL_ConsoleWrite,
 {$IFNDEF EnableLibOverlay}
  gtk2DisableLibOverlay,
 {$ENDIF}
  Gtk2Int, Forms, xlib;

function CustomX11ErrorHandler(Display: PDisplay; ErrorEv: PXErrorEvent): longint; extdecl;
begin
  {$IFDEF DEBUG}
  XError := ErrorEv^.error_code;
  WriteLn('Error: ' + IntToStr(XError));
  {$ENDIF}
  Result := 0;
end;

function CustomXIOErrorHandler(Display: PDisplay): longint; extdecl;
begin
  Result := 0;
end;

procedure CustomWidgetSetInitialization;
begin
  ConsoleLn('CustomWidgetSetInitialization');
  CreateWidgetset(TGtk2WidgetSet);
  // Install xlib error handlers so that the application won't be terminated
  // on non-fatal errors. Must be done after initializing GTK.
  XSetErrorHandler(@CustomX11ErrorHandler);
  XSetIOErrorHandler(@CustomXIOErrorHandler);
end;

procedure CustomWidgetSetFinalization;
begin
  FreeWidgetSet;
end;

end.
