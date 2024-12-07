//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure ChromiumFontOptions_StandardFontFamily(ASet: LongBool; const AObj: TChromium; AValue: PChar; out Result: PChar);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.StandardFontFamily := PCharToUStr(AValue);
  end
  else
    Result := ToPChar(AObj.FontOptions.StandardFontFamily);
  handleExceptionEnd
end;

procedure ChromiumFontOptions_FixedFontFamily(ASet: LongBool; const AObj: TChromium; AValue: PChar; out Result: PChar);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.FixedFontFamily := PCharToUStr(AValue);
  end
  else
    Result := ToPChar(AObj.FontOptions.FixedFontFamily);
  handleExceptionEnd
end;

procedure ChromiumFontOptions_SerifFontFamily(ASet: LongBool; const AObj: TChromium; AValue: PChar; out Result: PChar);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.SerifFontFamily := PCharToUStr(AValue);
  end
  else
    Result := ToPChar(AObj.FontOptions.SerifFontFamily);
  handleExceptionEnd
end;

procedure ChromiumFontOptions_SansSerifFontFamily(ASet: LongBool; const AObj: TChromium; AValue: PChar; out Result: PChar);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.SansSerifFontFamily := PCharToUStr(AValue);
  end
  else
    Result := ToPChar(AObj.FontOptions.SansSerifFontFamily);
  handleExceptionEnd
end;

procedure ChromiumFontOptions_CursiveFontFamily(ASet: LongBool; const AObj: TChromium; AValue: PChar; out Result: PChar);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.CursiveFontFamily := PCharToUStr(AValue);
  end
  else
    Result := ToPChar(AObj.FontOptions.CursiveFontFamily);
  handleExceptionEnd
end;

procedure ChromiumFontOptions_FantasyFontFamily(ASet: LongBool; const AObj: TChromium; AValue: PChar; out Result: PChar);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.FantasyFontFamily := PCharToUStr(AValue);
  end
  else
    Result := ToPChar(AObj.FontOptions.FantasyFontFamily);
  handleExceptionEnd
end;

procedure ChromiumFontOptions_DefaultFontSize(ASet: LongBool; const AObj: TChromium; AValue: Integer; out Result: Integer);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.DefaultFontSize := AValue;
  end
  else
    Result := AObj.FontOptions.DefaultFontSize;
  handleExceptionEnd
end;

procedure ChromiumFontOptions_DefaultFixedFontSize(ASet: LongBool; const AObj: TChromium; AValue: Integer; out Result: Integer);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.DefaultFixedFontSize := AValue;
  end
  else
    Result := AObj.FontOptions.DefaultFixedFontSize;
  handleExceptionEnd
end;

procedure ChromiumFontOptions_MinimumFontSize(ASet: LongBool; const AObj: TChromium; AValue: Integer; out Result: Integer);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.MinimumFontSize := AValue;
  end
  else
    Result := AObj.FontOptions.MinimumFontSize;
  handleExceptionEnd
end;

procedure ChromiumFontOptions_MinimumLogicalFontSize(ASet: LongBool; const AObj: TChromium; AValue: Integer; out Result: Integer);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.MinimumLogicalFontSize := AValue;
  end
  else
    Result := AObj.FontOptions.MinimumLogicalFontSize;
  handleExceptionEnd
end;

procedure ChromiumFontOptions_RemoteFonts(ASet: LongBool; const AObj: TChromium; AValue: TCefState; out Result: TCefState);  extdecl;
begin
  handleExceptionBegin
  if ASet then
  begin
    AObj.FontOptions.RemoteFonts := AValue;
  end
  else
    Result := AObj.FontOptions.RemoteFonts;
  handleExceptionEnd
end;

exports
  ChromiumFontOptions_StandardFontFamily,
  ChromiumFontOptions_FixedFontFamily,
  ChromiumFontOptions_SerifFontFamily,
  ChromiumFontOptions_SansSerifFontFamily,
  ChromiumFontOptions_CursiveFontFamily,
  ChromiumFontOptions_FantasyFontFamily,
  ChromiumFontOptions_DefaultFontSize,
  ChromiumFontOptions_DefaultFixedFontSize,
  ChromiumFontOptions_MinimumFontSize,
  ChromiumFontOptions_MinimumLogicalFontSize,
  ChromiumFontOptions_RemoteFonts;
