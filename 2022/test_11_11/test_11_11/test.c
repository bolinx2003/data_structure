#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
// 删除链表的所有指定元素
//
// 思路一：直接删除
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			// 删除
//			if (prev == NULL)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			// 保留
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//
//	return head;
//}
//
// 思路二：把不是val的值尾插到新链表
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
//			// 尾插
//			if (tail == NULL)
//			{
//				head = cur;
//				tail = head;
//			}
//			else
//			{
//				tail->next = cur;
//				tail = cur;
//			}
//			cur = cur->next;
//		}
//	}
//
//	if (tail != NULL)
//	{
//		tail->next = NULL;
//	}
//
//	return head;
//}
//
// 思路三：在思路二的基础上，使用带哨兵位的头结点
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
//			// 尾插
//			tail->next = cur;
//			tail = cur;
//			cur = cur->next;
//		}
//	}
//
//	tail->next = NULL;
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

// 反转单链表

// 思路一：把每个结点头插到新链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newhead = NULL;
//
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//
//		// 头插
//		cur->next = newhead;
//		newhead = cur;
//
//		cur = next;
//	}
//
//	return newhead;
//}

// 思路二：反转指向
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL)
//		return NULL;
//
//	struct ListNode* n1, * n2, * n3;
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->next;
//
//	while (n2)
//	{
//		// 倒转指向
//		n2->next = n1;
//
//		// 迭代
//		n1 = n2;
//		n2 = n3;
//		if (n3)
//			n3 = n2->next;
//	}
//
//	return n1;
//}

// 查找中间结点
//struct ListNode* middleNode(struct ListNode* head)
//{
//	struct ListNode* fast, * slow;
//	fast = slow = head;
//
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//
//	return slow;
//}