#include"PackageInventory.h"

//creates new package and stores in package vector if validation is correct
void PackageInventory::CreateNewPackage(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance)
{
  Package temp(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance);
  if (wt > 0)
    if (cost > 0)
      packages.push_back(temp);
    else
      cout << "Cost Per Ounce cannot be negative, package not added.\n";
  else
    cout << "Weight cannot be negative, package not added.\n";
}

//creates new priority package and stores in prioritypackage vector if validation is correct
void PackageInventory::CreateNewPriority(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance, string type, double length, double width, double height)
{
  PriorityPackage temp(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance, type, length, width, height);
  if (length < 12 && length > 0)
    if (width < 12 && width > 0)
      if (height < 5 && height >= 0)
	     priorityPackages.push_back(temp);
      else
	cout << "Height (" << height << ") is not a valid attribute for package " << l << ".\n";
    else
      cout << "Width (" << width << ") is not a valid attribute for package " << l << ".\n";
  else
    cout << "Length (" << length << ") is not a valid attribute for package " << l << ".\n";
}

//creates new express package and stores in expresspackage vector if validation is correct
void PackageInventory::CreateNewExpress(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance, double fee)
{
  ExpressPackage temp(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance, fee);
  if (wt > 0)
    if (cost > 0)
      if (fee > 0)
	expressPackages.push_back(temp);
      else
	cout << "Fee cannot be negative, package not added.\n";
    else
      cout << "Cost Per Ounce cannot be negative, package not added.\n";
  else
    cout << "Weight cannot be negative, package not added.\n";
}

//creates new international package and stores in internationalpackage vector if validation is correct
void PackageInventory::CreateNewInternational(string sName, string sAddress, string sCity, string sState, long sZIP, string rName, string rAddress, string rCity, string rState, long rZIP, string l, string d, double wt, double cost, string insurance, string dest)
{
  InternationalPackage temp(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, l, d, wt, cost, insurance, dest);
  if (dest == "Canada" || dest == "Mexico" || dest == "France" || dest == "England" || dest == "China" || dest == "India")
    internationalPackages.push_back(temp);
  else
    cout << "Invalid country, package not added.\n";
}

//prints all express packages
void PackageInventory::PrintAllExpressPackages() const
{
  cout << "\nPrinting All Express Packages.\n\n";
  cout << "======================================\n";
  for (int i = 0; i < expressPackages.size(); i++)
    expressPackages[i].print();
}

//prints all priority packages
void PackageInventory::PrintAllPriorityPackages() const
{
  cout << "Printing All Priority Packages.\n";
  cout << "======================================\n";
  for (int i = 0; i < priorityPackages.size(); i++)
    priorityPackages[i].print();
}

//prints all packages
void PackageInventory::PrintAllPackages() const
{
  cout << "Printing All Packages.\n";
  cout << "======================================\n";
  for (int i = 0; i < packages.size(); i++)
    packages[i].print();
}

//prints all international packages
void PackageInventory::PrintAllInternationalPackages()
{
  cout << "\nPrinting All International Packages.\n\n";
  cout << "======================================\n";
  for (int i = 0; i < internationalPackages.size(); i++)
    internationalPackages[i].print();
}

//calculates total cost for ALL packages and prints the total
void PackageInventory::CalculateTotalCost()
{
  double sum = 0;
  cout << "Calculating Total Cost\n";
  cout << "======================================\n";
  for (int i = 0; i < packages.size(); i++)
    sum += packages[i].calcCost();
  for (int i = 0; i < priorityPackages.size(); i++)
    sum += priorityPackages[i].calcCost();
  for (int i = 0; i < expressPackages.size(); i++)
    sum += expressPackages[i].calcCost();
  for (int i = 0; i < internationalPackages.size(); i++)
    sum += internationalPackages[i].calcCost();
  cout << "Total Cost: $" << fixed << setprecision(2) << sum << endl;
  cout << "======================================\n";
}

//prints all packages shipped on a given year
void PackageInventory::PrintAllShippedonYear(string year)
{
  cout << "Printing All Packages in " << year << "\n";
  cout << "======================================\n";
  for (int i = 0; i < packages.size(); i++)
    if (packages[i].getDate().substr(6, 4) == year)
      packages[i].print();
  for (int i = 0; i < expressPackages.size(); i++)
    if (expressPackages[i].getDate().substr(6, 4) == year)
      expressPackages[i].print();
  for (int i = 0; i < internationalPackages.size(); i++)
    if (internationalPackages[i].getDate().substr(6, 4) == year)
      internationalPackages[i].print();
  for (int i = 0; i < priorityPackages.size(); i++)
    if (priorityPackages[i].getDate().substr(6, 4) == year)
      priorityPackages[i].print();
}

//processes of given transaction file for a list of commands
void PackageInventory::ProcessTransactionFile(string file)
{
  ifstream fin;
  string command;
  string sName, sAddress, sCity, sState;
  long sZIP;
  string rName, rAddress, rCity, rState;
  long rZIP;
  string label, date, insuranceType;
  double weight, cost, fee;
  string type, dest, year;
  double length, width, height;

  fin.open(file.data());
  if (!fin)
    cout << "Could not open file.\n";
  else
    {
      cout << "======================================\n";
      cout << "File opened successfully.\n";
      cout << "======================================\n";
      while (fin >> command)
	{
	  if (command == "CreateNewPackage")
	    {
	      fin >> sName >> sAddress >> sCity >> sState >> sZIP >> rName >> rAddress >> rCity >> rState >> rZIP >> label >> date >> weight >> cost >> insuranceType;
	      CreateNewPackage(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, label, date, weight, cost, insuranceType);
	    }
	  else if (command == "PrintAllPackages")
	    PrintAllPackages();
	  else if (command == "CreateNewPriority")
	    {
              fin >> sName >> sAddress >> sCity >> sState >> sZIP >> rName >> rAddress >> rCity >> rState >> rZIP >> label >> date >> weight >> cost >> insuranceType >> type >> length >> width >> height;
	      CreateNewPriority(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, label, date, weight, cost, insuranceType, type, length, width, height);
	    }
	  else if (command == "PrintAllPriorityPackages")
	    PrintAllPriorityPackages();
	  else if (command == "CreateNewExpress")
	    {
              fin >> sName >> sAddress >> sCity >> sState >> sZIP >> rName >> rAddress >> rCity >> rState >> rZIP >> label >> date >> weight >> cost >> insuranceType >> fee;
	      CreateNewExpress(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, label, date, weight, cost, insuranceType, fee);
	    }
	  else if (command == "PrintAllExpressPackages")
	    PrintAllExpressPackages();
	  else if (command == "CreateNewInternational")
	    {
	      fin >> sName >> sAddress >> sCity >> sState >> sZIP >> rName >> rAddress >> rCity >> rState >> rZIP >> label >> date >> weight >> cost >> insuranceType >> dest;
	      CreateNewInternational(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, label, date, weight, cost, insuranceType, dest);
	    }
	  else if (command == "PrintAllInternationalPackages")
	    PrintAllInternationalPackages();
	  else if (command == "PrintAllShippedonYear")
	    {
	      fin >> year;
	      PrintAllShippedonYear(year);
	    }
	  else if (command == "CalculateTotalCost")
	    CalculateTotalCost();
	}
    }
}
