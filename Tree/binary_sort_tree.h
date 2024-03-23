#pragma once
#include <iostream>  
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinarySearchTree {
public:
    TreeNode* root;
    BinarySearchTree() : root(NULL) {}

    // 插入节点  
    void insert(int val);

    // 查找结点
    bool search(TreeNode* node, int val);

    // 中序遍历  
    void inorderTraversal(TreeNode* node);
};
