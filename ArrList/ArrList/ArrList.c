#define _CRT_SECURE_NO_WARNINGS 1

#include "ArrList.h"

void ArrListInit(AL* pa)
{
	assert(pa);

	memset(pa->a, 0, N * sizeof(ArrListDataType));
	pa->size = 0;
}

void ArrListPushBack(AL* pa, ArrListDataType x)
{
	assert(pa);
	assert(pa->size < N);

	pa->a[pa->size++] = x;
}

void ArrListPushFront(AL* pa, ArrListDataType x)
{
	assert(pa);
	assert(pa->size < N);

	memmove(pa->a + 1, pa->a, pa->size * sizeof(ArrListDataType));
	pa->a[0] = x;
	pa->size++;
}

void ArrListPopBack(AL* pa)
{
	assert(pa);
	assert(pa->size > 0);

	pa->size--;
}

void ArrListPopFront(AL* pa)
{
	assert(pa);
	assert(pa->size > 0);

	memmove(pa->a, pa->a + 1, (--(pa->size)) * sizeof(ArrListDataType));
}

void ArrListInsert(AL* pa, int pos, ArrListDataType x)
{
	assert(pa);
	assert(pos >= 0 && pos <= pa->size);

	memmove(pa->a + pos + 1, pa->a + pos, (pa->size - pos) * sizeof(ArrListDataType));
	pa->a[pos] = x;
	pa->size++;
}

void ArrListErase(AL* pa, int pos)
{
	assert(pa);
	assert(pos >= 0 && pos < pa->size);

	memmove(pa->a + pos, pa->a + pos + 1, ((--pa->size) - pos) * sizeof(ArrListDataType));
}

int ArrListFind(const AL* pa, ArrListDataType x)
{
	assert(pa);

	for (int i = 0; i < N; i++)
	{
		if (pa->a[i] == x)
			return i;
	}

	return -1;
}

void ArrListModify(AL* pa, int pos, ArrListDataType x)
{
	assert(pa);
	assert(pos >= 0 && pos < pa->size);

	pa->a[pos] = x;
}

void ArrListPrint(const AL* pa)
{
	assert(pa);

	for (int i = 0; i < pa->size; i++)
	{
		printf("%d ", pa->a[i]);
	}
	printf("\n");
}