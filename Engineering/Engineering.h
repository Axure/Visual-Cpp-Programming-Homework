// Engineering.h : main header file for the ENGINEERING application
//

#if !defined(AFX_ENGINEERING_H__8C70907D_FC3B_431D_9C36_B3455F7FD0F9__INCLUDED_)
#define AFX_ENGINEERING_H__8C70907D_FC3B_431D_9C36_B3455F7FD0F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEngineeringApp:
// See Engineering.cpp for the implementation of this class
//

class CEngineeringApp : public CWinApp
{
public:
	CEngineeringApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngineeringApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEngineeringApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGINEERING_H__8C70907D_FC3B_431D_9C36_B3455F7FD0F9__INCLUDED_)
