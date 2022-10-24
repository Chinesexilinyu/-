#if !defined(AFX_MATH24_WRONGDLG_H__8696DDBD_A32E_4389_A328_05AF899AF64A__INCLUDED_)
#define AFX_MATH24_WRONGDLG_H__8696DDBD_A32E_4389_A328_05AF899AF64A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Math24_WrongDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMath24_WrongDlg dialog

class CMath24_WrongDlg : public CDialog
{
// Construction
public:
	//CMath24_Wrong Math_Wrong;
	CMath24_WrongDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMath24_WrongDlg)
	enum { IDD = IDD_Math24_WrongDlg };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMath24_WrongDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMath24_WrongDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATH24_WRONGDLG_H__8696DDBD_A32E_4389_A328_05AF899AF64A__INCLUDED_)
