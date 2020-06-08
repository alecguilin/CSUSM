// ====   For the HW7 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.
// =======================================================
// HW#: HW7
// Your name: Alec Guilin
// Compiler:  g++ 
// File type: main client file 
//=======================================================
#include<iostream>
#include"dgraph.h"
#include"stack.h"
using namespace std;
int main()
{
  dgraph table;
  table.fillTable();
  table.displayGraph();
  table.visit(1, 'A');

  stack DFS;
  slist tempList; //temp slist so we can use deleteRear function without altering original data
  char tempChar; //temp placeholder for char type
  int visitCounter = 1; //counter for visit order

  //pushes adjacency list into a stack starting at A
  tempList = table.findAdjacency('A');
  cout << "Visited: " << 'A' << endl;
  while (tempList.isEmpty()==false)
  {
    tempList.deleteRear(tempChar); 
    cout << "PUSHING " << tempChar << " to stack.\n";
    DFS.push(tempChar);
  }

  DFS.displayAll();

  //while stack DFS is not empty, continue to traverse the graph
  while(DFS.isEmpty()==false)
  {
    DFS.pop(tempChar); //pop top char from stack
    if (table.isMarked(tempChar)==false) //if that char has not been marked
    {
      table.visit(++visitCounter, tempChar); //visit that vertex and increment visitCounter
      cout << "Visited: " << tempChar << endl;

      tempList = table.findAdjacency(tempChar); //find the adjacent ones from the removed char
      while (tempList.isEmpty()==false) //then push them into the stack DFS
      {
        tempList.deleteRear(tempChar);
        cout << "PUSHING " << tempChar << " to stack.\n";
        DFS.push(tempChar);
      }
    }
    DFS.displayAll();
    cout << endl;
  }

  table.displayGraph();
  
}
