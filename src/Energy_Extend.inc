//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function Ext_Panel_GetBevelColor(AObj: TPanel): TColor; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.BevelColor;
  handleExceptionEnd
end;

procedure Ext_Panel_SetBevelColor(AObj: TPanel; AValue: TColor); extdecl;
begin
  handleExceptionBegin
  AObj.BevelColor := AValue;
  handleExceptionEnd
end;

exports
  Ext_Panel_GetBevelColor,
  Ext_Panel_SetBevelColor
;
