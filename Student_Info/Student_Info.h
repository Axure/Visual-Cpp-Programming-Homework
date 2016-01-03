// Student_Info.h : main header file for the STUDENT_INFO application
//

#if !defined(AFX_STUDENT_INFO_H__BE650990_0F1F_4ACC_B075_E8941FABFCA2__INCLUDED_)
#define AFX_STUDENT_INFO_H__BE650990_0F1F_4ACC_B075_E8941FABFCA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoApp:
// See Student_Info.cpp for the implementation of this class
//

class CStudent_InfoApp : public CWinApp
{
public:
	CStudent_InfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudent_InfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStudent_InfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENT_INFO_H__BE650990_0F1F_4ACC_B075_E8941FABFCA2__INCLUDED_)
