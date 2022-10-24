// PlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "PlayerDlg.h"
#include "fstream"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg dialog


CPlayerDlg::CPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayerDlg)
	m_Name = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
}


void CPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayerDlg)
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayerDlg)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg message handlers

void CPlayerDlg::OnRight() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	 ifstream fin;
     fin.open("Player_Information.txt",ios_base::in);
     
	 string M_Name,M_Password;
	 M_Name=m_Name.GetBuffer(0);
	 M_Password=m_Password.GetBuffer(0);
	 string name;string password;int f1=0;
     while(fin>>name>>password)
	 {
        if(name==M_Name&&password==M_Password)
        {
             m_Dlg.DoModal();
             f1=1;
         }
     }
     if(f1==0)
     {
     m_Dlg1.DoModal();
     }
	 fin.close();


	UpdateData(FALSE);
	
}
