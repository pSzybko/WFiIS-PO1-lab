#pragma once

#include "Primitive.h"

class Sum : public Primitive{
public:
	Sum(Primitive& p1, Primitive& p2):_p1(p1), _p2(p2){}
	void Print() const override{
		std::cout<<"(";
		_p1.Print();
		std::cout<<"*";
		_p2.Print();
		std::cout<<")";
	}
	double Value() const override{
		return _p1.Value()+_p2.Value();
	}
private:
	Primitive& _p1;
	Primitive& _p2;
};