// noPriceWarning.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "noPriceWarning.h"
#include "afxdialogex.h"


// noPriceWarning 对话框

IMPLEMENT_DYNAMIC(noPriceWarning, CDialogEx)

noPriceWarning::noPriceWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NOPRICE_DIALOG, pParent)
{

}

noPriceWarning::~noPriceWarning()
{
}

void noPriceWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(noPriceWarning, CDialogEx)
END_MESSAGE_MAP()


// noPriceWarning 消息处理程序
