#pragma once
#include<iostream>
#include<queue>
using namespace std;
#define DataType string

// 结点
typedef struct tree_node
{
	DataType data;
	tree_node* lchild = nullptr;
	tree_node* rchild = nullptr;
}tree_node;

// 二叉树
class BinaryTree
{
public:
	tree_node* root;
	BinaryTree();

	// 构建
	tree_node* Create();

	// 先序遍历
	void pre_order(tree_node* node);

	// 中序遍历
	void in_order(tree_node* node);

	// 后序遍历
	void post_order(tree_node* node);

	// 层序遍历
	void level_order();
};

