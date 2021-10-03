#include "point.h"

#include <cmath>

Point::Point() : x_(0.0), y_(0.0) {}

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point(std::istream &is) {
  is >> x_ >> y_;
}

double Point::dist(Point& other) {
  double dx = (other.x_ - x_);
  double dy = (other.y_ - y_);
  return sqrt(dx*dx + dy*dy);
}

Point Point::MidDot(Point& other) {
  Point Mid ((other.x_ + x_)/2.0, (other.y_ + y_)/2.0);
  return Mid; 
}

double Point::getX() {
  return x_;
}

double Point::getY() {
  return x_;
}

std::istream& operator>>(std::istream& is, Point& p) {
  is >> p.x_ >> p.y_;
  return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
  os << "(" << p.x_ << ", " << p.y_ << ")";
  return os;
}

bool Point::operator!=(const Point& other) {
  if (x_ == other.x_) return false;
  if (y_ == other.y_) return false;
  return true;
}