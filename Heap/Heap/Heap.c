#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

static void Swap(HPDataType* p1, HPDataType* p2)
{
	assert(p1 && p2);

	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(a + child, a + parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	// 检查容量，满了要扩容
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("HeapPush::realloc");
			return;
		}

		php->a = tmp;
		php->capacity = newCapacity;
	}

	php->a[php->size++] = x;

	AdjustUp(php->a, php->size - 1);
}

void HeapPop(HP* php);
HPDataType HeapTop(const HP* php);
bool HeapEmpty(const HP* php);
int HeapSize(const HP* php);