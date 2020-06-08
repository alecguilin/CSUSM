#ifndef PCBh
#define PCBh

#include <iostream>
#include <iostream>
using namespace std;

class PCB
{
    private:
        int ID;
        int priority;
        string state;
    public:
        PCB(); //constructor
        int getID();
        int getPriority();
        string getState();
        void setID(int);
        void setPriority(int);
        void setState(string);
};

#endif