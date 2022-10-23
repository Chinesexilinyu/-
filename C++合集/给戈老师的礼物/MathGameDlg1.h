#if !defined(AFX_MATHGAMEDLG1_H__FF9C5BD0_CC9C_4E2F_B95E_F857D39354CA__INCLUDED_)
#define AFX_MATHGAMEDLG1_H__FF9C5BD0_CC9C_4E2F_B95E_F857D39354CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MathGameDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMathGameDlg dialog

class CMathGameDlg : public CDialog
{
// Construction
public:
	CMathGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMathGameDlg)
	enum { IDD = IDD_MATH24_G1320218 };
		// NOTE: the ClassWizard will add data members here
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
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATHGAMEDLG1_H__FF9C5BD0_CC9C_4E2F_B95E_F857D39354CA__INCLUDED_)
