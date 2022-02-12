// Prosze napisac szablon klasy PairOfNumbers, ktora reprezentuje pare liczb (w ogolnosci roznego typu). Klasa ta daje rozne mozliwości transformacji tych liczb oraz ich wypisywania.

// Prosze napisac szablon klasy RangeArray, ktora na podstawie PairOfNumbers tworzy tablice (typem przechowywanych danych jest drugi z typow szablonu klasy PairOfNumbers). Rozmiar tablicy = druga-pierwsza liczba z pary.

// UWAGA
// Przy rozwiazywaniu zadania NIE wolno korzystac z zadnych kontenerow bilbioteki standardowej m.in. z std::vector

#include <iostream>
#include "include/PairOfNumbers.h"
#include "include/RangeArray.h"

void ModifyArray(RangeArray<double> array){
  std::cout<<"===== In ModifyArray =====\n";

  array[-2] = -10.4;
  array[2] = -20.2;

  std::cout << array.At(-2) << std::endl;
  std::cout << array.At(2) << std::endl;
}


int main(){
  int firstNumber(1);
  double secondNumber(20.5);
  std::cout<<"raw numbers: "<<firstNumber<<"\t"<<secondNumber<<"\n";

  PairOfNumbers<int, double> pair(firstNumber, secondNumber);
  std::cout<<"manual print: "<<pair.first<<"\t"<<pair.second<<"\n";

  std::cout<<"===== CHANGING VALUES =====\n";
  pair.first = 11;
  pair.second = 22.2;
  std::cout<<"raw numbers: "<<firstNumber<<"\t"<<secondNumber<<"\n";
  std::cout<<"manual print: "<<pair.first<<"\t"<<pair.second<<"\n";


  std::cout<<"===== AFTER SWAPED =====\n";  
  PairOfNumbers<double, int> swapped = pair.Swapped();
  swapped.Print();
  std::cout<<"===== AFTER Setting SWAPED =====\n";    
  swapped.first  = 5;
  swapped.second  = 6;
  std::cout<<"raw numbers: "<<firstNumber<<"\t"<<secondNumber<<"\n";

  std::cout<<"===== AFTER ADD =====\n";
  pair.Add(7);
  pair.Print();
  
  std::cout<<"===== AFTER SCALE =====\n";
  pair.Scale(3383);
  pair.Print();

  std::cout<<"===== CONST PAIR =====\n";
  const PairOfNumbers<int,double>* const constPair = new const PairOfNumbers(pair);
  constPair->Print();
  
  std::cout<<"===== OBJECTS INFO =====\n";
  pair.Info();
  constPair->Info();

  std::cout<<"===== CHANGING VALUES AGAIN =====\n";
  firstNumber = -2;
  secondNumber = 3;

  pair.Print();
  constPair->Print();
 
  std::cout<<"===== RANGE ARRAY =====\n";  
  RangeArray<double> array(pair);
  //RangeArray<int> error(swapped); // odkomentowanie powinno spowodowac blad kompilacji
  std::cout << array.Size() << std::endl;
  array[-2] = 9.2;
  array[-1] = 8.4;
  array[-0] = 5.7;
  array[1] = 13.8;
  array[2] = 12.9;
  std::cout << array[-2] << std::endl;
  std::cout << array[2] << std::endl;

  ModifyArray(array);

  std::cout << "===== BACK TO THE MAIN =====" << std::endl;
  std::cout << array[-2] << std::endl;
  std::cout << array[2] << std::endl;

  delete constPair;
  
  return 0;
}

/* // Output:
raw numbers: 1  20.5
manual print: 1 20.5
===== CHANGING VALUES =====
raw numbers: 11 22.2
manual print: 11    22.2
===== AFTER SWAPED =====
Print method: 22.2 11
===== AFTER Setting SWAPED =====
raw numbers: 6  5
===== AFTER ADD =====
Print method: 13 12
===== AFTER SCALE =====
Print method: 43979 40596
===== CONST PAIR =====
Print method: 43979 40596
===== OBJECTS INFO =====
This is NON-const pair of numbers
This is const pair of numbers
===== CHANGING VALUES AGAIN =====
Print method: -2 3
Print method: -2 3
===== RANGE ARRAY =====
5
9.2
12.9
===== In ModifyArray =====
-10.4
-20.2
===== BACK TO THE MAIN =====
9.2
12.9
*/
