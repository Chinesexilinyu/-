// MathGameDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "MathGameDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMathGameDlg dialog


CMathGameDlg::CMathGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMathGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMathGameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMathGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMathGameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMathGameDlg, CDialog)
	//{{AFX_MSG_MAP(CMathGameDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMathGameDlg message handlers
