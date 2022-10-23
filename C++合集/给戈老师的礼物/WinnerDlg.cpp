// WinnerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "WinnerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinnerDlg dialog


CWinnerDlg::CWinnerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWinnerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWinnerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWinnerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWinnerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWinnerDlg, CDialog)
	//{{AFX_MSG_MAP(CWinnerDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinnerDlg message handlers
