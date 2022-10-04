//----------------------------------------
//
// Copyright © ying32. All Rights Reserved.
// 
// Licensed under Lazarus.modifiedLGPL
//
//----------------------------------------

unit uMacOSPatchs;

{$mode objfpc}{$H+}
{$modeswitch objectivec1}
{$modeswitch objectivec2}
{$interfaces corba}
//{$include cocoadefines.inc}
{$packrecords c}
{$I ExtDecl.inc}

interface

uses
  Classes, SysUtils, Dialogs, Forms, CocoaAll, CocoaWindows;


type
  NSWindowTitleVisibility = (NSWindowTitleVisible, NSWindowTitleHidden);

  MyNSWindow = objcclass external (NSWIndow)
  public
    function titleVisibility: NSWindowTitleVisibility; message 'titleVisibility';
    procedure setTitleVisibility(flag: NSWindowTitleVisibility); message 'setTitleVisibility:';
    function titlebarAppearsTransparent: Boolean; message 'titlebarAppearsTransparent';
    procedure setTitlebarAppearsTransparent(flag: Boolean); message 'setTitlebarAppearsTransparent:';
    //procedure _release; message 'release';
    //procedure _retain; message 'retain';
  end;

const
  NSWindowStyleMaskFullSizeContentView = 1 shl 15;




//procedure SetMacOSWindowProp(AForm: TForm);

function NSWindow_FromForm(AForm: TForm): MyNSWindow; extdecl;
function NSWindow_titleVisibility(AObj: MyNSWindow): NSWindowTitleVisibility; extdecl;
procedure NSWindow_setTitleVisibility(AObj: MyNSWindow; AVal: NSWindowTitleVisibility); extdecl;
function NSWindow_titlebarAppearsTransparent(AObj: MyNSWindow): Boolean; extdecl;
procedure NSWindow_setTitlebarAppearsTransparent(AObj: MyNSWindow; AVal: Boolean); extdecl;
function NSWindow_styleMask(AObj: MyNSWindow): NSInteger; extdecl;
procedure NSWindow_setStyleMask(AObj: MyNSWindow; AVal: NSInteger); extdecl;
procedure NSWindow_setRepresentedURL(AObj: MyNSWindow; AVal: NSURL); extdecl;
procedure NSWindow_release(AObj: MyNSWindow); extdecl;

implementation

{$ifdef UsehandleException}
uses
   uExceptionHandle;
{$endif}

function NSWindow_FromForm(AForm: TForm): MyNSWindow; extdecl;
var
  LWinContent: TCocoaWindowContent = nil;
begin
  Result := nil;
  handleExceptionBegin
  if AForm = nil then
    Exit;
  LWinContent := TCocoaWindowContent(AForm.Handle);
  if Assigned(LWinContent.fswin) then
    Result :=  MyNSWindow(LWinContent.fswin)
  else
    Result := MyNSWindow(LWinContent.window);
  //if Assigned(Result) then
  //  Result._retain;   // +1
  handleExceptionEnd
end;

function NSWindow_titleVisibility(AObj: MyNSWindow): NSWindowTitleVisibility; extdecl;
begin
  handleExceptionBegin
  Result := AObj.titleVisibility();
  handleExceptionEnd
end;

procedure NSWindow_setTitleVisibility(AObj: MyNSWindow; AVal: NSWindowTitleVisibility); extdecl;
begin
  handleExceptionBegin
  AObj.setTitleVisibility(AVal);
  handleExceptionEnd
end;

function NSWindow_titlebarAppearsTransparent(AObj: MyNSWindow): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := AObj.titlebarAppearsTransparent();
  handleExceptionEnd
end;

procedure NSWindow_setTitlebarAppearsTransparent(AObj: MyNSWindow; AVal: Boolean); extdecl;
begin
  handleExceptionBegin
  AObj.SetTitlebarAppearsTransparent(AVal);
  handleExceptionEnd
end;

function NSWindow_styleMask(AObj: MyNSWindow): NSInteger; extdecl;
begin
  handleExceptionBegin
  Result := AObj.styleMask();
  handleExceptionEnd
end;

procedure NSWindow_setStyleMask(AObj: MyNSWindow; AVal: NSInteger); extdecl;
begin
  handleExceptionBegin
  AObj.setStyleMask(AVal);
  handleExceptionEnd
end;

procedure NSWindow_setRepresentedURL(AObj: MyNSWindow; AVal: NSURL); extdecl;
begin
  handleExceptionBegin
  AObj.setRepresentedURL(AVal);
  handleExceptionEnd
end;

procedure NSWindow_release(AObj: MyNSWindow); extdecl;
begin
  //AObj._release;
end;

//procedure SetMacOSWindowProp(AForm: TForm);
//var
//  LWinContent: TCocoaWindowContent = nil;
//  Lwin: MyNSWindow = nil;
//begin
//  if AForm = nil then
//    Exit;
//  LWinContent := TCocoaWindowContent(AForm.Handle);
//  if Assigned(LWinContent.fswin) then
//    Lwin :=  MyNSWindow(LWinContent.fswin)
//  else
//    Lwin := MyNSWindow(LWinContent.window);
//  if Assigned(Lwin) then
//  begin
//    Lwin.setTitleVisibility(NSWindowTitleHidden);
//    Lwin.SetTitlebarAppearsTransparent(True);
//    Lwin.setStyleMask(Lwin.styleMask or NSWindowStyleMaskFullSizeContentView);
//    Lwin.setRepresentedURL(nil);
//  end;
//end;


//exports
////{$IFDEF LCLCocoa}
//  NSWindow_FromForm,
//  NSWindow_titleVisibility,
//  NSWindow_setTitleVisibility,
//  NSWindow_titlebarAppearsTransparent,
//  NSWindow_setTitlebarAppearsTransparent,
//  NSWindow_styleMask,
//  NSWindow_setStyleMask,
//  NSWindow_setRepresentedURL,
//  NSWindow_release;
////{$ENDIF}

end.

