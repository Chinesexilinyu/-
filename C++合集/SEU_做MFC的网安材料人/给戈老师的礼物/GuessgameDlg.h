#if !defined(AFX_GUESSGAMEDLG_H__96ADAAB4_9062_4844_911E_5FD3E5E2060C__INCLUDED_)
#define AFX_GUESSGAMEDLG_H__96ADAAB4_9062_4844_911E_5FD3E5E2060C__INCLUDED_

#include "NoWinnerDlg.h"	// Added by ClassView
#include "WinnerDlg.h"	// Added by ClassView
#include "LosserDlg.h"	// Added by ClassView
#include "GuessRuleDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuessgameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGuessgameDlg dialog

class CGuessgameDlg : public CDialog
{
// Construction
public:
	CGuessRuleDlg guessruleDlg;
	CLosserDlg losserDlg;
	CWinnerDlg winnerDlg;
	CNoWinnerDlg nowinnerDlg;
	CGuessgameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGuessgameDlg)
	enum { IDD = IDD_GUESSGAME };
	CString	m_COMPUTERS;
	CString	m_YOURS;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuessgameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGuessgameDlg)
	virtual void OnCancel();
	afx_msg void OnGoon();
	afx_msg void OnMusicon1();
	afx_msg void OnMusicoff1();
	afx_msg void OnRule();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUESSGAMEDLG_H__96ADAAB4_9062_4844_911E_5FD3E5E2060C__INCLUDED_)
