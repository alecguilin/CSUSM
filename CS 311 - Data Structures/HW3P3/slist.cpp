// =======================================================
// HW#: HW3P2
// Your name: Alec Guilin
// Compiler:  g++ 
// File type: implementation file 
//=======================================================
#include"slist.h"
#include<iostream>

//constructor
slist::slist() : llist() {} //calls llist constructor

//overloaded copy constructor
slist::slist(const slist& Original)
{
	//initialize this->'s data members
	this->Front = NULL;
	this->Rear = NULL;
	this->Count = 0;

	Node *P; //temp pointer to traverse list
	P = Original.Front;
	while(P!=NULL) //traverse the entire list
	{
		this->addRear(P->Elem); //P's element is added to this->
		P = P->Next; //go to next node
	}
}

//overloaded = operator
slist& slist::operator=(const slist& OtherOne)
{
	if (&OtherOne != this) //checks to make sure OtherOne and this-> are not the same object
	{
		el_t temp; //temp var for deleteRear function
		while (!this->isEmpty()) //deletes this-> list
			this->deleteRear(temp);
		Node *P; //temp pointer to traverse list
		P = OtherOne.Front; 
		while(P!=NULL) //traverse the entire list
		{
			this->addRear(P->Elem); //P's element is added to this->
			P = P->Next; //go to next node
		}
	}	
	return *this; //return the result
}

//PURPOSE: Searches the list of nodes for a given key and returns the position of the node if found.
//Otherwise, return 0.
//PARAMETER: Key of type el_t to search for
int slist::search(el_t Key)
{
	bool found = false; //flag if key is found
	int pos = 1; //keeps track of node position
	Node *P; //pointer to traverse the linked list
	P = Front; //start at the front of the list
	while(P!=NULL && found==false) //keep traversing list until there are no more nodes are key was found
	{
		if(P->Elem==Key) //set flag true if key was found
			found = true; 
		else //otherwise go to next ndoe
		{
			P = P->Next;
			pos++;
		}
	}
	if (found==false) //return 0 if key was not found
		return 0;
	else //return position if key was found
		return pos; 
}

//PURPOSE: Replaces element of the Ith node 
//PARAMETERS: Elem of type el_t is the new element to replace the old one.
//I of type int is the Ith node.
void slist::replace(el_t Elem, int I)
{
	if (I < 1 || I > Count) //throw OutOfRange if I is an illegal value
		throw OutOfRange();
	else //go to ith node and replace old element with given Elem
	{
		Node *P; //pointer to traverse the list
		P = Front; //start at the front of list

		for (int K = 1; K <= I-1; K++) //go to Ith node
			P = P->Next;
		P->Elem = Elem; //replace elem
	}
}