
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
	afx_msg void OnBnClickedAdd();
	CListCtrl initialList;
	afx_msg void OnLvnItemchangedInput(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl finalList;
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedClean();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	BOOL addInvoice();
	void division();
	afx_msg void OnNMDblclkInput(NMHDR* pNMHDR, LRESULT* pResult);
	void showEditWindow(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedImport();
	afx_msg void OnBnClickedExport();
	void importFile(CString filename);
	void exportFile(CString filename);
//	afx_msg void OnNMReturnInput(NMHDR* pNMHDR, LRESULT* pResult);
};
