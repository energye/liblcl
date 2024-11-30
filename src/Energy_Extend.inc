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

function Ext_ReadStringProperty(Sender: TObject): PChar;  extdecl;
var
  LTypeData: PTypeData;
  PropCount, I, Count: smallint;
  LPropInfo: PPropInfo;
  PropList: PPropList;
  Kind, Prop, Value: string;
  Ret: string;
begin
  handleExceptionBegin
  LTypeData := GetTypeData(Sender.ClassInfo);
  PropCount := LTypeData^.PropCount;
  GetPropList(Sender.ClassInfo, PropList);
  Count := 0;
  Ret := '';
  for I := 0 to PropCount - 1 do
  begin
    LPropInfo := PropList^[I];
    case LPropInfo^.PropType^.Kind of
      tkClass:
      begin
        //Kind := '0';//class
        continue;
      end;
      tkMethod: Kind := '1';//method
      tkSet: Kind := '2';//set
      tkEnumeration: Kind := '3';//enum
      else
        Kind := '4';//field
    end;
    if Count > 0 then
    begin
      Ret += Chr(10);// \n
    end;
    Prop := Kind + '-' + LPropInfo^.Name + '-' + LPropInfo^.PropType^.Name;
    Value := GetPropValue(Sender, LPropInfo^.Name, True);
    Prop := Prop + '-' + Value;
    Ret += Prop;
    Inc(Count);
  end;
  FreeMem(PropList);
  Result := PChar(Ret);
  handleExceptionEnd
end;


procedure Ext_Form_Activate(AObj: TGoForm); extdecl;
begin
  handleExceptionBegin
  AObj.GoActivate;
  handleExceptionEnd
end;

procedure Ext_Form_Deactivate(AObj: TGoForm); extdecl;
begin
  handleExceptionBegin
  AObj.GoDeactivate();
  handleExceptionEnd
end;

function Ext_Assigned(Ptr: Pointer): LongBool; extdecl;
begin
  Result := Assigned(Ptr);
end;

exports
  Ext_Panel_GetBevelColor,
  Ext_Panel_SetBevelColor,
  Ext_ReadStringProperty,
  Ext_Form_Activate,
  Ext_Form_Deactivate,
  Ext_Assigned
;
