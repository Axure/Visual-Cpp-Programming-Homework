#if !defined(AFX_MYPAINTDIALOG_H__83FC1D23_566A_4527_9943_BFE514F9846E__INCLUDED_)
#define AFX_MYPAINTDIALOG_H__83FC1D23_566A_4527_9943_BFE514F9846E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyPaintDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyPaintDialog dialog

class CMyPaintDialog : public CDialog
{
// Construction
public:
	CMyPaintDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyPaintDialog)
	enum { IDD = IDD_DIALOG1 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPaintDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyPaintDialog)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPAINTDIALOG_H__83FC1D23_566A_4527_9943_BFE514F9846E__INCLUDED_)
