#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// 链式二叉树

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

// 用于统计个数
extern int count;

// 销毁二叉树
void TreeDestroy(BTNode* root);

// 前序遍历
void PreOrder(const BTNode* root);

// 中序遍历
void InOrder(const BTNode* root);

// 后序遍历
void PostOrder(const BTNode* root);

// 层序遍历
void LevelOrder(const BTNode* root);

// 统计结点个数
void TreeSize1(const BTNode* root);
int TreeSize2(const BTNode* root);

// 统计叶子结点个数
void TreeLeafSize1(const BTNode* root);
int TreeLeafSize2(const BTNode* root);

// 求第k层结点的个数
int TreeKthLevelSize(const BTNode* root, int k);

// 求二叉树的深度
int TreeDepth(const BTNode* root);

// 查找值为x的结点
BTNode* TreeFind(const BTNode* root, BTDataType x);

// 判断是否为完全二叉树
bool TreeComplete(const BTNode* root);