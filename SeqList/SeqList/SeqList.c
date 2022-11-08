#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}
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

	SLInsert(ps, ps->size, x);

	// 单独实现
	/*
	// 检查容量
	SLCheckCapacity(ps);

	// 插入
	ps->a[ps->size] = x;
	ps->size++;
	*/
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLInsert(ps, 0, x);

	// 单独实现
	/*
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
	*/
}

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	SLErase(ps, ps->size - 1);

	// 单独实现
	//ps->size--;
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	SLErase(ps, 0);

	// 单独实现
	/*
	// 挪动数据
	memmove(ps->a, ps->a + 1, (ps->size - 1) * sizeof(SLDataType));
	// 手动挪
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}

	ps->size--;
	*/
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	// 检查容量
	SLCheckCapacity(ps);

	// 挪动数据
	memmove(ps->a + pos + 1, ps->a + pos, (ps->size - pos) * sizeof(SLDataType));
	// 手动挪
	//int end = ps->size - 1;
	//while (end >= pos)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}

	// 插入
	ps->a[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size); // 间接判断了ps->size>0

	// 挪动数据
	memmove(ps->a + pos, ps->a + pos + 1, (ps->size - pos - 1) * sizeof(SLDataType));
	// 手动挪
	//int begin = pos + 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}

	ps->size--;
}

int SLFind(const SL* ps, SLDataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;
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