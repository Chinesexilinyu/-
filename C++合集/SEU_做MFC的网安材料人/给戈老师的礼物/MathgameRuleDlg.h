#if !defined(AFX_MATHGAMERULEDLG_H__660AA830_AC02_4129_A4EC_0C5F46ECD5F5__INCLUDED_)
#define AFX_MATHGAMERULEDLG_H__660AA830_AC02_4129_A4EC_0C5F46ECD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MathgameRuleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMathgameRuleDlg dialog

class CMathgameRuleDlg : public CDialog
{
// Construction
public:
	CMathgameRuleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMathgameRuleDlg)
	enum { IDD = IDD_MATHRULE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMathgameRuleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMathgameRuleDlg)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATHGAMERULEDLG_H__660AA830_AC02_4129_A4EC_0C5F46ECD5F5__INCLUDED_)
