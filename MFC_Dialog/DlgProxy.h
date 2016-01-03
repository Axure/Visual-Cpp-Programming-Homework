// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__FEAE9DFA_5515_432E_A1C1_60C2958DD2C4__INCLUDED_)
#define AFX_DLGPROXY_H__FEAE9DFA_5515_432E_A1C1_60C2958DD2C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFC_DialogDlg;

/////////////////////////////////////////////////////////////////////////////
// CMFC_DialogDlgAutoProxy command target

class CMFC_DialogDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFC_DialogDlgAutoProxy)

	CMFC_DialogDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CMFC_DialogDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DialogDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMFC_DialogDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CMFC_DialogDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMFC_DialogDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMFC_DialogDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__FEAE9DFA_5515_432E_A1C1_60C2958DD2C4__INCLUDED_)
