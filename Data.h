/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA7                                                            *
* Date: November 12, 2021                                                                *
* Description: this file defines the Data class											 *
******************************************************************************************/


#pragma once
#include "Stack.h"
class Data
{
public:
	Data(int newRecord = -1, int newID = -1, std::string newName = "N/A", 
		std::string newEmail = "N/A", std::string newUnits = "N/A", 
		std::string newProgram = "N/A", std::string newLevel = "N/A");
	~Data();
	bool setRecord(int newRecord);
	int getRecord();
	bool setID(int newID);
	int getID() const;
	void setName(std::string newName);
	std::string getName() const;
	void setEmail(std::string newEmail);
	std::string getEmail();
	void setUnits(std::string newUnits);
	std::string getUnits();
	void setProgram(std::string newProgram);
	std::string getProgram();
	void setLevel(std::string newLevel);
	std::string getLevel();
	bool addAbsence(std::string newDate);
	int getAbsenceCount();
	void setAbsenceCount(int num);
	Stack* getAbsenceDates();
	bool removeAbsence(string date);

	friend bool operator==(const Data& data, const std::string &compare);

private:
	int recordNumber;
	int IDNumber;
	int absencesCount;
	std::string name;
	std::string email;
	std::string units;
	std::string program;
	std::string level;	
	Stack *absencesStack;
};

std::ofstream& operator<<(std::ofstream& lhs, Data& rhs);
std::ifstream& operator>>(std::ifstream& lhs, Data& rhs);

