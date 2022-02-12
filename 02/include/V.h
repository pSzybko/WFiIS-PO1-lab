#pragma once

#include <iostream>
#include <string>
#include <cmath>

class V{
public:
	explicit V(int size);
	V(const V& other);
	~V();
	double& at(int index) const;
	void print(const std::string str) const;
	static double dot(const V& v1, const V& v2);
	operator double() const;
	double norm() const;
	static V sum(const V& v1, const V& v2);
	static V sum(const V& v1, int n);
private:
	double* _arr;
	int _size=0;
};