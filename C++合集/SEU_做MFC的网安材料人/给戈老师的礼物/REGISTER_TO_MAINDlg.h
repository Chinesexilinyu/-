#if !defined(AFX_REGISTER_TO_MAINDLG_H__050AB48F_9D32_4BDE_B4A3_A450E768392C__INCLUDED_)
#define AFX_REGISTER_TO_MAINDLG_H__050AB48F_9D32_4BDE_B4A3_A450E768392C__INCLUDED_

#include "MainDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// REGISTER_TO_MAINDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CREGISTER_TO_MAINDlg dialog

class CREGISTER_TO_MAINDlg : public CDialog
{
// Construction
public:
	CMainDlg Main;
	CREGISTER_TO_MAINDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CREGISTER_TO_MAINDlg)
	enum { IDD = IDD_REGISTER_SUCCESS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CREGISTER_TO_MAINDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CREGISTER_TO_MAINDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_TO_MAINDLG_H__050AB48F_9D32_4BDE_B4A3_A450E768392C__INCLUDED_)
