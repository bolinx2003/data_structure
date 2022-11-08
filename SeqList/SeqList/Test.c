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
	SLDestroy(&sl);
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
	SLDestroy(&sl);
}

void TestSeqList3()
{
	SL sl;
	SLInit(&sl);
	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushFront(&sl, i);
	}
	SLPrint(&sl);

	// 尾删3次
	for (int i = 0; i < 3; i++)
	{
		SLPopBack(&sl);
		SLPrint(&sl);
	}

	SLDestroy(&sl);
}

void TestSeqList4()
{
	SL sl;
	SLInit(&sl);
	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushFront(&sl, i);
	}
	SLPrint(&sl);

	// 头删3次
	for (int i = 0; i < 3; i++)
	{
		SLPopFront(&sl);
		SLPrint(&sl);
	}

	SLDestroy(&sl);
}

void TestSeqList5()
{
	SL sl;
	SLInit(&sl);
	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);

	// 在6前面插入6000
	SLInsert(&sl, 5, 6000);
	SLPrint(&sl);

	SLDestroy(&sl);
}

void TestSeqList6()
{
	SL sl;
	SLInit(&sl);
	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);

	SLErase(&sl, 9);
	SLPrint(&sl);
	SLErase(&sl, 0);
	SLPrint(&sl);
	SLErase(&sl, 5);
	SLPrint(&sl);

	SLDestroy(&sl);
}

void TestSeqList7()
{
	SL sl;
	SLInit(&sl);
	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);

	int pos = SLFind(&sl, 7);
	printf("pos = %d\n", pos);

	pos = SLFind(&sl, 11);
	printf("pos = %d\n", pos);

	SLDestroy(&sl);
}

void TestSeqList8()
{
	SL sl;
	SLInit(&sl);
	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);

	// 把7改成7000
	int pos = SLFind(&sl, 7);
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		SLModify(&sl, pos, 7000);
	}
	SLPrint(&sl);

	SLDestroy(&sl);
}

void TestSeqList9()
{
	SL sl;
	SLInit(&sl);

	for (int i = 0; i < 3; i++)
	{
		// 头插1~10
		for (int j = 1; j <= 10; j++)
		{
			SLPushFront(&sl, j);
		}
		SLPrint(&sl);
		// 尾删10次
		for (int j = 0; j < 10; j++)
		{
			SLPopBack(&sl);
		}
		// 尾插1~10
		for (int j = 1; j <= 10; j++)
		{
			SLPushBack(&sl, j);
		}
		SLPrint(&sl);
		// 头删10次
		for (int j = 0; j < 10; j++)
		{
			SLPopFront(&sl);
		}
	}

	SLDestroy(&sl);
}

void TestSeqList10()
{
	SL sl;
	SLInit(&sl);

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);

	// 删除
	int del = 0;
	printf("请输入你要删除的数据:>");
	scanf("%d", &del);
	int pos = SLFind(&sl, del);
	if (pos == -1)
	{
		printf("没找到%d\n", del);
	}
	else
	{
		SLErase(&sl, pos);
		SLPrint(&sl);
	}

	// 修改
	int mdf = 0;
	printf("请输入你要修改的数:>");
	scanf("%d", &mdf);
	pos = SLFind(&sl, mdf);
	if (mdf == -1)
	{
		printf("没找到%d\n", mdf);
	}
	else
	{
		printf("请输入修改后的数:>");
		scanf("%d", &mdf);
		SLModify(&sl, pos, mdf);
		SLPrint(&sl);
	}

	SLDestroy(&sl);
}

int main()
{
	TestSeqList10();

	return 0;
}