//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CEFVersion: PChar; extdecl;
begin
  Result := PChar('1.109.18');
end;

function LibBuildVersion: PChar; extdecl;
begin
  Result := PChar('2.2.4');
end;

// CEF GoForm
procedure CEF_AddGoForm(BrowserId: Integer; GoForm: TGoForm); extdecl;
begin
  handleExceptionBegin
  TBrowserWindowClass.Add(BrowserId, GoForm);
  handleExceptionEnd
end;

procedure CEF_RemoveGoForm(BrowserId: Integer); extdecl;
begin
  handleExceptionBegin
  TBrowserWindowClass.Remove(BrowserId);
  handleExceptionEnd
end;

function CEF_Win_CreateRectRgn(X1, Y1, X2, Y2 : Integer): HRGN; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := CreateRectRgn(X1, Y1, X2, Y2);
  {$endif}
end;

function CEF_Win_SetRectRgn(aRGN: HRGN; X1, Y1, X2, Y2 : Integer): Longbool; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := SetRectRgn(aRGN, X1, Y1, X2, Y2);
  {$endif}
end;

function CEF_Win_DeleteObject(aRGN: HRGN): Longbool; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := DeleteObject(aRGN);
  {$endif}
end;

function CEF_Win_CombineRgn(Dest, Src1, Src2 : HRGN; fnCombineMode : Longint): Longint; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := CombineRgn(Dest, Src1, Src2, fnCombineMode);
  {$endif}
end;

function CEF_Win_PtInRegion(RGN: HRGN; X, Y: Integer): Longbool; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := PtInRegion(RGN, X, Y);
  {$endif}
end;

procedure CEF_Win_SetDraggableRegions(draggable_region: HRGN; regionsCount: NativeUInt; const regions: TCefDraggableRegionArray); extdecl;
var
  region: HRGN;
  idx, count: Integer;
  dragRegion: TCefDraggableRegion;
begin
  {$ifdef MSWINDOWS}
  //region = ::CreateRectRgn(it->bounds.x, it->bounds.y, it->bounds.x + it->bounds.width, it->bounds.y + it->bounds.height);
  SetRectRgn(draggable_region, 0, 0, 0, 0);
  count := Integer(regionsCount);
  for idx := 0 to count do
  begin
    dragRegion := regions[idx];
    region := CreateRectRgn(dragRegion.bounds.x, dragRegion.bounds.y, dragRegion.bounds.x + dragRegion.bounds.width, dragRegion.bounds.y + dragRegion.bounds.height);
    if dragRegion.draggable = 1 then
    begin
        CombineRgn(draggable_region, draggable_region, region, RGN_OR);
    end
    else
    begin
        CombineRgn(draggable_region, draggable_region, region, RGN_DIFF);
    end;
    DeleteObject(region);
  end;
  {$endif}
end;

function CEF_Win_ScreenToClient(hWnd : HWND; var P : TPoint): Longint; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := ScreenToClient(hWnd, p);
  {$endif}
end;

function CEF_Win_ClientToScreen(hWnd : HWND; var P : TPoint): Longbool; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := ClientToScreen(hWnd, p);
  {$endif}
end;

function CEF_Win_DefWindowProc(hWnd: HWND; Msg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := DefWindowProc(hWnd, Msg, wParam, lParam);
  //WriteLn('DefWindowProc ', Msg, ' ', wParam, ' ', lParam, ' Result ', Result);
  {$endif}
end;

function CEF_Win_DefSubclassProc(hWnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := DefSubclassProc(hWnd, uMsg, wParam, lParam);
  {$endif}
end;

function CEF_Win_CreateRoundRectRgn(_para1, _para2, _para3, _para4, _para5, _para6: longint):HRGN; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := CreateRoundRectRgn(_para1, _para2, _para3, _para4, _para5, _para6);
  {$endif}
end;

function CEF_Win_SetWindowRgn(hWnd: HWND; hRgn: HRGN; bRedraw: Longbool):longint; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := SetWindowRgn(hWnd, hRgn, WINBOOL(bRedraw));
  {$endif}
end;

function CEF_Win_SetCursor(hCursor: HCursor): HCURSOR; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := SetCursor(hCursor);
  {$endif}
end;

function CEF_Win_LoadCursor(hInstance: THandle; lpCursorName: Integer): HCursor; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := LoadCursor(hInstance, MakeIntResource(lpCursorName));
  {$endif}
end;

procedure CEF_Win_OnPaint(hWnd : HWND);
var
  ps: TPaintStruct;
begin
  {$ifdef MSWINDOWS}
  BeginPaint(hWnd, ps);
  EndPaint(hWnd, ps);
  {$endif}
end;

exports
  CEFVersion,
  LibBuildVersion,
  { ====  go from begin ==== }
  CEF_AddGoForm,
  CEF_RemoveGoForm,
  { ====  go from end ==== }
  CEF_Win_CreateRectRgn,
  CEF_Win_SetRectRgn,
  CEF_Win_DeleteObject,
  CEF_Win_CombineRgn,
  CEF_Win_SetDraggableRegions,
  CEF_Win_PtInRegion,
  CEF_Win_ScreenToClient,
  CEF_Win_ClientToScreen,
  CEF_Win_DefWindowProc,
  CEF_Win_DefSubclassProc,
  CEF_Win_CreateRoundRectRgn,
  CEF_Win_SetWindowRgn,
  CEF_Win_SetCursor,
  CEF_Win_LoadCursor,
  CEF_Win_OnPaint
;
