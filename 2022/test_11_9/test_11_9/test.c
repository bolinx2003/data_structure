#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 删除所有指定元素
//int removeElement(int* nums, int numsSize, int val)
//{
//	int src = 0, dst = 0;
//	while (src < numsSize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dst++] = nums[src++];
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return dst;
//}
//
//int main()
//{
//	int arr[] = { 11,1,2,3,11,4,11,11,5,6,7,11,8,9,10,11,11,11 };
//	int ret = removeElement(arr, sizeof(arr) / sizeof(arr[0]), 11);
//	for (size_t i = 0; i < ret; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

// 去重算法
//int removeDuplicates(int* nums, int numsSize)
//{
//	int src = 1; // 遍历数组
//	int dst = 0; // 记录可以放数据的位置
//
//	while (src < numsSize)
//	{
//		if (nums[src] == nums[dst])
//		{
//			src++;
//		}
//		else
//		{
//			nums[++dst] = nums[src++];
//		}
//	}
//	return dst + 1;
//}
//
//int main()
//{
//	int arr[] = { 0,0,0,1,1,1,1,1,2,2,3,4,4,4,4,4,5,5,6,6,6,6,6,6,7,7,7,7,8,8,9,10,10,10,10,10,11,11,11,12,13,14,15,15,15 };
//	int ret = removeDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
//	for (size_t i = 0; i < ret; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

// 合并有序数组
// 这题在LeetCode上，默认nums1Size=m+n，nums2Size=n
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = nums1Size - 1;
//
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}
//
//int main()
//{
//	int arr1[] = { 1,2,5,0,0,0,0,0,0,0 };
//	int arr2[] = { -3,-2,-1,1,3,4,6 };
//	merge(arr1, sizeof(arr1) / sizeof(arr1[0]), 3, arr2, sizeof(arr2) / sizeof(arr2[0]), 7);
//	for (size_t i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//	return 0;
//}