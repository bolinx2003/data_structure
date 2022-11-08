#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a; // 指向动态开辟的数组
	int size;      // 有效数据的个数
	int capacity;  // 容量
}SL;

// 初始化
void SLInit(SL* ps);

// 尾插
void SLPushBack(SL* ps, SLDataType x);

// 头插
void SLPushFront(SL* ps, SLDataType x);

// 打印
void SLPrint(const SL* ps);