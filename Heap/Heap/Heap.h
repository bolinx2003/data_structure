#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

// 堆

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a; // 指向数组的指针
	int size;      // 有效元素个数
	int capacity;  // 容量
}HP;

// 打印
void HeapPrint(const HP* php);

// 初始化
void HeapInit(HP* php);

// 销毁
void HeapDestroy(HP* php);

// 向上调整
void AdjustUp(HPDataType* a, int child);

// 向下调整
void AdjustDown(HPDataType* a, int size, int parent);

// 交换
void Swap(HPDataType* p1, HPDataType* p2);

// 插入数据
void HeapPush(HP* php, HPDataType x);

// 删除堆顶数据
void HeapPop(HP* php);

// 取堆顶数据
HPDataType HeapTop(const HP* php);

// 判空
bool HeapEmpty(const HP* php);

// 计算堆的元素个数
int HeapSize(const HP* php);