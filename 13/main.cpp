#include "include/Quantity.h"
#include <iostream>

// #define ERROR_0
// #define ERROR_1
// #define ERROR_2

int main(){
  const unsigned int maxArraySize = 10;
  ArrayOfQuantities array (maxArraySize);

  std::cout<<"----- Quantities PRINT -----\n";
  QuantityDouble* time = NULL;
  time = array.CreateAndAdd ("time", 13.);
  time->Print();
  
  QuantityFloat* distance = NULL;
  distance = array.CreateAndAdd ("distance", 15.f);
  distance->Print();
  
  QuantityInt* numberOfEvents = array.CreateAndAdd ("events", 176);
  QuantityChar* hexDigit = array.CreateAndAdd ("hex digit", 'F');
  QuantityBool* isGood = array.CreateAndAdd ("is good", true);

#ifdef ERROR_0
  QuantityInt* numberOfEvents2 = array.CreateAndAdd ("events", 176.);
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
  time->SetValue(4.5);
  distance->SetValue(1.5);
  numberOfEvents->SetValue(48);
  hexDigit->SetValue('9');
  isGood->SetValue(true);

  array.Print();
  std::cout<<std::endl;
  
  std::cout<<"----- WITH UNITS -----\n";
  QuantityWithUnits<double> speed ("speed", 332., "m/s");
  speed.Print();
  QuantityDouble& speedRef = speed;
  speedRef.Print();

  QuantityWithUnits<int> numberOfAtoms ("number of atoms", 136, "atoms");
  numberOfAtoms.Print();
  QuantityInt& numberOfAtomsRef = numberOfAtoms;
  numberOfAtomsRef.Print();

#ifdef ERROR_2
  QuantityWithUnits<double>& speedRef2 = speedRef;
  QuantityWithUnits<int>& numberRef = numberOfAtomsRef;
#endif
  
  return 0;
}
/* // Output: //
----- Quantities PRINT -----
time: 13
distance: 15
----- ARRAY PRINT -----
time: 13
distance: 15
events: 176
hex digit: F
is good: 1

----- MODIFIED VALUES -----
time: 4.5
distance: 1.5
events: 48
hex digit: 9
is good: 1

----- WITH UNITS -----
speed: 332 [m/s]
speed: 332 [m/s]
number of atoms: 136 [atoms]
number of atoms: 136 [atoms]
*/
