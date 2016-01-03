// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Dialog.h"
#include "DlgProxy.h"
#include "MFC_DialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_DialogDlgAutoProxy

IMPLEMENT_DYNCREATE(CMFC_DialogDlgAutoProxy, CCmdTarget)

CMFC_DialogDlgAutoProxy::CMFC_DialogDlgAutoProxy()
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
	ASSERT_KINDOF(CMFC_DialogDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CMFC_DialogDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CMFC_DialogDlgAutoProxy::~CMFC_DialogDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMFC_DialogDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFC_DialogDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CMFC_DialogDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFC_DialogDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMFC_DialogDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMFC_Dialog to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {656DD645-A3FA-4228-B80C-5CC39A651A45}
static const IID IID_IMFC_Dialog =
{ 0x656dd645, 0xa3fa, 0x4228, { 0xb8, 0xc, 0x5c, 0xc3, 0x9a, 0x65, 0x1a, 0x45 } };

BEGIN_INTERFACE_MAP(CMFC_DialogDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFC_DialogDlgAutoProxy, IID_IMFC_Dialog, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {588A1199-EC7E-4D27-845D-3A737258AB6C}
IMPLEMENT_OLECREATE2(CMFC_DialogDlgAutoProxy, "MFC_Dialog.Application", 0x588a1199, 0xec7e, 0x4d27, 0x84, 0x5d, 0x3a, 0x73, 0x72, 0x58, 0xab, 0x6c)

/////////////////////////////////////////////////////////////////////////////
// CMFC_DialogDlgAutoProxy message handlers
