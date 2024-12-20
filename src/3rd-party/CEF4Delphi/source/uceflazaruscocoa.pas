unit uCEFLazarusCocoa;


{$mode objfpc}{$H+}
{$I cef.inc}

{$IFDEF DARWIN}  // $IFDEF MACOSX
{$ModeSwitch objectivec2}
{$ENDIF}

interface

uses
{$IFDEF DARWIN}  // $IFDEF MACOSX
  CocoaAll, CocoaInt, Cocoa_Extra,
{$ENDIF}
  Classes, SysUtils, ctypes;

{$IFDEF DARWIN}  // $IFDEF MACOSX
type
  CrAppProtocol = objcprotocol
    function isHandlingSendEvent: LCLObjCBoolean; message 'isHandlingSendEvent';
  end;

  CrAppControlProtocol = objcprotocol(CrAppProtocol)
    procedure setHandlingSendEvent(handlingSendEvent: LCLObjCBoolean); message 'setHandlingSendEvent:';
  end;

  TCrCocoaApplication = objcclass(TCocoaApplication, CrAppControlProtocol)
   public
    function isHandlingSendEvent: LCLObjCBoolean;
    procedure setHandlingSendEvent(handlingSendEvent: LCLObjCBoolean);
    procedure sendEvent(theEvent: NSEvent); override;

    procedure terminate(sender: id); override;
   private
    fHandlingSendEvent: LCLObjCBoolean;
  end;

  procedure AddCrDelegate;

var   LastMacOsKeyDownCode: cushort;
{$ENDIF}

implementation

//
// Unit Author: Jonas Maebe
//

{$IFDEF DARWIN}  // $IFDEF MACOSX
uses
  Forms;

type
  TChromeAppDelegateIntercept = objcclass(NSProxy)
    procedure tryToTerminateApplication(app: NSApplication); message 'tryToTerminateApplication:';
    function initWithDelegate(delegate: id): id; message 'initWithDelegate:';
    procedure dealloc; override;
    function respondsToSelector(aSelector: SEL): LCLObjCBoolean; override;
    procedure forwardInvocation (invocation: NSInvocation); override;
    function methodSignatureForSelector (sel_: SEL): NSMethodSignature; override;

   private
    fLCLDelegate: id;
  end;

procedure TChromeAppDelegateIntercept.tryToTerminateApplication(app: NSApplication);
  begin
    Application.MainForm.Close;
  end;


function TChromeAppDelegateIntercept.initWithDelegate(delegate: id): id;
  begin
    fLCLDelegate:=delegate;
    fLCLDelegate.retain;
    result:=self;
  end;


procedure TChromeAppDelegateIntercept.dealloc;
begin
  fLCLDelegate.release;
  fLCLDelegate:=nil;
  inherited dealloc;
end;


function TChromeAppDelegateIntercept.respondsToSelector(aSelector: SEL): LCLObjCBoolean;
begin
  if aSelector = objcselector('tryToTerminateApplication:') then
    result:=true
  else if assigned(fLCLDelegate) then
    result:=fLCLDelegate.respondsToSelector(aSelector)
  else
    result:=false;
end;


procedure TChromeAppDelegateIntercept.forwardInvocation(invocation: NSInvocation);
begin
  { this only gets called in case we can't handle the invocation }
  if assigned(fLCLDelegate) then
    begin
      invocation.setTarget(fLCLDelegate);
      invocation.invoke;
    end;
end;


function TChromeAppDelegateIntercept.methodSignatureForSelector(sel_: SEL): NSMethodSignature;
begin
  { if the original delegate can handle it, send it there. Otherwise we try to handle it }
  if assigned(fLCLDelegate) then
    result:=fLCLDelegate.methodSignatureForSelector(sel_);
  if not assigned(result) then
    result:=inherited;
end;


procedure AddCrDelegate;
var
  delegate: id;
begin
  // CEF要求在创建NSApp之前，必须先实例化 TCrCocoaApplication
  // 否则CEF获取不到 isHandlingSendEvent
  TCrCocoaApplication.sharedApplication;
  delegate := TChromeAppDelegateIntercept.alloc.initWithDelegate(NSApp.delegate);
  NSApp.setDelegate(delegate);
end;


function TCrCocoaApplication.isHandlingSendEvent: LCLObjCBoolean;
begin
  result:=fHandlingSendEvent;
end;

procedure TCrCocoaApplication.setHandlingSendEvent(handlingSendEvent: LCLObjCBoolean);
begin
  fHandlingSendEvent:=handlingSendEvent;
end;

procedure TCrCocoaApplication.sendEvent(theEvent: NSEvent);
var
  CurrentHandling: LCLObjCBoolean;
begin
  CurrentHandling:=isHandlingSendEvent;
  setHandlingSendEvent(true);
  if (theEvent.type_ = NSKeyDown)
  then begin
    LastMacOsKeyDownCode := theEvent.keyCode;
    end;
  inherited;
  LastMacOsKeyDownCode:=0;
  setHandlingSendEvent(CurrentHandling);
end;

procedure TCrCocoaApplication.terminate(sender: id);
var
  AppDelegate: TChromeAppDelegateIntercept;
begin
  AppDelegate:=TChromeAppDelegateIntercept(NSApp.delegate);
  AppDelegate.tryToTerminateApplication(CocoaWidgetSet.NSApp);
end;

{$ENDIF}

end.

