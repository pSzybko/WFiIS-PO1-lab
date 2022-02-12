#include "ZlozenieFunkcji.h"

void ZlozenieFunkcji::insert(std::function<double(double)> f){
	_arr.push_back(f);
}

double ZlozenieFunkcji::wynik(double x){
	_wyn.clear();
	for(int i=0; i<_arr.size(); i++){
		x=_arr[i](x);
		_wyn.push_back(x);
	}
	return x;
}

double ZlozenieFunkcji::operator[](int index) const{
	return _wyn[index];
}
