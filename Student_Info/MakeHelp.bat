@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by STUDENT_INFO.HPJ. >"hlp\Student_Info.hm"
echo. >>"hlp\Student_Info.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Student_Info.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Student_Info.hm"
echo. >>"hlp\Student_Info.hm"
echo // Prompts (IDP_*) >>"hlp\Student_Info.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Student_Info.hm"
echo. >>"hlp\Student_Info.hm"
echo // Resources (IDR_*) >>"hlp\Student_Info.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Student_Info.hm"
echo. >>"hlp\Student_Info.hm"
echo // Dialogs (IDD_*) >>"hlp\Student_Info.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Student_Info.hm"
echo. >>"hlp\Student_Info.hm"
echo // Frame Controls (IDW_*) >>"hlp\Student_Info.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Student_Info.hm"
REM -- Make help for Project STUDENT_INFO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Student_Info.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Student_Info.hlp" goto :Error
if not exist "hlp\Student_Info.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Student_Info.hlp" Debug
if exist Debug\nul copy "hlp\Student_Info.cnt" Debug
if exist Release\nul copy "hlp\Student_Info.hlp" Release
if exist Release\nul copy "hlp\Student_Info.cnt" Release
echo.
goto :done

:Error
echo hlp\Student_Info.hpj(1) : error: Problem encountered creating help file

:done
echo.
