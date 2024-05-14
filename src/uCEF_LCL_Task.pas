//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_Task;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFTask,
  uCEFMiscFunctions;

type

  // TTask
  TTaskExecute = procedure() of object;

  /// <summary>
  /// Implement this interface for asynchronous task execution. If the task is
  /// posted successfully and if the associated message loop is still running then
  /// the execute() function will be called on the target thread. If the task
  /// fails to post then the task object may be destroyed on the source thread
  /// instead of the target thread. For this reason be cautious when performing
  /// work in the task object destructor.
  /// </summary>
  /// <remarks>
  /// <para><see cref="uCEFTypes|TCefTask">Implements TCefTask</see></para>
  /// <para><see href="https://bitbucket.org/chromiumembedded/cef/src/master/include/capi/cef_task_capi.h">CEF source file: /include/capi/cef_task_capi.h (cef_task_t)</see></para>
  /// </remarks>
  TTask = class(TCefTaskOwn)
  protected
    FOnly: boolean;
    FOnExecute: TTaskExecute;
    /// <summary>
    /// Method that will be executed on the target thread.
    /// </summary>
    procedure Execute; override;
  public
    constructor Create; override;
    destructor Destroy; override;
    function OnlyPostTask(threadId: TCefThreadId): Boolean;
    function OnlyPostDelayedTask(threadId: TCefThreadId; Delay: int64): Boolean;
  published
    /// <summary>
    /// Method that will be executed on the target thread.
    /// </summary>
    property OnExecute: TTaskExecute read FOnExecute write FOnExecute;
  end;

implementation

constructor TTask.Create();
begin
  inherited Create;
  FOnExecute := nil;
  FOnly := True;
end;

destructor TTask.Destroy;
begin
  inherited Destroy;
  FOnExecute := nil;
end;

function TTask.OnlyPostTask(threadId: TCefThreadId): Boolean;
begin
  Result := False;
  if FOnly and assigned(FOnExecute) then
  begin
    CefPostTask(threadId, self);
    FOnly := False;
    Result := True;
  end;
end;

function TTask.OnlyPostDelayedTask(threadId: TCefThreadId; Delay: int64): Boolean;
begin
  Result := False;
  if FOnly and assigned(FOnExecute) then
  begin
    CefPostDelayedTask(threadId, self, Delay);
    FOnly := False;
    Result := True;
  end;
end;

procedure TTask.Execute;
begin
  if assigned(FOnExecute) then
  begin
    FOnExecute();
  end;
end;

end.
