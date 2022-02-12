#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>

#include "Sum.h"

class Data{
friend Sum sumData(const Data& d);
public:
  Data(std::string name, std::vector<double> arr) : _arr(arr), _name(name) {}
  void print() const;
  double operator[](unsigned index)const;
  unsigned size() const{return _arr.size();}
private:
  std::vector<double> _arr;
  std::string _name;
};

Sum sumData(const Data& d);