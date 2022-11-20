#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

// 判断两棵树是否相同
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;

	if (p == NULL || q == NULL)
		return false;

	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

// 判断两颗子树是否对称
bool isSymmetricSubTree(struct TreeNode* root1, struct TreeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	if (root1->val != root2->val)
		return false;

	return isSymmetricSubTree(root1->left, root2->right)
		&& isSymmetricSubTree(root1->right, root2->left);
}

// 判断一棵树是否对称
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
		return true;

	return isSymmetricSubTree(root->left, root->right);
}

// 判断一棵树是不是另一棵树的子树
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (subRoot == NULL)
		return true;

	if (root == NULL)
		return false;

	if (isSameTree(root, subRoot))
		return true;

	return isSubtree(root->left, subRoot)
		|| isSubtree(root->right, subRoot);
}

// 计算结点个数
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

// 前序遍历
void preorder(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;

	a[(*pi)++] = root->val;

	preorder(root->left, a, pi);
	preorder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (returnSize == NULL)
		return NULL;

	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	*returnSize = TreeSize(root);
	int* ret = (int*)malloc(sizeof(int) * (*returnSize));
	if (ret == NULL)
		return NULL;

	int i = 0;
	preorder(root, ret, &i);

	return ret;
}