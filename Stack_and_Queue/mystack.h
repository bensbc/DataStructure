#pragma once
#include<iostream>
using namespace std;
#define DataType int
#define SIZE     100

// 线性栈
class linear_stack
{
public:
	DataType data[SIZE];   // 数据域
	int size;              // 当前栈的大小
	int top_index;         // 栈顶指针

	linear_stack();        // 无参构造
	bool Push(DataType data);           // 入栈
	bool Pop();            // 出栈
	bool IsEmpty() const;        // 判断栈空
	DataType Top(bool&get) const;        // 获取栈顶元素
	void Clear();          // 清空栈
};


//结点
typedef struct stack_node
{
	DataType data;        // 数据域
	stack_node* next;     // 连接指针
}stack_node;

// 链栈
class link_stack
{
public:
	int size;
	stack_node* head;    // 头结点
	link_stack();        // 初始化
	bool Push(DataType data);         //入栈
	bool Pop();          // 出栈
	bool IsEmpty() const;      // 判断栈空
	stack_node* Top() const;        // 获取栈顶元素
	void Clear();          // 清空栈
	void Destroy();        // 销毁栈
};