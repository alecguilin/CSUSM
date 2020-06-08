// =======================================================
// HW#: HW3P2
// Your name: Alec Guilin
// Compiler:  g++ 
// File type: header file 
//=======================================================
#include<iostream>
#include"llist.h" 
using namespace std;

class slist : public llist //inherit publically
{
	public: 
		//constructor
		slist();

		//searches for an elem
		int search(el_t);

		//replaces the element of the Ith node
		void replace(el_t, int);

		//overloaded copy constructor
		slist(const slist&);

		//overloaded = operator
		slist& operator=(const slist&);

};