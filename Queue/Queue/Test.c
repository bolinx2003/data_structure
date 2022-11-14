#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void TestQueue()
{
	Queue q;

	// 初始化
	QueueInit(&q);

	// 入队列：1~10
	for (int i = 1; i <= 10; i++)
	{
		QueuePush(&q, i);
		printf("%d ", QueueBack(&q));
	}
	printf("\n");

	// 计算队列元素个数
	printf("队列元素个数：%d\n", QueueSize(&q));

	// 出队列
	while (!(QueueEmpty(&q)))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	// 销毁
	QueueDestroy(&q);
}

int main()
{
	TestQueue();

	return 0;
}