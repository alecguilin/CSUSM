#pragma once

// enum for process status
enum status_t { NEW, RUNNING, READY, WAITING, TERMINATED };

// implementation of a cpu process
class Process {
public:
	int procID;					// process ID
	int priority;				// process priority
	status_t procStatus;		// process state

	int startTime;				// process arrival time
	int finishTime;				// process finish time
	int waitTime;				// process wait time
	int turnAroundTime;			// process turn around time
	int serviceTime;			// process service time

	int totalCPUduration;		// total CPU duration
	int remainCPUduration;		// remaining CPU duration
	int avgCPUburstLength;		// avg burst length used for next burst length
	int nextCPUburstLength;		// predicted next cpu burst

	int totalIOburstTime;		// total time spent in io
	int IOburstTime;			// burst time for io

	int enterTime;				// the time the process entered the ready queue
	int triggerTime;			// the time the process was dispatched from ready queue

	void info();				// displays process info

	Process();					// default constructor
	Process(int x);				// constructor to create process with x ID
};