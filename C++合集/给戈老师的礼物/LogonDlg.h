#if !defined(AFX_LOGONDLG_H__237AB529_C29C_4FBD_B697_486208E0C106__INCLUDED_)
#define AFX_LOGONDLG_H__237AB529_C29C_4FBD_B697_486208E0C106__INCLUDED_

#include "PlayerDlg.h"	// Added by ClassView
#include "WorkerDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogonDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogonDlg dialog

class CLogonDlg : public CDialog
{
// Construction
public:
	CWorkerDlg m_Dlg;
	CPlayerDlg m_dlg;
	CLogonDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogonDlg)
	enum { IDD = IDD_2_LOGON };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogonDlg)
	afx_msg void OnPlayer();
	afx_msg void OnWorker();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGONDLG_H__237AB529_C29C_4FBD_B697_486208E0C106__INCLUDED_)
