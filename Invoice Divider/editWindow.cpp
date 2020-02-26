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



//变量

//是否在“Enter”键检查中
BOOL EnterChecking = FALSE;



//操作函数

//“Name”编辑框失去焦点
void editWindow::OnEnKillfocusName()
{
	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(1);
	}
}


//“Num”编辑框失去焦点
void editWindow::OnEnKillfocusNum()
{
	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(2);
	}
}


//“Uprice”编辑框失去焦点
void editWindow::OnEnKillfocusUprice()
{
	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(3);
	}
}


//“Tprice”编辑框失去焦点
void editWindow::OnEnKillfocusTprice()
{
	if (EnterChecking)
	{
		return;
	}
	else
	{
		InputCheck(4);
	}
}


//点击“修改”按钮
void editWindow::OnBnClickedEdit()
{
	modify();
	EndDialog(0);
}


//键盘信息拦截处理
BOOL editWindow::PreTranslateMessage(MSG* pMsg)
{
	//“Enter”键处理
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (InputCheck(5))
		{
			modify();
			EndDialog(0);
		}
		return TRUE;
	}
	//默认输出
	return CDialogEx::PreTranslateMessage(pMsg);
}


//关闭对话框
void editWindow::OnClose()
{
	display();
	CDialogEx::OnClose();
}



//辅助函数

//显示原数据
void editWindow::display()
{
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


//修改数据
void editWindow::modify()
{
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


//检查输入数据
// 1 = name, 2 = num, 3 = uprice, 4 = tprice, 5 = 全部（“Enter”键检查）
// TRUE当通过所以检查
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
