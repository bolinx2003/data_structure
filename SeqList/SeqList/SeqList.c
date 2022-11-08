#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

static void SLCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size == ps->capacity)
	{
		// 满了，要扩容
		// 一开始给4个，后面每次扩2倍
		int newCapacity = ps->size == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("SLCheckCapacity::realloc");
			return;
		}
		// 扩容成功
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	// 检查容量
	SLCheckCapacity(ps);

	// 插入
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	// 检查容量
	SLCheckCapacity(ps);

	// 挪动数据
	memmove(ps->a + 1, ps->a, ps->size * sizeof(SLDataType));
	// 手动挪动
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}

	// 插入
	ps->a[0] = x;
	ps->size++;
}

void SLPrint(const SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}