// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__F4EC0925_D78E_4348_A0FA_FE54103A54DD__INCLUDED_)
#define AFX_DLGPROXY_H__F4EC0925_D78E_4348_A0FA_FE54103A54DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudent_InfoDlg;

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlgAutoProxy command target

class CStudent_InfoDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CStudent_InfoDlgAutoProxy)

	CStudent_InfoDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CStudent_InfoDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudent_InfoDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStudent_InfoDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CStudent_InfoDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CStudent_InfoDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CStudent_InfoDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__F4EC0925_D78E_4348_A0FA_FE54103A54DD__INCLUDED_)
