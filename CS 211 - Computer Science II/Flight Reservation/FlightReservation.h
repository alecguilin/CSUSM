#ifndef FlightReservation_H
#define FlightReservation_H
#include<vector>
#include<iostream>
#include<fstream>
#include"Flight.h"
#include"Passenger.h"
using namespace std;

class FlightReservation
{
 private:
  vector <Flight> flights;
  vector <Passenger> passengers;
  static bool failure;
  static bool success;
 public:
  bool CreateNewPassenger(string, string, string, char, int, string, string);
  bool CreateNewFlight(string, string, string, string, string, float, int);
  bool AddFlightPassenger(long, string);
  bool RemoveFlightPassenger(long, string);
  void PrintAllPassengers() const;
  void PrintAllFlights() const;
  void PrintSpecificFlights(string, string, string) const;
  void PrintFlightInfo(long) const;
  void PrintFlightPassengers(long) const;
  void PrintAssistancePassengers(long, string) const;
  bool IsFlightFull(long); 
  bool ProcessTransactionFile(string);
};

#endif
