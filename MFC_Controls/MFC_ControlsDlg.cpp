// MFC_ControlsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Controls.h"
#include "MFC_ControlsDlg.h"
#include "MyPaintDialog.h"
#include "DlgProxy.h"
#include <sstream>
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
// CMFC_ControlsDlg dialog

IMPLEMENT_DYNAMIC(CMFC_ControlsDlg, CDialog);

CMFC_ControlsDlg::CMFC_ControlsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_ControlsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_ControlsDlg)
	m_radio_fill = -1;
	m_radio_line = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CMFC_ControlsDlg::~CMFC_ControlsDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMFC_ControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_ControlsDlg)
	DDX_Control(pDX, IDC_LIST1, m_lb_shape);
	DDX_Control(pDX, IDC_COMBO2, m_cb_brush);
	DDX_Control(pDX, IDC_COMBO1, m_cb_pen);
	DDX_Radio(pDX, IDC_RADIO1, m_radio_fill);
	DDX_Radio(pDX, IDC_RADIO5, m_radio_line);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_ControlsDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_ControlsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonClicked)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_RADIO8, OnRadio8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_ControlsDlg message handlers

BOOL CMFC_ControlsDlg::OnInitDialog()
{
	this->shapeTexts.push_back(CString("Line"));
	this->shapeTexts.push_back(CString("Circle"));
	this->shapeTexts.push_back(CString("Rectangle"));
	this->shapeTexts.push_back(CString("RoundRectangle"));
	
	this->penColorTexts.push_back(CString("Red"));
	this->penColorTexts.push_back(CString("Green"));
	this->penColorTexts.push_back(CString("Blue"));

	this->brushColorTexts.push_back(CString("Red"));
	this->brushColorTexts.push_back(CString("Green"));
	this->brushColorTexts.push_back(CString("Blue"));

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
	std::vector<CString>::iterator it;
	for (it = this->shapeTexts.begin(); it != this->shapeTexts.end(); ++it)
	{
		m_lb_shape.AddString(*it);
	}
	m_lb_shape.SetCurSel(0);
	for (it = this->penColorTexts.begin(); it != this->penColorTexts.end(); ++it)
	{
		m_cb_pen.AddString(*it);
	}
	m_cb_pen.SetCurSel(0);
	for (it = this->brushColorTexts.begin(); it != this->brushColorTexts.end(); ++it)
	{
		m_cb_brush.AddString(*it);
	}
	m_cb_brush.SetCurSel(0);
	m_radio_line = 0;
	m_radio_fill = 0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_ControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_ControlsDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_ControlsDlg::OnPaint() 
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
HCURSOR CMFC_ControlsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CMFC_ControlsDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CMFC_ControlsDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CMFC_ControlsDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CMFC_ControlsDlg::CanExit()
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

void CMFC_ControlsDlg::OnButtonClicked() 
{
	this->shape = m_lb_shape.GetCurSel();
	this->penColor = m_cb_pen.GetCurSel();
	this->brushColor = m_cb_brush.GetCurSel();
	this->lineStyle = m_radio_line;
	this->fillStyle = m_radio_fill;
	std::ostringstream osstream;
	osstream
		<< "Shape: " << this->shape
		<< ", Pen Color" <<this->penColor
		<< ", Brush Color" <<this->brushColor
		<< ", Line Style" <<this->lineStyle
		<< ", Fill Style" <<this->fillStyle;
	MessageBox(osstream.str().c_str());
	// TODO: Add your control notification handler code here
	CMyPaintDialog* pMainWnd = new CMyPaintDialog(
			this->shape,
			this->penColor,
			this->brushColor,
			this->lineStyle,
			this->fillStyle
		);
	pMainWnd->Create(IDD_DIALOG1);
	pMainWnd->ShowWindow(TRUE);
}

void CMFC_ControlsDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_radio_fill = 0;
}

void CMFC_ControlsDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_radio_fill = 1;
}

void CMFC_ControlsDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_radio_fill = 2;
}

void CMFC_ControlsDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	m_radio_fill = 3;
}

void CMFC_ControlsDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	m_radio_line = 0;
}

void CMFC_ControlsDlg::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	m_radio_line = 1;
}

void CMFC_ControlsDlg::OnRadio7() 
{
	// TODO: Add your control notification handler code here
	m_radio_line = 2;
}

void CMFC_ControlsDlg::OnRadio8() 
{
	// TODO: Add your control notification handler code here
	m_radio_line = 3;
}
