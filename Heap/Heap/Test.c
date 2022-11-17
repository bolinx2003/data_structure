#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include "HeapSort.h"

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

int main()
{
	TestHeapSort();

	return 0;
}