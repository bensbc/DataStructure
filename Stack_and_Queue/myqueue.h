#pragma once
#include"mystack.h"
#include<memory.h>
// ���Զ�
class linear_queue
{
public:
	DataType data[SIZE];   // ������
	int front_index;       // ��ͷָ��
	int rear_index;        // ��βָ��
	int size;              // ���д�С

	linear_queue();        // �޲ι���
	bool Push(DataType data);     // ���
	bool Pop();            // ����
	DataType Front(bool& get) const;  //��ȡ��ͷԪ��
	DataType Rear(bool& get) const;   // ��ȡ��βԪ��
	bool IsEmpty() const;        // �ж϶ӿ�
	void Clear();          // ��ն���
};


// ���н��
typedef struct queue_node
{
	DataType data;     // ������
	queue_node* next;  // ����ָ��
}queue_node;

// ����
class linked_queue
{
public:
	queue_node* front;   // ��ͷָ��
	queue_node* rear;    // ��βָ��
	int size;            // ���д�С

	linked_queue();      // �޲ι���
	bool Push(DataType data);     // ���
	bool Pop();                   // ����
	queue_node* Front() const;   //��ȡ��ͷԪ��
	queue_node* Rear() const;    // ��ȡ��βԪ��
	bool IsEmpty() const;        // �ж϶ӿ�
	void Clear();          // ��ն���
};