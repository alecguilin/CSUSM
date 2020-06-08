#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define NUM_WORDS 18 // the number of reserved words

//=====================================================
// File scanner.cpp written by: Group Number: 13 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Brett Flavin
// RE: (v|I|E|vn|In|En|1v|1I|1E|2I|2E|1vn|1In|1En|2vn|2In|2En|2yv|2yI|2yE|2yvn|2yIn|2yEn|tv|tI|tE|tvn|tIn|tEn|tsv|tsI|tsE|tsvn|tsIn|tsEn|sv|sI|sE|svn|sIn|sEn|shv|shI|shE|shvn|shIn|shEn|chv|chI|chE|chvn|chIn|chEn)^+
bool word (string s)
{
  int state = 0;
  int charpos = 0;
  
  while (s[charpos] != '\0') {
	switch(state) {	
		case 0:
			if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
				state = 1;
			else if (state == 0 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2;
			else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'p'))
				state = 4;
			else if (state == 0 && s[charpos] == 'c')
				state = 5;
			else if (state == 0 && s[charpos] == 's')
				state = 6;
			else if (state == 0 && s[charpos] == 't')
				state = 7;
			else
				state=-1; //state is stuck, fails
			break;
		case 1:
			if (state == 1 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2; 
			else if (state == 1 && (s[charpos] == 'b' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'p'))
				state = 4;
			else
				state=-1;
			break;
		case 2:
			if (state == 2 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
				state = 1;
			else if (state == 2 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2;
			else if (state == 2 && s[charpos] == 'n')
				state = 3;
			else if (state == 2 && (s[charpos] == 'b' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'p'))
				state = 4;
			else if (state == 2 && s[charpos] == 'c')
				state = 5;
			else if (state == 2 && s[charpos] == 's')
				state = 6;
			else if (state == 2 && s[charpos] == 't')
				state = 7;
			else
				state=-1;
			break;
		case 3:
			if (state == 3 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
				state = 1;
			else if (state == 3 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2;
			else if (state == 3 && (s[charpos] == 'b' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'p'))
				state = 4;
			else if (state == 3 && s[charpos] == 'c')
				state = 5;
			else if (state == 3 && s[charpos] == 's')
				state = 6;
			else if (state == 3 && s[charpos] == 't')
				state = 7;
			else
				state = -1;
			break;
		case 4:
			if (state == 4 && s[charpos] == 'y')
				state = 1; 
			else if (state == 4 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2;
			else
				state = -1;
			break;
		case 5:
			if (state == 5 && s[charpos] == 'h')
				state = 1;
			else
				state = -1;
			break;
		case 6:
			if (state == 6 && s[charpos] == 'h')
				state = 1; 
			else if (state == 6 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2;
			else
				state = -1;
			break;
		case 7:
			if (state == 7 && s[charpos] == 's')
				state = 1; 
			else if (state == 7 && (s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
				state = 2;
			else
				state = -1;
			break;
     } // end of switch
	 charpos++;
   } //end of while
  // if in a final state return true, else return false
  if (state == 2 || state == 3) 
	  return(true); 
  else return(false);  
} // end of function

// PERIOD DFA 
// Done by: Brett Flavin
// RE: .^+
bool period (string s)
{  
	// string should just be a single period
	if (s[0] == '.')
		return true;
	else
		return(false);		
}

// TABLES Done by: Alec Guilin

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype { WORD1, WORD2, PERIOD, ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "WORD1", "WORD2", "PERIOD", "ERROR", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR"	};

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
struct reservedWords {
	const char* theString;
	tokentype theType;
};

reservedWords reserved[] = {
	{"masu", VERB},
	{"masen", VERBNEG},
	{"mashita", VERBPAST},
	{"masendeshita", VERBPASTNEG},
	{"desu", IS},
	{"deshita", WAS},
	{"o", OBJECT},
	{"wa", SUBJECT},
	{"ni", DESTINATION},
	{"watashi", PRONOUN},
	{"anata", PRONOUN},
	{"kare", PRONOUN},
	{"kanojo", PRONOUN},
	{"sore", PRONOUN},
	{"mata", CONNECTOR},
	{"soshite", CONNECTOR},
	{"shikashi", CONNECTOR},
	{"dakara", CONNECTOR},
};



// ------------ Scaner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// Done by: Kyle Allen

int scanner(tokentype& tt, string& w)
{
  // Grab the next word from the file via fin
	fin >> w;
	
	// if eofm return right now
	if (w == "eofm") 
		return 0;	
	
	// call word() to check if w is word
	if (word(w)) {
		cout << "WORD\n";
		// check if w is reserved word
		for (int i = 0; i < NUM_WORDS; ++i) {			
			if (w == reserved[i].theString) {
				tt = reserved[i].theType;
				return 0;
			}
		}
		// check last char to see if w is WORD2
		char lastChar = w[w.length() - 1];
		if (lastChar == 'I' || lastChar == 'E')
			tt = WORD2;
		else
			tt = WORD1;
	}

	// call period() to check if w is period
	else if (period(w)) {
		tt = PERIOD;
	}

	// error if w is not a word or period
	else {
		tt = ERROR;
		cout << "Lexical error: " << w << " is not a vaild token" << endl;
	}
	return 0;
}//the end of scanner

/*

// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Rika
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;  
	   cout << endl;
    }

   cout << "End of file is encountered." << endl;
   fin.close();

   // for debugging - take these out before submission
   //cin.get();
   //cin.get();
}// end
*/

