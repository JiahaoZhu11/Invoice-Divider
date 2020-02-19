
// Invoice DividerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Invoice Divider.h"
#include "Invoice DividerDlg.h"
#include "afxdialogex.h"
#include "noNameWarning.h"
#include "noPriceWarning.h"
#include "noNumWarning.h"
#include "duoPriceWarning.h"
#include "invalidPriceWarning.h"
#include "invalidNumWarning.h"
#include "InvoiceLST.h"
//#include "DivisionTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CInvoiceDividerDlg 对话框



CInvoiceDividerDlg::CInvoiceDividerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVOICEDIVIDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInvoiceDividerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, input, initialList);
	DDX_Control(pDX, output, finalList);
}

BEGIN_MESSAGE_MAP(CInvoiceDividerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(name, &CInvoiceDividerDlg::OnEnChangename)
	ON_EN_CHANGE(uprice, &CInvoiceDividerDlg::OnEnChangeuprice)
	ON_EN_CHANGE(tprice, &CInvoiceDividerDlg::OnEnChangetprice)
	ON_EN_CHANGE(num, &CInvoiceDividerDlg::OnEnChangenum)
	ON_BN_CLICKED(add, &CInvoiceDividerDlg::OnBnClickedadd)
	ON_NOTIFY(LVN_ITEMCHANGED, input, &CInvoiceDividerDlg::OnLvnItemchangedinput)
	ON_BN_CLICKED(divide, &CInvoiceDividerDlg::OnBnClickeddivide)
END_MESSAGE_MAP()


// CInvoiceDividerDlg 消息处理程序

BOOL CInvoiceDividerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	initialList.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	initialList.InsertColumn(0,_T(" 发票"),0,120);
	initialList.InsertColumn(1,_T(" 项目"),0,400);
	initialList.InsertColumn(2,_T(" 单价"),0,200);
	initialList.InsertColumn(3,_T(" 数量"),0,200);
	initialList.InsertColumn(4,_T(" 总价"),0,200);

	finalList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	finalList.InsertColumn(0, _T(" 发票"), 0, 120);
	finalList.InsertColumn(1, _T(" 项目"), 0, 400);
	finalList.InsertColumn(2, _T(" 单价"), 0, 200);
	finalList.InsertColumn(3, _T(" 数量"), 0, 200);
	finalList.InsertColumn(4, _T(" 总价"), 0, 200);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CInvoiceDividerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInvoiceDividerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CInvoiceDividerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CString itemName;
double itemUprice;
double itemTprice;
int itemNum;
bool decimal;


void CInvoiceDividerDlg::OnEnChangename()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInvoiceDividerDlg::OnEnChangeuprice()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInvoiceDividerDlg::OnEnChangetprice()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInvoiceDividerDlg::OnEnChangenum()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

int count = 0;
InvoiceLST iList;

void CInvoiceDividerDlg::OnBnClickedadd()
{
	// TODO: 在此添加控件通知处理程序代码

	CString tempCount;
	CString tempName;
	CString tempUprice;
	CString tempTprice;
	double calUprice;
	double calTprice;
	CString tempNum;

	GetDlgItemText(name, tempName);
	GetDlgItemText(uprice, tempUprice);
	GetDlgItemText(tprice, tempTprice);
	GetDlgItemText(num, tempNum);

	if (tempName == "")
	{
		noNameWarning nNa;
		nNa.DoModal();
		return;
	}
	if (tempUprice == "" && tempTprice == "")
	{
		noPriceWarning nPr;
		nPr.DoModal();
		return;
	}

	if (tempNum == "")
	{
		noNumWarning nNu;
		nNu.DoModal();
		return;
	}

	if (tempUprice != "" && tempTprice != "")
	{
		duoPriceWarning dPr;
		dPr.DoModal();
		return;
	}

	decimal = FALSE;

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
				invalidPriceWarning iUP;
				iUP.DoModal();
				return;
			}
		}
	}

	decimal = FALSE;

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
				invalidPriceWarning iTP;
				iTP.DoModal();
				return;
			}
		}
	}
	
	for (int i = 0; i < tempNum.GetLength(); i++)
	{
		if (tempNum[i] < '0' || tempNum[i] > '9')
		{
			invalidNumWarning iNu;
			iNu.DoModal();
			return;
		}
	}

	tempCount.Format(_T("%d"), count+1);
	initialList.InsertItem(count, tempCount);

	if (tempTprice == "")
	{
		calUprice = _tstof(tempUprice);
		calTprice = calUprice * _ttoi(tempNum);
	}
	if (tempUprice == "")
	{
		calTprice = _tstof(tempTprice);
		calUprice = calTprice / _ttoi(tempNum);
	}

	tempUprice.Format(_T("%f"), calUprice);
	tempTprice.Format(_T("%.02f"), calTprice);

	initialList.SetItemText(count, 1, tempName);
	initialList.SetItemText(count, 2, tempUprice);
	initialList.SetItemText(count, 4, tempTprice);
	initialList.SetItemText(count, 3, tempNum);

	iList.append(_ttoi(tempCount), tempName, calUprice, calTprice, _ttoi(tempNum));

	count++;

	}


void CInvoiceDividerDlg::OnLvnItemchangedinput(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CInvoiceDividerDlg::OnBnClickeddivide()
{
	// TODO: 在此添加控件通知处理程序代码

	InvoiceLST fList;
	InvoiceLST tempList(iList);
	CString temp;
	int tempCount = 1;
	int tempInvoice = 1;
	double tempTprice = 0;
	CString sTprice;

	fList = division(tempList);

	//divisionTest(iList,fList);
	
	//finalList.InsertItem(0, fList.test());

	/*if (!fList.isEmpty())
	{
		temp.Format(_T("%d"), 1);
		finalList.InsertItem(0, temp);

		temp = fList.getName();
		finalList.SetItemText(0, 1, temp);

		temp.Format(_T("%f"), fList.getUprice());
		finalList.SetItemText(0, 2, temp);

		temp.Format(_T("%d"), fList.getNum());
		finalList.SetItemText(0, 3, temp);

		tempTprice = fList.getTprice();

		fList.remove(1);
	}
	
	count = 1;

	while (!fList.isEmpty())
	{
		if (fList.getInvoice() != tempInvoice)
		{
			temp.Format(_T("%d"), fList.getInvoice());
			finalList.InsertItem(count, temp);
			sTprice.Format(_T("%.02f"), tempTprice);
			finalList.SetItemText(tempCount-1, 4, sTprice);
			tempCount = fList.getInvoice();
			tempTprice = fList.getTprice();
		}
		else
		{
			temp = "";
			tempTprice += fList.getTprice();
			finalList.InsertItem(count, temp);
		}

		temp = fList.getName();
		finalList.SetItemText(count, 1, temp);

		temp.Format(_T("%f"), fList.getUprice());
		finalList.SetItemText(count, 2, temp);

		temp.Format(_T("%d"), fList.getNum());
		finalList.SetItemText(count, 3, temp);
		
		count++;
		
		fList.remove(tempCount);
	}

	sTprice.Format(_T("%.02f"), tempTprice);
	finalList.SetItemText(tempCount-1, 4, sTprice);*/
	
}
