#include "ExpressPackage.h"

//constructor
ExpressPackage::ExpressPackage(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance, double fee) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance)
{
  if (fee > 0)
    expressFee = fee;
}

//calculates cost of express package
double ExpressPackage::calcCost() const
{
  if (insuranceType == "upto100")
    return (weight*(costPerOunce+expressFee))+5;
  if (insuranceType == "upto1000")
    return (weight*(costPerOunce+expressFee))+15;
  if (insuranceType == "upto5000")
    return (weight*(costPerOunce+expressFee))+40;
  else
    return (weight*(costPerOunce+expressFee));
}

//prints express package
void ExpressPackage::print() const
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
  cout << "Express Fee: " << expressFee << endl;
  cout << "Shipping Cost: " << fixed << setprecision(2) << "$" << calcCost() << endl;
  cout << "======================================\n";
}
