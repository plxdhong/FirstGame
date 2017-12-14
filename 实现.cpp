#include "БъЭЗ.h"
#include <cstdlib>

void Customer::set_time(long when)
{
	ptime = std::rand() % 3 + 1;
	arrive = when;
}

Queue::Queue(int qs):qsize(qs)
{
	first = last = NULL;
	number = 0;

}

Queue::~Queue()
{
	Node * temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}

}
bool Queue::isempty() const
{
	if (number == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Queue::isfull() const
{
	if (number == qsize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Queue::queuecount() const 
{
	return number;
}
bool Queue::enqueue(const Customer &item)
{
	if (isfull())
	{
		return false;
	}
	Node * add = new Node;
	add->customer = item;
	add->next = NULL;
	number++;
	if (first == NULL)
	{
		first = NULL;
	}
	else
		last->next = add;
	last = add;
	return true;
}
bool Queue::dequeue(Customer &item)
{
	if (first == NULL)
	{
		return false;
	}
	item = first->customer;
	number--;
	Node *temp = first;
	first = first->next;
	delete temp;
	if (number == 0) { last = NULL; }
	return true;
}