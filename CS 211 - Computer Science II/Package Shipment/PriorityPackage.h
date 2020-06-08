#ifndef PriorityPackage_H
#define PriorityPackage_H

#include<iostream>
#include "Package.h"
using namespace std;

class PriorityPackage : public Package
{
 protected:
  string type;
  double width, length, height;
 public:
  PriorityPackage(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, string, double, double, double);
  double calcCost() const;
  void print() const; 
};

#endif
