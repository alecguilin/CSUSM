#include "PCB.h"
#include <iostream>
using namespace std;

PCB::PCB()
{
    int ID = 0;
    int priority = 0;
    string state = "";
}

int PCB::getID(){return ID;}

int PCB::getPriority(){return priority;}

string PCB::getState(){return state;}

void PCB::setID(int x){ID = x;}

void PCB::setPriority(int x){priority = x;}

void PCB::setState(string x){state = x;}