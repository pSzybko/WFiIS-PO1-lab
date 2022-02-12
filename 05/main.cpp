#include <iostream>
#include <string>
#include "include/Figura.h"
#include "include/Prostokat.h"
#include "include/KontenerFigur.h"


/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[]) {

  Figura f("f");
  Prostokat p("p");

  const Wierzcholek w1(0,0);
  const Wierzcholek w2(3,0);
  const Wierzcholek w3(3,3);
  const Wierzcholek w4(0,3);

  std::cout << "Utworzone wierzchołki:" << w1 << w2 << w3 << w4 << std::endl;

  (((f += w1) += w2) += w3) += w4;
  p.dodajW(w1).dodajW(w2).dodajW(w3).dodajW(w4);

  std::cout << "Pole prostokata " << p.nazwa() << ": " << p.pole() << std::endl;

  Figura f2("f2");
  f2 += w2;
  f2 += w3;
  f2.dodajW(w1);

  std::cout << "Test: " << (f==f2 ? "" : "nie") << "identyczne figury" << std::endl;

  Figura f3("f3");
  (((f3 += w1) += w2) += w3) += w4;
  std::cout << "Test 2: " << (f==f3 ? "" : "nie") << "identyczne figury" << std::endl;

  KontenerFigur k;
  k += &f;
  k += &p;
  k += &f2;

  std::cout << k;
}

/*
Jestem nową figurą f
Jestem nową figurą p
Tak naprawdę jestem prostokątem.
Utworzone wierzchołki: (0, 0) (3, 0) (3, 3) (0, 3)
Pole prostokata p: 9
Jestem nową figurą f2
Test: nieidentyczne figury
Jestem nową figurą f3
Test 2: identyczne figury
Figura f: 
 (0, 0) (3, 0) (3, 3) (0, 3)
Figura p: 
 (0, 0) (3, 0) (3, 3) (0, 3)
Figura f2: 
 (3, 0) (3, 3) (0, 0)
*/
