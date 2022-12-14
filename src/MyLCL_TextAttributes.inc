
//----------------------------------------
// The code is automatically generated by the GenlibLcl tool.
// Copyright © yanghy. All Rights Reserved.
// 
// Licensed under Lazarus.modifiedLGPL
//
//----------------------------------------

//CLASSMETHOD:
procedure TextAttributes_Assign(AObj: TTextAttributes; Source: TPersistent); extdecl;
begin
  handleExceptionBegin
  AObj.Assign(Source);
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_GetNamePath(AObj: TTextAttributes): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.GetNamePath);
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_ClassType(AObj: TTextAttributes): TClass; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_ClassName(AObj: TTextAttributes): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  ToPChar(AObj.ClassName);
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_InstanceSize(AObj: TTextAttributes): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.InstanceSize;
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_InheritsFrom(AObj: TTextAttributes; AClass: TClass): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_Equals(AObj: TTextAttributes; Obj: TObject): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Equals(Obj);
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_GetHashCode(AObj: TTextAttributes): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.GetHashCode;
  handleExceptionEnd
end;

//CLASSMETHOD:
function TextAttributes_ToString(AObj: TTextAttributes): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

function TextAttributes_GetCharset(AObj: TTextAttributes): TFontCharset; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Charset;
  handleExceptionEnd
end;

procedure TextAttributes_SetCharset(AObj: TTextAttributes; AValue: TFontCharset); extdecl;
begin
  handleExceptionBegin
  AObj.Charset := AValue;
  handleExceptionEnd
end;

function TextAttributes_GetColor(AObj: TTextAttributes): TColor; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Color;
  handleExceptionEnd
end;

procedure TextAttributes_SetColor(AObj: TTextAttributes; AValue: TColor); extdecl;
begin
  handleExceptionBegin
  AObj.Color := AValue;
  handleExceptionEnd
end;

function TextAttributes_GetName(AObj: TTextAttributes): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.Name);
  handleExceptionEnd
end;

procedure TextAttributes_SetName(AObj: TTextAttributes; AValue: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Name := AValue;
  handleExceptionEnd
end;

function TextAttributes_GetPitch(AObj: TTextAttributes): TFontPitch; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Pitch;
  handleExceptionEnd
end;

procedure TextAttributes_SetPitch(AObj: TTextAttributes; AValue: TFontPitch); extdecl;
begin
  handleExceptionBegin
  AObj.Pitch := AValue;
  handleExceptionEnd
end;

function TextAttributes_GetSize(AObj: TTextAttributes): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Size;
  handleExceptionEnd
end;

procedure TextAttributes_SetSize(AObj: TTextAttributes; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Size := AValue;
  handleExceptionEnd
end;

function TextAttributes_GetStyle(AObj: TTextAttributes): TFontStyles; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Style;
  handleExceptionEnd
end;

procedure TextAttributes_SetStyle(AObj: TTextAttributes; AValue: TFontStyles); extdecl;
begin
  handleExceptionBegin
  AObj.Style := AValue;
  handleExceptionEnd
end;

function TextAttributes_GetHeight(AObj: TTextAttributes): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Height;
  handleExceptionEnd
end;

procedure TextAttributes_SetHeight(AObj: TTextAttributes; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Height := AValue;
  handleExceptionEnd
end;

function TextAttributes_StaticClassType: TClass; extdecl;
begin
  Result := TTextAttributes;
end;

exports
  TextAttributes_Assign,
  TextAttributes_GetNamePath,
  TextAttributes_ClassType,
  TextAttributes_ClassName,
  TextAttributes_InstanceSize,
  TextAttributes_InheritsFrom,
  TextAttributes_Equals,
  TextAttributes_GetHashCode,
  TextAttributes_ToString,
  TextAttributes_GetCharset,
  TextAttributes_SetCharset,
  TextAttributes_GetColor,
  TextAttributes_SetColor,
  TextAttributes_GetName,
  TextAttributes_SetName,
  TextAttributes_GetPitch,
  TextAttributes_SetPitch,
  TextAttributes_GetSize,
  TextAttributes_SetSize,
  TextAttributes_GetStyle,
  TextAttributes_SetStyle,
  TextAttributes_GetHeight,
  TextAttributes_SetHeight,
  TextAttributes_StaticClassType;

