#include "event.h"

// PURPOSE: default constructor for event
Event::Event()
{
	ID = 0;
	type = ARRIVAL;
	time = 0;
}

// PURPOSE: constructor to create an event 
// PARAMETER: pID = process to which the event belongs to
//			  etype = event type
//			  etime = time of event
Event::Event(int pID, event_t etype, int etime)
{
	ID = pID;
	type = etype;
	time = etime;
}

