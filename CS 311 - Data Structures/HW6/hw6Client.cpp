// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.
// =======================================================
// HW#: HW6
// Your name: Alec Guilin
// Compiler:  g++ 
// File type: main client file 
//=======================================================
#include<iostream>
#include"dgraph.h"
using namespace std;
int main()
{
  dgraph table;
  table.fillTable();
  table.displayGraph();


  char x; //temp for vertex user input
  slist tempList; //temp so we can store the return value from the findAdjacent func
  do
  {
    cout << "Enter vertex to find OutDegree (type 0 to exit): ";
    cin >> x;
    if (x!='0')
    {
      try
      {
        cout << table.findOutDegree(x) << endl;
      }
      catch (dgraph::BadVertex) 
      { cerr << "Bad vertex.\n"; }    
    }
  } while (x!='0');

  do
  {
    cout << "Enter vertex to find adjecentOnes (type 0 to exit): ";
    cin >> x;
    if (x!='0')
    {
      try
      {
        tempList = table.findAdjacency(x);
        tempList.displayAll();
      }
      catch (dgraph::BadVertex)
      { cerr << "Bad vertex.\n"; }
    }
  } while (x!='0');
  return 0;
}
