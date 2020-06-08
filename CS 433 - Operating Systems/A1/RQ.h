#include "PCB.h"
#include <list>
#include <iostream>
using namespace std;

typedef PCB el_t;      //using el_t as a shortcut for PCB type

class queue  
{
  private:
    list<el_t> el;
    int count;         
  public:
 
    class Underflow{};  //handles underflow exceptions
    //constructor
    queue(); 

    //destructor 
    ~queue();

    //returns the size
    int size();

    //displays everything in the queue (front to rear)
    void displayQueue();
    
    //add the PCB of a process into the ready queue
    void insertProc(el_t);

    //remove and return the PCB with the highest priority from the queue
    el_t removeHighestProc();
};           
