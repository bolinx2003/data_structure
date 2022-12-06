#define _CRT_SECURE_NO_WARNINGS 1

#include "ArrList.h"

void TestArrList1()
{
	AL al;
	ArrListInit(&al);

	for (int i = 1; i <= 10; i++)
	{
		ArrListPushBack(&al, i);
	}
	ArrListPrint(&al);

	for (size_t i = 0; i < 5; i++)
	{
		ArrListPopBack(&al);
		ArrListPrint(&al);
	}
}

void TestArrList2()
{
	AL al;
	ArrListInit(&al);

	for (int i = 1; i <= 10; i++)
	{
		ArrListPushFront(&al, i);
	}
	ArrListPrint(&al);

	for (size_t i = 0; i < 5; i++)
	{
		ArrListPopFront(&al);
		ArrListPrint(&al);
	}
}

void TestArrList3()
{
	AL al;
	ArrListInit(&al);

	for (int i = 1; i <= 10; i++)
	{
		ArrListPushBack(&al, i);
	}
	ArrListPrint(&al);

	// 在3前插入300
	ArrListInsert(&al, 2, 300);
	ArrListPrint(&al);

	// 删掉300
	ArrListErase(&al, 2);
	ArrListPrint(&al);
}

void TestArrList4()
{
	AL al;
	ArrListInit(&al);

	for (int i = 1; i <= 10; i++)
	{
		ArrListPushBack(&al, i);
	}
	ArrListPrint(&al);

	// 把3改成300
	int pos = ArrListFind(&al, 3);
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		ArrListModify(&al, pos, 300);
		ArrListPrint(&al);
	}
}

int main()
{
	TestArrList4();

	return 0;
}