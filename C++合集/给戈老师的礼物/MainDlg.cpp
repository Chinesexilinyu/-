// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "MainDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_GUESSON, OnGuesson)
	ON_BN_CLICKED(IDC_MATHON, OnMathon)
	ON_BN_CLICKED(IDC_GAMBLE, OnGamble)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	PlaySound((LPCTSTR)IDR_WAVE1,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	return 0;
}

void CMainDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	PlaySound(NULL,NULL,SND_PURGE);
	CDialog::OnCancel();
}

void CMainDlg::OnGuesson() 
{
	// TODO: Add your control notification handler code here
	PlaySound(NULL, NULL, SND_PURGE) ;
	guessDlg.DoModal();
}

void CMainDlg::OnMathon() 
{
	// TODO: Add your control notification handler code here
	PlaySound(NULL,NULL,SND_PURGE);
	mathgameDlg.DoModal();
}

void CMainDlg::OnGamble() 
{
	// TODO: Add your control notification handler code here
	PlaySound(NULL,NULL,SND_PURGE);
	gramblegameDlg.DoModal();
}
