#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

// 找倒数第k个结点
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	struct ListNode* fast, * slow;
//	fast = slow = pListHead;
//
//	// fast先走k步
//	while (k--)
//	{
//		// k太大了，fast提前走到NULL
//		if (fast == NULL)
//		{
//			return NULL;
//		}
//
//		fast = fast->next;
//	}
//
//	// 一起走
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//
//	return slow;
//}

// 合并2个有序链表
//
// 思路一
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	if (list1 == NULL)
//	{
//		return list2;
//	}
//	if (list2 == NULL)
//	{
//		return list1;
//	}
//
//	struct ListNode* head, * tail;
//	head = tail = NULL;
//
//	while (list1 && list2)
//	{
//		// 取小的尾插到新链表
//		if (list1->val < list2->val)
//		{
//			if (tail == NULL)
//			{
//				head = tail = list1;
//			}
//			else
//			{
//				tail->next = list1;
//				tail = tail->next;
//			}
//			list1 = list1->next;
//		}
//		else
//		{
//			if (tail == NULL)
//			{
//				head = tail = list2;
//			}
//			else
//			{
//				tail->next = list2;
//				tail = tail->next;
//			}
//			list2 = list2->next;
//		}
//	}
//
//	if (list1)
//	{
//		tail->next = list1;
//	}
//	else
//	{
//		tail->next = list2;
//	}
//
//	return head;
//}
//
// 思路二
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	struct ListNode* head, * tail;
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	tail->next = NULL;
//
//	while (list1 && list2)
//	{
//		if (list1->val < list2->val)
//		{
//			tail->next = list1;
//			tail = tail->next;
//
//			list1 = list1->next;
//		}
//		else
//		{
//			tail->next = list2;
//			tail = tail->next;
//
//			list2 = list2->next;
//		}
//	}
//
//	if (list1)
//	{
//		tail->next = list1;
//	}
//	else
//	{
//		tail->next = list2;
//	}
//
//	struct ListNode* list = head->next;
//	free(head);
//	return list;
//}

// 链表分割
//
// 思路一
//struct ListNode* partition(struct ListNode* pHead, int x)
//{
//	struct ListNode* cur = pHead, * lesshead, * lesstail, * greaterhead, * greatertail;
//	lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	lesstail->next = NULL;
//	greatertail->next = NULL;
//
//	// 分别尾插到2个链表
//	while (cur)
//	{
//		if (cur->val < x)
//		{
//			lesstail->next = cur;
//			lesstail = lesstail->next;
//		}
//		else
//		{
//			greatertail->next = cur;
//			greatertail = greatertail->next;
//		}
//
//		cur = cur->next;
//	}
//	greatertail->next = NULL;
//
//	// 把两个链表链接起来
//	lesstail->next = greaterhead->next;
//
//	struct ListNode* list = lesshead->next;
//	free(lesshead);
//	free(greaterhead);
//	return list;
//}
//
// 思路二
//struct ListNode* partition(struct ListNode* pHead, int x) {
//	if (pHead == NULL)
//	{
//		return NULL;
//	}
//
//	struct ListNode* cur = pHead, * lesshead = NULL, * lesstail = NULL, * greaterhead = NULL, * greatertail = NULL;
//
//	// 插入
//	while (cur)
//	{
//		if (cur->val < x)
//		{
//			if (lesstail == NULL)
//			{
//				lesshead = lesstail = cur;
//			}
//			else
//			{
//				lesstail->next = cur;
//				lesstail = lesstail->next;
//			}
//		}
//		else
//		{
//			if (greatertail == NULL)
//			{
//				greaterhead = greatertail = cur;
//			}
//			else
//			{
//				greatertail->next = cur;
//				greatertail = greatertail->next;
//			}
//		}
//
//		cur = cur->next;
//	}
//
//	if (greatertail)
//		greatertail->next = NULL;
//
//	// 链接
//	if (lesstail)
//		lesstail->next = greaterhead;
//	else
//		return greaterhead;
//
//	return lesshead;
//}