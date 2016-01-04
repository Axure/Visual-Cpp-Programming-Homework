// Student_InfoDlg.h : header file
//
#include <vector>
#include <map>
#include <string>
#include <sstream>


#if !defined(AFX_STUDENT_INFODLG_H__65F089A7_6184_4F06_886E_9891812DF646__INCLUDED_)
#define AFX_STUDENT_INFODLG_H__65F089A7_6184_4F06_886E_9891812DF646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudent_InfoDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlg dialog


class Student {
public:
	long student_id;
	std::string name;
	int gender;
	std::string department;
	int age;
	std::string toStr() {
		std::stringstream osstream;
		osstream
			<< "student id: " << this->student_id
			<< ", name: " << this->name
			<< ", gender: " << this->gender
			<< ", department: " << this->department
			<< ", age: " << this->age << std::endl;
		return osstream.str();
	}
};

class Department {
	
};


class CStudent_InfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudent_InfoDlg);
	friend class CStudent_InfoDlgAutoProxy;
	
private:
	std::map<long, Student> students;
	std::map<std::string, bool> departments;
	//std::vector<std::string> genders;
	std::map<int, std::string> genders;
// Construction
public:
	CStudent_InfoDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CStudent_InfoDlg();

// Dialog Data
	//{{AFX_DATA(CStudent_InfoDlg)
	enum { IDD = IDD_STUDENT_INFO_DIALOG };
	CListCtrl	m_lc_all;
	CListCtrl	m_lc_query;
	CComboBox	m_cb_department_input;
	CComboBox	m_cb_department;
	CComboBox	m_cb_gender;
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
	afx_msg void OnButton3();
	afx_msg void OnButtonAddClicked();
	afx_msg void OnSearchButtonClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENT_INFODLG_H__65F089A7_6184_4F06_886E_9891812DF646__INCLUDED_)
