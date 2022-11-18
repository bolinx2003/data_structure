#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include "HeapSort.h"

void HeapSort(int* a, int n)
{
	assert(a);

	// 建堆
	// 1、向上调整
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}
	// 2、向下调整
	// 最后一个非叶子结点，即最后一个叶子结点的父亲
	// n-1的父亲：(n-1-1)/2
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		// 交换第一个数和最后一个数
		Swap(a, a + end);

		// 向下调整
		AdjustDown(a, end--, 0);
	}
}

// 直接使用堆实现
//void HeapSort(int* a, int n)
//{
//	assert(a);
//
//	HP hp;
//	// 初始化
//	HeapInit(&hp);
//
//	// 把数组元素插入堆
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	// 把堆顶元素重新放入数组
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//
//	// 销毁
//	HeapDestroy(&hp);
//}

// k个数建堆
void PrintTopK(int* a, int n, int k)
{
	assert(a);

	// 前k个数建堆
	int* kMinHeap = (int*)malloc(sizeof(int) * k);
	if (kMinHeap == NULL)
	{
		perror("PrintTopK::malloc");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		kMinHeap[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kMinHeap, k, i);
	}

	// 将剩余的数和堆顶的数比较
	for (int i = k; i < n; i++)
	{
		if (a[i] > kMinHeap[0])
		{
			kMinHeap[0] = a[i];
			AdjustDown(kMinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", kMinHeap[i]);
	}
	printf("\n");

	free(kMinHeap);
	kMinHeap = NULL;
}

// 先取top再pop
//void PrintTopK(int* a, int n, int k)
//{
//	assert(a);
//
//	// 向下建堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	int end = n - 1;
//	while (k--)
//	{
//		// 打印堆顶数据
//		printf("%d ", a[0]);
//
//		// pop掉堆顶数据
//		Swap(a, a + end);
//		AdjustDown(a, end--, 0);
//	}
//}

// 使用堆排序
//void PrintTopK(int* a, int n, int k)
//{
//	assert(a);
//
//	HeapSort(a, n);
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}

void PrintArr(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}