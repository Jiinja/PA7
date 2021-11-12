#include "Stack.h"

Stack::Stack()
{
	this->array = new std::string[100];
	this->top = -1;
}

Stack::~Stack()
{
	delete this->array;
}

bool Stack::push(std::string newData)
{
	bool result = false;
	if (top != 99) //if there is room
	{
		top++;
		this->array[top] = newData;
		result = true;
	}
	return result;
}

bool Stack::pop()
{
	bool result = false;
	if (top != 0)
	{
		top--;
		result = true;
	}
	return result;
}

std::string Stack::peak()
{
	return this->array[this->top];
}

bool Stack::isEmpty()
{
	return (top == 0);
}

bool Stack::removeDate(string date)
{
	bool found = false;
	for (int i = 0; i <= this->top; i++)
	{
		if (this->array[i] == date)
		{
			found = true;
		}
		if (found)
		{
			array[i] = array[i + 1];
		}
	}
	return found;
}