// EngineeringDlg.h : header file
//

#if !defined(AFX_ENGINEERINGDLG_H__B60C12EF_D1DF_4AB8_8BFB_F9647A2E82E8__INCLUDED_)
#define AFX_ENGINEERINGDLG_H__B60C12EF_D1DF_4AB8_8BFB_F9647A2E82E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEngineeringDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CEngineeringDlg dialog

class CEngineeringDlg : public CDialog
{
	DECLARE_DYNAMIC(CEngineeringDlg);
	friend class CEngineeringDlgAutoProxy;

// Construction
public:
	CEngineeringDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CEngineeringDlg();

// Dialog Data
	//{{AFX_DATA(CEngineeringDlg)
	enum { IDD = IDD_ENGINEERING_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngineeringDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CEngineeringDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CEngineeringDlg)
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

#endif // !defined(AFX_ENGINEERINGDLG_H__B60C12EF_D1DF_4AB8_8BFB_F9647A2E82E8__INCLUDED_)
