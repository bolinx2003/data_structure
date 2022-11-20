#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 队列
// 使用单链表实现

struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

// 初始化
void QueueInit(Queue* pq);

// 销毁
void QueueDestroy(Queue* pq);

// 队尾入队列
void QueuePush(Queue* pq, QDataType x);

// 队头出队列
void QueuePop(Queue* pq);

// 取队头元素
QDataType QueueFront(const Queue* pq);

// 取队尾元素
QDataType QueueBack(const Queue* pq);

// 判断队列是否为空
bool QueueEmpty(const Queue* pq);

// 计算队列有效元素个数
int QueueSize(const Queue* pq);