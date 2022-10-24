// MathgameRuleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "MathgameRuleDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMathgameRuleDlg dialog


CMathgameRuleDlg::CMathgameRuleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMathgameRuleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMathgameRuleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMathgameRuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMathgameRuleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMathgameRuleDlg, CDialog)
	//{{AFX_MSG_MAP(CMathgameRuleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMathgameRuleDlg message handlers

void CMathgameRuleDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	PlaySound(NULL,NULL,SND_PURGE);	
	CDialog::OnCancel();
}
