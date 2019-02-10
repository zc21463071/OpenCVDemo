// DIALOG2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "DIALOG2.h"
#include "afxdialogex.h"
#include "MFCDlg.h"


// DIALOG2 对话框

IMPLEMENT_DYNAMIC(DIALOG2, CDialogEx)

//IMPLEMENT_DYNAMIC(DIALOG2, CMFCDlg)
DIALOG2::DIALOG2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

DIALOG2::~DIALOG2()
{
}

void DIALOG2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
//afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);

afx_msg LRESULT OnMyMessage1(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	AfxMessageBox(_T("hello"));
	return 0;
}

//void  OnControlPrint(WPARAM wParam, LPARAM lParam);

BEGIN_MESSAGE_MAP(DIALOG2, CDialogEx)
	ON_BN_CLICKED(IDOK, &DIALOG2::OnBnClickedOk)
//ON_MESSAGE(WM_CONTROLPRINT, OnMyMessage)
	//ON_COMMAND(ID_MYCOMMAND, &CMFCListViewDoc::OnMycommand)
END_MESSAGE_MAP()
//
//BEGIN_MESSAGE_MAP(DIALOG2, CMFCDlg)
//	ON_BN_CLICKED(IDOK, &DIALOG2::OnBnClickedOk)
//END_MESSAGE_MAP()
// DIALOG2 消息处理程序


void DIALOG2::OnBnClickedOk()
{
	/*CWnd *pWnd = CWnd::FindWindow( _T("CMFCDlg"),NULL);
	HWND hwnd =  ::FindWindowEX(this->GetParent()->m_hWnd,NULL,NULL,RECRIVE1_TITLE);
	FromHandle(hwnd)->SendMessage(WM_CONTROLPRINT,NULL,0);
	PostMessage(WM_CONTROLPRINT, 1, 1);*/
	
CMFCDlg* pm = (CMFCDlg*)theApp.m_pMainWnd;
 hwnd = ::FindWindow(NULL,_T("IDD_MFCAPPLICATION1_DIALOG"));
 //hwnd->SendMessage(WM_CONTROLPRINT, 0, 0);

 SendMessage(WM_CONTROLPRINT);
	//CDialogEx::OnOK();


 HWND h = ::FindWindow(NULL, _T("MFCApplication1"));
 ::PostMessage(h, WM_CONTROLPRINT, 0, 0);//发送给任意窗口
 Sleep(500);
 ::SendMessage(h, WM_CONTROLPRINT, 0, 0);

}

//LRESULT DIALOG2::OnMyMessage(WPARAM wParam, LPARAM lParam)
//{
//	AfxMessageBox(_T("hello1"));
//	return LRESULT();
//}

