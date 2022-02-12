#include "V.h"

V::V(int size){
	_size=size;
	_arr=new double[size];
	for(int i=0; i<size; i++)
		_arr[i]=0.;
}

V::V(const V& other):_size(other._size){
	_arr=new double[_size];
	for(int i=0; i<_size; i++)
		_arr[i]=other._arr[i];
}

V::~V(){
	delete [] _arr;
}

double& V::at(int index) const{
	return _arr[index];
}

void V::print(const std::string str) const{
	std::cout<<str<<"(";
	for(int i=0; i<_size-1; i++)
		std::cout<<_arr[i]<<", ";
	std::cout<<_arr[_size-1]<<")"<<std::endl;
}

double V::dot(const V& v1, const V& v2){
	if(v1._size!=v2._size){
		std::cout<<"Error, vectors of different dimensions!"<<std::endl;
		return 0.;
	}
	double tmp=0.;
	for(int i=0; i<v1._size; i++)
		tmp+=v1._arr[i]*v2._arr[i];
	return tmp;
}

double V::norm() const{
	return sqrt(dot(*this, *this));
}

V::operator double() const{
	return norm();
}

V V::sum(const V& v1, const V& v2){
	if(v1._size!=v2._size){
		std::cout<<"Error, vectors of different dimensions!"<<std::endl;
		return V(0);
	}
	V tmp(v1._size);
	for(int i=0; i<tmp._size; i++)
		tmp._arr[i]=v1._arr[i]+v2._arr[i];
	return tmp;
}

V V::sum(const V& v1, int n){
	V tmp(v1._size);
	for(int i=0; i<tmp._size; i++)
		tmp._arr[i]=v1._arr[i]+n;
	return tmp;
}