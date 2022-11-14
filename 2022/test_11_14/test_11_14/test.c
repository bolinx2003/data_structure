#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 队列
// 使用单链表实现
//
//typedef int QDataType;
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//}Queue;
//
//// 初始化
//void QueueInit(Queue* pq);
//
//// 销毁
//void QueueDestroy(Queue* pq);
//
//// 队尾入队列
//void QueuePush(Queue* pq, QDataType x);
//
//// 队头出队列
//void QueuePop(Queue* pq);
//
//// 取队头元素
//QDataType QueueFront(const Queue* pq);
//
//// 取队尾元素
//QDataType QueueBack(const Queue* pq);
//
//// 判断队列是否为空
//bool QueueEmpty(const Queue* pq);
//
//// 计算队列有效元素个数
//int QueueSize(const Queue* pq);
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->head = pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("QueuePush::malloc");
//		return;
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->tail == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	if (pq->head->next == NULL)
//	{
//		// 只剩1个结点
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		// 还有多个结点
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//}
//
//QDataType QueueFront(const Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(const Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//bool QueueEmpty(const Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL;
//}
//
//int QueueSize(const Queue* pq)
//{
//	assert(pq);
//
//	int size = 0;
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		++size;
//		cur = cur->next;
//	}
//
//	return size;
//}
//
//// 以下使用2个队列实现栈
//
//typedef struct
//{
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//MyStack* myStackCreate()
//{
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	if (obj == NULL)
//	{
//		perror("myStackCreate::malloc");
//		return NULL;
//	}
//
//	QueueInit(&(obj->q1));
//	QueueInit(&(obj->q2));
//
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	assert(obj);
//
//	Queue* pEmptyQ = &(obj->q1);
//	Queue* pNonEmptyQ = &(obj->q2);
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		pEmptyQ = &(obj->q2);
//		pNonEmptyQ = &(obj->q1);
//	}
//
//	// 把数据push到非空的队列
//	QueuePush(pNonEmptyQ, x);
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	assert(obj);
//
//	// 两个队列都空，则栈为空
//	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
//}
//
//int myStackPop(MyStack* obj)
//{
//	assert(obj);
//	assert(!myStackEmpty(obj));
//
//	Queue* pEmptyQ = &(obj->q1);
//	Queue* pNonEmptyQ = &(obj->q2);
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		pEmptyQ = &(obj->q2);
//		pNonEmptyQ = &(obj->q1);
//	}
//
//	// 把非空的队列的前size-1个数据拷贝到空队列
//	int size = QueueSize(pNonEmptyQ);
//	for (int i = 0; i < size - 1; i++)
//	{
//		QueuePush(pEmptyQ, QueueFront(pNonEmptyQ));
//		QueuePop(pNonEmptyQ);
//	}
//
//	int top = QueueFront(pNonEmptyQ);
//	QueuePop(pNonEmptyQ);
//	return top;
//}
//
//int myStackTop(MyStack* obj)
//{
//	assert(obj);
//	assert(!myStackEmpty(obj));
//
//	Queue* pEmptyQ = &(obj->q1);
//	Queue* pNonEmptyQ = &(obj->q2);
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		pEmptyQ = &(obj->q2);
//		pNonEmptyQ = &(obj->q1);
//	}
//
//	// 非空队列的队尾
//	return QueueBack(pNonEmptyQ);
//}
//
//void myStackFree(MyStack* obj)
//{
//	assert(obj);
//
//	QueueDestroy(&(obj->q1));
//	QueueDestroy(&(obj->q2));
//	free(obj);
//	obj = NULL;
//}
//
//void TestMyStack()
//{
//	// 初始化
//	MyStack* pst = myStackCreate();
//	if (pst == NULL)
//	{
//		printf("myStackCreate fail\n");
//		return;
//	}
//
//	// push1~10
//	for (int i = 1; i <= 10; i++)
//	{
//		myStackPush(pst, i);
//	}
//
//	// pop直到栈为空
//	while (!myStackEmpty(pst))
//	{
//		printf("%d ", myStackTop(pst));
//		myStackPop(pst);
//	}
//
//	// 销毁
//	myStackFree(pst);
//	pst = NULL;
//}
//
//int main()
//{
//	TestMyStack();
//
//	return 0;
//}

// 栈
// 使用数组实现
//
//typedef int STDataType;
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
//// 使用2个栈实现队列
//
//typedef struct
//{
//	ST pushst;
//	ST popst;
//} MyQueue;
//
//MyQueue* myQueueCreate()
//{
//	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//	if (obj == NULL)
//	{
//		perror("myQueueCreate::malloc");
//		return NULL;
//	}
//
//	StackInit(&(obj->pushst));
//	StackInit(&(obj->popst));
//	return obj;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//	assert(obj);
//
//	StackPush(&(obj->pushst), x);
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//	assert(obj);
//
//	return StackEmpty(&(obj->pushst)) && StackEmpty(&(obj->popst));
//}
//
//int myQueuePop(MyQueue* obj)
//{
//	assert(obj);
//	assert(!myQueueEmpty(obj));
//
//	// 判断popst里是否有数据，如果没有就把pushst的数据转移到popst里
//	if (StackEmpty(&(obj->popst)))
//	{
//		while (!StackEmpty(&(obj->pushst)))
//		{
//			StackPush(&(obj->popst), StackTop(&(obj->pushst)));
//			StackPop(&(obj->pushst));
//		}
//	}
//
//	int head = StackTop(&(obj->popst));
//	StackPop(&(obj->popst));
//	return head;
//}
//
//int myQueuePeek(MyQueue* obj)
//{
//	assert(obj);
//	assert(!myQueueEmpty(obj));
//
//	// 判断popst里是否有数据，如果没有就把pushst的数据转移到popst里
//	if (StackEmpty(&(obj->popst)))
//	{
//		while (!StackEmpty(&(obj->pushst)))
//		{
//			StackPush(&(obj->popst), StackTop(&(obj->pushst)));
//			StackPop(&(obj->pushst));
//		}
//	}
//
//	return StackTop(&(obj->popst));
//}
//
//void myQueueFree(MyQueue* obj)
//{
//	StackDestroy(&(obj->pushst));
//	StackDestroy(&(obj->popst));
//
//	free(obj);
//	obj = NULL;
//}
//
//void TestMyQueue()
//{
//	// 初始化
//	MyQueue* pq = myQueueCreate();
//	if (pq == NULL)
//	{
//		printf("myQueueCreate fail\n");
//		return;
//	}
//
//	// push1~10
//	for (int i = 1; i <= 10; i++)
//	{
//		myQueuePush(pq, i);
//	}
//
//	// pop直到空
//	while (!myQueueEmpty(pq))
//	{
//		printf("%d ", myQueuePeek(pq));
//		myQueuePop(pq);
//	}
//
//	// 销毁
//	myQueueFree(pq);
//	pq = NULL;
//}
//
//int main()
//{
//	TestMyQueue();
//
//	return 0;
//}