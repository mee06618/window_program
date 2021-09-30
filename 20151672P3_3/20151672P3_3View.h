
// 20151672P3_3View.h: CMy20151672P33View 클래스의 인터페이스
//

#pragma once


class CMy20151672P33View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20151672P33View() noexcept;
	DECLARE_DYNCREATE(CMy20151672P33View)

// 특성입니다.
public:
	CMy20151672P33Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy20151672P33View();
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
	CString m_strOutput=NULL;
	CPoint m_ptLocation=0;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_ptClientSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	bool m_bDrag = false;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20151672P3_3View.cpp의 디버그 버전
inline CMy20151672P33Doc* CMy20151672P33View::GetDocument() const
   { return reinterpret_cast<CMy20151672P33Doc*>(m_pDocument); }
#endif

