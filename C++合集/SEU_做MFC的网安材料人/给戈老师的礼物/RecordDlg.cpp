// RecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "RecordDlg.h"
#include "fstream"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg dialog


CRecordDlg::CRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecordDlg)
	m_Password1 = _T("");
	m_Password2 = _T("");
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordDlg)
	DDX_Text(pDX, IDC_Password1, m_Password1);
	DDX_Text(pDX, IDC_Password2, m_Password2);
	DDX_Text(pDX, IDC_NAME, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CRecordDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnOK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg message handlers


 
void trim(string &s)//È¥µô×Ö·û´®£¨ÕËºÅÃÜÂë£©µÄ¿Õ¸ñ
	{
	
		int index = 0;
		if( !s.empty())
		{
			while( (index = s.find(' ',index)) != string::npos)
			{
				s.erase(index,1);
			}
		}
 
	}
 

void CRecordDlg::OnOK() 
{
	// TODO: Add your control notification handler code here
	
	 UpdateData(TRUE);
	 fstream fout;
     fout.open("Player_Information.txt",ios::out|ios::app);
    
	 string name,password;
	 string M_Name,M_Password1,M_Password2;
	 M_Name=m_Name.GetBuffer(0);
	 M_Password1=m_Password1.GetBuffer(0);
	 M_Password2=m_Password2.GetBuffer(0);
     if(!(M_Password1==M_Password2))
	 {  
		fout.close();
		Pinconsistent.DoModal(); 
		UpdateData(FALSE);
	 }
	 else
	 {
	 trim(M_Name),trim(M_Password1),trim(M_Password2);
	 fout<<' '<<M_Name<<' '<<M_Password1;
	 fout.close();
	 CDialog::OnOK();
	 Succ.DoModal();
	 UpdateData(FALSE);
	 }
}
