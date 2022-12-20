#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void insert_sort(int* arr, int sz)
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

int main()
{
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = 100 - i;
	}

	insert_sort(arr, 100);

	for (size_t i = 0; i < 100; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}