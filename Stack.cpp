/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA7                                                            *
* Date: November 12, 2021                                                                *
* Description: this file defines all methods for the Stack class						 *
******************************************************************************************/

#include "Stack.h"

Stack::Stack()
{
	this->array = new std::string[100];
	this->top = -1;
}

Stack::~Stack()
{
	//delete this->array;
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
	if (top == -1) return "N/A";
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
	if (found) this->top--;
	return found;
}

string Stack::getString()
{
	string result = "";
	for (int i = 0; i <= top; i++)
	{
		result = ("," + this->array[i]) + result;
	}
	result = (std::to_string(this->top + 1) + result);
	return result;
}

std::ofstream& operator<<(std::ofstream& lhs, Stack& rhs)
{
	lhs << rhs.getString();
	return lhs;
}

std::ifstream& operator>>(std::ifstream& lhs, Stack& rhs)
{
	int num;
	string line;
	lhs >> line;
	num = stoi(line.substr(0, line.find_first_of(",")));
	line = line.substr(line.find_first_of(",")+1);
	for (int i = 0; i < num-1; i++)
	{
		rhs.push(line.substr(0, line.find_first_of(",")));
		line = line.substr(line.find_first_of(",")+1);
	}
	if (num > 0)
	{
		rhs.push(line);
	}
	return lhs;
}