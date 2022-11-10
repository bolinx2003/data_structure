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
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
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

	SLTNode* newnode = BuySListNode(x);

	if (*pphead)
	{
		// 找尾结点
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
	else
	{
		*pphead = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
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
	const SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			// 找到了
			return (SLTNode*)cur;
		}
		cur = cur->next;
	}

	// 没找到
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		// 头插
		SListPushFront(pphead, x);
	}
	else
	{
		// 找pos的前一个
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySListNode(x);
		newnode->next = pos;
		prev->next = newnode;
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		// 头删
		SListPopFront(pphead);
	}
	else
	{
		// 找pos的前一个结点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* del = pos->next;
	pos->next = del->next;

	free(del);
	del = NULL;
}