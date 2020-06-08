#ifndef Package_H
#define Package_H
#include<iostream>
#include<iomanip>
using namespace std;
class Package
{
 protected:
  //sender information
  string senderName, senderAddress, senderCity, senderState;
  long senderZIPcode;
  //recipient information
  string recipName, recipAddress, recipCity, recipState;
  long recipZIPcode;
  //other package details
  string label, date, insuranceType;
  double weight, costPerOunce;
 public:
  Package(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string);
  double calcCost() const;
  void print() const;
  string getDate() const;
};

#endif
