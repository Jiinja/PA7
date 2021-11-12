#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;


class Stack
{
public:
	Stack();
	~Stack();
	bool push(std::string newData);
	bool pop();
	std::string peak();
	bool isEmpty();
	bool removeDate(string date);
private:
	std::string* array;
	int top;
};

