/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA7                                                            *
* Date: November 12, 2021                                                                 *
* Description: this program generates a menu and calls functions to function as intended *
******************************************************************************************/


#include "List.h"

int main()
{
	int userChoice = 0;
	int userChoice2 = 0;
	int userChoice3 = 0;
	string userChoiceGrabber;
	string userChoiceGrabber2;
	string userChoiceGrabber3;
	List<Data>* pList = new List<Data>;
	ListNode<Data>* tempSearch;
	while (userChoice != 7)
	{
		userChoice = 0;
		cout << "[1] Import course list" << endl;
		cout << "[2] Load master list" << endl;
		cout << "[3] Store master list" << endl;
		cout << "[4] Mark absences" << endl;
		cout << "[5] Edit absences" << endl;
		cout << "[6] Generate report" << endl;
		cout << "[7] Exit" << endl;

		getline(cin, userChoiceGrabber);
		try {
			userChoice = stoi(userChoiceGrabber);
		}
		catch (const std::exception& e) {}
		switch (userChoice)
		{
		case 1:
			pList->clear();
			if (pList->importCourseList())
			{
				cout << "[Course List Imported Successfully]" << endl;
			}
			else cout << "Course List Import FAILED" << endl;
			break;
		case 2:
			pList->clear();
			if (pList->loadMaster()) cout << "[Master List Loaded Successfully]";
			else cout << "[Master List Load FAILED]";
			break;
		case 3:
			if (pList->saveMaster()) cout << "[Master List Stored Successfully]";
			else cout << "[Master List Storage FAILED]";
			break;
		case 4:
			pList->markAbsences();
			break;
		case 5:
			cout << "Please type the ID number of the Student who's absences you would like to edit" << endl;
			getline(cin, userChoiceGrabber);
			tempSearch = pList->searchList(userChoiceGrabber);
			if (tempSearch != nullptr)
			{
				cout << "[Student found successfully]" << endl;
				cout << "Which absence date would you like to remove? [M/D/YEAR]" << endl;
				getline(cin, userChoiceGrabber);
				if (tempSearch->getData()->removeAbsence(userChoiceGrabber))
				{
					cout << "[Absence removed successfully]" << endl;
				}
				else cout << "Failed to remove absence on that date" << endl;
			}
			else cout << "Failed to find student" << endl;
			break;
		case 6:
			cout << "Which type of report do you want?" << endl;
			cout << "[1] Report for all students" << endl;
			cout << "[2] Report for students with more than n absences" << endl;
			std::getline(cin, userChoiceGrabber2);
			try
			{
				userChoice2 = stoi(userChoiceGrabber2);
				switch (userChoice2)
				{
				case 1:
					pList->printReport();
					break;
				case 2:
					cout << "How many absences for a student to be on the report?" << endl;
					std::getline(cin, userChoiceGrabber3);
					try
					{
						userChoice3 = stoi(userChoiceGrabber3);
						pList->printReport(userChoice3);
					}
					catch (const std::exception& e)
					{
						cout << "Please chose an integer" << endl;
					}
				}
			}
			catch (const std::exception& e) 
			{
				cout << "Please chose an integer from [1-2]" << endl;
			}
			break;
		case 7:
			break;
		default:
			cout << "Please chose an integer from [1-7]" << endl;
			break;
		}
		for (int x = 0; x < 5; x++) cout << endl;
	}
}