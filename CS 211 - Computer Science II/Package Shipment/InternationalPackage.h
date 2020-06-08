#ifndef InternationalPackage_H
#define InternationalPackage_H

#include"Package.h"
#include<iostream>
using namespace std;

class InternationalPackage : public Package
{
 protected:
  string country;
 public:
  InternationalPackage(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, string);
  double calcCost();
  void print();
};

#endif
