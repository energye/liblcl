unit Interfaces;

{$mode objfpc}{$H+}

interface

uses
  {$IFDEF Windows}{$IFnDEF DisableUTF8RTL}LazUTF8,{$ENDIF}{$ENDIF}
  {$IFDEF Unix}{$IFnDEF DisableCWString}cwstring,{$ENDIF}{$ENDIF}
  {$IFDEF LCLCocoa}CocoaWSFactory,{$ENDIF}
  InterfaceBase;

procedure CustomWidgetSetInitialization;
procedure CustomWidgetSetFinalization;

implementation

uses
  {$IFDEF LCLWIN32}Win32Int,{$ENDIF}
  {$IFDEF Linux}
    {$IFDEF LCLGTK2}
      {$IFNDEF EnableLibOverlay}
        gtk2DisableLibOverlay,
      {$ENDIF}
      Gtk2Int,
    {$ENDIF}
    {$IFDEF LCLGTK3}
      LazGtk3, gtk3int,
    {$ENDIF}
    xlib,
  {$ENDIF}
  {$IFDEF LCLCOCOA}CocoaInt,{$ENDIF}
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
  {$IFDEF LCLWIN32}
    CreateWidgetset(TWin32WidgetSet);
  {$ENDIF}

  {$IFDEF Linux}
    {$IFDEF LCLGTK2}
      //gdk_set_allowed_backends('X11');
      CreateWidgetset(TGtk2WidgetSet);
      // Install xlib error handlers so that the application won't be terminated
      // on non-fatal errors. Must be done after initializing GTK.
      XSetErrorHandler(@CustomX11ErrorHandler);
      XSetIOErrorHandler(@CustomXIOErrorHandler);
    {$ENDIF}

    {$IFDEF LCLGTK3}
      //gdk_set_allowed_backends('X11');
      gtk_disable_setlocale;
      CreateWidgetset(TGtk3WidgetSet);
      // Install xlib error handlers so that the application won't be terminated
      // on non-fatal errors. Must be done after initializing GTK.
      XSetErrorHandler(@CustomX11ErrorHandler);
      XSetIOErrorHandler(@CustomXIOErrorHandler);
    {$ENDIF}
  {$ENDIF}

  {$IFDEF LCLCOCOA}
    CreateWidgetset(TCocoaWidgetSet);
  {$ENDIF}
end;

procedure CustomWidgetSetFinalization;
begin
  FreeWidgetSet;
end;

//{$IF Defined(LCLGTK2) or Defined(LCLGTK3)}
//{$IFnDEF LCLGTK3}
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
