#pragma once

// DIALOG2 对话框

class DIALOG2 : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG2)

public:
	DIALOG2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIALOG2();
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

	
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	void OnControlPrint(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();	
	HWND hwnd;
	//afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
};
