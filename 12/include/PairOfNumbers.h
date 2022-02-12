#pragma once

#include <iostream>


template<typename T1, typename T2>
class PairOfNumbers{
public:
  T1& first;
  T2& second;
  PairOfNumbers(T1 &f, T2 &s): first(f), second(s) {}
  PairOfNumbers<T2, T1> Swapped() const{
    return std::move(PairOfNumbers<T2, T1>(second, first));
  }
  ~PairOfNumbers()=default;
  void Print() const{
    std::cout<<"Print method: "<<first<<" "<<second<<std::endl;
  }
  void Add(int n){first+=n; second+=n;}
  void Scale(int n){first*=n; second*=n;}
  void Info() const{std::cout<<"This is const pair of numbers"<<std::endl;}
  void Info(){std::cout<<"This is NON-const pair of numbers"<<std::endl;}
};