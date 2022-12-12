#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

int count = 0;

void TreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	TreeDestroy(root->left);
	TreeDestroy(root->right);
	//printf("%p: %d\n", root, root->data);
	free(root);
	root = NULL;
}

void PreOrder(const BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(const BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(const BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

void LevelOrder(const BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, (BTNode*)root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);

		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");

	QueueDestroy(&q);
}

void TreeSize1(const BTNode* root)
{
	if (root == NULL)
		return;

	++count;
	TreeSize1(root->left);
	TreeSize1(root->right);
}

int TreeSize2(const BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

void TreeLeafSize1(const BTNode* root)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
		count++;

	TreeLeafSize1(root->left);
	TreeLeafSize1(root->right);
}

int TreeLeafSize2(const BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize2(root->left) + TreeLeafSize2(root->right);
}

int TreeKthLevelSize(const BTNode* root, int k)
{
	assert(k >= 1);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeKthLevelSize(root->left, k - 1)
		+ TreeKthLevelSize(root->right, k - 1);
}

int TreeDepth(const BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

BTNode* TreeFind(const BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return (BTNode*)root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

bool TreeComplete(const BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, (BTNode*)root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			// 遇到空，跳出层序遍历
			break;
		}
	}

	// 判断后面有没有非空，如果有就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}