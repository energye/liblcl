unit Interfaces;

{$mode objfpc}
{$H+}

interface

uses
  {$IFDEF Windows}{$IFnDEF DisableUTF8RTL}LazUTF8,{$ENDIF}{$ENDIF}
  {$IFDEF UNIX}{$IFNDEF DisableCWString}cwstring,{$ENDIF}{$ENDIF}
  InterfaceBase;

procedure CustomWidgetSetInitialization;
procedure CustomWidgetSetFinalization;

implementation

uses
  {$IFDEF Windows}Win32Int,{$ENDIF}
  {$IFDEF Linux}gtk3int, xlib, uCEFLinuxFunctions,{$ENDIF}
  {$IFDEF DARWIN}CocoaInt,{$ENDIF}
  Forms;

{$IFDEF Linux}
function CustomX11ErrorHandler(Display: PDisplay; ErrorEv: PXErrorEvent): longint; cdecl;
begin
  {$IFDEF DEBUG}
  XError := ErrorEv^.error_code;
  WriteLn('Error: ' + IntToStr(XError));
  {$ENDIF}
  Result := 0;
end;

function CustomXIOErrorHandler(Display: PDisplay): longint; cdecl;
begin
  Result := 0;
end;
{$ENDIF}

procedure CustomWidgetSetInitialization;
begin
  {$IFDEF Windows}
  CreateWidgetset(TWin32WidgetSet);
  {$ENDIF}

  {$IFDEF Linux}
  //gdk_set_allowed_backends('X11');
  CreateWidgetset(TGtk3WidgetSet);
  // Install xlib error handlers so that the application won't be terminated
  // on non-fatal errors. Must be done after initializing GTK.
  XSetErrorHandler(@CustomX11ErrorHandler);
  XSetIOErrorHandler(@CustomXIOErrorHandler);
  {$ENDIF}

  {$IFDEF DARWIN}
  CreateWidgetset(TCocoaWidgetSet);
  {$ENDIF}
end;

procedure CustomWidgetSetFinalization;
begin
  FreeWidgetSet;
end;

{$IFnDEF Linux}
initialization
  begin
    CustomWidgetSetInitialization;
  end;

finalization
  begin
    CustomWidgetSetFinalization;
  end;
{$ENDIF}

end.
