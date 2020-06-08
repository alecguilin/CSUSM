
#include<iostream>
#include<stdlib.h>
#include<fstream>
//#include"stack.h"  // ** can be removed
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

//---------------------------------------
// CS421 File ll1.cpp for HW3A LL1 Table-Driven Parser
// Your name: ** Alec Guilin
//---------------------------------------

// Complete this to fit the HW3A specification - look for **
// Must have the same types of tracing couts as my demo program.

// Feel free to use a stack class or use a vector
// to implement your stack.  The stack will contain characters.
vector<char> M[3][2];  // the table of rules 
                       // 3 rows for S, A, B
                       // 2 rows for 0, 1
       // Each slot contains a rule's right side
       // which is a vector of characters

//stack implemented as a vector
vector<char> stackBABY;

//  ------- conversion functions ------------------------


// to convert non-terms S, A, B to table rows 0, 1, 2
int toRow(char C)
{
  if (C == 'S')
    return 0;
  else if (C == 'A')
    return 1;
  else if (C == 'B')
    return 2;
  else
    return -1; //invalid returns -1
}

// to convert '0' and '1' to table columns 0 and 1 
int toCol(char c)
{
  if (c == '0')
    return 0;
  else if (c == '1')
    return 1;
  else
    return -1; //invalid returns -1
}

// to convert row 0, 1, 2 to non-terms S, A and B
char toNonterm(int r)
{
  if (r == 0)
    return 'S';
  else if (r == 1)
    return 'A';
  else if (r == 2)
    return 'B';
  else 
    return ' '; //invalid returns a blank char
}


// ** Then complete the following functions.-----------------------------

// to display a rule's rhs which is in vector V
void displayVector(vector<char> V) 
{
  // ** display V horizontally e.g. 0 A 0
  for (int i = 0; i < V.size(); i++)
    cout << V[i] << " ";
}

// to read in the rules into M, make sure ; is not stored
void readrules()
{ 
  ifstream fin ("rules", ios::in);

  // For each line of "rules" (e.g. S  0 A 0 ;) 
  // The first char of a line determines the row of M
  // The second char of a line determine the column of M  
  // Note that each entry of M (the second char up to ;)
  // will be a vector representing 
  // the right hand side of a rule (rhs)

  char temp;
  int i, j;

  while (fin >> temp)
  {
    i = toRow(temp);
    fin >> temp;
    j = toCol(temp);

    M[i][j].push_back(temp);

    while(fin >> temp && temp != ';')
      M[i][j].push_back(temp);
  }

  // ** Display the table nicely  
  //    use toNonterm to show row labels (S, A, B)
  //    use displayVector for each content 

  for (int i = 0; i < 3; ++i)
  {
    cout << toNonterm(i) << ": ";
    for (int j = 0; j < 2 && M[i][j].size() != 0; ++j)
    {
      cout << setw(10);
      displayVector(M[i][j]);
    }
    cout << endl;
  }

}

//  pushes V contents to the stack 
void addtostack(vector<char> V)
{  cout << "Pushing rhs of a rule to the stack." << endl;
  // **  be careful of the order
   // because 1 0 0 means 1 will be at the top of the stack
  for (int i = 0; i < V.size(); ++i)
  {
    //stackBABY.insert(stackBABY.begin(), V[i]);
    stackBABY.push_back(V[i]);
  }
}

int main()
{ 
  readrules();  // M is filled and displayed 
  string ss;
  cout << "Enter a string made of 0's and/or 1's: ";
  cin >> ss;

  // ** push 'S' onto the stack to start
  stackBABY.push_back('S');

  // ** display the stack vertically from top to bottom
      cout << "Stack: \n";
      for (int i = stackBABY.size()-1; i >= 0; --i)
      {
        cout << stackBABY[i] << endl;
      }
      cout << "---------------\n";

  int i = 0;  // index for ss
  bool fail = false; //reject
  char top; //top of stack
  while (ss[i] != '\0')  // for each char of ss
    {
     // Based on ss[i] and 
     //    the top of stack, update the stack: 
     // ** note that empty stack will cause immediate failure  
     // ** note that top of stack terminal and ss[i] mismatching
     //    will cause immediate failure 
     // ** note that no entry in M for the top of stack (non-terminal)
     //    and ss[i] will cause immediate
     //    failure  (use toRow and toCol to look up M)
     // ** otherwise, addtoStack the M entry based on ss[i] and the top of stack 
      cout << "current char is: " << ss[i] << endl;
      if (stackBABY.size() != 0)
      {
        top = stackBABY[stackBABY.size()-1];
        cout << "top is: " << top << endl;
        if(top == 'S' || top == 'A' || top == 'B')
        {
          if (toCol(ss[i])<2 && toCol(ss[i]) >= 0)
          {
            if (M[toRow(top)][toCol(ss[i])].size() != 0)
            {
              //replace top of stack here(replace with vector)
              stackBABY.pop_back();
              addtostack(M[toRow(top)][toCol(ss[i])]);
            }
            else
            {
              fail = true;
              break;
            }
          }
          else
          {
            //no rule found
            cout << ">>ERROR: no rule found\n";
            fail = true;
            break;
          }
        }
        else if (top == '0' || top == '1')
        {
          //match with current char, fails if no match, if match remove top from stack
          if (ss[i] == top)
          {
            //matches
            cout << "matched!\n";
            //remove top
            //stackBABY.erase(stackBABY.size()-1);
            stackBABY.pop_back();
            i++;
          }
          else
          {
            //does not match, fail
            cout << ">>ERROR: mismatch\n";
            fail = true;
            break;
          }
        }
      }
      else
      {
        cout << ">>ERROR: stack is empty\n";
        fail = true; //fails if stack is empty
        break;
      }

      cout << "Stack: \n";
      for (int i = stackBABY.size()-1; i >= 0; --i)
      {
        cout << stackBABY[i] << endl;
      }
      if (stackBABY.size() == 0)
      {
        cout << "[empty]\n";
      }

      cout << "---------------\n";

    } // end of string

  // ** Here, check for success for failure based on stack empty or not
    if (stackBABY.size() == 0 && fail == false)
      cout << "Accept!\n";
    else
      cout << "Reject...\n";

}// end of main
