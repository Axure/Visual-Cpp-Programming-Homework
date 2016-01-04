// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__A951A21E_6920_40E4_A007_EE4553EFC66C__INCLUDED_)
#define AFX_DLGPROXY_H__A951A21E_6920_40E4_A007_EE4553EFC66C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEngineeringDlg;

/////////////////////////////////////////////////////////////////////////////
// CEngineeringDlgAutoProxy command target

class CEngineeringDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CEngineeringDlgAutoProxy)

	CEngineeringDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CEngineeringDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngineeringDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CEngineeringDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CEngineeringDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CEngineeringDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CEngineeringDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__A951A21E_6920_40E4_A007_EE4553EFC66C__INCLUDED_)
