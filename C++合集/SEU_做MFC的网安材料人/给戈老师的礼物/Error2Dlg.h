#if !defined(AFX_ERROR2DLG_H__AB27451D_A096_4B77_909D_A2E08FBF8EF8__INCLUDED_)
#define AFX_ERROR2DLG_H__AB27451D_A096_4B77_909D_A2E08FBF8EF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Error2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CError2Dlg dialog

class CError2Dlg : public CDialog
{
// Construction
public:
	CError2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CError2Dlg)
	enum { IDD = IDD_ERROR2_G1320218 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CError2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CError2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERROR2DLG_H__AB27451D_A096_4B77_909D_A2E08FBF8EF8__INCLUDED_)
