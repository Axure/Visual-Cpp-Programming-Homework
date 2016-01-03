// MFC_ControlsDlg.h : header file
//

#if !defined(AFX_MFC_CONTROLSDLG_H__B962D0CC_7D68_4D27_BDDE_0A17FABD90E3__INCLUDED_)
#define AFX_MFC_CONTROLSDLG_H__B962D0CC_7D68_4D27_BDDE_0A17FABD90E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFC_ControlsDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CMFC_ControlsDlg dialog

class CMFC_ControlsDlg : public CDialog
{
	DECLARE_DYNAMIC(CMFC_ControlsDlg);
	friend class CMFC_ControlsDlgAutoProxy;

// Construction
public:
	CMFC_ControlsDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CMFC_ControlsDlg();

// Dialog Data
	//{{AFX_DATA(CMFC_ControlsDlg)
	enum { IDD = IDD_MFC_CONTROLS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ControlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMFC_ControlsDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CMFC_ControlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CONTROLSDLG_H__B962D0CC_7D68_4D27_BDDE_0A17FABD90E3__INCLUDED_)
