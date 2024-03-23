#pragma once
#include<iostream>
#include<queue>
using namespace std;
#define DataType string

// ���
typedef struct tree_node
{
	DataType data;
	tree_node* lchild = nullptr;
	tree_node* rchild = nullptr;
}tree_node;

// ������
class BinaryTree
{
public:
	tree_node* root;
	BinaryTree();

	// ����
	tree_node* Create();

	// �������
	void pre_order(tree_node* node);

	// �������
	void in_order(tree_node* node);

	// �������
	void post_order(tree_node* node);

	// �������
	void level_order();
};

