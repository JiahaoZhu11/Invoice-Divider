// invalidPriceWarning.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "invalidPriceWarning.h"
#include "afxdialogex.h"


// invalidPriceWarning 对话框

IMPLEMENT_DYNAMIC(invalidPriceWarning, CDialogEx)

invalidPriceWarning::invalidPriceWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVALIDPRICE_DIALOG, pParent)
{

}

invalidPriceWarning::~invalidPriceWarning()
{
}

void invalidPriceWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(invalidPriceWarning, CDialogEx)
END_MESSAGE_MAP()


// invalidPriceWarning 消息处理程序
