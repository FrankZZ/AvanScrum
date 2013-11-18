
// Project 14-SWADoc.cpp : implementation of the CProject14SWADoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Project 14-SWA.h"
#endif

#include "Project 14-SWADoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProject14SWADoc

IMPLEMENT_DYNCREATE(CProject14SWADoc, CDocument)

BEGIN_MESSAGE_MAP(CProject14SWADoc, CDocument)
    ON_COMMAND(ID_WINDOW_NEWWINDOW2, &CProject14SWADoc::OnWindowNewWindow)
END_MESSAGE_MAP()


// CProject14SWADoc construction/destruction

CProject14SWADoc::CProject14SWADoc()
{
	// TODO: add one-time construction code here

}

CProject14SWADoc::~CProject14SWADoc()
{
}

BOOL CProject14SWADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CProject14SWADoc serialization

void CProject14SWADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CProject14SWADoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CProject14SWADoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CProject14SWADoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CProject14SWADoc diagnostics

#ifdef _DEBUG
void CProject14SWADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProject14SWADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CProject14SWADoc commands


void CProject14SWADoc::OnWindowNewWindow()
{
    ::AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_WINDOW_NEW );
}
