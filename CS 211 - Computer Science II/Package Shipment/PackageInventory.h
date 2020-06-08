#ifndef PackageInv_H
#define PackageInv_H

#include"Package.h"
#include"ExpressPackage.h"
#include"PriorityPackage.h"
#include"InternationalPackage.h"
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class PackageInventory
{
 private:
  vector <Package> packages;
  vector <PriorityPackage> priorityPackages;
  vector <ExpressPackage> expressPackages;
  vector <InternationalPackage> internationalPackages;
 public:
  void CreateNewPackage(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string);
  void CreateNewPriority(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, string, double, double, double);
  void CreateNewExpress(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, double);
  void CreateNewInternational(string, string, string, string, long, string, string, string, string, long, string, string, double, double, string, string);
  void PrintAllPackages() const;
  void PrintAllPriorityPackages() const;
  void PrintAllExpressPackages() const;
  void PrintAllInternationalPackages(); //not declared const because a value is changed (costPerOunce)
  void CalculateTotalCost();
  void PrintAllShippedonYear(string);
  void ProcessTransactionFile(string);
};

#endif
