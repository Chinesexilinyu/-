#if !defined(AFX_GUESSRULEDLG_H__3CCF74D9_CC99_4ECA_A8DC_37B33516A014__INCLUDED_)
#define AFX_GUESSRULEDLG_H__3CCF74D9_CC99_4ECA_A8DC_37B33516A014__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuessRuleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGuessRuleDlg dialog

class CGuessRuleDlg : public CDialog
{
// Construction
public:
	CGuessRuleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGuessRuleDlg)
	enum { IDD = IDD_GUSEEGAMERULE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuessRuleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGuessRuleDlg)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUESSRULEDLG_H__3CCF74D9_CC99_4ECA_A8DC_37B33516A014__INCLUDED_)
