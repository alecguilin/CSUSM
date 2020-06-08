#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

//--------------------------------------
// CS421 File td.cpp for HW2B Table-Driven Scanner
// Your name: ** Alec Guilin
//--------------------------------------

// Complete this to fit the HW2B specification - look for **
// Must have the same types of tracing couts as my demo program.


// info on each DFA
struct info
{
  string name;  // token name
  int startstate;
  int finalstate;
};

info DFAs[4];     // store up to 4 dfas' start and final

int  TRS[10][4];  // store all trs's - states 0-9 and chars a b c d -- all dfas transitions are in here 

// ----- utility functions -----------------------

int readTables()
{  

    // ** Read in the files into TRS and DFAs
   // ** Return how many DFAs were read

   ifstream fin ("trs.txt", ios::in);
   ifstream fin2 ("dfas.txt", ios::in);

   //read TRS
   for (int i = 0; i < 10; i++)
    for (int j = 0; j < 4; j++)
    {
      fin >> TRS[i][j];
    }

    //read DFAs
   int i = 0;
   while(fin2 >> DFAs[i].name)
   {   
       fin2 >> DFAs[i].startstate;
       fin2 >> DFAs[i].finalstate;
       i++;
   }

   return i; //returns num of DFAs (count)

}

void displayTables(int numDFAs)
{
  // ** display TRS nicely labeled
  cout << setw(17) << "a b c d\n";
  for (int i = 0; i < 10; i++)
  {
    cout << "State " << i << ": ";
    for (int j = 0; j < 4; j++)
    {
      if (TRS[i][j] != -1)
        cout << TRS[i][j] << " ";
      else cout << "  ";
    }
    cout << endl;
  }
  cout << endl;

  // ** display DFAs nicely labeled
  for(int i = 0; i < numDFAs; i++)
  {
    cout << DFAs[i].name << endl;
    cout << "start state: " << DFAs[i].startstate << endl;
    cout << "final state: " << DFAs[i].finalstate << endl << endl;
  }
}

bool accept(info dfa, string word)
{
  // ** Does the dfa accept the word?
  // Start with the start state of the DFA and
  // look up the next state in TRS for each char in word.
  // At the end of the word, make sure you are in the 
  // final state of the DFA.
  // Use a formula to convert chars to TRS col numbers.
  int state = dfa.startstate;
  int charpos = 0;

  while (word[charpos] != '\0')
  {
    cout << "state: " << state << " char: " << word[charpos] << endl;
    if (TRS[state][word[charpos]-97] == -1)
    {
      cout << "new state: " << -1 << endl;
      return false;
    }
    else
    {
      state = TRS[dfa.startstate][word[charpos]-97];
      cout << "new state: " << state << endl;
    }
    charpos++;
  }

  if (state == dfa.finalstate)
    return true;
  
}


int main()
{
  cout << "This is a table driven scanner. Needs trs.txt and dfas.txt." << endl;
  cout << "States are 0 to 9 and chars are a to d" << endl;

  int numDFA = readTables(); // how many DFAs were read
  displayTables(numDFA);     // DISPLAY TABLES
  cout << ".....done reading tables...." << endl;

  bool found;

  string word;
  while(true)
    { cout << "@@Enter a string: " ;
      cin >> word;
      // ** try the DFAs one by one and see 
      //      if the word is accepted
      //      if so, display the word and the token name
      // ** if no DFA does, generate a lexical error message.
      found = false;
      for (int i = 0; i < numDFA && !found; i++)
      {
        cout << "Trying DFA " << i << ".....\n";
        if(accept(DFAs[i], word)){
          cout << word << " is accepted! \nToken name: " << DFAs[i].name << endl;
          found = true;
        }
      }
      if (!found)
        cout << "LEXICAL ERROR!\n";
      cout << "do control-C to quit" << endl;
    }

}//the end
