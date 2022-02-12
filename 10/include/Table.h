#pragma once

#include  "Data.h"

class Table{
public:
  Table()=default; 
  void print() const;
  void operator+=(const Data& d);
  unsigned minRow=0;
  Table& sort(unsigned n);
  Table& sortBy(std::function<bool(const Data&, const Data&)> comp);
private:
  std::vector<Data> _arr;
};