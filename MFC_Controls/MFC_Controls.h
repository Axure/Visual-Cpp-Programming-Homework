// MFC_Controls.h : main header file for the MFC_CONTROLS application
//

#if !defined(AFX_MFC_CONTROLS_H__C7500999_017A_4D6B_848D_2810FD3F2FE8__INCLUDED_)
#define AFX_MFC_CONTROLS_H__C7500999_017A_4D6B_848D_2810FD3F2FE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_ControlsApp:
// See MFC_Controls.cpp for the implementation of this class
//

class CMFC_ControlsApp : public CWinApp
{
public:
	CMFC_ControlsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ControlsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_ControlsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CONTROLS_H__C7500999_017A_4D6B_848D_2810FD3F2FE8__INCLUDED_)
