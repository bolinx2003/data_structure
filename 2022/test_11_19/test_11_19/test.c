#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

// 判断是否是单值二叉树
//
//bool flag = true;
//
//void PreOrderCompare(struct TreeNode* root, int val)
//{
//	if (root == NULL)
//		return;
//
//	if (flag == false)
//		return;
//
//	if (root->val != val)
//	{
//		flag = false;
//		return;
//	}
//
//	PreOrderCompare(root->left, val);
//	PreOrderCompare(root->right, val);
//}
//
//bool isUnivalTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//
//	flag = true;
//	PreOrderCompare(root, root->val);
//	return flag;
//}
//
//bool isUnivalTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//
//	if (root->left && root->left->val != root->val)
//		return false;
//
//	if (root->right && root->right->val != root->val)
//		return false;
//
//	return isUnivalTree(root->left)
//		&& isUnivalTree(root->right);
//}