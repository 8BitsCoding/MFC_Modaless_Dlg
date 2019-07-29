
// MFCApplication7Dlg.h: 헤더 파일
//

#pragma once

#include "NewDlg.h"
#include "MyView.h"

// CMFCApplication7Dlg 대화 상자
class CMFCApplication7Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication7Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedShowButton();

	NewDlg * mp_new_dlg = NULL;
	MyView * mp_my_view = NULL;
	afx_msg void OnDestroy();
protected:
	afx_msg LRESULT On27000(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedSetButton();
protected:
	afx_msg LRESULT On27001(WPARAM wParam, LPARAM lParam);
};
