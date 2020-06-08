#ifndef Person_C
#define Person_C

#include "Person.h"

//default constructor
Person::Person() : gender('?'), ID("")
{
  fName = "";
  lName = "";
  age = 0;
}
//constructor
Person::Person(string id, string fname, string lname, char gen, int ag) : gender(gen), ID(id)
{ 
  fName = fname;
  lName = lname;
  age = ag;
}

void Person::SetPerson(string id, string fname, string lname, char gen, int ag)
{
  fName = fname;
  lName = lname;
  age = ag;
  gender = gen;
  ID = id;
}
void Person::PrintPerson() const
{
  cout << left << setw(20) << getName();
  cout << left << setw(13) << ID;
  cout << left << setw(10) << gender;
  cout << left << setw(10) << age;
}

void Person::PrintPerson2() const
{
  cout << left << setw(20) << getName();
  cout << left << setw(13) << ID;
}
string Person::getName() const
{
  return fName + " " + lName;
}

string Person::getID() const
{
  return ID;
}

char Person::getGender() const
{
  return gender;
}

int Person::getAge() const
{
  return age;
}

#endif
