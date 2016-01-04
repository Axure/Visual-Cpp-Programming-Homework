@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by ENGINEERING.HPJ. >"hlp\Engineering.hm"
echo. >>"hlp\Engineering.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Engineering.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Engineering.hm"
echo. >>"hlp\Engineering.hm"
echo // Prompts (IDP_*) >>"hlp\Engineering.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Engineering.hm"
echo. >>"hlp\Engineering.hm"
echo // Resources (IDR_*) >>"hlp\Engineering.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Engineering.hm"
echo. >>"hlp\Engineering.hm"
echo // Dialogs (IDD_*) >>"hlp\Engineering.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Engineering.hm"
echo. >>"hlp\Engineering.hm"
echo // Frame Controls (IDW_*) >>"hlp\Engineering.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Engineering.hm"
REM -- Make help for Project ENGINEERING


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Engineering.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Engineering.hlp" goto :Error
if not exist "hlp\Engineering.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Engineering.hlp" Debug
if exist Debug\nul copy "hlp\Engineering.cnt" Debug
if exist Release\nul copy "hlp\Engineering.hlp" Release
if exist Release\nul copy "hlp\Engineering.cnt" Release
echo.
goto :done

:Error
echo hlp\Engineering.hpj(1) : error: Problem encountered creating help file

:done
echo.
