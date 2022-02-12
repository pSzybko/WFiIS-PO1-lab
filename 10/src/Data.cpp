#include "Data.h"

void Data::print() const{
    std::cout<<_name<<": ";
    std::for_each(_arr.begin(), _arr.end(), [](double n){std::cout<<std::setw(6)<<n;});
    std::cout<<std::endl;
  }

double Data::operator[](unsigned index)const {
  if(index>_arr.size()-1){
    return 0.;
  }
  return _arr[index];
}

Sum sumData(const Data& d){
  return Sum(std::accumulate(d._arr.begin(), d._arr.end(), 0.));
}