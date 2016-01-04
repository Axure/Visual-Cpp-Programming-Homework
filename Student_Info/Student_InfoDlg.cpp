// Student_InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student_Info.h"
#include "Student_InfoDlg.h"
#include "DlgProxy.h"
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlg dialog

IMPLEMENT_DYNAMIC(CStudent_InfoDlg, CDialog);

CStudent_InfoDlg::CStudent_InfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudent_InfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudent_InfoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CStudent_InfoDlg::~CStudent_InfoDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CStudent_InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudent_InfoDlg)
	DDX_Control(pDX, IDC_LIST6, m_lc_all);
	DDX_Control(pDX, IDC_LIST2, m_lc_query);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT_INPUT, m_cb_department_input);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT, m_cb_department);
	DDX_Control(pDX, IDC_COMBO_GENDER, m_cb_gender);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudent_InfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStudent_InfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnSearchButtonClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudent_InfoDlg message handlers

BOOL CStudent_InfoDlg::OnInitDialog()
{
	
	//this->genders.push_back(std::string("fsdf"));
	this->genders[0] = std::string("男的");
	this->genders[1] = std::string("女的");
	this->departments["数学系"] = true;
	this->departments["计算机系"] = true;

	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	for (std::map<std::string, bool>::iterator it = this->departments.begin(); it != departments.end(); ++it)
	{
		m_cb_department.AddString(it->first.c_str());
		m_cb_department_input.AddString(it->first.c_str());
	}
	
	m_cb_gender.AddString(CString("男"));
	m_cb_gender.AddString(CString("女"));
	//MessageBox("haha");
	CComboBoxEx *pGenderCombo = reinterpret_cast<CComboBoxEx*>(GetDlgItem(IDC_COMBO_GENDER));
	pGenderCombo->SetCurSel(0);
	//COMBOBOXEXITEM  item;
	//ZeroMemory(&item, sizeof(item));
	//item.mask = CBEIF_TEXT;
	//item.iItem = 0;
	//item.pszText = _T("Hello");
	//pGenderCombo->InsertItem(&item);
	// 
	m_lc_all.InsertColumn(0, "学号");
	m_lc_all.SetColumnWidth(0, 80);
	m_lc_all.InsertColumn(1, "姓名");
	m_lc_all.SetColumnWidth(1, 60);
	m_lc_all.InsertColumn(2, "性别");
	m_lc_all.SetColumnWidth(2, 40);
	m_lc_all.InsertColumn(3, "年龄");
	m_lc_all.SetColumnWidth(3, 40);
	m_lc_all.InsertColumn(4, "学院");
	m_lc_all.SetColumnWidth(4, 80);

	m_lc_query.InsertColumn(0, "学号");
	m_lc_query.SetColumnWidth(0, 80);
	m_lc_query.InsertColumn(1, "姓名");
	m_lc_query.SetColumnWidth(1, 60);
	m_lc_query.InsertColumn(2, "性别");
	m_lc_query.SetColumnWidth(2, 40);
	m_lc_query.InsertColumn(3, "年龄");
	m_lc_query.SetColumnWidth(3, 40);
	m_lc_query.InsertColumn(4, "学院");
	m_lc_query.SetColumnWidth(4, 80);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudent_InfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CStudent_InfoDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudent_InfoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudent_InfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CStudent_InfoDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CStudent_InfoDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CStudent_InfoDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CStudent_InfoDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CStudent_InfoDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	
	CString str;
	//std::string str;
	CString gender;
	

	
	/************************************************************************/
	/* Build the new student.                                                                     */
	/************************************************************************/
	Student newStudent;

	GetDlgItemText(IDC_EDIT_NAME, str);
	newStudent.name = (LPCTSTR)(str);

	GetDlgItemText(IDC_EDIT_STUDENT_ID, str);
	//std::istringstream((LPCTSTR)str) >> newStudent.student_id;
	newStudent.student_id = atoi(str);

	CComboBoxEx *pGenderCombo = reinterpret_cast<CComboBoxEx*>(GetDlgItem(IDC_COMBO_GENDER));
	int a = pGenderCombo->GetCurSel();
	newStudent.gender = a;

	GetDlgItemText(IDC_COMBO_DEPARTMENT_INPUT, str);
	newStudent.department = (LPCTSTR)(str);

	GetDlgItemText(IDC_EDIT_AGE, str);
	//std::istringstream((LPCTSTR)str) >> newStudent.age;
	newStudent.age = atoi(str);
	/************************************************************************/
	/* Get the index of the age combo.                                                                     */
	/************************************************************************/
	std::ostringstream sstream;
	sstream << a;
	GetDlgItemText(IDC_EDIT_NAME, str);
	//MessageBox(CString(sstream.str().c_str()));

	if (this->students.find(newStudent.student_id) != this->students.end()) {
		
		MessageBox("已经有了！");
	} else {
		this->students[newStudent.student_id] = (newStudent);
		
		LVITEM lvi;
		CString strItem;
		char cstudent_id[100];
		char cage[100];
		lvi.mask =  LVIF_IMAGE | LVIF_TEXT;
		lvi.iItem = 0;
		lvi.iSubItem = 0;
		lvi.pszText = itoa(newStudent.student_id, cstudent_id, 10);
		m_lc_all.InsertItem(&lvi);
		lvi.iSubItem = 1;
		lvi.pszText = (char*)newStudent.name.c_str();
		m_lc_all.SetItem(&lvi);
		lvi.pszText = (char*)this->genders[newStudent.gender].c_str();
		lvi.iSubItem = 2;
		m_lc_all.SetItem(&lvi);
		lvi.iSubItem = 3;
		lvi.pszText = itoa(newStudent.age, cage, 10);
		m_lc_all.SetItem(&lvi);
		lvi.iSubItem = 4;
		lvi.pszText = (char*)newStudent.department.c_str();
		m_lc_all.SetItem(&lvi);
		
		MessageBox("新的学生加入了！");
	}
	
}

void CStudent_InfoDlg::OnSearchButtonClicked() 
{
	// TODO: Add your control notification handler code here
	CString str_name, str_stu_id, str_dep;
	m_lc_query.DeleteAllItems();
	GetDlgItemText(IDC_NAME_SEARCH, str_name);
	GetDlgItemText(IDC_STUDENT_ID_SEARCH, str_stu_id);
	GetDlgItemText(IDC_COMBO_DEPARTMENT, str_dep);

	int flag;
	for (std::map<long, Student>::iterator it = this->students.begin(); it != students.end(); ++it)
	{
		flag = 0;
		if (str_stu_id.GetLength() != 0) {
			if (atoi(str_stu_id) != it->second.student_id) flag = 1;
		}
		if (str_name.GetLength() != 0) {
			if (str_name.Compare(it->second.name.c_str()) != 0) flag = 1;
		}
		if (str_dep.GetLength() != 0) {
			if (str_dep.Compare(it->second.department.c_str()) != 0) flag = 1;
		}
		if (flag == 0) {
			LVITEM lvi;
			CString strItem;
			char cstudent_id[100];
			char cage[100];
			lvi.mask =  LVIF_IMAGE | LVIF_TEXT;
			lvi.iItem = 0;
			lvi.iSubItem = 0;
			lvi.pszText = itoa(it->second.student_id, cstudent_id, 10);
			m_lc_query.InsertItem(&lvi);
			lvi.iSubItem = 1;
			lvi.pszText = (char*)it->second.name.c_str();
			m_lc_query.SetItem(&lvi);
			lvi.pszText = (char*)this->genders[it->second.gender].c_str();
			lvi.iSubItem = 2;
			m_lc_query.SetItem(&lvi);
			lvi.iSubItem = 3;
			lvi.pszText = itoa(it->second.age, cage, 10);
			m_lc_query.SetItem(&lvi);
			lvi.iSubItem = 4;
			lvi.pszText = (char*)it->second.department.c_str();
			m_lc_query.SetItem(&lvi);
		}
	}
	
}
