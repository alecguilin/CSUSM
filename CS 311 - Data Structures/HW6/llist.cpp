//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++
// ====================================================
//HW#: HW3P1 llist
//Your name: Alec Guilin
//Complier:  g++
//File type: llist implementation file
//=====================================================

#include<iostream>
#include"llist.h" 
using namespace std;

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist()
{
  Front = NULL; //set to null
  Rear = NULL; //set to null
  Count = 0;
}
  
//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  cout << "calling the llist destructor.\n";
  el_t temp; //temp var to call deleteFront function to clear list
  while (isEmpty()==false)
    deleteFront(temp);
}

//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.
//All 3 conditions must be checked.
bool llist::isEmpty()
{
  if (Front == NULL && Rear == NULL && Count == 0) //if list is empty
    return true;
  else //list is not empty
    return false;
}

//PURPOSE: displays each element of the list horizontally starting from Front in [ ].
void llist::displayAll()
{
  if (isEmpty()) //Special Case: if the list is empty, display [ empty ] 
    cout << "[ empty ]" << endl;
  else //Regular Case
    {
      cout << "[ ";
      Node *P; //temp pointer to traverse the list
      P = Front;
      while (P!=NULL)
	{
	  cout << P->Elem << " ";
	  P = P->Next;
	}
      cout << "]\n";
    }
}  

void llist::addRear(el_t NewNum) 
//PURPOSE: Adds rear node 
//  - Special case: if this is going to be the very first node, you must
//    create a new node and make Front and Rear point to it. Place NewNum and
//    Count is updated.
//  - Regular: adds a new node at the rear and puts NewNum in the Elem field
//    of this new node. Count is updated.
//PARAMETER: value to be added as element in new node
{
  if (Front == NULL) //special case: first node
    {
      Front = new Node;
      Rear = Front;
      Front->Elem = NewNum;
      Front->Next = NULL;
      Count++;
    }
  else //regular case
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
}

//PURPOSE: Adds node to front
//- Special case: if this is going to be the very first node, you must
//   create a new node and make Front and Rear point to it. Place NewNum and
//   Count is updated.
//- Regular: add a new node to the front of the list and 
//  Count is updated.
//PARAMETER: value to be added as element in new node
void llist::addFront(el_t NewNum)
{
  if (Front == NULL) //special case: first node
    {
      Front = new Node;
      Rear = Front;
      Front->Elem = NewNum;
      Front->Next = NULL;
      Count++;
    }
  else //regular case
    {
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Count++;
    }
}

//PURPOSE: Deletes front node
//- Error case: if the List is empty, throw Underflow
//- Special case: if currently only one Node,
//   give back the front node element through OldNum (pass by reference) and
//   make sure both Front and Rear become NULL. Count is updated.
//- Regular: give back the front node element through OldNum (pass by reference)
//  and also removes the front node.  Count is updated.
//PARAMETER: el_t variable passed by ref for the removed element to be stored in
void llist::deleteFront(el_t& OldNum)
{
  if (isEmpty()) //error case
    throw Underflow();
  else if (Front->Next==NULL) //special case: if only one node in list
    {
      OldNum = Front->Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else //regular case
    {
      OldNum = Front->Elem;
      Node *Second;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
}



//PURPOSE: Deletes rear node
//- Error case: if empty, throw Underflow
//- Special case: if currently only one node,
//   give back the rear node element through OldNum (pass by reference) and
//   make sure both Front and Rear become NULL. Count is updated.
//- Regular: give back the rear node element through OldNum (pass by reference)
//  and also remove the rear node. Count is updated.
//PARAMETER: el_t variable passed by ref for the removed element to be stored in
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty()) //error case
    throw Underflow();
  else if (Front->Next==NULL) //special case: if only one node
    {
      OldNum = Front->Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else //regular case
    {
      OldNum = Rear->Elem;
      //      cout << "REAR ELEMENT BEING STORED INTO OLDNUM IS: " << Rear->Elem << " and " << OldNum << endl;
      Node *P; //pointer to traverse the list
      P = Front;
      while (P->Next->Next!=NULL)
	       P=P->Next;
      delete Rear;
      Rear = P;
      Rear->Next = NULL;
      Count--;
    }
}


//PURPOSE: Deletes Ith Node
//- Error case: If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
//- Special cases: this should simply call deleteFront when I is 1 or 
//  deleteRear when I is Count
//- Regular: delete the Ith node (I starts out at 1).  Count is updated.
//<see the template loops in the notes to move 2 pointers to the right nodes;
//and make sure you indicate the purposes of these local pointers>
//PARAMETERS: I is the Ith node that we want to delete. OldNum is the var passed by ref 
//to store the removed element in
void llist::deleteIth(int I, el_t& OldNum)
{
  el_t x;
  if (I > Count || I < 1) //error case
    throw OutOfRange();
  else if (I==1) //special case 1: call deleteFront when you want to delete 1st node
    deleteFront(x);
  else if (I==Count) //special case 2: call deleteRear when you want to delete last node
    deleteRear(x);
  else //regular case
    {
      Node *P;
      Node *T; //keeps track of prev node while traversing list
      P = Front;
      for (int K = 1; K <= I-1; K++)
	{
	  T = P;
	  P=P->Next;
	}
      T->Next = P->Next;
      OldNum = P->Elem;
      //cout << "DELETE ITH NODE - OldNum is " << OldNum << " and " << P->Elem << endl;
      delete P;
      Count--;
    }    
}
/*

PURPOSE: adds before Ith node (i.e. before 5th node)
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
PARAMETERS: int I acts as the Ith node to be deleted and el_t newNum is the new value to be stored in a new node
*/
void llist::addbeforeIth(int I, el_t newNum)
{
  if (I>Count+1 || I<1) //error case
    throw OutOfRange();
  else if (I==1) //special case 1: if node is 1st node
    addFront(newNum);
  else if (I==Count+1) //special case 2: if node is last node
    addRear(newNum);
  else //regular case
    {
      Node *P;
      Node *T; //keeps track of prev node
      P = Front;
      for (int K = 1; K <= I-1; K++)
	{
	  T = P;
	  P = P->Next;
	}
      Node *x;
      x = new Node;
      x->Elem = newNum;
      x->Next = P;
      T->Next = x;
      Count++;
    }
}
