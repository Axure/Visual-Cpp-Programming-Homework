// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Student_Info.h"
#include "DlgProxy.h"
#include "Student_InfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlgAutoProxy

IMPLEMENT_DYNCREATE(CStudent_InfoDlgAutoProxy, CCmdTarget)

CStudent_InfoDlgAutoProxy::CStudent_InfoDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CStudent_InfoDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CStudent_InfoDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CStudent_InfoDlgAutoProxy::~CStudent_InfoDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CStudent_InfoDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CStudent_InfoDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CStudent_InfoDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CStudent_InfoDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CStudent_InfoDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IStudent_Info to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D5F7D0FA-2547-4E9B-A981-F725901A48EF}
static const IID IID_IStudent_Info =
{ 0xd5f7d0fa, 0x2547, 0x4e9b, { 0xa9, 0x81, 0xf7, 0x25, 0x90, 0x1a, 0x48, 0xef } };

BEGIN_INTERFACE_MAP(CStudent_InfoDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CStudent_InfoDlgAutoProxy, IID_IStudent_Info, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {EB274D5A-9DB8-40DC-AA33-C8AD8636A8AF}
IMPLEMENT_OLECREATE2(CStudent_InfoDlgAutoProxy, "Student_Info.Application", 0xeb274d5a, 0x9db8, 0x40dc, 0xaa, 0x33, 0xc8, 0xad, 0x86, 0x36, 0xa8, 0xaf)

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlgAutoProxy message handlers
