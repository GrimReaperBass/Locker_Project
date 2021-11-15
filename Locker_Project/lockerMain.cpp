//-------------------------------------------------------------
// Sebastian Rodriguez
// Agorithms Project
// lockerMain.cpp
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
//#include <cctype>

using namespace std;

//Function prototypes
void lockerProgress(const int lockerNumber, vector<bool> &locker, const int size);		//Runs through and completes the process of opening and closing lockers with displayed outputs
void lockerCompletion(const int lockerNumber, vector<bool> &locker, const int size);	//Runs through and completes the process of opening and closing lockers without displayed outputs
void displayLockers(vector<bool>& locker, const int size);								//Displays list of lockers and their status via open/close
void displayOpenLocker(vector<bool> &locker, const int size);							//Displays locker number of open lockers
void displayCloseLocker(vector<bool>& locker, const int size);							//Displays locker number of close lockers

int main()
{
	int lockerCount; //The number of elements the vector will have
	char showPaths;  //To know if the user wants to see each student go through the vector of lockers

	cout << "Amount of lockers in the school? (Ctrl Z to exit) ";

	while (cin >> lockerCount)
	{
		lockerCount++; //Do not wish to use the 0 element in the vector because of how lockerProgress and lockerCompletion works in incrementation
		vector<bool> lockerList;

		for (int i = 1; i <= lockerCount; i++)
			lockerList.push_back(false);

		cout << "\nShow locker progress? Y/N  ";
		cin >> showPaths;
		showPaths = toupper(showPaths);

		if (showPaths == 'Y')
			{
			cout << endl;

				for (int i = 1; i < lockerList.size(); i++)
					lockerProgress(i, lockerList, lockerCount);

				displayCloseLocker(lockerList, lockerCount);
				cout << endl;

				displayOpenLocker(lockerList, lockerCount);
				cout << endl;
			}
		else if (showPaths == 'N')
		{
			cout << "\nStudents quickly go through the lockers!\n";

			for (int i = 1; i < lockerList.size(); i++)
				lockerCompletion(i, lockerList, lockerCount);

			displayLockers(lockerList, lockerCount);
			cout << endl;

			displayCloseLocker(lockerList, lockerCount);
			cout << endl;

			displayOpenLocker(lockerList, lockerCount);
			cout << endl;

			system("PAUSE");
		}

		cout << "\nAmount of lockers in the next school? (Ctrl Z to exit) ";
	}
	return 0;
}

//Function definitions
void lockerProgress(int lockerNumber, vector<bool> &locker, const int size)
{
	//Lets the user see what "student" is going through the lockers on each loop
	cout << "Student " << lockerNumber << " goes through" << endl;

	//Key portion as the loops starts and increments by the lockerNumber; If set to 0, would be infinite
	for (int i = lockerNumber; i < size; i += lockerNumber) 
	{
		if (locker[i] == true)
			locker[i] = false;
		else
			locker[i] = true;
	}

	//Uses displayLockers() and pause to allow each step to be shown without moving too fast for user to see
	displayLockers(locker, size);

	cout << endl << endl;
	system("PAUSE");
	cout << endl;
}

void lockerCompletion(const int lockerNumber, vector<bool> &locker, const int size)
{
	//Key portion as the loops starts and increments by the lockerNumber; If set to 0, would be infinite
	for (int i = lockerNumber; i < size; i += lockerNumber)
	{
		if (locker[i] == true)
			locker[i] = false;
		else
			locker[i] = true;
	}
}

void displayLockers(vector<bool>& locker, const int size)
{
	for (int i = 1; i < size; i++)
	{
		//[  ] means "open" and [[]] means closed
		if (locker[i] == true)
			cout << "[ " << setw(3) << i << " ] ";
		else
			cout << "[[" << setw(3) << i << "]] ";

		//Used to keep 10 elements per line
		if (i % 10 == 0)
			cout << endl;
		else if (i == (size - 1) && i % 10 != 0)
			cout << endl;
	}
}

void displayOpenLocker(vector<bool>& locker, const int size)
{
	int count{ 0 }; //Counter for display output and number of open lockers

	//Section Header to ensure what the following locker numbers mean for user
	for (int i = 1; i <= 80; i++)
		cout << "-";
	cout << endl;

	cout << right << setw(48) << "Lockers Left Open" << endl;

	for (int i = 1; i <= 80; i++)
		cout << "-";
	cout << endl;

	//Searches vector for lockers that are "open"
	for (int i = 1; i < size; i++)
	{
		if (locker[i] == true)
		{
			cout << "| Locker " << left << setw(5) << i << " |";
			count++;

			if (count %5 == 0 && i != size -1)
				cout << endl;
			else if (i == (size - 1) && i % 5 != 0)
				cout << endl;
		}
	}

	cout << "\n\n* Number of Open Lockers: " << count << " *" << endl;
}

void displayCloseLocker(vector<bool>& locker, const int size)
{
	int count{ 0 }; //Counter for display output

	//Section Header to ensure what the following locker numbers mean for user
	for (int i = 1; i <= 80; i++)
		cout << "-";
	cout << endl;

	cout << right << setw(49) << "Lockers Left Closed" << endl;

	for (int i = 1; i <= 80; i++)
		cout << "-";
	cout << endl;

	//Searches vector for lockers that are "closed"
	for (int i = 1; i < size; i++)
	{
		if (locker[i] == false)
		{
			cout << "| Locker " << left << setw(5) << i << " |";
			count++;

			if (count % 5 == 0 && i != size-1)
				cout << endl;
			else if (i == (size - 1) && i % 5 != 0)
				cout << endl;
		}
	}
}