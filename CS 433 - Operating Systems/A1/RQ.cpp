#include "PCB.h"
#include "RQ.h"   
#include <iostream>
#include<iomanip>
using namespace std;

queue::queue()
{
    list<el_t> el;
    count = 0;
}
 
queue::~queue() {}

int queue::size() {return count;}

void queue::displayQueue()
{
    if (el.empty()) //checks if queue is empty
      cout << "[ empty ]" << endl;
    else //if queue is not empty
    {
        cout << "DISPLAYING QUEUE\n-----------------------------------\n";
        //for (list<el_t>::iterator it=el.begin(); it != el.end(); ++it) //traverses list and displays elements until it reaches the end
        list <el_t> :: iterator it;
        for (it = el.begin(); it != el.end(); it++)
        {
            cout << "ID: " << it->getID() << setw(27);
            cout << "Priority: " << it->getPriority() << endl;
        }
    }
}

void queue::insertProc(el_t e)
{
    bool inserted = false;
    
    if (el.empty()) //if list is empty
    {
        list<el_t>::iterator it = el.begin();
        el.insert(it, e); //insert PCB into beginning of list
    }
    else //if the list is not empty
    {
        int jobPriority = e.getPriority(); //get priority level of e
        list<el_t>::iterator it; //declare list iterator
        for (it=el.begin(); it != el.end(); ++it) //for loop iterates through entire list
        {
            if (jobPriority < it->getPriority()) //if we find a job with lower priority than e
            {
                el.insert(it, e); //inserts e into list and pushes exisitng job and all others behind it back
                inserted = true;
            }
        }
        
        if (inserted == false) //if e has a lower priority than all other jobs in the list
        {
            el.push_back(e); //add e to the very end of the list
        }
        
    }
    count++;  
}

el_t queue::removeHighestProc()
{
    list<el_t>::iterator it = el.begin(); //point iterator at beginning element in list
    PCB highestProc = *it;
    el.erase(it); //erase first item in list
    return highestProc;
}
