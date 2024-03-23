#include "Binary_Tree.h"

BinaryTree::BinaryTree()
{
	this->root = new tree_node;
}

tree_node* BinaryTree::Create()
{
	DataType data;
	cin >> data;
	if (data != "null")
	{
		tree_node* node = new tree_node;
		node->data = data;
		cout << "请输入节点" << data << "的左孩子：";
		node->lchild = Create();
		cout << "请输入节点" << data << "的右孩子：";
		node->rchild = Create();
		return node;
	}
	else
		return nullptr;
}

void BinaryTree::pre_order(tree_node*node)
{
	if (!node)  
		return;
	cout << node->data << " ";
	pre_order(node->lchild);
	pre_order(node->rchild);
}

void BinaryTree::in_order(tree_node* node)
{
	if (!node)
		return;
	pre_order(node->lchild);
	cout << node->data << " ";
	pre_order(node->rchild);
}

void BinaryTree::post_order(tree_node* node)
{
	if (!node)
		return;
	pre_order(node->lchild);
	pre_order(node->rchild);
	cout << node->data << " ";
}

void BinaryTree::level_order()
{
	if (!this->root)
		return;
	queue<tree_node*>myqueue;
	myqueue.push(this->root);
	tree_node* tmp = myqueue.front();
	myqueue.pop();
	while (tmp)
	{
		cout << tmp->data << " ";
		if (tmp->lchild)
			myqueue.push(tmp->lchild);
		if (tmp->rchild)
			myqueue.push(tmp->rchild);
		
		if (myqueue.empty())
			tmp = nullptr;
		else
		{
			tmp = myqueue.front();
			myqueue.pop();
		}
	}
}
