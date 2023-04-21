//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ResourceRequestHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces, uCEFResourceRequestHandler, uCEFCookieAccessFilter,
  uCEF_LCL_Entity, uCEF_LCL_EventCallback;

type

  {== ResourceRequestHandler ==}
  TResourceRequestHandlerRef = class(TCefResourceRequestHandlerOwn)
  public
    GetCookieAccessFilterPtr: Pointer;
    BeforeResourceLoadPtr: Pointer;
    GetResourceHandlerPtr: Pointer;
    ResourceRedirectPtr: Pointer;
    ResourceResponsePtr: Pointer;
    GetResourceResponseFilterPtr: Pointer;
    ResourceLoadCompletePtr: Pointer;
    ProtocolExecutionPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
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

  {== CookieAccessFilter ==}
  TCookieAccessFilterRef = class(TCefCookieAccessFilterOwn)
  public
    CanSendCookiePtr: Pointer;
    CanSaveCookiePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function CanSendCookie(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const cookie: PCefCookie): boolean; override;
    function CanSaveCookie(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; const cookie: PCefCookie): boolean; override;
    procedure RemoveReferences; override;
  end;

implementation

{== ResourceRequestHandler ==}
procedure TResourceRequestHandlerRef.GetCookieAccessFilter(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aFilter: ICefCookieAccessFilter);
begin
  if (GetCookieAccessFilterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetCookieAccessFilterPtr, [browser, frame, request, @aFilter]);
  end;
end;

function TResourceRequestHandlerRef.OnBeforeResourceLoad(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const callback: ICefCallback): TCefReturnValue;
begin
  Result := RV_CONTINUE;
  if (BeforeResourceLoadPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeResourceLoadPtr, [browser, frame, request, callback, @Result]);
  end;
end;

procedure TResourceRequestHandlerRef.GetResourceHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; var aResourceHandler: ICefResourceHandler);
begin
  if (GetResourceHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetResourceHandlerPtr, [browser, frame, request, @aResourceHandler]);
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
    if RetNewURL <> nil then
      newUrl := PCharToUStr(RetNewURL);
    RetNewURL := nil;
  end;
end;

function TResourceRequestHandlerRef.OnResourceResponse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse): boolean;
begin
  Result := False;
  if (ResourceResponsePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResourceResponsePtr, [browser, frame, request, response, @Result]);
  end;
end;

procedure TResourceRequestHandlerRef.GetResourceResponseFilter(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; var aResponseFilter: ICefResponseFilter);
begin
  if (GetResourceResponseFilterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetResourceResponseFilterPtr, [browser, frame, request, response, @aResponseFilter]);
  end;
end;

procedure TResourceRequestHandlerRef.OnResourceLoadComplete(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; status: TCefUrlRequestStatus; receivedContentLength: int64);
begin
  if (ResourceLoadCompletePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResourceLoadCompletePtr, [browser, frame, request, response, integer(status), @receivedContentLength]);
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
  GetResourceResponseFilterPtr := nil;
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

{== CookieAccessFilter ==}
function TCookieAccessFilterRef.CanSendCookie(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const cookie: PCefCookie): boolean;
begin
  Result := False;
  if (CanSendCookiePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanSendCookiePtr, [browser, frame, request, cookie, @Result]);
  end;
end;

function TCookieAccessFilterRef.CanSaveCookie(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; const response: ICefResponse; const cookie: PCefCookie): boolean;
begin
  Result := False;
  if (CanSaveCookiePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanSaveCookiePtr, [browser, frame, request, response, cookie, @Result]);
  end;
end;

procedure TCookieAccessFilterRef.RemoveReferences;
begin
  CanSendCookiePtr := nil;
  CanSaveCookiePtr := nil;
  inherited RemoveReferences;
end;

constructor TCookieAccessFilterRef.Create;
begin
  inherited Create;
end;

destructor TCookieAccessFilterRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

end.
