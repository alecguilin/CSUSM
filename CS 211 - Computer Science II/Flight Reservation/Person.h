#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<iomanip>
using namespace std;

class Person
{
 private:
  string fName, lName;
  char gender;
  string ID;
  int age;
 public:
  Person(); //default constructor
  Person(string, string, string, char, int); //constructor
  void SetPerson(string, string, string, char, int);
  void PrintPerson() const;
  void PrintPerson2() const;
  string getName() const;
  string getID() const;
  char getGender() const;
  int getAge() const;
};

#endif
