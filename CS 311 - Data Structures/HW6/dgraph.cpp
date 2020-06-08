  // ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

// =======================================================
// HW#: HW6
// Your name: Alec Guilin
// Compiler:  g++ 
// File type: implementation file 
//=======================================================

#include<iostream>
#include<fstream>
#include<iomanip>
#include"dgraph.h"

//constructor
dgraph::dgraph()
{
  countUsed = 0;
  for (int i = 0; i < SIZE; ++i)
  {
    Gtable[i].vertexName = ' ';
    Gtable[i].visit = 0;
  }
}

dgraph::~dgraph()
{
  cout << "calling destructor in dgraph.cpp.\n";
}

//PURPOSE: fills up the table using file input (in this case the file is "table.txt")
//PARAMETER: none
void dgraph::fillTable()
{
  ifstream fin;
  fin.open("table.txt");
  cout << "filling table\n";
  while(fin >> Gtable[countUsed].vertexName) //if you can read the name
  {
    char x; //temp var to store char from file for addRear function
    fin >> Gtable[countUsed].outDegree;
    for (int i = 0; i < Gtable[countUsed].outDegree; ++i)
    {
      fin >> x;
      Gtable[countUsed].adjacentOnes.addRear(x); //uses slist function
    }
    countUsed++;
  }
  cout << "table is filled!\n";
  fin.close();
}

void dgraph::displayGraph()
{
  cout << "displaying graph\n";
  cout << left << setw(12) << "Vertex";
  cout << left << setw(12) << "Out Degree";
  cout << left << setw(12) << "Visit";
  cout << left << setw(12) << "adjacentOnes\n";
  for (int i = 0; i < countUsed; i++)
  {
    cout << left << setw(12) << Gtable[i].vertexName;
    cout << left << setw(12) << Gtable[i].outDegree;
    cout << left << setw(12) << Gtable[i].visit;    
    (Gtable[i].adjacentOnes).displayAll();
  }
}

int dgraph::findOutDegree(char v)
{
  for (int i = 0; i < countUsed; ++i)
  {
    if(Gtable[i].vertexName==v)
      return Gtable[i].outDegree;
  }
  throw BadVertex();
  return 0;
}

slist dgraph::findAdjacency(char v)
{
  for (int i = 0; i < countUsed; ++i)
  {
    if(Gtable[i].vertexName==v)
      return Gtable[i].adjacentOnes;
  }
  throw BadVertex();
}

void dgraph::visit(int visit, char v)
{
  int temp = v-65; //changes the corresponding letter to a number using ascii value (A = 0, B = 1, etc.)
  Gtable[temp].visit = visit;
}

bool dgraph::isMarked(char v)
{
  int temp = v-65; //changes the corresponding letter to a number using ascii value (A = 0, B = 1, etc.)
  if (Gtable[temp].visit != 0)
    return true;
  else
    return false;
}

