
// 20151672P6_1View.cpp: CMy20151672P61View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151672P6_1.h"
#endif

#include "20151672P6_1Doc.h"
#include "20151672P6_1View.h"
#include"MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151672P61View

IMPLEMENT_DYNCREATE(CMy20151672P61View, CView)

BEGIN_MESSAGE_MAP(CMy20151672P61View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151672P61View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MYNEW, &CMy20151672P61View::OnMynew)
END_MESSAGE_MAP()

// CMy20151672P61View 생성/소멸

CMy20151672P61View::CMy20151672P61View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bFont = false;
}

CMy20151672P61View::~CMy20151672P61View()
{
}

BOOL CMy20151672P61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151672P61View 그리기

void CMy20151672P61View::OnDraw(CDC* pDC)
{
	CMy20151672P61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont* oldFont, * currentFont, newFont;

	if (m_bFont == TRUE) {
		newFont.CreateFontIndirect(&m_logFont);
		oldFont = pDC->SelectObject(&newFont);
	}
	else {
		currentFont = pDC->GetCurrentFont();
		oldFont = pDC->SelectObject(currentFont);
	}

	pDC->SetTextColor(m_colorText);

	pDC->TextOut(m_ptPosition.x, m_ptPosition.y, m_strOutput);

	CSize sizeText;
	sizeText = pDC->GetTextExtent(m_strOutput);
	m_nTextWidth = sizeText.cx;
	m_nTextHeight = sizeText.cy;

	pDC->SelectObject(oldFont);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy20151672P61View 인쇄


void CMy20151672P61View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151672P61View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151672P61View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151672P61View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20151672P61View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151672P61View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151672P61View 진단

#ifdef _DEBUG
void CMy20151672P61View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151672P61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151672P61Doc* CMy20151672P61View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151672P61Doc)));
	return (CMy20151672P61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151672P61View 메시지 처리기


void CMy20151672P61View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT:
		m_ptPosition.x -= 10;
		break;
	case VK_RIGHT:
		m_ptPosition.x += 10;
		break;
	case VK_UP:
		m_ptPosition.y -= 10;
		break;
	case VK_DOWN:
		m_ptPosition.y += 10;
		break;
	}
	if (m_ptPosition.x < 0) {
		m_ptPosition.x = 0;
		AfxMessageBox(_T("왼쪽으로 이동 불가"));
	}
	if (m_ptPosition.y < 0) {
		m_ptPosition.y = 0;
		AfxMessageBox(_T("위쪽으로 이동 불가"));
	}
	RECT rect;
	GetClientRect(&rect);
	if (m_ptPosition.x > rect.right - m_nTextWidth)
	{
		m_ptPosition.x = rect.right - m_nTextWidth;
		AfxMessageBox(_T("오른쪽으로 이동 불가"));
	}
	if (m_ptPosition.y > rect.bottom - m_nTextHeight)
	{
		m_ptPosition.y = rect.bottom - m_nTextHeight;
		AfxMessageBox(_T("아래쪽으로 이동 불가"));
	}

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_X, m_ptPosition.x);
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_Y, m_ptPosition.y);
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151672P61View::OnMynew()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	AfxMessageBox(_T("만든메뉴"));
}
