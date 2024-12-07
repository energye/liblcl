//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MediaRouteCreateCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFInterfaces, uCEFMediaRouteCreateCallback, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TMediaRouteCreateCallbackRef = class(TCefMediaRouteCreateCallbackOwn)
  public
    OnMediaRouteCreateFinishedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
      procedure OnMediaRouteCreateFinished(result: TCefMediaRouterCreateResult; const error: ustring; const route: ICefMediaRoute); override;
  end;

implementation

procedure TMediaRouteCreateCallbackRef.OnMediaRouteCreateFinished(result: TCefMediaRouterCreateResult; const error: ustring; const route: ICefMediaRoute);
begin
  if (OnMediaRouteCreateFinishedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnMediaRouteCreateFinishedPtr, [result, PChar(error), route]);
  end;
end;

constructor TMediaRouteCreateCallbackRef.Create;
begin
  inherited Create;
  OnMediaRouteCreateFinishedPtr := nil;
end;

destructor TMediaRouteCreateCallbackRef.Destroy;
begin
  OnMediaRouteCreateFinishedPtr := nil;
  inherited Destroy;
end;

end.
