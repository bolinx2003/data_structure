#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{
	// 初始化方式一
	//LTNode* plist = NULL;
	//ListInit(&plist);

	// 初始化方式二
	LTNode* plist = ListInit();

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		ListPushBack(plist, i);
	}

	// 打印
	ListPrint(plist);

	// 销毁
	ListDestroy(plist);
	plist = NULL;
}

void TestList2()
{
	// 初始化方式一
	//LTNode* plist = NULL;
	//ListInit(&plist);

	// 初始化方式二
	LTNode* plist = ListInit();

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		ListPushFront(plist, i);
	}

	// 打印
	ListPrint(plist);

	// 销毁
	ListDestroy(plist);
	plist = NULL;
}

void TestList3()
{
	// 初始化方式一
	//LTNode* plist = NULL;
	//ListInit(&plist);

	// 初始化方式二
	LTNode* plist = ListInit();

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		ListPushBack(plist, i);
	}
	// 打印
	ListPrint(plist);

	// 尾删
	while (!ListEmpty(plist))
	{
		ListPopBack(plist);
		ListPrint(plist);
	}

	// 销毁
	ListDestroy(plist);
	plist = NULL;
}

void TestList4()
{
	// 初始化方式一
	//LTNode* plist = NULL;
	//ListInit(&plist);

	// 初始化方式二
	LTNode* plist = ListInit();

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		ListPushBack(plist, i);
	}
	// 打印
	ListPrint(plist);

	// 头删
	while (!ListEmpty(plist))
	{
		ListPopFront(plist);
		ListPrint(plist);
	}

	// 销毁
	ListDestroy(plist);
	plist = NULL;
}

void TestList5()
{
	// 初始化方式一
	//LTNode* plist = NULL;
	//ListInit(&plist);

	// 初始化方式二
	LTNode* plist = ListInit();

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		ListPushBack(plist, i);
	}
	// 打印
	ListPrint(plist);

	int size = ListSize(plist);
	printf("size = %d\n", size);

	// 销毁
	ListDestroy(plist);
	plist = NULL;
}

void TestList6()
{
	// 初始化方式一
	//LTNode* plist = NULL;
	//ListInit(&plist);

	// 初始化方式二
	LTNode* plist = ListInit();

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		ListPushBack(plist, i);
	}
	// 打印
	ListPrint(plist);

	// 删除6
	LTNode* pos = ListFind(plist, 6);
	if (pos == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		ListErase(pos);
		ListPrint(plist);
	}

	// 销毁
	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	TestList6();

	return 0;
}