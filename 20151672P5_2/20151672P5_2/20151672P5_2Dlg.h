
// 20151672P5_2Dlg.h: 헤더 파일
//

#pragma once
#include "CClockHelpDlg.h"

// CMy20151672P52Dlg 대화 상자
class CMy20151672P52Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20151672P52Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151672P5_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strTime;
	afx_msg void OnEnChangeEditTime();
	bool m_bView=FALSE;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRadioView();
	afx_msg void OnRadioHide();
	CClockHelpDlg m_dlgClockHelp;
//	afx_msg void OnBnClickedButtonInform();
	bool m_bViewHelp=FALSE;
	afx_msg void OnClickedButtonInform();
};
