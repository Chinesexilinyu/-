// Math24_WrongDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "Math24_WrongDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMath24_WrongDlg dialog


CMath24_WrongDlg::CMath24_WrongDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMath24_WrongDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMath24_WrongDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMath24_WrongDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMath24_WrongDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMath24_WrongDlg, CDialog)
	//{{AFX_MSG_MAP(CMath24_WrongDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMath24_WrongDlg message handlers

void CMath24_WrongDlg::OnOK() 
{
	// TODO: Add extra validation here
	PlaySound(NULL,NULL,SND_PURGE);
	CDialog::OnOK();
}
