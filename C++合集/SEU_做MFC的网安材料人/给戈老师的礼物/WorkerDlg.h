#if !defined(AFX_WORKERDLG_H__39985970_C093_4CF5_AFE6_C8669C17578B__INCLUDED_)
#define AFX_WORKERDLG_H__39985970_C093_4CF5_AFE6_C8669C17578B__INCLUDED_

#include "Error1Dlg.h"	// Added by ClassView
#include "Error2Dlg.h"	// Added by ClassView
#include "MainWorkDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkerDlg dialog

class CWorkerDlg : public CDialog
{
// Construction
public:
	CMainWorkDlg m_Dlg;
	CError2Dlg m_Dlg2;
	CError1Dlg m_Dlg1;
	CWorkerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkerDlg)
	enum { IDD = IDD_3_WORKERLOGON };
	CString	m_Name;
	CString	m_Password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWorkerDlg)
	virtual void OnOK();
	afx_msg void OnRight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKERDLG_H__39985970_C093_4CF5_AFE6_C8669C17578B__INCLUDED_)
