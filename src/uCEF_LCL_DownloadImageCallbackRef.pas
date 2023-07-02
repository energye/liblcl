//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_DownloadImageCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFTypes, uCEFInterfaces,
  uCEFDownloadImageCallBack,
  uCEF_LCL_EventCallback;

type

  TDownloadImageCallbackRef = class(TCefDownloadImageCallbackOwn)
  public
    DownloadImageFinishedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnDownloadImageFinished(const imageUrl: ustring; httpStatusCode: integer; const image: ICefImage); override;

  end;

implementation

procedure TDownloadImageCallbackRef.OnDownloadImageFinished(const imageUrl: ustring; httpStatusCode: integer; const image: ICefImage);
begin
  if (DownloadImageFinishedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DownloadImageFinishedPtr, [PChar(string(imageUrl)), httpStatusCode, image]);
  end;
end;

constructor TDownloadImageCallbackRef.Create;
begin
  inherited Create;
end;

destructor TDownloadImageCallbackRef.Destroy;
begin
  inherited Destroy;
  DownloadImageFinishedPtr := nil;
end;

end.
