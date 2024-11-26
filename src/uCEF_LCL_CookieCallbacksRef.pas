//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_CookieCallbacksRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEF_LCL_Entity, uCEFInterfaces, uCEFCookieVisitor, uCEFSetCookieCallback, uCEFDeleteCookiesCallback,
  uCEF_LCL_EventCallback;

type

  {== CookieVisitor ==}
  TCookieVisitorRef = class(TCefCookieVisitorOwn)
  public
    visitPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function visit(const Name, Value, domain, path: ustring; secure, httponly, hasExpires: boolean; const creation, lastAccess, expires: TDateTime; Count, total: integer; same_site: TCefCookieSameSite; priority: TCefCookiePriority; out deleteCookie: boolean): boolean; override;
  end;

  {== SetCookieCallback ==}
  TSetCookieCallbackRef = class(TCefSetCookieCallbackOwn)
  public
    CompletePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
   procedure OnComplete(success: Boolean); override;
  end;

  {== DeleteCookiesCallback ==}
  TDeleteCookiesCallbackRef = class(TCefDeleteCookiesCallbackOwn)
  public
    CompletePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
   procedure OnComplete(numDeleted: Integer); override;
  end;



implementation

{== CookieVisitor ==}
function TCookieVisitorRef.visit(const Name, Value, domain, path: ustring;
  secure, httponly, hasExpires: boolean;
  const creation, lastAccess, expires: TDateTime;
  Count, total: integer;
  same_site: TCefCookieSameSite; priority: TCefCookiePriority; out deleteCookie: boolean): boolean;
var
  TempGoCookie: PMCefCookie;
begin
  Result := False;
  if (visitPtr <> nil) then
  begin
    TempGoCookie := InitCookie();
    TempGoCookie.name           := ToPChar(Name);
    TempGoCookie.value          := ToPChar(value);
    TempGoCookie.domain         := ToPChar(domain);
    TempGoCookie.path           := ToPChar(path);
    TempGoCookie.secure         := PBoolean(@secure);
    TempGoCookie.httponly       := PBoolean(@httponly);
    TempGoCookie.has_expires    := PBoolean(@hasExpires);
    TempGoCookie.creation       := PDouble(@creation);
    TempGoCookie.last_access    := PDouble(@lastAccess);
    TempGoCookie.expires        := PDouble(@expires);
    TempGoCookie.same_site      := PInteger(@same_site);
    TempGoCookie.priority       := PInteger(@priority);
    TempGoCookie.Count          := PInteger(@count);
    TempGoCookie.total          := PInteger(@total);

    TCEFEventCallback.SendEvent(visitPtr, [@TempGoCookie, @deleteCookie, @Result]);
  end
  else
    Result := inherited visit(Name, Value, domain, path, secure, httponly, hasExpires, creation, lastAccess, expires, Count, total, same_site, priority, deleteCookie);
end;

constructor TCookieVisitorRef.Create;
begin
  inherited Create;
end;

destructor TCookieVisitorRef.Destroy;
begin
  visitPtr := nil;
  inherited Destroy;
end;

{== SetCookieCallback ==}
procedure TSetCookieCallbackRef.OnComplete(success: Boolean);
begin
  if (CompletePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CompletePtr, [success]);
  end;
end;

constructor TSetCookieCallbackRef.Create;
begin
  inherited Create;
end;

destructor TSetCookieCallbackRef.Destroy;
begin
  CompletePtr := nil;
  inherited Destroy;
end;

{== DeleteCookiesCallback ==}
procedure TDeleteCookiesCallbackRef.OnComplete(numDeleted: Integer);
begin
  if (CompletePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CompletePtr, [numDeleted]);
  end;
end;

constructor TDeleteCookiesCallbackRef.Create;
begin
  inherited Create;
end;

destructor TDeleteCookiesCallbackRef.Destroy;
begin
  CompletePtr := nil;
  inherited Destroy;
end;


end.
