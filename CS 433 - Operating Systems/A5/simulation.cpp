#include "simulation.h"
#include <iostream>
using namespace std;

//defualt constructor
simulation::simulation()
{
	pagesize = 0;	//size of a page
	memorysize = 0;	//total memory size
	selection = 0;	//algorithm selected by user
	currentline = 0; //counter used for fifo
	linecounter = 0; //counter used in lru
	totalpagefaults = 0; //number of pages not found in page table
	totalreferences = 0; //number of references processed
	totalreplacements = 0; //number of page replacements
	totalflushes = 0; //number of victim pages marked as dirty
	elapsed = 0.00;	//total time of simulation
}

//displays the report for the simulation
void simulation::report() {
	cout << "-------------- REPORT --------------- " << endl;
	cout << "total memory references: " << totalreferences << endl;
	cout << "total page faults: " << totalpagefaults << endl;
	cout << "total flushes: " << totalflushes << endl;
	cout << "total replacements: " << totalreplacements << endl;
	cout << "elapsed time: " << elapsed << " ms" << endl;
	cout << "--------------------------------------" << endl;
}

// PURPOSE: searches for a page in main memory
// PARAMETERS: value = value to search in table
// RETURN: index if value found, else -1
int simulation::search(int value)
{
	for (int i = 0; i < page_table.size(); i++) 
	{
		if (page_table[i].address == value) 
			return i;
		else
			return -1;
	}
}

// PURPOSE: initializes a page_table with empty pages
// PARAMETERS: size = how big to make the table
void simulation::setup(int size)
{
	for (int i = 0; i < size; i++) 
	{
		pageEntry p;
		p.address = 0;
		p.last = 0;
		p.dirty = false;
		p.valid = false;

		page_table.push_back(p);
	}
}

// PURPOSE: FIFO paging replacement algorithm
// PARAMTERS: &p = pageEntry object
void simulation::FIFO(pageEntry &p)
{
	int victim = linecounter;

	linecounter++;
	linecounter = linecounter % page_table.size();

	page_table[victim] = p; //replacement
	totalreplacements++;


	//if victim page is dirty, increment total flushes count
	if (page_table[victim].dirty == true)
		totalflushes++;
}

// PURPOSE: Random paging replacement algorithm
// PARAMTERS: &p = pageEntry object
void simulation::Random(pageEntry &p)
{
	int rand_num = rand() % page_table.size();
	int victim = rand_num;
	page_table[victim] = p;  //replacement
	totalreplacements++;

	//if victim page is dirty, increment total flushes count
	if (page_table[victim].dirty == true)
		totalflushes++;
}

// PURPOSE: LRU paging replacement algorithm
// PARAMTERS: &p = pageEntry object
void simulation::LRU(pageEntry &p)
{
	int victim;

	//page is being used
	if (page_table[linecounter].valid == false) 
	{
		victim = linecounter;
		linecounter++;
		linecounter = linecounter % page_table.size();
	}

	//its being used, so find an unused page
	else 
	{
		int index = linecounter;
		int min = currentline;

		for (int i = 0; i < page_table.size(); i++) {
			if (page_table[i].last < min) {
				index = i;
				min = page_table[i].last;
			}
		}
		victim = index;

	}

	page_table[victim] = p; //replacement
	totalreplacements++;

	//if victim page is dirty, increment total flushes count
	if (page_table[victim].dirty == true)
		totalflushes++;
}