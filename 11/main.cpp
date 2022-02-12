#include "include/Variable.h"
#include <iostream>

//#define ERROR_0
//#define ERROR_1
//#define ERROR_2

int main(){
  const unsigned int maxArraySize = 10;
  ArrayOfVariables array (maxArraySize);

  std::cout<<"----- VARIABLES PRINT -----\n";
  VariableDouble* time = NULL;
  time = array.CreateAndAdd ("time", 13.);
  time->Print();
  
  VariableFloat* distance = NULL;
  distance = array.CreateAndAdd ("distance", 15.f);
  distance->Print();
  
  VariableInt* numberOfEvents = array.CreateAndAdd ("events", 176);
  VariableChar* hexDigit = array.CreateAndAdd ("hex digit", 'F');
  VariableBool* isGood = array.CreateAndAdd ("is good", true);

#ifdef ERROR_0
  VariableInt* numberOfEvents2 = array.CreateAndAdd ("events", 176.);
#endif

#ifdef ERROR_1
  time = distance;
  time = numberOfEvents;
  time = isGood;
  time = hexDigit;
  distance = numberOfEvents;
  distance = isGood;
  numberOfEvents = isGood;
#endif
  
  std::cout<<"----- ARRAY PRINT -----\n";
  array.Print();
  std::cout<<std::endl;

  std::cout<<"----- MODIFIED VALUES -----\n";
  time->SetValue(10.5);
  distance->SetValue(0.5);
  numberOfEvents->SetValue (42);
  hexDigit->SetValue('9');
  isGood->SetValue(true);

  array.Print();
  std::cout<<std::endl;
  
  std::cout<<"----- WITH UNITS -----\n";
  VariableWithUnits<double> speed ("speed", 333., "m/s");
  speed.Print();
  VariableDouble& speedRef = speed;
  speedRef.Print();

  VariableWithUnits<int> numberOfAtoms ("number of atoms", 436, "atoms");
  numberOfAtoms.Print();
  VariableInt& numberOfAtomsRef = numberOfAtoms;
  numberOfAtomsRef.Print();

#ifdef ERROR_2
  VariableWithUnits<double>& speedRef2 = speedRef;
  VariableWithUnits<int>& numberRef = numberOfAtomsRef;
#endif
  
  return 0;
}
/* // Output: //
----- VARIABLES PRINT -----
time: 13
distance: 15
----- ARRAY PRINT -----
time: 13
distance: 15
events: 176
hex digit: F
is good: 1

----- MODIFIED VALUES -----
time: 10.5
distance: 0.5
events: 42
hex digit: 9
is good: 1

----- WITH UNITS -----
speed: 333 [m/s]
speed: 333 [m/s]
number of atoms: 436 [atoms]
number of atoms: 436 [atoms]
*/