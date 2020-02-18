// noNumWarning.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "noNumWarning.h"
#include "afxdialogex.h"


// noNumWarning 对话框

IMPLEMENT_DYNAMIC(noNumWarning, CDialogEx)

noNumWarning::noNumWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NONUM_DIALOG, pParent)
{

}

noNumWarning::~noNumWarning()
{
}

void noNumWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(noNumWarning, CDialogEx)
END_MESSAGE_MAP()


// noNumWarning 消息处理程序
