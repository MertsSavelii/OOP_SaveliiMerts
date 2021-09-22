#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"

#include <iostream>


class Triangle : public Figure {
public:
    Triangle();
    Triangle(double a, double b, double c);
    Triangle(std::istream &is);
    Triangle(const Triangle& other);

    virtual ~Triangle();

    void Print();
    double Square();
    double Square2();

private:
    double len_a, len_b, len_c;
};

#endif
