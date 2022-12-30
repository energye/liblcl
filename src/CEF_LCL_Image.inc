//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CEFImage_New(): Pointer; extdecl;
var
  Image: ICefImage;
begin
  handleExceptionBegin
  Image := TCefImageRef.New;
  Result := Image.Wrap;
  handleExceptionEnd
end;

{$ifdef DARWIN}
function CEFImage_AddPng(TObj: Pointer; scaleFactor: PSingle; const data: array of Byte; dataSize: NativeUInt): longbool; extdecl;
var
  tmpData: array of Byte;
{$else}
function CEFImage_AddPng(TObj: Pointer; scaleFactor: PSingle; const data: array of Byte): longbool; extdecl;
{$endif}
begin
  handleExceptionBegin
  {$ifdef DARWIN}
  if dataSize >0 then
  begin
    try
      SetLength(tmpData, dataSize);
      Move(data[0], tmpData[0], dataSize);
      Result := TCefImageRef.UnWrap(TObj).AddPng(scaleFactor^, @tmpData[0], dataSize);
    finally
      SetLength(tmpData, 0);
    end;
  end;
  {$else}
  Result := TCefImageRef.UnWrap(TObj).AddPng(scaleFactor^, @data[0], Length(data));
  {$endif}
  handleExceptionEnd
end;

{$ifdef DARWIN}
function CEFImage_AddJpeg(TObj: Pointer; scaleFactor: PSingle; const data: array of Byte; dataSize: NativeUInt); extdecl;
var
  tmpData: array of Byte;
{$else}
function CEFImage_AddJpeg(TObj: Pointer; scaleFactor: PSingle; const data: array of Byte): longbool; extdecl;
{$endif}
begin
  handleExceptionBegin
  {$ifdef DARWIN}
  if dataSize >0 then
  begin
    try
      SetLength(tmpData, dataSize);
      Move(data[0], tmpData[0], dataSize);
      Result := TCefImageRef.UnWrap(TObj).AddJpeg(scaleFactor^, @tmpData[0], dataSize);
    finally
      SetLength(tmpData, 0);
    end;
  end;
  {$else}
  Result := TCefImageRef.UnWrap(TObj).AddJpeg(scaleFactor^, @data[0], Length(data));
  {$endif}
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

