// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Engineering.h"
#include "DlgProxy.h"
#include "EngineeringDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEngineeringDlgAutoProxy

IMPLEMENT_DYNCREATE(CEngineeringDlgAutoProxy, CCmdTarget)

CEngineeringDlgAutoProxy::CEngineeringDlgAutoProxy()
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
	ASSERT_KINDOF(CEngineeringDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CEngineeringDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CEngineeringDlgAutoProxy::~CEngineeringDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CEngineeringDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CEngineeringDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CEngineeringDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CEngineeringDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CEngineeringDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IEngineering to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {AD9247D8-5DFD-4E0C-8FDB-21E18B095D18}
static const IID IID_IEngineering =
{ 0xad9247d8, 0x5dfd, 0x4e0c, { 0x8f, 0xdb, 0x21, 0xe1, 0x8b, 0x9, 0x5d, 0x18 } };

BEGIN_INTERFACE_MAP(CEngineeringDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CEngineeringDlgAutoProxy, IID_IEngineering, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {14572EBA-10AE-4F0E-BA41-30BC7C2FFDC7}
IMPLEMENT_OLECREATE2(CEngineeringDlgAutoProxy, "Engineering.Application", 0x14572eba, 0x10ae, 0x4f0e, 0xba, 0x41, 0x30, 0xbc, 0x7c, 0x2f, 0xfd, 0xc7)

/////////////////////////////////////////////////////////////////////////////
// CEngineeringDlgAutoProxy message handlers
