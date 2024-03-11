#include "mystack.h"

linear_stack::linear_stack()
{
	this->size = 0;
	this->top_index = -1;
	this->data[0] = { 0 };
}

bool linear_stack::Push(DataType data)
{
	if (this->size == SIZE)   // 达到最大容量
		return false;

	// 移动栈顶指针后再插入元素
	this->data[++this->top_index] = data;
	this->size++;
	return true;
}

bool linear_stack::Pop()
{
	if (this->size == 0)
		return false;

	this->top_index--;
	this->size--;
	return true;
}

bool linear_stack::IsEmpty() const
{
	return this->size == 0;
}

DataType linear_stack::Top(bool& get) const
{
	if (IsEmpty())
	{
		get = false;
		return -1;
	}
	get = true;
	return this->data[this->top_index];
}

void linear_stack::Clear()
{
	this->size = 0;
	this->top_index = -1;
}



link_stack::link_stack()
{
	// 创建头结点
	this->head = new stack_node;
	head->next = nullptr;
	head->data = 0;
}

bool link_stack::Push(DataType data)
{
	if (this->head->data >= SIZE)  // 达到设定的最大值
		return false;

	stack_node* temp = new stack_node;
	temp->data = data;
	temp->next = this->head->next;
	this->head->next = temp;

	this->head->data++;

	return true;
}

bool link_stack::Pop()
{
	if (!head || !head->next)
		return false;
	stack_node* tmp = head->next;
	head->next = tmp->next;
	delete tmp;
	head->data--;
	return true;
}

bool link_stack::IsEmpty() const
{
	return this->head->data == 0;
}

stack_node* link_stack::Top() const
{
	if(!this->head )
		return nullptr;
	return this->head->next;
}

void link_stack::Clear()
{
	if (!this->head)
		return;
	stack_node* cur = head->next;
	while (cur)
	{
		head->next = cur->next;
		delete cur;
		cur = head->next;
	}
	head->data = 0;
}

void link_stack::Destroy()
{
	if (head)
	{
		this->Clear();
		delete head;
		head = nullptr;
	}
	
}


