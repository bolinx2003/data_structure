#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef int ArrListDataType;
#define N 100

typedef struct ArrList
{
	ArrListDataType a[N];
	int size;
}AL;

void ArrListInit(AL* pa);
void ArrListPushBack(AL* pa, ArrListDataType x);
void ArrListPushFront(AL* pa, ArrListDataType x);
void ArrListPopBack(AL* pa);
void ArrListPopFront(AL* pa);
void ArrListInsert(AL* pa, int pos, ArrListDataType x);
void ArrListErase(AL* pa, int pos);
int ArrListFind(const AL* pa, ArrListDataType x);
void ArrListModify(AL* pa, int pos, ArrListDataType x);
void ArrListPrint(const AL* pa);