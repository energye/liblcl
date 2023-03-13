//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPdfPrintCallback_Create(var Result: TPdfPrintCallbackRef); extdecl;
begin
  handleExceptionBegin
  Result := TPdfPrintCallbackRef.Create;
  handleExceptionEnd
end;

procedure CefPdfPrintCallback_OnPdfPrintFinished(const AObj: TPdfPrintCallbackRef; AEventData: Pointer); extdecl;
begin
    AObj.PdfPrintFinishedPtr := AEventData;
end;

exports
    CefPdfPrintCallback_Create,
    CefPdfPrintCallback_OnPdfPrintFinished
;
