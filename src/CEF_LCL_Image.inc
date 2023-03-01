//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFImage_New(out Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := TCefImageRef.New;
  handleExceptionEnd
end;

function CEFImage_AddPng(const TObj: ICefImage; scaleFactor: PSingle; const pngData: Pointer; pngDataSize: NativeUInt): longbool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.AddPng(Single(scaleFactor^), pngData, pngDataSize);
  handleExceptionEnd
end;

function CEFImage_AddJpeg(const TObj: ICefImage; scaleFactor: PSingle; const pngData: Pointer; pngDataSize: NativeUInt): longbool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.AddJpeg(Single(scaleFactor^), pngData, pngDataSize);
  handleExceptionEnd
end;

function CEFImage_GetWidth(const TObj: ICefImage): integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TObj.GetWidth());
  handleExceptionEnd
end;

function CEFImage_GetHeight(const TObj: ICefImage): integer; extdecl;
begin
  handleExceptionBegin
  Result := Integer(TObj.GetHeight());
  handleExceptionEnd
end;

function CEFImage_AddBitmap(const TObj: ICefImage; scaleFactor: PSingle; pixelWidth, pixelHeight: Integer; colorType: Integer; alphaType: Integer; const pixelData: Pointer; pixelDataSize: NativeUInt): longbool; extdecl;
var
  ct: TCefColorType;
  at: TCefAlphaType;
begin
  handleExceptionBegin
  //colorType = TCefColorType = (
  //  CEF_COLOR_TYPE_RGBA_8888,
  //  CEF_COLOR_TYPE_BGRA_8888
  //);
  //alphaType = TCefAlphaType = (
  //  CEF_ALPHA_TYPE_OPAQUE,
  //  CEF_ALPHA_TYPE_PREMULTIPLIED,
  //  CEF_ALPHA_TYPE_POSTMULTIPLIED
  //);
  if colorType = 0 then
     ct := TCefColorType.CEF_COLOR_TYPE_RGBA_8888
  else if colorType = 1 then
     ct := TCefColorType.CEF_COLOR_TYPE_BGRA_8888
  else
     ct := TCefColorType.CEF_COLOR_TYPE_RGBA_8888;
  if alphaType = 0 then
     at := TCefAlphaType.CEF_ALPHA_TYPE_OPAQUE
  else if alphaType = 1 then
     at := TCefAlphaType.CEF_ALPHA_TYPE_PREMULTIPLIED
  else if alphaType = 1 then
     at := TCefAlphaType.CEF_ALPHA_TYPE_POSTMULTIPLIED
  else
     at := TCefAlphaType.CEF_ALPHA_TYPE_OPAQUE;
  Result := TObj.AddBitmap(Single(scaleFactor^), pixelWidth, pixelHeight, ct, at, pixelData, pixelDataSize);
  handleExceptionEnd
end;

function CEFImage_HasRepresentation(const TObj: ICefImage; scaleFactor: PSingle): longbool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasRepresentation(Single(scaleFactor^));
  handleExceptionEnd
end;

function CEFImage_RemoveRepresentation(const TObj: ICefImage; scaleFactor: PSingle): longbool;  extdecl;
begin
  handleExceptionBegin
  Result := TObj.RemoveRepresentation(Single(scaleFactor^));
  handleExceptionEnd
end;

function CEFImage_GetRepresentationInfo(const TObj: ICefImage; scaleFactor: PSingle; var actualScaleFactor: PSingle; var pixelWidth, pixelHeight: Integer): longbool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetRepresentationInfo(Single(scaleFactor^), Single(actualScaleFactor^), pixelWidth, pixelHeight);
  handleExceptionEnd
end;

procedure CEFImage_GetAsBitmap(const TObj: ICefImage; scaleFactor: PSingle; colorType: Integer; alphaType: Integer; var pixelWidth, pixelHeight: Integer; out Result: ICefBinaryValue); extdecl;
var
  ct: TCefColorType;
  at: TCefAlphaType;
begin
  handleExceptionBegin
  //colorType = TCefColorType = (
  //  CEF_COLOR_TYPE_RGBA_8888,
  //  CEF_COLOR_TYPE_BGRA_8888
  //);
  //alphaType = TCefAlphaType = (
  //  CEF_ALPHA_TYPE_OPAQUE,
  //  CEF_ALPHA_TYPE_PREMULTIPLIED,
  //  CEF_ALPHA_TYPE_POSTMULTIPLIED
  //);
  if colorType = 0 then
     ct := TCefColorType.CEF_COLOR_TYPE_RGBA_8888
  else if colorType = 1 then
     ct := TCefColorType.CEF_COLOR_TYPE_BGRA_8888
  else
     ct := TCefColorType.CEF_COLOR_TYPE_RGBA_8888;
  if alphaType = 0 then
     at := TCefAlphaType.CEF_ALPHA_TYPE_OPAQUE
  else if alphaType = 1 then
     at := TCefAlphaType.CEF_ALPHA_TYPE_PREMULTIPLIED
  else if alphaType = 1 then
     at := TCefAlphaType.CEF_ALPHA_TYPE_POSTMULTIPLIED
  else
     at := TCefAlphaType.CEF_ALPHA_TYPE_OPAQUE;
  Result := TObj.GetAsBitmap(Single(scaleFactor^), ct, at, pixelWidth, pixelHeight);
  handleExceptionEnd
end;

procedure CEFImage_GetAsPng(const TObj: ICefImage; scaleFactor: PSingle; withTransparency: longbool; var pixelWidth, pixelHeight: Integer; out Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetAsPng(Single(scaleFactor^), withTransparency, pixelWidth, pixelHeight);
  handleExceptionEnd
end;

procedure CEFImage_GetAsJpeg(const TObj: ICefImage; scaleFactor: PSingle; quality: Integer; var pixelWidth, pixelHeight: Integer; out Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetAsJpeg(Single(scaleFactor^), quality, pixelWidth, pixelHeight);
  handleExceptionEnd
end;


exports
  CEFImage_New,
  CEFImage_AddPng,
  CEFImage_AddJpeg,
  CEFImage_GetWidth,
  CEFImage_GetHeight,
  CEFImage_AddBitmap,
  CEFImage_HasRepresentation,
  CEFImage_RemoveRepresentation,
  CEFImage_GetRepresentationInfo,
  CEFImage_GetAsBitmap,
  CEFImage_GetAsPng,
  CEFImage_GetAsJpeg
;

