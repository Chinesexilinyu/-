#if !defined(AFX_ERROR1DLG_H__A654CE14_1C1D_48A5_A7DA_C145854E9AFE__INCLUDED_)
#define AFX_ERROR1DLG_H__A654CE14_1C1D_48A5_A7DA_C145854E9AFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Error1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CError1Dlg dialog

class CError1Dlg : public CDialog
{
// Construction
public:
	CError1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CError1Dlg)
	enum { IDD = IDD_ERROR1_G1320218 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CError1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CError1Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERROR1DLG_H__A654CE14_1C1D_48A5_A7DA_C145854E9AFE__INCLUDED_)
