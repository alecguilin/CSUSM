/*******************************
  Name: Alec Guilin
  Date: 12/7/18
  CS 433 Assignment 5
 *******************************/
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>	
#include "simulation.h"
using namespace std;

//function prototypes
void prompt(simulation &);
void handleargs(int, simulation &);

int main(int argc, char *argv[])
{
	cout << "-----------------------------------------------\n";
	cout << "Alec Guilin\n";
	cout << "December 7 2018\n";
	cout << "CS433 Assignment 5\n";
	cout << "-----------------------------------------------\n\n";

	simulation sim;
	sim.pagesize = atoi(argv[1]); //arg 1
	sim.memorysize = atoi(argv[2]); //arg 2

	//argument error handling
	handleargs(argc, sim);

	//prompts user for algorithm selection
	prompt(sim);

	//initialize page table
	int size = sim.memorysize / sim.pagesize;
	sim.setup(size);

	//start simulation timer
	auto begin = std::chrono::high_resolution_clock::now(); 

	//read file until the entire file is read
	ifstream file("references.txt");
	string line;

	while (file >> line) 
	{
		int value = stoi(line);
		int lastdigit = value % 10;	//extracts the last digit from value
		bool bit;

		//check the last digit of the line
		if (lastdigit % 2 == 1)	//if last digit is odd then set to dirty bit
			bit = true;
		else 
			bit = false; //if last digit is even

		//search for value in page_table
		int index = sim.search(value); 

		//if the location returned is not -1, then it exists in the page_table
		if (index >= 0) 
		{
			sim.page_table[index].dirty = bit;
			sim.page_table[index].last = sim.currentline;
		}

		//if the value was not found, then generate fault, and place page into page_table
		else 
		{
			pageEntry temp(value - bit, bit, true, sim.currentline);
			sim.totalpagefaults++;

			//use selected algorithm to place page into page_table
			switch (sim.selection) 
			{
			case 0:
				sim.Random(temp);
				break;
			case 1:
				sim.FIFO(temp);
				break;
			case 2:
				sim.LRU(temp);
				break;
			}
		}

		sim.totalreferences++;	//keeps track of how many lines have been parsed
	}


	//end the timer
	auto end = std::chrono::high_resolution_clock::now();
	sim.elapsed = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();

	//displays the report
	sim.report();

	return 0;
}

void prompt(simulation &sim)
{
	//algorithm selection menu
	cout << "Select Paging Algorithm:\n\n";
	cout << "0: Random\n";
	cout << "1: FIFO\n";
	cout << "2: LRU\n\n";
	cout << ">> ";
	cin >> sim.selection;

	//if user enters an invalid menu option
	while (sim.selection > 2 || sim.selection < 0) 
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error: enter again: ";
		cin >> sim.selection;
	}

	switch (sim.selection) 
	{
		case 0: cout << "Running Random Paging algorithm...\n"; 
			break;
		case 1: cout << "Running FIFO Paging algorithm...\n"; 
			break;
		case 2: cout << "Running LRU Paging algorithm...\n"; 
			break;
	}
}

void handleargs(int argc, simulation &sim)
{
	//if user enters more than the required args (2) in the commandline, then inform the user and exit program
	if (argc < 3 || argc > 3) 
	{
		cout << "Error: please run the program as follows:\n ./sim <pagesize> <memorysize> \n\n";
		exit(1);
	}
	//if user enters an invalid page size or memory size, then inform the user and exit program
	if (((sim.pagesize & (sim.pagesize - 1)) != 0 || ((sim.memorysize & (sim.memorysize - 1)) != 0))) 
	{
		cout << "Error: input needs to be a power of 2\n\n";
		exit(1);
	}
}
