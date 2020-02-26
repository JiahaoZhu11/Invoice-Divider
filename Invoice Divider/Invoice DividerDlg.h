
// Invoice DividerDlg.h: 头文件
//

#pragma once

#include "libxl.h"
using namespace libxl;

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
	CListCtrl initialList;
	CListCtrl finalList;

	//操作函数
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedClean();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedImport();
	afx_msg void OnBnClickedExport();
	afx_msg void OnNMDblclkInput(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	//辅助函数
	BOOL addInvoice();
	void division();
	void showEditWindow(NMHDR* pNMHDR, LRESULT* pResult);
	void importFile(CString filename);
	void importBook(Book* book, CString filename);
	CString removeEndZero(CString strNum);
	void exportFile(CString filename);
	void exportBook(Book* book, CString filename);
};
