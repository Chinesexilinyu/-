// NoWinnerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "NoWinnerDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoWinnerDlg dialog


CNoWinnerDlg::CNoWinnerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoWinnerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoWinnerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNoWinnerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoWinnerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNoWinnerDlg, CDialog)
	//{{AFX_MSG_MAP(CNoWinnerDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoWinnerDlg message handlers

void CNoWinnerDlg::OnOK() 
{
	// TODO: Add extra validation here
	PlaySound(NULL,NULL,SND_PURGE);
	CDialog::OnOK();
}
