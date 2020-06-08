#include"PackageInventory.h"
#include"Package.h"
#include"PriorityPackage.h"
#include"ExpressPackage.h"
#include"InternationalPackage.h"
#include<iostream>
using namespace std;

int main()
{
  PackageInventory inventory;
  inventory.ProcessTransactionFile("transFile.txt");
  return 0;
}
