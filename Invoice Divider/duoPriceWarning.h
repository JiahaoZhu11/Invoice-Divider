#pragma once


// duoPriceWarning 对话框

class duoPriceWarning : public CDialogEx
{
	DECLARE_DYNAMIC(duoPriceWarning)

public:
	duoPriceWarning(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~duoPriceWarning();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DUOPRICE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
