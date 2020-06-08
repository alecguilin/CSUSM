#pragma once
#include <vector>

//data structure for a page
struct pageEntry 
{
	int address;
	bool dirty;
	bool valid;
	int last; //needed for lru algorithm

	//defualt constructor
	pageEntry() 
	{
		address = 0;
		dirty = false;
		valid = false;
		last = 0;
	}

	//constructor to create page entry
	pageEntry(int a, bool d, bool v, int l) 
	{
		address = a;
		dirty = d;
		valid = v;
		last = l;
	}
};

//data structure for paging simulator
class simulation
{
public:
	std::vector<pageEntry> page_table;	//table for page entries
	int pagesize;	//size of a page
	int memorysize;	//total memory size
	int selection;	//algorithm selected by user
	int currentline; //counter used for fifo
	int linecounter; //counter used in lru
	int totalpagefaults; //number of pages not found in page table
	int totalreferences; //number of references processed
	int totalflushes; //number of victim pages marked as dirty
	int totalreplacements; //number of page replacements
	double elapsed;	//total time of simulation

	simulation();
	void report();
	int search(int value);
	void setup(int size);

	//paging algorithms
	void LRU(pageEntry &p);	//lru algorithm
	void FIFO(pageEntry &p); //fifo alogirth
	void Random(pageEntry &p);
};