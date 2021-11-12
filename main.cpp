#include "List.h"

int main()
{
	int userChoice = 0;
	string userChoiceGrabber;
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
			if (pList->importCourseList())
			{
				cout << "Course List Imported Successfully" << endl;
			}
			else cout << "Course List Import FAILED" << endl;
			break;
		case 2:
			cout << "case 2" << endl;
			break;
		case 3:
			cout << "case 3" << endl;
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
			cout << "case 6" << endl;
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