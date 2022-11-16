#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

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

int main()
{
	TestHeap();

	return 0;
}