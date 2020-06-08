#include<iostream>
#include<string>
#include<queue>
using namespace std;
// include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is a binary number}.
// Your name: ** Alec Guilin
//----------------------------------------------

// Copy the recognizer function here from the other file.
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


// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can 
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()
{ 	
	//store each value into a queue instead of cout to system
	//then in while loop, run recognizing func on each queue element
	queue<string> myqueue;
	string temp;

	cout << "filling queue....\n";

	int maxL = 3;

	//fills one digit values
	for(int i = 0; i < maxL; i++){
	  temp = to_string(i);
		myqueue.push(temp);
	}

	//fills two digit values
	for (int i = 0; i < maxL; i++){
		for (int j = 0; j < maxL; j++){
		  temp = to_string(i) + to_string(j);
			myqueue.push(temp);
		}
	}

	//fills three digit values
	for (int i = 0; i < maxL; i++){
		for (int j = 0; j < maxL; j++){
			for (int k = 0; k < maxL; k++){
			  temp = to_string(i)+to_string(j)+to_string(k);
				myqueue.push(temp);
			}
		}
	}

	cout << "queue filled\n";

  	while(!myqueue.empty())
    {
    	if (recognizer(myqueue.front()))
    		cout << myqueue.front() << endl;
    	myqueue.pop();
    }// end of while

}// end of main
