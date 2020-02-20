// invalidNumWarning.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "invalidNumWarning.h"
#include "afxdialogex.h"


// invalidNumWarning 对话框

IMPLEMENT_DYNAMIC(invalidNumWarning, CDialogEx)

invalidNumWarning::invalidNumWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVALIDNUM_DIALOG, pParent)
{

}

invalidNumWarning::~invalidNumWarning()
{
}

void invalidNumWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(invalidNumWarning, CDialogEx)
END_MESSAGE_MAP()


// invalidNumWarning 消息处理程序
