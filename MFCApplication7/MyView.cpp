// MyView.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MyView.h"
#include "afxdialogex.h"


// MyView 대화 상자

IMPLEMENT_DYNAMIC(MyView, CDialogEx)

MyView::MyView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_VIEW, pParent)
{

}

MyView::~MyView()
{
}

void MyView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyView, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyView::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MyView::OnBnClickedCancel)
END_MESSAGE_MAP()


// MyView 메시지 처리기


void MyView::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
}


void MyView::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnCancel();
}


BOOL MyView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(0, 100, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
