#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

// 拷贝复杂链表
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return NULL;

	struct Node* cur = head;
	struct Node* copy = NULL;

	// 在原链表的结点后面拷贝一个结点
	while (cur)
	{
		copy = (struct Node*)malloc(sizeof(struct Node));
		if (copy == NULL)
			return NULL;

		copy->val = cur->val;
		copy->next = cur->next;
		cur->next = copy;

		cur = copy->next;
	}

	cur = head;
	copy = NULL;
	// 设置random指针
	while (cur)
	{
		copy = cur->next;

		if (cur->random == NULL)
			copy->random = NULL;
		else
			copy->random = cur->random->next;

		cur = copy->next;
	}

	cur = head;
	copy = NULL;
	struct Node* copyHead = (struct Node*)malloc(sizeof(struct Node));
	if (copyHead == NULL)
		return NULL;
	struct Node* copyTail = copyHead;
	copyHead->next = NULL;
	// 把拷贝的链表解下来
	while (cur)
	{
		copy = cur->next;
		cur->next = copy->next;
		cur = cur->next;

		// 把copy尾插到新链表
		copyTail->next = copy;
		copyTail = copyTail->next;
	}

	copyTail->next = NULL;

	struct Node* plist = copyHead->next;
	free(copyHead);
	return plist;
}