//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure ChromiumOptions_SetJavascript(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.Javascript := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetJavascriptCloseWindows(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.JavascriptCloseWindows := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetJavascriptAccessClipboard(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.JavascriptAccessClipboard := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetJavascriptDomPaste(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.JavascriptDomPaste := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetImageLoading(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.ImageLoading := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetImageShrinkStandaloneToFit(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.ImageShrinkStandaloneToFit := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetTextAreaResize(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.TextAreaResize := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetTabToLinks(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.TabToLinks := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetLocalStorage(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.LocalStorage := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetDatabases(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.Databases := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetWebgl(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.Webgl := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetBackgroundColor(const AObj: TChromium; AValue: TCefColor); extdecl;
begin
  handleExceptionBegin
  AObj.Options.BackgroundColor := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetWindowlessFrameRate(const AObj: TChromium; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Options.WindowlessFrameRate := AValue;
  handleExceptionEnd
end;

procedure ChromiumOptions_SetChromeStatusBubble(const AObj: TChromium; AValue: TCefState); extdecl;
begin
  handleExceptionBegin
  AObj.Options.ChromeStatusBubble := AValue;
  handleExceptionEnd
end;

function ChromiumOptions_ChromeZoomBubble(IsSet: LongBool; const AObj: TChromium; AValue: TCefState): TCefState; extdecl;
begin
  handleExceptionBegin
  Result := STATE_DEFAULT;
  if IsSet then
    AObj.Options.ChromeZoomBubble := AValue
  else
    Result := AObj.Options.ChromeZoomBubble;
  handleExceptionEnd
end;


exports
  ChromiumOptions_SetJavascript,
  ChromiumOptions_SetJavascriptCloseWindows,
  ChromiumOptions_SetJavascriptAccessClipboard,
  ChromiumOptions_SetJavascriptDomPaste,
  ChromiumOptions_SetImageLoading,
  ChromiumOptions_SetImageShrinkStandaloneToFit,
  ChromiumOptions_SetTextAreaResize,
  ChromiumOptions_SetTabToLinks,
  ChromiumOptions_SetLocalStorage,
  ChromiumOptions_SetDatabases,
  ChromiumOptions_SetWebgl,
  ChromiumOptions_SetBackgroundColor,
  ChromiumOptions_SetWindowlessFrameRate,
  ChromiumOptions_SetChromeStatusBubble,
  ChromiumOptions_ChromeZoomBubble;
