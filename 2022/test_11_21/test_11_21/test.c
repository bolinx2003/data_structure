#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void AdjustDown(int* a, int sz, int parent)
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		if (child + 1 < sz && a[child + 1] > a[child])
			child++;

		if (a[child] > a[parent])
		{
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int sz)
{
	// 向下建堆
	int i = 0;
	for (i = (sz - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, sz, i);
	}

	int end = sz - 1;
	while (end > 0)
	{
		int tmp = a[0];
		a[0] = a[end];
		a[end] = tmp;

		AdjustDown(a, end--, 0);
	}
}

void PrintArr(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	PrintArr(arr, sz);

	return 0;
}