// GuessRuleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "GuessRuleDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGuessRuleDlg dialog


CGuessRuleDlg::CGuessRuleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGuessRuleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGuessRuleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGuessRuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGuessRuleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGuessRuleDlg, CDialog)
	//{{AFX_MSG_MAP(CGuessRuleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuessRuleDlg message handlers

void CGuessRuleDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	PlaySound(NULL,NULL,SND_PURGE);
	CDialog::OnCancel();
}
