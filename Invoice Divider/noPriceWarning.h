#pragma once


// noPriceWarning 对话框

class noPriceWarning : public CDialogEx
{
	DECLARE_DYNAMIC(noPriceWarning)

public:
	noPriceWarning(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~noPriceWarning();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOPRICE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
