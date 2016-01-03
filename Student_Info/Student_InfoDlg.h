// Student_InfoDlg.h : header file
//

#if !defined(AFX_STUDENT_INFODLG_H__65F089A7_6184_4F06_886E_9891812DF646__INCLUDED_)
#define AFX_STUDENT_INFODLG_H__65F089A7_6184_4F06_886E_9891812DF646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudent_InfoDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlg dialog

class CStudent_InfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudent_InfoDlg);
	friend class CStudent_InfoDlgAutoProxy;

// Construction
public:
	CStudent_InfoDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CStudent_InfoDlg();

// Dialog Data
	//{{AFX_DATA(CStudent_InfoDlg)
	enum { IDD = IDD_STUDENT_INFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudent_InfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CStudent_InfoDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CStudent_InfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENT_INFODLG_H__65F089A7_6184_4F06_886E_9891812DF646__INCLUDED_)