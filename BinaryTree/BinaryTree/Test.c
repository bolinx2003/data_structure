#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

/*
*          1
*        2   4
*      3    5 6
*/

void TestBinaryTree1()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 前序遍历
	printf("PreOrder:\n");
	PreOrder(root); // 1 2 3 # # # 4 5 # # 6 # #

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree2()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 中序遍历
	printf("InOrder:\n");
	InOrder(root); // # 3 # 2 # 1 # 5 # 4 # 6 #

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree3()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 后序遍历
	printf("PostOrder:\n");
	PostOrder(root); // # # 3 # 2 # # 5 # # 6 4 1

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree4()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 层序遍历
	printf("LevelOrder:\n");
	LevelOrder(root); // 1 2 4 3 5 6

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree5()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 统计数据个数
	count = 0;
	TreeSize1(root);
	printf("TreeSize1: %d\n", count);
	printf("TreeSize2: %d\n", TreeSize2(root));

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree6()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 统计叶子结点个数
	count = 0;
	TreeLeafSize1(root);
	printf("TreeLeafSize1: %d\n", count);
	printf("TreeLeafSize2: %d\n", TreeLeafSize2(root));

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree7()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 求第k层结点个数
	printf("TreeKthLevelSize:\n");
	for (int i = 1; i <= 5; i++)
	{
		printf("level %d: %d\n", i, TreeKthLevelSize(root, i));
	}

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree8()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 求二叉树的深度
	printf("TreeDepth: %d\n", TreeDepth(root));

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree9()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	// 查找
	printf("TreeFind:\n");
	for (int i = 0; i <= 7; i++)
	{
		BTNode* pos = TreeFind(root, i);
		if (pos == NULL)
		{
			printf("找不到%d\n", i);
		}
		else
		{
			printf("找到了%d<-->%d\n", i, pos->data);
		}
	}

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

void TestBinaryTree10()
{
	// 创建二叉树
	BTNode* root = CreatBinaryTree();

	printf("TreeComplete: ");
	bool ret = TreeComplete(root);
	if (ret)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	// 销毁二叉树
	TreeDestroy(root);
	root = NULL;
}

int main()
{
	TestBinaryTree10();

	return 0;
}