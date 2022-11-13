#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 带头+双向+循环链表

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

// 初始化
// 方式一
//void ListInit(LTNode** pphead);
// 方式二
LTNode* ListInit();

// 销毁
void ListDestroy(LTNode* phead);

// 尾插
void ListPushBack(LTNode* phead, LTDataType x);

// 头插
void ListPushFront(LTNode* phead, LTDataType x);

// 尾删
void ListPopBack(LTNode* phead);

// 头删
void ListPopFront(LTNode* phead);

// 在pos前面插入
void ListInsert(LTNode* pos, LTDataType x);

// 删除pos
void ListErase(LTNode* pos);

// 查找
LTNode* ListFind(const LTNode* phead, LTDataType x);

// 判空
bool ListEmpty(const LTNode* phead);

// 求链表长度
int ListSize(const LTNode* phead);

// 打印
void ListPrint(const LTNode* phead);