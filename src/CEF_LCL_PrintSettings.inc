//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPrintSettingsRef_Create(var Result: ICefPrintSettings); extdecl;
begin
  handleExceptionBegin
  Result := TCefPrintSettingsRef.New;
  handleExceptionEnd
end;

function  CefPrintSettings_IsValid(const AObj: ICefPrintSettings): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsValid;
  handleExceptionEnd
end;

function  CefPrintSettings_IsReadOnly(const AObj: ICefPrintSettings): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsReadOnly;
  handleExceptionEnd
end;

procedure CefPrintSettings_SetOrientation(const AObj: ICefPrintSettings; landscape: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetOrientation(landscape);
  handleExceptionEnd
end;

function  CefPrintSettings_IsLandscape(const AObj: ICefPrintSettings): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsLandscape;
  handleExceptionEnd
end;

procedure CefPrintSettings_SetPrinterPrintableArea(const AObj: ICefPrintSettings; const physicalSizeDeviceUnits: TCefSize; const printableAreaDeviceUnits: TCefRect; landscapeNeedsFlip: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetPrinterPrintableArea(@physicalSizeDeviceUnits, @printableAreaDeviceUnits, landscapeNeedsFlip);
  handleExceptionEnd
end;

procedure CefPrintSettings_SetDeviceName(const AObj: ICefPrintSettings; const name: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetDeviceName(PCharToUStr(name));
  handleExceptionEnd
end;

function  CefPrintSettings_GetDeviceName(const AObj: ICefPrintSettings): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetDeviceName));
  handleExceptionEnd
end;

procedure CefPrintSettings_SetDpi(const AObj: ICefPrintSettings; dpi: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.SetDpi(dpi);
  handleExceptionEnd
end;

function  CefPrintSettings_GetDpi(const AObj: ICefPrintSettings): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetDpi;
  handleExceptionEnd
end;

procedure CefPrintSettings_SetPageRanges(const AObj: ICefPrintSettings; const PRanges: PTCefRangeArray; size: Integer); extdecl;
var
  i: Integer;
  ranges: TCefPageRangeArray;
begin
  handleExceptionBegin
  try
    SetLength(ranges, size);
    for i := 0 to  size - 1 do
    begin
      ranges[i] := PRanges^[i];
    end;
    AObj.SetPageRanges(ranges);
  finally
    SetLength(ranges, 0);
  end;
  handleExceptionEnd
end;

function  CefPrintSettings_GetPageRangesCount(const AObj: ICefPrintSettings): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetPageRangesCount;
  handleExceptionEnd
end;

procedure CefPrintSettings_GetPageRanges(const AObj: ICefPrintSettings; out Result: TCefPageRangeArray); extdecl;
begin
  handleExceptionBegin
  AObj.GetPageRanges(Result);
  handleExceptionEnd
end;

procedure CefPrintSettings_SetSelectionOnly(const AObj: ICefPrintSettings; selectionOnly: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetSelectionOnly(selectionOnly);
  handleExceptionEnd
end;

function  CefPrintSettings_IsSelectionOnly(const AObj: ICefPrintSettings): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSelectionOnly;
  handleExceptionEnd
end;

procedure CefPrintSettings_SetCollate(const AObj: ICefPrintSettings; collate: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetCollate(collate);
  handleExceptionEnd
end;

function  CefPrintSettings_WillCollate(const AObj: ICefPrintSettings): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.WillCollate;
  handleExceptionEnd
end;

procedure CefPrintSettings_SetColorModel(const AObj: ICefPrintSettings; model: Integer); extdecl;
begin
  handleExceptionBegin
  // const TCefColorModel
  AObj.SetColorModel(TCefColorModel(model));
  handleExceptionEnd
end;

function  CefPrintSettings_GetColorModel(const AObj: ICefPrintSettings): Integer; extdecl;
begin
  handleExceptionBegin
  // const TCefColorModel
  Result := Integer(AObj.GetColorModel);
  handleExceptionEnd
end;

procedure CefPrintSettings_SetCopies(const AObj: ICefPrintSettings; copies: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.SetCopies(copies);
  handleExceptionEnd
end;

function  CefPrintSettings_GetCopies(const AObj: ICefPrintSettings): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetCopies;
  handleExceptionEnd
end;

procedure CefPrintSettings_SetDuplexMode(const AObj: ICefPrintSettings; mode: Integer); extdecl;
begin
  handleExceptionBegin
  // const TCefDuplexMode
  AObj.SetDuplexMode(mode);
  handleExceptionEnd
end;

function  CefPrintSettings_GetDuplexMode(const AObj: ICefPrintSettings): Integer; extdecl;
begin
  handleExceptionBegin
  // const TCefDuplexMode
  Result := Integer(AObj.GetDuplexMode);
  handleExceptionEnd
end;

exports
  CefPrintSettingsRef_Create,
  CefPrintSettings_IsValid,
  CefPrintSettings_IsReadOnly,
  CefPrintSettings_SetOrientation,
  CefPrintSettings_IsLandscape,
  CefPrintSettings_SetPrinterPrintableArea,
  CefPrintSettings_SetDeviceName,
  CefPrintSettings_GetDeviceName,
  CefPrintSettings_SetDpi,
  CefPrintSettings_GetDpi,
  CefPrintSettings_SetPageRanges,
  CefPrintSettings_GetPageRangesCount,
  CefPrintSettings_GetPageRanges,
  CefPrintSettings_SetSelectionOnly,
  CefPrintSettings_IsSelectionOnly,
  CefPrintSettings_SetCollate,
  CefPrintSettings_WillCollate,
  CefPrintSettings_SetColorModel,
  CefPrintSettings_GetColorModel,
  CefPrintSettings_SetCopies,
  CefPrintSettings_GetCopies,
  CefPrintSettings_SetDuplexMode,
  CefPrintSettings_GetDuplexMode;
