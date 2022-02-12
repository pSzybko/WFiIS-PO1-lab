#include "Table.h"

void Table::print() const{
  std::for_each(_arr.begin(), _arr.end(), [](Data d){d.print();});
  std::cout<<std::endl;
}

void Table::operator+=(const Data& d){
  _arr.push_back(d);
  if(minRow==0 || d.size()<minRow)
    minRow=d.size();
}

Table& Table::sort(unsigned n){
  if(n>minRow-1){
    std::cout<<"Indeks "<<n<<" nieprawidlowy!"<<std::endl;
    return *this;
  }
  std::sort(_arr.begin(), _arr.end(), [n](Data d1, Data d2){
    return d1[n]<d2[n];
  });
  return *this;
}

Table& Table::sortBy(std::function<bool(const Data&, const Data&)> comp){
    std::sort(_arr.begin(), _arr.end(), comp);
    return *this;
  }