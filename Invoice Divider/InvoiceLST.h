//InvoiceLST.h
//Author: Jiahao Zhu
//List of invoice header file

#pragma once
class InvoiceLST
{
public:
	InvoiceLST();
	InvoiceLST(const InvoiceLST &source);
	~InvoiceLST();
	BOOL isEmpty();
	int getInvoice();
	CString getName();
	double getUprice();
	double getTprice();
	int getNum();
	void removeFirst();
	void append(int invoice, CString iName, double iUprice, double iTprice, int iNum);
	void remove(int invoice);

	CString test();

private:
	void clear();
	void copy(const InvoiceLST &source);

	struct Invoice
	{
		int invoice;
		CString iName;
		double iUprice;
		double iTprice;
		int iNum;
		Invoice* next;
	};

	Invoice* first;
};

void divisionTest(InvoiceLST iList, InvoiceLST fList);

InvoiceLST division(InvoiceLST iList);