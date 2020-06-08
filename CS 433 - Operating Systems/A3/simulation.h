#pragma once
#include <queue>
#include "event.h"
#include "process.h"

// enum for CPU state
enum state_t { BUSY, IDLE };

// overrides priority queues comparison logic
// comparison based on Event time
struct EventCompare {
	bool operator() (const Event* e1, const Event* e2) const {
		return e1->time > e2->time; 
	}
};

// implementation of CPU
struct CPU {
	Process * CPU_JOB;				// holds current Process
	state_t CPU_STATE;				// current state of CPU
};

// implementation of DES simulation
class Simulation {
public:
	std::priority_queue<Event*, std::vector<Event*>, EventCompare> event_queue;		// Event queue for DES
	std::vector<Process> process_table;		// vector of all processes in system
	
	CPU _CPU;						// CPU
	int currentTime;				// current time of sim
	int quitTime;					// duration of sim
	int selection;					// scheduling type(fcfs or sjf)
	int amount;						// number of processes to sim
	int completedJobs;				// total jobs completed in sim

	void runFCFS();					// runs fcfs scheduler
	void runSJF();					// runs sjf scheduler
	void report();					// display report of sim
	void setup();					// creates x amount of processes
	Simulation();					// default constructor

private:
	double utilizeCPU;				// utlizatation of cpu
	double throughput;				// throughput of completed jobs / s
	double avgTurnAround;			// average turnaround time of processes
	double avgWaitTime;				// average wait time of processes
};