#include"FlightReservation.h"
//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<iomanip>
//using namespace std;

//creates new passenger
bool FlightReservation::CreateNewPassenger(string ID, string fName, string lName, char gender, int age, string assistance, string meal)
{
  bool found = false;
  cout << "Adding " << fName << " " << lName << " as a passenger.\n";
  for (int i = 0; i < passengers.size() && found==false; i++)
    {
      if (passengers[i].getID() == ID) //check if passenger exists
	{
	  found = true;
	  cout << passengers[i].getFullName() << " is already a passenger.\n";
	  return failure;
	}
    }
  Passenger temp(ID, fName, lName, gender, age, assistance, meal);
  passengers.push_back(temp);
  return success;
}

//creates new flight
bool FlightReservation::CreateNewFlight (string departAirport, string arrivAirport, string fDate, string fTime, string fEnd, float fDuration, int fCapacity)
{
  cout << "Creating flight# " << Flight::getNextFlightNum() << endl;
  bool found = false;
  for (int i = 0; i < flights.size() && found==false; i++)
    {
      //check if flight already exists
      if (flights[i].getDepartureAirport() == departAirport && flights[i].getArrivalAirport() == arrivAirport)
	if (flights[i].getFlightDate() == fDate && flights[i].getFlightTime() == fTime && flights[i].getFlightEnd() == fEnd && flights[i].getFlightCapacity() == fCapacity)
	  {
	    found = true;
	    cout << "Duplicate detected. Flight# " << flights[i].getFlightNum() << " is already a flight.\n";
	    return failure;
	  }
    }
  Flight temp(departAirport, arrivAirport, fDate, fTime, fEnd, fDuration, fCapacity);
  flights.push_back(temp);
  return success;
}

//prints all passengers across all flights
void FlightReservation::PrintAllPassengers() const
{
  cout << "\nPrinting All Passengers Across All Flights\n-----------------------------------------------------------------------------------\n";
  cout << left << setw(20) << "Name" << left << setw(13) << "ID" << left << setw(10) << "Gender" << left << setw(10) << "Age" << left << setw(15) << "Assistance";
  cout << left << setw(10) << "Meal Preference";
  cout << "\n-----------------------------------------------------------------------------------\n";
  for(int i = 0; i < passengers.size(); i++)
    passengers[i].PrintPassenger();
   cout << "-----------------------------------------------------------------------------------\n\n";
}

//prints all flights
void FlightReservation::PrintAllFlights() const
{
  cout << "\nPrinting All Flights\n---------------------------------------------------------------------------------------\n";
  cout << left << setw(10) << "Flight #" << left << setw(10) << "From" << left << setw(10) << "To" << left << setw(15) << "Date" << left << setw(10) << "Leaves";
  cout << left << setw(10) << "Arrives" << left << setw(10) << "Duration" << left << setw(10) << "Capacity";
  cout << "\n---------------------------------------------------------------------------------------\n";
  for(int i = 0; i < flights.size(); i++)
    flights[i].PrintFlight();
  cout << "---------------------------------------------------------------------------------------\n\n";
}

//searches for a flight using given criteria and prints matching flights
void FlightReservation::PrintSpecificFlights(string source, string destination, string day) const
{
  bool found = false;
  cout << "Searching for " << source << " " << destination << " " << day << endl;
  cout << "---------------------------------\n";
  for (int i = 0; i < flights.size(); i++)
    if (source == flights[i].getDepartureAirport() && destination == flights[i].getArrivalAirport() && day == flights[i].getFlightDate())
      {
	cout << "Flight#: " << flights[i].getFlightNum() << endl;
	cout << "Time: " << flights[i].getFlightTime() << " - " << flights[i].getFlightEnd() << endl;
	cout << "Duration: " << flights[i].getFlightDuration() << endl;
	found = true;
      }
  if (found==false)
    cout << "Could not find flight matching\ngiven criteria.\n";
  cout << "---------------------------------\n\n";
}

//adds a passenger to a flight
bool FlightReservation::AddFlightPassenger (long flightNum, string passengerID)
{
  cout << "Adding Passenger " << passengerID << " to flight " << flightNum << ".\n";
  for (int i = 0; i < flights.size(); i++) //search flight nums
    if (flightNum == flights[i].getFlightNum()) //check if flight num is valid
      {
	for (int j = 0; j < passengers.size(); j++) //search passengerIDs
	  {
	    if (passengerID == passengers[j].getID()) //check if passengerID is valid
	      { 
		vector<string> temp = flights[i].getFlightPassengers(); //list of flight passengers
		for (int k = 0; k < flights[i].getFlightSize(); k++) //search passengers on flight
		  {
		    if (passengerID == temp[i]) //check if passengerID is already on flight
		      {
			cout << "Passenger already on desired flight.\n";
			return failure;
		      }
		  }
		if (flights[i].getFlightSize() < flights[i].getFlightCapacity()) //check if flight is full
		  {
		    flights[i].SetFlightPassenger(passengerID); //if all conditions are met, add passenger to flight
		    return success;
		  }
		else //if flight is full
		  {
		    bool found = false;
		    cout << "Flight full.\nAlternative Flights: ";
		    for (int m = 0; m <flights.size(); m++) //if flight is full, give alternative flights with same arrival, dest, and date
		      {
			if (flights[i].getFlightNum() != flights[m].getFlightNum()) //makes sure not to list the full flight as an alterative
			  if (flights[i].getDepartureAirport() == flights[m].getDepartureAirport())
			    if (flights[i].getArrivalAirport() == flights[m].getArrivalAirport())
			      if (flights[i].getFlightDate() == flights[m].getFlightDate())
				{
				  cout << flights[m].getFlightNum() << " ";
				  found = true;
				}
		      }
		    if (found == false)
		      cout << "N/A";
		    else
		      cout << endl;
		    return failure;
		  }
	      }
	  }
	cout << "Passenger was not found.\n";
	return failure;
      }
  
  cout << "Flight does not exist.\n";
  return failure;
      
}

//removes a passenger from a flight
bool FlightReservation::RemoveFlightPassenger(long flightNum, string passengerID)
{
  cout << "Removing Passenger " << passengerID << " from flight " << flightNum << ".\n";
  for (int i = 0; i < flights.size(); i++) //search flights
    if (flightNum == flights[i].getFlightNum()) //look for matching flight number
      {
        for (int j = 0; j < passengers.size(); j++) //search passengers across all flights
          {
            if (passengerID == passengers[j].getID()) //look for matching passenger to see if passenger exists
              {
		vector<string> temp = flights[i].getFlightPassengers(); //get list of flight passengers
                for (int k = 0; k < flights[i].getFlightSize(); k++) //search passengers on flight
                  {
                    if (passengerID == temp[k]) //check if passenger is on flight
                      {
                        cout << "Passenger was on flight.\n";
			flights[i].DeletePassenger(k);
                        return success;
                      }
                  }
	      }
	  }
	cout << "Passenger was not found.\n";
        return failure;
      }
  cout << "Flight does not exist.\n";
  return failure;
}

//prints flight info
void FlightReservation::PrintFlightInfo (long flightNum) const
{
  bool found = false;
  cout << "\nPrinting Flight info for Flight # " << flightNum << ".\n";
  for (int i = 0; i < flights.size() && found==false; i++)
    if (flightNum == flights[i].getFlightNum())
      {
	cout << "---------------------------------------------------------------------------------------\n";
	cout << left << setw(10) << "Flight #" << left << setw(10) << "From" << left << setw(10) << "To" << left << setw(15) << "Date" << left << setw(10) << "Leaves";
	cout << left << setw(10) << "Arrives" << left << setw(10) << "Duration" << left << setw(10) << "Capacity";
	cout << "\n---------------------------------------------------------------------------------------\n";
	flights[i].PrintFlight();
	cout << "---------------------------------------------------------------------------------------\n";
	found = true;
      }
  if (found==false)
    cout << "Flight was not found.\n";
}

//prints passengers on a given flight
void FlightReservation::PrintFlightPassengers (long flightNum) const
{
  bool found = false;
  bool empty = true;
  cout << "\nPrinting Passengers for Flight # " << flightNum << ".\n";
  cout << "--------------------------------------------------------------------\n";
  cout << left << setw(20) << "Name" << left << setw(13) << "ID" << left << setw(15) << "Assistance" << left << setw(10) << "Meal Preference";
  cout << "\n--------------------------------------------------------------------\n";
  for (int i = 0; i < flights.size() && found==false; i++) //search for flight
    if (flightNum == flights[i].getFlightNum()) //check if flight exists
      {
	found = true;
	if (flights[i].getFlightSize() > 0) //check if flight is empty
	  {
	    vector<string> temp = flights[i].getFlightPassengers(); //list of flight passenger IDs
	    for (int j = 0; j < temp.size(); j++) //temp only has IDs on flight but we want to print the data associated with that ID
	      {
		for (int k = 0; k < passengers.size(); k++) //so we look for the matching ID
		  {
		    if (temp[j] == passengers[k].getID()) //check if passenger ID matches
		      passengers[k].PrintPassenger2();
		  }
	      }
	    empty = false;
	  }
      }
  cout << "--------------------------------------------------------------------\n";
  if (found==false)
    cout << "Flight was not found.\n";
  else if (empty == true)
    cout << "Flight is empty.\n";
}

//checks if a flight is full or not
bool FlightReservation::IsFlightFull(long flightNum)
{
  cout << "Checking flight capacity for flight# " << flightNum << ".\n";
  for (int i = 0; i < flights.size(); i++) //search flights
    if (flightNum == flights[i].getFlightNum()) //check if flight exists
      {
	cout << "Flight has " << flights[i].getFlightSize() << " passenger(s).\n";
	if (flights[i].getFlightCapacity() == flights[i].getFlightSize())
	  return success;
	else 
	  return failure;
      }
  cout << "Flight was not found.\n";
  return failure;
}

//prints all passengers on a given flight with a specific assistance requirement or meal preference
void FlightReservation::PrintAssistancePassengers (long flightNum, string assistance) const
{
  bool found = false;
  bool valid = false;
  cout << "Printing all passengers with " << assistance << " assistance required on flight # " << flightNum << ".\n";
  cout << "-----------------------------------------------------------------------------------\n";
  cout << left << setw(20) << "Name" << left << setw(13) << "ID" << left << setw(10) << "Gender" << left << setw(10) << "Age" << left << setw(15) << "Assistance";
  cout << left << setw(10) << "Meal Preference";
  cout << "\n-----------------------------------------------------------------------------------\n";
  for (int i = 0; i < flights.size(); i++) //search flights
    {
      if (flightNum == flights[i].getFlightNum()) //check if flight exists
	{
	  found = true;
	  vector<string> temp = flights[i].getFlightPassengers(); //list of flight passengers
	  for (int j = 0; j < flights[i].getFlightSize(); j++) //search passengers on flight
	    {
	      for (int k = 0; k < passengers.size(); k++) //search passengers across all flights so we can find associated data
		if (temp[j] == passengers[k].getID()) //check if matching ID
		  if (assistance == passengers[k].getAssistance() || assistance == passengers[k].getMealPref())
		    {
		      valid = true;
		      passengers[k].PrintPassenger();
		    }
	    } 
	}
    }
  if (found==false)
    cout << "Flight # " << flightNum << " does not exist.\n";
  if (valid == false)
    cout << "No passenger with " << assistance << " assistance found.\n";
  cout << "-----------------------------------------------------------------------------------\n\n";
}

//reads given commands from transaction file
bool FlightReservation::ProcessTransactionFile(string fileName)
{
  ifstream fin;
  string command;
  string ID, fName, lName, assistance, meal, arrival, departure, flightdate, flighttime, flightend;
  char gender;
  int age, capacity;
  float flightdur;
  long flightnum;
  fin.open(fileName.data());
  if (!fin)
    {
      cout << "Could not open file.\n";
      return failure;
    }
  else
    {
      cout << "---------------------------------------\n";
      cout << "File opened successfully.\n";
      cout << "---------------------------------------\n\n";
      while(fin >> command)
	{
	  if (command == "CreateNewPassenger")
	    {
	      fin >> fName >> lName >> ID >> gender >> age >> assistance >> meal;
	      if(CreateNewPassenger(ID, fName, lName, gender, age, assistance, meal)==failure)
		cout << "-----Passenger not added.-----\n";
	      else
		cout << "Passenger successfully added.\n";
	    }
	  else if (command == "PrintAllPassengers")
	    PrintAllPassengers();
	  else if (command == "CreateNewFlight")
	    {
	      fin >> departure >> arrival >> flightdate >> flighttime >> flightend >> flightdur >> capacity;
	      if(CreateNewFlight(departure, arrival, flightdate, flighttime, flightend, flightdur, capacity)==failure)
		cout << "Flight not created.\n";
	      else
		cout << "Flight created.\n";
	    }
	  else if (command == "PrintAllFlights")
	    PrintAllFlights();
	  else if (command == "PrintSpecificFlights")
	    {
	      fin >> departure >> arrival >> flightdate;
	      PrintSpecificFlights(departure, arrival, flightdate);
	    }
	  else if (command == "AddFlightPassenger")
	    {
	      fin >> flightnum >> ID;
	      if (AddFlightPassenger(flightnum, ID) == failure)
		cout << "Passenger not added.\n";
	      else
		cout << "Passenger added.\n";
	    }
	  else if (command == "RemoveFlightPassenger")
	    {
	      fin >> flightnum >> ID;
	      if (RemoveFlightPassenger(flightnum, ID) == success)
		cout << "Passenger successfully deleted.\n";
	      else
		cout << "Passenger not deleted.\n";
	    }
	  else if (command == "PrintFlightInfo")
	    {
	      fin >> flightnum;
	      PrintFlightInfo(flightnum);
	    }
	  else if (command == "PrintFlightPassengers")
	    {
	      fin >> flightnum;
	      PrintFlightPassengers(flightnum);
	    }
	  else if (command == "isFlightFull")
	    {
	      fin >> flightnum;
	      if (IsFlightFull(flightnum) == success)
		cout << "Flight is full.\n\n";
	      else
		cout << "Flight is not full.\n\n";
	    }
	  else if (command == "PrintAssistancePassengers")
	    {
	      fin >> flightnum >> assistance;
	      PrintAssistancePassengers(flightnum, assistance);
	    }
	}
      return success;
    }
}

//static vars
bool FlightReservation::success = true;
bool FlightReservation::failure = false;
