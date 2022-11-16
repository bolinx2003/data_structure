#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(const HP* php);
bool HeapEmpty(const HP* php);
int HeapSize(const HP* php);
