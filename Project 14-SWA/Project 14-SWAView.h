
// Project 14-SWAView.h : interface of the CProject14SWAView class
//

#pragma once


class CProject14SWAView : public CView
{
protected: // create from serialization only
	CProject14SWAView();
	DECLARE_DYNCREATE(CProject14SWAView)

// Attributes
public:
	CProject14SWADoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CProject14SWAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
    virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in Project 14-SWAView.cpp
inline CProject14SWADoc* CProject14SWAView::GetDocument() const
   { return reinterpret_cast<CProject14SWADoc*>(m_pDocument); }
#endif

