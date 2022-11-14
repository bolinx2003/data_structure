#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("QueuePush::malloc");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		// 只剩1个结点
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		// 还有多个结点
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QDataType QueueFront(const Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(const Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

bool QueueEmpty(const Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}

int QueueSize(const Queue* pq)
{
	assert(pq);

	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}

	return size;
}