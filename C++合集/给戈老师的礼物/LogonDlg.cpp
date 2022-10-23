// LogonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "LogonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogonDlg dialog


CLogonDlg::CLogonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLogonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogonDlg, CDialog)
	//{{AFX_MSG_MAP(CLogonDlg)
	ON_BN_CLICKED(IDC_PLAYER, OnPlayer)
	ON_BN_CLICKED(IDC_WORKER, OnWorker)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogonDlg message handlers

void CLogonDlg::OnPlayer() 
{
	// TODO: Add your control notification handler code here
	CPlayerDlg dlg;
	dlg.DoModal();
}

void CLogonDlg::OnWorker() 
{
	// TODO: Add your control notification handler code here
	CWorkerDlg dlg;
    dlg.DoModal();
}
