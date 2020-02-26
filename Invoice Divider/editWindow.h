#pragma once

#include <vector>
using namespace std;


// editWindow 对话框

class editWindow : public CDialogEx
{
	DECLARE_DYNAMIC(editWindow)

public:
	editWindow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~editWindow();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	//目标指针
	Invoice* target;
	CListCtrl* initialList;

	//操作函数
	afx_msg void OnEnKillfocusName();
	afx_msg void OnEnKillfocusNum();
	afx_msg void OnEnKillfocusUprice();
	afx_msg void OnEnKillfocusTprice();
	afx_msg void OnBnClickedEdit();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClose();

	//辅助函数
	void display();
	void modify();
	BOOL InputCheck(int type);
};
