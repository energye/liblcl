//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MediaObserverRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFInterfaces, uCEFMediaObserver, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TMediaObserverRef = class(TCefMediaObserverOwn)
  public
    OnSinksPtr: Pointer;
    OnRoutesPtr: Pointer;
    OnRouteStateChangedPtr: Pointer;
    OnRouteMessageReceivedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnSinks(const sinks: TCefMediaSinkArray); override;
    procedure OnRoutes(const routes: TCefMediaRouteArray); override;
    procedure OnRouteStateChanged(const route: ICefMediaRoute; state: TCefMediaRouteConnectionState); override;
    procedure OnRouteMessageReceived(const route: ICefMediaRoute; const message_: ustring); override;
  end;

implementation

procedure TMediaObserverRef.OnSinks(const sinks: TCefMediaSinkArray);
begin
  if (OnSinksPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnSinksPtr, [@sinks, length(sinks)]);
  end;
end;
procedure TMediaObserverRef.OnRoutes(const routes: TCefMediaRouteArray);
begin
  if (OnRoutesPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnRoutesPtr, [@routes, length(routes)]);
  end;
end;
procedure TMediaObserverRef.OnRouteStateChanged(const route: ICefMediaRoute; state: TCefMediaRouteConnectionState);
begin
  if (OnRouteStateChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnRouteStateChangedPtr, [route, state]);
  end;
end;
procedure TMediaObserverRef.OnRouteMessageReceived(const route: ICefMediaRoute; const message_: ustring);
begin
  if (OnRouteMessageReceivedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnRouteMessageReceivedPtr, [route, PChar(message_)]);
  end;
end;

constructor TMediaObserverRef.Create;
begin
  inherited Create;
  OnSinksPtr := nil;
  OnRoutesPtr := nil;
  OnRouteStateChangedPtr := nil;
  OnRouteMessageReceivedPtr := nil;
end;

destructor TMediaObserverRef.Destroy;
begin
  OnSinksPtr := nil;
  OnRoutesPtr := nil;
  OnRouteStateChangedPtr := nil;
  OnRouteMessageReceivedPtr := nil;
  inherited Destroy;
end;

end.
