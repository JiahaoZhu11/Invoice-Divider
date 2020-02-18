#pragma once


// noNumWarning 对话框

class noNumWarning : public CDialogEx
{
	DECLARE_DYNAMIC(noNumWarning)

public:
	noNumWarning(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~noNumWarning();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NONUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
