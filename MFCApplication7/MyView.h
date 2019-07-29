﻿#pragma once


// MyView 대화 상자

class MyView : public CDialogEx
{
	DECLARE_DYNAMIC(MyView)

public:
	MyView(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MyView();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
