// Error1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "Error1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CError1Dlg dialog


CError1Dlg::CError1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CError1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CError1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CError1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CError1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CError1Dlg, CDialog)
	//{{AFX_MSG_MAP(CError1Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CError1Dlg message handlers
