//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure DownloadImageCallbackRef_Create(var Result: ICefDownloadImageCallback); extdecl;
begin
  handleExceptionBegin
  Result := TDownloadImageCallbackRef.Create;
  handleExceptionEnd
end;

procedure DownloadImageCallback_OnDownloadImageFinished(const AObj: ICefDownloadImageCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDownloadImageCallbackRef).DownloadImageFinishedPtr := AEventData;
  handleExceptionEnd
end;

exports
  DownloadImageCallbackRef_Create,
  DownloadImageCallback_OnDownloadImageFinished
;
