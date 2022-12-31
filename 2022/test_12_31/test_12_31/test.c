#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

void PrintArr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

bool IsAscend(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool IsDescend(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

void InsertSort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		// [0, end]有序，把arr[end+1]插入
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

void ShellSort(int arr[], int sz)
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
				if (arr[end] > tmp)
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

int main()
{
	int arr[1000] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		arr[i] = sz - i;
	}
	printf("排序前：");
	if (IsDescend(arr, sz))
	{
		printf("降序\n");
	}

	//InsertSort(arr, sz);
	ShellSort(arr, sz);
	printf("排序后：");
	if (IsAscend(arr, sz))
	{
		printf("升序\n");
	}

	return 0;
}