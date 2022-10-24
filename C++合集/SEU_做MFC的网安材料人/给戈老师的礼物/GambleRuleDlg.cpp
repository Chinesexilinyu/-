// GambleRuleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "GambleRuleDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGambleRuleDlg dialog


CGambleRuleDlg::CGambleRuleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGambleRuleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGambleRuleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGambleRuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGambleRuleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGambleRuleDlg, CDialog)
	//{{AFX_MSG_MAP(CGambleRuleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGambleRuleDlg message handlers

void CGambleRuleDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	PlaySound(NULL,NULL,SND_PURGE);
	CDialog::OnCancel();
}
