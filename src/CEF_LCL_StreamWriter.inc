//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefStreamWriterRef_UnWrap(const data: Pointer; var Result: ICefStreamWriter); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamWriterRef.UnWrap(data);
  handleExceptionEnd
end;

procedure CefStreamWriterRef_CreateForFile(const fileName: PChar; var Result: ICefStreamWriter); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamWriterRef.CreateForFile(PCharToUStr(fileName));
  handleExceptionEnd
end;

procedure CefStreamWriterRef_CreateForHandler(const handler: ICefWriteHandler; var Result: ICefStreamWriter); extdecl;
begin
  handleExceptionBegin
  Result := TCefStreamWriterRef.CreateForHandler(handler);
  handleExceptionEnd
end;

function CefStreamWriter_Write(const TObj: ICefStreamWriter; ptr: Pointer; size, n: NativeUInt): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TObj.write(ptr, size, n);
  handleExceptionEnd
end;

function CefStreamWriter_Seek(const TObj: ICefStreamWriter; offset: Int64; whence: Integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Seek(offset, whence);
  handleExceptionEnd
end;

procedure CefStreamWriter_Tell(const TObj: ICefStreamWriter; var Result: Int64); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Tell;
  handleExceptionEnd
end;

function CefStreamWriter_Flush(const TObj: ICefStreamWriter): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Flush;
  handleExceptionEnd
end;

function CefStreamWriter_MayBlock(const TObj: ICefStreamWriter): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.MayBlock;
  handleExceptionEnd
end;

exports
  CefStreamWriterRef_UnWrap,
  CefStreamWriterRef_CreateForFile,
  CefStreamWriterRef_CreateForHandler,
  CefStreamWriter_Write,
  CefStreamWriter_Seek,
  CefStreamWriter_Tell,
  CefStreamWriter_Flush,
  CefStreamWriter_MayBlock;