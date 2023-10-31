//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPdfPrintCallback_Create(var Result: ICefPdfPrintCallback); extdecl;
begin
  handleExceptionBegin
  Result := TPdfPrintCallbackRef.Create;
  handleExceptionEnd
end;

procedure CefPdfPrintCallback_OnPdfPrintFinished(const AObj: ICefPdfPrintCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPdfPrintCallbackRef).PdfPrintFinishedPtr := AEventData;
  handleExceptionEnd
end;

exports
  CefPdfPrintCallback_Create,
  CefPdfPrintCallback_OnPdfPrintFinished;