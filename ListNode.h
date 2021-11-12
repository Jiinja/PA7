/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA7                                                            *
* Date: November 12, 2021                                                                *
* Description: this file defines the ListNode class template							 *
******************************************************************************************/


#pragma once
#include "Data.h"

template <class T>
class ListNode
{
public:
	ListNode(T* newData);
	~ListNode();
	T* getData();
	ListNode<T>* getNextPtr();
	void setNextPtr(ListNode<T>* newNode);
private:
	T* mpData;
	ListNode<T>* mpNext;
};

template<class T>
ListNode<T>::ListNode(T* newData)
{
	this->mpData = newData;
	this->mpNext = nullptr;
}

template<class T>
ListNode<T>::~ListNode()
{
	delete this->mpData;
}

template<class T>
T* ListNode<T>::getData()
{
	return this->mpData;
}

template<class T>
ListNode<T>* ListNode<T>::getNextPtr()
{
	return this->mpNext;
}

template<class T>
void ListNode<T>::setNextPtr(ListNode<T>* newNode)
{;
	this->mpNext = newNode;
}

