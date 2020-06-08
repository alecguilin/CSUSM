#ifndef Passenger_H
#define Passenger_H

#include"Person.h"
#include"Preference.h"

class Passenger
{
 private:
  Person personInfo;
  Preference preferenceInfo;
 public:
  Passenger();
  Passenger(string, string, string, char, int, string, string);
  void SetPassenger(string, string, string, char, int, string, string);
  void PrintPassenger() const;
  void PrintPassenger2() const;
  string getID() const;
  string getFullName() const;
  string getAssistance() const;
  string getMealPref() const;
};

#endif
