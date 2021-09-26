#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include "triangle.h"
#include <iostream>
#include "point.h"


class Octagon : public Figure {
public:
    Octagon();
    Octagon(double a, double b, double c, double d, double e, double f, double g,
            double h, Point In);
    Octagon(std::istream &is);
    Octagon(const Octagon& other);

    virtual ~Octagon();

    size_t VertexesNumber();
    void Print(std::ostream& os);
    double Area();

private:
    double len_a, len_b, len_c, len_d, len_e, len_f, len_g, len_h;
    Point InPoint;
};

#endif
