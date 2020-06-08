#ifndef FLIGHT_H
#define FLIGHT_H
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Flight
{
 private:
  const long flightNum;
  string departureAirport;
  string arrivalAirport;
  string flightDate;
  string flightTime;
  string flightEnd;
  float flightDuration;
  const int flightCapacity;
  vector<string> passengersID;
  static long nextFlightNum;
 public:
  Flight();
  Flight(string, string, string, string, string, float, int);
  void SetFlight(string, string, string, string, string, float, int);
  void SetFlightPassenger(string);
  void PrintFlight() const;
  int getFlightSize() const;
  vector<string> getFlightPassengers() const;
  void DeletePassenger(int);
  long getFlightNum() const;
  string getDepartureAirport() const;
  string getArrivalAirport() const;
  string getFlightDate() const;
  string getFlightTime() const;
  string getFlightEnd() const;
  float getFlightDuration() const;
  int getFlightCapacity() const;
  static int getNextFlightNum();
  void PrintPass() const;
};

#endif
