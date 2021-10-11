#ifndef OCTAGON_H
#define OCTAGON_H


#include <iostream>

#include "figure.h"
#include "point.h"


class Octagon : public Figure {
public:
    Octagon();
    Octagon(double a, double b, double c, double d, double e, double f, double g,
            double h, Point In);
    Octagon(std::istream &is);
    Octagon(const Octagon& other);

    friend std::istream& operator>>(std::istream& is,  Octagon& obj);
    friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);

    virtual ~Octagon();

    size_t VertexesNumber();
    double Area();
    Octagon& operator=(const Octagon& other);
    bool operator==(const Octagon& other);

private:
    double len_a, len_b, len_c, len_d, len_e, len_f, len_g, len_h;
    Point InPoint;
};

#endif
