{ This file was automatically created by Lazarus. Do not edit!
  This source is only used to compile and install the package.
 }

unit OldCEF4Delphi;

{$warn 5023 off : no warning about unused units}
interface

uses
  uBufferPanel, uCEFApp, uCEFApplication, uCEFAuthCallback, uCEFBase, 
  uCEFBeforeDownloadCallback, uCEFBinaryValue, uCEFBrowser, 
  uCEFBrowserProcessHandler, uCEFCallback, uCEFChromium, uCEFChromiumEvents, 
  uCEFChromiumFontOptions, uCEFChromiumOptions, uCEFChromiumWindow, 
  uCEFClient, uCEFCommandLine, uCEFCompletionCallback, uCEFConstants, 
  uCEFContextMenuHandler, uCEFContextMenuParams, uCEFCookieManager, 
  uCEFCookieVisitor, uCEFCustomStreamReader, uCEFDeleteCookiesCallback, 
  uCEFDialogHandler, uCEFDictionaryValue, uCEFDisplayHandler, uCEFDomDocument, 
  uCEFDomNode, uCEFDomVisitor, uCEFDownloadHandler, uCEFDownLoadItem, 
  uCEFDownloadItemCallback, uCEFDragAndDropMgr, uCEFDragData, uCEFDragHandler, 
  uCEFEndTracingCallback, uCEFFileDialogCallback, uCEFFindHandler, 
  uCEFFocusHandler, uCEFFrame, uCEFGeolocationCallback, 
  uCEFGeolocationHandler, uCEFInterfaces, uCEFJsDialogCallback, 
  uCEFJsDialogHandler, uCEFKeyboardHandler, uCEFLibFunctions, 
  uCEFLifeSpanHandler, uCEFListValue, uCEFLoadHandler, uCEFMenuModel, 
  uCEFMiscFunctions, uCEFNavigationEntry, uCEFNavigationEntryVisitor, 
  uCEFPDFPrintCallback, uCEFPDFPrintOptions, uCEFPostData, 
  uCEFPostDataElement, uCEFPrintSettings, uCEFProcessMessage, 
  uCEFRenderHandler, uCEFRenderProcessHandler, uCEFRequest, 
  uCEFRequestCallback, uCEFRequestContext, uCEFRequestContextHandler, 
  uCEFRequestHandler, uCEFResolveCallback, uCEFResourceBundle, 
  uCEFResourceBundleHandler, uCEFResourceHandler, uCEFResponse, 
  uCEFResponseFilter, uCEFRunContextMenuCallback, uCEFRunFileDialogCallback, 
  uCEFSchemeHandlerFactory, uCEFSchemeRegistrar, uCEFSetCookieCallback, 
  uCEFSslCertPrincipal, uCEFSslInfo, uCEFStreamReader, uCEFStreamWriter, 
  uCEFStringList, uCEFStringMap, uCEFStringMultimap, uCEFStringVisitor, 
  uCEFTask, uCEFTaskRunner, uCEFTypes, uCEFUrlRequest, uCEFUrlrequestClient, 
  uCEFUrlRequestClientComponent, uCEFUrlRequestClientEvents, uCEFv8Accessor, 
  uCEFv8Context, uCEFV8Exception, uCEFv8Handler, uCEFv8StackFrame, 
  uCEFv8StackTrace, uCEFv8Types, uCEFv8Value, uCEFValue, uCEFWebPluginInfo, 
  uCEFWebPluginInfoVisitor, uCEFWebPluginUnstableCallback, uCEFWindowParent, 
  uCEFWorkScheduler, uCEFWorkSchedulerThread, uCEFWriteHandler, uCEFXmlReader, 
  uCEFZipReader, uFMXBufferPanel, uFMXChromium, uFMXWindowParent, 
  uFMXWorkScheduler, uOLEDragAndDrop, LazarusPackageIntf;

implementation

procedure Register;
begin
  RegisterUnit('uCEFUrlRequestClientComponent', 
    @uCEFUrlRequestClientComponent.Register);
end;

initialization
  RegisterPackage('OldCEF4Delphi', @Register);
end.
