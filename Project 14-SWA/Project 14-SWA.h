
// Project 14-SWA.h : main header file for the Project 14-SWA application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProject14SWAApp:
// See Project 14-SWA.cpp for the implementation of this class
//

class CProject14SWAApp : public CWinAppEx
{
public:
	CProject14SWAApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProject14SWAApp theApp;
