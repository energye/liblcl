
//----------------------------------------
// The code is automatically generated by the GenlibLcl tool.
// Copyright © yanghy. All Rights Reserved.
// 
// Licensed under Lazarus.modifiedLGPL
//
//----------------------------------------

function ListColumns_Create(AOwner: TCustomListView): TListColumns; extdecl;
begin
  handleExceptionBegin
  Result :=  TListColumns.Create(AOwner);
  handleExceptionEnd
end;

procedure ListColumns_Free(AObj: TListColumns); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_Add(AObj: TListColumns): TListColumn; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Add;
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_Owner(AObj: TListColumns): TCustomListView; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Owner;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure ListColumns_Assign(AObj: TListColumns; Source: TPersistent); extdecl;
begin
  handleExceptionBegin
  AObj.Assign(Source);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure ListColumns_BeginUpdate(AObj: TListColumns); extdecl;
begin
  handleExceptionBegin
  AObj.BeginUpdate;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure ListColumns_Clear(AObj: TListColumns); extdecl;
begin
  handleExceptionBegin
  AObj.Clear;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure ListColumns_Delete(AObj: TListColumns; Index: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Delete(Index);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure ListColumns_EndUpdate(AObj: TListColumns); extdecl;
begin
  handleExceptionBegin
  AObj.EndUpdate;
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_FindItemID(AObj: TListColumns; ID: Integer): TCollectionItem; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.FindItemID(ID);
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_GetNamePath(AObj: TListColumns): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.GetNamePath);
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_Insert(AObj: TListColumns; Index: Integer): TCollectionItem; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Insert(Index);
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_ClassType(AObj: TListColumns): TClass; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_ClassName(AObj: TListColumns): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  ToPChar(AObj.ClassName);
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_InstanceSize(AObj: TListColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.InstanceSize;
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_InheritsFrom(AObj: TListColumns; AClass: TClass): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_Equals(AObj: TListColumns; Obj: TObject): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Equals(Obj);
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_GetHashCode(AObj: TListColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.GetHashCode;
  handleExceptionEnd
end;

//CLASSMETHOD:
function ListColumns_ToString(AObj: TListColumns): PChar; extdecl;
begin
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

function ListColumns_GetCount(AObj: TListColumns): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Count;
  handleExceptionEnd
end;

function ListColumns_GetItems(AObj: TListColumns; Index: Integer): TListColumn; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Items[Index];
  handleExceptionEnd
end;

procedure ListColumns_SetItems(AObj: TListColumns; Index: Integer; AValue: TListColumn); extdecl;
begin
  handleExceptionBegin
  AObj.Items[Index] := AValue;
  handleExceptionEnd
end;

function ListColumns_StaticClassType: TClass; extdecl;
begin
  Result := TListColumns;
end;

exports
  ListColumns_Create,
  ListColumns_Free,
  ListColumns_Add,
  ListColumns_Owner,
  ListColumns_Assign,
  ListColumns_BeginUpdate,
  ListColumns_Clear,
  ListColumns_Delete,
  ListColumns_EndUpdate,
  ListColumns_FindItemID,
  ListColumns_GetNamePath,
  ListColumns_Insert,
  ListColumns_ClassType,
  ListColumns_ClassName,
  ListColumns_InstanceSize,
  ListColumns_InheritsFrom,
  ListColumns_Equals,
  ListColumns_GetHashCode,
  ListColumns_ToString,
  ListColumns_GetCount,
  ListColumns_GetItems,
  ListColumns_SetItems,
  ListColumns_StaticClassType;

