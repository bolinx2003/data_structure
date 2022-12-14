#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void insert_sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		// [0, end]有序
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
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

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	insert_sort(arr, 9);
	for (size_t i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}