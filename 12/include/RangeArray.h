#pragma once

#include "PairOfNumbers.h"

template<typename T>
class RangeArray{
public:
  template<typename T2>
  RangeArray(PairOfNumbers<T2, T>& pon){
    _size=(int)pon.second-(int)pon.first;
    _arr = new T [_size];
    
  }
  RangeArray(const RangeArray<T>& other){
    _size=other._size;
    _arr= new T [_size];
    for(int i=0; i<_size; i++)
      _arr[i]=other._arr[i];
  }
  ~RangeArray(){
    delete [] _arr;
  }
  int Size() const{return _size;}
  T& operator[](int index) const{
    return _arr[index+_size/2];
  }
  T At(int index) const{
    return (*this)[index];
  } 
private:
  T* _arr;
  int _size=0;
};