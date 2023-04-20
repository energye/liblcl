//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_CookieVisitorRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEF_LCL_Entity, uCEFInterfaces, uCEFCookieVisitor,
  uCEF_LCL_EventCallback;

type

  TCookieVisitorRef = class(TCefCookieVisitorOwn)
  public
    visitPtr: Pointer;
    constructor Create; override;
    destructor Destroy;
  protected
    function visit(const Name, Value, domain, path: ustring; secure, httponly, hasExpires: boolean; const creation, lastAccess, expires: TDateTime; Count, total: integer; same_site: TCefCookieSameSite; priority: TCefCookiePriority; out deleteCookie: boolean): boolean; override;
  end;

implementation

function TCookieVisitorRef.visit(const Name, Value, domain, path: ustring; secure, httponly, hasExpires: boolean; const creation, lastAccess, expires: TDateTime; Count, total: integer; same_site: TCefCookieSameSite; priority: TCefCookiePriority; out deleteCookie: boolean): boolean;
var
  cookie: PRCefCookie;
begin
  Result := False;
  if (visitPtr <> nil) then
  begin
    cookie := new(PRCefCookie);
    cookie^.url := PChar('');
    cookie^.Name := PChar(string(Name));
    cookie^.Value := PChar(string(Value));
    cookie^.domain := PChar(string(domain));
    cookie^.path := PChar(string(path));
    cookie^.secure := @secure;
    cookie^.httponly := @httponly;
    cookie^.hasExpires := @hasExpires;
    cookie^.creation := @creation;
    cookie^.lastAccess := @lastAccess;
    cookie^.expires := @expires;
    cookie^.Count := PInteger(count);
    cookie^.total := PInteger(total);
    cookie^.aID := PInteger(0);
    cookie^.sameSite := PInteger(integer(same_site));
    cookie^.priority := PInteger(priority);
    cookie^.setImmediately := @Result;
    cookie^.deleteCookie := @deleteCookie;
    cookie^.Result := @Result;
    TCEFEventCallback.SendEvent(visitPtr, [cookie, @Result]);
    cookie := nil;
  end;
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


end.
