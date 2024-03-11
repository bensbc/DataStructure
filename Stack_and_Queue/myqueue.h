#pragma once
#include"mystack.h"
#include<memory.h>
// 线性队
class linear_queue
{
public:
	DataType data[SIZE];   // 数据域
	int front_index;       // 队头指针
	int rear_index;        // 队尾指针
	int size;              // 队列大小

	linear_queue();        // 无参构造
	bool Push(DataType data);     // 入队
	bool Pop();            // 出队
	DataType Front(bool& get) const;  //获取队头元素
	DataType Rear(bool& get) const;   // 获取队尾元素
	bool IsEmpty() const;        // 判断队空
	void Clear();          // 清空队列
};


// 队列结点
typedef struct queue_node
{
	DataType data;     // 数据域
	queue_node* next;  // 连接指针
}queue_node;

// 链队
class linked_queue
{
public:
	queue_node* front;   // 队头指针
	queue_node* rear;    // 队尾指针
	int size;            // 队列大小

	linked_queue();      // 无参构造
	bool Push(DataType data);     // 入队
	bool Pop();                   // 出队
	queue_node* Front() const;   //获取队头元素
	queue_node* Rear() const;    // 获取队尾元素
	bool IsEmpty() const;        // 判断队空
	void Clear();          // 清空队列
};