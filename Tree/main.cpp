#include"Binary_Tree.h"
#include"binary_sort_tree.h"

static void test_binary_tree()
{
	cout << "**********测试创建二叉树*********" << endl;
	BinaryTree* tree = new BinaryTree;
	cout << "请输入根结点：";
	tree->root = tree->Create();
	if (tree->root)
		cout << "创建成功" << endl;
	else
		cout << "创建失败" << endl;
	// cout << tree->root->data << endl;
	cout << "**********测试完成***********" << endl;


	cout << "\n**********测试遍历**********" << endl;
	cout << "测试前序遍历" << endl;
	tree->pre_order(tree->root);
	cout << endl;

	cout << "测试中序遍历" << endl;
	tree->in_order(tree->root);
	cout << endl;

	cout << "测试后序遍历" << endl;
	tree->post_order(tree->root);
	cout << endl;

	cout << "测试层序遍历" << endl;
	tree->level_order();
	cout << endl;

	cout << "*************测试完成****************" << endl;
}

static void test_binary_sort_tree()
{
	BinarySearchTree tree;
	int data;
	cout << "请输入数据（-1为中止）：";
	cin >> data;
	while (data != -1)
	{
		tree.insert(data);
		cin >> data;
	}
	cout << "中序遍历结果：" << endl;
	tree.inorderTraversal(tree.root);
	cout << endl;

	cout << "请输入要查找的数字：";
	 cin >> data;
	if (tree.search(tree.root, data))
		cout << "找到数字" << data << endl;
	else
		cout << "未找到数字" << data << endl;
}

int main()
{
	//test_binary_tree();
	test_binary_sort_tree();
	system("pause");
	return 0;
}