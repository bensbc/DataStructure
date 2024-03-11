#include "myqueue.h"

linear_queue::linear_queue()
{
	memset(this->data, 0, SIZE * sizeof(DataType));
	this->front_index = this->rear_index = 0;
	this->size = 0;
}

bool linear_queue::Push(DataType data)
{
	if (this->size == SIZE)
		return false;
	this->data[this->rear_index] = data;
	this->rear_index = (this->rear_index + 1) % SIZE;     // 防止指针移出数据域
	this->size++;
	return true;
}

bool linear_queue::Pop()
{
	if(!this->size)
		return false;
	this->front_index = (this->front_index + 1) % SIZE;
	this->size--;
}

DataType linear_queue::Front(bool& get) const
{
	if (!this->size)
	{
		get = false;
		return -1;
	}

	get = true;
	return this->data[this->front_index];
}

DataType linear_queue::Rear(bool& get) const
{
	if (!this->size)
	{
		get = false;
		return -1;
	}
	get = true;
	int index = this->rear_index - 1;
	if (index < 0)
		index = SIZE - 1;
	return this->data[index];
}

bool linear_queue::IsEmpty() const
{
	return this->size == 0;
}

void linear_queue::Clear()
{
	this->front_index = this->rear_index = 0;
	this->size = 0;
	memset(this->data, 0, SIZE * sizeof(DataType));
}




linked_queue::linked_queue()
{
	this->front = this->rear = nullptr;
	this->size = 0;
}

bool linked_queue::Push(DataType data)
{
	if (this->size >= SIZE)
		return false;
	
	if (this->rear == NULL)
	{
		this->rear = new queue_node;
		this->rear->data = data;
		this->rear->next = NULL;
		this->front = this->rear;
		this->size++;
		return true;
	}

	queue_node* temp = new queue_node;
	temp->data = data;
	temp->next = NULL;
	this->rear->next = temp;
	this->rear = temp;
	this->size++;
	return true;
}

bool linked_queue::Pop()
{
	if (!this->size)
		return false;
	queue_node* tmp = this->front;
	this->front = tmp->next;
	delete tmp;
	this->size--;
	return true;
}

queue_node* linked_queue::Front() const
{
	if(!this->size)
		return nullptr;
	return this->front;
}

queue_node* linked_queue::Rear() const
{
	if(!this->size)
		return nullptr;
	return this->rear;
}

bool linked_queue::IsEmpty() const
{
	return this->size == 0;
}

void linked_queue::Clear()
{
	if (this->IsEmpty())
		return;
	queue_node* tmp = this->front;
	while (tmp)
	{
		this->front = tmp->next;
		delete tmp;
		tmp = this->front;
	}
	this->front = this->rear = nullptr;
	this->size = 0;
}

