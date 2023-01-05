#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "Stack.h"

// 比较函数
int CmpByInt(const void* e1, const void* e2);

// 打印数组
void PrintArr(int* a, int n);

// 直接插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 堆排序
void HeapSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序
//
// 递归
void QuickSort(int* a, int n);
//
// 非递归
void QuickSortNonR(int* a, int n);

// 归并排序
//
// 递归
void MergeSort(int* a, int n);
//
// 非递归
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);