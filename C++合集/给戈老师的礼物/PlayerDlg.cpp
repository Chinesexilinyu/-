// PlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "¼ªÀû.h"
#include "PlayerDlg.h"

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
