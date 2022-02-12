#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class QuantityBase{
public:
  QuantityBase(const std::string name):_name(name){}
  virtual ~QuantityBase(){}
  std::string name() const{return _name;}
  virtual void Print() const=0;
private:
  std::string _name;
};

template <typename T>
class Quantity: public QuantityBase{
public:
  Quantity<T>(const std::string name,const T& val):QuantityBase(name), _val(val) {}
  virtual void Print() const override{
    std::cout<<name()<<": "<<_val<<std::endl;
  }
  void PrintU() const{
    std::cout<<name()<<": "<<_val;
  }
  void SetValue(const T& nval){_val=nval;}
private:
  T _val;
};

typedef Quantity<int> QuantityInt;
typedef Quantity<float> QuantityFloat;
typedef Quantity<double> QuantityDouble;
typedef Quantity<bool> QuantityBool;
typedef Quantity<char> QuantityChar;


class ArrayOfQuantities{
public:
  ArrayOfQuantities(unsigned size):_size(size){
    _arr.reserve(_size);
  }
  ~ArrayOfQuantities(){
    std::for_each(_arr.begin(), _arr.end(), [](QuantityBase* qb){delete qb;});
    
  }
  template <typename T>
  Quantity<T>* CreateAndAdd(const std::string name, const T& val){
    Quantity<T>* ne=new Quantity(name, val);
    _arr.push_back(ne);
    return ne;
  }
  void Print() const{
    std::for_each(_arr.begin(), _arr.end(), [](const QuantityBase* qb){qb->Print();});
  }
private:
  unsigned _size;
  std::vector<QuantityBase*> _arr;
};

template<typename T>
class QuantityWithUnits: public Quantity<T>{
public:
  QuantityWithUnits<T>(const std::string name,const T& val, const std::string unit):Quantity<T>(name, val), _unit(unit){}
  void Print() const{
    this->PrintU();
    std::cout<<" ["<<_unit<<"]"<<std::endl;
  }
private:
  std::string _unit;
};