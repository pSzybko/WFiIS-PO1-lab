#pragma once

#include <iostream>
#include <vector>
#include <string>

//Przy pisaniu programu proszę nie korzystać ze słowa kluczowego friend (za użycie -2 pkt)

class Wierzcholek{
public:
	Wierzcholek(int x, int y):_x(x), _y(y){}
	int getX() const{return _x;}
	int getY() const{return _y;}
	bool operator==(const Wierzcholek& f) const;
private:
	int _x;
	int _y;
};

std::ostream& operator<<(std::ostream& s, const Wierzcholek& w){
	s<<" ("<<w.getX()<<", "<<w.getY()<<")";
	return s;
}

class Figura{
public:
	Figura(const std::string name):_name(name){
		std::cout<<"Jestem nowa figura "<<_name<<std::endl;
	}
	Figura& operator+=(const Wierzcholek& w);
	bool operator==(const Figura& f) const;
	Figura& dodajW(const Wierzcholek& w);
	std::string nazwa() const{return _name;}
	int size() const{return _arr.size();}
	const Wierzcholek* operator[](int index) const{
		return _arr[index];
	}
protected:
	std::vector<const Wierzcholek*> _arr;
	std::string _name;
};

std::ostream& operator<<(std::ostream& s, const Figura& f){
	s<<"Figura "<<f.nazwa()<<":\n";
	for(int i=0; i<f.size(); i++)
		s<<*f[i];
	s<<"\n";
	return s;
}