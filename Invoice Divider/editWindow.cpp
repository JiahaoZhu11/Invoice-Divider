// editWindow.cpp: 实现文件
//

#include "pch.h"
#include "Invoice Divider.h"
#include "editWindow.h"
#include "afxdialogex.h"


// editWindow 对话框

IMPLEMENT_DYNAMIC(editWindow, CDialogEx)

editWindow::editWindow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDIT_DIALOG, pParent)
{
	target = NULL;
	initialList = NULL;
}

editWindow::~editWindow()
{
}

void editWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(editWindow, CDialogEx)
	ON_BN_CLICKED(IDC_EDIT, &editWindow::OnBnClickedEdit)
	ON_EN_KILLFOCUS(IDC_NAME, &editWindow::OnEnKillfocusName)
	ON_WM_CLOSE()
	ON_WM_CLOSE()
	ON_EN_KILLFOCUS(IDC_NUM, &editWindow::OnEnKillfocusNum)
	ON_EN_KILLFOCUS(IDC_UPRICE, &editWindow::OnEnKillfocusUprice)
	ON_EN_KILLFOCUS(IDC_TPRICE, &editWindow::OnEnKillfocusTprice)
END_MESSAGE_MAP()


// editWindow 消息处理程序


BOOL editWindow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	display();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL EnterChecking = FALSE;


void editWindow::OnEnKillfocusName()
{
	// TODO: 在此添加控件通知处理程序代码

	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(1);
	}

}


void editWindow::OnEnKillfocusNum()
{
	// TODO: 在此添加控件通知处理程序代码

	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(2);
	}

}


void editWindow::OnEnKillfocusUprice()
{
	// TODO: 在此添加控件通知处理程序代码

	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(3);
	}

}


void editWindow::OnEnKillfocusTprice()
{
	// TODO: 在此添加控件通知处理程序代码

	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(4);
	}

}


void editWindow::OnBnClickedEdit()
{
	// TODO: 在此添加控件通知处理程序代码

	modify();
	EndDialog(0);

}


void editWindow::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	display();

	CDialogEx::OnClose();
}


void editWindow::display()
{
	// TODO: 在此处添加实现代码.

	SetDlgItemText(IDC_NAME, target->iName);
	CString strUprice;
	strUprice.Format(_T("%f"), target->iUprice);
	SetDlgItemText(IDC_UPRICE, strUprice);
	CString strTprice;
	strTprice.Format(_T("%.02f"), target->iTprice);
	SetDlgItemText(IDC_TPRICE, strTprice);
	CString strNum;
	strNum.Format(_T("%d"), target->iNum);
	SetDlgItemText(IDC_NUM, strNum);

}


void editWindow::modify()
{
	// TODO: 在此处添加实现代码.

	CString strUprice;
	strUprice.Format(_T("%f"), target->iUprice);
	SetDlgItemText(IDC_UPRICE, strUprice);
	CString strTprice;
	strTprice.Format(_T("%.02f"), target->iTprice);
	SetDlgItemText(IDC_TPRICE, strTprice);
	CString strNum;
	strNum.Format(_T("%d"), target->iNum);
	SetDlgItemText(IDC_NUM, strNum);

	initialList->SetItemText(target->invoice - 1, 1, target->iName);
	initialList->SetItemText(target->invoice - 1, 2, strUprice);
	initialList->SetItemText(target->invoice - 1, 3, strNum);
	initialList->SetItemText(target->invoice - 1, 4, strTprice);

}


BOOL editWindow::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (InputCheck(5))
		{
			modify();
			EndDialog(0);
		}
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


// 1 = name, 2 = num, 3 = uprice, 4 = tprice, 5 == all
// TRUE when all check passed
BOOL editWindow::InputCheck(int type)
{

	if (type == 5)
	{
		EnterChecking = TRUE;
	}
	
	if (type == 1 || type == 5)
	{
		CString tempName;
		GetDlgItemText(IDC_NAME, tempName);

		if (tempName == "")
		{
			EnterChecking = !MessageBox(_T("请输入项目名称！"), _T(""), 0x00000030L);
			GetDlgItem(IDC_NAME)->SetFocus();
			return FALSE;
		}
		target->iName = tempName;
	}

	if (type == 2 || type == 5)
	{
		CString tempNum;
		GetDlgItemText(IDC_NUM, tempNum);

		if (tempNum == "")
		{
			EnterChecking = !MessageBox(_T("请输入项目数量！"), _T(""), 0x00000030L);
			GetDlgItem(IDC_NUM)->SetFocus();
			return FALSE;
		}
		for (int i = 0; i < tempNum.GetLength(); i++)
		{
			if (tempNum[i] < '0' || tempNum[i] > '9')
			{
				EnterChecking = !MessageBox(_T("请输入有效数量！"), _T(""), 0x00000030L);
				GetDlgItem(IDC_NUM)->SetFocus();
				return FALSE;
			}
		}
		target->iNum = _ttoi(tempNum);
		target->iTprice = target->iUprice * target->iNum;
		CString strTprice;
		strTprice.Format(_T("%.02f"), target->iTprice);
		SetDlgItemText(IDC_TPRICE, strTprice);
	}

	if (type == 3 || type == 5)
	{
		CString tempUprice;
		GetDlgItemText(IDC_UPRICE, tempUprice);

		if (tempUprice == "")
		{
			CString strUprice;
			strUprice.Format(_T("%f"), target->iUprice);
			SetDlgItemText(IDC_UPRICE, strUprice);
		}
		else
		{
			bool decimal = FALSE;
			for (int i = 0; i < tempUprice.GetLength(); i++)
			{
				if (tempUprice[i] < '0' || tempUprice[i] > '9')
				{
					if (tempUprice[i] == '.' && !decimal)
					{
						decimal = TRUE;
					}
					else
					{
						EnterChecking = !MessageBox(_T("请输入有效价格！"), _T(""), 0x00000030L);
						GetDlgItem(IDC_UPRICE)->SetFocus();
						return FALSE;
					}
				}
			}
			target->iUprice = _tstof(tempUprice);
			target->iTprice = target->iUprice * target->iNum;
			CString strTprice;
			strTprice.Format(_T("%.02f"), target->iTprice);
			SetDlgItemText(IDC_TPRICE, strTprice);
		}
	}

	if (type == 4 || type == 5)
	{
		CString tempTprice;
	GetDlgItemText(IDC_TPRICE, tempTprice);

	if (tempTprice == "")
	{
		CString strTprice;
		strTprice.Format(_T("%.02f"), target->iTprice);
		SetDlgItemText(IDC_TPRICE, strTprice);
	}
	else
	{
		bool decimal = FALSE;
		for (int i = 0; i < tempTprice.GetLength(); i++)
		{
			if (tempTprice[i] < '0' || tempTprice[i] > '9')
			{
				if (tempTprice[i] == '.' && !decimal)
				{
					decimal = TRUE;
				}
				else
				{
					EnterChecking = !MessageBox(_T("请输入有效价格！"), _T(""), 0x00000030L);
					GetDlgItem(IDC_TPRICE)->SetFocus();
					return FALSE;
				}
			}
		}
		target->iTprice = _tstof(tempTprice);
		target->iUprice = target->iTprice / target->iNum;
		CString strUprice;
		strUprice.Format(_T("%f"), target->iUprice);
		SetDlgItemText(IDC_UPRICE, strUprice);
	}
	}

	return TRUE;

}
