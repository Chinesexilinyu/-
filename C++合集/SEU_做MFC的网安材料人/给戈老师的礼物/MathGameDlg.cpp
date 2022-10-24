// MathGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "吉利.h"
#include "MathGameDlg.h"
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMathGameDlg dialog


CMathGameDlg::CMathGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMathGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMathGameDlg)
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	out1 = 0;
	out2 = 0;
	out3 = 0;
	B = 0;
	A = 0;
	C = 0;
	D = 0;
	operator1 = -1;
	operator2 = -1;
	operator3 = -1;
	//}}AFX_DATA_INIT
}


void CMathGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMathGameDlg)
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT4, d);
	DDX_Text(pDX, IDC_EDIT5, e);
	DDX_Text(pDX, IDC_EDIT6, f);
	DDX_Text(pDX, IDC_EDIT7, out1);
	DDX_Text(pDX, IDC_EDIT8, out2);
	DDX_Text(pDX, IDC_EDIT9, out3);
	DDX_Text(pDX, IDC_EDIT11, B);
	DDX_Text(pDX, IDC_EDIT10, A);
	DDX_Text(pDX, IDC_EDIT12, C);
	DDX_Text(pDX, IDC_EDIT13, D);
	DDX_Radio(pDX, IDC_RADIO1, operator1);
	DDX_Radio(pDX, IDC_RADIO5, operator2);
	DDX_Radio(pDX, IDC_RADIO9, operator3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMathGameDlg, CDialog)
	//{{AFX_MSG_MAP(CMathGameDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnCalculate1)
	ON_BN_CLICKED(IDC_BUTTON4, OnRandNumber)
	ON_BN_CLICKED(IDC_BUTTON2, OnCalculate2)
	ON_BN_CLICKED(IDC_BUTTON3, OnCalculate3)
	ON_BN_CLICKED(IDC_MUSICOFF, OnMusicoff)
	ON_BN_CLICKED(IDC_MUSICON, OnMusicon)
	ON_BN_CLICKED(IDC_RULE, OnRule)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMathGameDlg message handlers
int num[13]={0};
int Bool=0;
void CMathGameDlg::OnCalculate1() 
{
	// TODO: Add your control notification handler code here
UpdateData(TRUE);  
   {
	   if(num[a-1]>0)                                 
	   {  
		   num[a-1]--;
		   if(num[b-1]>0)
		   {  
			  num[b-1]--; 
			  switch(operator1)
              {
			  case 0: out1=a+b;  break;
              case 1: out1=a-b;  break;
              case 2: out1=a*b;  break;
              case 3: out1=a/b;  break;
			  }
		   }
		   else
		   {
			   PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
			   Math24_WrongDlg.DoModal();
		   }
	   }
	   else
	   {
		   PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
		   Math24_WrongDlg.DoModal();
	   }
	   
   }
  
   //CMath24_WrongDlg Math_Wrong;
	UpdateData(FALSE);
}


void CMathGameDlg::OnRandNumber() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	srand(time(0));
    A=rand()%14,B=rand()%14,C=rand()%14;D=rand()%14;
	while(A==0)
	{
		A=rand()%14;
	}
	srand(time(0));
	while(B==0)
	{
		B=rand()%14;
	}
	while(C==0)
	{
		C=rand()%14;
	}
	while(D==0)
	{
		D=rand()%14;
	}
	for(int j=0;j<13;j++)
	num[j]=0;
	for(int i=0;i<13;i++)
	{
	 if(i+1==A)
	 num[i]++;
	 if(i+1==B)
	 num[i]++;
	 if(i+1==C)
	 num[i]++;
	 if(i+1==D)
	 num[i]++;
	}
	a=b=c=d=e=f=out1=out2=out3=Bool=0;
	UpdateData(FALSE);
}




void CMathGameDlg::OnCalculate2() 
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
	  if((num[c-1]>0)&&(c==A||c==B||c==C||c==D)&&((num[d-1]>0)&&(d==A||d==B||d==C||d==D)))
	  {	  num[c-1]--;num[d-1]--;
		  switch(operator2)
			{			
				case 0: out2=c+d; break;
			    case 1: out2=c-d; break; 
                case 2: out2=c*d; break; 
                case 3: out2=c/d; break; 
			}
	  }
	  else if (c==out1)  
			  if((num[d-1])&&(d==A||d==B||d==C||d==D))
					{
					num[d-1]--;Bool++;
					switch(operator2)
						{
							case 0: out2=c+d; break;
							case 1: out2=c-d; break; 
							case 2: out2=c*d; break; 
							case 3: out2=c/d; break; 
						}
					}
				else  if(d==out1)  
							if((num[c-1])&&(c==A||c==B||c==C||c==D))
							{	num[c-1]--;Bool++;
								switch(operator2)
								{	
									case 0: out2=c+d; break;
									case 1: out2=c-d; break; 
									case 2: out2=c*d; break; 
									case 3: out2=c/d; break; 
								}
							}  
							else
							{
								PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
								Math24_WrongDlg.DoModal();
							}
					  else 
					  {
						  PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
						  Math24_WrongDlg.DoModal();
					  }
		 /*  else 
		   {
			   PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
			   Math24_WrongDlg.DoModal();
		   }
		   */
		UpdateData(FALSE);
}

void CMathGameDlg::OnCalculate3() 
{
	UpdateData(TRUE);
	int i=0;
	// TODO: Add your control notification handler code here
	if(Bool)//out1在第二行式子中被用掉，则代表第三行式子中使用了ABCD中的最后一个未被使用的数
	{ 
		if(e==out2)
				 {
						if (f<14&&f>0&&num[f-1])
							{	
								switch(operator3)
								{
									 case 0:  out3=e+f;break;
									 case 1:  out3=e-f;break;
									 case 2:  out3=e*f;break;
									 case 3:  out3=e/f;break;
								}
							}
					   else 
					   {
						   PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
						   Math24_WrongDlg.DoModal();
					   }
				 }
		else
		{
			if(f==out2)
			{
				if (e<14&&e>0&&num[e-1])
					{	
						switch(operator3)
						{
							 case 0:  out3=e+f;break;
							 case 1:  out3=e-f;break;
							 case 2:  out3=e*f;break;
							 case 3:  out3=e/f;break;
						}
					}
				else 
				{
					PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
					Math24_WrongDlg.DoModal();
				}
			 } 
		}
	}
	else 
	{
		if((e==out1&&f==out2)||(e==out2&&f==out1))   
			{	switch(operator3)
					{
					 case 0:  out3=e+f;break;
					 case 1:  out3=e-f;break;
					 case 2:  out3=e*f;break;
					 case 3:  out3=e/f;break;
					}
			}
		else 
		{
			PlaySound((LPCTSTR)IDR_WAVE11,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
			Math24_WrongDlg.DoModal();
		}
	}
		
   if(out3==24)
   {
	   PlaySound((LPCTSTR)IDR_WAVE10,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	   Math24_WIN.DoModal();
	   a=b=c=d=e=f=out1=out2=out3=0;
   }
   else 
   {
	   PlaySound((LPCTSTR)IDR_WAVE9,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	   Math24_Lose.DoModal();
	   a=b=c=d=e=f=out1=out2=out3=0;
   }
   UpdateData(FALSE);
}

void CMathGameDlg::OnMusicoff() 
{
	// TODO: Add your control notification handler code here
	PlaySound(NULL,NULL,SND_PURGE);
}

void CMathGameDlg::OnMusicon() 
{
	// TODO: Add your control notification handler code here
	PlaySound((LPCTSTR)IDR_WAVE8,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
}

void CMathGameDlg::OnRule() 
{
	// TODO: Add your control notification handler code here
	PlaySound((LPCTSTR)IDR_WAVE13,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC);
	mathruleDlg.DoModal();
}
