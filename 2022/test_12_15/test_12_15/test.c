#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void insert_sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; ++i)
	{
		// 假设[0,end]有序
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

void shell_sort(int* arr, int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

void print_arr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

#define N 10000
void test_sort1(void (*pSort)(int*, int))
{
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = -i;
	}
	pSort(arr, N);
	bool flag = true;
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		printf("测试成功\n");
	else
		printf("测试失败\n");
}

void test_sort2(void(*pSort[])(int*, int), int sz)
{
	for (int i = 0; i < sz; i++)
	{
		// 测试单个函数

		// 创建数组
		int* arr = (int*)malloc(N * sizeof(int));
		if (arr == NULL)
		{
			perror("test_sort2::malloc");
			return;
		}

		// 初始化数组
		for (int j = 0; j < N; j++)
		{
			arr[j] = -j;
		}

		// 排序
		pSort[i](arr, N);

		// 检验排序结果
		bool flag = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			printf("第%d个排序函数测试成功\n", i + 1);
		else
			printf("第%d个排序函数测试失败\n", i + 1);
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

	void (*pSort[])(int*, int) = { insert_sort, shell_sort };
	test_sort2(pSort, sizeof(pSort) / sizeof(pSort[0]));

	//test_sort1(insert_sort);
	//test_sort1(shell_sort);

	//insert_sort(arr, 10);
	//shell_sort(arr, 10);
	//print_arr(arr, 10);

	return 0;
}