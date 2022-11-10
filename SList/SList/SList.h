#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// 销毁
void SListDestroy(SLTNode* phead);

// 打印
void SListPrint(const SLTNode* phead);

// 尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);

// 头插
void SListPushFront(SLTNode** pphead, SLTDataType x);

// 尾删
void SListPopBack(SLTNode** pphead);

// 头删
void SListPopFront(SLTNode** pphead);

// 查找
SLTNode* SListFind(const SLTNode* phead, SLTDataType x);

// 在pos位置之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// 删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);

// 在pos位置之后插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 删除pos位置后面的位置的值
void SListEraseAfter(SLTNode* pos);
