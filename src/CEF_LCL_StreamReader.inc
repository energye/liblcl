//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefStreamReaderRef_UnWrap(const data: Pointer; var Result: ICefStreamReader); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamReaderRef.UnWrap(data);
  handleExceptionEnd
end;

procedure CefStreamReaderRef_CreateForFile(const filename: PChar; var Result: ICefStreamReader); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamReaderRef.CreateForFile(PCharToUStr(filename));
  handleExceptionEnd
end;

procedure CefStreamReaderRef_CreateForStream(const stream: TSTream; owned: Boolean; var Result: ICefStreamReader); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamReaderRef.CreateForStream(stream, owned);
  handleExceptionEnd
end;

procedure CefStreamReaderRef_CreateForData(data: Pointer; size: NativeUInt; var Result: ICefStreamReader); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamReaderRef.CreateForData(data, size);
  handleExceptionEnd
end;

function CefStreamReader_Read(const TObj: ICefStreamReader; ptr: Pointer; size, n: NativeUInt): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Read(ptr, size, n);
  handleExceptionEnd
end;

function CefStreamReader_Seek(const TObj: ICefStreamReader; offset: Int64; whence: Integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Seek(offset, whence);
  handleExceptionEnd
end;

procedure CefStreamReader_Tell(const TObj: ICefStreamReader; var Result: Int64); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Tell;
  handleExceptionEnd
end;

function CefStreamReader_Eof(const TObj: ICefStreamReader): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Eof;
  handleExceptionEnd
end;

function CefStreamReader_MayBlock(const TObj: ICefStreamReader): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.MayBlock;
  handleExceptionEnd
end;

exports
    CefStreamReaderRef_UnWrap,
    CefStreamReaderRef_CreateForFile,
    CefStreamReaderRef_CreateForStream,
    CefStreamReaderRef_CreateForData,
    CefStreamReader_Read,
    CefStreamReader_Seek,
    CefStreamReader_Tell,
    CefStreamReader_Eof,
    CefStreamReader_MayBlock
;
