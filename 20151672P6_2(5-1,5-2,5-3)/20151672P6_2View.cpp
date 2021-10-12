
// 20151672P6_2View.cpp: CMy20151672P62View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151672P6_2.h"
#endif

#include "20151672P6_2Doc.h"
#include "20151672P6_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MainFrm.h"


// CMy20151672P62View

IMPLEMENT_DYNCREATE(CMy20151672P62View, CView)

BEGIN_MESSAGE_MAP(CMy20151672P62View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151672P62View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CMy20151672P62View::OnLine)
	ON_COMMAND(ID_ELLIPSE, &CMy20151672P62View::OnEllipse)
	ON_COMMAND(ID_POLYGON, &CMy20151672P62View::OnPolygon)
	ON_COMMAND(ID_LINE_COLOR, &CMy20151672P62View::OnLineColor)
	ON_COMMAND(ID_FACE_COLOR, &CMy20151672P62View::OnFaceColor)
	ON_COMMAND(ID_BDIAGONAL, &CMy20151672P62View::OnBdiagonal)
	ON_COMMAND(ID_CROSS, &CMy20151672P62View::OnCross)
	ON_COMMAND(ID_VERTICAL, &CMy20151672P62View::OnVertical)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMy20151672P62View::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, &CMy20151672P62View::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_POLYGON, &CMy20151672P62View::OnUpdatePolygon)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy20151672P62View 생성/소멸

CMy20151672P62View::CMy20151672P62View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151672P62View::~CMy20151672P62View()
{
}

BOOL CMy20151672P62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151672P62View 그리기

void CMy20151672P62View::OnDraw(CDC* /*pDC*/)
{
	CMy20151672P62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy20151672P62View 인쇄


void CMy20151672P62View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151672P62View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151672P62View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151672P62View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20151672P62View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151672P62View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151672P62View 진단

#ifdef _DEBUG
void CMy20151672P62View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151672P62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151672P62Doc* CMy20151672P62View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151672P62Doc)));
	return (CMy20151672P62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151672P62View 메시지 처리기


void CMy20151672P62View::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = LINE_MODE;

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->m_wndStatusBar.SetWindowText(_T("직선 그리기"));
}


void CMy20151672P62View::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = ELLIPSE_MODE;

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->m_wndStatusBar.SetWindowText(_T("원 그리기"));
}


void CMy20151672P62View::OnPolygon()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = POLYGON_MODE;

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->m_wndStatusBar.SetWindowText(_T("다각형 그리기"));
}


void CMy20151672P62View::OnLineColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	AfxMessageBox(_T("선의 색상을 변경합니다."));
}


void CMy20151672P62View::OnFaceColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	AfxMessageBox(_T("면의 색상을 변경합니다."));
}


void CMy20151672P62View::OnBdiagonal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHatchStyle = HS_BDIAGONAL;
}


void CMy20151672P62View::OnCross()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHatchStyle = HS_CROSS;
}


void CMy20151672P62View::OnVertical()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHatchStyle = HS_VERTICAL;
}


void CMy20151672P62View::OnUpdateLine(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == LINE_MODE ? 1 : 0);
}


void CMy20151672P62View::OnUpdateEllipse(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == ELLIPSE_MODE  ? 1 : 0);
}


void CMy20151672P62View::OnUpdatePolygon(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == POLYGON_MODE  ? 1 : 0);
}


void CMy20151672P62View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	CString strPoint;
	strPoint.Format(_T("마우스 위치 x : %d, y : %d"), point.x, point.y);

	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);
	CView::OnMouseMove(nFlags, point);
}
