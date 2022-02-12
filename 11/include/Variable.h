#pragma once

#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>
#include <algorithm>

class VariableVirt{
public:
  VariableVirt(std::string name):_name(name) {}
  virtual ~VariableVirt()=default;
  virtual void Print() const=0;
  std::string name() const{return _name;}
private:
  std::string _name;
};

template <typename T>
class Variable : public VariableVirt{
public:
  Variable<T>(const std::string name, const T value):VariableVirt(name), _value(value) {}
  virtual void Print() const override{
    std::cout<<name()<<": "<<_value<<std::endl;
  }
  void PrintU() const{
    std::cout<<name()<<": "<<_value;
  }
  void SetValue(const T value){_value=value;}
private:
  T _value;
};
typedef Variable<double> VariableDouble;
typedef Variable<int> VariableInt;
typedef Variable<float> VariableFloat;
typedef Variable<char> VariableChar;
typedef Variable<bool> VariableBool;

class ArrayOfVariables{
public:
  ArrayOfVariables(unsigned size){_arr.reserve(size);}
  ~ArrayOfVariables(){
    std::for_each(_arr.begin(), _arr.end(), [](VariableVirt* v){delete v;});
  }
  template <typename T>
  Variable<T>* CreateAndAdd(const std::string name, const T value){
    Variable<T>* tmp=new Variable<T>(name, value);
    _arr.push_back(tmp);
    return tmp;
  }
  void Print() const{
    std::for_each(_arr.begin(),_arr.end(), [](VariableVirt* v){v->Print();});
  }
private:
  std::vector<VariableVirt*> _arr;
};

template<typename T>
class VariableWithUnits : public Variable<T>{
public:
  VariableWithUnits<T>(const std::string name, const T val, const std::string unit):Variable<T>(name, val), _unit(unit) {}
  void Print() const override{
    Variable<T>::PrintU();
    std::cout<<" ["<<_unit<<"]"<<std::endl;
  }
private:
  std::string _unit;
};