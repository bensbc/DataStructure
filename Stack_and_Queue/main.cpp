#include"mystack.h"
#include"myqueue.h"
static void test_linear_stack()
{
	cout << "*********创建线性栈*********" << endl;
	linear_stack* l_stack = new linear_stack;
	if (l_stack)
		cout << "************创建成功**********" << endl;
	else
		cout << "**************创建失败***********" << endl;


	cout << "\n***************测试入栈****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	bool get = false;
	cout << "请输入数据量："; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "请输入第" << i + 1 << "个数据："; cin >> data;
		if (!l_stack->Push(data))
			cout << "入栈失败" << endl;
	}
	cout << "当前栈的大小：" << l_stack->size << endl;
	cout << "当前栈顶元素：" << l_stack->Top(get) << endl;
	cout << "**************测试完成****************" << endl;

	cout << "\n***************测试出栈***************" << endl;
	cout << "出栈元素：";
	size = l_stack->size;
	for (i = 0; i < size; i++)
	{
		cout << l_stack->Top(get) << " ";
		l_stack->Pop();
	}
	cout << "\n*****************测试完成*****************" << endl;

	cout << "\n**************测试清空*************" << endl;
	l_stack->Clear();
	if (l_stack->IsEmpty())
	{
		cout << "已清空" << endl;
	}
	else
		cout << "清空失败" << endl;
	cout << "*****************测试完成*****************" << endl;

}

static void test_linked_stack()
{
	cout << "*********创建链栈*********" << endl;
	link_stack* LinkStack = new link_stack;
	if (LinkStack)
		cout << "************创建成功**********" << endl;
	else
		cout << "**************创建失败***********" << endl;


	cout << "\n***************测试入栈****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	cout << "请输入数据量："; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "请输入第" << i + 1 << "个数据："; cin >> data;
		if (!LinkStack->Push(data))
			cout << "入栈失败" << endl;
	}
	cout << "当前栈的大小：" << LinkStack->head->data << endl;
	if (LinkStack->Top())
		cout << "当前栈顶元素：" << LinkStack->Top()->data << endl;
	cout << "**************测试完成****************" << endl;


	cout << "\n***************测试出栈***************" << endl;
	cout << "出栈元素：";
	size = LinkStack->head->data;
	for (i = 0; i < size; i++)
	{
		if (LinkStack->Top())
			cout << LinkStack->Top()->data << " ";
		if (!LinkStack->Pop())
			cout << "出栈失败" << endl;
	}
	cout << "\n*****************测试完成*****************" << endl;

	cout << "\n**************测试清空*************" << endl;
	LinkStack->Clear();
	if (LinkStack->IsEmpty())
	{
		cout << "已清空" << endl;
	}
	else
		cout << "清空失败" << endl;
	cout << "*****************测试完成*****************" << endl;

	cout << "\n***************测试销毁************" << endl;
	LinkStack->Destroy();
	if (!LinkStack->head)
		cout << "销毁成功" << endl;
	else
		cout << "销毁失败" << endl;
	cout << "*****************测试完成*****************" << endl;

}

static void test_linear_queue()
{
	cout << "*********创建线性队*********" << endl;
	linear_queue* LinearQueue = new linear_queue;
	if (LinearQueue)
		cout << "************创建成功**********" << endl;
	else
		cout << "**************创建失败***********" << endl;


	cout << "\n***************测试入队****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	bool get = false;
	cout << "请输入数据量："; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "请输入第" << i + 1 << "个数据："; cin >> data;
		if (!LinearQueue->Push(data))
			cout << "入队失败" << endl;
	}
	cout << "当前队的大小：" << LinearQueue->size << endl;
	cout << "当前队头元素：" << LinearQueue->Front(get) << endl;
	cout << "当前队尾元素：" << LinearQueue->Rear(get) << endl;
	cout << "**************测试完成****************" << endl;

	cout << "\n***************测试出队***************" << endl;
	cout << "出队元素：";
	size = LinearQueue->size;
	for (i = 0; i < size; i++)
	{
		cout << LinearQueue->Front(get) << " ";
		LinearQueue->Pop();
	}
	cout << "\n*****************测试完成*****************" << endl;

	cout << "\n**************测试清空*************" << endl;
	LinearQueue->Clear();
	if (LinearQueue->IsEmpty())
	{
		cout << "已清空" << endl;
	}
	else
		cout << "清空失败" << endl;
	cout << "*****************测试完成*****************" << endl;
}

static void test_linked_queue()
{
	cout << "*********创建链队*********" << endl;
	linked_queue* LinkQueue = new linked_queue;
	if (LinkQueue)
		cout << "************创建成功**********" << endl;
	else
		cout << "**************创建失败***********" << endl;


	cout << "\n***************测试入队****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	cout << "请输入数据量："; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "请输入第" << i + 1 << "个数据："; cin >> data;
		if (!LinkQueue->Push(data))
			cout << "入队失败" << endl;
	}
	cout << "当前队的大小：" << LinkQueue->size << endl;
	if (LinkQueue->Front() && LinkQueue->Rear())
	{
		cout << "当前队头元素：" << LinkQueue->Front()->data << endl;
		cout << "当前队尾元素：" << LinkQueue->Rear()->data << endl;
	}
	cout << "**************测试完成****************" << endl;

	cout << "\n***************测试出队***************" << endl;
	cout << "出队元素：";
	size = LinkQueue->size;
	for (i = 0; i < size; i++)
	{
		cout << LinkQueue->Front()->data << " ";
		LinkQueue->Pop();
	}
	cout << "\n*****************测试完成*****************" << endl;

	cout << "\n**************测试清空*************" << endl;
	LinkQueue->Clear();
	if (LinkQueue->IsEmpty())
	{
		cout << "已清空" << endl;
	}
	else
		cout << "清空失败" << endl;
	cout << "*****************测试完成*****************" << endl;
}

int main()
{
	void(*fp[])(void) = { test_linear_stack, test_linked_stack, test_linear_queue, test_linked_queue };
	// fp[0]();
	// fp[1]();
	// fp[2]();
	fp[3]();
	system("pause");
	return 0;
}