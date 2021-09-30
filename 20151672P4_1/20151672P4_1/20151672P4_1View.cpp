
// 20151672P4_1View.cpp: CMy20151672P41View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151672P4_1.h"
#endif

#include "20151672P4_1Doc.h"
#include "20151672P4_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CFont big_font;

// CMy20151672P41View

IMPLEMENT_DYNCREATE(CMy20151672P41View, CView)

BEGIN_MESSAGE_MAP(CMy20151672P41View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20151672P41View 생성/소멸

CMy20151672P41View::CMy20151672P41View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151672P41View::~CMy20151672P41View()
{
}

BOOL CMy20151672P41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151672P41View 그리기

void CMy20151672P41View::OnDraw(CDC* /*pDC*/)
{
	big_font.CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("굴림체"));
	CMy20151672P41Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CFont* p_old_font = dc.SelectObject(&big_font);
	CRect rect;
	CRect rect1;
	GetClientRect(&rect1);
	GetClientRect(&rect);
	dc.DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	
	dc.SelectObject(p_old_font);
	big_font.DeleteObject();

	rect1.SetRect(0, 0, 80, 2000);
	dc.DrawText(recordText, rect1, DT_LEFT | DT_WORDBREAK);
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy20151672P41View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151672P41View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151672P41View 진단

#ifdef _DEBUG
void CMy20151672P41View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151672P41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151672P41Doc* CMy20151672P41View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151672P41Doc)));
	return (CMy20151672P41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151672P41View 메시지 처리기


void CMy20151672P41View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_nMSec++;
	if (m_nMSec >= 100) {
		m_nMSec = 0;
		m_nSecond++;
		if (m_nSecond >= 60) {
			m_nSecond = 0;
			m_nMinute++;
			if (m_nMinute >= 60) {
				m_nMinute = 0;
			}
		}
	}                                      

	
	

	m_strStopWatch.Format(_T("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy20151672P41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStopWatchRun) { //실행중일때 정지함
		m_bStopWatchRun = FALSE;
		KillTimer(0);
	}
	else {
		m_bStopWatchRun = TRUE;
		SetTimer(0, 10, NULL);
	}

	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151672P41View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
		switch (nChar) {
		case VK_SPACE:
			m_strRecord[m_nCount] = m_strStopWatch;
			recordText += m_strStopWatch;
			recordText += "  ";
			m_nCount++;
			
			if (m_nCount >= 40) {
				for (int i = 0; i < 40; i++)
					m_strRecord[i] = "";
				m_nCount = 0;
				recordText = "";
			}
			
		}
	
	
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151672P41View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!m_bStopWatchRun) {
		if (AfxMessageBox(_T("초기화?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			KillTimer(0);
			m_strStopWatch.Format(_T("00:00. 00"));
			m_nCount = 0;
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
			recordText = "";
		}
	}
	else {
		AfxMessageBox(_T("동작중 초기화 x"));
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
