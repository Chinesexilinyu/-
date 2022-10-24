#if !defined(AFX_GRAMBLEGAMEDLG_H__FEAF699D_B766_48BD_A7CE_E9E26512332B__INCLUDED_)
#define AFX_GRAMBLEGAMEDLG_H__FEAF699D_B766_48BD_A7CE_E9E26512332B__INCLUDED_

#include "WinnerDlg.h"	// Added by ClassView
#include "LosserDlg.h"	// Added by ClassView
#include "GambleRuleDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GrambleGameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGrambleGameDlg dialog

class CGrambleGameDlg : public CDialog
{
// Construction
public:
	CGambleRuleDlg gambleruleDlg;
	CLosserDlg losserDlg;
	CWinnerDlg winnerDlg;
	CGrambleGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGrambleGameDlg)
	enum { IDD = IDD_GAMBLGAME_G1320218 };
	int		m_NUM1;
	int		m_NUM2;
	int		m_NUM3;
	int		m_OPERATOR;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrambleGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGrambleGameDlg)
	afx_msg void OnGoon();
	virtual void OnCancel();
	afx_msg void OnMusicon1();
	afx_msg void OnMusicoff1();
	afx_msg void OnRule();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAMBLEGAMEDLG_H__FEAF699D_B766_48BD_A7CE_E9E26512332B__INCLUDED_)
