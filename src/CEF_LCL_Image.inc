//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CEFImage_New(): Pointer; extdecl;
var
  Ret: ICefImage;
begin
  handleExceptionBegin
  Ret := TCefImageRef.New;
  Result := Ret.Wrap;
  //Result := TCefImageRef(TCefImageRef.New);
  //Result := nil;
  handleExceptionEnd
end;

function CEFImage_AddPng(TObj: Pointer; scaleFactor: PSingle; const pngData: array of Byte; pngDataSize: NativeUInt): longbool; extdecl;
var
  Image: ICefImage;
begin
  handleExceptionBegin
  ConsoleLn('CEFImage_AddPng ' + FloatToStr(scaleFactor^) + ' pngDataSize: ' + IntToStr(pngDataSize));
  Image := TCefImageRef.UnWrap(TObj);
  Result := Image.AddPng(scaleFactor^, @pngData[0], Length(pngData));
  ConsoleLn(' width: '+ IntToStr(Image.Width) +  ' height: '+ IntToStr(Image.height) + ' IsEmpty: ' + BoolToStr(Image.IsEmpty, True));
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

