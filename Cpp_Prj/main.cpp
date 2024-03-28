#include"mysort.h"

void MyPrint(int v)
{
	cout << v << " ";
}

// Êä³öÁ´±íÔªËØ£¬·½±ã²âÊÔ
void printList(ListNode* head) {
	ListNode* p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void test()
{
	int arr[10] = { 0 };
	string Buffer = "***********";
	string text[7] = {"Ö±½Ó²åÈëÅÅÐò","ÕÛ°ë²åÈëÅÅÐò","Ï£¶ûÅÅÐò",
		"Ã°ÅÝÅÅÐò","Ñ¡ÔñÅÅÐò","¶ÑÅÅÐò","»ùÊýÅÅÐò"};
	void(*p[])(int*, int) = { InsertSort ,BinaryInsertSort,ShellsSort,
		BubbleSort,SelectSort,heapSort,radix_sort };


	for (int i = 0; i < sizeof(p)/sizeof(void*); i++)
	{
		cout << Buffer + text[i] + Buffer << endl;
		cout << "Before sort: ";
		for (int j = 0; j < 10; j++)
		{
			arr[j] = rand() % 10;
			cout << arr[j] << " ";
		}
		cout << endl;

		p[i](arr, sizeof(arr) / sizeof(arr[0]));

		cout << "After sort: ";
		for (int j = 0; j < 10; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
		cout << Buffer + Buffer<< endl;
		cout << endl;
		
	}

	cout << "************¿ìËÙÅÅÐò*************" << endl;
	cout << "Before sort: ";
	for (int j = 0; j < 10; j++)
	{
		arr[j] = rand() % 10;
		cout << arr[j] << " ";
	}
	cout << endl;
	QuickSort(arr, 0, 9);
	cout << "After sort: ";
	for (int j = 0; j < 10; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "*********************" << endl;

	cout << endl << "***********¹é²¢ÅÅÐò*********"<< endl;
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
	}
	cout << "Before sort: ";
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
	cout << "After sort: ";
	mergeSort(v, 0, 9);
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl << "*********************" << endl;

	cout << endl << "************²âÊÔ¹é²¢ÅÅÐòÁ´±í°æ*********" << endl;
	// ´´½¨Á´±í£º2 -> 4 -> 3 -> 1 -> 5
	ListNode* head = new ListNode(2);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(1);
	head->next->next->next->next = new ListNode(5);
	cout << "Original list: ";
	printList(head);

	ListNode* sortedHead = sortList(head);

	cout << "Sorted list: ";
	printList(sortedHead);
	cout << "*********************" << endl;

}


int main()
{
	srand((size_t)time(NULL));
	test();
	system("pause");
	return 0;
}