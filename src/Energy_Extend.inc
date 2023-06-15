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

function Ext_ReadStringProperty(Sender: TObject): PChar;
var
  LTypeData: PTypeData;
  PropCount, I, Count: smallint;
  LPropInfo: PPropInfo;
  PropList: PPropList;
  Kind, Prop, Value: string;
  Ret: string;
begin
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
end;

procedure Ext_NIL();
begin
    //handleExceptionBegin
    //TODO 没搞懂，要加一个空函数编译才不报错
    //handleExceptionEnd
end;


exports
  Ext_Panel_GetBevelColor,
  Ext_Panel_SetBevelColor,
  Ext_ReadStringProperty
;