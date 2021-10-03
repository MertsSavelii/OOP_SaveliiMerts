#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
  Point();
  Point(std::istream &is);
  Point(double x, double y);

  double dist(Point& other);
  Point MidDot(Point& other);//находит точку посередине двух точек
  double getX();
  double getY();
  
  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, Point& p);

  bool operator!=(const Point& other);
private:
  double x_;
  double y_;
};

#endif // POINT_H