﻿#pragma once


// noNameWarning 对话框

class noNameWarning : public CDialogEx
{
	DECLARE_DYNAMIC(noNameWarning)

public:
	noNameWarning(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~noNameWarning();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NONAME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
