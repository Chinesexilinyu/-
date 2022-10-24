// 吉利.h : main header file for the 吉利 application
//

#if !defined(AFX__H__977B95B0_828F_4F49_AF07_BEDF42FE1E0F__INCLUDED_)
#define AFX__H__977B95B0_828F_4F49_AF07_BEDF42FE1E0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


//添加的skin++皮肤库头文件
#include <afxcmn.h>
#include <Windows.h>
#include "skin\\SkinPPWTL.h"
#pragma comment(lib, "skin\\SkinPPWTL.lib")


/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See 吉利.cpp for the implementation of this class
//

class CMyApp : public CWinApp
{
public:
	CMyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__H__977B95B0_828F_4F49_AF07_BEDF42FE1E0F__INCLUDED_)
