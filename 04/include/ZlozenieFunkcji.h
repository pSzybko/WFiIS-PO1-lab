#pragma once

#include "Funkcje.h"

#include <vector>
#include <functional>


class ZlozenieFunkcji{
public:
	void insert(std::function<double(double)> f);
	double wynik(double x);
	double operator[](int index) const;
private:
	std::vector<std::function<double(double)>> _arr;
	std::vector<double> _wyn;
};