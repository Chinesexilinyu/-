#if !defined(AFX_NOWINNERDLG_H__7D164886_F90A_4ED1_9C0E_DD58C6A0F277__INCLUDED_)
#define AFX_NOWINNERDLG_H__7D164886_F90A_4ED1_9C0E_DD58C6A0F277__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NoWinnerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNoWinnerDlg dialog

class CNoWinnerDlg : public CDialog
{
// Construction
public:
	CNoWinnerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNoWinnerDlg)
	enum { IDD = IDD_NOWINNER_G1320218 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoWinnerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNoWinnerDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOWINNERDLG_H__7D164886_F90A_4ED1_9C0E_DD58C6A0F277__INCLUDED_)
