// MFC_Dialog.h : main header file for the MFC_DIALOG application
//

#if !defined(AFX_MFC_DIALOG_H__6503F5E3_CD56_4437_9F85_DC6F9CDBA1E5__INCLUDED_)
#define AFX_MFC_DIALOG_H__6503F5E3_CD56_4437_9F85_DC6F9CDBA1E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_DialogApp:
// See MFC_Dialog.cpp for the implementation of this class
//

class CMFC_DialogApp : public CWinApp
{
public:
	CMFC_DialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_DialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_DIALOG_H__6503F5E3_CD56_4437_9F85_DC6F9CDBA1E5__INCLUDED_)
