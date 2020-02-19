
// Invoice DividerDlg.h: 头文件
//

#pragma once


// CInvoiceDividerDlg 对话框
class CInvoiceDividerDlg : public CDialogEx
{
// 构造
public:
	CInvoiceDividerDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVOICEDIVIDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangename();
	afx_msg void OnEnChangeuprice();
	afx_msg void OnEnChangetprice();
	afx_msg void OnEnChangenum();
	afx_msg void OnBnClickedadd();
	CListCtrl initialList;
	afx_msg void OnLvnItemchangedinput(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl finalList;
	afx_msg void OnBnClickeddivide();
	afx_msg void OnBnClickeddel();
	afx_msg void OnBnClickedclean();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void addInvoice();
	void division();
	// type of warning: 1 = no name, 2 = no price, 3 = no number, 4 = invalid price, 5 = invalid number, 6 = duo price
	void warning(int type);
};
