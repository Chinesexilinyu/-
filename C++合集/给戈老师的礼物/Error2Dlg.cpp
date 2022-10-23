// Error2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "Error2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CError2Dlg dialog


CError2Dlg::CError2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CError2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CError2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CError2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CError2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CError2Dlg, CDialog)
	//{{AFX_MSG_MAP(CError2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CError2Dlg message handlers
