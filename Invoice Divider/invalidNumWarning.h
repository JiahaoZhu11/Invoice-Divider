﻿#pragma once


// invalidNumWarning 对话框

class invalidNumWarning : public CDialogEx
{
	DECLARE_DYNAMIC(invalidNumWarning)

public:
	invalidNumWarning(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~invalidNumWarning();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVALIDNUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
