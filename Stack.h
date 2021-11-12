#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ostream;
using std::fstream;


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
	string getString();
private:
	std::string* array;
	int top;
};

std::ofstream& operator<<(std::ofstream& lhs, Stack& rhs);
std::ifstream& operator>>(std::ifstream& lhs, Stack& rhs);
