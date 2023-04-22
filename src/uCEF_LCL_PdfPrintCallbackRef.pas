//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_PdfPrintCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFPDFPrintCallback,
  uCEF_LCL_EventCallback;

type

  TPdfPrintCallbackRef = class(TCefPdfPrintCallbackOwn)
  public
    PdfPrintFinishedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnPdfPrintFinished(const path: ustring; ok: boolean); override;
  end;

implementation

procedure TPdfPrintCallbackRef.OnPdfPrintFinished(const path: ustring; ok: boolean);
begin
  if (PdfPrintFinishedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PdfPrintFinishedPtr, [PChar(string(path)), ok]);
  end;
end;

constructor TPdfPrintCallbackRef.Create;
begin
  inherited Create;
end;

destructor TPdfPrintCallbackRef.Destroy;
begin
  inherited Destroy;
end;

end.
