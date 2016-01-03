@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by MFC_DIALOG.HPJ. >"hlp\MFC_Dialog.hm"
echo. >>"hlp\MFC_Dialog.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\MFC_Dialog.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\MFC_Dialog.hm"
echo. >>"hlp\MFC_Dialog.hm"
echo // Prompts (IDP_*) >>"hlp\MFC_Dialog.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\MFC_Dialog.hm"
echo. >>"hlp\MFC_Dialog.hm"
echo // Resources (IDR_*) >>"hlp\MFC_Dialog.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\MFC_Dialog.hm"
echo. >>"hlp\MFC_Dialog.hm"
echo // Dialogs (IDD_*) >>"hlp\MFC_Dialog.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\MFC_Dialog.hm"
echo. >>"hlp\MFC_Dialog.hm"
echo // Frame Controls (IDW_*) >>"hlp\MFC_Dialog.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\MFC_Dialog.hm"
REM -- Make help for Project MFC_DIALOG


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\MFC_Dialog.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\MFC_Dialog.hlp" goto :Error
if not exist "hlp\MFC_Dialog.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\MFC_Dialog.hlp" Debug
if exist Debug\nul copy "hlp\MFC_Dialog.cnt" Debug
if exist Release\nul copy "hlp\MFC_Dialog.hlp" Release
if exist Release\nul copy "hlp\MFC_Dialog.cnt" Release
echo.
goto :done

:Error
echo hlp\MFC_Dialog.hpj(1) : error: Problem encountered creating help file

:done
echo.
