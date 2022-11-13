#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//struct Node
//{
//	int val;
//	struct Node* next;
//	struct Node* random;
//};
//
//// 拷贝复杂链表
//struct Node* copyRandomList(struct Node* head)
//{
//	if (head == NULL)
//		return NULL;
//
//	struct Node* cur = head;
//	struct Node* copy = NULL;
//
//	// 在原链表的结点后面拷贝一个结点
//	while (cur)
//	{
//		copy = (struct Node*)malloc(sizeof(struct Node));
//		if (copy == NULL)
//			return NULL;
//
//		copy->val = cur->val;
//		copy->next = cur->next;
//		cur->next = copy;
//
//		cur = copy->next;
//	}
//
//	cur = head;
//	copy = NULL;
//	// 设置random指针
//	while (cur)
//	{
//		copy = cur->next;
//
//		if (cur->random == NULL)
//			copy->random = NULL;
//		else
//			copy->random = cur->random->next;
//
//		cur = copy->next;
//	}
//
//	cur = head;
//	copy = NULL;
//	struct Node* copyHead = (struct Node*)malloc(sizeof(struct Node));
//	if (copyHead == NULL)
//		return NULL;
//	struct Node* copyTail = copyHead;
//	copyHead->next = NULL;
//	// 把拷贝的链表解下来
//	while (cur)
//	{
//		copy = cur->next;
//		cur->next = copy->next;
//		cur = cur->next;
//
//		// 把copy尾插到新链表
//		copyTail->next = copy;
//		copyTail = copyTail->next;
//	}
//
//	copyTail->next = NULL;
//
//	struct Node* plist = copyHead->next;
//	free(copyHead);
//	return plist;
//}

// 使用栈判断是不是有效的括号
//typedef char STDataType;
//
//typedef struct Stack
//{
//	STDataType* a; // 指向数组的指针
//	int top;       // 栈的数据个数
//	int capacity;  // 容量
//}ST;
//
//// 初始化
//void StackInit(ST* ps);
//
//// 销毁
//void StackDestroy(ST* ps);
//
//// 入栈
//void StackPush(ST* ps, STDataType x);
//
//// 出栈
//void StackPop(ST* ps);
//
//// 取栈顶元素
//STDataType StackTop(const ST* ps);
//
//// 判断栈是否为空
//bool StackEmpty(const ST* ps);
//
//// 栈元素个数
//int StackSize(const ST* ps);
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//
//	free(ps->a);
//	ps->top = ps->capacity = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//
//	// 检查容量
//	if (ps->top == ps->capacity)
//	{
//		// 满了
//		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
//		STDataType* tmp = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("StackPush::realloc");
//			return;
//		}
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//
//	// 插入
//	ps->a[ps->top++] = x;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	ps->top--;
//}
//
//STDataType StackTop(const ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//bool StackEmpty(const ST* ps)
//{
//	assert(ps);
//
//	return ps->top == 0;
//}
//
//int StackSize(const ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//// 判断是不是有效的括号
//bool isValid(char* s)
//{
//	assert(s);
//
//	ST st;
//	StackInit(&st);
//
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//		}
//		else
//		{
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//
//			char top = StackTop(&st);
//			StackPop(&st);
//
//			// 判断是否匹配
//			if (!((top == '(' && *s == ')') || (top == '[' && *s == ']') || (top == '{' && *s == '}')))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//		}
//
//		s++;
//	}
//
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "[](){}([{}]))";
//
//	if (isValid(arr))
//	{
//		printf("valid\n");
//	}
//	else
//	{
//		printf("invalid\n");
//	}
//
//	return 0;
//}