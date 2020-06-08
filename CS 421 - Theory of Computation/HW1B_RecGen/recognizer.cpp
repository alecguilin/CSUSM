#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1 
// Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name: ** Alec Guilin
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(string s)
{ 
	for(int i=0; i<s.size(); i++)
	{
		if (s[i] != '0' && s[i] != '1')
			return false;
	}
	return true;

}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{
	string s, e;
	do
	{	
		cout << "Enter a binary number: ";
		cin >> s;
		cout << "Checking " << s << "...\n";
		if (recognizer(s))
			cout << "YES IN L\n\n";
		else
			cout << "NO NOT IN L\n\n";
	} while(true);

    // feel free to put it in a loop 

}// end of main
