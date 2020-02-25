
// Invoice DividerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Invoice Divider.h"
#include "Invoice DividerDlg.h"
#include "afxdialogex.h"
#include "editWindow.h"
#include <vector>

using namespace std;

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
	DDX_Control(pDX, IDC_INPUT, initialList);
	DDX_Control(pDX, IDC_OUTPUT, finalList);
}

BEGIN_MESSAGE_MAP(CInvoiceDividerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CInvoiceDividerDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DIVIDE, &CInvoiceDividerDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_DEL, &CInvoiceDividerDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_CLEAN, &CInvoiceDividerDlg::OnBnClickedClean)
	ON_NOTIFY(NM_DBLCLK, IDC_INPUT, &CInvoiceDividerDlg::OnNMDblclkInput)
	ON_BN_CLICKED(IDC_IMPORT, &CInvoiceDividerDlg::OnBnClickedImport)
	ON_BN_CLICKED(IDC_EXPORT, &CInvoiceDividerDlg::OnBnClickedExport)
//	ON_NOTIFY(NM_RETURN, IDC_INPUT, &CInvoiceDividerDlg::OnNMReturnInput)
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


//全局变量
double totalPrice = 0;
CString strPrice;
vector<Invoice> dataIn;
vector<Invoice> dataOut;


void CInvoiceDividerDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码

	addInvoice();

}


void CInvoiceDividerDlg::OnLvnItemchangedInput(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CInvoiceDividerDlg::OnBnClickedDivide()
{
	// TODO: 在此添加控件通知处理程序代码

	division();
	
}


void CInvoiceDividerDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!dataIn.empty())
	{
		totalPrice -= dataIn.back().iTprice;
		strPrice.Format(_T("%.02f"), totalPrice);
		SetDlgItemText(IDC_TOTAL, strPrice);
		dataIn.pop_back();
		initialList.DeleteItem((int)dataIn.size());
	}

}


void CInvoiceDividerDlg::OnBnClickedClean()
{
	// TODO: 在此添加控件通知处理程序代码

	totalPrice = 0;
	strPrice.Format(_T("%.02f"), totalPrice);
	SetDlgItemText(IDC_TOTAL, strPrice);
	dataIn.clear();
	initialList.DeleteAllItems();

}

BOOL CInvoiceDividerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		CString tempName;
		CString tempUprice;
		CString tempTprice;
		CString tempNum;

		GetDlgItemText(IDC_NAME, tempName);
		GetDlgItemText(IDC_UPRICE, tempUprice);
		GetDlgItemText(IDC_TPRICE, tempTprice);
		GetDlgItemText(IDC_NUM, tempNum);
		if (GetFocus()->GetDlgCtrlID() == IDC_NAME)
		{
			if (tempName == "")
			{
				MessageBox(_T("请输入项目名称！"), _T(""), 0x00000030L);
			}
			else
			{
				GetDlgItem(IDC_UPRICE)->SetFocus();
				SendDlgItemMessage(IDC_UPRICE, EM_SETSEL, 0, -1);
			}
			return TRUE;
		}
		else if (GetFocus()->GetDlgCtrlID() == IDC_UPRICE)
		{
			if (tempUprice == "")
			{
				GetDlgItem(IDC_TPRICE)->SetFocus();
				SendDlgItemMessage(IDC_TPRICE, EM_SETSEL, 0, -1);
				return TRUE;
			}
			GetDlgItem(IDC_NUM)->SetFocus();
			SendDlgItemMessage(IDC_NUM, EM_SETSEL, 0, -1);
			return TRUE;
		}
		else if (GetFocus()->GetDlgCtrlID() == IDC_TPRICE)
		{
			if (tempTprice == "" && tempUprice == "")
			{
				MessageBox(_T("请输入项目价格!"), _T(""), 0x00000030L);
				GetDlgItem(IDC_UPRICE)->SetFocus();
				return TRUE;
			}
			GetDlgItem(IDC_NUM)->SetFocus();
			SendDlgItemMessage(IDC_NUM, EM_SETSEL, 0, -1);
			return TRUE;
		}
		else if (GetFocus()->GetDlgCtrlID() == IDC_NUM)
		{
			if (addInvoice())
			{
				GetDlgItem(IDC_NAME)->SetFocus();
				SendDlgItemMessage(IDC_NAME, EM_SETSEL, 0, -1);
			}

			return TRUE;
		}
		else if (GetFocus()->GetDlgCtrlID() == IDC_INPUT)
		{
			return	FALSE;
		}
		else if (GetFocus()->GetDlgCtrlID() == IDC_OUTPUT) return TRUE;
		else
		{
			return CDialogEx::PreTranslateMessage(pMsg);
		}
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;

	else return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CInvoiceDividerDlg::addInvoice()
{
	// TODO: 在此处添加实现代码.

	CString tempCount;
	double calUprice = 0;
	double calTprice = 0;
	CString tempName;
	CString tempUprice;
	CString tempTprice;
	CString tempNum;
	bool decimal = FALSE;

	GetDlgItemText(IDC_NAME, tempName);
	GetDlgItemText(IDC_UPRICE, tempUprice);
	GetDlgItemText(IDC_TPRICE, tempTprice);
	GetDlgItemText(IDC_NUM, tempNum);

	if (tempName == "")
	{
		MessageBox(_T("请输入项目名称！"), _T(""), 0x00000030L);
		GetDlgItem(IDC_NAME)->SetFocus();
		return FALSE;
	}
	if (tempUprice == "" && tempTprice == "")
	{
		MessageBox(_T("请输入项目价格！"), _T(""), 0x00000030L);
		GetDlgItem(IDC_UPRICE)->SetFocus();
		return FALSE;
	}

	if (tempNum == "")
	{
		MessageBox(_T("请输入项目数量！"), _T(""), 0x00000030L);
		GetDlgItem(IDC_NUM)->SetFocus();
		return FALSE;
	}

	if (tempUprice != "" && tempTprice != "")
	{
		MessageBox(_T("请勿同时输入单价和总价！"), _T(""), 0x00000030L);
		GetDlgItem(IDC_UPRICE)->SetFocus();
		SendDlgItemMessage(IDC_UPRICE, EM_SETSEL, 0, -1);
		return FALSE;
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
				MessageBox(_T("请输入有效价格！"), _T(""), 0x00000030L);
				GetDlgItem(IDC_UPRICE)->SetFocus();
				SendDlgItemMessage(IDC_UPRICE, EM_SETSEL, 0, -1);
				return FALSE;
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
				MessageBox(_T("请输入有效价格！"), _T(""), 0x00000030L);
				GetDlgItem(IDC_TPRICE)->SetFocus();
				SendDlgItemMessage(IDC_TPRICE, EM_SETSEL, 0, -1);
				return FALSE;
			}
		}
	}

	for (int i = 0; i < tempNum.GetLength(); i++)
	{
		if (tempNum[i] < '0' || tempNum[i] > '9')
		{
			MessageBox(_T("请输入有效数量！"), _T(""), 0x00000030L);
			GetDlgItem(IDC_NUM)->SetFocus();
			SendDlgItemMessage(IDC_NUM, EM_SETSEL, 0, -1);
			return FALSE;
		}
	}

	tempCount.Format(_T("%d"), (int)dataIn.size() + 1);
	initialList.InsertItem((int)dataIn.size(), tempCount);

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

	initialList.SetItemText((int)dataIn.size(), 1, tempName);
	initialList.SetItemText((int)dataIn.size(), 2, tempUprice);
	initialList.SetItemText((int)dataIn.size(), 4, tempTprice);
	initialList.SetItemText((int)dataIn.size(), 3, tempNum);

	Invoice i = newInvoice(_ttoi(tempCount), tempName, calUprice, calTprice, _ttoi(tempNum));
	dataIn.push_back(i);

	totalPrice += calTprice;
	strPrice.Format(_T("%.02f"), totalPrice);
	SetDlgItemText(IDC_TOTAL, strPrice);

	return TRUE;

}


void CInvoiceDividerDlg::division()
{
	// TODO: 在此处添加实现代码.

	if (dataIn.empty())
	{
		return;
	}

	Invoice tempIn;
	CString temp;
	double freeSpace = 112999.98;
	int tempInvoice = 1;
	int tempNum = 0;
	int remainNum = 0;
	int firstIndex = 0;

	dataOut.clear();
	finalList.DeleteAllItems();

	for (size_t i = 0; i < dataIn.size(); i++)
	{
		if (dataIn[i].iTprice < freeSpace)
		{
			dataOut.push_back(dataIn[i]);
			dataOut.back().invoice = tempInvoice;
			dataOut.back().iTprice = 0;
			freeSpace -= dataIn[i].iTprice;
		}
		else
		{
			remainNum = dataIn[i].iNum;
			while (true)
			{
				tempNum = int(ceil(freeSpace / dataIn[i].iUprice) - 1);
				if (tempNum <= remainNum)
				{
					tempIn = newInvoice(tempInvoice, dataIn[i].iName, dataIn[i].iUprice, 0, tempNum);
					dataOut.push_back(tempIn);
					if (tempNum == 0)
					{
						dataOut.pop_back();
					}
					dataOut[firstIndex].iTprice = 112999.98 - freeSpace + dataIn[i].iUprice * tempNum;
					freeSpace = 112999.98;
					remainNum -= tempNum;
					firstIndex = (int)dataOut.size();
					tempInvoice += 1;
				}
				else
				{
					if (remainNum == 0)
					{
						break;
					}
					tempIn = newInvoice(tempInvoice, dataIn[i].iName, dataIn[i].iUprice, 0, remainNum);
					dataOut.push_back(tempIn);
					freeSpace -= remainNum * dataIn[i].iUprice;
					remainNum = 0;
				}
			}
		}
	}

	dataOut[firstIndex].iTprice = 112999.98 - freeSpace;

	tempInvoice = 0;

	for (int i = 0; i < (int)dataOut.size(); i++)
	{
		if (dataOut[i].invoice == tempInvoice)
		{
			temp = "";
		}
		else
		{
			tempInvoice = dataOut[i].invoice;
			temp.Format(_T("%d"), dataOut[i].invoice);
		}
		finalList.InsertItem(i, temp);

		temp = dataOut[i].iName;
		finalList.SetItemText(i, 1, temp);

		temp.Format(_T("%f"), dataOut[i].iUprice);
		finalList.SetItemText(i, 2, temp);

		temp.Format(_T("%d"), dataOut[i].iNum);
		finalList.SetItemText(i, 3, temp);

		if (dataOut[i].iTprice == 0)
		{
			temp = "";
		}
		else
		{
			temp.Format(_T("%.02f"), dataOut[i].iTprice);
		}
		finalList.SetItemText(i, 4, temp);
	}

}


void CInvoiceDividerDlg::OnNMDblclkInput(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	showEditWindow(pNMHDR, pResult);

	*pResult = 0;
}


void CInvoiceDividerDlg::showEditWindow(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此处添加实现代码.

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	if (pNMListView->iItem != -1)
	{
		editWindow window;
		window.target = &dataIn[pNMListView->iItem];
		window.initialList = &initialList;
		window.DoModal();
	}

}


void CInvoiceDividerDlg::OnBnClickedImport()
{
	// TODO: 在此添加控件通知处理程序代码

	CString filename;

	CFileDialog importFileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Common Files (*.xls;*.xlsx;*.txt)|*.xls;*.xlsx;*.txt|"
			"Worksheet Files (*.xls;*.xlsx)|*.xls;*.xlsx|"
			"Text Files (*.txt)|*.txt|"
			"All Files (*.*)|*.*||"));

	if (importFileDlg.DoModal())
	{
		filename = importFileDlg.GetPathName();
	}

	SendMessage(WM_COMMAND, (BN_CLICKED << 16) | IDC_CLEAN);

	importFile(filename);

}


void CInvoiceDividerDlg::OnBnClickedExport()
{
	// TODO: 在此添加控件通知处理程序代码

	CString filename;
	CString folderPath;
	CTime curTime = CTime::GetCurrentTime();
	CString curDate= curTime.Format(_T("%y-%m-%d"));

	CFileDialog exportFileDlg(FALSE, _T("xlsx"), curDate + _T(".xlsx"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Common Files (*.xls;*.xlsx;*.txt)|*.xls;*.xlsx;*.txt|"
			"Worksheet Files (*.xlsx)|*.xlsx|"
			"Worksheet Files 97-2003 (*.xls;)|*.xls|"
			"Text Files (*.txt)|*.txt|"
			"All Files (*.*)|*.*||"));

	if (exportFileDlg.DoModal())
	{
		filename = exportFileDlg.GetPathName();
		folderPath = exportFileDlg.GetFolderPath();
	}
	exportFile(filename);

	if (MessageBox(_T("是否要打开文件夹？"), _T("文件已保存"), 0x00000004L | 0x00000040L) == 6)
	{
		ShellExecute(NULL, _T("open"), NULL, NULL, folderPath, SW_SHOWNORMAL);
	}

}


void CInvoiceDividerDlg::importFile(CString filename)
{
	// TODO: 在此处添加实现代码.

	if (filename.Right(4) == _T(".txt"))
	{
		CString fileInfo;
		CFile fileIn;
		fileIn.Open(filename, CFile::modeRead);
		char charInfo[10240] = { 0 };
		fileIn.Read(charInfo, sizeof(charInfo));
		int nBufferSize = MultiByteToWideChar(CP_UTF8, 0, charInfo, -1, NULL, 0); //取得所需缓存的多少
		wchar_t* pBuffer = (wchar_t*)malloc(nBufferSize * sizeof(wchar_t));//申请缓存空间
		MultiByteToWideChar(CP_UTF8, 0, charInfo, -1, pBuffer, nBufferSize * sizeof(wchar_t));//转码
		fileInfo = pBuffer;
		free(pBuffer); //释放缓存

		fileIn.Close();

		int start = fileInfo.Find(_T("\n"));
		fileInfo.Replace(_T("\r\n"), _T(","));
		fileInfo += _T(",");

		int col = 1;
		int row = 1;
		CString temp;
		CString tempUprice;

		for (int i = start; i < fileInfo.GetLength(); i++)
		{
			if ((CString)fileInfo[i] == _T(","))
			{
				if (col == 1)
				{
					//MessageBox(temp);
					temp = _T("");
					col++;
				}
				else if (col == 2)
				{
					//MessageBox(temp);
					SetDlgItemText(IDC_NAME, temp);
					temp = _T("");
					col++;
				}
				else if (col == 3)
				{
					tempUprice = temp;
					temp = _T("");
					col++;
				}
				else if (col == 4)
				{
					SetDlgItemText(IDC_NUM, temp);
					temp = _T("");
					col++;
				}
				else if (col == 5)
				{
					if (temp = _T(""))
					{
						SetDlgItemText(IDC_UPRICE, tempUprice);
					}
					else
					{
						SetDlgItemText(IDC_TPRICE, temp);
					}
					addInvoice();
					temp = _T("");
					SetDlgItemText(IDC_NAME, _T(""));
					SetDlgItemText(IDC_UPRICE, _T(""));
					SetDlgItemText(IDC_NUM, _T(""));
					SetDlgItemText(IDC_TPRICE, _T(""));
					col = 1;
					row++;
				}
			}
			else
			{
				temp += fileInfo[i];
			}
		}
	}

	else
	{

		if (filename.Right(4) == _T(".xls"))
		{
			Book* book = xlCreateBook();
			importBook(book, filename);
			book->release();
		}
		else if (filename.Right(5) == _T(".xlsx"))
		{
			Book* book = xlCreateXMLBook();
			importBook(book, filename);
			book->release();
		}
		else
		{
			MessageBox(_T("请选择正确的文件格式！"));
		}
	}

}


void CInvoiceDividerDlg::exportFile(CString filename)
{
	// TODO: 在此处添加实现代码.

	if (filename.Right(4) == _T(".txt"))
	{
		CFile fileOut;



		const int UNICODE_TXT_FLG = 0xFEFF; //UNICODE文本标示
		CString lineInfo;
		lineInfo.Format(_T("发票,项目,单价,数量,总价\r\n")); // 注意：输出的字节数与字符数并不一致



		fileOut.Open(filename, CFile::modeCreate | CFile::modeWrite);
		fileOut.Write(&UNICODE_TXT_FLG, 2);
		fileOut.Write(lineInfo, lineInfo.GetLength() * 2);
		
		


		for (size_t i = 0; i < dataOut.size(); i++)
		{
			lineInfo.Format(_T("%d,") + dataOut[i].iName + _T(",%f,%d,%.02f\r\n"), 
				dataOut[i].invoice, dataOut[i].iUprice, dataOut[i].iNum, dataOut[i].iTprice);
			fileOut.Write(lineInfo, lineInfo.GetLength() * 2);
		}

		fileOut.Close();
	}

	else
	{

		if (filename.Right(4) == _T(".xls"))
		{
			Book* book = xlCreateBook();
			exportBook(book, filename);
			book->release();
		}
		else if (filename.Right(5) == _T(".xlsx"))
		{
			Book* book = xlCreateXMLBook();
			exportBook(book, filename);
			book->release();
		}
		else
		{
			MessageBox(_T("请选择正确的文件格式！"));
		}
	}

}


void CInvoiceDividerDlg::importBook(Book* book, CString filename)
{
	// TODO: 在此处添加实现代码.

	book->setKey(L"TommoT", L"windows-2421220b07c2e10a6eb96768a2p7r6gc");

	CString temp;
	CString tempUprice;
	bool decimal = FALSE;

	if (book->load(filename))
	{
		Sheet* sheet = book->getSheet(0);
		if (sheet)
		{
			for (int row = sheet->firstRow() + 1; row < sheet->lastRow(); row++)
			{
				for (int col = sheet->firstCol() + 1; col < sheet->firstCol() + 5; col++)
				{
					CellType cellType = sheet->cellType(row, col);

					if (col == sheet->firstCol() + 1)
					{
						switch (cellType)
						{
						case CELLTYPE_EMPTY: break;
						case CELLTYPE_NUMBER:
						{
							temp.Format(_T("%f"), sheet->readNum(row, col));
							temp = removeEndZero(temp);
							SetDlgItemText(IDC_NAME, temp);
							break;
						}
						case CELLTYPE_STRING:
						{
							SetDlgItemText(IDC_NAME, sheet->readStr(row, col));
							break;
						}
						case CELLTYPE_BOOLEAN: break;
						case CELLTYPE_BLANK: break;
						case CELLTYPE_ERROR: break;
						}
					}
					else if (col == sheet->firstCol() + 2)
					{
						switch (cellType)
						{
						case CELLTYPE_EMPTY: break;
						case CELLTYPE_NUMBER:
						{
							tempUprice.Format(_T("%f"), sheet->readNum(row, col));
							tempUprice = removeEndZero(tempUprice);
							break;
						}
						case CELLTYPE_STRING:
						{
							tempUprice = sheet->readStr(row, col);
							break;
						}
						case CELLTYPE_BOOLEAN: break;
						case CELLTYPE_BLANK: break;
						case CELLTYPE_ERROR: break;
						}
					}
					else if (col == sheet->firstCol() + 3)
					{
						switch (cellType)
						{
						case CELLTYPE_EMPTY: break;
						case CELLTYPE_NUMBER:
						{
							temp.Format(_T("%f"), sheet->readNum(row, col));
							temp = removeEndZero(temp);
							SetDlgItemText(IDC_NUM, temp);
							break;
						}
						case CELLTYPE_STRING:
						{
							SetDlgItemText(IDC_NUM, sheet->readStr(row, col));
							break;
						}
						case CELLTYPE_BOOLEAN: break;
						case CELLTYPE_BLANK: break;
						case CELLTYPE_ERROR: break;
						}
					}
					else if (col == sheet->firstCol() + 4)
					{
						switch (cellType)
						{
						case CELLTYPE_EMPTY:
						{
							if (tempUprice != _T(""))
							{
								SetDlgItemText(IDC_UPRICE, tempUprice);
							}
							break;
						}
						case CELLTYPE_NUMBER:
						{
							temp.Format(_T("%f"), sheet->readNum(row, col));
							temp = removeEndZero(temp);
							SetDlgItemText(IDC_TPRICE, temp);
							break;
						}
						case CELLTYPE_STRING:
						{
							SetDlgItemText(IDC_TPRICE, sheet->readStr(row, col));
							break;
						}
						case CELLTYPE_BOOLEAN: break;
						case CELLTYPE_BLANK: break;
						case CELLTYPE_ERROR: break;
						}

						if (!addInvoice())
						{
							return;
						}
						SetDlgItemText(IDC_NAME, _T(""));
						SetDlgItemText(IDC_UPRICE, _T(""));
						SetDlgItemText(IDC_NUM, _T(""));
						SetDlgItemText(IDC_TPRICE, _T(""));
					}
				}
			}
		}
	}
	else
	{
		MessageBox((LPCTSTR)book->errorMessage(), _T(""), 0x00000010L);
	}

}


CString CInvoiceDividerDlg::removeEndZero(CString strNum)
{
	// TODO: 在此处添加实现代码.

	BOOL decimal = FALSE;

	for (int i = strNum.GetLength() - 1; i > -1; i--)
	{
		if ((CString)strNum[i] == _T("0"))
		{
			strNum.Delete(strNum.GetLength() - 1, 1);
		}
		else if ((CString)strNum[i] == _T(".") && !decimal)
		{
			decimal = TRUE;
			strNum.Delete(strNum.GetLength() - 1, 1);
		}
		else
		{
			break;
		}
	}
	return strNum;

}


void CInvoiceDividerDlg::exportBook(Book* book, CString filename)
{
	// TODO: 在此处添加实现代码.

	book->setKey(L"TommoT", L"windows-2421220b07c2e10a6eb96768a2p7r6gc");
	
	Sheet* sheet = book->addSheet(_T("Sheet") + book->sheetCount());
	sheet->setDisplayGridlines(true);

	sheet->writeStr(0, 0, _T("发票"));
	sheet->writeStr(0, 1, _T("项目"));
	sheet->writeStr(0, 2, _T("单价"));
	sheet->writeStr(0, 3, _T("数量"));
	sheet->writeStr(0, 4, _T("总价"));

	for (int row = 0; row < finalList.GetItemCount(); row++)
	{
		sheet->writeStr(row + 1, 0, finalList.GetItemText(row, 0));
		sheet->writeStr(row + 1, 1, finalList.GetItemText(row, 1));
		sheet->writeStr(row + 1, 2, finalList.GetItemText(row, 2));
		sheet->writeStr(row + 1, 3, finalList.GetItemText(row, 3));
		sheet->writeStr(row + 1, 4, finalList.GetItemText(row, 4));
	}

	book->save(filename);

}
