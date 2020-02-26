// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

//新建项目
Invoice newInvoice(int invoice, CString iName, double iUprice, double iTprice, int iNum)
{
	Invoice i;
	i.invoice = invoice;
	i.iName = iName;
	i.iUprice = iUprice;
	i.iTprice = iTprice;
	i.iNum = iNum;
	return i;
}
