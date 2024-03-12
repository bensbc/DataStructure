#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

#define MAXSIZE 100
#define DataType int 

// ˳���ṹ��
typedef struct SqList
{
	DataType Data[MAXSIZE];   // ���ڴ�����ݵ�����
	int length;               // ��Ч����
}SqList;

//��ʼ��˳���
static SqList* InitSqList()
{
	SqList* L = (SqList*)malloc(sizeof(SqList));
	if (!L)
		return NULL;
	// ��ʼ����Ч����
	L->length = 0;
	// ����ָ��ѿռ��ָ��
	return L;
}

//����Ԫ��
static int Insert(SqList* L, int  pos, DataType data)
{
	int i = pos - 1, k = L->length - 1;   // Ŀ��λ�õ��±�  �������һ��Ԫ�ص��±�

	if (L->length == MAXSIZE || pos > MAXSIZE || pos < 1)
		return 0;    //�޷�����

	// ��ԭ����pos�Լ��Ժ��Ԫ�غ���һλ
	// ���������Ԫ�ؿ�ʼ�ƶ����������ݻᶪʧ
	for (k = L->length - 1; k >= i; k--)
		L->Data[k + 1] = L->Data[k];

	// ��������
	L->Data[i] = data;
	// ������Ч����
	L->length++;

	//����ɹ�
	return 1;
}

//���˳����е�����Ԫ��
static void PrintSqList(SqList* L)
{
	if (L->length == 0)
	{
		printf("����Ϊ��\n");
		return;
	}

	int i = 0;
	while (i < L->length)
	{
		cout << L->Data[i]<<" ";
		i++;
	}
	puts("");
}


//���ر�
static int getLength(SqList* L)
{
	return L->length;
}

//�жϱ��Ƿ�Ϊ��
static int IsEmpty(SqList* L)
{
	if (!L)
	{
		printf("ָ��δָ��ѿռ�\n");
		return 1;
	}

	if (L->length == 0)
		return 1;

	return 0;

}

//����˳���ĳһλ�õ�Ԫ��
static DataType* getElem(SqList* L, int pos)
{
	if (pos<1 || pos>L->length)
	{
		printf("λ������\n");
		
		return nullptr;
	}
	
	return &(L->Data[pos - 1]);

}

//����ؼ��ֵ�λ��
static int Locate(SqList* L, DataType data)
{
	int i = 0;
	// ����
	for (; i < L->length; i++)
		if (L->Data[i] == data)
			return i + 1;

	//δ�ҵ���Ԫ��
	return 0;

}

//ɾ��ĳһλ���ϵ�Ԫ��
static int DeleteElem(SqList* L, int pos)
{
	if (pos<1 || pos>L->length)
		return 0;   //λ������ 

	int i = pos - 1;
	// �ú����Ԫ�����θ���ǰһ��Ԫ��
	// ����ӵ�ǰԪ�ػ��һ��Ԫ�ؿ�ʼ
	for (; i < L->length; i++)
		L->Data[i] = L->Data[i + 1];
	// ������Ч����
	L->length--;

	//ɾ���ɹ�
	return 1;

}

//�ͷ�˳���
static bool DestroySqList(SqList** L)
{
	if(*L != NULL)
		free(*L);

	*L = NULL;
	return true;
}

// �޸�˳���
// ָ��λ���޸�
static bool Modify_By_Location(SqList* L,int location,DataType value)
{
	DataType* val = getElem(L, location);
	if (val)
	{
		*val = value;
		return true;
	}
	else
		return false;
}

// ָ��Ԫ���޸ģ��޸����У�
static bool Modify_By_Value(SqList* L,DataType value, DataType exchanger)
{
	if (Locate(L, value))
	{
		for (int i = 0; i < L->length; i++)
		{
			if (L->Data[i] == value)
				L->Data[i] = exchanger;
		}
		return true;
	}
	else
		return false;
}

static void test_sqlist()
{
	// ����˳�����ʼ��
	cout << "����˳������г�ʼ��" << endl;
	SqList* L = InitSqList();
	cout << "���" << endl;

	// ����Ԫ��
	cout << endl << "����Ԫ�ز����˳���" << endl;
	Insert(L, 1, 134);
	Insert(L, 2, 34);
	Insert(L, 3, 9);
	Insert(L, 4, 12);
	Insert(L, 5, 175);
	// ���˳��� 
	PrintSqList(L);
	//�ж�˳����Ƿ�Ϊ�� 
	cout << "�ж�˳����Ƿ�Ϊ��: ";
	if (IsEmpty(L))
		printf("˳���Ϊ��\n");
	else
		printf("˳���Ϊ��\n");
	// ���˳���ĳ���
	printf("��ǰ˳���ĳ���Ϊ��");
	printf("%d\n", getLength(L));

	// ���λ��Ϊ3��Ԫ��
	cout << "----���԰�λ��Ѱ��Ԫ��----" << endl;
	if (getElem(L, 3))
		printf("λ��Ϊ3��Ԫ��Ϊ��%d\n", *getElem(L, 3));
	else
		cout << "�޷���ȡ" << endl;
	cout << "----�������----" << endl;


	// ���175��λ��
	cout << endl << "----����Ѱ��ָ��Ԫ�ص�λ��----" << endl;
	if(Locate(L,175))
		printf("Ԫ��175��λ��:%d\n", Locate(L, 175));
	cout << "----�������----" << endl;


	// �ڵ�һ��λ���ϲ���Ԫ��86
	cout << endl << "----���Բ���Ԫ��----" << endl;
	if (Insert(L, 1, 86))
	{
		printf("�ڵ�һ��λ���ϲ���Ԫ��86�ɹ�����ǰ��˳���Ϊ");
		PrintSqList(L);
	}
	else
		printf("���벻�ɹ�\n");
	cout << "----�������----" << endl;



	// ɾ��������Ԫ��
	cout << endl << "-----����ɾ��Ԫ��-----" << endl;
	if (!DeleteElem(L, 3))
		printf("������λ���ϵ�Ԫ��ɾ��ʧ��\n");
	else
	{
		printf("������Ԫ��ɾ���ɹ�����ǰ˳���Ϊ");
		PrintSqList(L);
	}
	cout << "----�������----" << endl;



	cout << "\n**************�����޸�Ԫ��***************" << endl;
	cout << "���԰�λ���޸�" << endl;
	cout << "������Ҫ�޸ĵ�ֵ��λ�ã�";
	int location; cin >> location;
	cout << "�������µ�ֵ��";
	int value; cin >> value;
	if (Modify_By_Location(L, location, value))
		cout << "�޸ĳɹ�" << endl;
	else
		cout << "�޸�ʧ��" << endl;
	cout << "��ǰ��˳���Ϊ��";
	PrintSqList(L);


	cout << "���԰�ֵ�޸�" << endl;
	cout << "������Ҫ�޸ĵ�ֵ��";
	cin >> location;
	cout << "�������µ�ֵ��";
	cin >> value;
	if (Modify_By_Value(L, location, value))
		cout << "�޸ĳɹ�" << endl;
	else
		cout << "�޸�ʧ��" << endl;

	cout << "��ǰ��˳���Ϊ��";
	PrintSqList(L);

	cout << "************�������*************" << endl;



	//�ͷ�˳���
	cout << "-----�����ͷ�˳���-----" << endl;
	DestroySqList(&L);
	if (IsEmpty(L))
		printf("˳�������գ��ռ��ͷųɹ�\n");
	else
		printf("�ͷ�ʧ�ܣ�\n");
	cout << "----�������----" << endl;
}

