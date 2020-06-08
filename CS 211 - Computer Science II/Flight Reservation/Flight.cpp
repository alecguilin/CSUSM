#include"Flight.h"

//default constructor
Flight::Flight() : flightNum(nextFlightNum) , flightCapacity(10)
{
  departureAirport = "Unknown";
  arrivalAirport = "Unknown";
  flightDate = "Unknown";
  flightTime = "Unknown";
  flightEnd = "Unknown";
  flightDuration = 0;
  nextFlightNum += 10;
}

//constructor
Flight::Flight(string depart, string arrival, string flightD, string flightT, string flightE, float flightDur, int flightC) : flightNum(nextFlightNum), flightCapacity(flightC)
{
  nextFlightNum += 10;
  departureAirport = depart;
  arrivalAirport = arrival;
  flightDate = flightD;
  flightTime = flightT;
  flightEnd = flightE;
  flightDuration = flightDur;
}

void Flight::PrintFlight() const
{
  cout << left << setw(10) << flightNum;
  cout << left << setw(10) << departureAirport;
  cout << left << setw(10) << arrivalAirport;
  cout << left << setw(15) << flightDate;
  cout << left << setw(10) << flightTime;
  cout << left << setw(10) << flightEnd;
  cout << left << setw(10) << fixed << setprecision(2) << flightDuration;
  cout << left << setw(10) << flightCapacity;
  cout << endl;
}

void Flight::SetFlightPassenger(string ID)
{
  passengersID.push_back(ID);
}

int Flight::getFlightSize() const
{
  return passengersID.size();
}
void Flight::PrintPass() const
{
  for (int i = 0; i < passengersID.size(); i++)
    cout << passengersID[i] << endl;
}
vector<string> Flight::getFlightPassengers() const
{
  return passengersID;
}

void Flight::DeletePassenger(int index)
{
  passengersID.erase(passengersID.begin() + index);
}

long Flight::getFlightNum() const
{
  return flightNum;
}

string Flight::getDepartureAirport() const
{
  return departureAirport;
}

string Flight::getArrivalAirport() const
{
  return arrivalAirport;
}

string Flight::getFlightDate() const
{
  return flightDate;
}

string Flight::getFlightTime() const
{
  return flightTime;
}

string Flight::getFlightEnd() const
{
  return flightEnd;
}
float Flight::getFlightDuration() const
{
  return flightDuration;
}

int Flight::getFlightCapacity() const
{
  return flightCapacity;
}

int Flight::getNextFlightNum()
{
  return nextFlightNum;
}
long Flight::nextFlightNum = 100;
