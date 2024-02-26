//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------
{
 导出接口 *.inc
}

// cef
{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

{$IFnDEF LINUX}
{$define handleExceptionBegin :=try}
{$define handleExceptionEnd :=
   except
     on E: Exception do
       CallException(E);
   end;
}
{$ENDIF}

{$I CEF_LCL_AccessibilityHandler.inc}
{$I CEF_LCL_Application_Event.inc}
{$I CEF_LCL_Application_Proc.inc}
{$I CEF_LCL_AuthCallback.inc}
{$I CEF_LCL_BaseRefCounted.inc}
{$I CEF_LCL_Browser.inc}
{$I CEF_LCL_BinaryValue.inc}
//{$I CEF_LCL_BitmapBitBuffer.inc}
//{$I CEF_LCL_BrowserView.inc}
//{$I CEF_LCL_BrowserViewComponent.inc}
//{$I CEF_LCL_BrowserViewDelegate.inc}
{$I CEF_LCL_BufferPanel.inc}
//{$I CEF_LCL_Button.inc}
//{$I CEF_LCL_ButtonComponent.inc}
//{$I CEF_LCL_ButtonDelegate.inc}
{$I CEF_LCL_Callback.inc}
//{$I CEF_LCL_Callback_Register.inc}
{$I CEF_LCL_Chromium_Event.inc}
{$I CEF_LCL_Chromium_Options.inc}
{$I CEF_LCL_Chromium_Proc.inc}
{$I CEF_LCL_Client.inc}
{$I CEF_LCL_ClientHandlers.inc}
{$I CEF_LCL_CommandLine.inc}
{$I CEF_LCL_CompletionCallback.inc}
{$I CEF_LCL_ContextMenuParams.inc}
{$I CEF_LCL_CookieManager.inc}
{$I CEF_LCL_CustomWidgetInterfaces.inc}
{$I CEF_LCL_CookieCallbacks.inc}
{$I CEF_LCL_Def.inc}
{$I CEF_LCL_DictionaryValue.inc}
//{$I CEF_LCL_Display.inc}
{$I CEF_LCL_DomDocument.inc}
{$I CEF_LCL_DomNode.inc}
{$I CEF_LCL_DomVisitor.inc}
//{$I CEF_LCL_DownloadImageCallback.inc}
{$I CEF_LCL_DownloadItem.inc}
{$I CEF_LCL_DragData.inc}
//{$I CEF_LCL_Extension.inc}
//{$I CEF_LCL_ExtensionHandler.inc}
{$I CEF_LCL_FileDialogCallback.inc}
{$I CEF_LCL_Frame.inc}
//{$I CEF_LCL_GetExtensionResourceCallback.inc}
//{$I CEF_LCL_Image.inc}
{$I CEF_LCL_JsDialogCallback.inc}
//{$I CEF_LCL_LabelButton.inc}
//{$I CEF_LCL_LabelButtonComponent.inc}
//{$I CEF_LCL_LinkedWindowParent.inc}
//{$I CEF_LCL_MediaAccessCallback.inc}
//{$I CEF_LCL_MenuButton.inc}
//{$I CEF_LCL_MenuButtonDelegate.inc}
//{$I CEF_LCL_MenuButtonComponent.inc}
{$I CEF_LCL_MenuModel.inc}
//{$I CEF_LCL_MenuModelDelegate.inc}
{$I CEF_LCL_MiscFunctions.inc}
//{$I CEF_LCL_Panel.inc}
//{$I CEF_LCL_PanelComponent.inc}
//{$I CEF_LCL_PanelDelegate.inc}
{$I CEF_LCL_PdfPrintCallback.inc}
//{$I CEF_LCL_PermissionPromptCallback.inc}
{$I CEF_LCL_PostData.inc}
{$I CEF_LCL_PostDataElement.inc}
{$I CEF_LCL_PrintDialogCallback.inc}
{$I CEF_LCL_PrintJobCallback.inc}
{$I CEF_LCL_PrintSettings.inc}
{$I CEF_LCL_ProcessMessage.inc}
{$I CEF_LCL_Request.inc}
{$I CEF_LCL_RequestContext.inc}
{$I CEF_LCL_RequestContextHandler.inc}
//{$I CEF_LCL_ResourceCallbacks.inc}
{$I CEF_LCL_ResourceRequestHandler.inc}
{$I CEF_LCL_Response.inc}
{$I CEF_LCL_ResponseFilter.inc}
{$I CEF_LCL_RunContextMenuCallback.inc}
{$I CEF_LCL_RunFileDialogCallback.inc}
{$I CEF_LCL_RunQuickMenuCallback.inc}
{$I CEF_LCL_SchemeHandlerFactory.inc}
{$I CEF_LCL_SchemeRegistrarRef.inc}
//{$I CEF_LCL_ScrollView.inc}
//{$I CEF_LCL_ScrollViewComponent.inc}
{$I CEF_LCL_StreamReader.inc}
{$I CEF_LCL_StreamWriter.inc}
{$I CEF_LCL_StringMultiMap.inc}
//{$I CEF_LCL_Textfield.inc}
//{$I CEF_LCL_TextfieldComponent.inc}
//{$I CEF_LCL_TextfieldDelegate.inc}
{$I CEF_LCL_TString.inc}
{$I CEF_LCL_v8Accessor.inc}
//{$I CEF_LCL_v8ArrayBufferReleaseCallback.inc}
{$I CEF_LCL_v8Context.inc}
{$I CEF_LCL_v8Exception.inc}
{$I CEF_LCL_v8Handler.inc}
//{$I CEF_LCL_v8Interceptor.inc}
{$I CEF_LCL_v8Value.inc}
{$I CEF_LCL_Value.inc}
{$I CEF_LCL_ValueConvert.inc}
//{$I CEF_LCL_View.inc}
//{$I CEF_LCL_ViewComponent.inc}
//{$I CEF_LCL_ViewDelegate.inc}
//{$I CEF_LCL_Window.inc}
//{$I CEF_LCL_WindowComponent.inc}
{$I CEF_LCL_WindowParent.inc}
{$I CEF_LCL_WorkScheduler.inc}
//{$I CEF_LCL_X509Certificate.inc}
{$I Energy_Extend.inc}
