// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Controls.h"
#include "DlgProxy.h"
#include "MFC_ControlsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_ControlsDlgAutoProxy

IMPLEMENT_DYNCREATE(CMFC_ControlsDlgAutoProxy, CCmdTarget)

CMFC_ControlsDlgAutoProxy::CMFC_ControlsDlgAutoProxy()
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
	ASSERT_KINDOF(CMFC_ControlsDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CMFC_ControlsDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CMFC_ControlsDlgAutoProxy::~CMFC_ControlsDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMFC_ControlsDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFC_ControlsDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CMFC_ControlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFC_ControlsDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMFC_ControlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMFC_Controls to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {0D589A1D-B181-42B6-B14F-455DED37B9E2}
static const IID IID_IMFC_Controls =
{ 0xd589a1d, 0xb181, 0x42b6, { 0xb1, 0x4f, 0x45, 0x5d, 0xed, 0x37, 0xb9, 0xe2 } };

BEGIN_INTERFACE_MAP(CMFC_ControlsDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFC_ControlsDlgAutoProxy, IID_IMFC_Controls, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {0A24548A-D274-492A-8180-488416FCCDD1}
IMPLEMENT_OLECREATE2(CMFC_ControlsDlgAutoProxy, "MFC_Controls.Application", 0xa24548a, 0xd274, 0x492a, 0x81, 0x80, 0x48, 0x84, 0x16, 0xfc, 0xcd, 0xd1)

/////////////////////////////////////////////////////////////////////////////
// CMFC_ControlsDlgAutoProxy message handlers
