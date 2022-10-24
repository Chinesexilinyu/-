// GuessgameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "吉利.h"
#include "GuessgameDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#include<cstdlib>
#include<ctime>

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
	m_COMPUTERS = _T("");
	m_YOURS = _T("");
	//}}AFX_DATA_INIT
}


void CGuessgameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGuessgameDlg)
	DDX_Text(pDX, IDC_COMPUTERS, m_COMPUTERS);
	DDX_Text(pDX, IDC_YOURS, m_YOURS);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGuessgameDlg, CDialog)
	//{{AFX_MSG_MAP(CGuessgameDlg)
	ON_BN_CLICKED(IDC_GOON, OnGoon)
	ON_BN_CLICKED(IDC_MUSICON1, OnMusicon1)
	ON_BN_CLICKED(IDC_MUSICOFF1, OnMusicoff1)
	ON_BN_CLICKED(IDC_RULE, OnRule)
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

void CGuessgameDlg::OnGoon() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int a,b;
	if(m_YOURS=="剪刀") a=0;
	if(m_YOURS=="石头") a=1;
	if(m_YOURS=="布") a=2;
	srand(time(0));
	b=rand()%3;
	switch(b)
	{
	case 0:m_COMPUTERS="剪刀";break;
	case 1:m_COMPUTERS="石头";break;
	case 2:m_COMPUTERS="布";break;
	}
	UpdateData(FALSE);
	if(a==b) 
	{
		PlaySound((LPCTSTR)IDR_WAVE12,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
		nowinnerDlg.DoModal();
	}
	else
	{
		if(a==0)
		{
			if(b==2)
			{
				PlaySound((LPCTSTR)IDR_WAVE10,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
				winnerDlg.DoModal();
			}
			else 
			{
				PlaySound((LPCTSTR)IDR_WAVE9,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
				losserDlg.DoModal();
			}
		}
		if(a==1)
		{
			if(b==0)
			{
				PlaySound((LPCTSTR)IDR_WAVE10,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
				winnerDlg.DoModal();
			}
			else
			{
				PlaySound((LPCTSTR)IDR_WAVE9,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
				losserDlg.DoModal();
			}
		}
		if(a==2)
		{
			if(b==1)
			{
				PlaySound((LPCTSTR)IDR_WAVE10,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
				winnerDlg.DoModal();
			}
			else
			{
				PlaySound((LPCTSTR)IDR_WAVE9,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
				losserDlg.DoModal();
			}
		}
	}
}


void CGuessgameDlg::OnMusicon1() 
{
	// TODO: Add your control notification handler code here
	PlaySound((LPCTSTR)IDR_WAVE6,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
}

void CGuessgameDlg::OnMusicoff1() 
{
	// TODO: Add your control notification handler code here
	PlaySound(NULL,NULL,SND_PURGE);
}

void CGuessgameDlg::OnRule() 
{
	// TODO: Add your control notification handler code here
	PlaySound((LPCTSTR)IDR_WAVE13,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	guessruleDlg.DoModal();
}
