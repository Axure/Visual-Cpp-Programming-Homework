// MFC_DialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Dialog.h"
#include "MFC_DialogDlg.h"
#include "DlgProxy.h"

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
// CMFC_DialogDlg dialog

IMPLEMENT_DYNAMIC(CMFC_DialogDlg, CDialog);

CMFC_DialogDlg::CMFC_DialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_DialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_DialogDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CMFC_DialogDlg::~CMFC_DialogDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMFC_DialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_DialogDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_DialogDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_DialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER2, OnOutofmemorySlider2)
	ON_BN_CLICKED(IDC_CANCEL_BUTTON, OnCancelButtonClicked)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER1, OnOutofmemorySlider1)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_DialogDlg message handlers

BOOL CMFC_DialogDlg::OnInitDialog()
{
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
	CProgressCtrl *pProg = reinterpret_cast<CProgressCtrl*>(GetDlgItem(IDC_PROGRESS1));
	pProg->SetRange(0, 100);
	pProg->SetPos(33);

	CString strText1;
	CSliderCtrl *pSlide1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	pSlide1->SetRange(1, 100);
	pSlide1->SetPos(50);
	strText1.Format("%d", pSlide1->GetPos());
	SetDlgItemText(IDC_STATIC_SLIDER_1, strText1);

	CString strText2;
	CSliderCtrl *pSlide2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
	pSlide2->SetRange(4.0, 16.0);
	pSlide2->SetPos(8.0);
	strText2.Format("%d", pSlide2->GetPos());
	SetDlgItemText(IDC_STATIC_SLIDER_2, strText2);
	
	HICON hIcon[8];
	int n;
	m_imageList.Create(16, 16, 0, 8, 8);
	int icons[8] = {
		IDI_ICON_WHITE, IDI_ICON_BLACK, IDI_ICON_RED, IDI_ICON_BLUE,
		IDI_ICON_YELLOW, IDI_ICON_CYAN, IDI_ICON_PURPLE, IDI_ICON_GREEN
	};
	int i;
	for (i = 0; i < 8; ++i)
	{
		hIcon[i] = AfxGetApp()->LoadIcon(icons[i]);
		m_imageList.Add(hIcon[i]);
	}
	static char *color[] = {"white", "black", "red", "blue", "yellow", "cyan", "purple", "green"};
	CListCtrl *pList = reinterpret_cast<CListCtrl*>(GetDlgItem(IDC_LIST2));
	pList->SetImageList(&m_imageList, LVSIL_NORMAL);
	for (i = 0; i < 8; ++i)
	{
		pList->InsertItem(i, color[i], i);
	}
	pList->SetBkColor(RGB(222,222,222));
	pList->SetTextBkColor(RGB(233,233,233));

	CTreeCtrl *pTree = reinterpret_cast<CTreeCtrl*>(GetDlgItem(IDC_TREE1));
	pTree->SetImageList(&m_imageList, TVSIL_NORMAL);

	TV_INSERTSTRUCT tvinsert;
	tvinsert.hParent = NULL;
	tvinsert.hInsertAfter = TVI_LAST;
	tvinsert.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT;

	tvinsert.item.hItem = NULL;
	tvinsert.item.state = 0;
	tvinsert.item.stateMask = 0;
	tvinsert.item.cchTextMax = 0;
	tvinsert.item.iSelectedImage = 1;
	tvinsert.item.cChildren = 0;
	tvinsert.item.lParam = 0;

	tvinsert.item.iImage = 2;
	tvinsert.item.pszText = "Homer";
	HTREEITEM hDad = pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "Marge";
	HTREEITEM hMom = pTree->InsertItem(&tvinsert);

	tvinsert.hParent = hDad;
	tvinsert.item.pszText = "??";
	pTree->InsertItem(&tvinsert);

	tvinsert.hParent = hMom;
	pTree->InsertItem(&tvinsert);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_DialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_DialogDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_DialogDlg::OnPaint() 
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
HCURSOR CMFC_DialogDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CMFC_DialogDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CMFC_DialogDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CMFC_DialogDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CMFC_DialogDlg::CanExit()
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

void CMFC_DialogDlg::OnOutofmemorySlider2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CMFC_DialogDlg::OnCancelButtonClicked() 
{
	// TODO: Add your control notification handler code here
	MessageBox(NULL);
	
}

void CMFC_DialogDlg::OnOutofmemorySlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	MessageBox(NULL);
	*pResult = 0;
}

void CMFC_DialogDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar) 
{
	// TODO: Add your control notification handler code here
	CSliderCtrl *pSlide = reinterpret_cast<CSliderCtrl*>(pScrollBar);
	CString strText;
		strText.Format("%d", pSlide->GetPos());
	switch (pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER1:
		SetDlgItemText(IDC_STATIC_SLIDER_1, strText);
		break;
	case IDC_SLIDER2:
		SetDlgItemText(IDC_STATIC_SLIDER_2, strText);
		break;
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
