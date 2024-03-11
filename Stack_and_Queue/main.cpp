#include"mystack.h"
#include"myqueue.h"
static void test_linear_stack()
{
	cout << "*********��������ջ*********" << endl;
	linear_stack* l_stack = new linear_stack;
	if (l_stack)
		cout << "************�����ɹ�**********" << endl;
	else
		cout << "**************����ʧ��***********" << endl;


	cout << "\n***************������ջ****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	bool get = false;
	cout << "��������������"; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "�������" << i + 1 << "�����ݣ�"; cin >> data;
		if (!l_stack->Push(data))
			cout << "��ջʧ��" << endl;
	}
	cout << "��ǰջ�Ĵ�С��" << l_stack->size << endl;
	cout << "��ǰջ��Ԫ�أ�" << l_stack->Top(get) << endl;
	cout << "**************�������****************" << endl;

	cout << "\n***************���Գ�ջ***************" << endl;
	cout << "��ջԪ�أ�";
	size = l_stack->size;
	for (i = 0; i < size; i++)
	{
		cout << l_stack->Top(get) << " ";
		l_stack->Pop();
	}
	cout << "\n*****************�������*****************" << endl;

	cout << "\n**************�������*************" << endl;
	l_stack->Clear();
	if (l_stack->IsEmpty())
	{
		cout << "�����" << endl;
	}
	else
		cout << "���ʧ��" << endl;
	cout << "*****************�������*****************" << endl;

}

static void test_linked_stack()
{
	cout << "*********������ջ*********" << endl;
	link_stack* LinkStack = new link_stack;
	if (LinkStack)
		cout << "************�����ɹ�**********" << endl;
	else
		cout << "**************����ʧ��***********" << endl;


	cout << "\n***************������ջ****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	cout << "��������������"; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "�������" << i + 1 << "�����ݣ�"; cin >> data;
		if (!LinkStack->Push(data))
			cout << "��ջʧ��" << endl;
	}
	cout << "��ǰջ�Ĵ�С��" << LinkStack->head->data << endl;
	if (LinkStack->Top())
		cout << "��ǰջ��Ԫ�أ�" << LinkStack->Top()->data << endl;
	cout << "**************�������****************" << endl;


	cout << "\n***************���Գ�ջ***************" << endl;
	cout << "��ջԪ�أ�";
	size = LinkStack->head->data;
	for (i = 0; i < size; i++)
	{
		if (LinkStack->Top())
			cout << LinkStack->Top()->data << " ";
		if (!LinkStack->Pop())
			cout << "��ջʧ��" << endl;
	}
	cout << "\n*****************�������*****************" << endl;

	cout << "\n**************�������*************" << endl;
	LinkStack->Clear();
	if (LinkStack->IsEmpty())
	{
		cout << "�����" << endl;
	}
	else
		cout << "���ʧ��" << endl;
	cout << "*****************�������*****************" << endl;

	cout << "\n***************��������************" << endl;
	LinkStack->Destroy();
	if (!LinkStack->head)
		cout << "���ٳɹ�" << endl;
	else
		cout << "����ʧ��" << endl;
	cout << "*****************�������*****************" << endl;

}

static void test_linear_queue()
{
	cout << "*********�������Զ�*********" << endl;
	linear_queue* LinearQueue = new linear_queue;
	if (LinearQueue)
		cout << "************�����ɹ�**********" << endl;
	else
		cout << "**************����ʧ��***********" << endl;


	cout << "\n***************�������****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	bool get = false;
	cout << "��������������"; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "�������" << i + 1 << "�����ݣ�"; cin >> data;
		if (!LinearQueue->Push(data))
			cout << "���ʧ��" << endl;
	}
	cout << "��ǰ�ӵĴ�С��" << LinearQueue->size << endl;
	cout << "��ǰ��ͷԪ�أ�" << LinearQueue->Front(get) << endl;
	cout << "��ǰ��βԪ�أ�" << LinearQueue->Rear(get) << endl;
	cout << "**************�������****************" << endl;

	cout << "\n***************���Գ���***************" << endl;
	cout << "����Ԫ�أ�";
	size = LinearQueue->size;
	for (i = 0; i < size; i++)
	{
		cout << LinearQueue->Front(get) << " ";
		LinearQueue->Pop();
	}
	cout << "\n*****************�������*****************" << endl;

	cout << "\n**************�������*************" << endl;
	LinearQueue->Clear();
	if (LinearQueue->IsEmpty())
	{
		cout << "�����" << endl;
	}
	else
		cout << "���ʧ��" << endl;
	cout << "*****************�������*****************" << endl;
}

static void test_linked_queue()
{
	cout << "*********��������*********" << endl;
	linked_queue* LinkQueue = new linked_queue;
	if (LinkQueue)
		cout << "************�����ɹ�**********" << endl;
	else
		cout << "**************����ʧ��***********" << endl;


	cout << "\n***************�������****************" << endl;
	int count = 0, i = 0, data = 0, size = 0;
	cout << "��������������"; cin >> count;
	for (i = 0; i < count; i++)
	{
		cout << "�������" << i + 1 << "�����ݣ�"; cin >> data;
		if (!LinkQueue->Push(data))
			cout << "���ʧ��" << endl;
	}
	cout << "��ǰ�ӵĴ�С��" << LinkQueue->size << endl;
	if (LinkQueue->Front() && LinkQueue->Rear())
	{
		cout << "��ǰ��ͷԪ�أ�" << LinkQueue->Front()->data << endl;
		cout << "��ǰ��βԪ�أ�" << LinkQueue->Rear()->data << endl;
	}
	cout << "**************�������****************" << endl;

	cout << "\n***************���Գ���***************" << endl;
	cout << "����Ԫ�أ�";
	size = LinkQueue->size;
	for (i = 0; i < size; i++)
	{
		cout << LinkQueue->Front()->data << " ";
		LinkQueue->Pop();
	}
	cout << "\n*****************�������*****************" << endl;

	cout << "\n**************�������*************" << endl;
	LinkQueue->Clear();
	if (LinkQueue->IsEmpty())
	{
		cout << "�����" << endl;
	}
	else
		cout << "���ʧ��" << endl;
	cout << "*****************�������*****************" << endl;
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