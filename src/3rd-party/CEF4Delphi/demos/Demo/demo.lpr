program demo;

{$mode objfpc}{$H+}

{$APPTYPE CONSOLE}
uses
  Forms,
  Interfaces,
  uCEFApplication,
  uCEFConstants,
  uDemo { you can add units after this };

  {$R *.res}


begin
  WriteLn('run');
  GlobalCEFApp := TCefApplication.Create;
  //GlobalCEFApp.LogSeverity := LOGSEVERITY_INFO;
  //GlobalCEFApp.LogFile := 'D:\app.exe\energy\EnergyFramework32_49\log.log';
  GlobalCEFApp.FrameworkDirPath := 'D:\app.exe\energy\EnergyFramework64_49\';
  //GlobalCEFApp.NoSandbox := False;
  //GlobalCEFApp.SingleProcess:=true;
  // In case you want to use custom directories for the CEF3 binaries, cache, cookies and user data.
  // If you don't set a cache directory the browser will use in-memory cache.
{
  GlobalCEFApp.FrameworkDirPath     := 'cef';
  GlobalCEFApp.ResourcesDirPath     := 'cef';
  GlobalCEFApp.LocalesDirPath       := 'cef\locales';
  GlobalCEFApp.EnableGPU            := True;      // Enable hardware acceleration
  GlobalCEFApp.DisableGPUCache      := True;      // Disable the creation of a 'GPUCache' directory in the hard drive.
  GlobalCEFApp.cache                := 'cef\cache';
  GlobalCEFApp.cookies              := 'cef\cookies';
  GlobalCEFApp.UserDataPath         := 'cef\User Data';
}

  // You *MUST* call GlobalCEFApp.StartMainProcess in a if..then clause
  // with the Application initialization inside the begin..end.
  // Read this https://www.briskbard.com/index.php?lang=en&pageid=cef
  if GlobalCEFApp.StartMainProcess then
  begin
    //RequireDerivedFormResource := True;
    //Application.Scaled := True;
  Application.Scaled:=True;
    Application.Initialize;
    Application.CreateForm(TForm1, Form1);
    Application.Run;
  end;

  GlobalCEFApp.Free;
  GlobalCEFApp := nil;
end.
