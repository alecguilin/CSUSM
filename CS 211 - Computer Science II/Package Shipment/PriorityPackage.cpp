#include"PriorityPackage.h"

//constructor with validation
PriorityPackage::PriorityPackage(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance, string t, double lngth, double w, double h) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance)
{
  type = t;
  if (lngth < 12 && lngth > 0)
    length = lngth;
  if (w < 12 && w > 0)
    width = w;
  if (h < 5 && h > 0)
    height = h;
}

//calculates cost of priority package
double PriorityPackage::calcCost() const
{
  double total;
  if (type == "letter")
    total = 3;
  else if (type == "envelope")
    total = 7;
  else if (width < 8 && length < 5 && height < 2)
    total = 10;
  else if (width < 11 &&length < 8 && height < 5)
    total = 17;
  else
    total = 25;
  if (insuranceType == "upto100")
    return total+5;
  if (insuranceType == "upto1000")
    return total+15;
  if (insuranceType == "upto5000")
    return total+40;
  else
    return total;
}

//prints priority package
void PriorityPackage::print() const
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
  cout << "-------Package Specifications-------\n";
  cout << "Package Type: " << type << endl;
  cout << "Package Dimensions(LxWxH): " << length << " x " << width << " x " << height << endl;
  cout << "Shipping Cost: " << fixed << setprecision(2) << "$" << calcCost() << endl;
  cout << "======================================\n";
}
