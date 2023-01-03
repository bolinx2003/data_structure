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
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	clock_t begin = clock();
	pSort(a, n);
	clock_t end = clock();

	// 检验是否排序成功
	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		printf("排序成功，");
	else
		printf("排序失败，");

	printf("耗时：%ld毫秒\n", end - begin);

	free(a);
	a = NULL;
}

void TestAll()
{
	void(*pSort[])(int*, int) = { InsertSort, ShellSort, HeapSort, SelectSort, BubbleSort, QuickSort };
	char* sortFunName[] = { "InsertSort", "ShellSort", "HeapSort", "SelectSort", "BubbleSort", "QuickSort" };
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

	// 初始化待排序数组
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	for (int i = 0; i < sz; i++)
	{
		memmove(copy, a, n * sizeof(int));
		clock_t begin = clock();
		pSort[i](copy, n);
		clock_t end = clock();

		// 检验是否排序成功
		bool flag = true;
		for (int j = 0; j < n - 1; j++)
		{
			if (copy[j] > copy[j + 1])
			{
				flag = false;
				printf("pSort[%d]: %-20s排序失败", i, sortFunName[i]);
				break;
			}
		}
		if (flag)
			printf("pSort[%d]: %-20s排序成功", i, sortFunName[i]);

		printf("，耗时%-6d毫秒\n", end - begin);
	}

	free(a);
	a = NULL;
	free(copy);
	copy = NULL;
}

int main()
{
	srand((unsigned int)time(NULL));

	TestSort(QuickSort);
	//TestAll();

	return 0;
}