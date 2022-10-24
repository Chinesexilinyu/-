// REGISTER_TO_MAINDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "REGISTER_TO_MAINDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CREGISTER_TO_MAINDlg dialog


CREGISTER_TO_MAINDlg::CREGISTER_TO_MAINDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CREGISTER_TO_MAINDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CREGISTER_TO_MAINDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CREGISTER_TO_MAINDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CREGISTER_TO_MAINDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CREGISTER_TO_MAINDlg, CDialog)
	//{{AFX_MSG_MAP(CREGISTER_TO_MAINDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CREGISTER_TO_MAINDlg message handlers

void CREGISTER_TO_MAINDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
	Main.DoModal();
}
