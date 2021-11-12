#include "Data.h"

Data::Data(int newRecord, int newID, std::string newName,
	std::string newEmail, std::string newUnits,
	std::string newProgram, std::string newLevel)
{
	this->recordNumber = newRecord;
	this->IDNumber = newID;
	this->name = newName;
	this->email = newEmail;
	this->units = newUnits;
	this->program = newProgram;
	this->level = newLevel;
	this->absencesCount = 0;
	this->absencesStack = new Stack;
}

Data::~Data()
{
	delete this->absencesStack;
}

bool Data::setRecord(int newRecord)
{
	bool result = false;
	if (newRecord < 999 && newRecord > 0)
	{
		this->recordNumber = newRecord;
		result = true;
	}
	return result;
}

int Data::getRecord()
{
	return this->recordNumber;
}

bool Data::setID(int newID)
{
	bool result = false;
	if (newID < 999999999 && newID > 0)
	{
		this->IDNumber = newID;
		result = true;
	}
	return result;
}

int Data::getID() const
{
	return this->IDNumber;
}

void Data::setName(std::string newName)
{
	this->name = newName;
}

std::string Data::getName() const
{
	return this->name;
}

void Data::setEmail(std::string newEmail)
{
	this->email = newEmail;
}

std::string Data::getEmail()
{
	return this->email;
}

void Data::setUnits(std::string newUnits)
{
	this->units = newUnits;
}

std::string Data::getUnits()
{
	return this->units;
}

void Data::setProgram(std::string newProgram)
{
	this->program = newProgram;
}

std::string Data::getProgram()
{
	return this->program;
}

void Data::setLevel(std::string newLevel)
{
	this->level = newLevel;
}

std::string Data::getLevel()
{
	return this->level;
}

bool Data::addAbsence(std::string newDate)
{
	bool result = false;
	if (absencesCount != 99)
	{
		this->absencesCount++;
		result = this->absencesStack->push(newDate);
	}
	return result;
}

int Data::getAbsenceCount()
{
	return this->absencesCount;
}

Stack* Data::getAbsenceDates()
{
	return this->absencesStack;
}

bool operator==(const Data& data, const std::string& compare)
{
	bool result = false;
	if (data.getName() == compare)
	{
		result = true;
	}
	if (std::to_string(data.getID()) == compare)
	{
		result = true;
	}
	return result;
}

bool Data::removeAbsence(string date)
{
	bool found = this->absencesStack->removeDate(date);
	if (found) this->absencesCount--;
	return found;
}