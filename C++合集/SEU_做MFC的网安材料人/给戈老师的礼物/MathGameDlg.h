#if !defined(AFX_MATHGAMEDLG_H__AB950D2C_A874_4150_AB1D_5B1D67B6EE3D__INCLUDED_)
#define AFX_MATHGAMEDLG_H__AB950D2C_A874_4150_AB1D_5B1D67B6EE3D__INCLUDED_

#include "Math24_WrongDlg.h"	// Added by ClassView
#include "WinnerDlg.h"	// Added by ClassView
#include "LosserDlg.h"	// Added by ClassView
#include "MathgameRuleDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MathGameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMathGameDlg dialog

class CMathGameDlg : public CDialog
{
// Construction
public:
	CMathgameRuleDlg mathruleDlg;
	CLosserDlg Math24_Lose;
	CWinnerDlg Math24_WIN;
	CMath24_WrongDlg Math24_WrongDlg;
	CMathGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMathGameDlg)
	enum { IDD = IDD_MATHGAME_G1320218 };
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		f;
	int		out1;
	int		out2;
	int		out3;
	int		B;
	int		A;
	int		C;
	int		D;
	int		operator1;
	int		operator2;
	int		operator3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMathGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMathGameDlg)
	afx_msg void OnCalculate1();
	afx_msg void OnRandNumber();
	afx_msg void OnCalculate2();
	afx_msg void OnCalculate3();
	afx_msg void OnMusicoff();
	afx_msg void OnMusicon();
	afx_msg void OnRule();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATHGAMEDLG_H__AB950D2C_A874_4150_AB1D_5B1D67B6EE3D__INCLUDED_)
