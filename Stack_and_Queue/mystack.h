#pragma once
#include<iostream>
using namespace std;
#define DataType int
#define SIZE     100

// ����ջ
class linear_stack
{
public:
	DataType data[SIZE];   // ������
	int size;              // ��ǰջ�Ĵ�С
	int top_index;         // ջ��ָ��

	linear_stack();        // �޲ι���
	bool Push(DataType data);           // ��ջ
	bool Pop();            // ��ջ
	bool IsEmpty() const;        // �ж�ջ��
	DataType Top(bool&get) const;        // ��ȡջ��Ԫ��
	void Clear();          // ���ջ
};


//���
typedef struct stack_node
{
	DataType data;        // ������
	stack_node* next;     // ����ָ��
}stack_node;

// ��ջ
class link_stack
{
public:
	int size;
	stack_node* head;    // ͷ���
	link_stack();        // ��ʼ��
	bool Push(DataType data);         //��ջ
	bool Pop();          // ��ջ
	bool IsEmpty() const;      // �ж�ջ��
	stack_node* Top() const;        // ��ȡջ��Ԫ��
	void Clear();          // ���ջ
	void Destroy();        // ����ջ
};