#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestSList1()
{
	// 直接手搓单链表
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n2);
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n3);
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n4);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	SLTNode* plist = n1;
	SListPrint(plist);

	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPrint(plist);

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList2()
{
	SLTNode* plist = NULL;

	// 尾插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushBack(&plist, i);
	}
	SListPrint(plist);

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList3()
{
	SLTNode* plist = NULL;

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushFront(&plist, i);
	}
	SListPrint(plist);

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList4()
{
	SLTNode* plist = NULL;

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushFront(&plist, i);
	}
	SListPrint(plist);

	// 头删3次
	for (size_t i = 0; i < 3; i++)
	{
		SListPopFront(&plist);
	}
	SListPrint(plist);

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList5()
{
	SLTNode* plist = NULL;

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushFront(&plist, i);
	}
	SListPrint(plist);

	// 尾删3次
	for (size_t i = 0; i < 3; i++)
	{
		SListPopBack(&plist);
	}
	SListPrint(plist);

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList6()
{
	SLTNode* plist = NULL;

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushFront(&plist, i);
	}
	SListPrint(plist);

	// 尾删
	for (size_t i = 0; i < 10; i++)
	{
		SListPopBack(&plist);
		SListPrint(plist);
	}

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList7()
{
	SLTNode* plist = NULL;

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushFront(&plist, i);
	}
	SListPrint(plist);

	// 头删
	for (size_t i = 0; i < 10; i++)
	{
		SListPopFront(&plist);
		SListPrint(plist);
	}

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

void TestSList8()
{
	SLTNode* plist = NULL;

	// 头插1~10
	for (int i = 1; i <= 10; i++)
	{
		SListPushFront(&plist, i);
	}
	SListPrint(plist);

	// 把3改成3000
	SLTNode* ret = SListFind(plist, 3);
	if (ret)
	{
		ret->data = 3000;
		SListPrint(plist);
	}
	else
	{
		printf("找不到\n");
	}

	// 销毁
	SListDestroy(plist);
	plist = NULL;
}

int main()
{
	TestSList8();

	return 0;
}