//----------------------------------------
// The code is automatically generated by the GenlibLcl tool.
// 
// Licensed under Lazarus.modifiedLGPL
//
//----------------------------------------

{$if FPC_FULLVERSION < 30200}
   {$ERROR 'Requires FPC version>=3.2'}
{$endif}

library liblcl;

{$mode delphi}

// 以后测试
// https://www.freepascal.org/docs-html/prog/progsu25.html
//{$LONGSTRINGS ON}

{$ifndef windows}
  {$define UseCThreads}
{$endif}

uses
  //sysinit,
{$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
{$ENDIF}{$ENDIF}
  //LCLTranslator,
{$I UseAll.inc},
  Classes,
  SysUtils,
  LCLVersion,
  uFormDesignerFile,
{$IFDEF LCLCocoa}
  uMacOSPatchs,
{$ENDIF}
{$IFDEF LINUX}
  uLinuxPatchs,
{$ENDIF}
  uExceptionHandle,
  uComponents,
  uControlPatchs;

{$IFDEF WINDOWS}
  {$R *.res}
  {$SetPEFlags IMAGE_FILE_LARGE_ADDRESS_AWARE}
{$ENDIF}

{$I ExtDecl.inc}
{$I LazarusDef.inc}


{$I uExport1.pas}
{$I uExport2.pas}
{$I uExport3.pas}
{$I uExport4.pas}


//组件接口导出
//{$I CEF_LCL_Export.inc}

begin
  RequireDerivedFormResource := False;
  // 3.2还是多少这个得设置下了，不然收不到消息了
  // 3.0.4不需要设置
{$if FPC_FULLVERSION >= 30200}
  IsMultiThread := True;
{$endif}
  InitLazarusDef;
end.
