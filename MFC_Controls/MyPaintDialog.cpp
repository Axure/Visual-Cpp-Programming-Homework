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

CMyPaintDialog::CMyPaintDialog(int shape, int penColor, int brushColor, int lineStyle, int fillStyle, CWnd* pParent /*=NULL*/)
: CDialog(CMyPaintDialog::IDD, pParent)
{
	this->shape = shape;
	this->penColor = penColor;
	this->brushColor = brushColor;
	this->lineStyle = lineStyle;
	this->fillStyle = fillStyle;
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

	CPen pen;
	int penStyles[4] = {PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT};
	COLORREF penColors[3] = {RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255)};
	pen.CreatePen(penStyles[this->lineStyle], 3, penColors[this->penColor]);
	dc.SelectObject(&pen);

	CBrush brush;
	int brushStyles[4] = {BS_SOLID, HS_CROSS, HS_FDIAGONAL, HS_BDIAGONAL};

	if (this->fillStyle == 0) {
		brush.CreateSolidBrush(penColors[this->brushColor]);
	} else {
		brush.CreateHatchBrush(brushStyles[this->fillStyle], penColors[this->brushColor]);
	}
	dc.SelectObject(&brush);


	switch(this->shape) {
	case 0:
		dc.Ellipse(10, 10, 100, 100);
		break;
	case 1:
		dc.LineTo(100, 100);
		break;
	case 2:
		dc.Rectangle(10, 10, 100, 100);
		break;
	case 3:
		dc.RoundRect(10, 10, 100, 100, 52, 52);
		break;
	default:
		break;
	}
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
