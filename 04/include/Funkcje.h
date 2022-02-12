#pragma once

#include <iostream>
#include <cmath>

class Sinus{
public:
	Sinus(double a, double b);
	double operator()(double x) const;
private:
	double _a;
	double _b;
};

struct PierwiastekKwadratowy{
	double operator()(double x) const;
};

class Liniowa{
public:
	Liniowa(double a, double b);
	double operator()(double x) const;
private:
	double _a;
	double _b;
};