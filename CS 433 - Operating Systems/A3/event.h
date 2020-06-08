	#pragma once

// enum for event type
enum event_t { ARRIVAL, BURST_COMPLETE, IO_COMPLETE, TIME_EXPIRE };

// implementation of an event
class Event {
public:
	int ID;				// the process that belongs to event
	int time;			// time when event should take place
	event_t type;		// event type

	Event();			// default constructor
	Event(int pID, event_t etype, int etime);	// constructor to create event
};