#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void TestStack()
{
	ST st;
	// 初始化
	StackInit(&st);

	for (size_t i = 0; i < 5; i++)
	{
		// 入栈1~10
		for (int i = 1; i <= 10; i++)
		{
			StackPush(&st, i);
		}

		// 统计栈元素个数
		printf("栈元素个数：%d\n", StackSize(&st));

		// 出栈，同时打印栈顶元素
		while (!StackEmpty(&st))
		{
			printf("%d ", StackTop(&st));
			StackPop(&st);
		}
		printf("\n");
	}

	// 销毁
	StackDestroy(&st);
}

int main()
{
	TestStack();

	return 0;
}