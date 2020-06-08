#include <iostream>
#include "random.h"
#include "FCFS.h"
#include "simulation.h"
using namespace std;

// PURPOSE: default constructor
FCFS::FCFS()
{
	DES = nullptr;
}

// PURPOSE: constructor to create FCFS object
// PARAMETER: s = accesses sim member variables
FCFS::FCFS(Simulation * s)
{
	DES = s;
}

// PURPOSE: this function dispatches a process
void FCFS::schedule()
{
	// dispatch process
	if (DES->_CPU.CPU_STATE == IDLE && !ready_queue.empty()) {
		// select process to schedule from ready queue
		Process * p = ready_queue.front();
		ready_queue.pop();

		// assign process to CPU
		DES->_CPU.CPU_JOB = p;
		DES->_CPU.CPU_STATE = BUSY;
		p->procStatus = RUNNING;
		p->triggerTime = DES->currentTime;

		// create Event for the time when process cpu burst will finish
		int time = DES->currentTime + p->nextCPUburstLength;
		Event * cpucompletion = new Event(p->procID, BURST_COMPLETE, time);

		// add Event to Event queue
		DES->event_queue.push(cpucompletion);
	}
}

// PURPOSE: This function handles an Event from event_queue
// PARAMETER: &e = Event from event_queue
void FCFS::handle_event(Event & e)
{
	switch (e.type) {
	case ARRIVAL:
		handle_process_arrival(e);
		break;

	case BURST_COMPLETE:
		handle_cpuburst_completion(e);
		break;

	case IO_COMPLETE:
		handle_io_completion(e);
		break;

	case TIME_EXPIRE:
		handle_timer_expiration(e);
		break;
	}
}

// PURPOSE: This function handles a Process arrival Event
// PARAMETER: &e = Process arrival Event
void FCFS::handle_process_arrival(Event & e)
{
	Process * p = &DES->process_table[e.ID];

	// generate processes next cpu burst length
	p->nextCPUburstLength = CPUBurstRandom(p->avgCPUburstLength);

	// add Process to ready queue.
	p->enterTime = DES->currentTime;
	p->procStatus = READY;
	ready_queue.push(p);

	schedule();
}

// PURPOSE: This function handles a CPU completion Event
// PARAMETER: &e = cpu completion Event
void FCFS::handle_cpuburst_completion(Event & e)
{
	Process * p = &DES->process_table[e.ID];

	// update remaining cpu duration
	p->remainCPUduration -= p->nextCPUburstLength;

	// update stats info
	p->serviceTime += p->nextCPUburstLength;
	p->waitTime = p->waitTime + (p->triggerTime - p->enterTime);

	// when Process is complete
	if (p->remainCPUduration <= 0) {
		// update Process info
		DES->completedJobs++;
		p->turnAroundTime = DES->currentTime - p->startTime;
		p->finishTime = DES->currentTime;

		// remove Process from cpu
		p->procStatus = TERMINATED;
		DES->_CPU.CPU_JOB = nullptr;
	}

	else {
		// generate next io burst length
		p->IOburstTime = ranInt(30, 100);

		// create Event for time when Process completes io burst
		int time = DES->currentTime + p->IOburstTime;
		Event * iocompletion = new Event(e.ID, IO_COMPLETE, time);
		DES->event_queue.push(iocompletion);
	}

	DES->_CPU.CPU_STATE = IDLE;
	schedule();
}

// PURPOSE: This function handles a io completion Event
// PARAMETER: &e = io completion Event
void FCFS::handle_io_completion(Event & e)
{
	Process * p = &DES->process_table[e.ID];

	// generate the processes next cpu burst length
	p->nextCPUburstLength = CPUBurstRandom(p->avgCPUburstLength);
	p->totalIOburstTime += +p->IOburstTime;

	// move the process to ready queue
	p->procStatus = READY;
	p->enterTime = DES->currentTime;
	ready_queue.push(p);

	schedule();
}

// PURPOSE: This function handles a timer expiration Event used in preemptive schedulers
// PARAMETER: &e = time expiration Event
void FCFS::handle_timer_expiration(Event & e)
{
	Process * p = &DES->process_table[e.ID];
	p->procStatus = READY;
	ready_queue.push(p);

	p->nextCPUburstLength = CPUBurstRandom(p->avgCPUburstLength);

	DES->_CPU.CPU_STATE = IDLE;
	schedule();
}
