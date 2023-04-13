//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------
{
CEFChromium 组件单元
}

//基础库 单元(*.pas) CEF_LCL_*.inc 使用
{$ifdef DARWIN}
uCEFLazarusCocoa,
{$endif}
{$ifdef Linux}
//uCEF_LCL_GTK2_Interfaces, //注释掉占CPU
{$endif}
Messages, Variants, uCEF_LCL_ScheduleMessagePumpWork, fpjson, jsonparser,
uCEFBaseRefCounted, uCEFDownloadItemCallback, uCEFSchemeRegistrar,uCEFCommandLine, uCEFLibFunctions,
uCEFStringMultimap, uCEFCallback, uCEFChromium, uCEFWindowParent, uCEFLinkedWindowParent, uCEFInterfaces, uCEFApplication, uCEFv8Interceptor, uCEFTypes, uCEFv8Value, uCEFBinaryValue, uCEFDictionaryValue, uCEFListValue, uCEFValue, uCEFFrame,
uCEFConstants, uCEFWinControl, uCEFChromiumEvents, uCEFMiscFunctions, uCEFClient, uCEFProcessMessage, uCEFWorkScheduler, uCEFRunFileDialogCallback, uCEFDownloadImageCallBack, uCEFPostData, uCEFPostDataElement, uCEFDownLoadItem, uCEFRequest, uCEFResponse,
uCEFPDFPrintCallback, uCEFv8Context, uCEFBrowser, uCEFBrowserViewComponent, uCEFWindowComponent, uCEFImage, uCEFRequestContext, uCEFRequestContextHandler, uCEFv8Accessor, uCEFv8Exception, uCEFPDFPrintOptions, uCEFExtensionHandler,
uCEF_LCL_Entity, uCEF_LCL_Application, uCEF_LCL_Event, uCEF_LCL_DictionaryValue, uCEF_LCL_V8AccessorRef, uCEF_LCL_V8HandlerRef, uCEF_LCL_V8InterceptorRef, uCEF_LCL_PdfPrintCallbackRef,
uCEF_LCL_V8ArrayBufferReleaseCallbackRef, uCEF_LCL_ValueConvert, uCEF_LCL_CompletionCallbackRef, uCEF_LCL_ExtensionHandlerRef,
uCEF_LCL_ConsoleWrite,
