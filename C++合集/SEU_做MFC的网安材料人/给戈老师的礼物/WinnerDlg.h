#if !defined(AFX_WINNERDLG_H__9BED693F_3454_4F90_9923_B51C452CF1E1__INCLUDED_)
#define AFX_WINNERDLG_H__9BED693F_3454_4F90_9923_B51C452CF1E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WinnerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWinnerDlg dialog

class CWinnerDlg : public CDialog
{
// Construction
public:
	CWinnerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWinnerDlg)
	enum { IDD = IDD_WINNER_G1320218 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinnerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWinnerDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINNERDLG_H__9BED693F_3454_4F90_9923_B51C452CF1E1__INCLUDED_)
