; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_DialogDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_Dialog.h"
ODLFile=MFC_Dialog.odl

ClassCount=4
Class1=CMFC_DialogApp
Class2=CMFC_DialogDlg
Class3=CAboutDlg
Class4=CMFC_DialogDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_DIALOG_DIALOG

[CLS:CMFC_DialogApp]
Type=0
HeaderFile=MFC_Dialog.h
ImplementationFile=MFC_Dialog.cpp
Filter=N

[CLS:CMFC_DialogDlg]
Type=0
HeaderFile=MFC_DialogDlg.h
ImplementationFile=MFC_DialogDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_DialogDlg.h
ImplementationFile=MFC_DialogDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CMFC_DialogDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_MFC_DIALOG_DIALOG]
Type=1
Class=CMFC_DialogDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_HELP,button,1342242816
Control4=IDC_STATIC,static,1342308352

