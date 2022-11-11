#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//// 删除链表的所有指定元素
//
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* tail = NULL;
//	head = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			// 删除
//			struct ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else
//		{
//			// 尾插保存
//			if (tail)
//			{
//				tail->next = cur;
//				tail = cur;
//			}
//			else
//			{
//				head = cur;
//				tail = head;
//			}
//			cur = cur->next;
//		}
//	}
//
//	if (tail)
//		tail->next = NULL;
//
//	return head;
//}
//
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			// 删除
//			if (prev)
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//			else
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//
//	return head;
//}
//
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* tail = NULL;
//	head = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			// 删除
//			struct ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else
//		{
//			// 保存
//			if (tail == NULL)
//			{
//				head = cur;
//			}
//			else
//			{
//				tail->next = cur;
//			}
//			tail = cur;
//			cur = cur->next;
//			tail->next = NULL;
//		}
//	}
//
//	return head;
//}
//
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	head = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* tail = head;
//	tail->next = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			// 删除
//			struct ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else
//		{
//			tail->next = cur;
//			tail = cur;
//			cur = cur->next;
//			tail->next = NULL;
//		}
//	}
//
//	struct ListNode* newHead = head->next;
//	free(head);
//	return newHead;
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n5);
//	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n6);
//	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n7);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 6;
//	n4->val = 3;
//	n5->val = 4;
//	n6->val = 5;
//	n7->val = 6;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = n7;
//	n7->next = NULL;
//
//	struct ListNode* plist = n1;
//	plist = removeElements(n1, 6);
//
//	return 0;
//}