
//----------------------------------------
// The code is automatically generated by the GenlibLcl tool.
// Copyright © yanghy. All Rights Reserved.
// 
// Licensed under Lazarus.modifiedLGPL
//
//----------------------------------------

//CLASSMETHOD:
function GridColumns_Add(AObj: TGridColumns): TGridColumn; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Add;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure GridColumns_Clear(AObj: TGridColumns); extdecl;
begin
  handleExceptionBegin
  AObj.Clear;
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_RealIndex(AObj: TGridColumns; Index: Integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.RealIndex(Index);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_IndexOf(AObj: TGridColumns; Column: TGridColumn): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.IndexOf(Column);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_IsDefault(AObj: TGridColumns): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.IsDefault;
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_HasIndex(AObj: TGridColumns; Index: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.HasIndex(Index);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_Owner(AObj: TGridColumns): TPersistent; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Owner;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure GridColumns_Assign(AObj: TGridColumns; Source: TPersistent); extdecl;
begin
  handleExceptionBegin
  AObj.Assign(Source);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure GridColumns_BeginUpdate(AObj: TGridColumns); extdecl;
begin
  handleExceptionBegin
  AObj.BeginUpdate;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure GridColumns_Delete(AObj: TGridColumns; Index: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Delete(Index);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure GridColumns_EndUpdate(AObj: TGridColumns); extdecl;
begin
  handleExceptionBegin
  AObj.EndUpdate;
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_FindItemID(AObj: TGridColumns; ID: Integer): TCollectionItem; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.FindItemID(ID);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_GetNamePath(AObj: TGridColumns): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.GetNamePath);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_Insert(AObj: TGridColumns; Index: Integer): TCollectionItem; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Insert(Index);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_ClassType(AObj: TGridColumns): TClass; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_ClassName(AObj: TGridColumns): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  ToPChar(AObj.ClassName);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_InstanceSize(AObj: TGridColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.InstanceSize;
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_InheritsFrom(AObj: TGridColumns; AClass: TClass): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_Equals(AObj: TGridColumns; Obj: TObject): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Equals(Obj);
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_GetHashCode(AObj: TGridColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.GetHashCode;
  handleExceptionEnd
end;

//CLASSMETHOD:
function GridColumns_ToString(AObj: TGridColumns): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

function GridColumns_GetGrid(AObj: TGridColumns): TCustomGrid; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Grid;
  handleExceptionEnd
end;

function GridColumns_GetVisibleCount(AObj: TGridColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.VisibleCount;
  handleExceptionEnd
end;

function GridColumns_GetEnabled(AObj: TGridColumns): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Enabled;
  handleExceptionEnd
end;

function GridColumns_GetCount(AObj: TGridColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Count;
  handleExceptionEnd
end;

function GridColumns_GetItems(AObj: TGridColumns; Index: Integer): TGridColumn; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Items[Index];
  handleExceptionEnd
end;

procedure GridColumns_SetItems(AObj: TGridColumns; Index: Integer; AValue: TGridColumn); extdecl;
begin
  handleExceptionBegin
  AObj.Items[Index] := AValue;
  handleExceptionEnd
end;

function GridColumns_StaticClassType: TClass; extdecl;
begin
  Result := TGridColumns;
end;

exports
  GridColumns_Add,
  GridColumns_Clear,
  GridColumns_RealIndex,
  GridColumns_IndexOf,
  GridColumns_IsDefault,
  GridColumns_HasIndex,
  GridColumns_Owner,
  GridColumns_Assign,
  GridColumns_BeginUpdate,
  GridColumns_Delete,
  GridColumns_EndUpdate,
  GridColumns_FindItemID,
  GridColumns_GetNamePath,
  GridColumns_Insert,
  GridColumns_ClassType,
  GridColumns_ClassName,
  GridColumns_InstanceSize,
  GridColumns_InheritsFrom,
  GridColumns_Equals,
  GridColumns_GetHashCode,
  GridColumns_ToString,
  GridColumns_GetGrid,
  GridColumns_GetVisibleCount,
  GridColumns_GetEnabled,
  GridColumns_GetCount,
  GridColumns_GetItems,
  GridColumns_SetItems,
  GridColumns_StaticClassType;

