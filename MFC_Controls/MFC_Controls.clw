; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_ControlsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_Controls.h"
ODLFile=MFC_Controls.odl

ClassCount=5
Class1=CMFC_ControlsApp
Class2=CMFC_ControlsDlg
Class3=CAboutDlg
Class4=CMFC_ControlsDlgAutoProxy

ResourceCount=4
Resource1=IDD_MFC_CONTROLS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class5=CMyPaintDialog
Resource4=IDD_DIALOG1

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
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO1

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_ControlsDlg.h
ImplementationFile=MFC_ControlsDlg.cpp
Filter=D
LastObject=CAboutDlg

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
LastObject=CMFC_ControlsDlgAutoProxy

[DLG:IDD_MFC_CONTROLS_DIALOG]
Type=1
Class=CMFC_ControlsDlg
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_LIST1,listbox,1352728835
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO1,combobox,1344340227
Control7=IDC_COMBO2,combobox,1344340227
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTTON1,button,1342242816
Control11=IDC_RADIO1,button,1342177289
Control12=IDC_RADIO2,button,1342177289
Control13=IDC_RADIO3,button,1342177289
Control14=IDC_RADIO4,button,1342177289
Control15=IDC_RADIO5,button,1342177289
Control16=IDC_RADIO6,button,1342177289
Control17=IDC_RADIO7,button,1342177289
Control18=IDC_RADIO8,button,1342177289

[CLS:CMyPaintDialog]
Type=0
HeaderFile=MyPaintDialog.h
ImplementationFile=MyPaintDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyPaintDialog

[DLG:IDD_DIALOG1]
Type=1
Class=CMyPaintDialog
ControlCount=0

