#if !defined(AFX_PASSWORD_INCONSISTENTDLG_H__9953EF36_A5D2_42DB_822E_17A0CE72038B__INCLUDED_)
#define AFX_PASSWORD_INCONSISTENTDLG_H__9953EF36_A5D2_42DB_822E_17A0CE72038B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Password_InconsistentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPassword_InconsistentDlg dialog

class CPassword_InconsistentDlg : public CDialog
{
// Construction
public:
	CPassword_InconsistentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPassword_InconsistentDlg)
	enum { IDD = IDD_Password_Inconsistent};
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassword_InconsistentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPassword_InconsistentDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORD_INCONSISTENTDLG_H__9953EF36_A5D2_42DB_822E_17A0CE72038B__INCLUDED_)
