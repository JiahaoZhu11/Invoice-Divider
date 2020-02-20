// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include "noNameWarning.h"
#include "noPriceWarning.h"
#include "noNumWarning.h"
#include "duoPriceWarning.h"
#include "invalidPriceWarning.h"
#include "invalidNumWarning.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

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


// type of warning: 1 = no name, 2 = no price, 3 = no number, 4 = invalid price, 5 = invalid number, 6 = duo price
void warning(int type)
{
	// TODO: 在此处添加实现代码.

	if (type == 1)
	{
		noNameWarning nNa;
		nNa.DoModal();
	}

	if (type == 2)
	{
		noPriceWarning nPr;
		nPr.DoModal();
	}

	if (type == 3)
	{
		noNumWarning nNu;
		nNu.DoModal();
	}

	if (type == 4)
	{
		invalidPriceWarning iPr;
		iPr.DoModal();
	}

	if (type == 5)
	{
		invalidPriceWarning iPr;
		iPr.DoModal();
	}

	if (type == 6)
	{
		invalidNumWarning iNu;
		iNu.DoModal();
	}

	if (type == 7)
	{
		duoPriceWarning dPr;
		dPr.DoModal();
	}

}
