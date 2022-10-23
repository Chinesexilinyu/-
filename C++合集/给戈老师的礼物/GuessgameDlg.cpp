// GuessgameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "GuessgameDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGuessgameDlg dialog


CGuessgameDlg::CGuessgameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGuessgameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGuessgameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGuessgameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGuessgameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGuessgameDlg, CDialog)
	//{{AFX_MSG_MAP(CGuessgameDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuessgameDlg message handlers

void CGuessgameDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	PlaySound((LPCTSTR)IDR_WAVE1,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	CDialog::OnCancel();
}
