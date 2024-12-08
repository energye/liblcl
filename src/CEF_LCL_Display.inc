//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFDisplayRef_Primary(var Result: ICefDisplay) ; extdecl;
begin
  handleExceptionBegin
  Result := TCefDisplayRef.Primary();
  handleExceptionEnd
end;

procedure CEFDisplayRef_NearestPoint(var point: TCefPoint; input_pixel_coords: LongBool; var Result: ICefDisplay); extdecl;
begin
  handleExceptionBegin
  Result := TCefDisplayRef.NearestPoint(point, input_pixel_coords);
  handleExceptionEnd
end;

procedure CEFDisplayRef_MatchingBounds(var bounds: TCefRect; input_pixel_coords: LongBool; var Result: ICefDisplay); extdecl;
begin
  handleExceptionBegin
  Result := TCefDisplayRef.MatchingBounds(bounds, input_pixel_coords);
  handleExceptionEnd
end;

function CEFDisplayRef_GetCount(): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := TCefDisplayRef.GetCount();
  handleExceptionEnd
end;

//function CEFDisplayRef_GetAlls(var DisplayArray : TCefDisplayArray): LongBool; extdecl;
//var
//  aDisplayArray : TCefDisplayArray;
//begin
//  Result := TCefDisplayRef.GetAlls(aDisplayArray);
//  DisplayArray := aDisplayArray;
//end;

function CEFDisplayRef_GetAlls(var DisplayArray : TCefDisplayArray): LongBool; extdecl;
type
  TDisplayArray = array of PCefDisplay;
var
  i, displaysCount: nativeuint;
  displays: PPCefDisplay;
  TempSize: integer;
  aDisplayArray : TCefDisplayArray;
begin
  handleExceptionBegin
  Result := False;
  displaysCount := TCefDisplayRef.GetCount;
  if (displaysCount > 0) then
    try
      TempSize := SizeOf(TCefDisplay) * displaysCount;
      GetMem(displays, TempSize);
      //FillChar(displays, TempSize, 0); // error
      cef_display_get_alls(@displaysCount, displays);
      SetLength(aDisplayArray, displaysCount);
      i := 0;
      while (i < displaysCount) do
        begin
          aDisplayArray[i] := TCefDisplayRef.UnWrap(TDisplayArray(displays)[i]);
          inc(i);
        end;
      DisplayArray := aDisplayArray;
      Result := True;
    finally
      FreeMem(displays);
    end;
  handleExceptionEnd
end;

procedure CEFDisplayRef_Get(const aDisplayArray : TCefDisplayArray; index: NativeUInt; var Result: ICefDisplay); extdecl;
var
  len: Integer;
begin
  Result := nil;
  handleExceptionBegin
  len := Length(aDisplayArray);
  if (index < len) then
  begin
    Result := aDisplayArray[index];
  end;
  handleExceptionEnd
end;

procedure CEFDisplay_ID(const ADisplay: ICefDisplay; var Result: int64) ; extdecl;
begin
  handleExceptionBegin
  Result := ADisplay.ID;
  handleExceptionEnd
end;

procedure CEFDisplay_DeviceScaleFactor(const ADisplay: ICefDisplay; var Result: Single) ; extdecl;
begin
  handleExceptionBegin
  Result := ADisplay.DeviceScaleFactor;
  handleExceptionEnd
end;

function CEFDisplay_Rotation(const ADisplay: ICefDisplay): Integer ; extdecl;
begin
  handleExceptionBegin
  Result := ADisplay.Rotation;
  handleExceptionEnd
end;

procedure CEFDisplay_Bounds(const ADisplay: ICefDisplay; var Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := ADisplay.Bounds;
  handleExceptionEnd
end;

procedure CEFDisplay_WorkArea(const ADisplay: ICefDisplay; var Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := ADisplay.WorkArea;
  handleExceptionEnd
end;


exports
  CEFDisplayRef_Primary,
  CEFDisplayRef_NearestPoint,
  CEFDisplayRef_MatchingBounds,
  CEFDisplayRef_GetCount,
  CEFDisplayRef_GetAlls,
  CEFDisplayRef_Get,
  CEFDisplay_ID,
  CEFDisplay_DeviceScaleFactor,
  CEFDisplay_Rotation,
  CEFDisplay_Bounds,
  CEFDisplay_WorkArea;
