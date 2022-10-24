// WorkerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "WorkerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkerDlg dialog


CWorkerDlg::CWorkerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWorkerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWorkerDlg)
	m_Name = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
}


void CWorkerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkerDlg)
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWorkerDlg, CDialog)
	//{{AFX_MSG_MAP(CWorkerDlg)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkerDlg message handlers

void CWorkerDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CWorkerDlg::OnRight() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString s1="900909",s2="123456";
	if(m_Name==s1)
	{
		if(m_Password==s2)
			m_Dlg.DoModal();
		else 
			m_Dlg1.DoModal();
	}
	else
		m_Dlg2.DoModal();
    UpdateData(FALSE);
}
