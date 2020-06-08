#include"Package.h"

//constructor
Package::Package(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance)
{
  senderName = sName;
  senderAddress = sAddress;
  senderCity = sCity;
  senderState = sState;
  senderZIPcode = sZIP;
  recipName = rName;
  recipAddress = rAddress;
  recipCity = rCity;
  recipState = rState;
  recipZIPcode = rZIP;
  label = l;
  date = d;
  if (wt > 0)
    weight = wt;
  if (cost > 0)
    costPerOunce = cost;
  insuranceType = insurance;
}

//calculates cost of package
double Package::calcCost() const
{
  if (insuranceType == "upto100")
    return weight*costPerOunce+5;
  if (insuranceType == "upto1000")
    return weight*costPerOunce+15;
  if (insuranceType == "upto5000")
    return weight*costPerOunce+40;
  else
    return weight*costPerOunce;
}

//prints package 
void Package::print() const
{
  cout << "-------Shipping Label-------\n";
  cout << "Label: " << label << endl << "Date: " << date << endl << "Weight: " << weight << endl << "Insurance Type: " << insuranceType << endl;
  cout << "-------Sender Info-------\n";
  cout << senderName << endl;
  cout << senderAddress << endl;
  cout << senderCity << " " << senderState << " " << senderZIPcode << endl;
  cout << "-------Recipient Info-------\n";
  cout << recipName << endl;
  cout << recipAddress << endl;
  cout << recipCity << " " << recipState << " " << recipZIPcode << endl;
  cout << "Shipping Cost: " << fixed << setprecision(2) << "$" << calcCost() << endl;
  cout << "======================================\n";
}

//returns date package was sent
string Package::getDate() const
{
  return date;
}
