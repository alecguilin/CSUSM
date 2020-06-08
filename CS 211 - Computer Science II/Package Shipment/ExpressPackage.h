#ifndef ExpressPackage_H
#define ExpressPackage_H

#include <iostream>
#include"Package.h"
using namespace std;

class ExpressPackage : public Package
{
 protected:
  double expressFee;
 public:
  ExpressPackage(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, double);
  double calcCost() const;
  void print() const;
};

#endif
