//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_DomVisitorRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFInterfaces, uCEFDomVisitor,
  uCEF_LCL_EventCallback;

type

  TDomVisitorRef = class(TCefDomVisitorOwn)
  public
    VisitPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure visit(const document: ICefDomDocument); override;
  end;

implementation

procedure TDomVisitorRef.visit(const document: ICefDomDocument);
begin
  if (VisitPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(VisitPtr, [document]);
  end;
end;

constructor TDomVisitorRef.Create;
begin
  inherited Create;
  VisitPtr := nil;
end;

destructor TDomVisitorRef.Destroy;
begin
  inherited Destroy;
  VisitPtr := nil;
end;

end.
