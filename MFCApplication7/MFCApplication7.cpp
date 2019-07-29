
// MFCApplication7.cpp: 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MFCApplication7Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7App

BEGIN_MESSAGE_MAP(CMFCApplication7App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCApplication7App 생성

CMFCApplication7App::CMFCApplication7App()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CMFCApplication7App 개체입니다.

CMFCApplication7App theApp;


// CMFCApplication7App 초기화

BOOL CMFCApplication7App::InitInstance()
{
	CWinApp::InitInstance();

	CMFCApplication7Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

