#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int* a;   // 指向数组的指针
	int k;    // 最多存储有效数据的个数
	int head; // 头下标
	int tail; // 尾下标
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL)
	{
		perror("myCircularQueueCreate::malloc");
		return NULL;
	}

	obj->a = (int*)malloc((k + 1) * sizeof(int));
	if (obj->a == NULL)
	{
		perror("myCircularQueueCreate::malloc");
		free(obj);
		obj = NULL;
		return NULL;
	}

	obj->k = k;
	obj->head = 0;
	obj->tail = 0;

	return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj == NULL)
		return false;

	return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj == NULL)
		return false;

	if (obj->tail == obj->k && obj->head == 0)
		return true;

	return obj->tail + 1 == obj->head;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (obj == NULL)
		return false;

	if (myCircularQueueIsFull(obj))
		return false;

	obj->a[obj->tail] = value;
	obj->tail++;
	if (obj->tail == obj->k + 1)
		obj->tail = 0;

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (obj == NULL)
		return false;

	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->head++;
	if (obj->head == obj->k + 1)
		obj->head = 0;

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (obj == NULL)
		return false;

	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (obj == NULL)
		return false;

	if (myCircularQueueIsEmpty(obj))
		return -1;

	if (obj->tail == 0)
		return obj->a[obj->k];

	return obj->a[obj->tail - 1];
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	if (obj == NULL)
		return;

	free(obj->a);
	obj->a = NULL;
	free(obj);
	obj = NULL;
}