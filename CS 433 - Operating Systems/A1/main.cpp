/*
  Name: Alec Guilin
  Date: 9/19/19
  CS 433 Assignment 1
 */

#include "PCB.h"
#include "RQ.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//global vars
PCB * pcb_Table = new PCB[20]; //allocating memory for type PCB
queue q1;

//Fills the PCB table with 20 PCB objects with random priorites 1-50
void fillTable()
{
  cout << "Filling PCB Table with 20 random entries...\n";
  int j=0;
  for(int i =0; i<20;i++){
      pcb_Table[i].setID(j);
      pcb_Table[i].setPriority(rand() % 50 + 1);
      j++;
      cout<<"Added ID "<<j<< " with priority "<<pcb_Table[i].getPriority()<<endl;
    }  
    cout << "Table filled.\n";
    
}
//This function will add a PCB to the queue and also changes the PCB status to 
// "READY" within the pcb_Table. 
//Args: integer ID of the PCB object
void addToQueue(int id)
{
    pcb_Table[id].setState("READY");
    q1.insertProc(pcb_Table[id]);
}
//Removes the highest priority PCB from the queue and returns it, also sets the 
// status of the PCB in the pcb_Table to "RUNNING"
//Returns the ID of the PCB that was removed
int removeFromQueue()
{
    PCB temp = q1.removeHighestProc();
    int tempID = temp.getID();
    for(int i=0;i<19;i++){
        if(pcb_Table[i].getID() == tempID){
            pcb_Table[i].setState("RUNNING");
        }
    }
    return tempID;
}

//This function runs test 1 that is described in the instuctions
//Args: A pointer to the pcb_Table
int main()
{
    fillTable();
    cout << "Adding IDs 5, 1, 8, 11 to the Queue...\n";
    addToQueue(5);
        q1.displayQueue();

    addToQueue(1);
        q1.displayQueue();

    addToQueue(8);
        q1.displayQueue();

    addToQueue(11);
        q1.displayQueue();

    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout << "Adding 3, 7, 2, 12, 9 to the Queue...\n";
    addToQueue(3);
        q1.displayQueue();

    addToQueue(7);
        q1.displayQueue();

    addToQueue(2);
    addToQueue(12);
    addToQueue(9);
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout << "Exiting...\n";
    return 0;
}
