#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// 打印数组
void PrintArr(int* a, int n);

// 直接插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 堆排序
void HeapSort(int* a, int n);