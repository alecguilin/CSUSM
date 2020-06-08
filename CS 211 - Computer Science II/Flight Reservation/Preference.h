#ifndef Pref_H
#define Pref_H
#include<iostream>
#include<iomanip>
using namespace std;

class Preference
{
 private: 
  string assistanceType;
  string mealType;
 public:
  Preference();
  Preference(string, string);
  void SetPreference(string, string);
  void PrintPreference() const;
  string getAssistance() const;
  string getMeal() const;

};

#endif
