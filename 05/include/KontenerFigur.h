#pragma once

#include "Prostokat.h"

class KontenerFigur{
public:
	void operator+=(const Figura* f){
		_arr.push_back(f);
	}
	int size() const{return _arr.size();}
	const Figura operator[](int index) const{
		return *_arr[index];
	}
private:
	std::vector<const Figura*> _arr;
};

std::ostream& operator<<(std::ostream& s, const KontenerFigur& kf){
	for(int i=0; i<kf.size(); i++)
		s<<kf[i];
	return s;
}