#include "Figura.h"

bool Wierzcholek::operator==(const Wierzcholek& f) const{
	return (_x==f._x and _y==f._y);
}


Figura& Figura::operator+=(const Wierzcholek& w){
	_arr.push_back(&w);
	return *this;
}


bool Figura::operator==(const Figura& f) const{
	if(_arr.size()!=f._arr.size())
		return false;
	for(int i=0; i<_arr.size(); i++)
		if(!((*_arr[i])==(*f._arr[i])))
			return false;
	return true;
}


Figura& Figura::dodajW(const Wierzcholek& w){
	(*this)+=w;
	return *this;
}