#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SLInit(&sl);
	// 尾插1~100
	for (int i = 1; i <= 100; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);
}

void TestSeqList2()
{
	SL sl;
	SLInit(&sl);
	// 头插1~100
	for (int i = 1; i <= 100; i++)
	{
		SLPushFront(&sl, i);
	}
	SLPrint(&sl);
}

int main()
{
	TestSeqList2();

	return 0;
}