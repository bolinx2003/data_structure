#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapPrint(const HP* php)
{
	assert(php);

	int k = 1;     // 层数
	int count = 0; // 已经打印的数据个数
	// 当 count = 2^k - 1 时换行
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		if (++count == (int)pow(2, k) - 1)
		{
			printf("\n");
			k++;
		}
	}
	printf("\n");
}

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

void Swap(HPDataType* p1, HPDataType* p2)
{
	assert(p1 && p2);

	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent]) // 小于--小堆，大于--大堆
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

	// 向上调整
	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	assert(a);

	// 左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		// 如果有右孩子，则取两个孩子中较小的
		if (child + 1 < size
			&& a[child + 1] < a[child]) // 小于--小堆，大于--大堆
		{
			child++;
		}

		if (a[child] < a[parent]) // 小于--小堆，大于--大堆
		{
			Swap(a + child, a + parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	// 交换第一个数据和最后一个数据
	Swap(php->a, php->a + php->size - 1);

	// 删除最后一个数据
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(const HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool HeapEmpty(const HP* php)
{
	assert(php);

	return php->size == 0;
}

int HeapSize(const HP* php)
{
	assert(php);

	return php->size;
}