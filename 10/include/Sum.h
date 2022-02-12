#pragma once

#include <iostream>

class Sum{
public:
  Sum()=default;
  Sum(double suma) : _suma(suma) {}
  double value() const {return _suma;}
  void operator()(double n){_suma+=2;}
private:
  double _suma;
};