#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void TestSort(void(*pSort)(int*, int))
{
	const int n = 1000000;
	int* a = calloc(n, sizeof(int));
	if (a == NULL)
	{
		perror("TestSort::calloc");
		return;
	}
	int* tmp = calloc(n, sizeof(int));
	if (tmp == NULL)
	{
		perror("TestSort::calloc");
		return;
	}

	// 初始化待排序数组
	for (int i = 0; i < n; i++)
	{
		tmp[i] = a[i] = rand();
	}

	// 排序tmp用于检验
	qsort(tmp, n, sizeof(tmp[0]), CmpByInt);

	clock_t begin = clock();
	pSort(a, n);
	clock_t end = clock();

	// 检验是否排序成功
	if (memcmp(a, tmp, n * sizeof(int)) == 0)
		printf("排序成功，");
	else
		printf("排序失败，");

	printf("耗时：%ld毫秒\n", end - begin);

	free(a);
	a = NULL;
}

void TestAll()
{
	void(*pSort[])(int*, int) = { InsertSort, ShellSort, HeapSort, SelectSort, BubbleSort, QuickSort, QuickSortNonR };
	char* sortFunName[] = { "InsertSort", "ShellSort", "HeapSort", "SelectSort", "BubbleSort", "QuickSort", "QuickSortNonR" };
	int sz = sizeof(pSort) / sizeof(pSort[0]);
	const int n = 100000;
	int* a = calloc(n, sizeof(int));
	if (a == NULL)
	{
		perror("TestAll::calloc");
		return;
	}
	int* copy = calloc(n, sizeof(int));
	if (copy == NULL)
	{
		perror("TestAll::calloc");
		return;
	}
	int* tmp = calloc(n, sizeof(int));
	if (tmp == NULL)
	{
		perror("TestAll::calloc");
		return;
	}

	// 初始化待排序数组
	for (int i = 0; i < n; i++)
	{
		tmp[i] = a[i] = rand();
	}

	// 排序tmp用于检验
	qsort(tmp, n, sizeof(tmp[0]), CmpByInt);

	for (int i = 0; i < sz; i++)
	{
		memmove(copy, a, n * sizeof(int));
		clock_t begin = clock();
		pSort[i](copy, n);
		clock_t end = clock();

		// 检验是否排序成功
		if (memcmp(copy, tmp, n * sizeof(int)) == 0)
			printf("pSort[%d]: %-20s排序成功", i, sortFunName[i]);
		else
			printf("pSort[%d]: %-20s排序失败", i, sortFunName[i]);

		printf("，耗时%-6d毫秒\n", end - begin);
	}

	free(a);
	a = NULL;
	free(copy);
	copy = NULL;
	free(tmp);
	tmp = NULL;
}

int main()
{
	srand((unsigned int)time(NULL));

	//TestSort(QuickSortNonR);
	TestAll();

	return 0;
}