//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//property
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
    //property
    CEFDisplay_ID,
    CEFDisplay_DeviceScaleFactor,
    CEFDisplay_Rotation,
    CEFDisplay_Bounds,
    CEFDisplay_WorkArea
;
