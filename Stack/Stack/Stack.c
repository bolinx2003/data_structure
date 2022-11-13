#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->top = ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	// 检查容量
	if (ps->top == ps->capacity)
	{
		// 满了
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("StackPush::realloc");
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	// 插入
	ps->a[ps->top++] = x;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

STDataType StackTop(const ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

bool StackEmpty(const ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

int StackSize(const ST* ps)
{
	assert(ps);

	return ps->top;
}