
// 20151672P3_2View.cpp: CMy20151672P32View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151672P3_2.h"
#endif

#include "20151672P3_2Doc.h"
#include "20151672P3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151672P32View

IMPLEMENT_DYNCREATE(CMy20151672P32View, CView)

BEGIN_MESSAGE_MAP(CMy20151672P32View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMy20151672P32View 생성/소멸

CMy20151672P32View::CMy20151672P32View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bTimerRun = false;
	m_bTimerType = true;
}

CMy20151672P32View::~CMy20151672P32View()
{
}

BOOL CMy20151672P32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151672P32View 그리기

void CMy20151672P32View::OnDraw(CDC* pDC)
{
	CMy20151672P32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

void CMy20151672P32View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151672P32View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151672P32View 진단

#ifdef _DEBUG
void CMy20151672P32View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151672P32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151672P32Doc* CMy20151672P32View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151672P32Doc)));
	return (CMy20151672P32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151672P32View 메시지 처리기


int CMy20151672P32View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 1000, NULL);
	m_bTimerRun = TRUE;
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CMy20151672P32View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int hour;
	CString str;
	CTime timer;
	timer = CTime::GetCurrentTime();
	if (m_bTimerType) {
		m_strTimer.Format(_T("현재는 %d년 %d월 %d일 %d시 %d분 %d초"),
			timer.GetYear(), timer.GetMonth(), timer.GetDay(), timer.GetHour(),
			timer.GetMinute(), timer.GetSecond());
	}
	else {
		hour = timer.GetHour();
		if (hour >= 12)
		{
			str=_T("PM");
			if(hour>=13)
				hour=hour-12;
		}
		else {
			str = _T("AM");
		}
		m_strTimer.Format(_T("지금은 %s %d시 %d분 %d초"), str, hour, timer.GetMinute(), timer.GetSecond());

	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy20151672P32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerType) {
		if (AfxMessageBox(_T("시,분,초 형태로 표시?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_bTimerType = false;
		}
	}
	else {
		if (AfxMessageBox(_T("년,월,시,분,초 형태로 표시?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_bTimerType = true;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151672P32View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerRun == false) {
		if (AfxMessageBox(_T("디지털시계 작동?"), MB_YESNO | MB_ICONQUESTION )== IDYES)
		{
			SetTimer(0,1000,NULL);
				m_bTimerRun=true;
		}
	}
	else {
		if (AfxMessageBox(_T("디지털시계 정지??"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			KillTimer(0);
			m_bTimerRun =  false;
		}
	}
	CView::OnRButtonDown(nFlags, point);
}


void CMy20151672P32View::OnDestroy()
{
	CView::OnDestroy();
	if (m_bTimerRun) {
		KillTimer(0);
	}
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
