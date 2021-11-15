#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

enum lockerDoor { Open, Close };
template <typename L> 

class Locker
{
public:
	void lockerProgress(const int lockerNumber, vector<bool>& locker, const int size);		//Runs through and completes the process of opening and closing lockers with displayed outputs
	void lockerCompletion(const int lockerNumber, vector<bool>& locker, const int size);	//Runs through and completes the process of opening and closing lockers without displayed outputs
	void displayLockers(vector<bool>& locker, const int size);								//Displays list of lockers and their status via open/close
	void displayOpenLocker(vector<bool>& locker, const int size);							//Displays locker number of open lockers

private:
	vector<L> list;
};
