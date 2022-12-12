//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CEFImage_New(): ICefImage; extdecl;
begin
  handleExceptionBegin
  //Result := TCefImageRef.New;
  Result := nil;
  handleExceptionEnd
end;


function CEFImage_AddPng(TObj: TCefImageRef; scaleFactor: Single; const pngData: Pointer; pngDataSize: NativeUInt): longbool; extdecl;
begin
  handleExceptionBegin
  Result := ICefImage(TObj).AddPng(scaleFactor, pngData, pngDataSize);
  handleExceptionEnd
end;

function CEFImage_AddJpeg(TObj: Pointer; scaleFactor: Single; const jpegData: Pointer; jpegDataSize: NativeUInt): longbool; extdecl;
begin
  handleExceptionBegin
  Result := TCefImageRef.UnWrap(TObj).AddJpeg(scaleFactor, jpegData, jpegDataSize);
  handleExceptionEnd
end;

function CEFImage_GetWidth(TObj: Pointer): integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TCefImageRef.UnWrap(TObj).GetWidth);
  handleExceptionEnd
end;

function CEFImage_GetHeight(TObj: Pointer): integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TCefImageRef.UnWrap(TObj).GetHeight);
  handleExceptionEnd
end;

exports
  CEFImage_New,
  CEFImage_AddPng,
  CEFImage_AddJpeg,
  CEFImage_GetWidth,
  CEFImage_GetHeight
;

