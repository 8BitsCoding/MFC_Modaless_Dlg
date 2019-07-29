
// MFCApplication7Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MFCApplication7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7Dlg 대화 상자



CMFCApplication7Dlg::CMFCApplication7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication7Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_BUTTON, &CMFCApplication7Dlg::OnBnClickedShowButton)
	ON_WM_DESTROY()
	ON_MESSAGE(27000, &CMFCApplication7Dlg::On27000)
	ON_BN_CLICKED(IDC_SET_BUTTON, &CMFCApplication7Dlg::OnBnClickedSetButton)
	ON_MESSAGE(27001, &CMFCApplication7Dlg::On27001)
END_MESSAGE_MAP()


// CMFCApplication7Dlg 메시지 처리기

BOOL CMFCApplication7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	
	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	mp_my_view = new MyView;
	mp_my_view->Create(IDD_MY_VIEW, this);
	mp_my_view->SetWindowPos(NULL, 0, 80, 0, 0, SWP_NOSIZE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication7Dlg::OnBnClickedShowButton()
{
	if (mp_new_dlg == NULL) {
		mp_new_dlg = new NewDlg;
		mp_new_dlg->Create(IDD_NEW_DLG, this);
	}
}


void CMFCApplication7Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (mp_new_dlg != NULL) {
		On27000(0, 0);
		//mp_new_dlg->DestroyWindow();
		//delete mp_new_dlg;
	}

	mp_my_view->DestroyWindow();
	delete mp_my_view;
}


afx_msg LRESULT CMFCApplication7Dlg::On27000(WPARAM wParam, LPARAM lParam)
{
	mp_new_dlg->DestroyWindow();
	delete mp_new_dlg;
	mp_new_dlg = NULL;

	return 0;
}


void CMFCApplication7Dlg::OnBnClickedSetButton()
{
	if (mp_new_dlg != NULL) {
		int num = GetDlgItemInt(IDC_NUM_EDIT);
		mp_new_dlg->SetDlgItemInt(IDC_NUM_EDIT, num);
	}
	
}


afx_msg LRESULT CMFCApplication7Dlg::On27001(WPARAM wParam, LPARAM lParam)
{
	// (참고) WPARAM은 UINT이기에 형변환해야함.
	int num = (int)wParam;
	if (num < 0) num = num * (-1);
	SetDlgItemInt(IDC_NUM_EDIT, num);
	return 0;
}
