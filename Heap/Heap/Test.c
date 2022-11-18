#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include "HeapSort.h"
#include <time.h>

void TestHeap()
{
	HP hp;
	// 初始化
	HeapInit(&hp);

	// 插入10~1
	for (int i = 10; i >= 1; i--)
	{
		HeapPush(&hp, i);
	}
	HeapPrint(&hp);

	// 计算有效数据个数
	printf("数据个数：%d\n", HeapSize(&hp));

	// 选数
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	// 销毁
	HeapDestroy(&hp);
}

void TestHeapSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArr(a, sizeof(a) / sizeof(a[0]));
}

void TestTopK()
{
	srand((unsigned int)time(NULL));

	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("TestTopk::malloc");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}

	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	PrintTopK(a, n, 10);
}

int main()
{
	//TestHeap();
	//TestHeapSort();
	TestTopK();

	return 0;
}