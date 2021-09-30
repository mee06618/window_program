
// 20151672P3_3View.cpp: CMy20151672P33View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include <math.h>
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151672P3_3.h"
#endif

#include "20151672P3_3Doc.h"
#include "20151672P3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151672P33View

IMPLEMENT_DYNCREATE(CMy20151672P33View, CView)

BEGIN_MESSAGE_MAP(CMy20151672P33View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20151672P33View 생성/소멸

CMy20151672P33View::CMy20151672P33View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CMy20151672P33View::~CMy20151672P33View()
{
}

BOOL CMy20151672P33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151672P33View 그리기

void CMy20151672P33View::OnDraw(CDC* pDC)
{
	CMy20151672P33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy20151672P33View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151672P33View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151672P33View 진단

#ifdef _DEBUG
void CMy20151672P33View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151672P33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151672P33Doc* CMy20151672P33View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151672P33Doc)));
	return (CMy20151672P33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151672P33View 메시지 처리기


void CMy20151672P33View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();

	if (nChar == VK_BACK)
		m_strOutput.Delete(nCharIndex - 1, 1);
	else
		m_strOutput += (WCHAR)nChar;

	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy20151672P33View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT:
		m_ptLocation.x--;
		break;
	case VK_RIGHT:
		m_ptLocation.x++;
		break;
	case VK_UP:
		m_ptLocation.y--;
		break;
	case VK_DOWN:
		m_ptLocation.y++;
		break;
	case VK_PRIOR:
		m_ptLocation.y -= 50;
		break;
	case VK_NEXT:
		m_ptLocation.y += 50;
		break;
	case VK_HOME:
		m_ptLocation = CPoint(0, 0);
		break;
	}

	if (m_ptLocation.x < 0)
	{
		m_ptLocation.x = 0;
		AfxMessageBox(_T("왼쪽으로 이동 불가"));
	}
	if (m_ptLocation.y < 0)
	{
		m_ptLocation.y = 0;
		AfxMessageBox(_T("위쪽으로 이동 불가"));
	}
	if (m_ptLocation.x > m_ptClientSize.x)
	{
		m_ptLocation.x = m_ptClientSize.x;
		AfxMessageBox(_T("오른쪽으로 이동 불가"));
	}
	if (m_ptLocation.y > m_ptClientSize.y)
	{
		m_ptLocation.y = m_ptClientSize.y;
		AfxMessageBox(_T("아래쪽으로 이동 불가"));
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151672P33View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;
	Invalidate();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMy20151672P33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	float locationPow = sqrt(pow((m_ptLocation.x - point.x), 2) + pow((m_ptLocation.y - point.y), 2));

	if (locationPow <= 30)
		m_bDrag = true;

	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151672P33View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_strOutput.IsEmpty() == false) {
		if (AfxMessageBox(_T("문자를 지울까요?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_strOutput.Empty();
		}
	}
	else {
		AfxMessageBox(_T("문자를 입력하시오"));
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy20151672P33View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag) {
		m_ptLocation.x = point.x;
		m_ptLocation.y = point.y;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMy20151672P33View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag) {
		m_bDrag = false;
		m_ptLocation.x = point.x;
		m_ptLocation.y = point.y;
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
