#include"InternationalPackage.h"

//constructor with validation
InternationalPackage::InternationalPackage(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance, string c) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance)
{
  if (c == "Canada" || c == "Mexico" || c == "France" || c == "England" || c == "China" || c == "India")
    country = c;
}

//calculates cost of international package
//not declared constant because costPerOunce value is changed
double InternationalPackage::calcCost()
{
  if (country == "Canada")
    {
      costPerOunce = 10;
      return Package::calcCost();
    }
  if (country == "Mexico")
    {
      costPerOunce = 9;
      return Package::calcCost();
    }
  if (country == "France")
    {
      costPerOunce = 20;
      return Package::calcCost();
    }
  if (country == "England")
    {
      costPerOunce = 18;
      return Package::calcCost();
    }
  if (country == "China")
    {
      costPerOunce = 25;
      return Package::calcCost();
    }
  else
    {
      costPerOunce = 22;
      return Package::calcCost();
    }
}

//prints international package
void InternationalPackage::print()
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
  cout << "Country: " << country << endl;
  cout << "Shipping Cost: " << fixed << setprecision(2) << "$" << calcCost() << endl;
  cout << "======================================\n";
}
