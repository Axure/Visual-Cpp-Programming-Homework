// MyPaintDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Controls.h"
#include "MyPaintDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyPaintDialog dialog


CMyPaintDialog::CMyPaintDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyPaintDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyPaintDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyPaintDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyPaintDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyPaintDialog, CDialog)
	//{{AFX_MSG_MAP(CMyPaintDialog)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPaintDialog message handlers

void CMyPaintDialog::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.Rectangle(10,10,50,50);
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
