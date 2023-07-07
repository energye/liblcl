//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure BitmapBitBuffer_Create(aWidth, aHeight: Integer; var Result: TCEFBitmapBitBuffer); extdecl;
begin
  handleExceptionBegin
  Result := TCEFBitmapBitBuffer.Create(aWidth, aHeight);
  handleExceptionEnd
end;

procedure BitmapBitBuffer_Free(AObj: TCEFBitmapBitBuffer); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

procedure BitmapBitBuffer_UpdateSize(AObj: TCEFBitmapBitBuffer; aWidth, aHeight : integer); extdecl;
begin
  handleExceptionBegin
  AObj.UpdateSize(aWidth, aHeight);
  handleExceptionEnd
end;

function  BitmapBitBuffer_Width(AObj: TCEFBitmapBitBuffer) :integer ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Width;
  handleExceptionEnd
end;

function  BitmapBitBuffer_Height(AObj: TCEFBitmapBitBuffer) :integer ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Height;
  handleExceptionEnd
end;

function  BitmapBitBuffer_BufferLength(AObj: TCEFBitmapBitBuffer) :integer ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferLength;
  handleExceptionEnd
end;

function  BitmapBitBuffer_Empty(AObj: TCEFBitmapBitBuffer) :LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Empty;
  handleExceptionEnd
end;

function  BitmapBitBuffer_Scanline(AObj: TCEFBitmapBitBuffer; y: integer) :PByte ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Scanline[y];
  handleExceptionEnd
end;

function  BitmapBitBuffer_ScanlineSize(AObj: TCEFBitmapBitBuffer) :integer ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ScanlineSize;
  handleExceptionEnd
end;

function  BitmapBitBuffer_BufferScanlineSize(AObj: TCEFBitmapBitBuffer) :integer ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferScanlineSize;
  handleExceptionEnd
end;

function  BitmapBitBuffer_BufferBits(AObj: TCEFBitmapBitBuffer) :pointer ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferBits;
  handleExceptionEnd
end;

exports
  BitmapBitBuffer_Create,
  BitmapBitBuffer_Free,
  BitmapBitBuffer_UpdateSize,
  BitmapBitBuffer_Width,
  BitmapBitBuffer_Height,
  BitmapBitBuffer_BufferLength,
  BitmapBitBuffer_Empty,
  BitmapBitBuffer_Scanline,
  BitmapBitBuffer_ScanlineSize,
  BitmapBitBuffer_BufferScanlineSize,
  BitmapBitBuffer_BufferBits

;
