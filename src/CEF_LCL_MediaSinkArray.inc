//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaSinkArray_Get(const AObj: TCefMediaSinkArray; index: Integer; out Result: ICefMediaSink); extdecl;
begin
  handleExceptionBegin
  Result := AObj[index];
  handleExceptionEnd
end;

exports
  MediaSinkArray_Get;
