// duoPriceWarning.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "duoPriceWarning.h"
#include "afxdialogex.h"


// duoPriceWarning 对话框

IMPLEMENT_DYNAMIC(duoPriceWarning, CDialogEx)

duoPriceWarning::duoPriceWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DUOPRICE_DIALOG, pParent)
{

}

duoPriceWarning::~duoPriceWarning()
{
}

void duoPriceWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(duoPriceWarning, CDialogEx)
END_MESSAGE_MAP()


// duoPriceWarning 消息处理程序
