// GrambleGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "GrambleGameDlg.h"
#include<cstdlib>
#include<ctime>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrambleGameDlg dialog


CGrambleGameDlg::CGrambleGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGrambleGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGrambleGameDlg)
	m_NUM1 = 0;
	m_NUM2 = 0;
	m_NUM3 = 0;
	m_OPERATOR = -1;
	//}}AFX_DATA_INIT
}


void CGrambleGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrambleGameDlg)
	DDX_Text(pDX, IDC_NUM1, m_NUM1);
	DDX_Text(pDX, IDC_NUM2, m_NUM2);
	DDX_Text(pDX, IDC_NUM3, m_NUM3);
	DDX_Radio(pDX, IDC_OPERATOR, m_OPERATOR);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGrambleGameDlg, CDialog)
	//{{AFX_MSG_MAP(CGrambleGameDlg)
	ON_BN_CLICKED(IDC_GOON, OnGoon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrambleGameDlg message handlers

void CGrambleGameDlg::OnGoon() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	srand(time(0));
	int a=rand()%7,b=rand()%7,c=rand()%7;
	while(a==0)
	{
		a=rand()%7;
	}
	m_NUM1=a;
	while(b==0)
	{
		b=rand()%7;
	}
	m_NUM2=b;
	while(c==0)
	{
		c=rand()%7;
	}
	m_NUM3=c;
	UpdateData(FALSE);
	int sum=a+b+c;
	if(a==b&&b==c) losserDlg.DoModal();
	else
	{
		if(m_OPERATOR==0)
		{
			if(sum>=4&&sum<=10) losserDlg.DoModal();
			if(sum>=11&&sum<=17) winnerDlg.DoModal();
		}
		if(m_OPERATOR==1)
		{
			if(sum>=4&&sum<=10) winnerDlg.DoModal();
			if(sum>=11&&sum<=17) losserDlg.DoModal();
		}
	}
}

void CGrambleGameDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	PlaySound((LPCTSTR)IDR_WAVE1,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	CDialog::OnCancel();
}
