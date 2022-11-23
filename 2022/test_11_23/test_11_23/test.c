#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* ReverseList(struct ListNode* phead)
{
	if (phead == NULL)
		return NULL;

	struct ListNode* p1 = NULL, * p2 = phead, * p3 = phead->next;
	while (p2)
	{
		p2->next = p1;
		
		p1 = p2;
		p2 = p3;
		if (p3)
			p3 = p3->next;
	}

	return p1;
}

int main()
{
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	assert(p1 && p2 && p3 && p4 && p5);

	p1->val = 1;
	p2->val = 2;
	p3->val = 3;
	p4->val = 4;
	p5->val = 5;

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;

	struct ListNode* plist = p1;

	plist = ReverseList(plist);

	while (plist)
	{
		printf("%d->", plist->val);
		plist = plist->next;
	}
	printf("NULL\n");

	return 0;
}