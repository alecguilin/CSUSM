#include"Preference.h"

//default constructor
Preference::Preference()
{
  assistanceType = "none";
  mealType = "none";
}

//constructor
Preference::Preference(string assistance, string meal)
{
  assistanceType = assistance;
  mealType = meal;
}

void Preference::SetPreference(string assistance, string meal)
{
  assistanceType = assistance;
  mealType = meal;
}
void Preference::PrintPreference() const
{
  cout << left << setw(15) << assistanceType;
  cout << left << setw(10) << mealType;
  cout << endl;
}

string Preference::getAssistance() const
{
  return assistanceType;
}

string Preference::getMeal() const
{
  return mealType;
}
