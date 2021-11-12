#pragma once
#include "ListNode.h"

template<class T>
class List
{
public:
	List();
	~List();
	ListNode<T>* searchList(std::string searchWord);
	void insert(T* newData);
	bool importCourseList();
	void markAbsences();
private:
	void deleteAtEnd();
	ListNode<T>* mpHead;
};

template<class T>
List<T>::List()
{
	this->mpHead = nullptr;
}

template<class T>
List<T>::~List()
{
	while (this->mpHead != nullptr)
	{
		this->deleteAtEnd();
	}
}

template<class T>
ListNode<T>* List<T>::searchList(std::string searchWord) //returns the found node or nullptr
{
	ListNode<T>* pSearch = this->mpHead;
	while (pSearch != nullptr && !(*(pSearch->getData()) == searchWord))
	{
		pSearch = pSearch->getNextPtr();
	}
	return pSearch;
}

template<class T>
void List<T>::insert(T* newData)
{
	ListNode<T>* newNode = new ListNode<T>(newData);
	newNode->setNextPtr(this->mpHead);
	this->mpHead = newNode;
}

template<class T>
void List<T>::deleteAtEnd()
{
	ListNode<T>* deleter = this->mpHead;
	while (deleter->getNextPtr() != nullptr)
	{
		deleter = deleter->getNextPtr();
	}
	delete deleter->getData();
	delete deleter;
}

template<class T>
bool List<T>::importCourseList()
{
	bool result = false;
	std::ifstream infile;
	infile.open("classList.csv", std::ios::in);
	if (infile.is_open())
	{
		std::string fileGrabber;
		std::string temp;
		result = true;
		std::getline(infile, fileGrabber);
		while (!infile.eof())
		{
			T* newData = new T;
			std::getline(infile, fileGrabber);
			//getting record
			temp = fileGrabber.substr(0, fileGrabber.find_first_of(','));
			fileGrabber = fileGrabber.substr(fileGrabber.find_first_of(',')+1);
			newData->setRecord(stoi(temp));

			//getting ID
			temp = fileGrabber.substr(0, fileGrabber.find_first_of(','));
			fileGrabber = fileGrabber.substr(fileGrabber.find_first_of(',')+2); // +2 because the string has ,"
			newData->setID(stoi(temp));

			//getting name
			temp = fileGrabber.substr(0, fileGrabber.find_first_of('"')); 
			fileGrabber = fileGrabber.substr(fileGrabber.find_first_of('"')+2); //+2 because string has ",
			newData->setName(temp);

			//getting email
			temp = fileGrabber.substr(0, fileGrabber.find_first_of(','));
			fileGrabber = fileGrabber.substr(fileGrabber.find_first_of(',')+1);
			newData->setEmail(temp);

			//getting Units
			temp = fileGrabber.substr(0, fileGrabber.find_first_of(','));
			fileGrabber = fileGrabber.substr(fileGrabber.find_first_of(',')+1);
			newData->setUnits(temp);

			//getting Program
			temp = fileGrabber.substr(0, fileGrabber.find_first_of(','));
			fileGrabber = fileGrabber.substr(fileGrabber.find_first_of(',')+1);
			newData->setProgram(temp);

			//getting Level
			temp = fileGrabber;
			newData->setLevel(temp);

			this->insert(newData);
		}
	}
	return result;
}

template <class T>
void List<T>::markAbsences()
{
	ListNode<T>* pMarker = this->mpHead;
	std::string lineGrabber;
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	std::string date = std::to_string(now->tm_mon + 1) + "/" + std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_year + 1900);
	cout << date;
	while (pMarker != nullptr)
	{
		cout << "Is " << pMarker->getData()->getName() << " absent today? [Y/N]" << endl;
		getline(cin, lineGrabber);
		if (lineGrabber.substr(0, 1) == "Y" || lineGrabber.substr(0, 1) == "y")
		{
			pMarker->getData()->addAbsence(date);
		}
		pMarker = pMarker->getNextPtr();
	}
}

