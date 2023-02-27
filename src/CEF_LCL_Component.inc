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
Messages, Variants,uCEF_LCL_ScheduleMessagePumpWork,
uCEFStringMultimap, uCEFCallback, uCEFChromium, uCEFWindowParent, uCEFLinkedWindowParent, uCEFInterfaces, uCEFApplication, uCEFv8Interceptor, uCEFTypes, uCEFv8Value, uCEFBinaryValue, uCEFDictionaryValue, uCEFListValue, uCEFValue,
uCEFConstants, uCEFWinControl, uCEFChromiumEvents, uCEFMiscFunctions, uCEFClient, uCEFProcessMessage, uCEFWorkScheduler, uCEFRunFileDialogCallback, uCEFDownloadImageCallBack, uCEFPostData, uCEFPostDataElement,
uCEFPDFPrintCallback, uCEFv8Context, uCEFBrowser, uCEFBrowserViewComponent, uCEFWindowComponent, uCEFImage, uCEFRequestContext, uCEFRequestContextHandler, uCEFv8Accessor, uCEFv8Exception,
uCEF_LCL_Entity, uCEF_LCL_Chromium, uCEF_LCL_Application, uCEF_LCL_Event, uCEF_LCL_IPC, uCEF_LCL_DictionaryValue, uCEF_LCL_V8ValueRef, uCEF_LCL_V8AccessorRef, uCEF_LCL_V8HandlerRef, uCEF_LCL_V8InterceptorRef,
uCEF_LCL_V8ArrayBufferReleaseCallbackRef,
uCEF_LCL_ConsoleWrite,
