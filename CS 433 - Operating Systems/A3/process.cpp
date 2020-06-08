#include <iomanip>
#include <iostream>
#include "process.h"
#include "random.h"
using namespace std;

// PURPOSE: default constructor
Process::Process()
{
	procID = 0;
	startTime = 0;
	procStatus = NEW;
	priority = 0;

	totalCPUduration = 0; 
	remainCPUduration = 0;
	avgCPUburstLength = 0; 
	nextCPUburstLength = 0;
	totalIOburstTime = 0;
	IOburstTime = 0;

	enterTime = 0;
	triggerTime = 0;

	finishTime = 0;
	waitTime = 0;
	turnAroundTime = 0;
	serviceTime = 0;
}

// PURPOSE: constructor to create a process
// PARAMETER: x = used to set the id of the process
Process::Process(int x)
{
	procID = x;
	startTime = ranInt(0, 300000); // generated between 1 millseconds to 5 mins
	procStatus = NEW;
	priority = 0;

	totalCPUduration = ranInt(1000, 60000); // generated between 1 second to 1 min
	remainCPUduration = totalCPUduration;

	avgCPUburstLength = ranInt(5, 100); // generated between 5 to 100 milliseconds
	nextCPUburstLength = 0;

	totalIOburstTime = 0;
	IOburstTime = 0;
	enterTime = 0;
	triggerTime = 0;

	finishTime = 0;
	waitTime = 0;
	turnAroundTime = 0;
	serviceTime = 0;
}

// PURPOSE: display a process info
void Process::info()
{
	cout << left << setw(7) << procID << setw(7) << priority << setw(7) << procStatus 
		<< setw(7) << startTime << setw(7) << remainCPUduration << setw(7) << totalCPUduration 
		<< setw(7) << avgCPUburstLength << setw(7) << nextCPUburstLength << setw(7) << IOburstTime
		<< setw(7) << finishTime << setw(7) << turnAroundTime << setw(7) << waitTime << endl;
}
