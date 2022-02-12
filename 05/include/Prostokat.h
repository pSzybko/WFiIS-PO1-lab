#pragma once

#include "Figura.h"

class Prostokat : public Figura{
public:
	Prostokat(const std::string name):Figura(name){}
	int pole() const{
		return abs(_arr[0]->getX()-_arr[1]->getX())*abs(_arr[1]->getY()-_arr[2]->getY());
	}
};