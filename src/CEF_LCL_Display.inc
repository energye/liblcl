//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFDisplayRef_Primary(var Result: ICefDisplay) ; extdecl;
begin
  Result := TCefDisplayRef.Primary();
end;

procedure CEFDisplayRef_NearestPoint(const point: TCefPoint; input_pixel_coords: LongBool; var Result: ICefDisplay); extdecl;
begin
  Result := TCefDisplayRef.NearestPoint(point, input_pixel_coords);
end;

procedure CEFDisplayRef_MatchingBounds(const bounds: TCefRect; input_pixel_coords: LongBool; var Result: ICefDisplay); extdecl;
begin
  Result := TCefDisplayRef.MatchingBounds(bounds, input_pixel_coords);
end;

function CEFDisplayRef_GetCount(): NativeUInt; extdecl;
begin
  Result := TCefDisplayRef.GetCount();
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
end;

procedure CEFDisplayRef_Get(const aDisplayArray : TCefDisplayArray; index: NativeUInt; var Result: ICefDisplay); extdecl;
var
  len: Integer;
begin
  Result := nil;
  len := Length(aDisplayArray);
  if (index < len) then
  begin
    Result := aDisplayArray[index];
  end;
end;

procedure CEFDisplayRef_ScreenPointToPixels(const aScreenPoint : TPoint; var Result: TPoint); extdecl;
begin
end;

procedure CEFDisplayRef_ScreenPointFromPixels(const aPixelsPoint : TPoint; var Result: TPoint); extdecl;
begin
end;

procedure CEFDisplayRef_ScreenRectToPixels(const aScreenRect : TRect; var Result: TRect); extdecl;
begin
end;

procedure CEFDisplayRef_ScreenRectFromPixels(const aPixelsRect : TRect; var Result: TRect); extdecl;
begin
end;

procedure CEFDisplay_ID(const ADisplay: ICefDisplay; var Result: int64) ; extdecl;
begin
  Result := ADisplay.ID;
end;

procedure CEFDisplay_DeviceScaleFactor(const ADisplay: ICefDisplay; var Result: Single) ; extdecl;
begin
  Result := ADisplay.DeviceScaleFactor;
end;

function CEFDisplay_Rotation(const ADisplay: ICefDisplay): Integer ; extdecl;
begin
  Result := ADisplay.Rotation;
end;

procedure CEFDisplay_Bounds(const ADisplay: ICefDisplay; var Result: TCefRect); extdecl;
begin
  Result := ADisplay.Bounds;
end;

procedure CEFDisplay_WorkArea(const ADisplay: ICefDisplay; var Result: TCefRect); extdecl;
begin
  Result := ADisplay.WorkArea;
end;


exports
  CEFDisplayRef_Primary,
  CEFDisplayRef_NearestPoint,
  CEFDisplayRef_MatchingBounds,
  CEFDisplayRef_GetCount,
  CEFDisplayRef_GetAlls,
  CEFDisplayRef_Get,
  CEFDisplayRef_ScreenPointToPixels,
  CEFDisplayRef_ScreenPointFromPixels,
  CEFDisplayRef_ScreenRectToPixels,
  CEFDisplayRef_ScreenRectFromPixels,
  CEFDisplay_ID,
  CEFDisplay_DeviceScaleFactor,
  CEFDisplay_Rotation,
  CEFDisplay_Bounds,
  CEFDisplay_WorkArea;
