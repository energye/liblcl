//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_RequestContextRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFRequestContextHandler,
  uCEF_LCL_EventCallback;

type

  TRequestContextHandlerRef = class(TCefRequestContextHandlerOwn)
  public
    RequestContextInitializedPtr: Pointer;
    GetResourceRequestHandlerPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnRequestContextInitialized(const request_context: ICefRequestContext); override;
    procedure GetResourceRequestHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aResourceRequestHandler: ICefResourceRequestHandler); override;

    procedure RemoveReferences; override;

  end;

implementation

procedure TRequestContextHandlerRef.OnRequestContextInitialized(const request_context: ICefRequestContext);
begin
  if (RequestContextInitializedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RequestContextInitializedPtr, [request_context]);
  end
  else
    inherited OnRequestContextInitialized(request_context);
end;

procedure TRequestContextHandlerRef.GetResourceRequestHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aResourceRequestHandler: ICefResourceRequestHandler);
begin
  if (GetResourceRequestHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetResourceRequestHandlerPtr, [browser, frame, request, is_navigation, is_download, PChar(string(request_initiator)), @disable_default_handling, @aResourceRequestHandler]);
  end
  else
    inherited GetResourceRequestHandler(browser, frame, request, is_navigation, is_download, request_initiator, disable_default_handling, aResourceRequestHandler);
end;

procedure TRequestContextHandlerRef.RemoveReferences;
begin
  RequestContextInitializedPtr := nil;
  GetResourceRequestHandlerPtr := nil;
  inherited RemoveReferences;
end;

constructor TRequestContextHandlerRef.Create;
begin
  inherited Create;
end;

destructor TRequestContextHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

end.
