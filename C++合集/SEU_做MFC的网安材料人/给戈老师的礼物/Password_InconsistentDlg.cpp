// Password_InconsistentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "Password_InconsistentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassword_InconsistentDlg dialog


CPassword_InconsistentDlg::CPassword_InconsistentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPassword_InconsistentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPassword_InconsistentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPassword_InconsistentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassword_InconsistentDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassword_InconsistentDlg, CDialog)
	//{{AFX_MSG_MAP(CPassword_InconsistentDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassword_InconsistentDlg message handlers
