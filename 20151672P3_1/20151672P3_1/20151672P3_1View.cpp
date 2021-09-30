
// 20151672P3_1View.cpp: CMy20151672P31View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151672P3_1.h"
#endif

#include "20151672P3_1Doc.h"
#include "20151672P3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151672P31View

IMPLEMENT_DYNCREATE(CMy20151672P31View, CView)

BEGIN_MESSAGE_MAP(CMy20151672P31View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMy20151672P31View 생성/소멸

CMy20151672P31View::CMy20151672P31View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151672P31View::~CMy20151672P31View()
{
}

BOOL CMy20151672P31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151672P31View 그리기

void CMy20151672P31View::OnDraw(CDC* /*pDC*/)
{
	CMy20151672P31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy20151672P31View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151672P31View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151672P31View 진단

#ifdef _DEBUG
void CMy20151672P31View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151672P31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151672P31Doc* CMy20151672P31View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151672P31Doc)));
	return (CMy20151672P31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151672P31View 메시지 처리기


int CMy20151672P31View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	AfxMessageBox(_T("윈도우 생성"), MB_OKCANCEL | MB_ICONINFORMATION);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CMy20151672P31View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("왼쪽 마우스 더블클릭?"), MB_YESNO | MB_ICONQUESTION);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy20151672P31View::OnDestroy()
{
	CView::OnDestroy();
	AfxMessageBox(_T("윈도우 종료?"), MB_YESNO | MB_ICONWARNING);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}



