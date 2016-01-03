// MFC_DialogDlg.h : header file
//

#if !defined(AFX_MFC_DIALOGDLG_H__6BD0BCF3_1BF8_4F22_BF42_3CE7C0B97856__INCLUDED_)
#define AFX_MFC_DIALOGDLG_H__6BD0BCF3_1BF8_4F22_BF42_3CE7C0B97856__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFC_DialogDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CMFC_DialogDlg dialog

class CMFC_DialogDlg : public CDialog
{
	DECLARE_DYNAMIC(CMFC_DialogDlg);
	friend class CMFC_DialogDlgAutoProxy;

// Construction
public:
	CMFC_DialogDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CMFC_DialogDlg();

// Dialog Data
	//{{AFX_DATA(CMFC_DialogDlg)
	enum { IDD = IDD_MFC_DIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMFC_DialogDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CMFC_DialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOutofmemorySlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCancelButtonClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_DIALOGDLG_H__6BD0BCF3_1BF8_4F22_BF42_3CE7C0B97856__INCLUDED_)
