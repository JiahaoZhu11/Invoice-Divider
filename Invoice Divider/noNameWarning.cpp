// noNameWarning.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "noNameWarning.h"
#include "afxdialogex.h"


// noNameWarning 对话框

IMPLEMENT_DYNAMIC(noNameWarning, CDialogEx)

noNameWarning::noNameWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NONAME_DIALOG, pParent)
{

}

noNameWarning::~noNameWarning()
{
}

void noNameWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(noNameWarning, CDialogEx)
END_MESSAGE_MAP()


// noNameWarning 消息处理程序
