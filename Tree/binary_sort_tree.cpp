#include "binary_sort_tree.h"

void BinarySearchTree::insert(int val)
{
    TreeNode* node = new TreeNode(val);
    if (root == NULL) {
        root = node;
    }
    else {
        TreeNode* cur = root;
        while (cur) {
            if (val < cur->val) {
                if (cur->left == NULL) {
                    cur->left = node;
                    break;
                }
                else {
                    cur = cur->left;
                }
            }
            else {
                if (cur->right == NULL) {
                    cur->right = node;
                    break;
                }
                else {
                    cur = cur->right;
                }
            }
        }
    }
}

bool BinarySearchTree::search(TreeNode* node, int val)
{
    if (node == NULL) {
        return false; // 节点不存在  
    }
    if (node->val == val) {
        return true; // 找到节点  
    }
    else if (val < node->val) {
        return search(node->left, val); // 在左子树中查找  
    }
    else {
        return search(node->right, val); // 在右子树中查找  
    }
}

void BinarySearchTree::inorderTraversal(TreeNode* node)
{
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    cout << node->val << " ";
    inorderTraversal(node->right);
}
