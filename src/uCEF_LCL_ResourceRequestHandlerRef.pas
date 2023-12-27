//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ResourceRequestHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFMiscFunctions,
  uCEFTypes, uCEFInterfaces, uCEFResourceHandler,
  uCEF_LCL_Entity, uCEF_LCL_EventCallback;

type

  {== ResourceRequestHandler ==}
  TResourceRequestHandlerRef = class
  public
    GetCookieAccessFilterPtr: Pointer;
    BeforeResourceLoadPtr: Pointer;
    GetResourceHandlerPtr: Pointer;
    ResourceRedirectPtr: Pointer;
    ResourceResponsePtr: Pointer;
    GetResourceResponseFilterPtr: Pointer;
    ResourceLoadCompletePtr: Pointer;
    ProtocolExecutionPtr: Pointer;
    constructor Create;
    destructor Destroy;
  end;

  {== CookieAccessFilter ==}
  TCookieAccessFilterRef = class
  public
    CanSendCookiePtr: Pointer;
    CanSaveCookiePtr: Pointer;
    constructor Create;
    destructor Destroy;
  end;

  {== ResourceHandler ==}
  TResourceHandlerRef = class(TCefResourceHandlerOwn)
  public
    OpenPtr: Pointer;
    GetResponseHeadersPtr: Pointer;
    skipPtr: Pointer;
    ReadPtr: Pointer;
    ProcessRequestPtr: Pointer;
    ReadResponsePtr: Pointer;
    CancelPtr: Pointer;
    constructor Create(const browser: ICefBrowser; const frame: ICefFrame; const schemeName: ustring; const request: ICefRequest); override;
    destructor Destroy; override;
  protected
    procedure GetResponseHeaders(const response: ICefResponse; out responseLength: int64; out redirectUrl: ustring); override;
    function ProcessRequest(const request: ICefRequest; const callback: ICefCallback): boolean; override; // deprecated
    function ReadResponse(const dataOut: Pointer; bytesToRead: integer; var bytesRead: integer; const callback: ICefCallback): boolean; override; // deprecated
    procedure Cancel; override;
  end;

implementation

{== ResourceRequestHandler ==}
constructor TResourceRequestHandlerRef.Create;
begin
end;

destructor TResourceRequestHandlerRef.Destroy;
begin
end;

{== CookieAccessFilter ==}
constructor TCookieAccessFilterRef.Create;
begin
end;

destructor TCookieAccessFilterRef.Destroy;
begin
end;

{== ResourceHandler ==}
procedure TResourceHandlerRef.GetResponseHeaders(const response: ICefResponse; out responseLength: int64; out redirectUrl: ustring);
var
  RetRedirectUrl: PChar;
begin
  if (GetResponseHeadersPtr <> nil) then
  begin
    RetRedirectUrl := new(PChar);
    TCEFEventCallback.SendEvent(GetResponseHeadersPtr, [response, @responseLength, @RetRedirectUrl]);
    if RetRedirectUrl <> nil then
      redirectUrl := PCharToUStr(RetRedirectUrl);
    RetRedirectUrl := nil;
  end
  else
    inherited GetResponseHeaders(response, responseLength, redirectUrl);
end;

function TResourceHandlerRef.ProcessRequest(const request: ICefRequest; const callback: ICefCallback): boolean; // deprecated
begin
  Result := False;
  if (ProcessRequestPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ProcessRequestPtr, [request, callback, @Result]);
  end
  else
    Result := inherited ProcessRequest(request, callback);
end;

function TResourceHandlerRef.ReadResponse(const dataOut: Pointer; bytesToRead: integer; var bytesRead: integer; const callback: ICefCallback): boolean; // deprecated
begin
  Result := False;
  if (ReadResponsePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ReadResponsePtr, [dataOut, bytesToRead, @bytesRead, callback, @Result]);
  end
  else
    Result := inherited ReadResponse(dataOut, bytesToRead, bytesRead, callback);
end;

procedure TResourceHandlerRef.Cancel;
begin
  if (CancelPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CancelPtr, []);
  end
  else
    inherited Cancel();
end;

constructor TResourceHandlerRef.Create(const browser: ICefBrowser; const frame: ICefFrame; const schemeName: ustring; const request: ICefRequest);
begin
  inherited Create(browser, frame, schemeName, request);
end;

destructor TResourceHandlerRef.Destroy;
begin
  OpenPtr := nil;
  GetResponseHeadersPtr := nil;
  skipPtr := nil;
  ReadPtr := nil;
  CancelPtr := nil;
  inherited Destroy;
end;

end.
