#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void InsertSort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] < tmp)
			{
				break;
			}
			else
			{
				arr[end + 1] = arr[end];
				--end;
			}
		}
		arr[end + 1] = tmp;
	}
}

void PrintArr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArr(arr, sz);

	return 0;
}