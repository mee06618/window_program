
// 20151672P6_1View.h: CMy20151672P61View 클래스의 인터페이스
//

#pragma once
#include "MainFrm.h"

#include "20151672P6_1View.h"

#include "20151672P6_1Doc.h"
class CMy20151672P61View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20151672P61View() noexcept;
	DECLARE_DYNCREATE(CMy20151672P61View)

// 특성입니다.
public:
	CMy20151672P61Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy20151672P61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutput;
	int m_nTextWidth;
	int m_nTextHeight;
	CPoint m_ptPosition;
	COLORREF m_colorText;
	bool m_bFont;
	LOGFONT m_logFont;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMynew();
};

#ifndef _DEBUG  // 20151672P6_1View.cpp의 디버그 버전
inline CMy20151672P61Doc* CMy20151672P61View::GetDocument() const
   { return reinterpret_cast<CMy20151672P61Doc*>(m_pDocument); }
#endif

