#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

static LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("BuyListNode::malloc");
		exit(-1);
	}

	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

//void ListInit(LTNode** pphead)
//{
//	assert(pphead);
//
//	*pphead = BuyListNode(-1);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	ListInsert(phead, x);

	// 手动尾插
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;
	//
	//// 链接tail newnode phead
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	ListInsert(phead->next, x);

	// 手动头插
	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->next;
	//
	//// 链接phead newnode next
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = next;
	//next->prev = newnode;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	ListErase(phead->prev);

	// 手动尾删
	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;
	//
	//free(tail);
	//
	//tailPrev->next = phead;
	//phead->prev = tailPrev;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	ListErase(phead->next);

	// 手动头删
	//LTNode* head = phead->next;
	//LTNode* headNext = head->next;
	//
	//free(head);
	//
	//phead->next = headNext;
	//headNext->prev = phead;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	// 链接prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	free(pos);

	prev->next = next;
	next->prev = prev;
}

LTNode* ListFind(const LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}

	return NULL;
}

bool ListEmpty(const LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

int ListSize(const LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

void ListPrint(const LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}