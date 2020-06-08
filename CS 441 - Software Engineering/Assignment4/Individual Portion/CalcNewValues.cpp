// Name: Alec Guilin
// Date: 11/20/19
// Assignment 4

#include <stdio.h>  
#include <iostream> 
using namespace std;

//class CalcNewValues{}
//changed to 
//int main(int argc, char const *argv[]){} 

int main(int argc, char const *argv[]){    //Initialize values
    static int GRAVITY = 2;
    int altitude = 1000;
    int fuel = 500;
    int velocity = 70;
    int time = 0;
    
    //Print initial values
    //have to add identifiers to advance through pipe to next filter
    //filter needs to be able to understand the output to use as input
    cout << "%a" << altitude << endl;
    cout << "%f" << fuel <<endl;
    cout << "%v" << velocity << endl;
    cout << "%t" << time << endl;

    //string pointing to null was causing issues
    //default construction of string is ""
    //so instead, just use .empty() to check if it is "null"
    string inputLine;

    do{
        getline(cin, inputLine);    
        if((inputLine.empty() == false) && (inputLine.length() > 0)) {
            
            if(inputLine[0] == '#') {
                //This is a status line of text, and
                //should be passed down the pipeline


                //had to use cout here because printf was causing issues 
                cout << inputLine << endl;
            }
            else if(inputLine[0] == '%'){
                //This is an input burn rate
                //dont want to include % symbol as burn rate
                //.substr(1) captures the string starting from position 1
                //atoi converts to int
                int burnRate = atoi(inputLine.substr(1).c_str());
                if(altitude <= 0){
                    printf("#The game is over.\n");
                }
                else if(burnRate > fuel){
                    printf("#Sorry, you don't have that much fuel.\n");
                }
                else{
                    //Calculate new application state
                    // directly translated from orignial CalcNewValues.java
                    time = time + 1;
                    altitude = altitude - velocity;
                    velocity = ((velocity + GRAVITY) * 10 - burnRate * 2) / 10;
                    fuel = fuel - burnRate;
                    if(altitude <= 0){
                        altitude = 0;
                        if(velocity <= 5){
                            printf("#You have landed safely.\n");
                        }
                        else{
                            printf("#You have crashed.\n");
                        }
                    }
                }
            //Print new values
    cout << "%a" << altitude << endl;
    cout << "%f" << fuel <<endl;
    cout << "%v" << velocity << endl;
    cout << "%t" << time << endl;
            }
        }
    }
    while((inputLine.empty() == false) && (altitude > 0));
  };
//};