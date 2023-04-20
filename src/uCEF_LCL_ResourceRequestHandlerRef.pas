//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ResourceRequestHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFResourceRequestHandler,
  uCEF_LCL_Entity, uCEF_LCL_EventCallback;

type

  TResourceRequestHandlerRef = class(TCefResourceRequestHandlerOwn)
  public
    GetCookieAccessFilterPtr: Pointer;
    BeforeResourceLoadPtr: Pointer;
    GetResourceHandlerPtr: Pointer;
    ResourceRedirectPtr: Pointer;
    ResourceResponsePtr: Pointer;
    ResourceResponseFilterPtr: Pointer;
    ResourceLoadCompletePtr: Pointer;
    ProtocolExecutionPtr: Pointer;
    constructor Create; override;
    destructor Destroy;
  protected
    procedure GetCookieAccessFilter(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aFilter: ICefCookieAccessFilter); override;
    function OnBeforeResourceLoad(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefCallback): TCefReturnValue; override;
    procedure GetResourceHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aResourceHandler: ICefResourceHandler); override;
    procedure OnResourceRedirect(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var newUrl: ustring); override;
    function OnResourceResponse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse): boolean; override;
    procedure GetResourceResponseFilter(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var aResponseFilter: ICefResponseFilter); override;
    procedure OnResourceLoadComplete(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; status: TCefUrlRequestStatus; receivedContentLength: int64); override;
    procedure OnProtocolExecution(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var allowOsExecution: boolean); override;
    procedure RemoveReferences; override;

  end;

implementation


procedure TResourceRequestHandlerRef.GetCookieAccessFilter(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aFilter: ICefCookieAccessFilter);
begin
  if (GetCookieAccessFilterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetCookieAccessFilterPtr, [browser, frame, request, @aFilter]);
  end;
end;

function TResourceRequestHandlerRef.OnBeforeResourceLoad(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefCallback): TCefReturnValue;
begin
  if (BeforeResourceLoadPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeResourceLoadPtr, [browser, frame, request, callback]);
  end;
end;

procedure TResourceRequestHandlerRef.GetResourceHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aResourceHandler: ICefResourceHandler);
begin
  if (GetResourceHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetResourceHandlerPtr, [browser, frame, request, aResourceHandler]);
  end;
end;

procedure TResourceRequestHandlerRef.OnResourceRedirect(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var newUrl: ustring);
var
  RetNewURL: PChar;
begin
  if (ResourceRedirectPtr <> nil) then
  begin
    RetNewURL := new(PChar);
    TCEFEventCallback.SendEvent(ResourceRedirectPtr, [browser, frame, request, response, @RetNewURL]);
    newUrl := PCharToUStr(RetNewURL);
    RetNewURL := nil;
  end;
end;

function TResourceRequestHandlerRef.OnResourceResponse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse): boolean;
begin
  if (ResourceResponsePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResourceResponsePtr, [browser, frame, request, response]);
  end;
end;

procedure TResourceRequestHandlerRef.GetResourceResponseFilter(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var aResponseFilter: ICefResponseFilter);
begin
  if (ResourceResponseFilterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResourceResponseFilterPtr, [browser, frame, request, response, @aResponseFilter]);
  end;
end;

procedure TResourceRequestHandlerRef.OnResourceLoadComplete(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; status: TCefUrlRequestStatus; receivedContentLength: int64);
begin
  if (ResourceLoadCompletePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResourceLoadCompletePtr, [browser, frame, request, response, Integer(status), @receivedContentLength]);
  end;
end;

procedure TResourceRequestHandlerRef.OnProtocolExecution(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var allowOsExecution: boolean);
begin
  if (ProtocolExecutionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ProtocolExecutionPtr, [browser, frame, request, @allowOsExecution]);
  end;
end;

procedure TResourceRequestHandlerRef.RemoveReferences;
begin
  GetCookieAccessFilterPtr := nil;
  BeforeResourceLoadPtr := nil;
  GetResourceHandlerPtr := nil;
  ResourceRedirectPtr := nil;
  ResourceResponsePtr := nil;
  ResourceResponseFilterPtr := nil;
  ResourceLoadCompletePtr := nil;
  ProtocolExecutionPtr := nil;
  inherited RemoveReferences;
end;

constructor TResourceRequestHandlerRef.Create;
begin
  inherited Create;
end;

destructor TResourceRequestHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

end.
