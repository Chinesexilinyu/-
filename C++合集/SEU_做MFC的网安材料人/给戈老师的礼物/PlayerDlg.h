#if !defined(AFX_PLAYERDLG_H__4F160DD2_3336_405E_9322_3ADFC7844DDA__INCLUDED_)
#define AFX_PLAYERDLG_H__4F160DD2_3336_405E_9322_3ADFC7844DDA__INCLUDED_

#include "Error1Dlg.h"	// Added by ClassView
#include "MainDlg.h"	// Added by ClassView
#include "Error2Dlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlayerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg dialog

class CPlayerDlg : public CDialog
{
// Construction
public:
	CError2Dlg m_Dlg2;
	CMainDlg m_Dlg;
	CError1Dlg m_Dlg1;
	CPlayerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayerDlg)
	enum { IDD = IDD_3_PLAYERLOGON };
	CString	m_Name;
	CString	m_Password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlayerDlg)
	afx_msg void OnRight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYERDLG_H__4F160DD2_3336_405E_9322_3ADFC7844DDA__INCLUDED_)
