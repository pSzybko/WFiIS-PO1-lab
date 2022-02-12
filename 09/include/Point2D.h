#pragma once
#include <iostream>
#include <initializer_list>
#include <cmath>


class Point2D{
public:
  Point2D()=default;
  Point2D(int x, int y): _x(x), _y(y), _odl(sqrt(pow(x,2)+pow(y,2))) {}
  ~Point2D()=default;
  void Print() const{
    std::cout<<"Point coordinates ("<<_x<<", "<<_y<<") distance from origin: "<<_odl<<std::endl;
  }
  int retX() const {return _x;}
  int retY() const {return _y;}
  bool operator<(const Point2D& other) const{
    return _odl<other._odl;
  }
  static void FunctionPrintY(const Point2D& point){
    std::cout<<"Function print y="<<point.retY()<<std::endl;
  }
  static void PrintPoint(const Point2D point){
    point.Print();
  }

private:
  int _x;
  int _y;
  double _odl;
};

bool MaxDistanceAsc(const Point2D& p1, const Point2D& p2){
    return std::max(p1.retX(), p1.retY())<(std::max(p2.retX(), p2.retY()));

}

void FunctionPrintX(const Point2D& point){
  std::cout<<"Function print x="<<point.retX()<<std::endl;
}

class OrderAscX{
  public:
  bool operator()(const Point2D& p1, const Point2D& p2) const{
    return (p1.retX()<p2.retX());
  }
};

class OrderDescY{
  public:
  bool operator()(const Point2D& p1, const Point2D& p2) const{
    return (p1.retY()>p2.retY());
  }
};