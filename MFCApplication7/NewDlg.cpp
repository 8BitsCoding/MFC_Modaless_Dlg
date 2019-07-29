// NewDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "NewDlg.h"
#include "afxdialogex.h"


// NewDlg 대화 상자

IMPLEMENT_DYNAMIC(NewDlg, CDialogEx)

NewDlg::NewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEW_DLG, pParent)
{

}

NewDlg::~NewDlg()
{
}

void NewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &NewDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_SET_BUTTON, &NewDlg::OnBnClickedSetButton)
END_MESSAGE_MAP()


// NewDlg 메시지 처리기


void NewDlg::OnBnClickedOk()
{
	GetParent()->PostMessageW(27000);
}


void NewDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnCancel();
}


void NewDlg::OnBnClickedSetButton()
{
	int num = GetDlgItemInt(IDC_NUM_EDIT);
	//GetParent()->SetDlgItemInt(IDC_NUM_EDIT, num);
	GetParent()->PostMessageW(27001, num);
}
