#pragma once

#include <iostream>

class Primitive{
public:
	Primitive(double val=0):_val(val){}
	virtual ~Primitive()=default;
	void Set(double val){_val=val;}
	void PrintWithValue() const{
		Print();
		std::cout<<" = "<<Value()<<std::endl;
	}
	virtual void Print() const{std::cout<<_val;}
	virtual double Value() const{return _val;}
private:
	double _val;
};