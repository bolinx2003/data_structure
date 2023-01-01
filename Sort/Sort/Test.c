#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void TestSort(void(*pSort)(int*, int))
{
	const int n = 100000;
	int* a = calloc(n, sizeof(int));
	if (a == NULL)
	{
		perror("TestSort::calloc");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = n - i;
	}

	pSort(a, n);

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
		printf("排序成功\n");
	else
		printf("排序失败\n");

	free(a);
	a = NULL;
}

void TestAll()
{
	srand((unsigned int)time(NULL));

	void(*pSort[])(int*, int) = { InsertSort, ShellSort, HeapSort, SelectSort, BubbleSort };
	char* sortFunName[] = { "InsertSort", "ShellSort", "HeapSort", "SelectSort", "BubbleSort" };
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
		int begin = clock();
		pSort[i](copy, n);
		int end = clock();

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
	//void(*pSort[])(int*, int) = { InsertSort, ShellSort, HeapSort, SelectSort, BubbleSort };
	//for (int i = 0; i < sizeof(pSort) / sizeof(pSort[0]); i++)
	//{
	//	TestSort(pSort[i]);
	//}
	TestAll();

	return 0;
}