#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 栈
// 使用数组实现

typedef int STDataType;

typedef struct Stack
{
	STDataType* a; // 指向数组的指针
	int top;       // 栈的数据个数
	int capacity;  // 容量
}ST;

// 初始化
void StackInit(ST* ps);

// 销毁
void StackDestroy(ST* ps);

// 入栈
void StackPush(ST* ps, STDataType x);

// 出栈
void StackPop(ST* ps);

// 取栈顶元素
STDataType StackTop(const ST* ps);

// 判断栈是否为空
bool StackEmpty(const ST* ps);

// 栈元素个数
int StackSize(const ST* ps);