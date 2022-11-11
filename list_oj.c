// 方便调试oj链表题目

#include <stdlib.h>
#include <assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n1);
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n2);
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n3);
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n4);
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n5);
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n6);
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n7);

	n1->val = 1;
	n2->val = 1;
	n3->val = 1;
	n4->val = 1;
	n5->val = 1;
	n6->val = 1;
	n7->val = 1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	struct ListNode* plist = n1;

	return 0;
}