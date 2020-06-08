/*******************************
  Name: Alec Guilin
  Date: 11/2/19
  CS 433 Assignment 3
 *******************************/

#include <iostream>
#include <string>
#include "simulation.h"
using namespace std;

// function prototypes
void userInput(Simulation &DES, int argc, char * argv[]);
void prompt(Simulation &DES, int argc, char * argv[]);

// PURPOSE: tests the simulation
// PARAMETERS: argc = number of arguments
//			   argv[] = arguments passed
int main(int argc, char * argv[])
{
	cout << "---------------------------------------------\n";
	cout << "Name: Alec Guilin\n";
	cout << "Date: 11/2/19\n";
	cout << "Assignment 3 - CPU Scheduling\n";
	cout << "---------------------------------------------\n\n";

	Simulation DES;

	userInput(DES, argc, argv);	
	DES.setup();					

	switch (DES.selection) {
	case 1: // FCFS scheduler
		DES.runFCFS();
		cout << "FCFS Stats(time shown in seconds)\n";
		DES.report();
		break;
	case 2: // SJF scheduler
		DES.runSJF();
		cout << "SJF Stats(time shown in seconds)\n";
		DES.report();
		break;
	}

	return 0;
}

// PURPOSE: if user enters no args, a prompt will ask user for required args
//			if the args are invalid, display error message and ask for required args again
// PARAMETERS: &DES = DES Simulation
//			   argc = number of arguments
//			   argv[] = arguments passed
void userInput(Simulation &DES, int argc, char * argv[])
{
	// if 2 arguments are passed
	if (argc == 3) {
		DES.amount = atoi(argv[1]);
		DES.selection = atoi(argv[2]);

		// input error
		if (DES.amount < 1 || DES.selection < 1 || DES.selection > 2) {
			cout << "*ERROR* invalid argument(s)..." << endl;
			prompt(DES, argc, argv);
		}
	}

	// if 2 arguments are not passed
	else {

		// input error
		if (argc > 3 || argc == 2) {
			cout << "*ERROR* invalid argument(s)..." << endl;
		}

		prompt(DES, argc, argv);
	}
}


// PURPOSE: prompts user for input
// PARAMETERS: &DES = DES simulation
//			   argc = number of arguments
//			   argv[] = arguments passed
void prompt(Simulation &DES, int argc, char * argv[]) {
	cout << "Enter number of processes: ";
	cin >> DES.amount;

	// input error
	while (DES.amount < 1 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "*ERROR* enter again: ";
		cin >> DES.amount;
	}
	cout << endl;

	cout << "Select scheduler type" << endl;
	cout << "1: FCFS" << endl;
	cout << "2: SJF" << endl;
	cout << ">> ";
	cin >> DES.selection;

	// input error
	while (DES.selection < 1 || DES.selection > 2 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "*ERROR* enter again: ";
		cin >> DES.selection;
	}
	cout << endl;
}
