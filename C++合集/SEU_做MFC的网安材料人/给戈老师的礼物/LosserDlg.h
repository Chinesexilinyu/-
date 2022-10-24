#if !defined(AFX_LOSSERDLG_H__1ABE6FC7_7D4E_4776_8B69_940FC28D7CAB__INCLUDED_)
#define AFX_LOSSERDLG_H__1ABE6FC7_7D4E_4776_8B69_940FC28D7CAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LosserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLosserDlg dialog

class CLosserDlg : public CDialog
{
// Construction
public:
	CLosserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLosserDlg)
	enum { IDD = IDD_LOSER_G1320218 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLosserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLosserDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOSSERDLG_H__1ABE6FC7_7D4E_4776_8B69_940FC28D7CAB__INCLUDED_)
