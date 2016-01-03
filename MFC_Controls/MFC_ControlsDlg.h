// MFC_ControlsDlg.h : header file
//
#include <vector>
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
private:
	int shape;
	int penColor;
	int brushColor;
	int lineStyle;
	int fillStyle;

	std::vector<CString> shapeTexts;
	std::vector<CString> penColorTexts;
	std::vector<CString> brushColorTexts;
	std::vector<CString> lineStyleTexts;
	std::vector<CString> fillStyleTexts;
// Construction
public:
	CMFC_ControlsDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CMFC_ControlsDlg();

// Dialog Data
	//{{AFX_DATA(CMFC_ControlsDlg)
	enum { IDD = IDD_MFC_CONTROLS_DIALOG };
	CListBox	m_lb_shape;
	CComboBox	m_cb_brush;
	CComboBox	m_cb_pen;
	int		m_radio_fill;
	int		m_radio_line;
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
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	afx_msg void OnRadio8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CONTROLSDLG_H__B962D0CC_7D68_4D27_BDDE_0A17FABD90E3__INCLUDED_)
