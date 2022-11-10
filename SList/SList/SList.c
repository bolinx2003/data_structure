#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SListDestroy(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

static SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPrint(const SLTNode* phead)
{
	const SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newNode = BuySListNode(x);

	if (*pphead)
	{
		// 找尾结点
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
	else
	{
		*pphead = newNode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	if ((*pphead)->next)
	{
		// 找尾结点的前一个结点
		SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		// 此时tail->next是尾结点
		free(tail->next);
		// 此时tail是新的尾结点
		tail->next = NULL;
	}
	else
	{
		free(*pphead);
		*pphead = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(const SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			break;
		}
		cur = cur->next;
	}

	return cur;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
}