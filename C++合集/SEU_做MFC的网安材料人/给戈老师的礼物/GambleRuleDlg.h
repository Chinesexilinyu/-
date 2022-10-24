#if !defined(AFX_GAMBLERULEDLG_H__DA2B1B6B_F5B6_4116_9CAE_04FA1EE60534__INCLUDED_)
#define AFX_GAMBLERULEDLG_H__DA2B1B6B_F5B6_4116_9CAE_04FA1EE60534__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GambleRuleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGambleRuleDlg dialog

class CGambleRuleDlg : public CDialog
{
// Construction
public:
	CGambleRuleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGambleRuleDlg)
	enum { IDD = IDD_GAMBLERULE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGambleRuleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGambleRuleDlg)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMBLERULEDLG_H__DA2B1B6B_F5B6_4116_9CAE_04FA1EE60534__INCLUDED_)
