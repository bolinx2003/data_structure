#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

static void Swap(int* pa, int* pb)
{
	assert(pa && pb);

	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		// [0,end]有序，插入end+1位置的数据
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

// 升序建大堆
static void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出较大的子节点
		if (child + 1 < n && a[child + 1] > a[child])
			child++;

		if (a[child] > a[parent])
		{
			Swap(a + parent, a + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	// 向下建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	// 把堆顶的数换到后面
	int end = n - 1;
	while (end > 0)
	{
		Swap(a, a + end);
		AdjustDown(a, end--, 0);
	}
}