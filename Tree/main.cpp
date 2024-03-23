#include"Binary_Tree.h"
#include"binary_sort_tree.h"

static void test_binary_tree()
{
	cout << "**********���Դ���������*********" << endl;
	BinaryTree* tree = new BinaryTree;
	cout << "���������㣺";
	tree->root = tree->Create();
	if (tree->root)
		cout << "�����ɹ�" << endl;
	else
		cout << "����ʧ��" << endl;
	// cout << tree->root->data << endl;
	cout << "**********�������***********" << endl;


	cout << "\n**********���Ա���**********" << endl;
	cout << "����ǰ�����" << endl;
	tree->pre_order(tree->root);
	cout << endl;

	cout << "�����������" << endl;
	tree->in_order(tree->root);
	cout << endl;

	cout << "���Ժ������" << endl;
	tree->post_order(tree->root);
	cout << endl;

	cout << "���Բ������" << endl;
	tree->level_order();
	cout << endl;

	cout << "*************�������****************" << endl;
}

static void test_binary_sort_tree()
{
	BinarySearchTree tree;
	int data;
	cout << "���������ݣ�-1Ϊ��ֹ����";
	cin >> data;
	while (data != -1)
	{
		tree.insert(data);
		cin >> data;
	}
	cout << "������������" << endl;
	tree.inorderTraversal(tree.root);
	cout << endl;

	cout << "������Ҫ���ҵ����֣�";
	 cin >> data;
	if (tree.search(tree.root, data))
		cout << "�ҵ�����" << data << endl;
	else
		cout << "δ�ҵ�����" << data << endl;
}

int main()
{
	//test_binary_tree();
	test_binary_sort_tree();
	system("pause");
	return 0;
}