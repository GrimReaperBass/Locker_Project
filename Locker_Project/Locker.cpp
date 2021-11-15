#include "Locker.h"

void lockerProgress(int lockerNumber, vector<bool>& locker, const int size)
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

void lockerCompletion(const int lockerNumber, vector<bool>& locker, const int size)
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
	}
}

void displayOpenLocker(vector<bool>& locker, const int size)
{
	//Section Header to ensure what the following locker numbers mean for user
	for (int i = 1; i <= 19; i++)
		cout << "-";
	cout << endl;

	cout << "Lockers Left Opened" << endl;

	for (int i = 1; i <= 19; i++)
		cout << "-";
	cout << endl;

	//Searches vector for lockers that are "open"
	for (int i = 1; i < size; i++)
	{
		if (locker[i] == true)
			cout << "Locker " << i << endl;
	}
}