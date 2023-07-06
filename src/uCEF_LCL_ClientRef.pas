//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ClientRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes,
  uCEFTypes, uCEFInterfaces, uCEFClient, uCEF_LCL_ClientHandlersRef,
  uCEF_LCL_EventCallback;

type

  {== Client ==}
  TClientRef = class(TCefClientOwn)
  protected
    FAudioHandler: ICefAudioHandler;
    FCommandHandler: ICefCommandHandler;
    FLoadHandler: ICefLoadHandler;
    FFocusHandler: ICefFocusHandler;
    FContextMenuHandler: ICefContextMenuHandler;
    FDialogHandler: ICefDialogHandler;
    FKeyboardHandler: ICefKeyboardHandler;
    FDisplayHandler: ICefDisplayHandler;
    FDownloadHandler: ICefDownloadHandler;
    FJsDialogHandler: ICefJsDialogHandler;
    FLifeSpanHandler: ICefLifeSpanHandler;
    FRenderHandler: ICefRenderHandler;
    FRequestHandler: ICefRequestHandler;
    FDragHandler: ICefDragHandler;
    FFindHandler: ICefFindHandler;
    FPrintHandler: ICefPrintHandler;
    FFrameHandler: ICefFrameHandler;
    FPermissionHandler: ICefPermissionHandler;
  public

    procedure GetAudioHandler(var aHandler: ICefAudioHandler); override;
    procedure GetCommandHandler(var aHandler: ICefCommandHandler); override;
    procedure GetContextMenuHandler(var aHandler: ICefContextMenuHandler); override;
    procedure GetDialogHandler(var aHandler: ICefDialogHandler); override;
    procedure GetDisplayHandler(var aHandler: ICefDisplayHandler); override;
    procedure GetDownloadHandler(var aHandler: ICefDownloadHandler); override;
    procedure GetDragHandler(var aHandler: ICefDragHandler); override;
    procedure GetFindHandler(var aHandler: ICefFindHandler); override;
    procedure GetFocusHandler(var aHandler: ICefFocusHandler); override;
    procedure GetFrameHandler(var aHandler: ICefFrameHandler); override;
    procedure GetPermissionHandler(var aHandler: ICefPermissionHandler); override;
    procedure GetJsdialogHandler(var aHandler: ICefJsdialogHandler); override;
    procedure GetKeyboardHandler(var aHandler: ICefKeyboardHandler); override;
    procedure GetLifeSpanHandler(var aHandler: ICefLifeSpanHandler); override;
    procedure GetLoadHandler(var aHandler: ICefLoadHandler); override;
    procedure GetPrintHandler(var aHandler: ICefPrintHandler); override;
    procedure GetRenderHandler(var aHandler: ICefRenderHandler); override;
    procedure GetRequestHandler(var aHandler: ICefRequestHandler); override;
    function OnProcessMessageReceived(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message_: ICefProcessMessage): boolean; override;

    procedure RemoveReferences; override;
    constructor Create; override;
    destructor Destroy; override;
  end;

implementation


procedure TClientRef.GetAudioHandler(var aHandler: ICefAudioHandler);
begin
  if FAudioHandler = nil then
  begin
    FAudioHandler := TAudioHandlerRef.Create;
  end;
  aHandler := FAudioHandler;
end;

procedure TClientRef.GetCommandHandler(var aHandler: ICefCommandHandler);
begin
  if FCommandHandler = nil then
  begin
    FCommandHandler := TCommandHandlerRef.Create;
  end;
  aHandler := FCommandHandler;
end;

procedure TClientRef.GetContextMenuHandler(var aHandler: ICefContextMenuHandler);
begin
  if FContextMenuHandler = nil then
  begin
    FContextMenuHandler := TContextMenuHandlerRef.Create;
  end;
  aHandler := FContextMenuHandler;
end;

procedure TClientRef.GetDialogHandler(var aHandler: ICefDialogHandler);
begin
  if FDialogHandler = nil then
  begin
    FDialogHandler := TDialogHandlerRef.Create;
  end;
  aHandler := FDialogHandler;
end;

procedure TClientRef.GetDisplayHandler(var aHandler: ICefDisplayHandler);
begin
  if FDisplayHandler = nil then
  begin
    FDisplayHandler := TDisplayHandlerRef.Create;
  end;
  aHandler := FDisplayHandler;
end;

procedure TClientRef.GetDownloadHandler(var aHandler: ICefDownloadHandler);
begin
  if FDownloadHandler = nil then
  begin
    FDownloadHandler := TDownloadHandlerRef.Create;
  end;
  aHandler := FDownloadHandler;
end;

procedure TClientRef.GetDragHandler(var aHandler: ICefDragHandler);
begin
  if FDragHandler = nil then
  begin
    FDragHandler := TDragHandlerRef.Create;
  end;
  aHandler := FDragHandler;
end;

procedure TClientRef.GetFindHandler(var aHandler: ICefFindHandler);
begin
  if FFindHandler = nil then
  begin
    FFindHandler := TFindHandlerRef.Create;
  end;
  aHandler := FFindHandler;
end;

procedure TClientRef.GetFocusHandler(var aHandler: ICefFocusHandler);
begin
  if FFocusHandler = nil then
  begin
    FFocusHandler := TFocusHandlerRef.Create;
  end;
  aHandler := FFocusHandler;
end;

procedure TClientRef.GetFrameHandler(var aHandler: ICefFrameHandler);
begin
  if FFrameHandler = nil then
  begin
    FFrameHandler := TFrameHandlerRef.Create;
  end;
  aHandler := FFrameHandler;
end;

procedure TClientRef.GetPermissionHandler(var aHandler: ICefPermissionHandler);
begin
  if FPermissionHandler = nil then
  begin
    FPermissionHandler := TPermissionHandlerRef.Create;
  end;
  aHandler := FPermissionHandler;
end;

procedure TClientRef.GetJsdialogHandler(var aHandler: ICefJsdialogHandler);
begin
  if FJsDialogHandler = nil then
  begin
    FJsDialogHandler := TJsDialogHandlerRef.Create;
  end;
  aHandler := FJsDialogHandler;
end;

procedure TClientRef.GetKeyboardHandler(var aHandler: ICefKeyboardHandler);
begin
  if FKeyboardHandler = nil then
  begin
    FKeyboardHandler := TKeyboardHandlerRef.Create;
  end;
  aHandler := FKeyboardHandler;
end;

procedure TClientRef.GetLifeSpanHandler(var aHandler: ICefLifeSpanHandler);
begin
  if FLifeSpanHandler = nil then
  begin
    FLifeSpanHandler := TLifeSpanHandlerRef.Create;
  end;
  aHandler := FLifeSpanHandler;
end;

procedure TClientRef.GetLoadHandler(var aHandler: ICefLoadHandler);
begin
  if FLoadHandler = nil then
  begin
    FLoadHandler := TLoadHandlerRef.Create;
  end;
  aHandler := FLoadHandler;
end;

procedure TClientRef.GetPrintHandler(var aHandler: ICefPrintHandler);
begin
  if FPrintHandler = nil then
  begin
    FPrintHandler := TPrintHandlerRef.Create;
  end;
  aHandler := FPrintHandler;
end;

procedure TClientRef.GetRenderHandler(var aHandler: ICefRenderHandler);
begin
  if FRenderHandler = nil then
  begin
    FRenderHandler := TRenderHandlerRef.Create;
  end;
  aHandler := FRenderHandler;
end;

procedure TClientRef.GetRequestHandler(var aHandler: ICefRequestHandler);
begin
  if FRequestHandler = nil then
  begin
    FRequestHandler := TRequestHandlerRef.Create;
  end;
  aHandler := FRequestHandler;
end;

function TClientRef.OnProcessMessageReceived(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message_: ICefProcessMessage): boolean;
begin
  Result := inherited OnProcessMessageReceived(browser, frame, sourceProcess, message_);
end;

procedure TClientRef.RemoveReferences;
begin
  if (FAudioHandler <> nil) then FAudioHandler.RemoveReferences;
  if (FCommandHandler <> nil) then FCommandHandler.RemoveReferences;
  if (FLoadHandler <> nil) then FLoadHandler.RemoveReferences;
  if (FFocusHandler <> nil) then FFocusHandler.RemoveReferences;
  if (FContextMenuHandler <> nil) then FContextMenuHandler.RemoveReferences;
  if (FDialogHandler <> nil) then FDialogHandler.RemoveReferences;
  if (FKeyboardHandler <> nil) then FKeyboardHandler.RemoveReferences;
  if (FDisplayHandler <> nil) then FDisplayHandler.RemoveReferences;
  if (FDownloadHandler <> nil) then FDownloadHandler.RemoveReferences;
  if (FJsDialogHandler <> nil) then FJsDialogHandler.RemoveReferences;
  if (FLifeSpanHandler <> nil) then FLifeSpanHandler.RemoveReferences;
  if (FRequestHandler <> nil) then FRequestHandler.RemoveReferences;
  if (FRenderHandler <> nil) then FRenderHandler.RemoveReferences;
  if (FDragHandler <> nil) then FDragHandler.RemoveReferences;
  if (FFindHandler <> nil) then FFindHandler.RemoveReferences;
  if (FPrintHandler <> nil) then FPrintHandler.RemoveReferences;
  if (FFrameHandler <> nil) then FFrameHandler.RemoveReferences;
  if (FPermissionHandler <> nil) then FPermissionHandler.RemoveReferences;
  FAudioHandler := nil;
  FCommandHandler := nil;
  FContextMenuHandler := nil;
  FDialogHandler := nil;
  FDisplayHandler := nil;
  FDownloadHandler := nil;
  FDragHandler := nil;
  FFindHandler := nil;
  FFocusHandler := nil;
  FFrameHandler := nil;
  FPermissionHandler := nil;
  FJsDialogHandler := nil;
  FKeyboardHandler := nil;
  FLifeSpanHandler := nil;
  FLoadHandler := nil;
  FPrintHandler := nil;
  FRenderHandler := nil;
  FRequestHandler := nil;
end;


constructor TClientRef.Create;
begin
  inherited Create;
  FAudioHandler := nil;
  FCommandHandler := nil;
  FContextMenuHandler := nil;
  FDialogHandler := nil;
  FDisplayHandler := nil;
  FDownloadHandler := nil;
  FDragHandler := nil;
  FFindHandler := nil;
  FFocusHandler := nil;
  FFrameHandler := nil;
  FPermissionHandler := nil;
  FJsDialogHandler := nil;
  FKeyboardHandler := nil;
  FLifeSpanHandler := nil;
  FLoadHandler := nil;
  FPrintHandler := nil;
  FRenderHandler := nil;
  FRequestHandler := nil;
end;

destructor TClientRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

end.
