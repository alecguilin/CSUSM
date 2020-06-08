#include"Passenger.h"

//constructor
Passenger::Passenger(string ID, string fName, string lName, char gender, int age, string assistance, string meal)
{
  personInfo.SetPerson(ID, fName, lName, gender, age);
  preferenceInfo.SetPreference(assistance, meal);
}

void Passenger::SetPassenger(string ID, string fName, string lName, char gender, int age, string assistance, string meal)
{
  personInfo.SetPerson(ID, fName, lName, gender, age);
  preferenceInfo.SetPreference(assistance, meal);
}
void Passenger::PrintPassenger() const
{
  personInfo.PrintPerson();
  preferenceInfo.PrintPreference();
}

void Passenger::PrintPassenger2() const
{
  personInfo.PrintPerson2();
  preferenceInfo.PrintPreference();
}

string Passenger::getID() const
{
  return personInfo.getID();
}

string Passenger::getFullName() const
{
  return personInfo.getName();
}

string Passenger::getAssistance() const
{
  return preferenceInfo.getAssistance();
}

string Passenger::getMealPref() const
{
  return preferenceInfo.getMeal();
}
