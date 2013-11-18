
// Project 14-SWAView.cpp : implementation of the CProject14SWAView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Project 14-SWA.h"
#endif

#include "Project 14-SWADoc.h"
#include "Project 14-SWAView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "TFSTransaction.h"

// CProject14SWAView

IMPLEMENT_DYNCREATE(CProject14SWAView, CView)

BEGIN_MESSAGE_MAP(CProject14SWAView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProject14SWAView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CProject14SWAView construction/destruction

CProject14SWAView::CProject14SWAView()
{
	// TODO: add construction code here

}

CProject14SWAView::~CProject14SWAView()
{
}

BOOL CProject14SWAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProject14SWAView drawing

void CProject14SWAView::OnDraw(CDC* pDC)
{
	CProject14SWADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;

    std::list<std::string>              saFilenameList;
    std::list<std::string>::iterator    iList;
    CString                             sFilename;
    int                                 y   = 10;
    
    pDC->Rectangle( 10, 10, 100, 100 );
    pDC->Ellipse( 10, 10, 100, 100 );
    pDC->Rectangle( 23, 23, 87, 87 );
    pDC->Ellipse( 23, 23, 87, 87 );

    try
    {
        TFSTransaction::remoteListProjects( saFilenameList );

        for ( iList=saFilenameList.begin(); iList!=saFilenameList.end(); ++iList )
        {
            sFilename   = iList->c_str();

            pDC->TextOut( 150, y, sFilename );
            y += 20;
        }
    }
    catch ( ... )
    {
        pDC->TextOut( 150, y, L"No connection to the server..." );
    }
}


// CProject14SWAView printing


void CProject14SWAView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProject14SWAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProject14SWAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProject14SWAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CProject14SWAView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProject14SWAView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProject14SWAView diagnostics

#ifdef _DEBUG
void CProject14SWAView::AssertValid() const
{
	CView::AssertValid();
}

void CProject14SWAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProject14SWADoc* CProject14SWAView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject14SWADoc)));
	return (CProject14SWADoc*)m_pDocument;
}
#endif //_DEBUG


// CProject14SWAView message handlers


void CProject14SWAView::OnInitialUpdate()
{
    CView::OnInitialUpdate();
}
