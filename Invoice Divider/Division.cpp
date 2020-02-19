//Division.cpp
//Author: Jiahao Zhu
//Dividing invoice under 10,0000 total price each.

#include "pch.h"
#include "Division.h"
/*
InvoiceLST division(InvoiceLST iList)
{
	InvoiceLST fList;
	InvoiceLST tempList = iList;
	double freeSpace = 100000;
	int tempInvoice = 1;
	int tempNum = 0;
	int remainNum = 0;
	
	while (!tempList.isEmpty())
	{
		if ((*listPtr).getTprice() < freeSpace)
		{
			fList.append(tempInvoice,tempList.getName(), tempList.getUprice(), tempList.getTprice(), tempList.getNum());
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
	}
	return iList;
}

void divisionTest(InvoiceLST iList, InvoiceLST fList)
{

}*/