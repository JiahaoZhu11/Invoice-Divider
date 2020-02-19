#pragma once


// invalidPriceWarning 对话框

class invalidPriceWarning : public CDialogEx
{
	DECLARE_DYNAMIC(invalidPriceWarning)

public:
	invalidPriceWarning(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~invalidPriceWarning();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVALIDPRICE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
