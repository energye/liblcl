//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CEF_Win_CreateRectRgn(X1, Y1, X2, Y2 : Integer): HRGN; extdecl;
begin
  Result := CreateRectRgn(X1, Y1, X2, Y2);
end;

function CEF_Win_SetRectRgn(aRGN: HRGN; X1, Y1, X2, Y2 : Integer): Longbool; extdecl;
begin
  Result := SetRectRgn(aRGN, X1, Y1, X2, Y2);
end;

function CEF_Win_DeleteObject(aRGN: HRGN): Longbool; extdecl;
begin
  Result := DeleteObject(aRGN);
end;

function CEF_Win_CombineRgn(Dest, Src1, Src2 : HRGN; fnCombineMode : Longint): Longint; extdecl;
begin
  Result := CombineRgn(Dest, Src1, Src2, fnCombineMode);
end;

function CEF_Win_PtInRegion(RGN: HRGN; X, Y: Integer): Longbool; extdecl;
begin
  Result := PtInRegion(RGN, X, Y);
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
  Result := ScreenToClient(hWnd, p);
end;

function CEF_Win_ClientToScreen(hWnd : HWND; var P : TPoint): Longbool; extdecl;
begin
  Result := ClientToScreen(hWnd, p);
end;

function CEF_Win_DefWindowProc(hWnd: HWND; Msg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := DefWindowProc(hWnd, Msg, wParam, lParam);
  {$else}
  Result := 0;
  {$endif}
end;

function CEF_Win_DefSubclassProc(hWnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; extdecl;
begin
  {$ifdef MSWINDOWS}
  Result := DefSubclassProc(hWnd, uMsg, wParam, lParam);
  {$else}
  Result := 0;
  {$endif}
end;

function CEF_Win_CreateRoundRectRgn(_para1, _para2, _para3, _para4, _para5, _para6: longint): HRGN; extdecl;
begin
  Result := CreateRoundRectRgn(_para1, _para2, _para3, _para4, _para5, _para6);
end;

function CEF_Win_SetWindowRgn(hWnd: HWND; hRgn: HRGN; bRedraw: Longbool):longint; extdecl;
begin
  //Result := SetWindowRgn(hWnd, hRgn, {$ifdef MSWINDOWS}WINBOOL(bRedraw){$else}bRedraw{$endif});
  Result := SetWindowRgn(hWnd, hRgn, bRedraw);
end;

function CEF_Win_SetCursor(hCursor: HCursor): HCURSOR; extdecl;
begin
  Result := SetCursor(hCursor);
end;

function CEF_Win_LoadCursor(hInstance: THandle; lpCursorName: PChar): HCursor; extdecl;
begin
  Result := LoadCursor(hInstance, lpCursorName);
end;

procedure CEF_Win_OnPaint(hWnd : HWND); extdecl;
var
  ps: TPaintStruct;
begin
  BeginPaint(hWnd, ps);
  EndPaint(hWnd, ps);
end;

function CEF_Win_EndPaint(Handle : hwnd; var PS : TPaintStruct): Integer; extdecl;
begin
  Result := EndPaint(Handle, PS);
end;

function CEF_Win_BeginPaint(Handle : hwnd; var PS : TPaintStruct): HDC; extdecl;
begin
  Result := BeginPaint(Handle, PS);
end;

function CEF_Win_Arc(DC: HDC; Left, Top, Right, Bottom, Angle16Deg, Angle16DegLength: Integer): LongBool;  extdecl;
begin
  Result := Arc(DC, Left, Top, Right, Bottom, Angle16Deg, Angle16DegLength);
end;

function CEF_Win_AngleChord(DC: HDC; x1, y1, x2, y2, angle1, angle2 : Integer): LongBool;  extdecl;
begin
  Result := AngleChord(DC, x1, y1, x2, y2, angle1, angle2);
end;

function CEF_Win_CallNextHookEx(hhk : HHOOK; ncode : Integer; WParam: WParam; LParam: LParam) : Integer; extdecl;
begin
  Result := CallNextHookEx(hhk, ncode, WParam, LParam);
end;

function CEF_Win_CallWindowProc(lpPrevWndFunc : TFarProc; Handle : HWND; Msg : UINT; WParam: WParam; LParam: LParam): Integer; extdecl;
begin
  Result := CallWindowProc(lpPrevWndFunc, Handle, Msg, WParam, LParam);
end;

function CEF_Win_BitBlt(DestDC: HDC; X, Y, Width, Height: Integer; SrcDC: HDC; XSrc, YSrc: Integer; Rop: DWORD): LongBool; extdecl;
begin
  Result := BitBlt(DestDC,  X, Y, Width, Height, SrcDC, XSrc, YSrc, Rop);
end;

function  CEF_Win_CreateBitmap(Width, Height: Integer; Planes, BitCount: Longint; BitmapBits: Pointer): HBITMAP; extdecl;
begin
  Result := CreateBitmap(Width, Height, Planes, BitCount, BitmapBits);
end;

function  CEF_Win_CreateBrushIndirect(const LogBrush: TLogBrush): HBRUSH; extdecl;
begin
  Result := CreateBrushIndirect(LogBrush);
end;

function  CEF_Win_CreateBrushWithRadialGradient(const LogBrush: TLogRadialGradient): HBRUSH; extdecl;
begin
  Result := CreateBrushWithRadialGradient(LogBrush);
end;

function  CEF_Win_CreateCaret(Handle: HWND; Bitmap: HBITMAP; width, Height: Integer):  LongBool; extdecl;
begin
  Result := CreateCaret(Handle, Bitmap, width, Height);
end;

function  CEF_Win_CreateCompatibleBitmap(DC: HDC; Width, Height: Integer): HBITMAP; extdecl;
begin
  Result := CreateCompatibleBitmap(DC, Width, Height);
end;

function  CEF_Win_CreateCompatibleDC(DC: HDC): HDC; extdecl;
begin
  Result := CreateCompatibleDC(DC);
end;

function  CEF_Win_CreateDIBitmap(DC: HDC; var InfoHeader: TBitmapInfoHeader; dwUsage: DWORD; InitBits: PChar; var InitInfo: TBitmapInfo; wUsage: UINT): HBITMAP; extdecl;
begin
  Result := CreateDIBitmap(DC, InfoHeader, dwUsage, InitBits, InitInfo, wUsage);
end;

function  CEF_Win_CreateDIBSection(DC: HDC; const BitmapInfo: tagBitmapInfo; Usage: UINT; var Bits: Pointer; SectionHandle: THandle; Offset: DWORD): HBITMAP; extdecl;
begin
  Result := CreateDIBSection(DC, BitmapInfo, Usage, Bits, SectionHandle, Offset);
end;

function  CEF_Win_CreateEllipticRgn(X1, Y1, X2, Y2: Integer): HRGN; extdecl;
begin
  Result := CreateEllipticRgn(X1, Y1, X2, Y2);
end;

function  CEF_Win_CreateFontIndirect(const LogFont: TLogFont): HFONT; extdecl;
begin
  Result := CreateFontIndirect(LogFont);
end;

function  CEF_Win_CreateFontIndirectEx(const LogFont: TLogFont; const LongFontName: PChar): HFONT; extdecl;
begin
  Result := CreateFontIndirectEx(LogFont, StrPas(LongFontName));
end;

function  CEF_Win_CreateIconIndirect(IconInfo: PIconInfo): HICON; extdecl;
begin
  Result := CreateIconIndirect(IconInfo);
end;

function  CEF_Win_CreatePalette(const LogPalette: TLogPalette): HPalette; extdecl;
begin
  Result := CreatePalette(LogPalette);
end;

function  CEF_Win_CreatePatternBrush(ABitmap: HBITMAP): HBRUSH; extdecl;
begin
  Result := CreatePatternBrush(ABitmap);
end;

function  CEF_Win_CreatePenIndirect(const LogPen: TLogPen): HPEN; extdecl;
begin
  Result := CreatePenIndirect(LogPen);
end;

function  CEF_Win_CreatePolygonRgn(Points: PPoint; NumPts: Integer; FillMode: integer): HRGN; extdecl;
begin
  Result := CreatePolygonRgn(Points, NumPts, FillMode);
end;

procedure CEF_Win_DeleteCriticalSection(var CritSection: TCriticalSection); extdecl;
begin
  DeleteCriticalSection(CritSection);
end;

function  CEF_Win_DeleteDC(hDC: HDC):  LongBool; extdecl;
begin
  Result := DeleteDC(hDC);
end;

function  CEF_Win_DestroyCaret(Handle : HWND):  LongBool; extdecl;
begin
  Result := DestroyCaret(Handle);
end;

function  CEF_Win_DestroyCursor(Handle: HCURSOR):  LongBool; extdecl;
begin
  Result := DestroyCursor(Handle);
end;

function  CEF_Win_DestroyIcon(Handle: HICON):  LongBool; extdecl;
begin
  Result := DestroyIcon(Handle);
end;

function  CEF_Win_DrawFrameControl(DC: HDC; const Rect : TRect; uType, uState : Cardinal) :  LongBool; extdecl;
begin
  Result := DrawFrameControl(DC, Rect, uType, uState);
end;

function  CEF_Win_DrawFocusRect(DC: HDC; const Rect: TRect):  LongBool; extdecl;
begin
  Result := DrawFocusRect(DC, Rect);
end;

function  CEF_Win_DrawEdge(DC: HDC; var Rect: TRect; edge: Cardinal; grfFlags: Cardinal):  LongBool; extdecl;
begin
  Result := DrawEdge(DC, Rect, edge, grfFlags);
end;

function  CEF_Win_DrawText(DC: HDC; Str: PChar; Count: Integer; var Rect: TRect; Flags: Cardinal): Integer; extdecl;
begin
  Result := DrawText(DC, Str, Count, Rect, Flags);
end;

function  CEF_Win_EnableScrollBar(Wnd: HWND; wSBflags, wArrows: Cardinal):  LongBool; extdecl;
begin
  Result := EnableScrollBar(Wnd, wSBflags, wArrows);
end;

function  CEF_Win_EnableWindow(hWnd: HWND; bEnable:  LongBool):  LongBool; extdecl;
begin
  Result := EnableWindow(hWnd, bEnable);
end;

procedure CEF_Win_EnterCriticalSection(var CritSection: TCriticalSection);  extdecl;
begin
  EnterCriticalSection(CritSection);
end;

function Internal_EnumDisplayMonitorsProc(hMonitor: HMONITOR; hdcMonitor: HDC; lprcMonitor: PRect; dwData: LPARAM): LongBool; {$ifdef WinCE}cdecl{$else}stdcall{$endif};
begin
  Result := WinApiCallback.EnumDisplayMonitorsProc(hMonitor, hdcMonitor, lprcMonitor, dwData);
end;

function  CEF_Win_EnumDisplayMonitors(hdc: HDC; lprcClip: PRect; callbackPtr: Pointer; dwData: LPARAM): LongBool; extdecl;
begin
  WinApiCallback.EnumDisplayMonitorsProcPtr := callbackPtr;
  Result := EnumDisplayMonitors(hdc, lprcClip, Internal_EnumDisplayMonitorsProc, dwData);
end;

function Internal_EnumFontFamiliesProc(var ELogFont: TEnumLogFont; var Metric: TNewTextMetric; FontType: longint; Data:LParam): longint; {$ifdef WinCE}cdecl{$else}stdcall{$endif};
begin
  Result := WinApiCallback.EnumFontFamiliesProc(ELogFont, Metric, FontType, Data);
end;

function  CEF_Win_EnumFontFamilies(DC: HDC; Family: Pchar; callbackPtr: Pointer; LParam:Lparam):longint; extdecl;
begin
  WinApiCallback.EnumFontFamiliesProcPtr := callbackPtr;
  Result := EnumFontFamilies(DC,Family, Internal_EnumFontFamiliesProc, LParam);
end;

function Internal_EnumFontFamiliesExProc(var ELogFont: TEnumLogFontEx; var Metric: TNewTextMetricEx; FontType: Longint; Data: LParam): Longint; {$ifdef WinCE}cdecl{$else}stdcall{$endif};
begin
  Result := WinApiCallback.EnumFontFamiliesExProc(ELogFont, Metric, FontType, Data);
end;

function  CEF_Win_EnumFontFamiliesEx(DC: HDC; lpLogFont: PLogFont; callbackPtr: Pointer; Lparam: LParam; Flags: dword): longint; extdecl;
begin
  WinApiCallback.EnumFontFamiliesExProcPtr := callbackPtr;
  Result := EnumFontFamiliesEx(DC,lpLogFont, Internal_EnumFontFamiliesExProc, Lparam, Flags);
end;

procedure CEF_Win_EnumDisplayMonitorsCallbackFree(); extdecl;
begin
  WinApiCallback.EnumDisplayMonitorsProcPtr := nil;
end;

procedure CEF_Win_EnumFontFamiliesCallbackFree(); extdecl;
begin
  WinApiCallback.EnumFontFamiliesProcPtr := nil;
end;

procedure CEF_Win_EnumFontFamiliesExCallbackFree(); extdecl;
begin
  WinApiCallback.EnumFontFamiliesExProcPtr := nil;
end;

function  CEF_Win_Ellipse(DC: HDC; x1, y1, x2, y2: Integer):  LongBool; extdecl;
begin
  Result := Ellipse(DC,x1, y1, x2, y2);
end;

function  CEF_Win_EqualRgn(Rgn1: HRGN; Rgn2: HRGN):  LongBool; extdecl;
begin
  Result := EqualRgn(Rgn1, Rgn2);
end;

function  CEF_Win_ExcludeClipRect(dc: hdc; Left, Top, Right, Bottom : Integer) : Integer; extdecl;
begin
  Result := ExcludeClipRect(dc, Left, Top, Right, Bottom);
end;

function  CEF_Win_ExtCreatePen(dwPenStyle, dwWidth: DWord; const lplb: TLogBrush; dwStyleCount: DWord; lpStyle: PDWord): HPEN; extdecl;
begin
  Result := ExtCreatePen(dwPenStyle, dwWidth, lplb, dwStyleCount, lpStyle);
end;

function  CEF_Win_ExtTextOut(DC: HDC; X, Y: Integer; Options: Longint; Rect: PRect; Str: PChar; Count: Longint; Dx: PInteger):  LongBool;  extdecl;
begin
  Result := ExtTextOut(DC,X , Y, Options, Rect, Str, Count, Dx);
end;

function  CEF_Win_ExtSelectClipRGN(dc: hdc; rgn : hrgn; Mode : Longint) : Integer;  extdecl;
begin
  Result := ExtSelectClipRGN(dc, rgn, Mode);
end;

function  CEF_Win_FillRect(DC: HDC; const Rect: TRect; Brush: HBRUSH):  LongBool; extdecl;
begin
  Result := FillRect(DC, Rect, Brush);
end;

function  CEF_Win_FillRgn(DC: HDC; RegionHnd: HRGN; hbr: HBRUSH): BOOL; extdecl;
begin
  Result := FillRgn(DC, RegionHnd, hbr);
end;

function  CEF_Win_FloodFill(DC: HDC; X, Y: Integer; Color: TGraphicsColor; FillStyle: TGraphicsFillStyle; Brush: HBRUSH):  LongBool; extdecl;
begin
  Result := FloodFill(DC, X, Y, Color, FillStyle, Brush);
end;

function  CEF_Win_FrameRect(DC: HDC; const ARect: TRect; hBr: HBRUSH): Integer; extdecl;
begin
  Result := FrameRect(DC, ARect, hBr);
end;

function  CEF_Win_GetActiveWindow : HWND; extdecl;
begin
  Result := GetActiveWindow();
end;

function  CEF_Win_GetBitmapBits(Bitmap: HBITMAP; Count: Longint;  Bits: Pointer): Longint; extdecl;
begin
  Result := GetBitmapBits(Bitmap,Count, Bits);
end;

function  CEF_Win_GetBkColor(DC: HDC): TColorRef; extdecl;
begin
  Result := GetBkColor(DC);
end;

function  CEF_Win_GetCapture : HWND; extdecl;
begin
  Result := GetCapture();
end;

function  CEF_Win_GetCaretPos(var lpPoint: TPoint):  LongBool; extdecl;
begin
  Result := GetCaretPos(lpPoint);
end;

function  CEF_Win_GetClientRect(handle : HWND; var Rect: TRect) :  LongBool; extdecl;
begin
  Result := GetClientRect(handle, Rect);
end;

function  CEF_Win_GetClipBox(DC : hDC; lpRect : PRect) : Longint; extdecl;
begin
  Result := GetClipBox(DC, lpRect);
end;

function  CEF_Win_GetClipRGN(DC : hDC; RGN : hRGN) : Longint; extdecl;
begin
  Result := GetClipRGN(DC, RGN);
end;

function  CEF_Win_GetCurrentObject(DC: HDC; uObjectType: UINT): HGDIOBJ; extdecl;
begin
  Result := GetCurrentObject(DC, uObjectType);
end;

function  CEF_Win_GetCursorPos(var lpPoint: TPoint):  LongBool; extdecl;
begin
  Result := GetCursorPos(lpPoint);
end;

function  CEF_Win_GetDC(hWnd: HWND): HDC; extdecl;
begin
  Result := GetDC(hWnd);
end;

function  CEF_Win_GetDeviceCaps(DC: HDC; Index: Integer): Integer; extdecl;
begin
  Result := GetDeviceCaps(DC, Index);
end;

function  CEF_Win_GetDIBits(DC: HDC; Bitmap: HBitmap; StartScan, NumScans: UINT; Bits: Pointer; var BitInfo: BitmapInfo; Usage: UINT): Integer; extdecl;
begin
  Result := GetDIBits(DC,Bitmap, StartScan, NumScans, Bits, BitInfo, Usage);
end;

function  CEF_Win_GetDoubleClickTime: UINT; extdecl;
begin
  Result := GetDoubleClickTime();
end;

function  CEF_Win_GetFocus: HWND; extdecl;
begin
  Result := GetFocus();
end;

function  CEF_Win_GetFontLanguageInfo(DC: HDC): DWord; extdecl;
begin
  Result := GetFontLanguageInfo(DC);
end;

function  CEF_Win_GetForegroundWindow: HWND; extdecl;
begin
  Result := GetForegroundWindow();
end;

function  CEF_Win_GetIconInfo(AIcon: HICON; AIconInfo: PIconInfo):  LongBool; extdecl;
begin
  Result := GetIconInfo(AIcon, AIconInfo);
end;

function  CEF_Win_GetKeyState(nVirtKey: Integer): Smallint; extdecl;
begin
  Result := GetKeyState(nVirtKey);
end;

function  CEF_Win_GetMapMode(DC: HDC): Integer; extdecl;
begin
  Result := GetMapMode(DC);
end;

function  CEF_Win_GetMonitorInfo(hMonitor: HMONITOR; lpmi: PMonitorInfo):  LongBool; extdecl;
begin
  Result := GetMonitorInfo(hMonitor, lpmi);
end;

function  CEF_Win_GetDpiForMonitor(hmonitor: HMONITOR; dpiType: TMonitorDpiType; out dpiX: UINT; out dpiY: UINT): HRESULT; extdecl;
begin
  Result := GetDpiForMonitor(hmonitor, dpiType, dpiX, dpiY);
end;

function  CEF_Win_GetObject(GDIObject: HGDIOBJ; BufSize: Integer; Buf: Pointer): Integer; extdecl;
begin
  Result := GetObject(GDIObject,BufSize, Buf);
end;

function  CEF_Win_GetParent(Handle : HWND): HWND; extdecl;
begin
  Result := GetParent(Handle);
end;

function  CEF_Win_GetProp(Handle : hwnd; Str : PChar): Pointer; extdecl;
begin
  Result := GetProp(Handle, Str);
end;

function  CEF_Win_GetRgnBox(RGN : HRGN; lpRect : PRect) : Longint; extdecl;
begin
  Result := GetRgnBox(RGN, lpRect);
end;

function  CEF_Win_GetROP2(DC: HDC): integer; extdecl;
begin
  Result := GetROP2(DC);
end;

function  CEF_Win_GetScrollInfo(Handle: HWND; SBStyle: Integer; var ScrollInfo: TScrollInfo):  LongBool; extdecl;
begin
  Result := GetScrollInfo(Handle, SBStyle, ScrollInfo);
end;

function  CEF_Win_GetStockObject(Value: Integer): THandle; extdecl;
begin
  Result := GetStockObject(Value);
end;

function  CEF_Win_GetSysColor(nIndex: Integer): DWORD; extdecl;
begin
  Result := GetSysColor(nIndex);
end;

function  CEF_Win_GetSysColorBrush(nIndex: Integer): HBrush; extdecl;
begin
  Result := GetSysColorBrush(nIndex);
end;

function  CEF_Win_GetSystemMetrics(nIndex: Integer): Integer;  extdecl;
begin
  Result := GetSystemMetrics(nIndex);
end;

function  CEF_Win_GetTextColor(DC: HDC) : TColorRef; extdecl;
begin
  Result := GetTextColor(DC);
end;

function  CEF_Win_GetTextExtentExPoint(DC: HDC; Str: PChar; Count, MaxWidth: Integer; MaxCount, PartialWidths: Integer; var Size: TSize):  LongBool; extdecl;
begin
  Result := GetTextExtentExPoint(DC,Str, Count, MaxWidth, @MaxCount, @PartialWidths, Size);
end;

function  CEF_Win_GetTextExtentPoint(DC: HDC; Str: PChar; Count: Integer; var Size: TSize):  LongBool; extdecl;
begin
  Result := GetTextExtentPoint(DC,Str, Count, Size);
end;

function  CEF_Win_GetTextExtentPoint32(DC: HDC; Str: PChar; Count: Integer; var Size: TSize):  LongBool; extdecl;
begin
  Result := GetTextExtentPoint32(DC,Str, Count, Size);
end;

function  CEF_Win_GetTextMetrics(DC: HDC; var TM: TTextMetric):  LongBool;  extdecl;
begin
  Result := GetTextMetrics(DC, TM);
end;

function  CEF_Win_GetViewPortExtEx(DC: HDC; Size: PSize): Integer; extdecl;
begin
  Result := GetViewPortExtEx(DC, Size);
end;

function  CEF_Win_GetViewPortOrgEx(DC: HDC; P: PPoint): Integer; extdecl;
begin
  Result := GetViewPortOrgEx(DC, P);
end;

function  CEF_Win_GetWindowExtEx(DC: HDC; Size: PSize): Integer; extdecl;
begin
  Result := GetWindowExtEx(DC, Size);
end;

function  CEF_Win_GetWindowLong(Handle : hwnd; int : Integer): PtrInt; extdecl;
begin
  Result := GetWindowLong(Handle, int);
end;

function  CEF_Win_GetWindowRect(Handle : hwnd; var Rect : TRect): Integer; extdecl;
begin
  Result := GetWindowRect(Handle, Rect);
end;

function  CEF_Win_GetWindowSize(Handle : hwnd; var Width, Height: integer):  LongBool; extdecl;
begin
  Result := GetWindowSize(Handle,Width, Height);
end;

function  CEF_Win_GetWindowOrgEx(dc : hdc; var P: TPoint): Integer; extdecl; // because of delphi compatibility
begin
  Result := GetWindowOrgEx(dc, P);
end;

function  CEF_Win_GradientFill(DC: HDC; Vertices: PTriVertex; NumVertices: Longint; Meshes: Pointer; NumMeshes: Longint; Mode: Longint):  LongBool; extdecl;
begin
  Result := GradientFill(DC, Vertices, NumVertices, Meshes, NumMeshes, Mode);
end;

function  CEF_Win_HideCaret(hWnd: HWND):  LongBool; extdecl;
begin
  Result := HideCaret(hWnd);
end;

procedure CEF_Win_InitializeCriticalSection(var CritSection: TCriticalSection); extdecl;
begin
  InitializeCriticalSection(CritSection);
end;

function  CEF_Win_IntersectClipRect(dc: hdc; Left, Top, Right,Bottom: Integer): Integer; extdecl;
begin
  Result := IntersectClipRect(dc,Left, Top, Right, Bottom);
end;

function  CEF_Win_InvalidateRect(aHandle : HWND; ARect : pRect; bErase :  LongBool) :  LongBool; extdecl;
begin
  Result := InvalidateRect(aHandle, ARect, bErase);
end;

function  CEF_Win_InvalidateRgn(Handle: HWND; Rgn: HRGN; Erase:  LongBool):  LongBool; extdecl;
begin
  Result := InvalidateRgn(Handle, Rgn, Erase);
end;

function  CEF_Win_IsDBCSLeadByte(TestChar: Byte):  LongBool; extdecl;
begin
  Result := IsDBCSLeadByte(TestChar);
end;

function  CEF_Win_IsIconic(handle: HWND):  LongBool; extdecl;
begin
  Result := IsIconic(handle);
end;

function  CEF_Win_IsWindow(handle: HWND):  LongBool; extdecl;
begin
  Result := IsWindow(handle);
end;

function  CEF_Win_IsWindowEnabled(handle: HWND):  LongBool; extdecl;
begin
  Result := IsWindowEnabled(handle);
end;

function  CEF_Win_IsWindowVisible(handle: HWND):  LongBool; extdecl;
begin
  Result := IsWindowVisible(handle);
end;

function  CEF_Win_IsZoomed(handle: HWND):  LongBool; extdecl;
begin
  Result := IsZoomed(handle);
end;

procedure CEF_Win_LeaveCriticalSection(var CritSection: TCriticalSection);  extdecl;
begin
  LeaveCriticalSection(CritSection);
end;

function  CEF_Win_LineTo(DC: HDC; X, Y: Integer):  LongBool; extdecl;
begin
  Result := LineTo(DC, X, Y);
end;

function  CEF_Win_LoadBitmap(hInstance: THandle; lpBitmapName: PChar): HBitmap; extdecl;
begin
  Result := LoadBitmap(hInstance, lpBitmapName);
end;

function  CEF_Win_LoadIcon(hInstance: THandle; lpIconName: PChar): HIcon; extdecl;
begin
  Result := LoadIcon(hInstance, lpIconName);
end;

function  CEF_Win_MaskBltRop(DestDC: HDC; X, Y, Width, Height: Integer; SrcDC: HDC; XSrc, YSrc: Integer; Mask: HBITMAP; XMask, YMask: Integer; Rop: DWORD):  LongBool; extdecl;
begin
  Result := MaskBlt(DestDC, X, Y, Width, Height, SrcDC, XSrc, YSrc, Mask, XMask, YMask, Rop);
end;

function  CEF_Win_MaskBlt(DestDC: HDC; X, Y, Width, Height: Integer; SrcDC: HDC; XSrc, YSrc: Integer; Mask: HBITMAP; XMask, YMask: Integer):  LongBool; extdecl;
begin
  Result := MaskBlt(DestDC,X, Y, Width, Height, SrcDC, XSrc, YSrc, Mask, XMask, YMask);
end;

function  CEF_Win_MessageBox(hWnd: HWND; lpText, lpCaption: PChar; uType: Cardinal = MB_OK): integer; extdecl;
begin
  Result := MessageBox(hWnd, lpText, lpCaption, uType);
end;

function  CEF_Win_MonitorFromPoint(ptScreenCoords: TPoint; dwFlags: DWord): HMONITOR; extdecl;
begin
  Result := MonitorFromPoint(ptScreenCoords, dwFlags);
end;

function  CEF_Win_MonitorFromRect(lprcScreenCoords: PRect; dwFlags: DWord): HMONITOR; extdecl;
begin
  Result := MonitorFromRect(lprcScreenCoords, dwFlags);
end;

function  CEF_Win_MonitorFromWindow(hWnd: HWND; dwFlags: DWord): HMONITOR; extdecl;
begin
  Result := MonitorFromWindow(hWnd,dwFlags);
end;

function  CEF_Win_MoveToEx(DC: HDC; X, Y: Integer; OldPoint: PPoint):  LongBool; extdecl;
begin
  Result := MoveToEx(DC,X, Y, OldPoint);
end;

function  CEF_Win_OffsetRgn(RGN: HRGN; nXOffset, nYOffset: Integer): Integer; extdecl;
begin
  Result := OffsetRgn(RGN,nXOffset, nYOffset);
end;

function  CEF_Win_PaintRgn(DC: HDC; RGN: HRGN):  LongBool; extdecl;
begin
  Result := PaintRgn(DC,RGN);
end;

//function  CEF_Win_PeekMessage(var lpMsg : TMSG; Handle : HWND; wMsgFilterMin, wMsgFilterMax,wRemoveMsg : UINT):  LongBool; extdecl;
//begin
//  Result := PeekMessage(lpMsg, Handle, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
//end;

function  CEF_Win_Pie(DC: HDC; x1, y1, x2, y2, sx, sy, ex, ey: Integer):  LongBool; extdecl;
begin
  Result := Pie(DC,x1, y1, x2, y2, sx, sy, ex, ey);
end;

function  CEF_Win_PolyBezier(DC: HDC; Points: PPoint;  NumPts: Integer; Filled, Continuous:  LongBool):  LongBool; extdecl;
begin
  Result := PolyBezier(DC,Points, NumPts, Filled, Continuous);
end;

function  CEF_Win_Polygon(DC: HDC; Points: PPoint;  NumPts: Integer; Winding:  LongBool):  LongBool; extdecl;
begin
  Result := Polygon(DC, Points, NumPts, Winding);
end;

function  CEF_Win_Polyline(DC: HDC; Points: PPoint; NumPts: Integer):  LongBool; extdecl;
begin
  Result := Polyline(DC, Points, NumPts);
end;

function  CEF_Win_PostMessage(Handle: HWND; Msg: Cardinal; WParam: WParam; LParam: LParam):  LongBool; extdecl;
begin
  Result := PostMessage(Handle, Msg, WParam, LParam);
end;

function  CEF_Win_RealizePalette(DC: HDC): Cardinal; extdecl;
begin
  Result := RealizePalette(DC);
end;

function  CEF_Win_Rectangle(DC: HDC; X1, Y1, X2, Y2: Integer):  LongBool; extdecl;
begin
  Result := Rectangle(DC, X1, Y1, X2, Y2);
end;

function  CEF_Win_RectInRegion(RGN: HRGN; ARect: TRect):  LongBool; extdecl;
begin
  Result := RectInRegion(RGN,ARect);
end;

function  CEF_Win_RectVisible(DC: HDC; const ARect: TRect):  LongBool; extdecl;
begin
  Result := RectVisible(DC,ARect);
end;

function  CEF_Win_RedrawWindow(Wnd: HWND; lprcUpdate: PRECT; hrgnUpdate: HRGN; flags: UINT):  LongBool; extdecl;
begin
  Result := RedrawWindow(Wnd, lprcUpdate, hrgnUpdate, flags);
end;

function  CEF_Win_ReleaseCapture :  LongBool; extdecl;
begin
  Result := ReleaseCapture ();
end;

function  CEF_Win_ReleaseDC(hWnd: HWND; DC: HDC): Integer; extdecl;
begin
  Result := ReleaseDC(hWnd, DC);
end;

function  CEF_Win_RemoveProp(Handle: hwnd; Str: PChar): THandle; extdecl;
begin
  Result := RemoveProp(Handle,Str);
end;

function  CEF_Win_RestoreDC(DC: HDC; SavedDC: Integer):  LongBool; extdecl;
begin
  Result := RestoreDC(DC, SavedDC);
end;

function  CEF_Win_RoundRect(DC : hDC; X1, Y1, X2, Y2: Integer; RX, RY : Integer):  LongBool; extdecl;
begin
  Result := RoundRect(DC, X1, Y1, X2, Y2, RX, RY );
end;

function  CEF_Win_SaveDC(DC: HDC): Integer; extdecl;
begin
  Result := SaveDC(DC);
end;

function  CEF_Win_ScrollWindowEx(hWnd: HWND; dx, dy: Integer; prcScroll, prcClip: PRect; hrgnUpdate: HRGN; prcUpdate: PRect; flags: UINT):  LongBool; extdecl;
begin
  Result := ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags);
end;

function  CEF_Win_SelectClipRGN(DC : hDC; RGN : HRGN) : Longint; extdecl;
begin
  Result := SelectClipRGN(DC, RGN);
end;

function  CEF_Win_SelectObject(DC: HDC; GDIObj: HGDIOBJ): HGDIOBJ; extdecl;
begin
  Result := SelectObject(DC, GDIObj);
end;

function  CEF_Win_SelectPalette(DC: HDC; Palette: HPALETTE; ForceBackground:  LongBool): HPALETTE; extdecl;
begin
  Result := SelectPalette(DC, Palette, ForceBackground);
end;

function  CEF_Win_SendMessage(HandleWnd: HWND; Msg: Cardinal; WParam: WParam; LParam: LParam): LResult; extdecl;
begin
  Result := SendMessage(HandleWnd, Msg, WParam, LParam);
end;

function  CEF_Win_SetActiveWindow(Handle: HWND): HWND;  extdecl;
begin
  Result := SetActiveWindow(Handle);
end;

function  CEF_Win_SetBkColor(DC: HDC; Color: TColorRef): TColorRef; extdecl; //pbd
begin
  Result := SetBkColor(DC, Color);
end;

function  CEF_Win_SetBkMode(DC: HDC; bkMode : Integer): Integer; extdecl;
begin
  Result := SetBkMode(DC, bkMode);
end;

function  CEF_Win_SetCapture (AHandle: HWND): HWND; extdecl;
begin
  Result := SetCapture(AHandle);
end;

function  CEF_Win_SetCaretPos(X, Y: Integer):  LongBool; extdecl;
begin
  Result := SetCaretPos(X, Y);
end;

function  CEF_Win_SetCaretPosEx(handle: HWnd; X, Y: Integer):  LongBool; extdecl;
begin
  Result := SetCaretPosEx(handle, X, Y);
end;

function  CEF_Win_SetCursorPos(X, Y: Integer):  LongBool; extdecl;
begin
  Result := SetCursorPos(X, Y);
end;

function  CEF_Win_SetFocus(hWnd: HWND): HWND; extdecl;
begin
  Result := SetFocus(hWnd);
end;

function  CEF_Win_SetForegroundWindow(hWnd : HWND):  LongBool; extdecl;
begin
  Result := SetForegroundWindow(hWnd);
end;

function  CEF_Win_SetMapMode(DC: HDC; fnMapMode : Integer): Integer; extdecl;
begin
  Result := SetMapMode(DC, fnMapMode);
end;

function  CEF_Win_SetMenu(AWindowHandle: HWND; AMenuHandle: HMENU):  LongBool; extdecl;
begin
  Result := SetMenu(AWindowHandle, AMenuHandle);
end;

function  CEF_Win_SetParent(hWndChild: HWND; hWndParent: HWND): HWND; extdecl;
begin
  Result := SetParent(hWndChild, hWndParent);
end;

function  CEF_Win_SetProp(Handle: hwnd; Str : PChar; Data : Pointer) :  LongBool; extdecl;
begin
  Result := SetProp(Handle, Str, Data);
end;

function  CEF_Win_SetROP2(DC: HDC; Mode: Integer): Integer; extdecl;
begin
  Result := SetROP2(DC, Mode);
end;

function  CEF_Win_SetScrollInfo(Handle: HWND; SBStyle: Integer; ScrollInfo: TScrollInfo; Redraw :  LongBool): Integer; extdecl;
begin
  Result := SetScrollInfo(Handle, SBStyle, ScrollInfo, Redraw);
end;

function  CEF_Win_SetStretchBltMode(DC: HDC; StretchMode: Integer): Integer; extdecl;
begin
  Result := SetStretchBltMode(DC, StretchMode);
end;

function  CEF_Win_SetTextCharacterExtra(_hdc : hdc; nCharExtra : Integer):Integer; extdecl;
begin
  Result := SetTextCharacterExtra(_hdc, nCharExtra);
end;

function  CEF_Win_SetTextColor(DC: HDC; Color: TColorRef): TColorRef; extdecl;
begin
  Result := SetTextColor(DC, Color);
end;

function  CEF_Win_SetWindowLong(Handle: HWND; Idx: Integer; NewLong : PtrInt): PtrInt; extdecl;
begin
  Result := SetWindowLong(Handle, Idx, NewLong);
end;

function  CEF_Win_SetViewPortExtEx(DC: HDC; XExtent, YExtent : Integer; OldSize: PSize):  LongBool; extdecl;
begin
  Result := SetViewPortExtEx(DC,XExtent, YExtent, OldSize);
end;

function  CEF_Win_SetViewPortOrgEx(DC: HDC; NewX, NewY: Integer; OldPoint: PPoint):  LongBool; extdecl;
begin
  Result := SetViewPortOrgEx(DC,NewX, NewY, OldPoint);
end;

function  CEF_Win_SetWindowExtEx(DC: HDC; XExtent, YExtent: Integer; OldSize: PSize):  LongBool; extdecl;
begin
  Result := SetWindowExtEx(DC,XExtent, YExtent, OldSize);
end;

function  CEF_Win_SetWindowOrgEx(dc : hdc; NewX, NewY: Integer; OldPoint: PPoint):  LongBool; extdecl;
begin
  Result := SetWindowOrgEx(dc,NewX, NewY, OldPoint);
end;

function  CEF_Win_SetWindowPos(hWnd: HWND; hWndInsertAfter: HWND; X, Y, cx, cy: Integer; uFlags: UINT):  LongBool;  extdecl;
begin
  Result := SetWindowPos(hWnd,hWndInsertAfter, X, Y, cx, cy, uFlags);
end;

function  CEF_Win_ShowCaret(hWnd: HWND):  LongBool; extdecl;
begin
  Result := ShowCaret(hWnd);
end;

function  CEF_Win_ShowScrollBar(Handle: HWND; wBar: Integer; bShow:  LongBool):  LongBool; extdecl;
begin
  Result := ShowScrollBar(Handle,wBar, bShow);
end;

function  CEF_Win_ShowWindow(hWnd: HWND; nCmdShow: Integer):  LongBool; extdecl;
begin
  Result := ShowWindow(hWnd,nCmdShow);
end;

function  CEF_Win_StretchBlt(DestDC: HDC; X, Y, Width, Height: Integer; SrcDC: HDC; XSrc, YSrc, SrcWidth, SrcHeight: Integer; Rop: Cardinal):  LongBool; extdecl;
begin
  Result := StretchBlt(DestDC,X, Y, Width, Height, SrcDC, XSrc, YSrc, SrcWidth, SrcHeight, Rop);
end;

function  CEF_Win_StretchDIBits(DC: HDC; DestX, DestY, DestWidth, DestHeight, SrcX,SrcY, SrcWidth, SrcHeight: Integer; Bits: Pointer; var BitsInfo: TBitmapInfo;Usage: UINT; Rop: DWORD): Integer; extdecl;
begin
  Result := StretchDIBits(DC, DestX, DestY, DestWidth, DestHeight, SrcX, SrcY, SrcWidth, SrcHeight, Bits, BitsInfo, Usage, Rop);
end;

function  CEF_Win_SystemParametersInfo(uiAction: DWord; uiParam: DWord; pvParam: Pointer; fWinIni: DWord): LongBool; extdecl;
begin
  Result := SystemParametersInfo(uiAction, uiParam, pvParam, fWinIni);
end;

function  CEF_Win_TextOut(DC: HDC; X,Y : Integer; Str : Pchar; Count: Integer) :  LongBool; extdecl;
begin
  Result := TextOut(DC, X, Y, Str, Count);
end;

function  CEF_Win_UpdateWindow(Handle: HWND):  LongBool; extdecl;
begin
  Result := UpdateWindow(Handle);
end;

function  CEF_Win_WindowFromPoint(Point : TPoint) : HWND; extdecl;
begin
  Result := WindowFromPoint(Point);
end;

{$ifdef MSWINDOWS}
function CEF_Win_GetWindowLongPtr(hWnd: HWND; nIndex: LongInt): LONG_PTR; extdecl;
begin
  Result := GetWindowLongPtr(hWnd, nIndex);
end;

function CEF_Win_SetWindowLongPtr(hWnd: HWND; nIndex: LongInt; dwNewLong: LONG_PTR): LONG_PTR; extdecl;
begin
  Result := SetWindowLongPtr(hWnd, nIndex, dwNewLong);
end;

function CEF_Win_GetClassLongPtr(hWnd: HWND; nIndex: LongInt): LONG_PTR; extdecl;
begin
  Result := GetClassLongPtr(hWnd, nIndex);
end;

function CEF_Win_SetClassLongPtr(hWnd: HWND; nIndex: LongInt; dwNewLong: LONG_PTR): LONG_PTR; extdecl;
begin
  Result := SetClassLongPtr(hWnd, nIndex, dwNewLong);
end;

function CEF_Win_FindWindow(lpClassName: PChar; lpWindowName: PChar): HWND; extdecl;
begin
  Result := FindWindow(LPCSTR(lpClassName), LPCSTR(lpWindowName));
end;

function CEF_Win_FindWindowEx(_para1: HWND; _para2: HWND; _para3: PChar; _para4: PChar): HWND; extdecl;
begin
  Result := FindWindowEx(_para1,_para2, LPCSTR(_para3), LPCSTR(_para4));
end;

function CEF_Win_SetWindowText(hWnd: HWND; lpString: PChar): LongBool; extdecl;
begin
  Result := SetWindowText(hWnd, LPCSTR(lpString));
end;

function CEF_Win_GetWindowText(hWnd: HWND; lpString: PChar; nMaxCount: LongInt): LongInt; extdecl;
begin
  Result := GetWindowText(hWnd, LPCSTR(lpString), nMaxCount);
end;

function CEF_Win_GetWindowTextLength(hWnd: HWND): LongInt; extdecl;
begin
  Result := GetWindowTextLength(hWnd);
end;
{$endif}


exports
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
  CEF_Win_OnPaint,
  CEF_Win_EndPaint,
  CEF_Win_BeginPaint,
  CEF_Win_Arc,
  CEF_Win_AngleChord,
  CEF_Win_CallNextHookEx,
  CEF_Win_CallWindowProc,
  CEF_Win_BitBlt,
  CEF_Win_CreateBitmap,
  CEF_Win_CreateBrushIndirect,
  CEF_Win_CreateBrushWithRadialGradient,
  CEF_Win_CreateCaret,
  CEF_Win_CreateCompatibleBitmap,
  CEF_Win_CreateCompatibleDC,
  CEF_Win_CreateDIBitmap,
  CEF_Win_CreateDIBSection,
  CEF_Win_CreateEllipticRgn,
  CEF_Win_CreateFontIndirect,
  CEF_Win_CreateFontIndirectEx,
  CEF_Win_CreateIconIndirect,
  CEF_Win_CreatePalette,
  CEF_Win_CreatePatternBrush,
  CEF_Win_CreatePenIndirect,
  CEF_Win_CreatePolygonRgn,
  CEF_Win_DeleteCriticalSection,
  CEF_Win_DeleteDC,
  CEF_Win_DestroyCaret,
  CEF_Win_DestroyCursor,
  CEF_Win_DestroyIcon,
  CEF_Win_DrawFrameControl,
  CEF_Win_DrawFocusRect,
  CEF_Win_DrawEdge,
  CEF_Win_DrawText,
  CEF_Win_EnableScrollBar,
  CEF_Win_EnableWindow,
  CEF_Win_EnterCriticalSection,
  CEF_Win_EnumDisplayMonitors,
  CEF_Win_EnumFontFamilies,
  CEF_Win_EnumFontFamiliesEx,
  CEF_Win_EnumDisplayMonitorsCallbackFree,
  CEF_Win_EnumFontFamiliesCallbackFree,
  CEF_Win_EnumFontFamiliesExCallbackFree,
  CEF_Win_Ellipse,
  CEF_Win_EqualRgn,
  CEF_Win_ExcludeClipRect,
  CEF_Win_ExtCreatePen,
  CEF_Win_ExtTextOut,
  CEF_Win_ExtSelectClipRGN,
  CEF_Win_FillRect,
  CEF_Win_FillRgn,
  CEF_Win_FloodFill,
  CEF_Win_FrameRect,
  CEF_Win_GetActiveWindow,
  CEF_Win_GetBitmapBits,
  CEF_Win_GetBkColor,
  CEF_Win_GetCapture,
  CEF_Win_GetCaretPos,
  CEF_Win_GetClientRect,
  CEF_Win_GetClipBox,
  CEF_Win_GetClipRGN,
  CEF_Win_GetCurrentObject,
  CEF_Win_GetCursorPos,
  CEF_Win_GetDC,
  CEF_Win_GetDeviceCaps,
  CEF_Win_GetDIBits,
  CEF_Win_GetDoubleClickTime,
  CEF_Win_GetFocus,
  CEF_Win_GetFontLanguageInfo,
  CEF_Win_GetForegroundWindow,
  CEF_Win_GetIconInfo,
  CEF_Win_GetKeyState,
  CEF_Win_GetMapMode,
  CEF_Win_GetMonitorInfo,
  CEF_Win_GetDpiForMonitor,
  CEF_Win_GetObject,
  CEF_Win_GetParent,
  CEF_Win_GetProp,
  CEF_Win_GetRgnBox,
  CEF_Win_GetROP2,
  CEF_Win_GetScrollInfo,
  CEF_Win_GetStockObject,
  CEF_Win_GetSysColor,
  CEF_Win_GetSysColorBrush,
  CEF_Win_GetSystemMetrics,
  CEF_Win_GetTextColor,
  CEF_Win_GetTextExtentExPoint,
  CEF_Win_GetTextExtentPoint,
  CEF_Win_GetTextExtentPoint32,
  CEF_Win_GetTextMetrics,
  CEF_Win_GetViewPortExtEx,
  CEF_Win_GetViewPortOrgEx,
  CEF_Win_GetWindowExtEx,
  CEF_Win_GetWindowLong,
  CEF_Win_GetWindowRect,
  CEF_Win_GetWindowSize,
  CEF_Win_GetWindowOrgEx,
  CEF_Win_GradientFill,
  CEF_Win_HideCaret,
  CEF_Win_InitializeCriticalSection,
  CEF_Win_IntersectClipRect,
  CEF_Win_InvalidateRect,
  CEF_Win_InvalidateRgn,
  CEF_Win_IsDBCSLeadByte,
  CEF_Win_IsIconic,
  CEF_Win_IsWindow,
  CEF_Win_IsWindowEnabled,
  CEF_Win_IsWindowVisible,
  CEF_Win_IsZoomed,
  CEF_Win_LeaveCriticalSection,
  CEF_Win_LineTo,
  CEF_Win_LoadBitmap,
  CEF_Win_LoadIcon,
  CEF_Win_MaskBltRop,
  CEF_Win_MaskBlt,
  CEF_Win_MessageBox,
  CEF_Win_MonitorFromPoint,
  CEF_Win_MonitorFromRect,
  CEF_Win_MonitorFromWindow,
  CEF_Win_MoveToEx,
  CEF_Win_OffsetRgn,
  CEF_Win_PaintRgn,
  CEF_Win_Pie,
  CEF_Win_PolyBezier,
  CEF_Win_Polygon,
  CEF_Win_Polyline,
  CEF_Win_PostMessage,
  CEF_Win_RealizePalette,
  CEF_Win_Rectangle,
  CEF_Win_RectInRegion,
  CEF_Win_RectVisible,
  CEF_Win_RedrawWindow,
  CEF_Win_ReleaseCapture,
  CEF_Win_ReleaseDC,
  CEF_Win_RemoveProp,
  CEF_Win_RestoreDC,
  CEF_Win_RoundRect,
  CEF_Win_SaveDC,
  CEF_Win_ScrollWindowEx,
  CEF_Win_SelectClipRGN,
  CEF_Win_SelectObject,
  CEF_Win_SelectPalette,
  CEF_Win_SendMessage,
  CEF_Win_SetActiveWindow,
  CEF_Win_SetBkColor,
  CEF_Win_SetBkMode,
  CEF_Win_SetCapture,
  CEF_Win_SetCaretPos,
  CEF_Win_SetCaretPosEx,
  CEF_Win_SetCursorPos,
  CEF_Win_SetFocus,
  CEF_Win_SetForegroundWindow,
  CEF_Win_SetMapMode,
  CEF_Win_SetMenu,
  CEF_Win_SetParent,
  CEF_Win_SetProp,
  CEF_Win_SetROP2,
  CEF_Win_SetScrollInfo,
  CEF_Win_SetStretchBltMode,
  CEF_Win_SetTextCharacterExtra,
  CEF_Win_SetTextColor,
  CEF_Win_SetWindowLong,
  CEF_Win_SetViewPortExtEx,
  CEF_Win_SetViewPortOrgEx,
  CEF_Win_SetWindowExtEx,
  CEF_Win_SetWindowOrgEx,
  CEF_Win_SetWindowPos,
  CEF_Win_ShowCaret,
  CEF_Win_ShowScrollBar,
  CEF_Win_ShowWindow,
  CEF_Win_StretchBlt,
  CEF_Win_StretchDIBits,
  CEF_Win_SystemParametersInfo,
  CEF_Win_TextOut,
  CEF_Win_UpdateWindow,
  CEF_Win_WindowFromPoint
{$ifdef MSWINDOWS},
  CEF_Win_GetWindowLongPtr,
  CEF_Win_SetWindowLongPtr,
  CEF_Win_GetClassLongPtr,
  CEF_Win_SetClassLongPtr,
  CEF_Win_FindWindow,
  CEF_Win_FindWindowEx,
  CEF_Win_SetWindowText,
  CEF_Win_GetWindowText,
  CEF_Win_GetWindowTextLength
{$endif};
