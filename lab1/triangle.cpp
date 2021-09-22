#include "triangle.h"

#include <cmath>

static Point a_, b_, c_;

Triangle::Triangle()
    : len_a(0.0),
      len_b(0.0),
      len_c(0.0) {
  std::cout << "Default triangle created" << std::endl;
}

Triangle::Triangle(double a, double b, double c)
    : len_a(a),
      len_b(b),
      len_c(c) {
  std::cout << "Triangle created" << std::endl;
}

Triangle::Triangle(std::istream &is) { 
    is >> a_ >> b_ >> c_;
      len_a = a_.dist(b_);
      len_b = b_.dist(c_);
      len_c = c_.dist(a_);
  std::cout << "Triangle created via istream" << std::endl;
}

Triangle::Triangle(const Triangle& other)
    : Triangle(other.len_a, other.len_b, other.len_c) {
  std::cout << "Made copy of triangle" << std::endl;

}

void Triangle::Print() {
    std::cout << len_a << ", ";
    std::cout << len_b << ", ";
    std::cout << len_c << std::endl;
}

double Triangle::Square2() {
    double p = (len_a + len_b + len_c) / 2.0;
    return p * (p - len_a) * (p - len_b) * (p - len_c);
}

double Triangle::Square() {
    return std::sqrt(Square2());
}

Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}
