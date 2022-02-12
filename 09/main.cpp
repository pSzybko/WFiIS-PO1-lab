/*Proszę napisać klasę Point2D, która będzie przechowywała dwie współrzedne punktu: x i y. Każdy punkt ma również odleglość od środka układu współrzędnych (funkcja sqrt znajduje się w pliku cmath). Proszę dopisać możliwość porównywania punktów na podstawie odległości od środka układu współrzędnych - potrzebny jest operator mniejszości.

Klasa Point2D powinna zawierać również dwie metody statyczne: PrintPoint(const Point2D point), która wypisuje na ekran informacje o obiekcie point i FunctionPrintY(const Point2D& point), która wypisuje na ekran tylko współrzędną Y punktu.

Funkcja MaxDistanceAsc powinna zwracać prawdę, jeżeli większa ze współrzędnych pierwszego punktu jest mniejsza od większej współrzędnej drugiego punktu. Czyli należy sprawdzić czy x czy y jest większy dla pierwszego punktu, następnie powtórzyć to samo dla współrzędnych drugiego punktu i zwrócić prawdę, jeżeli wartość dla pierwszego punktu jest mniejsza od wartości dla drugiego punktu.

Należy dopisać również dwie klasy-funktory:
OrderAscX - porównuje dwa punkty na podstawie tylko współrzędnej X,
OrderDescY - porównuje dwa punkty tylko na podstawie współrzędnej Y.

Ostatnią funkcją do zaimplementowania jest FunctionPrintX(const Point2D& point), która wypisuje na ekran wspolrzędną X punktu.

Proszę cały kod umieścić w plikach Point2D.h oraz Point2D.cpp.*/

#include "include/Point2D.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main(){
  using namespace std;

  Point2D pointsArray [] = {Point2D(0, 0), Point2D(3, 2), Point2D(4, 4), Point2D(2, 3), Point2D(1, 5)};
  const int pointsArraySize = sizeof(pointsArray)/sizeof(Point2D);

  cout<<"===== POINTS =====\n";
  set<Point2D> points;
  points.insert(pointsArray, pointsArray + pointsArraySize);

  for (set<Point2D>::iterator it = points.begin(); it != points.end(); ++it)
    it->Print();

  cout<<"===== POINTS ascending X =====\n";
  set<Point2D, OrderAscX> pointsAscX;
  pointsAscX.insert(pointsArray, pointsArray + pointsArraySize);
  for (set<Point2D, OrderAscX>::iterator it = pointsAscX.begin(); it != pointsAscX.end(); ++it)
    it->Print();
  
  cout<<"===== POINTS descending Y =====\n";
  set<Point2D, OrderDescY> pointsDescY;
  pointsDescY.insert(pointsArray, pointsArray + pointsArraySize);
  for (set<Point2D, OrderDescY>::iterator it = pointsDescY.begin(); it != pointsDescY.end(); ++it)
    it->Print();
  
  cout<<"===== POINTS max(x, y) =====\n";
  bool(*maxMetricsAsc)(const Point2D&, const Point2D&) = MaxDistanceAsc;
  set<Point2D, bool(*)(const Point2D&, const Point2D&)> pointsMax (maxMetricsAsc);
  pointsMax.insert(pointsArray, pointsArray + pointsArraySize);
  for (set<Point2D, bool(*)(const Point2D&, const Point2D&)>::iterator it = pointsMax.begin(); it != pointsMax.end(); ++it)
    it->Print();

  cout<<"===== POINTS vector =====\n";
  vector<Point2D> pointsVector;
  pointsVector.insert(pointsVector.begin(), pointsArray, pointsArray + pointsArraySize);

  cout<<"----- print X -----\n";
  for_each(pointsVector.begin(), pointsVector.end(), FunctionPrintX);

  cout<<"----- print Y -----\n";
  for_each(pointsVector.begin(), pointsVector.end(), Point2D::FunctionPrintY);

  cout<<"----- sorted Y -----\n";
  OrderDescY descY;
  sort (pointsVector.begin(), pointsVector.end(), descY);
  for_each(pointsVector.begin(), pointsVector.end(), Point2D::FunctionPrintY);
  
  cout<<"===== FOR EACH =====\n";
  cout<<"----- set -----\n";
  for_each(pointsAscX.begin(), pointsAscX.end(), Point2D::PrintPoint);

  cout<<"----- array -----\n";
  for_each(pointsArray, pointsArray + pointsArraySize, Point2D::PrintPoint);

  return 0;
}

/* //Output:
===== POINTS =====
Point coordinates (0, 0) distance from origin: 0
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (4, 4) distance from origin: 5.65685
===== POINTS ascending X =====
Point coordinates (0, 0) distance from origin: 0
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
===== POINTS descending Y =====
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (4, 4) distance from origin: 5.65685
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (0, 0) distance from origin: 0
===== POINTS max(x, y) =====
Point coordinates (0, 0) distance from origin: 0
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
Point coordinates (1, 5) distance from origin: 5.09902
===== POINTS vector =====
----- print X -----
Function print x=0
Function print x=3
Function print x=4
Function print x=2
Function print x=1
----- print Y -----
Function print y=0
Function print y=2
Function print y=4
Function print y=3
Function print y=5
----- sorted Y -----
Function print y=5
Function print y=4
Function print y=3
Function print y=2
Function print y=0
===== FOR EACH =====
----- set -----
Point coordinates (0, 0) distance from origin: 0
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
----- array -----
Point coordinates (0, 0) distance from origin: 0
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (1, 5) distance from origin: 5.09902
*/
