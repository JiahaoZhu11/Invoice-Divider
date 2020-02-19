//InvoiceLST.cpp
//Author: Jiahao Zhu
//List of invoice

#include "pch.h"
#include "InvoiceLST.h"

InvoiceLST::InvoiceLST() : first(0) { }

InvoiceLST::InvoiceLST(const InvoiceLST& source)
{
	this->copy(source);
}

InvoiceLST::~InvoiceLST()
{
	this->clear();
}

BOOL InvoiceLST::isEmpty()
{
	if (first == 0)
	{
		return TRUE;
	}
	return FALSE;
}

int InvoiceLST::getInvoice()
{
	return first->invoice;
}

CString InvoiceLST::getName()
{
	return first->iName;
}

double InvoiceLST::getUprice()
{
	return first->iUprice;
}

double InvoiceLST::getTprice()
{
	return first->iTprice;
}

int InvoiceLST::getNum()
{
	return first->iNum;
}

void InvoiceLST::removeFirst()
{
	this->remove(this->getInvoice());
}

void InvoiceLST::append(int invoice, CString name, double uprice, double tprice, int num)
{
	if (first == 0)
	{
		first = new Invoice;
		first->invoice = invoice;
		first->iName = name;
		first->iUprice = uprice;
		first->iTprice = tprice;
		first->iNum = num;
		first->next = 0;
	}
	else
	{
		Invoice* i = first;
		while (i->next)
		{
			i = i->next;
		}
		i->next = new Invoice;
		i->next->invoice = invoice;
		i->next->iName = name;
		i->next->iUprice = uprice;
		i->next->iTprice = tprice;
		i->next->iNum = num;
		i->next->next = 0;
	}
}

void InvoiceLST::remove(int invoice)
{
	if (first == 0)
	{
		return;
	}
	Invoice* i = first;
	if (i->invoice == invoice)
	{
		first = i->next;
		free(i);
	}
	else
	{
		while (i->next)
		{
			if (i->next->invoice == invoice)
			{
				i->next = i->next->next;
				i->next->next = 0;
				free(i->next);
				break;
			}
		}
	}
}

CString InvoiceLST::test()
{
	CString nameString;
	Invoice* i = first;
	while (i)
	{
		nameString += i->iName;
		i = i->next;
	}
	return nameString;
}

void InvoiceLST::clear()
{
	Invoice* i = first;
	while (i)
	{
		Invoice* next = i->next;
		delete i;
		i = next;
	}
	first = 0;
}

void InvoiceLST::copy(const InvoiceLST &source)
{
	first = 0;
	Invoice* i = source.first;
	while (i)
	{
		this->append(i->invoice, i->iName, i->iUprice, i->iTprice, i->iNum);
		i = i->next;
	}
}

void divisionTest(InvoiceLST iList, InvoiceLST fList)
{

}

InvoiceLST division(InvoiceLST newList)
{
	InvoiceLST fList;
	InvoiceLST tempaList = newList;
	double freeSpace = 100000;
	int tempInvoice = 1;
	int tempNum = 0;
	int remainNum = 0;

	/*while (!tempList.isEmpty())
	{
		if ((*listPtr).getTprice() < freeSpace)
		{
			fList.append(tempInvoice, tempList.getName(), tempList.getUprice(), tempList.getTprice(), tempList.getNum());
			freeSpace -= tempList.getTprice();
			tempList.removeFirst();
			tempInvoice += 1;
		}
		else
		{
			remainNum = (*listPtr).getNum();
			while (true)
			{
				tempNum = freeSpace / (*listPtr).getUprice();
				if (tempNum <= remainNum)
				{
					fList.append(tempInvoice, (*listPtr).getName(), (*listPtr).getUprice(), tempNum * (*listPtr).getUprice(), tempNum);
					freeSpace = 100000;
					remainNum -= tempNum;
					tempNum = freeSpace / (*listPtr).getUprice();
					tempInvoice += 1;
				}
				else
				{
					if (remainNum != 0)
					{
						fList.append(tempInvoice, (*listPtr).getName(), (*listPtr).getUprice(), remainNum * (*listPtr).getUprice(), remainNum);
						freeSpace -= remainNum * (*listPtr).getUprice();
					}
					(*listPtr).getNext(listPtr);
				}
			}

		}
	}*/
	return newList;
}