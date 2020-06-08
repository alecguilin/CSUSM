//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Alec Guilin
//Complier:  g++
//File type: client program (tester)
//===========================================================

#include <iostream>
#include "llist.h"
using namespace std;

void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element

  //1 check empty and report the result  
  cout << 1 << endl;
  if(L.isEmpty())
    cout << "List is empty.\n";
  else
    cout << "List is not empty.\n";
  //2 display the list  
  cout << 2 << endl;
  L.displayAll();
  //3 add 4 integers 1,2,3,4    
  cout << 3 << endl;
  cout << "Adding 1, 2, 3, and 4 to list.\n";
  L.addRear(1);
  L.addRear(2);
  L.addRear(3);
  L.addRear(4);
  //4 display the list  
  cout << 4 << endl;
  L.displayAll();
  //5 remove from front twice (and display the elements removed)
  cout << 5 << endl;
  cout << "Removing from the front twice.\n";
  L.deleteFront(x);
  cout << x << " was removed from the list.\n";
  L.deleteFront(x);
  cout << x << " was removed from the list.\n";
  //6 display the list
  cout << 6 << endl;
  L.displayAll();
  //7 check empty and report the result 
   cout << 7 << endl;
   if (L.isEmpty())
     cout << "List is empty.\n";
   else
     cout << "List is not empty.\n";
  //8 remove from the rear twice (display the element removed)
   cout << 8 << endl;
   cout << "Deleting from the rear twice.\n";
   L.deleteRear(x);
   cout << x << " was removed from the list.\n";
   L.deleteRear(x);
   cout << x << " was removed from the list.\n";
  //9 check empty again and report the result
   cout << 9 << endl; 
   if(L.isEmpty())
     cout << "List is empty.\n";
   else
     cout << "List is not empty.\n";
}//end of case 1 
 

void caseTwo()
{ 
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << c << endl; c++;
  cout << "Adding 5 to front.\n";
  L2.addFront(5);
  // 2.add to front again  (element 4)
  cout << c << endl; c++;
  cout << "Adding 4 to front.\n";
  L2.addFront(4);
  // 3.delete Front
  cout << c << endl; c++;
  cout << "Deleting front.\n";
  L2.deleteFront(x);
  cout << "Removed "<< x << " from list.\n"; 
  // 4.add to rear 3 times (elements 6,8,9)
  cout << c << endl; c++;
  cout << "Adding 6, 8, and 9 to the rear.\n";
  L2.addRear(6);
  L2.addRear(8);
  L2.addRear(9);
  // 5. display all
  cout << c << endl; c++;
  L2.displayAll();
  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << c << endl; c++;
  cout << "Adding 4 before 1st node.\n";
  L2.addbeforeIth(1, 4);
  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << c << endl; c++;
  cout << "Adding 7 before 4th node.\n";
  L2.addbeforeIth(4, 7);
  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << c << endl; c++;
  cout << "Adding 10 before 7th element.\n";
  L2.addbeforeIth(7, 10);
  // 9.add before the 9th  (element 12) . error (out of range)
  cout << c << endl; c++;
   try{ L2.addbeforeIth(9, 12); } 
  catch(llist::OutOfRange){ cerr << "Error: Out of range.\n";}
  
  // 10.add before the 0th (element 0) . error (out of range)
  cout << c << endl; c++;
  try{L2.addbeforeIth(0, 0);} 
  catch(llist::OutOfRange){cerr << "Error: Out of range.\n";}
  // 11.displayAll
  cout << c << endl; c++;
  L2.displayAll();
  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << c << endl; c++;
  cout << "Deleting 1st node.\n";
  L2.deleteIth(1, x);
  cout << "Element " << x << " was removed.\n";

  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
  cout << c << endl; c++;
  cout << "Deleting 6th node.\n";
  //cout << "x before: "<< x << endl;
  L2.deleteIth(6, x);
  //cout << "x after: " << x << endl;
  cout << "Element " << x << " was removed.\n";

  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << c << endl; c++;
  cout << "Deleting 3rd node.\n";
  L2.deleteIth(3, x);
  cout << "Element " << x << " was removed.\n";

  // 15.delete Ith I==5 . error (out of range)
  cout << c << endl; c++;
  try {L2.deleteIth(5, x); }
  catch(llist::OutOfRange){cerr << "Error: Out of range.\n"; }
  // 16.delete Ith I==0 . error (out of range)
  cout << c << endl; c++;
  try {L2.deleteIth(0, x);}
  catch(llist::OutOfRange){cerr << "Error: Out of range.\n";}
  // 17.displayAll
  cout << c << endl; c++;
  L2.displayAll();
  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << c << endl; c++;
  cout << "Deleting from rear until list is empty.\n";
  while (L2.isEmpty()==false)
    {
      L2.deleteRear(x);
      cout << "Element " << x << " was removed.\n";
    }
  // 19.displayAll  
  cout << c << endl; c++;
  L2.displayAll();
  
  }//end of case 2

void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << 1 << endl;
  try {L3.addbeforeIth(0, x);}
  catch (llist::OutOfRange){cerr << "Error: Out of range.\n";}
  //2.delete front . error (underflow)
  cout << 2 << endl;
  try {L3.deleteFront(x);}
  catch (llist::Underflow){cerr << "Error: Underflow.\n";}
}   //end of case 3

void caseFour()
{
  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  //   1.delete 2nd . error (out of range)
  cout << 1 << endl;
  try {L4.deleteIth(2, x); }
  catch (llist::OutOfRange){cerr << "Error: Out of range.\n";}
  //    2.delete rear . error (underflow)
  cout << 2 << endl;
  try {L4.deleteRear(x); }
  catch (llist::Underflow){cerr << "Error: Underflow.\n";}
} // end of case 4


//PURPOSE of the Program: To test our implementation of our created linked list class by testing various functions that we designed. 
//Algorithm/Design: 4 test cases are divided into 3 functions and we used a menu for the user to select which test case to test our linked list class. 
int main()
{
  int selection; // this will indicate what the user wants to do
  
  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "   (4) Case 4 " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";
      
      cin >> selection;
      
      switch(selection)
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	case 4: caseFour(); break;
	}
    }
  while(selection !=0);

}// end of main

