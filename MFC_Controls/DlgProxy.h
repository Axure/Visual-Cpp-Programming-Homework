// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__561BFD58_E24D_45F4_AAD4_D691E708F0B1__INCLUDED_)
#define AFX_DLGPROXY_H__561BFD58_E24D_45F4_AAD4_D691E708F0B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFC_ControlsDlg;

/////////////////////////////////////////////////////////////////////////////
// CMFC_ControlsDlgAutoProxy command target

class CMFC_ControlsDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFC_ControlsDlgAutoProxy)

	CMFC_ControlsDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CMFC_ControlsDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ControlsDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMFC_ControlsDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CMFC_ControlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMFC_ControlsDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMFC_ControlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__561BFD58_E24D_45F4_AAD4_D691E708F0B1__INCLUDED_)
