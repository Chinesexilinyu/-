#if !defined(AFX_MATHGAMEDLG_H__AB950D2C_A874_4150_AB1D_5B1D67B6EE3D__INCLUDED_)
#define AFX_MATHGAMEDLG_H__AB950D2C_A874_4150_AB1D_5B1D67B6EE3D__INCLUDED_

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
	CMathGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMathGameDlg)
	enum { IDD = IDD_MATHGAME_G1320218 };
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

#endif // !defined(AFX_MATHGAMEDLG_H__AB950D2C_A874_4150_AB1D_5B1D67B6EE3D__INCLUDED_)
