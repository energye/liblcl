//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure DownloadImageCallbackRef_Create(var Result: TDownloadImageCallbackRef); extdecl;
begin
  handleExceptionBegin
  Result := TDownloadImageCallbackRef.Create;
  handleExceptionEnd
end;

procedure DownloadImageCallback_OnDownloadImageFinished(const AObj: TDownloadImageCallbackRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.DownloadImageFinishedPtr := AEventData;
  handleExceptionEnd
end;

exports
  DownloadImageCallbackRef_Create,
  DownloadImageCallback_OnDownloadImageFinished
;
