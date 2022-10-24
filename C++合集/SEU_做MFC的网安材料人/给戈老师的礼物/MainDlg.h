#if !defined(AFX_MAINDLG_H__720D563A_2ADC_4D14_B356_0C6013267F8B__INCLUDED_)
#define AFX_MAINDLG_H__720D563A_2ADC_4D14_B356_0C6013267F8B__INCLUDED_

#include "GuessgameDlg.h"	// Added by ClassView
#include "MathGameDlg.h"	// Added by ClassView
#include "GrambleGameDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

class CMainDlg : public CDialog
{
// Construction
public:
	CGrambleGameDlg gramblegameDlg;
	CMathGameDlg mathgameDlg;
	CGuessgameDlg guessDlg;
	CMainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_MAIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnCancel();
	afx_msg void OnGuesson();
	afx_msg void OnMathon();
	afx_msg void OnGamble();
	afx_msg void OnMusicoff1();
	afx_msg void OnMusicon1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__720D563A_2ADC_4D14_B356_0C6013267F8B__INCLUDED_)
