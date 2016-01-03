; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_ControlsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_Controls.h"
ODLFile=MFC_Controls.odl

ClassCount=4
Class1=CMFC_ControlsApp
Class2=CMFC_ControlsDlg
Class3=CAboutDlg
Class4=CMFC_ControlsDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_CONTROLS_DIALOG

[CLS:CMFC_ControlsApp]
Type=0
HeaderFile=MFC_Controls.h
ImplementationFile=MFC_Controls.cpp
Filter=N

[CLS:CMFC_ControlsDlg]
Type=0
HeaderFile=MFC_ControlsDlg.h
ImplementationFile=MFC_ControlsDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_ControlsDlg.h
ImplementationFile=MFC_ControlsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CMFC_ControlsDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_MFC_CONTROLS_DIALOG]
Type=1
Class=CMFC_ControlsDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_HELP,button,1342242816

