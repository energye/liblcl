//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------


function LazIntfImage_Create(AWidth, AHeight: Integer): TLazIntfImage; extdecl;
begin
  handleExceptionBegin
  Result := TLazIntfImage.Create(AWidth, AHeight);
  handleExceptionEnd
end;

procedure LazIntfImage_DataDescription(const AObj: TLazIntfImage; DataDescription: Integer; AWidth, AHeight: Integer); extdecl;
var
  ImgFormatDescription: TRawImageDescription;
begin
  handleExceptionBegin
  if DataDescription = 0 then
  begin
     ImgFormatDescription.Init_BPP32_B8G8R8_BIO_TTB(AWidth, AHeight);
     AObj.DataDescription := ImgFormatDescription;
  end else if DataDescription = 1 then
  begin
     ImgFormatDescription.Init_BPP32_B8G8R8_M1_BIO_TTB(AWidth, AHeight);
     AObj.DataDescription := ImgFormatDescription;
  end else if DataDescription = 2 then
  begin
     ImgFormatDescription.Init_BPP32_B8G8R8A8_BIO_TTB(AWidth, AHeight);
     AObj.DataDescription := ImgFormatDescription;
  end else if DataDescription = 3 then
  begin
     ImgFormatDescription.Init_BPP32_B8G8R8A8_M1_BIO_TTB(AWidth, AHeight);
     AObj.DataDescription := ImgFormatDescription;
  end;
  handleExceptionEnd
end;

procedure LazIntfImage_Colors(const AObj: TLazIntfImage; X, Y: Integer; var AValue: TFPColor); extdecl;
begin
  handleExceptionBegin
  //WriteLn('LazIntfImage_Colors X: ', X, ' Y: ', Y, ' Red: ', AValue.Red, ' Green: ', AValue.Green, ' Blue: ', AValue.Blue, ' Alpha: ', AValue.Alpha);
  AObj.Colors[X, Y] := AValue;
  handleExceptionEnd
end;

procedure LazIntfImage_Free(const AObj: TLazIntfImage); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

exports
  LazIntfImage_Create,
  LazIntfImage_DataDescription,
  LazIntfImage_Colors,
  LazIntfImage_Free
  ;
