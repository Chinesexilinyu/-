#if !defined(AFX_RECORDDLG_H__4FCAA0BD_6372_45AA_BADE_C986CF9F50BC__INCLUDED_)
#define AFX_RECORDDLG_H__4FCAA0BD_6372_45AA_BADE_C986CF9F50BC__INCLUDED_

#include "Error2Dlg.h"	// Added by ClassView
#include "REGISTER_TO_MAINDlg.h"	// Added by ClassView
#include "Password_InconsistentDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg dialog

class CRecordDlg : public CDialog
{
// Construction
public:
	CREGISTER_TO_MAINDlg Succ;
	CPassword_InconsistentDlg Pinconsistent;
	CRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRecordDlg)
	enum { IDD = IDD_2_RECORD };
	CString	m_Password1;
	CString	m_Password2;
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRecordDlg)
	afx_msg void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDDLG_H__4FCAA0BD_6372_45AA_BADE_C986CF9F50BC__INCLUDED_)
