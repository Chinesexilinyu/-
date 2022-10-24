// MainWorkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "MainWorkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainWorkDlg dialog


CMainWorkDlg::CMainWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainWorkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainWorkDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainWorkDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainWorkDlg, CDialog)
	//{{AFX_MSG_MAP(CMainWorkDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainWorkDlg message handlers
