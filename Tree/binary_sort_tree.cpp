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
        return false; // �ڵ㲻����  
    }
    if (node->val == val) {
        return true; // �ҵ��ڵ�  
    }
    else if (val < node->val) {
        return search(node->left, val); // ���������в���  
    }
    else {
        return search(node->right, val); // ���������в���  
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
